@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_649_grp, bank_028
	.equ	seq_649_pri, 127
	.equ	seq_649_rev, 0
	.equ	seq_649_mvl, 127
	.equ	seq_649_key, 0

	.section .rodata
	.global	seq_649
	.align	2

@*********************** Track 01 ***********************@

seq_649_0:
	.byte	KEYSH , seq_649_key+0
	.byte	TEMPO , 160/2
	.byte		VOICE , 6
	.byte		VOL   , 118*seq_649_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		MOD   , 50
	.byte		LFOS  , 70
	.byte		MODT  , mod_vib
	.byte	W01
	.byte		BEND  , c_v-15
	.byte	W01
	.byte		N03   , An2 , v127
	.byte	W01
	.byte		BEND  , c_v-19
	.byte	W01
	.byte		        c_v-22
	.byte	W01
	.byte		        c_v-25
	.byte		N03   , An3 , v060
	.byte	W01
	.byte		BEND  , c_v-28
	.byte	W02
	.byte		        c_v-64
	.byte		N03   , An4 , v127
	.byte	W01
	.byte		BEND  , c_v-55
	.byte	W01
	.byte		        c_v-37
	.byte	W01
	.byte		        c_v-19
	.byte		N03   , An5 , v060
	.byte	W01
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		        c_v+17
	.byte	W01
	.byte		        c_v+20
	.byte		N03   , En4 , v127
	.byte	W01
	.byte		BEND  , c_v+24
	.byte	W01
	.byte		        c_v+28
	.byte	W01
	.byte		        c_v+32
	.byte		N03   , En5 , v060
	.byte	W01
	.byte		BEND  , c_v+37
	.byte	W01
	.byte		        c_v+44
	.byte	W01
	.byte		N03   , Cn4 , v127
	.byte	W01
	.byte		VOL   , 115*seq_649_mvl/mxv
	.byte	W01
	.byte		        105*seq_649_mvl/mxv
	.byte	W01
	.byte		        95*seq_649_mvl/mxv
	.byte		N03   , Cn5 , v060
	.byte	W01
	.byte		VOL   , 84*seq_649_mvl/mxv
	.byte	W01
	.byte		        72*seq_649_mvl/mxv
	.byte	W01
	.byte		        61*seq_649_mvl/mxv
	.byte		N03   , Gs3 , v127
	.byte	W01
	.byte		VOL   , 51*seq_649_mvl/mxv
	.byte	W01
	.byte		        39*seq_649_mvl/mxv
	.byte	W01
	.byte		        28*seq_649_mvl/mxv
	.byte		N03   , Gs4 , v060
	.byte	W03
	.byte		        Fn3 , v127
	.byte	W03
	.byte	FINE

@******************************************************@

	.align	2

seq_649:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_649_pri	@ Priority
	.byte	seq_649_rev	@ Reverb

	.word	seq_649_grp

	.word	seq_649_0

	.end
