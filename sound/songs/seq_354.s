@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_354_grp, bank_027
	.equ	seq_354_pri, 80
	.equ	seq_354_rev, 0
	.equ	seq_354_mvl, 127
	.equ	seq_354_key, 0

	.section .rodata
	.global	seq_354
	.align	2

@*********************** Track 01 ***********************@

seq_354_0:
	.byte	KEYSH , seq_354_key+0
	.byte	TEMPO , 200/2
	.byte		VOICE , 60
	.byte		VOL   , 94*seq_354_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		MOD   , 10
	.byte		N03   , An3 , v060
	.byte	W01
	.byte		BEND  , c_v-12
	.byte	W01
	.byte		        c_v-3
	.byte	W01
	.byte		VOL   , 94*seq_354_mvl/mxv
	.byte		BEND  , c_v-38
	.byte		N02   , As5 , v092
	.byte	W01
	.byte		VOL   , 92*seq_354_mvl/mxv
	.byte		BEND  , c_v-33
	.byte	W01
	.byte		VOL   , 85*seq_354_mvl/mxv
	.byte		BEND  , c_v-19
	.byte	W01
	.byte		VOL   , 72*seq_354_mvl/mxv
	.byte		BEND  , c_v+29
	.byte		N02   , Cn6 , v020
	.byte	W01
	.byte		VOL   , 55*seq_354_mvl/mxv
	.byte	W02
	.byte		        0*seq_354_mvl/mxv
	.byte	FINE

@******************************************************@

	.align	2

seq_354:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_354_pri	@ Priority
	.byte	seq_354_rev	@ Reverb

	.word	seq_354_grp

	.word	seq_354_0

	.end
