@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_891_grp, bank_028
	.equ	seq_891_pri, 127
	.equ	seq_891_rev, 0
	.equ	seq_891_mvl, 127
	.equ	seq_891_key, 0

	.section .rodata
	.global	seq_891
	.align	2

@*********************** Track 01 ***********************@

seq_891_0:
	.byte		VOL   , 105*seq_891_mvl/mxv
	.byte	KEYSH , seq_891_key+0
	.byte	TEMPO , 180/2
	.byte		VOICE , 15
	.byte		N04   , An1 , v052
	.byte		N04   , Cs4 , v088
	.byte	W01
	.byte		VOL   , 105*seq_891_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W23
	.byte		N02   , An1 , v052
	.byte		N02   , Cs4 , v088
	.byte	W15
	.byte		        An1 , v052
	.byte	W01
	.byte		        Cs4 , v088
	.byte	W02
	.byte	FINE

@******************************************************@

	.align	2

seq_891:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_891_pri	@ Priority
	.byte	seq_891_rev	@ Reverb

	.word	seq_891_grp

	.word	seq_891_0

	.end
