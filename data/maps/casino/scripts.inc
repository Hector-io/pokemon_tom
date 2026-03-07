casino_MapScripts::

	.byte 0

Casino_EventScript_Greeter::
    lock
    faceplayer
    checkitem ITEM_COIN_CASE, 1
    compare VAR_RESULT, TRUE
    goto_if_eq Casino_EventScript_AlreadyHaveCase

    msgbox Casino_Text_Welcome, MSGBOX_DEFAULT
    giveitem ITEM_COIN_CASE
    setflag FLAG_UNUSED_0x020
    msgbox Casino_Text_ReceivedCase, MSGBOX_DEFAULT
    release
    end

Casino_EventScript_AlreadyHaveCase::
    setflag FLAG_UNUSED_0x020
    msgbox Casino_Text_AlreadyHave, MSGBOX_DEFAULT
    release
    end

Casino_Text_Welcome:
    .string "Welcome to the CASINO!\n"
    .string "You'll need a COIN CASE to play.$"

Casino_Text_ReceivedCase:
    .string "Here, take this COIN CASE.\n"
    .string "Enjoy the games!$"

Casino_Text_AlreadyHave:
    .string "Enjoy the CASINO!\n"
    .string "Try your luck at the machines!$"

Casino_EventScript_CoinVendor::
    lock
    faceplayer
    msgbox Casino_Text_CoinVendorWelcome, MSGBOX_DEFAULT
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
    showmoneybox 0, 0
    showcoinsbox 1, 6
    goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50

Casino_Text_CoinVendorWelcome:
    .string "Welcome to the CASINO!\n"
    .string "How many coins would you like?$"

Casino_EventScript_PrizeVendor_Kanto::
    lock
    faceplayer
    msgbox Casino_Text_PrizeVendor, MSGBOX_DEFAULT
    showcoinsbox 1, 6
    multichoice 0, 0, MULTI_UNUSED_40, 0
    switch VAR_RESULT
        case 0, Casino_Prize_Articuno
        case 1, Casino_Prize_Zapdos
        case 2, Casino_Prize_Moltres
        case 3, Casino_Prize_Mewtwo
        case 4, Casino_Prize_Cancel

Casino_Text_PrizeVendor:
    .string "Welcome to the prize exchange!\n"
    .string "Which prize would you like?$"

Casino_Prize_Articuno:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 600, Casino_NotEnoughCoins
    removecoins 600
    createmon 0, PARTY_SIZE, SPECIES_ARTICUNO, 50
    msgbox Casino_Text_GotArticuno, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Zapdos:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 700, Casino_NotEnoughCoins
    removecoins 700
    createmon 0, PARTY_SIZE, SPECIES_ZAPDOS, 50
    msgbox Casino_Text_GotZapdos, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Moltres:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 800, Casino_NotEnoughCoins
    removecoins 800
    createmon 0, PARTY_SIZE, SPECIES_MOLTRES, 50
    msgbox Casino_Text_GotMoltres, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Mewtwo:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1200, Casino_NotEnoughCoins
    removecoins 1200
    createmon 0, PARTY_SIZE, SPECIES_MEWTWO, 70
    msgbox Casino_Text_GotMewtwo, MSGBOX_DEFAULT
    release
    end

Casino_NotEnoughCoins:
    msgbox Casino_Text_NotEnoughCoins, MSGBOX_DEFAULT
    release
    end

Casino_PrizeDone:
    msgbox Casino_Text_PrizeReceived, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Cancel:
    release
    end

Casino_PrizeShop:
    .2byte ITEM_POTION
    .2byte ITEM_SUPER_POTION
    .2byte ITEM_HYPER_POTION
    .2byte ITEM_NONE

Casino_Text_NotEnoughCoins:
    .string "You don't have enough coins.$"

Casino_Text_PrizeReceived:
    .string "Here you go! Enjoy your prize!$"

Casino_Text_GotArticuno:
    .string "Tom received ARTICUNO!$"

Casino_Text_GotZapdos:
    .string "Tom received ZAPDOS!$"

Casino_Text_GotMoltres:
    .string "Tom received MOLTRES!$"


Casino_Text_GotMewtwo:
    .string "Tom received MEWTWO!$"

Casino_EventScript_PrizeVendor_Johto::
    lock
    faceplayer
    msgbox Casino_Text_PrizeVendor, MSGBOX_DEFAULT
    showcoinsbox 1, 6
    multichoice 0, 0, MULTI_UNUSED_41, 0
    switch VAR_RESULT
        case 0, Casino_Prize_Raikou
        case 1, Casino_Prize_Entei
        case 2, Casino_Prize_Suicune
        case 3, Casino_Prize_Lugia
        case 4, Casino_Prize_HoOh
        case 5, Casino_Prize_Cancel

Casino_Prize_Raikou:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 700, Casino_NotEnoughCoins
    removecoins 700
    createmon 0, PARTY_SIZE, SPECIES_RAIKOU, 55
    msgbox Casino_Text_GotRaikou, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Entei:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 700, Casino_NotEnoughCoins
    removecoins 700
    createmon 0, PARTY_SIZE, SPECIES_ENTEI, 55
    msgbox Casino_Text_GotEntei, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Suicune:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 800, Casino_NotEnoughCoins
    removecoins 800
    createmon 0, PARTY_SIZE, SPECIES_SUICUNE, 55
    msgbox Casino_Text_GotSuicune, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Lugia:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1200, Casino_NotEnoughCoins
    removecoins 1200
    createmon 0, PARTY_SIZE, SPECIES_LUGIA, 65
    msgbox Casino_Text_GotLugia, MSGBOX_DEFAULT
    release
    end

Casino_Prize_HoOh:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1200, Casino_NotEnoughCoins
    removecoins 1200
    createmon 0, PARTY_SIZE, SPECIES_HO_OH, 65
    msgbox Casino_Text_GotHoOh, MSGBOX_DEFAULT
    release
    end

Casino_Text_GotRaikou:
    .string "Tom received RAIKOU!$"

Casino_Text_GotEntei:
    .string "Tom received ENTEI!$"

Casino_Text_GotSuicune:
    .string "Tom received SUICUNE!$"

Casino_Text_GotLugia:
    .string "Tom received LUGIA!$"


Casino_Text_GotHoOh:
    .string "Tom received HO-OH!$"


Casino_EventScript_PrizeVendor_Sinnoh::
    lock
    faceplayer
    msgbox Casino_Text_PrizeVendor, MSGBOX_DEFAULT
    showcoinsbox 1, 6
    multichoice 0, 0, MULTI_CASINO_SINNOH, 0
    switch VAR_RESULT
        case 0, Casino_Prize_Uxie
        case 1, Casino_Prize_Mesprit
        case 2, Casino_Prize_Azelf
        case 3, Casino_Prize_Dialga
        case 4, Casino_Prize_Palkia
        case 5, Casino_Prize_Giratina
        case 6, Casino_Prize_Cancel

Casino_Prize_Uxie:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 800, Casino_NotEnoughCoins
    removecoins 800
    createmon 0, PARTY_SIZE, SPECIES_UXIE, 60
    msgbox Casino_Text_GotUxie, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Mesprit:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 800, Casino_NotEnoughCoins
    removecoins 800
    createmon 0, PARTY_SIZE, SPECIES_MESPRIT, 60
    msgbox Casino_Text_GotMesprit, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Azelf:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 800, Casino_NotEnoughCoins
    removecoins 800
    createmon 0, PARTY_SIZE, SPECIES_AZELF, 60
    msgbox Casino_Text_GotAzelf, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Dialga:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1200, Casino_NotEnoughCoins
    removecoins 1200
    createmon 0, PARTY_SIZE, SPECIES_DIALGA, 65
    msgbox Casino_Text_GotDialga, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Palkia:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1200, Casino_NotEnoughCoins
    removecoins 1200
    createmon 0, PARTY_SIZE, SPECIES_PALKIA, 65
    msgbox Casino_Text_GotPalkia, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Giratina:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1300, Casino_NotEnoughCoins
    removecoins 1300
    createmon 0, PARTY_SIZE, SPECIES_GIRATINA, 65
    msgbox Casino_Text_GotGiratina, MSGBOX_DEFAULT
    release
    end

Casino_Text_GotUxie:
    .string "Tom received UXIE!$"

Casino_Text_GotMesprit:
    .string "Tom received MESPRIT!$"

Casino_Text_GotAzelf:
    .string "Tom received AZELF!$"

Casino_Text_GotDialga:
    .string "Tom received DIALGA!$"

Casino_Text_GotPalkia:
    .string "Tom received PALKIA!$"

Casino_Text_GotGiratina:
    .string "Tom received GIRATINA!$"


Casino_EventScript_PrizeVendor_Unova::
    lock
    faceplayer
    msgbox Casino_Text_PrizeVendor, MSGBOX_DEFAULT
    showcoinsbox 1, 6
    multichoice 0, 0, MULTI_CASINO_UNOVA, 0
    switch VAR_RESULT
        case 0, Casino_Prize_Cobalion
        case 1, Casino_Prize_Terrakion
        case 2, Casino_Prize_Virizion
        case 3, Casino_Prize_Reshiram
        case 4, Casino_Prize_Zekrom
        case 5, Casino_Prize_Kyurem
        case 6, Casino_Prize_Cancel

Casino_Prize_Cobalion:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 900, Casino_NotEnoughCoins
    removecoins 900
    createmon 0, PARTY_SIZE, SPECIES_COBALION, 65
    msgbox Casino_Text_GotCobalion, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Terrakion:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 900, Casino_NotEnoughCoins
    removecoins 900
    createmon 0, PARTY_SIZE, SPECIES_TERRAKION, 65
    msgbox Casino_Text_GotTerrakion, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Virizion:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 900, Casino_NotEnoughCoins
    removecoins 900
    createmon 0, PARTY_SIZE, SPECIES_VIRIZION, 65
    msgbox Casino_Text_GotVirizion, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Reshiram:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1300, Casino_NotEnoughCoins
    removecoins 1300
    createmon 0, PARTY_SIZE, SPECIES_RESHIRAM, 70
    msgbox Casino_Text_GotReshiram, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Zekrom:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1300, Casino_NotEnoughCoins
    removecoins 1300
    createmon 0, PARTY_SIZE, SPECIES_ZEKROM, 70
    msgbox Casino_Text_GotZekrom, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Kyurem:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1400, Casino_NotEnoughCoins
    removecoins 1400
    createmon 0, PARTY_SIZE, SPECIES_KYUREM, 70
    msgbox Casino_Text_GotKyurem, MSGBOX_DEFAULT
    release
    end

Casino_Text_GotCobalion:
    .string "Tom received COBALION!$"

Casino_Text_GotTerrakion:
    .string "Tom received TERRAKION!$"

Casino_Text_GotVirizion:
    .string "Tom received VIRIZION!$"

Casino_Text_GotReshiram:
    .string "Tom received RESHIRAM!$"

Casino_Text_GotZekrom:
    .string "Tom received ZEKROM!$"


Casino_Text_GotKyurem:
    .string "Tom received KYUREM!$"


Casino_EventScript_PrizeVendor_Kalos::
    lock
    faceplayer
    msgbox Casino_Text_PrizeVendor, MSGBOX_DEFAULT
    showcoinsbox 1, 6
    multichoice 0, 0, MULTI_CASINO_KALOS, 0
    switch VAR_RESULT
        case 0, Casino_Prize_Xerneas
        case 1, Casino_Prize_Yveltal
        case 2, Casino_Prize_Zygarde
        case 3, Casino_Prize_Diancie
        case 4, Casino_Prize_Hoopa
        case 5, Casino_Prize_Volcanion
        case 6, Casino_Prize_Cancel

Casino_Prize_Xerneas:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1400, Casino_NotEnoughCoins
    removecoins 1400
    createmon 0, PARTY_SIZE, SPECIES_XERNEAS, 70
    msgbox Casino_Text_GotXerneas, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Yveltal:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1400, Casino_NotEnoughCoins
    removecoins 1400
    createmon 0, PARTY_SIZE, SPECIES_YVELTAL, 70
    msgbox Casino_Text_GotYveltal, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Zygarde:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1500, Casino_NotEnoughCoins
    removecoins 1500
    createmon 0, PARTY_SIZE, SPECIES_ZYGARDE, 70
    msgbox Casino_Text_GotZygarde, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Diancie:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1600, Casino_NotEnoughCoins
    removecoins 1600
    createmon 0, PARTY_SIZE, SPECIES_DIANCIE, 70
    msgbox Casino_Text_GotDiancie, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Hoopa:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1600, Casino_NotEnoughCoins
    removecoins 1600
    createmon 0, PARTY_SIZE, SPECIES_HOOPA, 70
    msgbox Casino_Text_GotHoopa, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Volcanion:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1700, Casino_NotEnoughCoins
    removecoins 1700
    createmon 0, PARTY_SIZE, SPECIES_VOLCANION, 70
    msgbox Casino_Text_GotVolcanion, MSGBOX_DEFAULT
    release
    end

Casino_Text_GotXerneas:
    .string "Tom received XERNEAS!$"

Casino_Text_GotYveltal:
    .string "Tom received YVELTAL!$"

Casino_Text_GotZygarde:
    .string "Tom received ZYGARDE!$"

Casino_Text_GotDiancie:
    .string "Tom received DIANCIE!$"

Casino_Text_GotHoopa:
    .string "Tom received HOOPA!$"

Casino_Text_GotVolcanion:
    .string "Tom received VOLCANION!$"


Casino_EventScript_PrizeVendor_Alola::
    lock
    faceplayer
    msgbox Casino_Text_PrizeVendor, MSGBOX_DEFAULT
    showcoinsbox 1, 6
    multichoice 0, 0, MULTI_CASINO_ALOLA, 0
    switch VAR_RESULT
        case 0, Casino_Prize_TapuKoko
        case 1, Casino_Prize_TapuLele
        case 2, Casino_Prize_TapuBulu
        case 3, Casino_Prize_TapuFini
        case 4, Casino_Prize_Solgaleo
        case 5, Casino_Prize_Lunala
        case 6, Casino_Prize_Necrozma
        case 7, Casino_Prize_Cancel

Casino_Prize_TapuKoko:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1200, Casino_NotEnoughCoins
    removecoins 1200
    createmon 0, PARTY_SIZE, SPECIES_TAPU_KOKO, 70
    msgbox Casino_Text_GotTapuKoko, MSGBOX_DEFAULT
    release
    end

Casino_Prize_TapuLele:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1200, Casino_NotEnoughCoins
    removecoins 1200
    createmon 0, PARTY_SIZE, SPECIES_TAPU_LELE, 70
    msgbox Casino_Text_GotTapuLele, MSGBOX_DEFAULT
    release
    end

Casino_Prize_TapuBulu:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1200, Casino_NotEnoughCoins
    removecoins 1200
    createmon 0, PARTY_SIZE, SPECIES_TAPU_BULU, 70
    msgbox Casino_Text_GotTapuBulu, MSGBOX_DEFAULT
    release
    end

Casino_Prize_TapuFini:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1200, Casino_NotEnoughCoins
    removecoins 1200
    createmon 0, PARTY_SIZE, SPECIES_TAPU_FINI, 70
    msgbox Casino_Text_GotTapuFini, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Solgaleo:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1600, Casino_NotEnoughCoins
    removecoins 1600
    createmon 0, PARTY_SIZE, SPECIES_SOLGALEO, 70
    msgbox Casino_Text_GotSolgaleo, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Lunala:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1600, Casino_NotEnoughCoins
    removecoins 1600
    createmon 0, PARTY_SIZE, SPECIES_LUNALA, 70
    msgbox Casino_Text_GotLunala, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Necrozma:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1700, Casino_NotEnoughCoins
    removecoins 1700
    createmon 0, PARTY_SIZE, SPECIES_NECROZMA, 70
    msgbox Casino_Text_GotNecrozma, MSGBOX_DEFAULT
    release
    end

Casino_Text_GotSolgaleo:
    .string "Tom received SOLGALEO!$"

Casino_Text_GotLunala:
    .string "Tom received LUNALA!$"

Casino_Text_GotNecrozma:
    .string "Tom received NECROZMA!$"


Casino_Text_GotTapuKoko:
    .string "Tom received TAPU KOKO!$"

Casino_Text_GotTapuLele:
    .string "Tom received TAPU LELE!$"

Casino_Text_GotTapuBulu:
    .string "Tom received TAPU BULU!$"

Casino_Text_GotTapuFini:
    .string "Tom received TAPU FINI!$"


Casino_EventScript_PrizeVendor_Galar::
    lock
    faceplayer
    msgbox Casino_Text_PrizeVendor, MSGBOX_DEFAULT
    showcoinsbox 1, 6
    multichoice 0, 0, MULTI_CASINO_GALAR, 0
    switch VAR_RESULT
        case 0, Casino_Prize_Zacian
        case 1, Casino_Prize_Zamazenta
        case 2, Casino_Prize_Eternatus
        case 3, Casino_Prize_Kubfu
        case 4, Casino_Prize_Urshifu
        case 5, Casino_Prize_Calyrex
        case 6, Casino_Prize_Cancel

Casino_Prize_Zacian:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1800, Casino_NotEnoughCoins
    removecoins 1800
    createmon 0, PARTY_SIZE, SPECIES_ZACIAN, 70
    msgbox Casino_Text_GotZacian, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Zamazenta:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1800, Casino_NotEnoughCoins
    removecoins 1800
    createmon 0, PARTY_SIZE, SPECIES_ZAMAZENTA, 70
    msgbox Casino_Text_GotZamazenta, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Eternatus:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 2000, Casino_NotEnoughCoins
    removecoins 2000
    createmon 0, PARTY_SIZE, SPECIES_ETERNATUS, 70
    msgbox Casino_Text_GotEternatus, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Kubfu:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 900, Casino_NotEnoughCoins
    removecoins 900
    createmon 0, PARTY_SIZE, SPECIES_KUBFU, 65
    msgbox Casino_Text_GotKubfu, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Urshifu:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1200, Casino_NotEnoughCoins
    removecoins 1200
    createmon 0, PARTY_SIZE, SPECIES_URSHIFU, 70
    msgbox Casino_Text_GotUrshifu, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Calyrex:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 2000, Casino_NotEnoughCoins
    removecoins 2000
    createmon 0, PARTY_SIZE, SPECIES_CALYREX, 75
    msgbox Casino_Text_GotCalyrex, MSGBOX_DEFAULT
    release
    end


Casino_Text_GotZacian:
    .string "Tom received ZACIAN!$"

Casino_Text_GotZamazenta:
    .string "Tom received ZAMAZENTA!$"

Casino_Text_GotEternatus:
    .string "Tom received ETERNATUS!$"

Casino_Text_GotKubfu:
    .string "Tom received KUBFU!$"

Casino_Text_GotUrshifu:
    .string "Tom received URSHIFU!$"

Casino_Text_GotCalyrex:
    .string "Tom received CALYREX!$"


Casino_EventScript_PrizeVendor_Paldea::
    lock
    faceplayer
    msgbox Casino_Text_PrizeVendor, MSGBOX_DEFAULT
    showcoinsbox 1, 6
    multichoice 0, 0, MULTI_CASINO_PALDEA, 0
    switch VAR_RESULT
        case 0, Casino_Prize_Koraidon
        case 1, Casino_Prize_Miraidon
        case 2, Casino_Prize_WoChien
        case 3, Casino_Prize_ChienPao
        case 4, Casino_Prize_TingLu
        case 5, Casino_Prize_ChiYu
        case 6, Casino_Prize_Cancel

Casino_Prize_Koraidon:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 2000, Casino_NotEnoughCoins
    removecoins 2000
    createmon 0, PARTY_SIZE, SPECIES_KORAIDON, 75
    msgbox Casino_Text_GotKoraidon, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Miraidon:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 2000, Casino_NotEnoughCoins
    removecoins 2000
    createmon 0, PARTY_SIZE, SPECIES_MIRAIDON, 75
    msgbox Casino_Text_GotMiraidon, MSGBOX_DEFAULT
    release
    end

Casino_Prize_WoChien:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1400, Casino_NotEnoughCoins
    removecoins 1400
    createmon 0, PARTY_SIZE, SPECIES_WO_CHIEN, 70
    msgbox Casino_Text_GotWoChien, MSGBOX_DEFAULT
    release
    end

Casino_Prize_ChienPao:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1400, Casino_NotEnoughCoins
    removecoins 1400
    createmon 0, PARTY_SIZE, SPECIES_CHIEN_PAO, 70
    msgbox Casino_Text_GotChienPao, MSGBOX_DEFAULT
    release
    end

Casino_Prize_TingLu:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1400, Casino_NotEnoughCoins
    removecoins 1400
    createmon 0, PARTY_SIZE, SPECIES_TING_LU, 70
    msgbox Casino_Text_GotTingLu, MSGBOX_DEFAULT
    release
    end

Casino_Prize_ChiYu:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 1400, Casino_NotEnoughCoins
    removecoins 1400
    createmon 0, PARTY_SIZE, SPECIES_CHI_YU, 70
    msgbox Casino_Text_GotChiYu, MSGBOX_DEFAULT
    release
    end

Casino_Text_GotKoraidon:
    .string "Tom received KORAIDON!$"

Casino_Text_GotMiraidon:
    .string "Tom received MIRAIDON!$"

Casino_Text_GotWoChien:
    .string "Tom received WO-CHIEN!$"

Casino_Text_GotChienPao:
    .string "Tom received CHIEN-PAO!$"

Casino_Text_GotTingLu:
    .string "Tom received TING-LU!$"

Casino_Text_GotChiYu:
    .string "Tom received CHI-YU!$"


Casino_EventScript_PrizeVendor_Mythicals::
    lock
    faceplayer
    msgbox Casino_Text_PrizeVendor, MSGBOX_DEFAULT
    showcoinsbox 1, 6
    multichoice 0, 0, MULTI_CASINO_MYTHICALS, 0
    switch VAR_RESULT
        case 0, Casino_Prize_Mew
        case 1, Casino_Prize_Celebi
        case 2, Casino_Prize_Jirachi
        case 3, Casino_Prize_Deoxys
        case 4, Casino_Prize_Arceus
        case 5, Casino_Prize_Cancel

Casino_Prize_Mew:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 2000, Casino_NotEnoughCoins
    removecoins 2000
    createmon 0, PARTY_SIZE, SPECIES_MEW, 70
    msgbox Casino_Text_GotMew, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Celebi:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 2000, Casino_NotEnoughCoins
    removecoins 2000
    createmon 0, PARTY_SIZE, SPECIES_CELEBI, 70
    msgbox Casino_Text_GotCelebi, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Jirachi:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 2200, Casino_NotEnoughCoins
    removecoins 2200
    createmon 0, PARTY_SIZE, SPECIES_JIRACHI, 70
    msgbox Casino_Text_GotJirachi, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Deoxys:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 2400, Casino_NotEnoughCoins
    removecoins 2400
    createmon 0, PARTY_SIZE, SPECIES_DEOXYS, 70
    msgbox Casino_Text_GotDeoxys, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Arceus:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 3000, Casino_NotEnoughCoins
    removecoins 3000
    createmon 0, PARTY_SIZE, SPECIES_ARCEUS, 75
    msgbox Casino_Text_GotArceus, MSGBOX_DEFAULT
    release
    end

Casino_Text_GotMew:
    .string "Tom received MEW!$"

Casino_Text_GotCelebi:
    .string "Tom received CELEBI!$"

Casino_Text_GotJirachi:
    .string "Tom received JIRACHI!$"

Casino_Text_GotDeoxys:
    .string "Tom received DEOXYS!$"

Casino_Text_GotArceus:
    .string "Tom received ARCEUS!$"


Casino_EventScript_PrizeVendor_Items::
    lock
    faceplayer
    showcoinsbox 1, 6
    multichoice 0, 0, MULTI_CASINO_ITEMS, 0
    switch VAR_RESULT
        case 0, Casino_Prize_NSolarizer
        case 1, Casino_Prize_NLunarizer
        case 2, Casino_Prize_RevealGlass
        case 3, Casino_Prize_RustedSword
        case 4, Casino_Prize_RustedShield
        case 5, Casino_Prize_ReinsOfUnity
        case 6, Casino_EventScript_ItemsPage2
        case 7, Casino_Prize_Cancel

Casino_EventScript_ItemsPage2::
    multichoice 0, 0, MULTI_CASINO_ITEMS_PAGE2, 0
    switch VAR_RESULT
        case 0, Casino_Prize_DNASplicers
        case 1, Casino_Prize_Gracidea
        case 2, Casino_Prize_PrisonBottle
        case 3, Casino_Prize_AdamantOrb
        case 4, Casino_Prize_LustrousOrb
        case 5, Casino_Prize_GriseousOrb
        case 6, Casino_EventScript_PrizeVendor_Items

Casino_Prize_DNASplicers:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 50, Casino_NotEnoughCoins
    removecoins 50
    giveitem ITEM_DNA_SPLICERS
    msgbox Casino_Text_PrizeReceived, MSGBOX_DEFAULT
    release
    end

Casino_Prize_NSolarizer:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 50, Casino_NotEnoughCoins
    removecoins 50
    giveitem ITEM_N_SOLARIZER
    msgbox Casino_Text_PrizeReceived, MSGBOX_DEFAULT
    release
    end

Casino_Prize_NLunarizer:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 50, Casino_NotEnoughCoins
    removecoins 50
    giveitem ITEM_N_LUNARIZER
    msgbox Casino_Text_PrizeReceived, MSGBOX_DEFAULT
    release
    end

Casino_Prize_RevealGlass:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 50, Casino_NotEnoughCoins
    removecoins 50
    giveitem ITEM_REVEAL_GLASS
    msgbox Casino_Text_PrizeReceived, MSGBOX_DEFAULT
    release
    end

Casino_Prize_Gracidea:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 50, Casino_NotEnoughCoins
    removecoins 50
    giveitem ITEM_GRACIDEA
    msgbox Casino_Text_PrizeReceived, MSGBOX_DEFAULT
    release
    end

Casino_Prize_RustedSword:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 50, Casino_NotEnoughCoins
    removecoins 50
    giveitem ITEM_RUSTED_SWORD
    msgbox Casino_Text_PrizeReceived, MSGBOX_DEFAULT
    release
    end

Casino_Prize_RustedShield:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 50, Casino_NotEnoughCoins
    removecoins 50
    giveitem ITEM_RUSTED_SHIELD
    msgbox Casino_Text_PrizeReceived, MSGBOX_DEFAULT
    release
    end

Casino_Prize_ReinsOfUnity:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 50, Casino_NotEnoughCoins
    removecoins 50
    giveitem ITEM_REINS_OF_UNITY
    msgbox Casino_Text_PrizeReceived, MSGBOX_DEFAULT
    release
    end


Casino_Prize_PrisonBottle:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 50, Casino_NotEnoughCoins
    removecoins 50
    giveitem ITEM_PRISON_BOTTLE
    msgbox Casino_Text_PrizeReceived, MSGBOX_DEFAULT
    release
    end

Casino_Prize_AdamantOrb:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 50, Casino_NotEnoughCoins
    removecoins 50
    giveitem ITEM_ADAMANT_ORB
    msgbox Casino_Text_PrizeReceived, MSGBOX_DEFAULT
    release
    end

Casino_Prize_LustrousOrb:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 50, Casino_NotEnoughCoins
    removecoins 50
    giveitem ITEM_LUSTROUS_ORB
    msgbox Casino_Text_PrizeReceived, MSGBOX_DEFAULT
    release
    end

Casino_Prize_GriseousOrb:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 50, Casino_NotEnoughCoins
    removecoins 50
    giveitem ITEM_GRISEOUS_ORB
    msgbox Casino_Text_PrizeReceived, MSGBOX_DEFAULT
    release
    end
