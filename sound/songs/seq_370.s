@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_370_grp, bank_027
	.equ	seq_370_pri, 100
	.equ	seq_370_rev, 0
	.equ	seq_370_mvl, 127
	.equ	seq_370_key, 0

	.section .rodata
	.global	seq_370
	.align	2

@*********************** Track 01 ***********************@

seq_370_0:
	.byte		VOL   , 90*seq_370_mvl/mxv
	.byte	KEYSH , seq_370_key+0
	.byte	TEMPO , 140/2
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOICE , 1
	.byte		N09   , Fs5 , v100
	.byte	W06
	.byte		VOICE , 60
	.byte		N09   , En6 , v092
	.byte	W05
	.byte	W04
	.byte		N06   , En6 , v024
	.byte	W08
	.byte	FINE

@******************************************************@

	.align	2

seq_370:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_370_pri	@ Priority
	.byte	seq_370_rev	@ Reverb

	.word	seq_370_grp

	.word	seq_370_0

	.end
