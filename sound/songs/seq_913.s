@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_913_grp, bank_026
	.equ	seq_913_pri, 127
	.equ	seq_913_rev, 0
	.equ	seq_913_mvl, 127
	.equ	seq_913_key, 0

	.section .rodata
	.global	seq_913
	.align	2

@*********************** Track 01 ***********************@

seq_913_0:
	.byte	KEYSH , seq_913_key+0
	.byte	TEMPO , 180/2
	.byte		VOICE , 11
	.byte		VOL   , 115*seq_913_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		MOD   , 50
	.byte	W01
	.byte		BEND  , c_v-15
	.byte		N06   , Cn5 , v127
	.byte	W02
	.byte		BEND  , c_v-19
	.byte	W01
	.byte		        c_v-22
	.byte	W01
	.byte		        c_v-25
	.byte	W01
	.byte		        c_v-28
	.byte	W01
	.byte		N11   , Dn4 , v060
	.byte	W04
	.byte		BEND  , c_v-19
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+17
	.byte	W01
	.byte		VOL   , 110*seq_913_mvl/mxv
	.byte		BEND  , c_v+20
	.byte	W01
	.byte		VOL   , 101*seq_913_mvl/mxv
	.byte		BEND  , c_v+24
	.byte	W01
	.byte		VOL   , 91*seq_913_mvl/mxv
	.byte		BEND  , c_v+28
	.byte	W01
	.byte		VOL   , 80*seq_913_mvl/mxv
	.byte		BEND  , c_v+32
	.byte	W01
	.byte		VOL   , 69*seq_913_mvl/mxv
	.byte		BEND  , c_v+37
	.byte	W01
	.byte		VOL   , 58*seq_913_mvl/mxv
	.byte		BEND  , c_v+44
	.byte	W01
	.byte		VOL   , 48*seq_913_mvl/mxv
	.byte	W01
	.byte		        38*seq_913_mvl/mxv
	.byte	W01
	.byte		        27*seq_913_mvl/mxv
	.byte	FINE

@******************************************************@

	.align	2

seq_913:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_913_pri	@ Priority
	.byte	seq_913_rev	@ Reverb

	.word	seq_913_grp

	.word	seq_913_0

	.end
