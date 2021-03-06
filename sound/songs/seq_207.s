@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_207_grp, bank_025
	.equ	seq_207_pri, 50
	.equ	seq_207_rev, 178
	.equ	seq_207_mvl, 127
	.equ	seq_207_key, 0

	.section .rodata
	.global	seq_207
	.align	2

@*********************** Track 01 ***********************@

seq_207_0:
	.byte	KEYSH , seq_207_key+0
	.byte	TEMPO , 150/2
	.byte		VOICE , 50
	.byte	W01
	.byte		VOL   , 77*seq_207_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N05   , As4 , v112
	.byte	W06
	.byte		        Fn4 , v100
	.byte	W03
	.byte	W03
	.byte		N06   , As5 , v096
	.byte	W11
	.byte		        As5 , v012
	.byte	W07
	.byte	FINE

@*********************** Track 02 ***********************@

seq_207_1:
	.byte	KEYSH , seq_207_key+0
	.byte		VOICE , 50
	.byte	W01
	.byte		VOL   , 51*seq_207_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W05
	.byte		N06   , As4 , v040
	.byte	W05
	.byte	W01
	.byte		        Fn4 , v032
	.byte	W06
	.byte		N07   , Dn5 , v040
	.byte	W09
	.byte		N05   , Dn5 , v012
	.byte	W05
	.byte	FINE

@*********************** Track 03 ***********************@

seq_207_2:
	.byte	KEYSH , seq_207_key+0
	.byte		VOICE , 50
	.byte	W01
	.byte		MOD   , 60
	.byte		VOL   , 69*seq_207_mvl/mxv
	.byte	W01
	.byte		MODT  , mod_pan
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N05   , Fs5 , v100
	.byte	W06
	.byte		        Cs5 , v092
	.byte	W03
	.byte	W03
	.byte		N06   , Dn5 , v060
	.byte	W11
	.byte		        Dn5 , v008
	.byte	W07
	.byte	FINE

@******************************************************@

	.align	2

seq_207:
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_207_pri	@ Priority
	.byte	seq_207_rev	@ Reverb

	.word	seq_207_grp

	.word	seq_207_0
	.word	seq_207_1
	.word	seq_207_2

	.end
