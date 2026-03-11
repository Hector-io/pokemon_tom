import json
import csv
from collections import defaultdict

FILE = "src/data/wild_encounters.json"
OUTPUT_FILE = "encounter_report.csv"

with open(FILE) as f:
    data = json.load(f)

groups = data["wild_encounter_groups"]

def calculate_percentages(slots, rates):
    totals = defaultdict(float)
    total_weight = sum(rates)

    for slot, rate in zip(slots, rates):
        species = slot["species"]
        totals[species] += (rate / total_weight) * 100

    return totals


with open(OUTPUT_FILE, "w", newline="") as csvfile:
    writer = csv.writer(csvfile)

    # Header row
    writer.writerow(["map", "encounter_type", "species", "percent"])

    for group in groups:
        fields = {f["type"]: f for f in group.get("fields", [])}

        for encounter in group["encounters"]:
            map_name = encounter.get("map") or encounter.get("base_label") or "UNKNOWN_MAP"

            # Skip FireRed/LeafGreen encounter data
            if "FRLG" in map_name:
                continue

            for encounter_type in ["land_mons", "water_mons", "rock_smash_mons", "fishing_mons"]:
                if encounter_type not in encounter:
                    continue

                mons = encounter[encounter_type]["mons"]
                if encounter_type not in fields:
                    continue
                rates = fields[encounter_type]["encounter_rates"]

                percentages = calculate_percentages(mons, rates)

                for species, pct in sorted(percentages.items(), key=lambda x: -x[1]):
                    writer.writerow([map_name, encounter_type, species, round(pct, 2)])

print(f"Encounter report written to {OUTPUT_FILE}")