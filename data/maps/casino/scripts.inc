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