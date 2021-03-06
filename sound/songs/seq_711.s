@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_711_grp, bank_026
	.equ	seq_711_pri, 127
	.equ	seq_711_rev, 0
	.equ	seq_711_mvl, 127
	.equ	seq_711_key, 0

	.section .rodata
	.global	seq_711
	.align	2

@*********************** Track 01 ***********************@

seq_711_0:
	.byte	KEYSH , seq_711_key+0
	.byte	TEMPO , 280/2
	.byte		VOICE , 22
	.byte		VOL   , 127*seq_711_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		BENDR , 36
	.byte		LFOS  , 60
	.byte		MODT  , mod_pan
	.byte	W01
	.byte		MOD   , 40
	.byte	W01
	.byte		N30   , Gn2 , v120
	.byte	W10
	.byte		BEND  , c_v-3
	.byte	W01
	.byte		        c_v-5
	.byte	W01
	.byte		        c_v-7
	.byte	W01
	.byte		        c_v-9
	.byte	W01
	.byte		        c_v-12
	.byte	W01
	.byte		        c_v-14
	.byte	W01
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-18
	.byte	W01
	.byte		        c_v-20
	.byte	W01
	.byte		        c_v-23
	.byte	W01
	.byte		        c_v-25
	.byte	W01
	.byte		        c_v-30
	.byte	W01
	.byte		        c_v-32
	.byte	W01
	.byte		        c_v-33
	.byte	W01
	.byte		        c_v-35
	.byte	W01
	.byte		        c_v-36
	.byte	W01
	.byte		        c_v-37
	.byte	W01
	.byte		        c_v-40
	.byte	W01
	.byte		        c_v-42
	.byte	W01
	.byte		        c_v-45
	.byte	W02
	.byte		        c_v-50
	.byte	W01
	.byte		        c_v-52
	.byte	FINE

@******************************************************@

	.align	2

seq_711:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_711_pri	@ Priority
	.byte	seq_711_rev	@ Reverb

	.word	seq_711_grp

	.word	seq_711_0

	.end
