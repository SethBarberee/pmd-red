@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_409_grp, bank_027
	.equ	seq_409_pri, 127
	.equ	seq_409_rev, 0
	.equ	seq_409_mvl, 127
	.equ	seq_409_key, 0

	.section .rodata
	.global	seq_409
	.align	2

@*********************** Track 01 ***********************@

seq_409_0:
	.byte	KEYSH , seq_409_key+0
	.byte	TEMPO , 200/2
	.byte		VOICE , 1
	.byte		VOL   , 120*seq_409_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N06   , Bn2 , v120
	.byte	W06
	.byte		        As2 , v080
	.byte	W06
	.byte		N12   , Bn2 , v060
	.byte	W12
	.byte		        Bn2 , v020
	.byte	W12
	.byte	FINE

@******************************************************@

	.align	2

seq_409:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_409_pri	@ Priority
	.byte	seq_409_rev	@ Reverb

	.word	seq_409_grp

	.word	seq_409_0

	.end
