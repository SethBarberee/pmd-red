@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_410_grp, bank_027
	.equ	seq_410_pri, 127
	.equ	seq_410_rev, 0
	.equ	seq_410_mvl, 127
	.equ	seq_410_key, 0

	.section .rodata
	.global	seq_410
	.align	2

@*********************** Track 01 ***********************@

seq_410_0:
	.byte	KEYSH , seq_410_key+0
	.byte	TEMPO , 200/2
	.byte		VOICE , 1
	.byte		VOL   , 120*seq_410_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N06   , Cs3 , v120
	.byte	W06
	.byte		        Ds3 , v080
	.byte	W06
	.byte		N12   , Bn2 , v060
	.byte	W12
	.byte		        As2 , v020
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

seq_410:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_410_pri	@ Priority
	.byte	seq_410_rev	@ Reverb

	.word	seq_410_grp

	.word	seq_410_0

	.end
