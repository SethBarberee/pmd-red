@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_748_grp, bank_026
	.equ	seq_748_pri, 127
	.equ	seq_748_rev, 0
	.equ	seq_748_mvl, 127
	.equ	seq_748_key, 0

	.section .rodata
	.global	seq_748
	.align	2

@*********************** Track 01 ***********************@

seq_748_0:
	.byte	KEYSH , seq_748_key+0
	.byte	TEMPO , 200/2
	.byte		VOICE , 38
	.byte		VOL   , 127*seq_748_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		BENDR , 26
	.byte	W02
	.byte		N01   , An2 , v127
	.byte	W01
	.byte		        Ds3 , v036
	.byte	W01
	.byte		        An2 , v127
	.byte	W02
	.byte		        Ds3 , v036
	.byte	W01
	.byte		        Bn2 , v127
	.byte	W01
	.byte		        Fn3 , v036
	.byte	W01
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		        c_v+6
	.byte		N01   , Bn2 , v127
	.byte	W01
	.byte		BEND  , c_v+11
	.byte		N06   , Ds3 
	.byte	W01
	.byte		BEND  , c_v+16
	.byte	W01
	.byte		        c_v+20
	.byte	W01
	.byte		        c_v+23
	.byte	W01
	.byte		        c_v+27
	.byte	W01
	.byte		        c_v+30
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

seq_748:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_748_pri	@ Priority
	.byte	seq_748_rev	@ Reverb

	.word	seq_748_grp

	.word	seq_748_0

	.end