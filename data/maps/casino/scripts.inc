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

Casino_EventScript_PrizeVendor::
    lock
    faceplayer
    msgbox Casino_Text_PrizeVendor, MSGBOX_DEFAULT
    showcoinsbox 1, 6
    multichoice 0, 0, MULTI_UNUSED_40, 0
    switch VAR_RESULT
        case 0, Casino_Prize_Potion
        case 1, Casino_Prize_SuperPotion
        case 2, Casino_Prize_HyperPotion
        case 3, Casino_Prize_Cancel

Casino_Text_PrizeVendor:
    .string "Welcome to the prize exchange!\n"
    .string "Which prize would you like?$"

Casino_Prize_Potion:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 50, Casino_NotEnoughCoins
    removecoins 50
    giveitem ITEM_POTION
    goto Casino_PrizeDone

Casino_Prize_SuperPotion:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 100, Casino_NotEnoughCoins
    removecoins 100
    giveitem ITEM_SUPER_POTION
    goto Casino_PrizeDone

Casino_Prize_HyperPotion:
    checkcoins VAR_TEMP_2
    goto_if_lt VAR_TEMP_2, 200, Casino_NotEnoughCoins
    removecoins 200
    giveitem ITEM_HYPER_POTION
    goto Casino_PrizeDone

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
