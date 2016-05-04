;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.3.0 #8604 (Dec 30 2013) (Linux)
; This file was generated Fri Apr 29 02:06:10 2016
;--------------------------------------------------------
	.module sort4
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _TF2
	.globl _EXF2
	.globl _RCLK
	.globl _TCLK
	.globl _EXEN2
	.globl _TR2
	.globl _C_T2
	.globl _CP_RL2
	.globl _T2CON_7
	.globl _T2CON_6
	.globl _T2CON_5
	.globl _T2CON_4
	.globl _T2CON_3
	.globl _T2CON_2
	.globl _T2CON_1
	.globl _T2CON_0
	.globl _PT2
	.globl _ET2
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _TH2
	.globl _TL2
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _T2CON
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _quickSort_PARM_2
	.globl _array
	.globl _quickSort
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_P1	=	0x0090
_SCON	=	0x0098
_SBUF	=	0x0099
_P2	=	0x00a0
_IE	=	0x00a8
_P3	=	0x00b0
_IP	=	0x00b8
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
_T2CON	=	0x00c8
_RCAP2L	=	0x00ca
_RCAP2H	=	0x00cb
_TL2	=	0x00cc
_TH2	=	0x00cd
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_RI	=	0x0098
_TI	=	0x0099
_RB8	=	0x009a
_TB8	=	0x009b
_REN	=	0x009c
_SM2	=	0x009d
_SM1	=	0x009e
_SM0	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES	=	0x00ac
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_RXD	=	0x00b0
_TXD	=	0x00b1
_INT0	=	0x00b2
_INT1	=	0x00b3
_T0	=	0x00b4
_T1	=	0x00b5
_WR	=	0x00b6
_RD	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS	=	0x00bc
_P	=	0x00d0
_F1	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
_ET2	=	0x00ad
_PT2	=	0x00bd
_T2CON_0	=	0x00c8
_T2CON_1	=	0x00c9
_T2CON_2	=	0x00ca
_T2CON_3	=	0x00cb
_T2CON_4	=	0x00cc
_T2CON_5	=	0x00cd
_T2CON_6	=	0x00ce
_T2CON_7	=	0x00cf
_CP_RL2	=	0x00c8
_C_T2	=	0x00c9
_TR2	=	0x00ca
_EXEN2	=	0x00cb
_TCLK	=	0x00cc
_RCLK	=	0x00cd
_EXF2	=	0x00ce
_TF2	=	0x00cf
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_array::
	.ds 4
_quickSort_PARM_2:
	.ds 2
_quickSort_left_1_5:
	.ds 2
_quickSort_i_1_6:
	.ds 2
_quickSort_j_1_6:
	.ds 2
_quickSort_pivot_1_6:
	.ds 2
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG	(DATA)
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;i                         Allocated to registers r6 r7 
;------------------------------------------------------------
;	sort4.c:6: void main(){
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	sort4.c:9: for(i = 0; i < 4; i++) {
	mov	r6,#0x00
	mov	r7,#0x00
00106$:
;	sort4.c:10: array[i] = P0;
	mov	a,r6
	add	a,#_array
	mov	r0,a
	mov	@r0,_P0
;	sort4.c:9: for(i = 0; i < 4; i++) {
	inc	r6
	cjne	r6,#0x00,00126$
	inc	r7
00126$:
	clr	c
	mov	a,r6
	subb	a,#0x04
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jc	00106$
;	sort4.c:12: quickSort(0, 3);
	mov	_quickSort_PARM_2,#0x03
	mov	(_quickSort_PARM_2 + 1),#0x00
	mov	dptr,#0x0000
	lcall	_quickSort
;	sort4.c:13: for(i = 0; i < 4; i++) {
	mov	r6,#0x00
	mov	r7,#0x00
00108$:
;	sort4.c:14: P2 = array[i];
	mov	a,r6
	add	a,#_array
	mov	r1,a
	mov	_P2,@r1
;	sort4.c:13: for(i = 0; i < 4; i++) {
	inc	r6
	cjne	r6,#0x00,00128$
	inc	r7
00128$:
	clr	c
	mov	a,r6
	subb	a,#0x04
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jc	00108$
;	sort4.c:17: while(1);
00104$:
	sjmp	00104$
;------------------------------------------------------------
;Allocation info for local variables in function 'quickSort'
;------------------------------------------------------------
;right                     Allocated with name '_quickSort_PARM_2'
;left                      Allocated with name '_quickSort_left_1_5'
;i                         Allocated with name '_quickSort_i_1_6'
;j                         Allocated with name '_quickSort_j_1_6'
;tmp                       Allocated to registers r5 r4 
;pivot                     Allocated with name '_quickSort_pivot_1_6'
;------------------------------------------------------------
;	sort4.c:20: void quickSort(int left, int right){
;	-----------------------------------------
;	 function quickSort
;	-----------------------------------------
_quickSort:
	mov	_quickSort_left_1_5,dpl
	mov	(_quickSort_left_1_5 + 1),dph
;	sort4.c:21: int i = left;
	mov	_quickSort_i_1_6,_quickSort_left_1_5
	mov	(_quickSort_i_1_6 + 1),(_quickSort_left_1_5 + 1)
;	sort4.c:22: int j = right;
	mov	_quickSort_j_1_6,_quickSort_PARM_2
	mov	(_quickSort_j_1_6 + 1),(_quickSort_PARM_2 + 1)
;	sort4.c:24: int pivot = array[(left + right) / 2];
	mov	a,_quickSort_j_1_6
	add	a,_quickSort_left_1_5
	mov	dpl,a
	mov	a,(_quickSort_j_1_6 + 1)
	addc	a,(_quickSort_left_1_5 + 1)
	mov	dph,a
	mov	__divsint_PARM_2,#0x02
	mov	(__divsint_PARM_2 + 1),#0x00
	lcall	__divsint
	mov	r6,dpl
	mov	a,r6
	add	a,#_array
	mov	r1,a
	mov	ar7,@r1
	mov	_quickSort_pivot_1_6,r7
	mov	(_quickSort_pivot_1_6 + 1),#0x00
;	sort4.c:26: while(i <= j) {
00109$:
	clr	c
	mov	a,_quickSort_j_1_6
	subb	a,_quickSort_i_1_6
	mov	a,(_quickSort_j_1_6 + 1)
	xrl	a,#0x80
	mov	b,(_quickSort_i_1_6 + 1)
	xrl	b,#0x80
	subb	a,b
	jnc	00146$
	ljmp	00111$
00146$:
;	sort4.c:27: while(array[i] < pivot) {
	mov	r2,_quickSort_i_1_6
	mov	r3,(_quickSort_i_1_6 + 1)
00101$:
	mov	a,r2
	add	a,#_array
	mov	r1,a
	mov	ar7,@r1
	mov	r6,#0x00
	clr	c
	mov	a,r7
	subb	a,_quickSort_pivot_1_6
	mov	a,r6
	xrl	a,#0x80
	mov	b,(_quickSort_pivot_1_6 + 1)
	xrl	b,#0x80
	subb	a,b
	jnc	00126$
;	sort4.c:28: i++;
	inc	r2
;	sort4.c:30: while(array[j] > pivot) {
	cjne	r2,#0x00,00101$
	inc	r3
	sjmp	00101$
00126$:
	mov	_quickSort_i_1_6,r2
	mov	(_quickSort_i_1_6 + 1),r3
	mov	r6,_quickSort_j_1_6
	mov	r7,(_quickSort_j_1_6 + 1)
00104$:
	mov	a,r6
	add	a,#_array
	mov	r1,a
	mov	ar3,@r1
	mov	ar2,r3
	mov	r5,#0x00
	clr	c
	mov	a,_quickSort_pivot_1_6
	subb	a,r2
	mov	a,(_quickSort_pivot_1_6 + 1)
	xrl	a,#0x80
	mov	b,r5
	xrl	b,#0x80
	subb	a,b
	jnc	00127$
;	sort4.c:31: j--;
	dec	r6
	cjne	r6,#0xFF,00150$
	dec	r7
00150$:
	sjmp	00104$
00127$:
	mov	_quickSort_j_1_6,r6
	mov	(_quickSort_j_1_6 + 1),r7
;	sort4.c:33: if(i <= j) {
	clr	c
	mov	a,r6
	subb	a,_quickSort_i_1_6
	mov	a,r7
	xrl	a,#0x80
	mov	b,(_quickSort_i_1_6 + 1)
	xrl	b,#0x80
	subb	a,b
	jc	00109$
;	sort4.c:34: tmp = array[i];
	mov	a,_quickSort_i_1_6
	add	a,#_array
	mov	r0,a
	mov	ar5,@r0
	mov	r4,#0x00
;	sort4.c:35: array[i] = array[j];
	mov	@r0,ar3
;	sort4.c:36: array[j] = tmp;
	mov	@r1,ar5
;	sort4.c:37: i++;
	inc	_quickSort_i_1_6
	clr	a
	cjne	a,_quickSort_i_1_6,00152$
	inc	(_quickSort_i_1_6 + 1)
00152$:
;	sort4.c:38: j--;
	mov	a,r6
	add	a,#0xFF
	mov	_quickSort_j_1_6,a
	mov	a,r7
	addc	a,#0xFF
	mov	(_quickSort_j_1_6 + 1),a
	ljmp	00109$
00111$:
;	sort4.c:41: if(left < j) {
	clr	c
	mov	a,_quickSort_left_1_5
	subb	a,_quickSort_j_1_6
	mov	a,(_quickSort_left_1_5 + 1)
	xrl	a,#0x80
	mov	b,(_quickSort_j_1_6 + 1)
	xrl	b,#0x80
	subb	a,b
	jnc	00113$
;	sort4.c:42: quickSort(left, j);
	mov	_quickSort_PARM_2,_quickSort_j_1_6
	mov	(_quickSort_PARM_2 + 1),(_quickSort_j_1_6 + 1)
	mov	dpl,_quickSort_left_1_5
	mov	dph,(_quickSort_left_1_5 + 1)
	lcall	_quickSort
00113$:
;	sort4.c:44: if(i < right) {
	clr	c
	mov	a,_quickSort_i_1_6
	subb	a,_quickSort_PARM_2
	mov	a,(_quickSort_i_1_6 + 1)
	xrl	a,#0x80
	mov	b,(_quickSort_PARM_2 + 1)
	xrl	b,#0x80
	subb	a,b
	jnc	00116$
;	sort4.c:45: quickSort(i, right);
	mov	dpl,_quickSort_i_1_6
	mov	dph,(_quickSort_i_1_6 + 1)
	ljmp	_quickSort
00116$:
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
