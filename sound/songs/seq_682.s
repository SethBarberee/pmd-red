@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_682_grp, bank_026
	.equ	seq_682_pri, 127
	.equ	seq_682_rev, 0
	.equ	seq_682_mvl, 127
	.equ	seq_682_key, 0

	.section .rodata
	.global	seq_682
	.align	2

@*********************** Track 01 ***********************@

seq_682_0:
	.byte	KEYSH , seq_682_key+0
	.byte	TEMPO , 280/2
	.byte		VOICE , 27
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		BENDR , 40
	.byte		VOL   , 127*seq_682_mvl/mxv
	.byte	W02
	.byte		N36   , An1 , v127
	.byte	W01
	.byte		BEND  , c_v-1
	.byte	W08
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		VOL   , 79*seq_682_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		        c_v-3
	.byte	W01
	.byte		VOL   , 77*seq_682_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		VOL   , 75*seq_682_mvl/mxv
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		VOL   , 71*seq_682_mvl/mxv
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		VOL   , 67*seq_682_mvl/mxv
	.byte		BEND  , c_v-7
	.byte	W01
	.byte		VOL   , 61*seq_682_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		VOL   , 55*seq_682_mvl/mxv
	.byte		BEND  , c_v-9
	.byte	W01
	.byte		VOL   , 47*seq_682_mvl/mxv
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		VOL   , 38*seq_682_mvl/mxv
	.byte		BEND  , c_v-12
	.byte	W01
	.byte		VOL   , 18*seq_682_mvl/mxv
	.byte		BEND  , c_v-14
	.byte	W01
	.byte		VOL   , 17*seq_682_mvl/mxv
	.byte		BEND  , c_v-15
	.byte	W01
	.byte		        c_v-17
	.byte	W01
	.byte		        c_v-19
	.byte	W01
	.byte		        c_v-20
	.byte	W01
	.byte		        c_v-22
	.byte	W01
	.byte		        c_v-24
	.byte	W01
	.byte		        c_v-29
	.byte	W01
	.byte		        c_v-31
	.byte	W01
	.byte		        c_v-32
	.byte	W01
	.byte	FINE

@******************************************************@

	.align	2

seq_682:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_682_pri	@ Priority
	.byte	seq_682_rev	@ Reverb

	.word	seq_682_grp

	.word	seq_682_0

	.end
