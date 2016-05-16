                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.3.0 #8604 (Dec 30 2013) (Linux)
                              4 ; This file was generated Fri May 13 12:39:06 2016
                              5 ;--------------------------------------------------------
                              6 	.module sort10
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _bubble_sort_PARM_2
                             13 	.globl _main
                             14 	.globl _TF2
                             15 	.globl _EXF2
                             16 	.globl _RCLK
                             17 	.globl _TCLK
                             18 	.globl _EXEN2
                             19 	.globl _TR2
                             20 	.globl _C_T2
                             21 	.globl _CP_RL2
                             22 	.globl _T2CON_7
                             23 	.globl _T2CON_6
                             24 	.globl _T2CON_5
                             25 	.globl _T2CON_4
                             26 	.globl _T2CON_3
                             27 	.globl _T2CON_2
                             28 	.globl _T2CON_1
                             29 	.globl _T2CON_0
                             30 	.globl _PT2
                             31 	.globl _ET2
                             32 	.globl _CY
                             33 	.globl _AC
                             34 	.globl _F0
                             35 	.globl _RS1
                             36 	.globl _RS0
                             37 	.globl _OV
                             38 	.globl _F1
                             39 	.globl _P
                             40 	.globl _PS
                             41 	.globl _PT1
                             42 	.globl _PX1
                             43 	.globl _PT0
                             44 	.globl _PX0
                             45 	.globl _RD
                             46 	.globl _WR
                             47 	.globl _T1
                             48 	.globl _T0
                             49 	.globl _INT1
                             50 	.globl _INT0
                             51 	.globl _TXD
                             52 	.globl _RXD
                             53 	.globl _P3_7
                             54 	.globl _P3_6
                             55 	.globl _P3_5
                             56 	.globl _P3_4
                             57 	.globl _P3_3
                             58 	.globl _P3_2
                             59 	.globl _P3_1
                             60 	.globl _P3_0
                             61 	.globl _EA
                             62 	.globl _ES
                             63 	.globl _ET1
                             64 	.globl _EX1
                             65 	.globl _ET0
                             66 	.globl _EX0
                             67 	.globl _P2_7
                             68 	.globl _P2_6
                             69 	.globl _P2_5
                             70 	.globl _P2_4
                             71 	.globl _P2_3
                             72 	.globl _P2_2
                             73 	.globl _P2_1
                             74 	.globl _P2_0
                             75 	.globl _SM0
                             76 	.globl _SM1
                             77 	.globl _SM2
                             78 	.globl _REN
                             79 	.globl _TB8
                             80 	.globl _RB8
                             81 	.globl _TI
                             82 	.globl _RI
                             83 	.globl _P1_7
                             84 	.globl _P1_6
                             85 	.globl _P1_5
                             86 	.globl _P1_4
                             87 	.globl _P1_3
                             88 	.globl _P1_2
                             89 	.globl _P1_1
                             90 	.globl _P1_0
                             91 	.globl _TF1
                             92 	.globl _TR1
                             93 	.globl _TF0
                             94 	.globl _TR0
                             95 	.globl _IE1
                             96 	.globl _IT1
                             97 	.globl _IE0
                             98 	.globl _IT0
                             99 	.globl _P0_7
                            100 	.globl _P0_6
                            101 	.globl _P0_5
                            102 	.globl _P0_4
                            103 	.globl _P0_3
                            104 	.globl _P0_2
                            105 	.globl _P0_1
                            106 	.globl _P0_0
                            107 	.globl _TH2
                            108 	.globl _TL2
                            109 	.globl _RCAP2H
                            110 	.globl _RCAP2L
                            111 	.globl _T2CON
                            112 	.globl _B
                            113 	.globl _ACC
                            114 	.globl _PSW
                            115 	.globl _IP
                            116 	.globl _P3
                            117 	.globl _IE
                            118 	.globl _P2
                            119 	.globl _SBUF
                            120 	.globl _SCON
                            121 	.globl _P1
                            122 	.globl _TH1
                            123 	.globl _TH0
                            124 	.globl _TL1
                            125 	.globl _TL0
                            126 	.globl _TMOD
                            127 	.globl _TCON
                            128 	.globl _PCON
                            129 	.globl _DPH
                            130 	.globl _DPL
                            131 	.globl _SP
                            132 	.globl _P0
                            133 	.globl _array
                            134 	.globl _bubble_sort
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
   0008                     274 	.ds 10
                            275 ;--------------------------------------------------------
                            276 ; overlayable items in internal ram 
                            277 ;--------------------------------------------------------
                            278 	.area	OSEG    (OVR,DATA)
   0012                     279 _bubble_sort_PARM_2:
   0012                     280 	.ds 2
   0014                     281 _bubble_sort_list_1_5:
   0014                     282 	.ds 3
   0017                     283 _bubble_sort_c_1_6:
   0017                     284 	.ds 1
   0018                     285 _bubble_sort_d_1_6:
   0018                     286 	.ds 1
   0019                     287 _bubble_sort_sloc0_1_0:
   0019                     288 	.ds 2
   001B                     289 _bubble_sort_sloc1_1_0:
   001B                     290 	.ds 3
                            291 ;--------------------------------------------------------
                            292 ; Stack segment in internal ram 
                            293 ;--------------------------------------------------------
                            294 	.area	SSEG	(DATA)
   001E                     295 __start__stack:
   001E                     296 	.ds	1
                            297 
                            298 ;--------------------------------------------------------
                            299 ; indirectly addressable internal ram data
                            300 ;--------------------------------------------------------
                            301 	.area ISEG    (DATA)
                            302 ;--------------------------------------------------------
                            303 ; absolute internal ram data
                            304 ;--------------------------------------------------------
                            305 	.area IABS    (ABS,DATA)
                            306 	.area IABS    (ABS,DATA)
                            307 ;--------------------------------------------------------
                            308 ; bit data
                            309 ;--------------------------------------------------------
                            310 	.area BSEG    (BIT)
                            311 ;--------------------------------------------------------
                            312 ; paged external ram data
                            313 ;--------------------------------------------------------
                            314 	.area PSEG    (PAG,XDATA)
                            315 ;--------------------------------------------------------
                            316 ; external ram data
                            317 ;--------------------------------------------------------
                            318 	.area XSEG    (XDATA)
                            319 ;--------------------------------------------------------
                            320 ; absolute external ram data
                            321 ;--------------------------------------------------------
                            322 	.area XABS    (ABS,XDATA)
                            323 ;--------------------------------------------------------
                            324 ; external initialized ram data
                            325 ;--------------------------------------------------------
                            326 	.area XISEG   (XDATA)
                            327 	.area HOME    (CODE)
                            328 	.area GSINIT0 (CODE)
                            329 	.area GSINIT1 (CODE)
                            330 	.area GSINIT2 (CODE)
                            331 	.area GSINIT3 (CODE)
                            332 	.area GSINIT4 (CODE)
                            333 	.area GSINIT5 (CODE)
                            334 	.area GSINIT  (CODE)
                            335 	.area GSFINAL (CODE)
                            336 	.area CSEG    (CODE)
                            337 ;--------------------------------------------------------
                            338 ; interrupt vector 
                            339 ;--------------------------------------------------------
                            340 	.area HOME    (CODE)
   0000                     341 __interrupt_vect:
   0000 02 00 06      [24]  342 	ljmp	__sdcc_gsinit_startup
                            343 ;--------------------------------------------------------
                            344 ; global & static initialisations
                            345 ;--------------------------------------------------------
                            346 	.area HOME    (CODE)
                            347 	.area GSINIT  (CODE)
                            348 	.area GSFINAL (CODE)
                            349 	.area GSINIT  (CODE)
                            350 	.globl __sdcc_gsinit_startup
                            351 	.globl __sdcc_program_startup
                            352 	.globl __start__stack
                            353 	.globl __mcs51_genXINIT
                            354 	.globl __mcs51_genXRAMCLEAR
                            355 	.globl __mcs51_genRAMCLEAR
                            356 	.area GSFINAL (CODE)
   005F 02 00 03      [24]  357 	ljmp	__sdcc_program_startup
                            358 ;--------------------------------------------------------
                            359 ; Home
                            360 ;--------------------------------------------------------
                            361 	.area HOME    (CODE)
                            362 	.area HOME    (CODE)
   0003                     363 __sdcc_program_startup:
   0003 02 00 62      [24]  364 	ljmp	_main
                            365 ;	return from main will return to caller
                            366 ;--------------------------------------------------------
                            367 ; code
                            368 ;--------------------------------------------------------
                            369 	.area CSEG    (CODE)
                            370 ;------------------------------------------------------------
                            371 ;Allocation info for local variables in function 'main'
                            372 ;------------------------------------------------------------
                            373 ;i                         Allocated to registers r6 r7 
                            374 ;------------------------------------------------------------
                            375 ;	sort10.c:6: void main(){
                            376 ;	-----------------------------------------
                            377 ;	 function main
                            378 ;	-----------------------------------------
   0062                     379 _main:
                     0007   380 	ar7 = 0x07
                     0006   381 	ar6 = 0x06
                     0005   382 	ar5 = 0x05
                     0004   383 	ar4 = 0x04
                     0003   384 	ar3 = 0x03
                     0002   385 	ar2 = 0x02
                     0001   386 	ar1 = 0x01
                     0000   387 	ar0 = 0x00
                            388 ;	sort10.c:9: for(i = 0; i < 10; i++) {
   0062 7E 00         [12]  389 	mov	r6,#0x00
   0064 7F 00         [12]  390 	mov	r7,#0x00
   0066                     391 00106$:
                            392 ;	sort10.c:10: array[i] = P0;
   0066 EE            [12]  393 	mov	a,r6
   0067 24 08         [12]  394 	add	a,#_array
   0069 F8            [12]  395 	mov	r0,a
   006A A6 80         [24]  396 	mov	@r0,_P0
                            397 ;	sort10.c:9: for(i = 0; i < 10; i++) {
   006C 0E            [12]  398 	inc	r6
   006D BE 00 01      [24]  399 	cjne	r6,#0x00,00126$
   0070 0F            [12]  400 	inc	r7
   0071                     401 00126$:
   0071 C3            [12]  402 	clr	c
   0072 EE            [12]  403 	mov	a,r6
   0073 94 0A         [12]  404 	subb	a,#0x0A
   0075 EF            [12]  405 	mov	a,r7
   0076 64 80         [12]  406 	xrl	a,#0x80
   0078 94 80         [12]  407 	subb	a,#0x80
   007A 40 EA         [24]  408 	jc	00106$
                            409 ;	sort10.c:13: bubble_sort(array, 10);
   007C 75 12 0A      [24]  410 	mov	_bubble_sort_PARM_2,#0x0A
   007F 75 13 00      [24]  411 	mov	(_bubble_sort_PARM_2 + 1),#0x00
   0082 90 00 08      [24]  412 	mov	dptr,#_array
   0085 75 F0 40      [24]  413 	mov	b,#0x40
   0088 12 00 A7      [24]  414 	lcall	_bubble_sort
                            415 ;	sort10.c:14: for(i = 0; i < 10; i++) {
   008B 7E 00         [12]  416 	mov	r6,#0x00
   008D 7F 00         [12]  417 	mov	r7,#0x00
   008F                     418 00108$:
                            419 ;	sort10.c:15: P2 = array[i];
   008F EE            [12]  420 	mov	a,r6
   0090 24 08         [12]  421 	add	a,#_array
   0092 F9            [12]  422 	mov	r1,a
   0093 87 A0         [24]  423 	mov	_P2,@r1
                            424 ;	sort10.c:14: for(i = 0; i < 10; i++) {
   0095 0E            [12]  425 	inc	r6
   0096 BE 00 01      [24]  426 	cjne	r6,#0x00,00128$
   0099 0F            [12]  427 	inc	r7
   009A                     428 00128$:
   009A C3            [12]  429 	clr	c
   009B EE            [12]  430 	mov	a,r6
   009C 94 0A         [12]  431 	subb	a,#0x0A
   009E EF            [12]  432 	mov	a,r7
   009F 64 80         [12]  433 	xrl	a,#0x80
   00A1 94 80         [12]  434 	subb	a,#0x80
   00A3 40 EA         [24]  435 	jc	00108$
                            436 ;	sort10.c:18: while(1);
   00A5                     437 00104$:
   00A5 80 FE         [24]  438 	sjmp	00104$
                            439 ;------------------------------------------------------------
                            440 ;Allocation info for local variables in function 'bubble_sort'
                            441 ;------------------------------------------------------------
                            442 ;n                         Allocated with name '_bubble_sort_PARM_2'
                            443 ;list                      Allocated with name '_bubble_sort_list_1_5'
                            444 ;c                         Allocated with name '_bubble_sort_c_1_6'
                            445 ;d                         Allocated with name '_bubble_sort_d_1_6'
                            446 ;t                         Allocated to registers 
                            447 ;sloc0                     Allocated with name '_bubble_sort_sloc0_1_0'
                            448 ;sloc1                     Allocated with name '_bubble_sort_sloc1_1_0'
                            449 ;------------------------------------------------------------
                            450 ;	sort10.c:21: void bubble_sort(unsigned char* list, int n)
                            451 ;	-----------------------------------------
                            452 ;	 function bubble_sort
                            453 ;	-----------------------------------------
   00A7                     454 _bubble_sort:
   00A7 85 82 14      [24]  455 	mov	_bubble_sort_list_1_5,dpl
   00AA 85 83 15      [24]  456 	mov	(_bubble_sort_list_1_5 + 1),dph
   00AD 85 F0 16      [24]  457 	mov	(_bubble_sort_list_1_5 + 2),b
                            458 ;	sort10.c:25: for (c = 0 ; c < ( n - 1 ); c++)
   00B0 E5 12         [12]  459 	mov	a,_bubble_sort_PARM_2
   00B2 24 FF         [12]  460 	add	a,#0xFF
   00B4 FB            [12]  461 	mov	r3,a
   00B5 E5 13         [12]  462 	mov	a,(_bubble_sort_PARM_2 + 1)
   00B7 34 FF         [12]  463 	addc	a,#0xFF
   00B9 FC            [12]  464 	mov	r4,a
   00BA 75 17 00      [24]  465 	mov	_bubble_sort_c_1_6,#0x00
   00BD                     466 00109$:
   00BD A8 17         [24]  467 	mov	r0,_bubble_sort_c_1_6
   00BF 79 00         [12]  468 	mov	r1,#0x00
   00C1 C3            [12]  469 	clr	c
   00C2 E8            [12]  470 	mov	a,r0
   00C3 9B            [12]  471 	subb	a,r3
   00C4 E9            [12]  472 	mov	a,r1
   00C5 64 80         [12]  473 	xrl	a,#0x80
   00C7 8C F0         [24]  474 	mov	b,r4
   00C9 63 F0 80      [24]  475 	xrl	b,#0x80
   00CC 95 F0         [12]  476 	subb	a,b
   00CE 40 01         [24]  477 	jc	00130$
   00D0 22            [24]  478 	ret
   00D1                     479 00130$:
                            480 ;	sort10.c:27: for (d = 0 ; d < n - c - 1; d++)
   00D1 75 18 00      [24]  481 	mov	_bubble_sort_d_1_6,#0x00
   00D4                     482 00106$:
   00D4 A8 17         [24]  483 	mov	r0,_bubble_sort_c_1_6
   00D6 7A 00         [12]  484 	mov	r2,#0x00
   00D8 E5 12         [12]  485 	mov	a,_bubble_sort_PARM_2
   00DA C3            [12]  486 	clr	c
   00DB 98            [12]  487 	subb	a,r0
   00DC F8            [12]  488 	mov	r0,a
   00DD E5 13         [12]  489 	mov	a,(_bubble_sort_PARM_2 + 1)
   00DF 9A            [12]  490 	subb	a,r2
   00E0 FA            [12]  491 	mov	r2,a
   00E1 18            [12]  492 	dec	r0
   00E2 B8 FF 01      [24]  493 	cjne	r0,#0xFF,00131$
   00E5 1A            [12]  494 	dec	r2
   00E6                     495 00131$:
   00E6 85 18 19      [24]  496 	mov	_bubble_sort_sloc0_1_0,_bubble_sort_d_1_6
   00E9 75 1A 00      [24]  497 	mov	(_bubble_sort_sloc0_1_0 + 1),#0x00
   00EC C3            [12]  498 	clr	c
   00ED E5 19         [12]  499 	mov	a,_bubble_sort_sloc0_1_0
   00EF 98            [12]  500 	subb	a,r0
   00F0 E5 1A         [12]  501 	mov	a,(_bubble_sort_sloc0_1_0 + 1)
   00F2 64 80         [12]  502 	xrl	a,#0x80
   00F4 8A F0         [24]  503 	mov	b,r2
   00F6 63 F0 80      [24]  504 	xrl	b,#0x80
   00F9 95 F0         [12]  505 	subb	a,b
   00FB 50 74         [24]  506 	jnc	00110$
                            507 ;	sort10.c:29: if (list[d] > list[d+1])
   00FD E5 18         [12]  508 	mov	a,_bubble_sort_d_1_6
   00FF 25 14         [12]  509 	add	a,_bubble_sort_list_1_5
   0101 F5 1B         [12]  510 	mov	_bubble_sort_sloc1_1_0,a
   0103 E4            [12]  511 	clr	a
   0104 35 15         [12]  512 	addc	a,(_bubble_sort_list_1_5 + 1)
   0106 F5 1C         [12]  513 	mov	(_bubble_sort_sloc1_1_0 + 1),a
   0108 85 16 1D      [24]  514 	mov	(_bubble_sort_sloc1_1_0 + 2),(_bubble_sort_list_1_5 + 2)
   010B 85 1B 82      [24]  515 	mov	dpl,_bubble_sort_sloc1_1_0
   010E 85 1C 83      [24]  516 	mov	dph,(_bubble_sort_sloc1_1_0 + 1)
   0111 85 1D F0      [24]  517 	mov	b,(_bubble_sort_sloc1_1_0 + 2)
   0114 12 01 91      [24]  518 	lcall	__gptrget
   0117 FA            [12]  519 	mov	r2,a
   0118 74 01         [12]  520 	mov	a,#0x01
   011A 25 19         [12]  521 	add	a,_bubble_sort_sloc0_1_0
   011C F8            [12]  522 	mov	r0,a
   011D E4            [12]  523 	clr	a
   011E 35 1A         [12]  524 	addc	a,(_bubble_sort_sloc0_1_0 + 1)
   0120 F9            [12]  525 	mov	r1,a
   0121 E8            [12]  526 	mov	a,r0
   0122 25 14         [12]  527 	add	a,_bubble_sort_list_1_5
   0124 F8            [12]  528 	mov	r0,a
   0125 E9            [12]  529 	mov	a,r1
   0126 35 15         [12]  530 	addc	a,(_bubble_sort_list_1_5 + 1)
   0128 F9            [12]  531 	mov	r1,a
   0129 AF 16         [24]  532 	mov	r7,(_bubble_sort_list_1_5 + 2)
   012B 88 82         [24]  533 	mov	dpl,r0
   012D 89 83         [24]  534 	mov	dph,r1
   012F 8F F0         [24]  535 	mov	b,r7
   0131 12 01 91      [24]  536 	lcall	__gptrget
   0134 F8            [12]  537 	mov	r0,a
   0135 C3            [12]  538 	clr	c
   0136 9A            [12]  539 	subb	a,r2
   0137 50 33         [24]  540 	jnc	00107$
                            541 ;	sort10.c:34: list[d]   = list[d+1];
   0139 74 01         [12]  542 	mov	a,#0x01
   013B 25 19         [12]  543 	add	a,_bubble_sort_sloc0_1_0
   013D FE            [12]  544 	mov	r6,a
   013E E4            [12]  545 	clr	a
   013F 35 1A         [12]  546 	addc	a,(_bubble_sort_sloc0_1_0 + 1)
   0141 FF            [12]  547 	mov	r7,a
   0142 EE            [12]  548 	mov	a,r6
   0143 25 14         [12]  549 	add	a,_bubble_sort_list_1_5
   0145 FE            [12]  550 	mov	r6,a
   0146 EF            [12]  551 	mov	a,r7
   0147 35 15         [12]  552 	addc	a,(_bubble_sort_list_1_5 + 1)
   0149 FF            [12]  553 	mov	r7,a
   014A AD 16         [24]  554 	mov	r5,(_bubble_sort_list_1_5 + 2)
   014C 8E 82         [24]  555 	mov	dpl,r6
   014E 8F 83         [24]  556 	mov	dph,r7
   0150 8D F0         [24]  557 	mov	b,r5
   0152 12 01 91      [24]  558 	lcall	__gptrget
   0155 F9            [12]  559 	mov	r1,a
   0156 85 1B 82      [24]  560 	mov	dpl,_bubble_sort_sloc1_1_0
   0159 85 1C 83      [24]  561 	mov	dph,(_bubble_sort_sloc1_1_0 + 1)
   015C 85 1D F0      [24]  562 	mov	b,(_bubble_sort_sloc1_1_0 + 2)
   015F 12 01 76      [24]  563 	lcall	__gptrput
                            564 ;	sort10.c:35: list[d+1] = t;
   0162 8E 82         [24]  565 	mov	dpl,r6
   0164 8F 83         [24]  566 	mov	dph,r7
   0166 8D F0         [24]  567 	mov	b,r5
   0168 EA            [12]  568 	mov	a,r2
   0169 12 01 76      [24]  569 	lcall	__gptrput
   016C                     570 00107$:
                            571 ;	sort10.c:27: for (d = 0 ; d < n - c - 1; d++)
   016C 05 18         [12]  572 	inc	_bubble_sort_d_1_6
   016E 02 00 D4      [24]  573 	ljmp	00106$
   0171                     574 00110$:
                            575 ;	sort10.c:25: for (c = 0 ; c < ( n - 1 ); c++)
   0171 05 17         [12]  576 	inc	_bubble_sort_c_1_6
   0173 02 00 BD      [24]  577 	ljmp	00109$
                            578 	.area CSEG    (CODE)
                            579 	.area CONST   (CODE)
                            580 	.area XINIT   (CODE)
                            581 	.area CABS    (ABS,CODE)
