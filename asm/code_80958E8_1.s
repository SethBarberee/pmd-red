	#include "asm/constants/gba_constants.inc"
	#include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80965F4
sub_80965F4:
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r2, 0
	movs r3, 0
	ldr r0, _0809660C
	mov r12, r0
	mov r8, r3
	movs r4, 0
	mov r9, r4
	b _08096636
	.align 2, 0
_0809660C: .4byte gUnknown_203B490
_08096610:
	cmp r2, r3
	ble _0809662A
	mov r1, r12
	ldr r0, [r1]
	mov r5, r8
	adds r1, r0, r5
	adds r0, r4
	adds r1, 0x50
	adds r0, 0x50
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r6,r7}
	stm r1!, {r6,r7}
_0809662A:
	adds r4, 0x14
	movs r0, 0x14
	add r9, r0
	adds r2, 0x1
	add r8, r0
	adds r3, 0x1
_08096636:
	cmp r2, 0x7
	bgt _08096666
	mov r1, r12
	ldr r0, [r1]
	adds r0, r4
	adds r0, 0x50
	ldrb r0, [r0]
	cmp r0, 0
	bne _08096666
	ldr r6, _08096694
	mov r1, r9
_0809664C:
	adds r1, 0x14
	adds r4, 0x14
	movs r5, 0x14
	add r9, r5
	adds r2, 0x1
	cmp r2, 0x7
	bgt _08096666
	ldr r0, [r6]
	adds r0, r1
	adds r0, 0x50
	ldrb r0, [r0]
	cmp r0, 0
	beq _0809664C
_08096666:
	cmp r2, 0x8
	bne _08096610
	cmp r3, 0x7
	bgt _08096688
	ldr r4, _08096694
	movs r2, 0
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 2
_08096678:
	ldr r0, [r4]
	adds r0, r1
	adds r0, 0x50
	strb r2, [r0]
	adds r1, 0x14
	adds r3, 0x1
	cmp r3, 0x7
	ble _08096678
_08096688:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096694: .4byte gUnknown_203B490
	thumb_func_end sub_80965F4

        .align 2,0
