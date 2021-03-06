	.section .rodata

        .global gUnknown_80E2068
gUnknown_80E2068: @ 80E2068
@ replacing .incbin "baserom.gba", 0x000e2068, 0x50
        .4byte GoRescue_80E20AC
        .byte 0x00, 0x00, 0x00, 0x00
        .4byte GetHelp_80E20A0
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte Info_80E2098
        .byte 0x17, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global Exit_80E2090
        Exit_80E2090:
        .string "Exit\0"
        .align 2,0

        .global Info_80E2098
        Info_80E2098:
        .string "Info\0"
        .align 2,0

        .global GetHelp_80E20A0
        GetHelp_80E20A0:
        .string "Get Help\0"
        .align 2,0

        .global GoRescue_80E20AC
        GoRescue_80E20AC:
        .string "Go Rescue\0"
        .align 2,0

	.global gUnknown_80E20B8
gUnknown_80E20B8: @ 80E20B8
@ replacing .incbin "baserom.gba", 0x000e20b8, 0x28
        .4byte GoRescue_80E20AC
        .byte 0x00, 0x00, 0x00, 0x00
        .4byte GetHelp_80E20A0
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte Info_80E2098
        .byte 0x17, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E20E0
gUnknown_80E20E0: @ 80E20E0
@ replacing .incbin "baserom.gba", 0x000e20e0, 0x28
        .4byte GoRescue_80E20AC
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte GetHelp_80E20A0
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte Info_80E2098
        .byte 0x17, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E2108
gUnknown_80E2108: @ 80E2108
@ replacing .incbin "baserom.gba", 0x000e2108, 0x28
        .4byte GoRescue_80E20AC
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte GetHelp_80E20A0
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte Info_80E2098
        .byte 0x17, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E2130
gUnknown_80E2130: @ 80E2130
        @ Friend Resuce Pelipper Menu
@ replacing .incbin "baserom.gba", 0x000e2130, 0x60
        .4byte ReceiveSOSMail_80E217C
        .byte 0x03, 0x00, 0x00, 0x00
        .4byte SendAOKMail_80E216C
        .byte 0x04, 0x00, 0x00, 0x00
        .4byte GetThankYouMail_80E2158
        .byte 0x14, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global GetThankYouMail_80E2158
        GetThankYouMail_80E2158:
        .string "Get Thank-You Mail\0"
        .align 2,0

        .global SendAOKMail_80E216C
        SendAOKMail_80E216C:
        .string "Send A-OK Mail\0"
        .align 2,0

        .global ReceiveSOSMail_80E217C
        ReceiveSOSMail_80E217C:
        .string "Receive SOS Mail\0"
        .align 2,0

	.global gUnknown_80E2190
gUnknown_80E2190: @ 80E2190
@ replacing .incbin "baserom.gba", 0x000e2190, 0x28
        .4byte ReceiveSOSMail_80E217C
        .byte 0x03, 0x00, 0x00, 0x00
        .4byte SendAOKMail_80E216C
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte GetThankYouMail_80E2158
        .byte 0x14, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E21B8
gUnknown_80E21B8: @ 80E21B8
@ replacing .incbin "baserom.gba", 0x000e21b8, 0x60
        .4byte SendSOS_80E2208
        .byte 0x11, 0x00, 0x00, 0x00
        .4byte ReceiveAOK_80E21F4
        .byte 0x12, 0x00, 0x00, 0x00
        .4byte SendThankYou_80E21E0
        .byte 0x13, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global SendThankYou_80E21E0
        SendThankYou_80E21E0:
        .string "Send Thank-You Mail\0"
        .align 2,0

        .global ReceiveAOK_80E21F4
        ReceiveAOK_80E21F4:
        .string "Receive A-OK Mail\0"
        .align 2,0

        .global SendSOS_80E2208
        SendSOS_80E2208:
        .string "Send SOS Mail\0"
        .align 2,0

	.global gUnknown_80E2218
gUnknown_80E2218: @ 80E2218
@ replacing .incbin "baserom.gba", 0x000e2218, 0x28
        .4byte SendSOS_80E2208
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte ReceiveAOK_80E21F4
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte SendThankYou_80E21E0
        .byte 0x13, 0x00, 0x00, 0x00
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E2240
gUnknown_80E2240: @ 80E2240
@ replacing .incbin "baserom.gba", 0x000e2240, 0x28
        .4byte SendSOS_80E2208
        .byte 0x11, 0x00, 0x00, 0x00
        .4byte ReceiveAOK_80E21F4
        .byte 0x12, 0x00, 0x00, 0x00
        .4byte SendThankYou_80E21E0
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E2268
gUnknown_80E2268: @ 80E2268
@ replacing .incbin "baserom.gba", 0x000e2268, 0x28
        .4byte SendSOS_80E2208
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte ReceiveAOK_80E21F4
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte SendThankYou_80E21E0
        .byte 0xff, 0xff, 0xff, 0xff
        .4byte Exit_80E2090
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E2290
gUnknown_80E2290: @ 80E2290
@ replacing .incbin "baserom.gba", 0x000e2290, 0x24
        .4byte Yes_80E22B0
        .byte 0x06, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global Cancel_80E22A8
        Cancel_80E22A8:
        .string "Cancel\0"
        .align 2,0

        .global Yes_80E22B0
        Yes_80E22B0:
        .string "Yes\0"
        .align 2,0

	.global gUnknown_80E22B4
gUnknown_80E22B4: @ 80E22B4
@ replacing .incbin "baserom.gba", 0x000e22b4, 0x1c
        .4byte Yes_80E22B0
        .byte 0x06, 0x00, 0x00, 0x00
        .4byte No_80E22CC
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global No_80E22CC
        No_80E22CC:
        .string "No\0"
        .align 2,0

	.global gUnknown_80E22D0
gUnknown_80E22D0: @ 80E22D0
@ replacing .incbin "baserom.gba", 0x000e22d0, 0x20
        .4byte Yes_80E22B0
        .byte 0x06, 0x00, 0x00, 0x00
        .4byte No_80E22CC
        .byte 0x07, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E22F0
gUnknown_80E22F0: @ 80E22F0
@ replacing .incbin "baserom.gba", 0x000e22f0, 0x2c
        .4byte SendPokemon_80E2308
        .byte 0x10, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global SendPokemon_80E2308
        SendPokemon_80E2308:
        .string "Send w/o Pokémon\0"
        .align 2,0

	.global gUnknown_80E231C
gUnknown_80E231C: @ 80E231C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x07, 0x00
        .byte 0x06, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E2334
gUnknown_80E2334: @ 80E2334
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x06, 0x00
        .byte 0x06, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E234C
gUnknown_80E234C: @ 80E234C
        .4byte Confirm_80E2364
        .byte 0x09, 0x00, 0x00, 0x00
        .4byte Info_80E2098
        .byte 0x0a, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00
        .global Confirm_80E2364
        Confirm_80E2364:
        .string "Confirm\0"
        .align 2,0

	.global gUnknown_80E236C
gUnknown_80E236C: @ 80E236C
        .4byte GameLinkCable_80E2398
        .byte 0x0b, 0x00, 0x00, 0x00
        .4byte Password_80E238C
        .byte 0x0d, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global Password_80E238C
        Password_80E238C:
        .string "Password\0"
        .align 2,0
        .global GameLinkCable_80E2398
        GameLinkCable_80E2398:
        .string "Game Link cable\0"
        .align 2,0

	.global gUnknown_80E23A8
gUnknown_80E23A8: @ 80E23A8
@ replacing .incbin "baserom.gba", 0x000e23a8, 0x48
        .4byte SendPokemon_80E23E0
        .byte 0x0f, 0x00, 0x00, 0x00
        .4byte DontSendPokemon_80E23C8
        .byte 0x10, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .global DontSendPokemon_80E23C8
        DontSendPokemon_80E23C8:
        .string "Don~27t Send Pokémon\0"
        .align 2,0

        .global SendPokemon_80E23E0
        SendPokemon_80E23E0:
        .string "Send Pokémon\0"
        .align 2,0

	.global gUnknown_80E23F0
gUnknown_80E23F0: @ 80E23F0
        @ replacing .incbin "baserom.gba", 0x000e23f0, 0x18
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E2408
gUnknown_80E2408: @ 80E2408
        @ replacing .incbin "baserom.gba", 0x000e2408, 0x38
        .4byte Confirm_80E2364
        .byte 0x09, 0x00, 0x00, 0x00
        .4byte Info_80E2098
        .byte 0x0a, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E2440
gUnknown_80E2440: @ 80E2440
        @ replacing .incbin "baserom.gba", 0x000e2440, 0x18
        .4byte Yes_80E22B0
        .byte 0x06, 0x00, 0x00, 0x00
        .4byte Cancel_80E22A8
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E2458
gUnknown_80E2458: @ 80E2458
        @ replacing .incbin "baserom.gba", 0x000e2458, 0x18
        .4byte Yes_80E22B0
        .byte 0x06, 0x00, 0x00, 0x00
        .4byte No_80E22CC
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00

	.global gUnknown_80E2470
gUnknown_80E2470: @ 80E2470
        @ replacing .incbin "baserom.gba", 0x000e2470, 0x40
        .byte 0xa4, 0x24, 0x0e, 0x08
        .byte 0x15, 0x00, 0x00, 0x00
        .byte 0x90, 0x24, 0x0e, 0x08
        .byte 0x16, 0x00, 0x00, 0x00
        .byte 0xa8, 0x22, 0x0e, 0x08
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x44, 0x6f, 0x6e, 0x7e, 0x32, 0x37, 0x74, 0x20, 0x53, 0x65, 0x6e, 0x64, 0x20, 0x49, 0x74, 0x65, 0x6d, 0x00, 0x00, 0x00
        .byte 0x53, 0x65, 0x6e, 0x64, 0x20, 0x49, 0x74, 0x65, 0x6d, 0x00, 0x00, 0x00


	.global gUnknown_80E24B0
gUnknown_80E24B0: @ 80E24B0
	.incbin "baserom.gba", 0xE24B0, 0x28

	.global gUnknown_80E24D8
gUnknown_80E24D8: @ 80E24D8
	.incbin "baserom.gba", 0xE24D8, 0x20

	.global gUnknown_80E24F8
gUnknown_80E24F8: @ 80E24F8
	.incbin "baserom.gba", 0xE24F8, 0x5C

	.global gUnknown_80E2554
gUnknown_80E2554: @ 80E2554
	.incbin "baserom.gba", 0xE2554, 0x60

	.global gUnknown_80E25B4
gUnknown_80E25B4: @ 80E25B4
	.incbin "baserom.gba", 0xE25B4, 0x40

	.global gUnknown_80E25F4
gUnknown_80E25F4: @ 80E25F4
        .string "What would you like to do?\0"
        .align 2,0

	.global gUnknown_80E2610
gUnknown_80E2610: @ 80E2610
	.incbin "baserom.gba", 0xE2610, 0x30

	.global gUnknown_80E2640
gUnknown_80E2640: @ 80E2640
	.incbin "baserom.gba", 0xE2640, 0x40

	.global gUnknown_80E2680
gUnknown_80E2680: @ 80E2680
	.incbin "baserom.gba", 0xE2680, 0x30

	.global gUnknown_80E26B0
gUnknown_80E26B0: @ 80E26B0
	.incbin "baserom.gba", 0xE26B0, 0x40

	.global gUnknown_80E26F0
gUnknown_80E26F0: @ 80E26F0
	.incbin "baserom.gba", 0xE26F0, 0x38

	.global gUnknown_80E2728
gUnknown_80E2728: @ 80E2728
	.incbin "baserom.gba", 0xE2728, 0x44

	.global gUnknown_80E276C
gUnknown_80E276C: @ 80E276C
	.incbin "baserom.gba", 0xE276C, 0x38

	.global gUnknown_80E27A4
gUnknown_80E27A4: @ 80E27A4
	.incbin "baserom.gba", 0xE27A4, 0x70

	.global gUnknown_80E2814
gUnknown_80E2814: @ 80E2814
	.incbin "baserom.gba", 0xE2814, 0x2C

	.global gUnknown_80E2840
gUnknown_80E2840: @ 80E2840
	.incbin "baserom.gba", 0xE2840, 0x34

	.global gUnknown_80E2874
gUnknown_80E2874: @ 80E2874
	.incbin "baserom.gba", 0xE2874, 0x24

	.global gUnknown_80E2898
gUnknown_80E2898: @ 80E2898
	.incbin "baserom.gba", 0xE2898, 0x40

	.global gUnknown_80E28D8
gUnknown_80E28D8: @ 80E28D8
	.incbin "baserom.gba", 0xE28D8, 0x2C

	.global gUnknown_80E2904
gUnknown_80E2904: @ 80E2904
	.incbin "baserom.gba", 0xE2904, 0x68

	.global gUnknown_80E296C
gUnknown_80E296C: @ 80E296C
	.incbin "baserom.gba", 0xE296C, 0x34

	.global gUnknown_80E29A0
gUnknown_80E29A0: @ 80E29A0
	.incbin "baserom.gba", 0xE29A0, 0x30

	.global gUnknown_80E29D0
gUnknown_80E29D0: @ 80E29D0
	.incbin "baserom.gba", 0xE29D0, 0x3C

	.global gUnknown_80E2A0C
gUnknown_80E2A0C: @ 80E2A0C
        .asciz "Save completed."
        .align 2,0

	.global gUnknown_80E2A1C
gUnknown_80E2A1C: @ 80E2A1C
	.incbin "baserom.gba", 0xE2A1C, 0x40

	.global gUnknown_80E2A5C
gUnknown_80E2A5C: @ 80E2A5C
        .asciz "Here is the #CGSOS Mail password#R."
        .align 2,0

	.global gUnknown_80E2A80
gUnknown_80E2A80: @ 80E2A80
        .asciz "Here is the #CGA-OK Mail password#R."
        .align 2,0

	.global gUnknown_80E2AA8
gUnknown_80E2AA8: @ 80E2AA8
	.incbin "baserom.gba", 0xE2AA8, 0x3C

	.global gUnknown_80E2AE4
gUnknown_80E2AE4: @ 80E2AE4
	.incbin "baserom.gba", 0xE2AE4, 0x70

	.global gUnknown_80E2B54
gUnknown_80E2B54: @ 80E2B54
	.incbin "baserom.gba", 0xE2B54, 0x3C

	.global gUnknown_80E2B90
gUnknown_80E2B90: @ 80E2B90
	.incbin "baserom.gba", 0xE2B90, 0x50

	.global gUnknown_80E2BE0
gUnknown_80E2BE0: @ 80E2BE0
	.incbin "baserom.gba", 0xE2BE0, 0x68

	.global gUnknown_80E2C48
gUnknown_80E2C48: @ 80E2C48
	.incbin "baserom.gba", 0xE2C48, 0x4C

	.global gUnknown_80E2C94
gUnknown_80E2C94: @ 80E2C94
	.incbin "baserom.gba", 0xE2C94, 0x40

	.global gUnknown_80E2CD4
gUnknown_80E2CD4: @ 80E2CD4
	.incbin "baserom.gba", 0xE2CD4, 0x14

	.global gUnknown_80E2CE8
gUnknown_80E2CE8: @ 80E2CE8
	.incbin "baserom.gba", 0xE2CE8, 0x48

	.global gUnknown_80E2D30
gUnknown_80E2D30: @ 80E2D30
	.incbin "baserom.gba", 0xE2D30, 0x30

	.global gUnknown_80E2D60
gUnknown_80E2D60: @ 80E2D60
        .asciz "There is no #CGA-OK Mail#R."
        .align 2,0

	.global gUnknown_80E2D7C
gUnknown_80E2D7C: @ 80E2D7C
	.incbin "baserom.gba", 0xE2D7C, 0x54

	.global gUnknown_80E2DD0
gUnknown_80E2DD0: @ 80E2DD0
	.incbin "baserom.gba", 0xE2DD0, 0x50

	.global gUnknown_80E2E20
gUnknown_80E2E20: @ 80E2E20
	.incbin "baserom.gba", 0xE2E20, 0x34

	.global gUnknown_80E2E54
gUnknown_80E2E54: @ 80E2E54
	.incbin "baserom.gba", 0xE2E54, 0x60

	.global gUnknown_80E2EB4
gUnknown_80E2EB4: @ 80E2EB4
	.incbin "baserom.gba", 0xE2EB4, 0x60

	.global gUnknown_80E2F14
gUnknown_80E2F14: @ 80E2F14
	.incbin "baserom.gba", 0xE2F14, 0x30

	.global gUnknown_80E2F44
gUnknown_80E2F44: @ 80E2F44
	.incbin "baserom.gba", 0xE2F44, 0x34

	.global gUnknown_80E2F78
gUnknown_80E2F78: @ 80E2F78
	.incbin "baserom.gba", 0xE2F78, 0x28

	.global gUnknown_80E2FA0
gUnknown_80E2FA0: @ 80E2FA0
	.incbin "baserom.gba", 0xE2FA0, 0x4C

	.global gUnknown_80E2FEC
gUnknown_80E2FEC: @ 80E2FEC
	.incbin "baserom.gba", 0xE2FEC, 0x44

	.global gUnknown_80E3030
gUnknown_80E3030: @ 80E3030
	.incbin "baserom.gba", 0xE3030, 0x48

	.global gUnknown_80E3078
gUnknown_80E3078: @ 80E3078
	.incbin "baserom.gba", 0xE3078, 0x2C

	.global gUnknown_80E30A4
gUnknown_80E30A4: @ 80E30A4
	.incbin "baserom.gba", 0xE30A4, 0x2C

	.global gUnknown_80E30D0
gUnknown_80E30D0: @ 80E30D0
	.incbin "baserom.gba", 0xE30D0, 0x4C

	.global gUnknown_80E311C
gUnknown_80E311C: @ 80E311C
	.incbin "baserom.gba", 0xE311C, 0x30

	.global gUnknown_80E314C
gUnknown_80E314C: @ 80E314C
	.incbin "baserom.gba", 0xE314C, 0x30

	.global gUnknown_80E317C
gUnknown_80E317C: @ 80E317C
        .string "Your adventure will be saved.\0"
        .align 2,0

	.global gUnknown_80E319C
gUnknown_80E319C: @ 80E319C
	.incbin "baserom.gba", 0xE319C, 0x3C

	.global gUnknown_80E31D8
gUnknown_80E31D8: @ 80E31D8
        .string "All preparations have been made.\0"
        .align 2,0

	.global gUnknown_80E31FC
gUnknown_80E31FC: @ 80E31FC
        .string "The #CGThank-You Mail#R was sent.\0"
        .align 2,0

	.global gUnknown_80E3220
gUnknown_80E3220: @ 80E3220
        .string "You received the #CGThank-You Mail#R.\0"
        .align 2,0

	.global gUnknown_80E3248
gUnknown_80E3248: @ 80E3248
	.incbin "baserom.gba", 0xE3248, 0x40

	.global gUnknown_80E3288
gUnknown_80E3288: @ 80E3288
	.incbin "baserom.gba", 0xE3288, 0x3C

	.global gUnknown_80E32C4
gUnknown_80E32C4: @ 80E32C4
	.incbin "baserom.gba", 0xE32C4, 0x58

	.global gUnknown_80E331C
gUnknown_80E331C: @ 80E331C
	.incbin "baserom.gba", 0xE331C, 0x5C

	.global gUnknown_80E3378
gUnknown_80E3378: @ 80E3378
        .string "Please choose the item to be sent.\0"
        .align 2,0

	.global gUnknown_80E339C
gUnknown_80E339C: @ 80E339C
	.incbin "baserom.gba", 0xE339C, 0x3C

	.global gUnknown_80E33D8
gUnknown_80E33D8: @ 80E33D8
	.incbin "baserom.gba", 0xE33D8, 0x58

	.global gUnknown_80E3430
gUnknown_80E3430: @ 80E3430
	.incbin "baserom.gba", 0xE3430, 0x80

	.global gUnknown_80E34B0
gUnknown_80E34B0: @ 80E34B0
	.incbin "baserom.gba", 0xE34B0, 0x40

	.global gUnknown_80E34F0
gUnknown_80E34F0: @ 80E34F0
	.incbin "baserom.gba", 0xE34F0, 0x3C

	.global gUnknown_80E352C
gUnknown_80E352C: @ 80E352C
        .string "Is it OK to accept this #CGThank-You Mail#R?\0"
        .align 2,0

	.global gUnknown_80E355C
gUnknown_80E355C: @ 80E355C
	.incbin "baserom.gba", 0xE355C, 0x50

	.global gUnknown_80E35AC
gUnknown_80E35AC: @ 80E35AC
	.incbin "baserom.gba", 0xE35AC, 0x3C

	.global gUnknown_80E35E8
gUnknown_80E35E8: @ 80E35E8
        .string "There is no #CGThank-You Mail#R.\0"
        .align 2,0

	.global gUnknown_80E360C
gUnknown_80E360C: @ 80E360C
	.incbin "baserom.gba", 0xE360C, 0x38

	.global gUnknown_80E3644
gUnknown_80E3644: @ 80E3644
	.incbin "baserom.gba", 0xE3644, 0x38

	.global gUnknown_80E367C
gUnknown_80E367C: @ 80E367C
        .string "Read which Info?\0"
        .align 2,0

	.global gUnknown_80E3690
gUnknown_80E3690: @ 80E3690
	.incbin "baserom.gba", 0xE3690, 0x188

	.global gUnknown_80E3818
gUnknown_80E3818: @ 80E3818
	.incbin "baserom.gba", 0xE3818, 0x180

	.global gUnknown_80E3998
gUnknown_80E3998: @ 80E3998
	.incbin "baserom.gba", 0xE3998, 0x184

	.global gUnknown_80E3B1C
gUnknown_80E3B1C: @ 80E3B1C
	.incbin "baserom.gba", 0xE3B1C, 0xDC

	.global gUnknown_80E3BF8
gUnknown_80E3BF8: @ 80E3BF8
	.incbin "baserom.gba", 0xE3BF8, 0x1EC

	.global gUnknown_80E3DE4
gUnknown_80E3DE4: @ 80E3DE4
	.incbin "baserom.gba", 0xE3DE4, 0xB4

	.global gUnknown_80E3E98
gUnknown_80E3E98: @ 80E3E98
	.incbin "baserom.gba", 0xE3E98, 0x17C

	.global gUnknown_80E4014
gUnknown_80E4014: @ 80E4014
	.incbin "baserom.gba", 0xE4014, 0x11C

	.global gUnknown_80E4130
gUnknown_80E4130: @ 80E4130
	.incbin "baserom.gba", 0xE4130, 0xAC

	.global gUnknown_80E41DC
gUnknown_80E41DC: @ 80E41DC
	.incbin "baserom.gba", 0xE41DC, 0x138

	.global gUnknown_80E4314
gUnknown_80E4314: @ 80E4314
	.incbin "baserom.gba", 0xE4314, 0x16C

	.global gUnknown_80E4480
gUnknown_80E4480: @ 80E4480
        .string "There was a communication error.\0"
        .align 2,0

	.global gUnknown_80E44A4
gUnknown_80E44A4: @ 80E44A4
	.incbin "baserom.gba", 0xE44A4, 0x5C

	.global gUnknown_80E4500
gUnknown_80E4500: @ 80E4500
	.incbin "baserom.gba", 0xE4500, 0x50

	.global gUnknown_80E4550
gUnknown_80E4550: @ 80E4550
	.incbin "baserom.gba", 0xE4550, 0x64

	.global gUnknown_80E45B4
gUnknown_80E45B4: @ 80E45B4
	.incbin "baserom.gba", 0xE45B4, 0x58

	.global gUnknown_80E460C
gUnknown_80E460C: @ 80E460C
	.incbin "baserom.gba", 0xE460C, 0x44

	.global gUnknown_80E4650
gUnknown_80E4650: @ 80E4650
	.incbin "baserom.gba", 0xE4650, 0x3C

	.global gUnknown_80E468C
gUnknown_80E468C: @ 80E468C
	.incbin "baserom.gba", 0xE468C, 0x3C

	.global gUnknown_80E46C8
gUnknown_80E46C8: @ 80E46C8
	.incbin "baserom.gba", 0xE46C8, 0x3C

	.global gUnknown_80E4704
gUnknown_80E4704: @ 80E4704
	.incbin "baserom.gba", 0xE4704, 0x40

	.global gUnknown_80E4744
gUnknown_80E4744: @ 80E4744
	.incbin "baserom.gba", 0xE4744, 0x44

	.global gUnknown_80E4788
gUnknown_80E4788: @ 80E4788
	.incbin "baserom.gba", 0xE4788, 0x50

	.global gUnknown_80E47D8
gUnknown_80E47D8: @ 80E47D8
	.incbin "baserom.gba", 0xE47D8, 0x54

	.global gUnknown_80E482C
gUnknown_80E482C: @ 80E482C
	.incbin "baserom.gba", 0xE482C, 0x7C

	.global gUnknown_80E48A8
gUnknown_80E48A8: @ 80E48A8
	.incbin "baserom.gba", 0xE48A8, 0x40

	.global gUnknown_80E48E8
gUnknown_80E48E8: @ 80E48E8
	.incbin "baserom.gba", 0xE48E8, 0x40

	.global gUnknown_80E4928
gUnknown_80E4928: @ 80E4928
	.incbin "baserom.gba", 0xE4928, 0x3C

	.global gUnknown_80E4964
gUnknown_80E4964: @ 80E4964
	.incbin "baserom.gba", 0xE4964, 0x38

	.global gUnknown_80E499C
gUnknown_80E499C: @ 80E499C
	.incbin "baserom.gba", 0xE499C, 0x28

	.global gUnknown_80E49C4
gUnknown_80E49C4: @ 80E49C4
	.incbin "baserom.gba", 0xE49C4, 0x4C

	.global gUnknown_80E4A10
gUnknown_80E4A10: @ 80E4A10
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E4A28
gUnknown_80E4A28: @ 80E4A28
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1a, 0x00, 0x10, 0x00
        .byte 0x10, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E4A40
gUnknown_80E4A40: @ 80E4A40
@ replacing .incbin "baserom.gba", 0x000e4a40, 0xedc
        .byte 0x18, 0x18
        .byte 0x38, 0x00
        .byte 0x21, 0xff
        .byte 0x22, 0xff
        .byte 0x23, 0xff
        .byte 0x24, 0xff
        .byte 0x25, 0xff
        .byte 0x26, 0xff
        .byte 0x27, 0xff
        .byte 0x28, 0xff
        .byte 0x29, 0xff
        .byte 0x2a, 0xff
        .byte 0x2b, 0xff
        .byte 0x2c, 0xff
        .byte 0x2d, 0xff
        .byte 0x2e, 0xff
        .byte 0x2f, 0xff
        .byte 0x30, 0xff
        .byte 0x31, 0xff
        .byte 0x32, 0xff
        .byte 0x33, 0xff
        .byte 0x34, 0xff
        .byte 0x35, 0xff
        .byte 0x36, 0xff
        .byte 0x37, 0xff
        .byte 0x38, 0xff
        .byte 0x39, 0xff
        .byte 0x3a, 0xff
        .byte 0x41, 0xff
        .byte 0x42, 0xff
        .byte 0x43, 0xff
        .byte 0x44, 0xff
        .byte 0x45, 0xff
        .byte 0x46, 0xff
        .byte 0x47, 0xff
        .byte 0x48, 0xff
        .byte 0x49, 0xff
        .byte 0x4a, 0xff
        .byte 0x4b, 0xff
        .byte 0x4c, 0xff
        .byte 0x4d, 0xff
        .byte 0x4e, 0xff
        .byte 0x4f, 0xff
        .byte 0x50, 0xff
        .byte 0x51, 0xff
        .byte 0x52, 0xff
        .byte 0x53, 0xff
        .byte 0x54, 0xff
        .byte 0x55, 0xff
        .byte 0x56, 0xff
        .byte 0x57, 0xff
        .byte 0x58, 0xff
        .byte 0x59, 0xff
        .byte 0x5a, 0xff
        .byte 0x10, 0xff
        .byte 0x11, 0xff
        .byte 0x12, 0xff
        .byte 0x13, 0xff
        .byte 0x14, 0xff
        .byte 0x15, 0xff
        .byte 0x16, 0xff
        .byte 0x17, 0xff
        .byte 0x18, 0xff
        .byte 0x19, 0xff

        .include "data/text/credits.inc"

	.global gUnknown_80E5990
gUnknown_80E5990: @ 80E5990
        .byte 0x06, 0x02
        .byte 0x40, 0x00
        .byte 0x80, 0x00
        .byte 0x10, 0x00
        .byte 0x20, 0x00
        .byte 0x01, 0x00
        .byte 0x02, 0x00
        .byte 0x00, 0x00
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E59A8
gUnknown_80E59A8: @ 80E59A8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E59C8
gUnknown_80E59C8: @ 80E59C8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E59E0
gUnknown_80E59E0: @ 80E59E0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0A, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E59F8
gUnknown_80E59F8: @ 80E59F8
	.incbin "baserom.gba", 0xE59F8, 0x68

	.global gUnknown_80E5A60
gUnknown_80E5A60: @ 80E5A60
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0A, 0x00, 0x08, 0x00
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E5A78
gUnknown_80E5A78: @ 80E5A78
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0B, 0x00, 0x09, 0x00
        .byte 0x09, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E5A90
gUnknown_80E5A90: @ 80E5A90
	.incbin "baserom.gba", 0xE5A90, 0x6C

	.global gUnknown_80E5AFC
gUnknown_80E5AFC: @ 80E5AFC
	.incbin "baserom.gba", 0xE5AFC, 0x38

	.global gUnknown_80E5B34
gUnknown_80E5B34: @ 80E5B34
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0A, 0x00, 0x08, 0x00
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E5B4C
gUnknown_80E5B4C: @ 80E5B4C
	.incbin "baserom.gba", 0xE5B4C, 0x40

	.global gUnknown_80E5B8C
gUnknown_80E5B8C: @ 80E5B8C
	.incbin "baserom.gba", 0xE5B8C, 0x38

	.global gUnknown_80E5BC4
gUnknown_80E5BC4: @ 80E5BC4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0A, 0x00, 0x08, 0x00
        .byte 0x08, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E5BDC
gUnknown_80E5BDC: @ 80E5BDC
	.incbin "baserom.gba", 0xE5BDC, 0x3C

	.global gUnknown_80E5C18
gUnknown_80E5C18: @ 80E5C18
	.incbin "baserom.gba", 0xE5C18, 0x9C

	.global gUnknown_80E5CB4
gUnknown_80E5CB4: @ 80E5CB4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x0F, 0x00
        .byte 0x1A, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E5CCC
gUnknown_80E5CCC: @ 80E5CCC
	.incbin "baserom.gba", 0xE5CCC, 0x40

	.global gUnknown_80E5D0C
gUnknown_80E5D0C: @ 80E5D0C
	.incbin "baserom.gba", 0xE5D0C, 0x3C

	.global gUnknown_80E5D48
gUnknown_80E5D48: @ 80E5D48
	.incbin "baserom.gba", 0xE5D48, 0x58

	.global gUnknown_80E5DA0
gUnknown_80E5DA0: @ 80E5DA0
	.incbin "baserom.gba", 0xE5DA0, 0x50

	.global gUnknown_80E5DF0
gUnknown_80E5DF0: @ 80E5DF0
	.incbin "baserom.gba", 0xE5DF0, 0x6C

	.global gUnknown_80E5E5C
gUnknown_80E5E5C: @ 80E5E5C
	.incbin "baserom.gba", 0xE5E5C, 0x60

	.global gUnknown_80E5EBC
gUnknown_80E5EBC: @ 80E5EBC
	.incbin "baserom.gba", 0xE5EBC, 0x60

	.global gUnknown_80E5F1C
gUnknown_80E5F1C: @ 80E5F1C
	.incbin "baserom.gba", 0xE5F1C, 0x64

	.global gUnknown_80E5F80
gUnknown_80E5F80: @ 80E5F80
	.incbin "baserom.gba", 0xE5F80, 0x4C

	.global gUnknown_80E5FCC
gUnknown_80E5FCC: @ 80E5FCC
	.incbin "baserom.gba", 0xE5FCC, 0x64

	.global gUnknown_80E6030
gUnknown_80E6030: @ 80E6030
	.incbin "baserom.gba", 0xE6030, 0x70

@ Start of Trade Items Data

	.global gUnknown_80E60A0
gUnknown_80E60A0: @ 80E60A0
        .4byte SendItem_80E60C8
        .4byte 1
        .4byte ReceiveItem_80E60B8
        .4byte 2
        .4byte 0
        .4byte 0

        .global ReceiveItem_80E60B8
        ReceiveItem_80E60B8:
        .asciz "Receive item"
        .align 2,0

        .global SendItem_80E60C8
        SendItem_80E60C8:
        .asciz "Send item"
        .align 2,0

	.global gUnknown_80E60D4
gUnknown_80E60D4: @ 80E60D4
        .4byte SendItem_80E60C8
        .4byte -1
        .4byte ReceiveItem_80E60B8
        .4byte 2
        .4byte 0
        .4byte 0

	.global gUnknown_80E60EC
gUnknown_80E60EC: @ 80E60EC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x04, 0x00
        .byte 0x06, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6104
gUnknown_80E6104: @ 80E6104
        .4byte Confirm_80E6134
        .4byte 3
        .4byte Info_80E612C
        .4byte 4
        .4byte Cancel_80E6124
        .4byte 7
        .4byte 0
        .4byte 0

        .global Cancel_80E6124
        Cancel_80E6124:
        .asciz "Cancel"
        .align 2,0


        .global Info_80E612C
        Info_80E612C:
        .asciz "Info"
        .align 2,0

        .global Confirm_80E6134
        Confirm_80E6134:
        .asciz "Confirm"
        .align 2,0

        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x16, 0x00, 0x09, 0x00
        .byte 0x05, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6154
gUnknown_80E6154: @ 80E6154
        .4byte Yes_80E6170
        .4byte 5
        .4byte No_80E616C
        .4byte 6
        .4byte 0
        .4byte 0

        .global No_80E616C
        No_80E616C:
        .asciz "No"
        .align 2,0

        .global Yes_80E6170
        Yes_80E6170:
        .asciz "Yes"
        .align 2,0

	.global gUnknown_80E6174
gUnknown_80E6174: @ 80E6174
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x0D, 0x00
        .byte 0x06, 0x00, 0x04, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E618C
gUnknown_80E618C: @ 80E618C
        .4byte Yes_80E6170
        .4byte 5
        .4byte Cancel_80E6124
        .4byte 0
        .4byte 0
        .4byte 0

	.global gUnknown_80E61A4
gUnknown_80E61A4: @ 80E61A4
        .asciz "What would you like to do? "
        .align 2,0

	.global gUnknown_80E61C0
gUnknown_80E61C0: @ 80E61C0
        .asciz "Please choose the item to be sent."
        .align 2,0

	.global gUnknown_80E61E4
gUnknown_80E61E4: @ 80E61E4
	.incbin "baserom.gba", 0xE61E4, 0x30

	.global gUnknown_80E6214
gUnknown_80E6214: @ 80E6214
	.incbin "baserom.gba", 0xE6214, 0x54

	.global gUnknown_80E6268
gUnknown_80E6268: @ 80E6268
	.incbin "baserom.gba", 0xE6268, 0x5C

	.global gUnknown_80E62C4
gUnknown_80E62C4: @ 80E62C4
	.incbin "baserom.gba", 0xE62C4, 0x50

	.global gUnknown_80E6314
gUnknown_80E6314: @ 80E6314
	.incbin "baserom.gba", 0xE6314, 0x44

	.global gUnknown_80E6358
gUnknown_80E6358: @ 80E6358
	.incbin "baserom.gba", 0xE6358, 0x20

@ Trade Items Link Errors
	.global gTradeItemsCommunicationError
gTradeItemsCommunicationError: @ 80E6378
        .asciz "There was a communication error."
        .align 2,0

	.global gUnknown_80E639C
gUnknown_80E639C: @ 80E639C
	.incbin "baserom.gba", 0xE639C, 0x5C

	.global gUnknown_80E63F8
gUnknown_80E63F8: @ 80E63F8
	.incbin "baserom.gba", 0xE63F8, 0x50

	.global gUnknown_80E6448
gUnknown_80E6448: @ 80E6448
	.incbin "baserom.gba", 0xE6448, 0x64

	.global gUnknown_80E64AC
gUnknown_80E64AC: @ 80E64AC
	.incbin "baserom.gba", 0xE64AC, 0x7C

	.global gTradeItemsHowManyText
gTradeItemsHowManyText: @ 80E6528
        .asciz "How many?"
        .align 2,0
        .asciz "pksdir0"

@ End of Trade Menu Data

	.global gUnknown_80E653C
gUnknown_80E653C: @ 80E653C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6554
gUnknown_80E6554: @ 80E6554
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00


	.global gUnknown_80E656C
gUnknown_80E656C: @ 80E656C
	.incbin "baserom.gba", 0xE656C, 0x6C

	.global gUnknown_80E65D8
gUnknown_80E65D8: @ 80E65D8
	.incbin "baserom.gba", 0xE65D8, 0x44

	.global gUnknown_80E661C
gUnknown_80E661C: @ 80E661C
	.incbin "baserom.gba", 0xE661C, 0x40

	.global gUnknown_80E665C
gUnknown_80E665C: @ 80E665C
	.incbin "baserom.gba", 0xE665C, 0x20

	.global gUnknown_80E667C
gUnknown_80E667C: @ 80E667C
	.incbin "baserom.gba", 0xE667C, 0x40

	.global gUnknown_80E66BC
gUnknown_80E66BC: @ 80E66BC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E66D4
gUnknown_80E66D4: @ 80E66D4
	.incbin "baserom.gba", 0xE66D4, 0x74

	.global gUnknown_80E6748
gUnknown_80E6748: @ 80E6748
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6760
gUnknown_80E6760: @ 80E6760
	.incbin "baserom.gba", 0xE6760, 0x74

	.global gUnknown_80E67D4
gUnknown_80E67D4: @ 80E67D4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E67EC
gUnknown_80E67EC: @ 80E67EC
	.incbin "baserom.gba", 0xE67EC, 0xB0

	.global gUnknown_80E689C
gUnknown_80E689C: @ 80E689C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E68B4
gUnknown_80E68B4: @ 80E68B4
	.incbin "baserom.gba", 0xE68B4, 0x84

	.global gUnknown_80E6938
gUnknown_80E6938: @ 80E6938
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6950
gUnknown_80E6950: @ 80E6950
	.incbin "baserom.gba", 0xE6950, 0x60

	.global gUnknown_80E69B0
gUnknown_80E69B0: @ 80E69B0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E69C8
gUnknown_80E69C8: @ 80E69C8
	.incbin "baserom.gba", 0xE69C8, 0x48

	.global gUnknown_80E6A10
gUnknown_80E6A10: @ 80E6A10
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6A28
gUnknown_80E6A28: @ 80E6A28
	.incbin "baserom.gba", 0xE6A28, 0x4C

	.global gUnknown_80E6A74
gUnknown_80E6A74: @ 80E6A74
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6A8C
gUnknown_80E6A8C: @ 80E6A8C
	.incbin "baserom.gba", 0xE6A8C, 0xEC

	.global gUnknown_80E6B78
gUnknown_80E6B78: @ 80E6B78
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6B90
gUnknown_80E6B90: @ 80E6B90
	.incbin "baserom.gba", 0xE6B90, 0x64

	.global gUnknown_80E6BF4
gUnknown_80E6BF4: @ 80E6BF4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6C0C
gUnknown_80E6C0C: @ 80E6C0C
	.incbin "baserom.gba", 0xE6C0C, 0x44

	.global gUnknown_80E6C50
gUnknown_80E6C50: @ 80E6C50
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6C68
gUnknown_80E6C68: @ 80E6C68
	.incbin "baserom.gba", 0xE6C68, 0x68

	.global gUnknown_80E6CD0
gUnknown_80E6CD0: @ 80E6CD0
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6CE8
gUnknown_80E6CE8: @ 80E6CE8
	.incbin "baserom.gba", 0xE6CE8, 0x6C

	.global gUnknown_80E6D54
gUnknown_80E6D54: @ 80E6D54
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6D6C
gUnknown_80E6D6C: @ 80E6D6C
	.incbin "baserom.gba", 0xE6D6C, 0x70

	.global gUnknown_80E6DDC
gUnknown_80E6DDC: @ 80E6DDC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x08, 0x00
        .byte 0x18, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6DF4
gUnknown_80E6DF4: @ 80E6DF4
	.incbin "baserom.gba", 0xE6DF4, 0x5C

        .global gUnknown_80E6E50
gUnknown_80E6E50:: @ 80E6E50
        .string "CHUNSOFT\0"
        .align 2,0

        .string "pksdir0\0"

        .string "pksdir0\0"

        .string "pksdir0\0"

        .string "pksdir0\0"


	.global gUnknown_80E6E7C
gUnknown_80E6E7C: @ 80E6E7C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6E94
gUnknown_80E6E94: @ 80E6E94
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x05, 0x00, 0x09, 0x00
        .byte 0x13, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6EAC
gUnknown_80E6EAC: @ 80E6EAC
        .4byte Caution_80E6F04
        .4byte 3
        .4byte StorageEmpty_80E6EE4
        .4byte 3
        .4byte CheckAgain_80E6ECC
        .4byte 3
        .4byte 0
        .4byte 1

        .global CheckAgain_80E6ECC
        CheckAgain_80E6ECC:
        .asciz "#+Please check again."
        .align 2,0

        .global StorageEmpty_80E6EE4
        StorageEmpty_80E6EE4:
        .asciz "#+The storage space is empty!"
        .align 2,0

        .global Caution_80E6F04
        Caution_80E6F04:
        .asciz "#+#C2Caution!#R "
        .align 2,0

        .asciz "pksdir0"

	.global gUnknown_80E6F20
gUnknown_80E6F20: @ 80E6F20
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6F38
gUnknown_80E6F38: @ 80E6F38
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x05, 0x00, 0x08, 0x00
        .byte 0x15, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E6F50
gUnknown_80E6F50: @ 80E6F50
	.incbin "baserom.gba", 0xE6F50, 0x6C

	.global gUnknown_80E6FBC
gUnknown_80E6FBC: @ 80E6FBC
	.incbin "baserom.gba", 0xE6FBC, 0x60

	.global gUnknown_80E701C
gUnknown_80E701C: @ 80E701C
	.incbin "baserom.gba", 0xE701C, 0x74

	.global gUnknown_80E7090
gUnknown_80E7090: @ 80E7090
        .4byte 0x80e6fac
        .4byte 4
        .4byte DeletingAdventure_80E70B0
        .4byte 4
        .4byte 0x80e6f70
        .4byte 4
        .4byte 0
        .4byte 2

        .global DeletingAdventure_80E70B0
        DeletingAdventure_80E70B0:
        .string "#+Deleting your adventure!"
        .align 2,0

	.global gUnknown_80E70CC
gUnknown_80E70CC: @ 80E70CC
        .4byte 0x80e7008
        .4byte 4
        .4byte AdventureDeleted_80E70F0
        .4byte 4
        .4byte Data_80E70EC
        .4byte 4
        .4byte 0
        .4byte 2

        .global Data_80E70EC
        Data_80E70EC:
        .string "  "
        .align 2,0

        .global AdventureDeleted_80E70F0
        AdventureDeleted_80E70F0:
        .string "#+Your adventure has been deleted."
        .align 2,0

	.global gUnknown_80E7114
gUnknown_80E7114: @ 80E7114
	.incbin "baserom.gba", 0xE7114, 0x64

	.global gUnknown_80E7178
gUnknown_80E7178: @ 80E7178
	.incbin "baserom.gba", 0xE7178, 0x6C

	.global gUnknown_80E71E4
gUnknown_80E71E4: @ 80E71E4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E71FC
gUnknown_80E71FC: @ 80E71FC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7214
gUnknown_80E7214: @ 80E7214
        .4byte Error_80E7268
        .4byte 0xC
        .4byte IncorrectPassword_80E7250
        .4byte 0xC
        .4byte CheckAgain_80E7234
        .4byte 0xC
        .4byte 0
        .4byte 0xA

        .global CheckAgain_80E7234
        CheckAgain_80E7234:
        .asciz "#+Please check it again."
        .align 2,0

        .global IncorrectPassword_80E7250
        IncorrectPassword_80E7250:
        .asciz "#+Incorrect password!"
        .align 2,0

        .global Error_80E7268
        Error_80E7268:
        .asciz "#+#C2Error!#R "
        .align 2,0

	.global gUnknown_80E7278
gUnknown_80E7278: @ 80E7278
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7290
gUnknown_80E7290: @ 80E7290
        .4byte Success_80E72D8
        .4byte 0xC
        .4byte PasswordAccept_80E72B4
        .4byte 0xC
        .4byte DATA_80E72B0
        .4byte 0xC
        .4byte 0
        .4byte 0xA

        .global DATA_80E72B0
        DATA_80E72B0:
        .byte 0x20, 0x20, 0x00, 0x00 @ 2 spaces??

        .global PasswordAccept_80E72B4
        PasswordAccept_80E72B4:
        .asciz "#+The password has been accepted."
        .align 2,0
        
        .global Success_80E72D8
        Success_80E72D8:
        .asciz "#+#CGSuccess!#R "
        .align 2,0

	.global gUnknown_80E72EC
gUnknown_80E72EC: @ 80E72EC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7304
gUnknown_80E7304: @ 80E7304
        .4byte Error_80E7268
        .4byte 0xC
        .4byte NotSOSMail_80E7324
        .4byte 0xC
        .4byte CheckAgain_80E7234
        .4byte 0xC
        .4byte 0
        .4byte 0xA

        .global NotSOSMail_80E7324
        NotSOSMail_80E7324:
        .asciz "#+This is not an #CGSOS Mail#R."
        .align 2,0

	.global gUnknown_80E7344
gUnknown_80E7344: @ 80E7344
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E735C
gUnknown_80E735C: @ 80E735C
        .4byte Error_80E7268
        .4byte 0xC
        .4byte ReceiveSOSMail_80E737C
        .4byte 0xC
        .4byte CheckAgain_80E7234
        .4byte 0xC
        .4byte 0
        .4byte 0xA

        .global ReceiveSOSMail_80E737C
        ReceiveSOSMail_80E737C:
        .asciz "#+This #CGSOS Mail#R has been received already."
        .align 2,0

	.global gUnknown_80E73AC
gUnknown_80E73AC: @ 80E73AC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E73C4
gUnknown_80E73C4: @ 80E73C4
	.incbin "baserom.gba", 0xE73C4, 0x44

	.global gUnknown_80E7408
gUnknown_80E7408: @ 80E7408
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7420
gUnknown_80E7420: @ 80E7420
	.incbin "baserom.gba", 0xE7420, 0x48

	.global gUnknown_80E7468
gUnknown_80E7468: @ 80E7468
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7480
gUnknown_80E7480: @ 80E7480
	.incbin "baserom.gba", 0xE7480, 0x48

	.global gUnknown_80E74C8
gUnknown_80E74C8: @ 80E74C8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E74E0
gUnknown_80E74E0: @ 80E74E0
	.incbin "baserom.gba", 0xE74E0, 0x4C

	.global gUnknown_80E752C
gUnknown_80E752C: @ 80E752C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7544
gUnknown_80E7544: @ 80E7544
	.incbin "baserom.gba", 0xE7544, 0x44

	.global gUnknown_80E7588
gUnknown_80E7588: @ 80E7588
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x09, 0x00
        .byte 0x17, 0x00, 0x05, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E75A0
gUnknown_80E75A0: @ 80E75A0
	.incbin "baserom.gba", 0xE75A0, 0x58

	.global gUnknown_80E75F8
gUnknown_80E75F8: @ 80E75F8
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7610
gUnknown_80E7610: @ 80E7610
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x1A, 0x00, 0x0B, 0x00
        .byte 0x0B, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x20, 0x00, 0x00, 0x00

	.global gUnknown_80E762C
gUnknown_80E762C: @ 80E762C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x0F, 0x00
        .byte 0x13, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7644
gUnknown_80E7644: @ 80E7644
	.incbin "baserom.gba", 0xE7644, 0x40

	.global gUnknown_80E7684
gUnknown_80E7684: @ 80E7684
	.incbin "baserom.gba", 0xE7684, 0x34

	.global gUnknown_80E76B8
gUnknown_80E76B8: @ 80E76B8
	.incbin "baserom.gba", 0xE76B8, 0x30

	.global gUnknown_80E76E8
gUnknown_80E76E8: @ 80E76E8
	.incbin "baserom.gba", 0xE76E8, 0x48

	.global gUnknown_80E7730
gUnknown_80E7730: @ 80E7730
	.incbin "baserom.gba", 0xE7730, 0x54

	.global gUnknown_80E7784
gUnknown_80E7784: @ 80E7784
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x17, 0x00, 0x0F, 0x00
        .byte 0x05, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E779C
gUnknown_80E779C: @ 80E779C
        .4byte Yes_80E77B8
        .4byte 1
        .4byte No_80E77B4
        .4byte 2
        .4byte 0
        .4byte 3

        .global No_80E77B4
        No_80E77B4:
        .asciz "No"
        .align 2,0

        .global Yes_80E77B8
        Yes_80E77B8:
        .asciz "Yes"
        .align 2,0

	.global gUnknown_80E77BC
gUnknown_80E77BC: @ 80E77BC
        .string "Team:\0"
        .align 2,0

	.global gUnknown_80E77C4
gUnknown_80E77C4: @ 80E77C4
        .string "Name:\0"
        .align 2,0

	.global gUnknown_80E77CC
gUnknown_80E77CC: @ 80E77CC
        .string "Location:\0"
        .align 2,0

	.global gUnknown_80E77D8
gUnknown_80E77D8: @ 80E77D8
        .string "Play time:\0"
        .align 2,0

	.global gUnknown_80E77E4
gUnknown_80E77E4: @ 80E77E4
        .string "Adventures:\0"
        .align 2,0

	.global gUnknown_80E77F0
gUnknown_80E77F0: @ 80E77F0
        .string "Helper:\0"
        .align 2,0

	.global gUnknown_80E77F8
gUnknown_80E77F8: @ 80E77F8
        .byte 0x81, 0x48
        .byte 0x81, 0x48
        .byte 0x81, 0x48
        .byte 0x81, 0x48
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80E7804
gUnknown_80E7804: @ 80E7804
        .string "%s \0"
        .align 2,0

	.global gUnknown_80E7808
gUnknown_80E7808: @ 80E7808
        .string "???\0"
        .align 2,0

	.global gUnknown_80E780C
gUnknown_80E780C: @ 80E780C
        .string "Quicksave data deleted.\0"
        .align 2,0

	.global gUnknown_80E7824
gUnknown_80E7824: @ 80E7824
        .string "Location unknown.\0"
        .align 2,0

	.global gUnknown_80E7838
gUnknown_80E7838: @ 80E7838
        .string "%d:%02d:%02d \0"
        .align 2,0

	.global gUnknown_80E7848
gUnknown_80E7848: @ 80E7848
        .string "%d\0"
        .align 2,0

	.global gUnknown_80E784C
gUnknown_80E784C: @ 80E784C
        .string "%s (%s)\0"
        .align 2,0

	.global gUnknown_80E7854
gUnknown_80E7854: @ 80E7854
        .string "-----\0"
        .align 2,0

	.global gUnknown_80E785C
gUnknown_80E785C: @ 80E785C
        .string "clmkpat\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E786C
gUnknown_80E786C: @ 80E786C
        .4byte Send_80E788C
        .4byte 1
        .4byte Receive_80E7884
        .4byte 2
        .4byte 0
        .4byte 0

        .global Receive_80E7884
        Receive_80E7884:
        .asciz "Receive"
        .align 2,0

        .global Send_80E788C
        Send_80E788C:
        .asciz "Send"
        .align 2,0

	.global gUnknown_80E7894
gUnknown_80E7894: @ 80E7894
        .4byte GameLinkCable_80E78C8
        .4byte 3
        .4byte Password_80E78BC
        .4byte -1
        .4byte Cancel_80E78B4
        .4byte 8
        .4byte 0
        .4byte 0

        .global Cancel_80E78B4
        Cancel_80E78B4:
        .asciz "Cancel"
        .align 2,0

        .global Password_80E78BC
        Password_80E78BC:
        .asciz "Password"
        .align 2,0

        .global GameLinkCable_80E78C8
        GameLinkCable_80E78C8:
        .asciz "Game Link cable"
        .align 2,0

	.global gUnknown_80E78D8
gUnknown_80E78D8: @ 80E78D8
        .4byte GameLinkCable_80E78C8
        .4byte 3
        .4byte Password_80E78BC
        .4byte 5
        .4byte Cancel_80E78B4
        .4byte 8
        .4byte 0
        .4byte 0

	.global gUnknown_80E78F8
gUnknown_80E78F8: @ 80E78F8
        .4byte Yes_80E7910
        .4byte 6
        .4byte Cancel_80E78B4
        .4byte 0
        .4byte 0
        .4byte 0

        .global Yes_80E7910
        Yes_80E7910:
        .asciz "Yes"
        .align 2,0

	.global gUnknown_80E7914
gUnknown_80E7914: @ 80E7914
        .asciz "There was a communication error."
        .align 2,0

	.global gUnknown_80E7938
gUnknown_80E7938: @ 80E7938
        .string "An incorrect number of GBA systems are\n"
        .string "connected.\n"
        .asciz "Please redo this process from the start."
        .align 2,0

	.global gUnknown_80E7994
gUnknown_80E7994: @ 80E7994
        .string "There is no response from your friend.\n"
        .asciz "Please redo this process from the start."
        .align 2,0

	.global gUnknown_80E79E4
gUnknown_80E79E4: @ 80E79E4
        .string "The sender and receiver appear to be\n"
        .string "in different modes.\n"
        .asciz "Please redo the process from the start."
        .align 2,0

	.global gUnknown_80E7A48
gUnknown_80E7A48: @ 80E7A48
	.incbin "baserom.gba", 0xE7A48, 0x7C

	.global gUnknown_80E7AC4
gUnknown_80E7AC4: @ 80E7AC4
        .asciz "What would you like to do?"
        .align 2,0

	.global gUnknown_80E7AE0
gUnknown_80E7AE0: @ 80E7AE0
        .string "How would you like to send your\n"
        .asciz "#CGWonder Mail#R?"
        .align 2,0

	.global gUnknown_80E7B14
gUnknown_80E7B14: @ 80E7B14
        .string "How would you like to receive the\n"
        .asciz "#CGWonder Mail#R?"
        .align 2,0

	.global gUnknown_80E7B48
gUnknown_80E7B48: @ 80E7B48
        .asciz "Your adventure will be saved."
        .align 2,0

	.global gUnknown_80E7B68
gUnknown_80E7B68: @ 80E7B68
        .asciz "Your #CGWonder Mail#R was sent."
        .align 2,0

	.global gUnknown_80E7B88
gUnknown_80E7B88: @ 80E7B88
	.incbin "baserom.gba", 0xE7B88, 0x40

	.global gUnknown_80E7BC8
gUnknown_80E7BC8: @ 80E7BC8
        .asciz "The #CGWonder Mail#R was refused."
        .align 2,0

	.global gUnknown_80E7BEC
gUnknown_80E7BEC: @ 80E7BEC
	.incbin "baserom.gba", 0xE7BEC, 0x5C

	.global gUnknown_80E7C48
gUnknown_80E7C48: @ 80E7C48
	.incbin "baserom.gba", 0xE7C48, 0x50

	.global gUnknown_80E7C98
gUnknown_80E7C98: @ 80E7C98
        .string "Please enter the\n"
        .string "#CGWonder Mail password#R.\0"
        .align 2,0

	.global gUnknown_80E7CC4
gUnknown_80E7CC4: @ 80E7CC4
        .string "This password is incorrect.\n"
        .string "Would you like to enter it again?\0"
        .align 2,0
        .string "pksdir0\0"
        .4byte Yes_80E7D2C 
        .byte 0x01, 0x00, 0x00, 0x00
        .4byte Cancel_80E7D24 
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .global Cancel_80E7D24
        Cancel_80E7D24:
        .string "Cancel\0"
        .align 2,0
        .global Yes_80E7D2C
        Yes_80E7D2C:
        .string "Yes\0"
        .align 2,0
        .string "pksdir0\0"
        .string "pksdir0\0"

