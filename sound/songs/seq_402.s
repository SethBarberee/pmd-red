@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_402_grp, bank_026
	.equ	seq_402_pri, 127
	.equ	seq_402_rev, 0
	.equ	seq_402_mvl, 127
	.equ	seq_402_key, 0

	.section .rodata
	.global	seq_402
	.align	2

@*********************** Track 01 ***********************@

seq_402_0:
	.byte		VOL   , 110*seq_402_mvl/mxv
	.byte	KEYSH , seq_402_key+0
	.byte	TEMPO , 280/2
	.byte		VOICE , 23
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		BEND  , c_v-29
	.byte		N12   , Cs5 , v060
	.byte	W01
	.byte		BEND  , c_v-19
	.byte	W01
	.byte		        c_v-8
	.byte	W01
	.byte		        c_v-1
	.byte	W07
	.byte		N12   , Ds5 , v127
	.byte	W10
	.byte		BEND  , c_v-22
	.byte	W01
	.byte		        c_v-3
	.byte		N12   , Dn5 , v120
	.byte	W01
	.byte		BEND  , c_v+10
	.byte	W01
	.byte		        c_v+15
	.byte	W01
	.byte		        c_v+19
	.byte	W01
	.byte		        c_v+23
	.byte	W01
	.byte		        c_v+27
	.byte	W01
	.byte		        c_v+30
	.byte	W01
	.byte		        c_v+33
	.byte	W01
	.byte		        c_v+36
	.byte	W01
	.byte		        c_v+39
	.byte	W01
	.byte		        c_v+42
	.byte		N11   , En5 , v127
	.byte	W01
	.byte		BEND  , c_v+45
	.byte	W01
	.byte		        c_v+47
	.byte	W01
	.byte		        c_v+50
	.byte	W01
	.byte		        c_v+52
	.byte	W01
	.byte		        c_v+55
	.byte	W07
	.byte	FINE

@******************************************************@

	.align	2

seq_402:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_402_pri	@ Priority
	.byte	seq_402_rev	@ Reverb

	.word	seq_402_grp

	.word	seq_402_0

	.end
