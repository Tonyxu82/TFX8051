                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.3.0 #8604 (Dec 30 2013) (Linux)
                              4 ; This file was generated Fri Apr 29 02:06:10 2016
                              5 ;--------------------------------------------------------
                              6 	.module sort4
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _TF2
                             14 	.globl _EXF2
                             15 	.globl _RCLK
                             16 	.globl _TCLK
                             17 	.globl _EXEN2
                             18 	.globl _TR2
                             19 	.globl _C_T2
                             20 	.globl _CP_RL2
                             21 	.globl _T2CON_7
                             22 	.globl _T2CON_6
                             23 	.globl _T2CON_5
                             24 	.globl _T2CON_4
                             25 	.globl _T2CON_3
                             26 	.globl _T2CON_2
                             27 	.globl _T2CON_1
                             28 	.globl _T2CON_0
                             29 	.globl _PT2
                             30 	.globl _ET2
                             31 	.globl _CY
                             32 	.globl _AC
                             33 	.globl _F0
                             34 	.globl _RS1
                             35 	.globl _RS0
                             36 	.globl _OV
                             37 	.globl _F1
                             38 	.globl _P
                             39 	.globl _PS
                             40 	.globl _PT1
                             41 	.globl _PX1
                             42 	.globl _PT0
                             43 	.globl _PX0
                             44 	.globl _RD
                             45 	.globl _WR
                             46 	.globl _T1
                             47 	.globl _T0
                             48 	.globl _INT1
                             49 	.globl _INT0
                             50 	.globl _TXD
                             51 	.globl _RXD
                             52 	.globl _P3_7
                             53 	.globl _P3_6
                             54 	.globl _P3_5
                             55 	.globl _P3_4
                             56 	.globl _P3_3
                             57 	.globl _P3_2
                             58 	.globl _P3_1
                             59 	.globl _P3_0
                             60 	.globl _EA
                             61 	.globl _ES
                             62 	.globl _ET1
                             63 	.globl _EX1
                             64 	.globl _ET0
                             65 	.globl _EX0
                             66 	.globl _P2_7
                             67 	.globl _P2_6
                             68 	.globl _P2_5
                             69 	.globl _P2_4
                             70 	.globl _P2_3
                             71 	.globl _P2_2
                             72 	.globl _P2_1
                             73 	.globl _P2_0
                             74 	.globl _SM0
                             75 	.globl _SM1
                             76 	.globl _SM2
                             77 	.globl _REN
                             78 	.globl _TB8
                             79 	.globl _RB8
                             80 	.globl _TI
                             81 	.globl _RI
                             82 	.globl _P1_7
                             83 	.globl _P1_6
                             84 	.globl _P1_5
                             85 	.globl _P1_4
                             86 	.globl _P1_3
                             87 	.globl _P1_2
                             88 	.globl _P1_1
                             89 	.globl _P1_0
                             90 	.globl _TF1
                             91 	.globl _TR1
                             92 	.globl _TF0
                             93 	.globl _TR0
                             94 	.globl _IE1
                             95 	.globl _IT1
                             96 	.globl _IE0
                             97 	.globl _IT0
                             98 	.globl _P0_7
                             99 	.globl _P0_6
                            100 	.globl _P0_5
                            101 	.globl _P0_4
                            102 	.globl _P0_3
                            103 	.globl _P0_2
                            104 	.globl _P0_1
                            105 	.globl _P0_0
                            106 	.globl _TH2
                            107 	.globl _TL2
                            108 	.globl _RCAP2H
                            109 	.globl _RCAP2L
                            110 	.globl _T2CON
                            111 	.globl _B
                            112 	.globl _ACC
                            113 	.globl _PSW
                            114 	.globl _IP
                            115 	.globl _P3
                            116 	.globl _IE
                            117 	.globl _P2
                            118 	.globl _SBUF
                            119 	.globl _SCON
                            120 	.globl _P1
                            121 	.globl _TH1
                            122 	.globl _TH0
                            123 	.globl _TL1
                            124 	.globl _TL0
                            125 	.globl _TMOD
                            126 	.globl _TCON
                            127 	.globl _PCON
                            128 	.globl _DPH
                            129 	.globl _DPL
                            130 	.globl _SP
                            131 	.globl _P0
                            132 	.globl _quickSort_PARM_2
                            133 	.globl _array
                            134 	.globl _quickSort
                            135 ;--------------------------------------------------------
                            136 ; special function registers
                            137 ;--------------------------------------------------------
                            138 	.area RSEG    (ABS,DATA)
   0000                     139 	.org 0x0000
                     0080   140 _P0	=	0x0080
                     0081   141 _SP	=	0x0081
                     0082   142 _DPL	=	0x0082
                     0083   143 _DPH	=	0x0083
                     0087   144 _PCON	=	0x0087
                     0088   145 _TCON	=	0x0088
                     0089   146 _TMOD	=	0x0089
                     008A   147 _TL0	=	0x008a
                     008B   148 _TL1	=	0x008b
                     008C   149 _TH0	=	0x008c
                     008D   150 _TH1	=	0x008d
                     0090   151 _P1	=	0x0090
                     0098   152 _SCON	=	0x0098
                     0099   153 _SBUF	=	0x0099
                     00A0   154 _P2	=	0x00a0
                     00A8   155 _IE	=	0x00a8
                     00B0   156 _P3	=	0x00b0
                     00B8   157 _IP	=	0x00b8
                     00D0   158 _PSW	=	0x00d0
                     00E0   159 _ACC	=	0x00e0
                     00F0   160 _B	=	0x00f0
                     00C8   161 _T2CON	=	0x00c8
                     00CA   162 _RCAP2L	=	0x00ca
                     00CB   163 _RCAP2H	=	0x00cb
                     00CC   164 _TL2	=	0x00cc
                     00CD   165 _TH2	=	0x00cd
                            166 ;--------------------------------------------------------
                            167 ; special function bits
                            168 ;--------------------------------------------------------
                            169 	.area RSEG    (ABS,DATA)
   0000                     170 	.org 0x0000
                     0080   171 _P0_0	=	0x0080
                     0081   172 _P0_1	=	0x0081
                     0082   173 _P0_2	=	0x0082
                     0083   174 _P0_3	=	0x0083
                     0084   175 _P0_4	=	0x0084
                     0085   176 _P0_5	=	0x0085
                     0086   177 _P0_6	=	0x0086
                     0087   178 _P0_7	=	0x0087
                     0088   179 _IT0	=	0x0088
                     0089   180 _IE0	=	0x0089
                     008A   181 _IT1	=	0x008a
                     008B   182 _IE1	=	0x008b
                     008C   183 _TR0	=	0x008c
                     008D   184 _TF0	=	0x008d
                     008E   185 _TR1	=	0x008e
                     008F   186 _TF1	=	0x008f
                     0090   187 _P1_0	=	0x0090
                     0091   188 _P1_1	=	0x0091
                     0092   189 _P1_2	=	0x0092
                     0093   190 _P1_3	=	0x0093
                     0094   191 _P1_4	=	0x0094
                     0095   192 _P1_5	=	0x0095
                     0096   193 _P1_6	=	0x0096
                     0097   194 _P1_7	=	0x0097
                     0098   195 _RI	=	0x0098
                     0099   196 _TI	=	0x0099
                     009A   197 _RB8	=	0x009a
                     009B   198 _TB8	=	0x009b
                     009C   199 _REN	=	0x009c
                     009D   200 _SM2	=	0x009d
                     009E   201 _SM1	=	0x009e
                     009F   202 _SM0	=	0x009f
                     00A0   203 _P2_0	=	0x00a0
                     00A1   204 _P2_1	=	0x00a1
                     00A2   205 _P2_2	=	0x00a2
                     00A3   206 _P2_3	=	0x00a3
                     00A4   207 _P2_4	=	0x00a4
                     00A5   208 _P2_5	=	0x00a5
                     00A6   209 _P2_6	=	0x00a6
                     00A7   210 _P2_7	=	0x00a7
                     00A8   211 _EX0	=	0x00a8
                     00A9   212 _ET0	=	0x00a9
                     00AA   213 _EX1	=	0x00aa
                     00AB   214 _ET1	=	0x00ab
                     00AC   215 _ES	=	0x00ac
                     00AF   216 _EA	=	0x00af
                     00B0   217 _P3_0	=	0x00b0
                     00B1   218 _P3_1	=	0x00b1
                     00B2   219 _P3_2	=	0x00b2
                     00B3   220 _P3_3	=	0x00b3
                     00B4   221 _P3_4	=	0x00b4
                     00B5   222 _P3_5	=	0x00b5
                     00B6   223 _P3_6	=	0x00b6
                     00B7   224 _P3_7	=	0x00b7
                     00B0   225 _RXD	=	0x00b0
                     00B1   226 _TXD	=	0x00b1
                     00B2   227 _INT0	=	0x00b2
                     00B3   228 _INT1	=	0x00b3
                     00B4   229 _T0	=	0x00b4
                     00B5   230 _T1	=	0x00b5
                     00B6   231 _WR	=	0x00b6
                     00B7   232 _RD	=	0x00b7
                     00B8   233 _PX0	=	0x00b8
                     00B9   234 _PT0	=	0x00b9
                     00BA   235 _PX1	=	0x00ba
                     00BB   236 _PT1	=	0x00bb
                     00BC   237 _PS	=	0x00bc
                     00D0   238 _P	=	0x00d0
                     00D1   239 _F1	=	0x00d1
                     00D2   240 _OV	=	0x00d2
                     00D3   241 _RS0	=	0x00d3
                     00D4   242 _RS1	=	0x00d4
                     00D5   243 _F0	=	0x00d5
                     00D6   244 _AC	=	0x00d6
                     00D7   245 _CY	=	0x00d7
                     00AD   246 _ET2	=	0x00ad
                     00BD   247 _PT2	=	0x00bd
                     00C8   248 _T2CON_0	=	0x00c8
                     00C9   249 _T2CON_1	=	0x00c9
                     00CA   250 _T2CON_2	=	0x00ca
                     00CB   251 _T2CON_3	=	0x00cb
                     00CC   252 _T2CON_4	=	0x00cc
                     00CD   253 _T2CON_5	=	0x00cd
                     00CE   254 _T2CON_6	=	0x00ce
                     00CF   255 _T2CON_7	=	0x00cf
                     00C8   256 _CP_RL2	=	0x00c8
                     00C9   257 _C_T2	=	0x00c9
                     00CA   258 _TR2	=	0x00ca
                     00CB   259 _EXEN2	=	0x00cb
                     00CC   260 _TCLK	=	0x00cc
                     00CD   261 _RCLK	=	0x00cd
                     00CE   262 _EXF2	=	0x00ce
                     00CF   263 _TF2	=	0x00cf
                            264 ;--------------------------------------------------------
                            265 ; overlayable register banks
                            266 ;--------------------------------------------------------
                            267 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     268 	.ds 8
                            269 ;--------------------------------------------------------
                            270 ; internal ram data
                            271 ;--------------------------------------------------------
                            272 	.area DSEG    (DATA)
   0008                     273 _array::
   0008                     274 	.ds 4
   000C                     275 _quickSort_PARM_2:
   000C                     276 	.ds 2
   000E                     277 _quickSort_left_1_5:
   000E                     278 	.ds 2
   0010                     279 _quickSort_i_1_6:
   0010                     280 	.ds 2
   0012                     281 _quickSort_j_1_6:
   0012                     282 	.ds 2
   0014                     283 _quickSort_pivot_1_6:
   0014                     284 	.ds 2
                            285 ;--------------------------------------------------------
                            286 ; overlayable items in internal ram 
                            287 ;--------------------------------------------------------
                            288 ;--------------------------------------------------------
                            289 ; Stack segment in internal ram 
                            290 ;--------------------------------------------------------
                            291 	.area	SSEG	(DATA)
   0018                     292 __start__stack:
   0018                     293 	.ds	1
                            294 
                            295 ;--------------------------------------------------------
                            296 ; indirectly addressable internal ram data
                            297 ;--------------------------------------------------------
                            298 	.area ISEG    (DATA)
                            299 ;--------------------------------------------------------
                            300 ; absolute internal ram data
                            301 ;--------------------------------------------------------
                            302 	.area IABS    (ABS,DATA)
                            303 	.area IABS    (ABS,DATA)
                            304 ;--------------------------------------------------------
                            305 ; bit data
                            306 ;--------------------------------------------------------
                            307 	.area BSEG    (BIT)
                            308 ;--------------------------------------------------------
                            309 ; paged external ram data
                            310 ;--------------------------------------------------------
                            311 	.area PSEG    (PAG,XDATA)
                            312 ;--------------------------------------------------------
                            313 ; external ram data
                            314 ;--------------------------------------------------------
                            315 	.area XSEG    (XDATA)
                            316 ;--------------------------------------------------------
                            317 ; absolute external ram data
                            318 ;--------------------------------------------------------
                            319 	.area XABS    (ABS,XDATA)
                            320 ;--------------------------------------------------------
                            321 ; external initialized ram data
                            322 ;--------------------------------------------------------
                            323 	.area XISEG   (XDATA)
                            324 	.area HOME    (CODE)
                            325 	.area GSINIT0 (CODE)
                            326 	.area GSINIT1 (CODE)
                            327 	.area GSINIT2 (CODE)
                            328 	.area GSINIT3 (CODE)
                            329 	.area GSINIT4 (CODE)
                            330 	.area GSINIT5 (CODE)
                            331 	.area GSINIT  (CODE)
                            332 	.area GSFINAL (CODE)
                            333 	.area CSEG    (CODE)
                            334 ;--------------------------------------------------------
                            335 ; interrupt vector 
                            336 ;--------------------------------------------------------
                            337 	.area HOME    (CODE)
   0000                     338 __interrupt_vect:
   0000 02 00 06      [24]  339 	ljmp	__sdcc_gsinit_startup
                            340 ;--------------------------------------------------------
                            341 ; global & static initialisations
                            342 ;--------------------------------------------------------
                            343 	.area HOME    (CODE)
                            344 	.area GSINIT  (CODE)
                            345 	.area GSFINAL (CODE)
                            346 	.area GSINIT  (CODE)
                            347 	.globl __sdcc_gsinit_startup
                            348 	.globl __sdcc_program_startup
                            349 	.globl __start__stack
                            350 	.globl __mcs51_genXINIT
                            351 	.globl __mcs51_genXRAMCLEAR
                            352 	.globl __mcs51_genRAMCLEAR
                            353 	.area GSFINAL (CODE)
   005F 02 00 03      [24]  354 	ljmp	__sdcc_program_startup
                            355 ;--------------------------------------------------------
                            356 ; Home
                            357 ;--------------------------------------------------------
                            358 	.area HOME    (CODE)
                            359 	.area HOME    (CODE)
   0003                     360 __sdcc_program_startup:
   0003 02 00 62      [24]  361 	ljmp	_main
                            362 ;	return from main will return to caller
                            363 ;--------------------------------------------------------
                            364 ; code
                            365 ;--------------------------------------------------------
                            366 	.area CSEG    (CODE)
                            367 ;------------------------------------------------------------
                            368 ;Allocation info for local variables in function 'main'
                            369 ;------------------------------------------------------------
                            370 ;i                         Allocated to registers r6 r7 
                            371 ;------------------------------------------------------------
                            372 ;	sort4.c:6: void main(){
                            373 ;	-----------------------------------------
                            374 ;	 function main
                            375 ;	-----------------------------------------
   0062                     376 _main:
                     0007   377 	ar7 = 0x07
                     0006   378 	ar6 = 0x06
                     0005   379 	ar5 = 0x05
                     0004   380 	ar4 = 0x04
                     0003   381 	ar3 = 0x03
                     0002   382 	ar2 = 0x02
                     0001   383 	ar1 = 0x01
                     0000   384 	ar0 = 0x00
                            385 ;	sort4.c:9: for(i = 0; i < 4; i++) {
   0062 7E 00         [12]  386 	mov	r6,#0x00
   0064 7F 00         [12]  387 	mov	r7,#0x00
   0066                     388 00106$:
                            389 ;	sort4.c:10: array[i] = P0;
   0066 EE            [12]  390 	mov	a,r6
   0067 24 08         [12]  391 	add	a,#_array
   0069 F8            [12]  392 	mov	r0,a
   006A A6 80         [24]  393 	mov	@r0,_P0
                            394 ;	sort4.c:9: for(i = 0; i < 4; i++) {
   006C 0E            [12]  395 	inc	r6
   006D BE 00 01      [24]  396 	cjne	r6,#0x00,00126$
   0070 0F            [12]  397 	inc	r7
   0071                     398 00126$:
   0071 C3            [12]  399 	clr	c
   0072 EE            [12]  400 	mov	a,r6
   0073 94 04         [12]  401 	subb	a,#0x04
   0075 EF            [12]  402 	mov	a,r7
   0076 64 80         [12]  403 	xrl	a,#0x80
   0078 94 80         [12]  404 	subb	a,#0x80
   007A 40 EA         [24]  405 	jc	00106$
                            406 ;	sort4.c:12: quickSort(0, 3);
   007C 75 0C 03      [24]  407 	mov	_quickSort_PARM_2,#0x03
   007F 75 0D 00      [24]  408 	mov	(_quickSort_PARM_2 + 1),#0x00
   0082 90 00 00      [24]  409 	mov	dptr,#0x0000
   0085 12 00 A4      [24]  410 	lcall	_quickSort
                            411 ;	sort4.c:13: for(i = 0; i < 4; i++) {
   0088 7E 00         [12]  412 	mov	r6,#0x00
   008A 7F 00         [12]  413 	mov	r7,#0x00
   008C                     414 00108$:
                            415 ;	sort4.c:14: P2 = array[i];
   008C EE            [12]  416 	mov	a,r6
   008D 24 08         [12]  417 	add	a,#_array
   008F F9            [12]  418 	mov	r1,a
   0090 87 A0         [24]  419 	mov	_P2,@r1
                            420 ;	sort4.c:13: for(i = 0; i < 4; i++) {
   0092 0E            [12]  421 	inc	r6
   0093 BE 00 01      [24]  422 	cjne	r6,#0x00,00128$
   0096 0F            [12]  423 	inc	r7
   0097                     424 00128$:
   0097 C3            [12]  425 	clr	c
   0098 EE            [12]  426 	mov	a,r6
   0099 94 04         [12]  427 	subb	a,#0x04
   009B EF            [12]  428 	mov	a,r7
   009C 64 80         [12]  429 	xrl	a,#0x80
   009E 94 80         [12]  430 	subb	a,#0x80
   00A0 40 EA         [24]  431 	jc	00108$
                            432 ;	sort4.c:17: while(1);
   00A2                     433 00104$:
   00A2 80 FE         [24]  434 	sjmp	00104$
                            435 ;------------------------------------------------------------
                            436 ;Allocation info for local variables in function 'quickSort'
                            437 ;------------------------------------------------------------
                            438 ;right                     Allocated with name '_quickSort_PARM_2'
                            439 ;left                      Allocated with name '_quickSort_left_1_5'
                            440 ;i                         Allocated with name '_quickSort_i_1_6'
                            441 ;j                         Allocated with name '_quickSort_j_1_6'
                            442 ;tmp                       Allocated to registers r5 r4 
                            443 ;pivot                     Allocated with name '_quickSort_pivot_1_6'
                            444 ;------------------------------------------------------------
                            445 ;	sort4.c:20: void quickSort(int left, int right){
                            446 ;	-----------------------------------------
                            447 ;	 function quickSort
                            448 ;	-----------------------------------------
   00A4                     449 _quickSort:
   00A4 85 82 0E      [24]  450 	mov	_quickSort_left_1_5,dpl
   00A7 85 83 0F      [24]  451 	mov	(_quickSort_left_1_5 + 1),dph
                            452 ;	sort4.c:21: int i = left;
   00AA 85 0E 10      [24]  453 	mov	_quickSort_i_1_6,_quickSort_left_1_5
   00AD 85 0F 11      [24]  454 	mov	(_quickSort_i_1_6 + 1),(_quickSort_left_1_5 + 1)
                            455 ;	sort4.c:22: int j = right;
   00B0 85 0C 12      [24]  456 	mov	_quickSort_j_1_6,_quickSort_PARM_2
   00B3 85 0D 13      [24]  457 	mov	(_quickSort_j_1_6 + 1),(_quickSort_PARM_2 + 1)
                            458 ;	sort4.c:24: int pivot = array[(left + right) / 2];
   00B6 E5 12         [12]  459 	mov	a,_quickSort_j_1_6
   00B8 25 0E         [12]  460 	add	a,_quickSort_left_1_5
   00BA F5 82         [12]  461 	mov	dpl,a
   00BC E5 13         [12]  462 	mov	a,(_quickSort_j_1_6 + 1)
   00BE 35 0F         [12]  463 	addc	a,(_quickSort_left_1_5 + 1)
   00C0 F5 83         [12]  464 	mov	dph,a
   00C2 75 16 02      [24]  465 	mov	__divsint_PARM_2,#0x02
   00C5 75 17 00      [24]  466 	mov	(__divsint_PARM_2 + 1),#0x00
   00C8 12 01 DB      [24]  467 	lcall	__divsint
   00CB AE 82         [24]  468 	mov	r6,dpl
   00CD EE            [12]  469 	mov	a,r6
   00CE 24 08         [12]  470 	add	a,#_array
   00D0 F9            [12]  471 	mov	r1,a
   00D1 87 07         [24]  472 	mov	ar7,@r1
   00D3 8F 14         [24]  473 	mov	_quickSort_pivot_1_6,r7
   00D5 75 15 00      [24]  474 	mov	(_quickSort_pivot_1_6 + 1),#0x00
                            475 ;	sort4.c:26: while(i <= j) {
   00D8                     476 00109$:
   00D8 C3            [12]  477 	clr	c
   00D9 E5 12         [12]  478 	mov	a,_quickSort_j_1_6
   00DB 95 10         [12]  479 	subb	a,_quickSort_i_1_6
   00DD E5 13         [12]  480 	mov	a,(_quickSort_j_1_6 + 1)
   00DF 64 80         [12]  481 	xrl	a,#0x80
   00E1 85 11 F0      [24]  482 	mov	b,(_quickSort_i_1_6 + 1)
   00E4 63 F0 80      [24]  483 	xrl	b,#0x80
   00E7 95 F0         [12]  484 	subb	a,b
   00E9 50 03         [24]  485 	jnc	00146$
   00EB 02 01 73      [24]  486 	ljmp	00111$
   00EE                     487 00146$:
                            488 ;	sort4.c:27: while(array[i] < pivot) {
   00EE AA 10         [24]  489 	mov	r2,_quickSort_i_1_6
   00F0 AB 11         [24]  490 	mov	r3,(_quickSort_i_1_6 + 1)
   00F2                     491 00101$:
   00F2 EA            [12]  492 	mov	a,r2
   00F3 24 08         [12]  493 	add	a,#_array
   00F5 F9            [12]  494 	mov	r1,a
   00F6 87 07         [24]  495 	mov	ar7,@r1
   00F8 7E 00         [12]  496 	mov	r6,#0x00
   00FA C3            [12]  497 	clr	c
   00FB EF            [12]  498 	mov	a,r7
   00FC 95 14         [12]  499 	subb	a,_quickSort_pivot_1_6
   00FE EE            [12]  500 	mov	a,r6
   00FF 64 80         [12]  501 	xrl	a,#0x80
   0101 85 15 F0      [24]  502 	mov	b,(_quickSort_pivot_1_6 + 1)
   0104 63 F0 80      [24]  503 	xrl	b,#0x80
   0107 95 F0         [12]  504 	subb	a,b
   0109 50 07         [24]  505 	jnc	00126$
                            506 ;	sort4.c:28: i++;
   010B 0A            [12]  507 	inc	r2
                            508 ;	sort4.c:30: while(array[j] > pivot) {
   010C BA 00 E3      [24]  509 	cjne	r2,#0x00,00101$
   010F 0B            [12]  510 	inc	r3
   0110 80 E0         [24]  511 	sjmp	00101$
   0112                     512 00126$:
   0112 8A 10         [24]  513 	mov	_quickSort_i_1_6,r2
   0114 8B 11         [24]  514 	mov	(_quickSort_i_1_6 + 1),r3
   0116 AE 12         [24]  515 	mov	r6,_quickSort_j_1_6
   0118 AF 13         [24]  516 	mov	r7,(_quickSort_j_1_6 + 1)
   011A                     517 00104$:
   011A EE            [12]  518 	mov	a,r6
   011B 24 08         [12]  519 	add	a,#_array
   011D F9            [12]  520 	mov	r1,a
   011E 87 03         [24]  521 	mov	ar3,@r1
   0120 8B 02         [24]  522 	mov	ar2,r3
   0122 7D 00         [12]  523 	mov	r5,#0x00
   0124 C3            [12]  524 	clr	c
   0125 E5 14         [12]  525 	mov	a,_quickSort_pivot_1_6
   0127 9A            [12]  526 	subb	a,r2
   0128 E5 15         [12]  527 	mov	a,(_quickSort_pivot_1_6 + 1)
   012A 64 80         [12]  528 	xrl	a,#0x80
   012C 8D F0         [24]  529 	mov	b,r5
   012E 63 F0 80      [24]  530 	xrl	b,#0x80
   0131 95 F0         [12]  531 	subb	a,b
   0133 50 07         [24]  532 	jnc	00127$
                            533 ;	sort4.c:31: j--;
   0135 1E            [12]  534 	dec	r6
   0136 BE FF 01      [24]  535 	cjne	r6,#0xFF,00150$
   0139 1F            [12]  536 	dec	r7
   013A                     537 00150$:
   013A 80 DE         [24]  538 	sjmp	00104$
   013C                     539 00127$:
   013C 8E 12         [24]  540 	mov	_quickSort_j_1_6,r6
   013E 8F 13         [24]  541 	mov	(_quickSort_j_1_6 + 1),r7
                            542 ;	sort4.c:33: if(i <= j) {
   0140 C3            [12]  543 	clr	c
   0141 EE            [12]  544 	mov	a,r6
   0142 95 10         [12]  545 	subb	a,_quickSort_i_1_6
   0144 EF            [12]  546 	mov	a,r7
   0145 64 80         [12]  547 	xrl	a,#0x80
   0147 85 11 F0      [24]  548 	mov	b,(_quickSort_i_1_6 + 1)
   014A 63 F0 80      [24]  549 	xrl	b,#0x80
   014D 95 F0         [12]  550 	subb	a,b
   014F 40 87         [24]  551 	jc	00109$
                            552 ;	sort4.c:34: tmp = array[i];
   0151 E5 10         [12]  553 	mov	a,_quickSort_i_1_6
   0153 24 08         [12]  554 	add	a,#_array
   0155 F8            [12]  555 	mov	r0,a
   0156 86 05         [24]  556 	mov	ar5,@r0
   0158 7C 00         [12]  557 	mov	r4,#0x00
                            558 ;	sort4.c:35: array[i] = array[j];
   015A A6 03         [24]  559 	mov	@r0,ar3
                            560 ;	sort4.c:36: array[j] = tmp;
   015C A7 05         [24]  561 	mov	@r1,ar5
                            562 ;	sort4.c:37: i++;
   015E 05 10         [12]  563 	inc	_quickSort_i_1_6
   0160 E4            [12]  564 	clr	a
   0161 B5 10 02      [24]  565 	cjne	a,_quickSort_i_1_6,00152$
   0164 05 11         [12]  566 	inc	(_quickSort_i_1_6 + 1)
   0166                     567 00152$:
                            568 ;	sort4.c:38: j--;
   0166 EE            [12]  569 	mov	a,r6
   0167 24 FF         [12]  570 	add	a,#0xFF
   0169 F5 12         [12]  571 	mov	_quickSort_j_1_6,a
   016B EF            [12]  572 	mov	a,r7
   016C 34 FF         [12]  573 	addc	a,#0xFF
   016E F5 13         [12]  574 	mov	(_quickSort_j_1_6 + 1),a
   0170 02 00 D8      [24]  575 	ljmp	00109$
   0173                     576 00111$:
                            577 ;	sort4.c:41: if(left < j) {
   0173 C3            [12]  578 	clr	c
   0174 E5 0E         [12]  579 	mov	a,_quickSort_left_1_5
   0176 95 12         [12]  580 	subb	a,_quickSort_j_1_6
   0178 E5 0F         [12]  581 	mov	a,(_quickSort_left_1_5 + 1)
   017A 64 80         [12]  582 	xrl	a,#0x80
   017C 85 13 F0      [24]  583 	mov	b,(_quickSort_j_1_6 + 1)
   017F 63 F0 80      [24]  584 	xrl	b,#0x80
   0182 95 F0         [12]  585 	subb	a,b
   0184 50 0F         [24]  586 	jnc	00113$
                            587 ;	sort4.c:42: quickSort(left, j);
   0186 85 12 0C      [24]  588 	mov	_quickSort_PARM_2,_quickSort_j_1_6
   0189 85 13 0D      [24]  589 	mov	(_quickSort_PARM_2 + 1),(_quickSort_j_1_6 + 1)
   018C 85 0E 82      [24]  590 	mov	dpl,_quickSort_left_1_5
   018F 85 0F 83      [24]  591 	mov	dph,(_quickSort_left_1_5 + 1)
   0192 12 00 A4      [24]  592 	lcall	_quickSort
   0195                     593 00113$:
                            594 ;	sort4.c:44: if(i < right) {
   0195 C3            [12]  595 	clr	c
   0196 E5 10         [12]  596 	mov	a,_quickSort_i_1_6
   0198 95 0C         [12]  597 	subb	a,_quickSort_PARM_2
   019A E5 11         [12]  598 	mov	a,(_quickSort_i_1_6 + 1)
   019C 64 80         [12]  599 	xrl	a,#0x80
   019E 85 0D F0      [24]  600 	mov	b,(_quickSort_PARM_2 + 1)
   01A1 63 F0 80      [24]  601 	xrl	b,#0x80
   01A4 95 F0         [12]  602 	subb	a,b
   01A6 50 09         [24]  603 	jnc	00116$
                            604 ;	sort4.c:45: quickSort(i, right);
   01A8 85 10 82      [24]  605 	mov	dpl,_quickSort_i_1_6
   01AB 85 11 83      [24]  606 	mov	dph,(_quickSort_i_1_6 + 1)
   01AE 02 00 A4      [24]  607 	ljmp	_quickSort
   01B1                     608 00116$:
   01B1 22            [24]  609 	ret
                            610 	.area CSEG    (CODE)
                            611 	.area CONST   (CODE)
                            612 	.area XINIT   (CODE)
                            613 	.area CABS    (ABS,CODE)
