; ModuleID = 'demo_tfx_10_klee.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.test = type { [64 x i8], %struct.em8051*, [4 x i8*], [4 x i32], [4 x i32], [4 x i8*], [4 x i32], [4 x i32], [4 x i8*], [4 x i32], [4 x i32], i32 }
%struct.em8051 = type { i8*, i32*, i32, i8*, i32, i8*, i8*, i8*, i32, i32, [256 x i32 (%struct.em8051*)*], [256 x i32 (%struct.em8051*, i32, i8*)*], void (%struct.em8051*, i32)*, i32 (%struct.em8051*, i32)*, void (%struct.em8051*, i32)*, i32 (%struct.em8

@opt_exception_iret_sp = global i32 1, align 4
@opt_exception_iret_acc = global i32 1, align 4
@opt_exception_iret_psw = global i32 1, align 4
@opt_exception_acc_to_a = global i32 1, align 4
@opt_exception_stack = global i32 1, align 4
@opt_exception_invalid = global i32 1, align 4
@opt_input_outputlow = global i32 1, align 4
@opt_clock_select = global i32 3, align 4
@opt_clock_hz = global i32 12000000, align 4
@opt_step_instruction = global i32 0, align 4
@clockspeeds = global [12 x i32] [i32 33000000, i32 24000000, i32 22000000, i32 12000000, i32 11000000, i32 7372800, i32 6000000, i32 5000000, i32 4915200, i32 3000000, i32 1000000, i32 100000], align 16
@cur_test = global %struct.test* null, align 8
@cur_core = global %struct.em8051* null, align 8
@.str = private unnamed_addr constant [20 x i8] c"SFRREAD %X FROM %X\0A\00", align 1
@.str1 = private unnamed_addr constant [19 x i8] c"SFRWRITE %X TO %X\0A\00", align 1
@.str2 = private unnamed_addr constant [17 x i8] c"Finish Test ...\0A\00", align 1
@.str3 = private unnamed_addr constant [14 x i8] c"Run Test ...\0A\00", align 1
@.str4 = private unnamed_addr constant [3 x i8] c"P0\00", align 1
@.str5 = private unnamed_addr constant [14 x i8] c"Run Core ...\0A\00", align 1
@.str6 = private unnamed_addr constant [4 x i8] c"P2:\00", align 1
@.str7 = private unnamed_addr constant [4 x i8] c"%X \00", align 1
@.str8 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@.str9 = private unnamed_addr constant [9 x i8] c"sort.hex\00", align 1
@.str10 = private unnamed_addr constant [22 x i8] c"klee_div_zero_check.c\00", align 1
@.str111 = private unnamed_addr constant [15 x i8] c"divide by zero\00", align 1
@.str212 = private unnamed_addr constant [8 x i8] c"div.err\00", align 1
@.str313 = private unnamed_addr constant [8 x i8] c"IGNORED\00", align 1
@.str14 = private unnamed_addr constant [16 x i8] c"overshift error\00", align 1
@.str25 = private unnamed_addr constant [14 x i8] c"overshift.err\00", align 1
@.str614 = private unnamed_addr constant [13 x i8] c"klee_range.c\00", align 1
@.str17 = private unnamed_addr constant [14 x i8] c"invalid range\00", align 1
@.str28 = private unnamed_addr constant [5 x i8] c"user\00", align 1

; Function Attrs: nounwind uwtable
define i32 @getP(i32 %aRegister) #0 {
  %1 = alloca i32, align 4
  %p = alloca i32, align 4
  store i32 %aRegister, i32* %1, align 4
  store i32 0, i32* %p, align 4, !dbg !286
  %2 = load i32* %1, align 4, !dbg !287
  %3 = icmp eq i32 %2, 128, !dbg !287
  br i1 %3, label %4, label %5, !dbg !287

; <label>:4                                       ; preds = %0
  store i32 0, i32* %p, align 4, !dbg !289
  br label %18, !dbg !291

; <label>:5                                       ; preds = %0
  %6 = load i32* %1, align 4, !dbg !292
  %7 = icmp eq i32 %6, 144, !dbg !292
  br i1 %7, label %8, label %9, !dbg !292

; <label>:8                                       ; preds = %5
  store i32 1, i32* %p, align 4, !dbg !294
  br label %18, !dbg !296

; <label>:9                                       ; preds = %5
  %10 = load i32* %1, align 4, !dbg !297
  %11 = icmp eq i32 %10, 160, !dbg !297
  br i1 %11, label %12, label %13, !dbg !297

; <label>:12                                      ; preds = %9
  store i32 2, i32* %p, align 4, !dbg !299
  br label %18, !dbg !301

; <label>:13                                      ; preds = %9
  %14 = load i32* %1, align 4, !dbg !302
  %15 = icmp eq i32 %14, 176, !dbg !302
  br i1 %15, label %16, label %17, !dbg !302

; <label>:16                                      ; preds = %13
  store i32 3, i32* %p, align 4, !dbg !304
  br label %18, !dbg !306

; <label>:17                                      ; preds = %13
  store i32 -1, i32* %p, align 4, !dbg !307
  br label %18

; <label>:18                                      ; preds = %8, %16, %17, %12, %4
  %19 = load i32* %p, align 4, !dbg !309
  ret i32 %19, !dbg !309
}

; Function Attrs: nounwind readnone
declare void @llvm.dbg.declare(metadata, metadata) #1

; Function Attrs: nounwind uwtable
define i32 @tfx_sfrread(%struct.em8051* %core, i32 %aRegister) #0 {
  %1 = alloca i32, align 4
  %2 = alloca %struct.em8051*, align 8
  %3 = alloca i32, align 4
  %outputbye = alloca i32, align 4
  %p = alloca i32, align 4
  store %struct.em8051* %core, %struct.em8051** %2, align 8
  store i32 %aRegister, i32* %3, align 4
  store i32 -1, i32* %outputbye, align 4, !dbg !310
  %4 = load i32* %3, align 4, !dbg !311
  %5 = icmp eq i32 %4, 128, !dbg !311
  %6 = load i32* %3, align 4, !dbg !311
  %7 = icmp eq i32 %6, 144, !dbg !311
  %or.cond = or i1 %5, %7, !dbg !311
  %8 = load i32* %3, align 4, !dbg !311
  %9 = icmp eq i32 %8, 160, !dbg !311
  %or.cond3 = or i1 %or.cond, %9, !dbg !311
  %10 = load i32* %3, align 4, !dbg !311
  %11 = icmp eq i32 %10, 176, !dbg !311
  %or.cond5 = or i1 %or.cond3, %11, !dbg !311
  %12 = load i32* %3, align 4, !dbg !313
  br i1 %or.cond5, label %13, label %53, !dbg !311

; <label>:13                                      ; preds = %0
  %14 = call i32 @getP(i32 %12), !dbg !313
  store i32 %14, i32* %p, align 4, !dbg !313
  %15 = load i32* %p, align 4, !dbg !315
  %16 = icmp eq i32 %15, -1, !dbg !315
  br i1 %16, label %62, label %17, !dbg !315

; <label>:17                                      ; preds = %13
  %18 = load i32* %p, align 4, !dbg !317
  %19 = sext i32 %18 to i64, !dbg !317
  %20 = load %struct.test** @cur_test, align 8, !dbg !317
  %21 = getelementptr inbounds %struct.test* %20, i32 0, i32 4, !dbg !317
  %22 = getelementptr inbounds [4 x i32]* %21, i32 0, i64 %19, !dbg !317
  %23 = load i32* %22, align 4, !dbg !317
  %24 = load i32* %p, align 4, !dbg !317
  %25 = sext i32 %24 to i64, !dbg !317
  %26 = load %struct.test** @cur_test, align 8, !dbg !317
  %27 = getelementptr inbounds %struct.test* %26, i32 0, i32 3, !dbg !317
  %28 = getelementptr inbounds [4 x i32]* %27, i32 0, i64 %25, !dbg !317
  %29 = load i32* %28, align 4, !dbg !317
  %30 = icmp sge i32 %23, %29, !dbg !317
  br i1 %30, label %62, label %31, !dbg !317

; <label>:31                                      ; preds = %17
  %32 = load i32* %p, align 4, !dbg !319
  %33 = sext i32 %32 to i64, !dbg !319
  %34 = load %struct.test** @cur_test, align 8, !dbg !319
  %35 = getelementptr inbounds %struct.test* %34, i32 0, i32 4, !dbg !319
  %36 = getelementptr inbounds [4 x i32]* %35, i32 0, i64 %33, !dbg !319
  %37 = load i32* %36, align 4, !dbg !319
  %38 = add nsw i32 %37, 1, !dbg !319
  store i32 %38, i32* %36, align 4, !dbg !319
  %39 = sext i32 %37 to i64, !dbg !319
  %40 = load i32* %p, align 4, !dbg !319
  %41 = sext i32 %40 to i64, !dbg !319
  %42 = load %struct.test** @cur_test, align 8, !dbg !319
  %43 = getelementptr inbounds %struct.test* %42, i32 0, i32 2, !dbg !319
  %44 = getelementptr inbounds [4 x i8*]* %43, i32 0, i64 %41, !dbg !319
  %45 = load i8** %44, align 8, !dbg !319
  %46 = getelementptr inbounds i8* %45, i64 %39, !dbg !319
  %47 = load i8* %46, align 1, !dbg !319
  %48 = zext i8 %47 to i32, !dbg !319
  store i32 %48, i32* %outputbye, align 4, !dbg !319
  %49 = load i32* %outputbye, align 4, !dbg !320
  %50 = load i32* %3, align 4, !dbg !320
  %51 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([20 x i8]* @.str, i32 0, i32 0), i32 %49, i32 %50), !dbg !320
  %52 = load i32* %outputbye, align 4, !dbg !321
  store i32 %52, i32* %1, !dbg !321
  br label %63, !dbg !321

; <label>:53                                      ; preds = %0
  %54 = sub nsw i32 %12, 128, !dbg !322
  %55 = sext i32 %54 to i64, !dbg !322
  %56 = load %struct.em8051** %2, align 8, !dbg !322
  %57 = getelementptr inbounds %struct.em8051* %56, i32 0, i32 7, !dbg !322
  %58 = load i8** %57, align 8, !dbg !322
  %59 = getelementptr inbounds i8* %58, i64 %55, !dbg !322
  %60 = load i8* %59, align 1, !dbg !322
  %61 = zext i8 %60 to i32, !dbg !322
  store i32 %61, i32* %1, !dbg !322
  br label %63, !dbg !322

; <label>:62                                      ; preds = %17, %13
  store i32 0, i32* %1, !dbg !323
  br label %63, !dbg !323

; <label>:63                                      ; preds = %62, %53, %31
  %64 = load i32* %1, !dbg !324
  ret i32 %64, !dbg !324
}

declare i32 @printf(i8*, ...) #2

; Function Attrs: nounwind uwtable
define void @tfx_sfrwrite(%struct.em8051* %core, i32 %aRegister) #0 {
  %1 = alloca %struct.em8051*, align 8
  %2 = alloca i32, align 4
  %p = alloca i32, align 4
  store %struct.em8051* %core, %struct.em8051** %1, align 8
  store i32 %aRegister, i32* %2, align 4
  %3 = load i32* %2, align 4, !dbg !325
  %4 = icmp eq i32 %3, 128, !dbg !325
  %5 = load i32* %2, align 4, !dbg !325
  %6 = icmp eq i32 %5, 144, !dbg !325
  %or.cond = or i1 %4, %6, !dbg !325
  %7 = load i32* %2, align 4, !dbg !325
  %8 = icmp eq i32 %7, 160, !dbg !325
  %or.cond3 = or i1 %or.cond, %8, !dbg !325
  %9 = load i32* %2, align 4, !dbg !325
  %10 = icmp eq i32 %9, 176, !dbg !325
  %or.cond5 = or i1 %or.cond3, %10, !dbg !325
  br i1 %or.cond5, label %11, label %65, !dbg !325

; <label>:11                                      ; preds = %0
  %12 = load i32* %2, align 4, !dbg !327
  %13 = call i32 @getP(i32 %12), !dbg !327
  store i32 %13, i32* %p, align 4, !dbg !327
  %14 = load i32* %p, align 4, !dbg !329
  %15 = icmp eq i32 %14, -1, !dbg !329
  br i1 %15, label %65, label %16, !dbg !329

; <label>:16                                      ; preds = %11
  %17 = load i32* %p, align 4, !dbg !331
  %18 = sext i32 %17 to i64, !dbg !331
  %19 = load %struct.test** @cur_test, align 8, !dbg !331
  %20 = getelementptr inbounds %struct.test* %19, i32 0, i32 7, !dbg !331
  %21 = getelementptr inbounds [4 x i32]* %20, i32 0, i64 %18, !dbg !331
  %22 = load i32* %21, align 4, !dbg !331
  %23 = load i32* %p, align 4, !dbg !331
  %24 = sext i32 %23 to i64, !dbg !331
  %25 = load %struct.test** @cur_test, align 8, !dbg !331
  %26 = getelementptr inbounds %struct.test* %25, i32 0, i32 6, !dbg !331
  %27 = getelementptr inbounds [4 x i32]* %26, i32 0, i64 %24, !dbg !331
  %28 = load i32* %27, align 4, !dbg !331
  %29 = icmp sge i32 %22, %28, !dbg !331
  br i1 %29, label %65, label %30, !dbg !331

; <label>:30                                      ; preds = %16
  %31 = load i32* %2, align 4, !dbg !333
  %32 = sub nsw i32 %31, 128, !dbg !333
  %33 = sext i32 %32 to i64, !dbg !333
  %34 = load %struct.em8051** %1, align 8, !dbg !333
  %35 = getelementptr inbounds %struct.em8051* %34, i32 0, i32 7, !dbg !333
  %36 = load i8** %35, align 8, !dbg !333
  %37 = getelementptr inbounds i8* %36, i64 %33, !dbg !333
  %38 = load i8* %37, align 1, !dbg !333
  %39 = load i32* %p, align 4, !dbg !333
  %40 = sext i32 %39 to i64, !dbg !333
  %41 = load %struct.test** @cur_test, align 8, !dbg !333
  %42 = getelementptr inbounds %struct.test* %41, i32 0, i32 7, !dbg !333
  %43 = getelementptr inbounds [4 x i32]* %42, i32 0, i64 %40, !dbg !333
  %44 = load i32* %43, align 4, !dbg !333
  %45 = add nsw i32 %44, 1, !dbg !333
  store i32 %45, i32* %43, align 4, !dbg !333
  %46 = sext i32 %44 to i64, !dbg !333
  %47 = load i32* %p, align 4, !dbg !333
  %48 = sext i32 %47 to i64, !dbg !333
  %49 = load %struct.test** @cur_test, align 8, !dbg !333
  %50 = getelementptr inbounds %struct.test* %49, i32 0, i32 5, !dbg !333
  %51 = getelementptr inbounds [4 x i8*]* %50, i32 0, i64 %48, !dbg !333
  %52 = load i8** %51, align 8, !dbg !333
  %53 = getelementptr inbounds i8* %52, i64 %46, !dbg !333
  store i8 %38, i8* %53, align 1, !dbg !333
  %54 = load i32* %2, align 4, !dbg !334
  %55 = sub nsw i32 %54, 128, !dbg !334
  %56 = sext i32 %55 to i64, !dbg !334
  %57 = load %struct.em8051** %1, align 8, !dbg !334
  %58 = getelementptr inbounds %struct.em8051* %57, i32 0, i32 7, !dbg !334
  %59 = load i8** %58, align 8, !dbg !334
  %60 = getelementptr inbounds i8* %59, i64 %56, !dbg !334
  %61 = load i8* %60, align 1, !dbg !334
  %62 = zext i8 %61 to i32, !dbg !334
  %63 = load i32* %2, align 4, !dbg !334
  %64 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([19 x i8]* @.str1, i32 0, i32 0), i32 %62, i32 %63), !dbg !334
  br label %65, !dbg !335

; <label>:65                                      ; preds = %30, %0, %16, %11
  ret void, !dbg !336
}

; Function Attrs: nounwind uwtable
define void @tfx_exception(%struct.em8051* %core, i32 %err_code) #0 {
  %1 = alloca %struct.em8051*, align 8
  %2 = alloca i32, align 4
  store %struct.em8051* %core, %struct.em8051** %1, align 8
  store i32 %err_code, i32* %2, align 4
  %3 = load i32* %2, align 4, !dbg !337
  ret void, !dbg !338
}

; Function Attrs: nounwind uwtable
define %struct.em8051* @create_core() #0 {
  %core = alloca %struct.em8051*, align 8
  %1 = call noalias i8* @malloc(i64 4240) #4, !dbg !339
  %2 = bitcast i8* %1 to %struct.em8051*, !dbg !339
  store %struct.em8051* %2, %struct.em8051** %core, align 8, !dbg !339
  %3 = load %struct.em8051** %core, align 8, !dbg !340
  %4 = bitcast %struct.em8051* %3 to i8*, !dbg !340
  %5 = call i8* @memset(i8* %4, i32 0, i64 4240)
  %6 = call noalias i8* @malloc(i64 65536) #4, !dbg !341
  %7 = load %struct.em8051** %core, align 8, !dbg !341
  %8 = getelementptr inbounds %struct.em8051* %7, i32 0, i32 0, !dbg !341
  store i8* %6, i8** %8, align 8, !dbg !341
  %9 = load %struct.em8051** %core, align 8, !dbg !342
  %10 = getelementptr inbounds %struct.em8051* %9, i32 0, i32 2, !dbg !342
  store i32 65536, i32* %10, align 4, !dbg !342
  %11 = call noalias i8* @malloc(i64 65536) #4, !dbg !343
  %12 = load %struct.em8051** %core, align 8, !dbg !343
  %13 = getelementptr inbounds %struct.em8051* %12, i32 0, i32 3, !dbg !343
  store i8* %11, i8** %13, align 8, !dbg !343
  %14 = load %struct.em8051** %core, align 8, !dbg !344
  %15 = getelementptr inbounds %struct.em8051* %14, i32 0, i32 4, !dbg !344
  store i32 65536, i32* %15, align 4, !dbg !344
  %16 = call noalias i8* @malloc(i64 128) #4, !dbg !345
  %17 = load %struct.em8051** %core, align 8, !dbg !345
  %18 = getelementptr inbounds %struct.em8051* %17, i32 0, i32 5, !dbg !345
  store i8* %16, i8** %18, align 8, !dbg !345
  %19 = call noalias i8* @malloc(i64 128) #4, !dbg !346
  %20 = load %struct.em8051** %core, align 8, !dbg !346
  %21 = getelementptr inbounds %struct.em8051* %20, i32 0, i32 6, !dbg !346
  store i8* %19, i8** %21, align 8, !dbg !346
  %22 = call noalias i8* @malloc(i64 128) #4, !dbg !347
  %23 = load %struct.em8051** %core, align 8, !dbg !347
  %24 = getelementptr inbounds %struct.em8051* %23, i32 0, i32 7, !dbg !347
  store i8* %22, i8** %24, align 8, !dbg !347
  %25 = load %struct.em8051** %core, align 8, !dbg !348
  %26 = getelementptr inbounds %struct.em8051* %25, i32 0, i32 12, !dbg !348
  store void (%struct.em8051*, i32)* @tfx_exception, void (%struct.em8051*, i32)** %26, align 8, !dbg !348
  %27 = load %struct.em8051** %core, align 8, !dbg !349
  %28 = getelementptr inbounds %struct.em8051* %27, i32 0, i32 13, !dbg !349
  store i32 (%struct.em8051*, i32)* @tfx_sfrread, i32 (%struct.em8051*, i32)** %28, align 8, !dbg !349
  %29 = load %struct.em8051** %core, align 8, !dbg !350
  %30 = getelementptr inbounds %struct.em8051* %29, i32 0, i32 14, !dbg !350
  store void (%struct.em8051*, i32)* @tfx_sfrwrite, void (%struct.em8051*, i32)** %30, align 8, !dbg !350
  %31 = load %struct.em8051** %core, align 8, !dbg !351
  %32 = getelementptr inbounds %struct.em8051* %31, i32 0, i32 15, !dbg !351
  store i32 (%struct.em8051*, i32)* null, i32 (%struct.em8051*, i32)** %32, align 8, !dbg !351
  %33 = load %struct.em8051** %core, align 8, !dbg !352
  %34 = getelementptr inbounds %struct.em8051* %33, i32 0, i32 16, !dbg !352
  store void (%struct.em8051*, i32, i32)* null, void (%struct.em8051*, i32, i32)** %34, align 8, !dbg !352
  %35 = load %struct.em8051** %core, align 8, !dbg !353
  call void @reset(%struct.em8051* %35, i32 1), !dbg !353
  %36 = load %struct.em8051** %core, align 8, !dbg !354
  ret %struct.em8051* %36, !dbg !354
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #3

; Function Attrs: nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture, i8, i64, i32, i1) #4

declare void @reset(%struct.em8051*, i32) #2

; Function Attrs: nounwind uwtable
define void @delete_core(%struct.em8051* %core) #0 {
  %1 = alloca %struct.em8051*, align 8
  store %struct.em8051* %core, %struct.em8051** %1, align 8
  %2 = load %struct.em8051** %1, align 8, !dbg !355
  %3 = icmp ne %struct.em8051* %2, null, !dbg !355
  br i1 %3, label %4, label %59, !dbg !355

; <label>:4                                       ; preds = %0
  %5 = load %struct.em8051** %1, align 8, !dbg !357
  %6 = getelementptr inbounds %struct.em8051* %5, i32 0, i32 0, !dbg !357
  %7 = load i8** %6, align 8, !dbg !357
  %8 = icmp ne i8* %7, null, !dbg !357
  br i1 %8, label %9, label %15, !dbg !357

; <label>:9                                       ; preds = %4
  %10 = load %struct.em8051** %1, align 8, !dbg !360
  %11 = getelementptr inbounds %struct.em8051* %10, i32 0, i32 0, !dbg !360
  %12 = load i8** %11, align 8, !dbg !360
  call void @free(i8* %12) #4, !dbg !360
  %13 = load %struct.em8051** %1, align 8, !dbg !360
  %14 = getelementptr inbounds %struct.em8051* %13, i32 0, i32 0, !dbg !360
  store i8* null, i8** %14, align 8, !dbg !360
  br label %15, !dbg !360

; <label>:15                                      ; preds = %9, %4
  %16 = load %struct.em8051** %1, align 8, !dbg !362
  %17 = getelementptr inbounds %struct.em8051* %16, i32 0, i32 3, !dbg !362
  %18 = load i8** %17, align 8, !dbg !362
  %19 = icmp ne i8* %18, null, !dbg !362
  br i1 %19, label %20, label %26, !dbg !362

; <label>:20                                      ; preds = %15
  %21 = load %struct.em8051** %1, align 8, !dbg !365
  %22 = getelementptr inbounds %struct.em8051* %21, i32 0, i32 3, !dbg !365
  %23 = load i8** %22, align 8, !dbg !365
  call void @free(i8* %23) #4, !dbg !365
  %24 = load %struct.em8051** %1, align 8, !dbg !365
  %25 = getelementptr inbounds %struct.em8051* %24, i32 0, i32 3, !dbg !365
  store i8* null, i8** %25, align 8, !dbg !365
  br label %26, !dbg !365

; <label>:26                                      ; preds = %20, %15
  %27 = load %struct.em8051** %1, align 8, !dbg !367
  %28 = getelementptr inbounds %struct.em8051* %27, i32 0, i32 5, !dbg !367
  %29 = load i8** %28, align 8, !dbg !367
  %30 = icmp ne i8* %29, null, !dbg !367
  br i1 %30, label %31, label %37, !dbg !367

; <label>:31                                      ; preds = %26
  %32 = load %struct.em8051** %1, align 8, !dbg !370
  %33 = getelementptr inbounds %struct.em8051* %32, i32 0, i32 5, !dbg !370
  %34 = load i8** %33, align 8, !dbg !370
  call void @free(i8* %34) #4, !dbg !370
  %35 = load %struct.em8051** %1, align 8, !dbg !370
  %36 = getelementptr inbounds %struct.em8051* %35, i32 0, i32 5, !dbg !370
  store i8* null, i8** %36, align 8, !dbg !370
  br label %37, !dbg !370

; <label>:37                                      ; preds = %31, %26
  %38 = load %struct.em8051** %1, align 8, !dbg !372
  %39 = getelementptr inbounds %struct.em8051* %38, i32 0, i32 6, !dbg !372
  %40 = load i8** %39, align 8, !dbg !372
  %41 = icmp ne i8* %40, null, !dbg !372
  br i1 %41, label %42, label %48, !dbg !372

; <label>:42                                      ; preds = %37
  %43 = load %struct.em8051** %1, align 8, !dbg !375
  %44 = getelementptr inbounds %struct.em8051* %43, i32 0, i32 6, !dbg !375
  %45 = load i8** %44, align 8, !dbg !375
  call void @free(i8* %45) #4, !dbg !375
  %46 = load %struct.em8051** %1, align 8, !dbg !375
  %47 = getelementptr inbounds %struct.em8051* %46, i32 0, i32 6, !dbg !375
  store i8* null, i8** %47, align 8, !dbg !375
  br label %48, !dbg !375

; <label>:48                                      ; preds = %42, %37
  %49 = load %struct.em8051** %1, align 8, !dbg !377
  %50 = getelementptr inbounds %struct.em8051* %49, i32 0, i32 7, !dbg !377
  %51 = load i8** %50, align 8, !dbg !377
  %52 = icmp ne i8* %51, null, !dbg !377
  br i1 %52, label %53, label %59, !dbg !377

; <label>:53                                      ; preds = %48
  %54 = load %struct.em8051** %1, align 8, !dbg !380
  %55 = getelementptr inbounds %struct.em8051* %54, i32 0, i32 7, !dbg !380
  %56 = load i8** %55, align 8, !dbg !380
  call void @free(i8* %56) #4, !dbg !380
  %57 = load %struct.em8051** %1, align 8, !dbg !380
  %58 = getelementptr inbounds %struct.em8051* %57, i32 0, i32 7, !dbg !380
  store i8* null, i8** %58, align 8, !dbg !380
  br label %59, !dbg !380

; <label>:59                                      ; preds = %0, %53, %48
  ret void, !dbg !382
}

; Function Attrs: nounwind
declare void @free(i8*) #3

; Function Attrs: nounwind uwtable
define i32 @run_core() #0 {
  %ticked = alloca i32, align 4
  %targettime = alloca i32, align 4
  %targetclocks = alloca i32, align 4
  %old_pc = alloca i32, align 4
  store i32 1, i32* %ticked, align 4, !dbg !383
  br label %1, !dbg !384

; <label>:1                                       ; preds = %26, %0
  %2 = call i32 (...)* @getTick(), !dbg !385
  %3 = add nsw i32 %2, 10, !dbg !385
  store i32 %3, i32* %targettime, align 4, !dbg !385
  %4 = load i32* @opt_clock_hz, align 4, !dbg !387
  %int_cast_to_i64 = zext i32 1200 to i64
  call void @klee_div_zero_check(i64 %int_cast_to_i64), !dbg !387
  %5 = sdiv i32 %4, 1200, !dbg !387
  store i32 %5, i32* %targetclocks, align 4, !dbg !387
  br label %6, !dbg !388

; <label>:6                                       ; preds = %6, %1
  %7 = load %struct.em8051** @cur_core, align 8, !dbg !389
  %8 = getelementptr inbounds %struct.em8051* %7, i32 0, i32 8, !dbg !389
  %9 = load i32* %8, align 4, !dbg !389
  store i32 %9, i32* %old_pc, align 4, !dbg !389
  %10 = load i32* %targetclocks, align 4, !dbg !391
  %11 = add i32 %10, -1, !dbg !391
  store i32 %11, i32* %targetclocks, align 4, !dbg !391
  %12 = load %struct.em8051** @cur_core, align 8, !dbg !392
  %13 = call i32 @tick(%struct.em8051* %12), !dbg !392
  store i32 %13, i32* %ticked, align 4, !dbg !392
  %14 = load i32* %ticked, align 4, !dbg !393
  %15 = icmp ne i32 %14, 0, !dbg !393
  %16 = load i32* %targettime, align 4, !dbg !395
  %17 = call i32 (...)* @getTick(), !dbg !396
  %18 = icmp sgt i32 %16, %17, !dbg !396
  %19 = load i32* %targetclocks, align 4, !dbg !396
  %20 = icmp ugt i32 %19, 0, !dbg !396
  %or.cond = and i1 %18, %20, !dbg !396
  br i1 %or.cond, label %6, label %.critedge, !dbg !396

.critedge:                                        ; preds = %6, %24
  %21 = load i32* %targettime, align 4, !dbg !397
  %22 = call i32 (...)* @getTick(), !dbg !397
  %23 = icmp sgt i32 %21, %22, !dbg !397
  br i1 %23, label %24, label %26, !dbg !397

; <label>:24                                      ; preds = %.critedge
  %25 = call i32 @core_sleep(i32 1), !dbg !398
  br label %.critedge, !dbg !400

; <label>:26                                      ; preds = %.critedge
  %27 = load %struct.test** @cur_test, align 8, !dbg !401
  %28 = getelementptr inbounds %struct.test* %27, i32 0, i32 7, !dbg !401
  %29 = getelementptr inbounds [4 x i32]* %28, i32 0, i64 2, !dbg !401
  %30 = load i32* %29, align 4, !dbg !401
  %31 = icmp slt i32 %30, 10, !dbg !401
  br i1 %31, label %1, label %32, !dbg !401

; <label>:32                                      ; preds = %26
  ret i32 0, !dbg !402
}

declare i32 @getTick(...) #2

declare i32 @tick(%struct.em8051*) #2

declare i32 @core_sleep(i32) #2

; Function Attrs: nounwind uwtable
define i32 @before() #0 {
  %1 = call %struct.em8051* @create_core(), !dbg !403
  store %struct.em8051* %1, %struct.em8051** @cur_core, align 8, !dbg !403
  ret i32 0, !dbg !404
}

; Function Attrs: nounwind uwtable
define i32 @after() #0 {
  %1 = load %struct.test** @cur_test, align 8, !dbg !405
  %2 = icmp ne %struct.test* %1, null, !dbg !405
  br i1 %2, label %3, label %5, !dbg !405

; <label>:3                                       ; preds = %0
  %4 = load %struct.test** @cur_test, align 8, !dbg !407
  call void @delete_test(%struct.test* %4), !dbg !407
  store %struct.test* null, %struct.test** @cur_test, align 8, !dbg !409
  br label %5, !dbg !410

; <label>:5                                       ; preds = %3, %0
  %6 = load %struct.em8051** @cur_core, align 8, !dbg !411
  %7 = icmp ne %struct.em8051* %6, null, !dbg !411
  br i1 %7, label %8, label %10, !dbg !411

; <label>:8                                       ; preds = %5
  %9 = load %struct.em8051** @cur_core, align 8, !dbg !413
  call void @delete_core(%struct.em8051* %9), !dbg !413
  store %struct.em8051* null, %struct.em8051** @cur_core, align 8, !dbg !415
  br label %10, !dbg !416

; <label>:10                                      ; preds = %8, %5
  %11 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([17 x i8]* @.str2, i32 0, i32 0)), !dbg !417
  ret i32 0, !dbg !418
}

declare void @delete_test(%struct.test*) #2

; Function Attrs: nounwind uwtable
define zeroext i8 @klee_byte(i8* %name) #0 {
  %1 = alloca i8*, align 8
  %x = alloca i8, align 1
  store i8* %name, i8** %1, align 8
  %2 = load i8** %1, align 8, !dbg !419
  %3 = call i32 (i8*, i64, i8*, ...)* bitcast (i32 (...)* @klee_make_symbolic to i32 (i8*, i64, i8*, ...)*)(i8* %x, i64 1, i8* %2), !dbg !419
  %4 = load i8* %x, align 1, !dbg !420
  ret i8 %4, !dbg !420
}

declare i32 @klee_make_symbolic(...) #2

; Function Attrs: nounwind uwtable
define i32 @run_test() #0 {
  %1 = alloca i32, align 4
  %i = alloca i32, align 4
  %n = alloca i32, align 4
  %a = alloca i8*, align 8
  %2 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([14 x i8]* @.str3, i32 0, i32 0)), !dbg !421
  store i32 0, i32* %i, align 4, !dbg !422
  store i32 10, i32* %n, align 4, !dbg !423
  %3 = load i32* %n, align 4, !dbg !424
  %4 = load i32* %n, align 4, !dbg !424
  %5 = call %struct.test* @init_test(i32 %3, i32 %4), !dbg !424
  store %struct.test* %5, %struct.test** @cur_test, align 8, !dbg !424
  %6 = load %struct.test** @cur_test, align 8, !dbg !425
  %7 = icmp ne %struct.test* %6, null, !dbg !425
  br i1 %7, label %9, label %8, !dbg !425

; <label>:8                                       ; preds = %0
  store i32 -1, i32* %1, !dbg !425
  br label %83, !dbg !425

; <label>:9                                       ; preds = %0
  %10 = load i32* %n, align 4, !dbg !427
  %11 = sext i32 %10 to i64, !dbg !427
  %12 = call noalias i8* @malloc(i64 %11) #4, !dbg !427
  store i8* %12, i8** %a, align 8, !dbg !427
  %13 = load i8** %a, align 8, !dbg !428
  %14 = call i32 (i8*, i32, i8*, ...)* bitcast (i32 (...)* @klee_make_symbolic to i32 (i8*, i32, i8*, ...)*)(i8* %13, i32 10, i8* getelementptr inbounds ([3 x i8]* @.str4, i32 0, i32 0)), !dbg !428
  store i32 0, i32* %i, align 4, !dbg !429
  br label %15, !dbg !429

; <label>:15                                      ; preds = %19, %9
  %16 = load i32* %i, align 4, !dbg !429
  %17 = load i32* %n, align 4, !dbg !429
  %18 = icmp slt i32 %16, %17, !dbg !429
  br i1 %18, label %19, label %40, !dbg !429

; <label>:19                                      ; preds = %15
  %20 = load i32* %i, align 4, !dbg !431
  %21 = sext i32 %20 to i64, !dbg !431
  %22 = load i8** %a, align 8, !dbg !431
  %23 = getelementptr inbounds i8* %22, i64 %21, !dbg !431
  %24 = load i8* %23, align 1, !dbg !431
  %25 = zext i8 %24 to i32, !dbg !431
  %26 = icmp sgt i32 %25, 0, !dbg !431
  %27 = zext i1 %26 to i32, !dbg !431
  %28 = call i32 (i32, ...)* bitcast (i32 (...)* @klee_assume to i32 (i32, ...)*)(i32 %27), !dbg !431
  %29 = load i32* %i, align 4, !dbg !433
  %30 = sext i32 %29 to i64, !dbg !433
  %31 = load i8** %a, align 8, !dbg !433
  %32 = getelementptr inbounds i8* %31, i64 %30, !dbg !433
  %33 = load i8* %32, align 1, !dbg !433
  %34 = zext i8 %33 to i32, !dbg !433
  %35 = icmp slt i32 %34, 20, !dbg !433
  %36 = zext i1 %35 to i32, !dbg !433
  %37 = call i32 (i32, ...)* bitcast (i32 (...)* @klee_assume to i32 (i32, ...)*)(i32 %36), !dbg !433
  %38 = load i32* %i, align 4, !dbg !429
  %39 = add nsw i32 %38, 1, !dbg !429
  store i32 %39, i32* %i, align 4, !dbg !429
  br label %15, !dbg !429

; <label>:40                                      ; preds = %15
  store i32 0, i32* %i, align 4, !dbg !434
  br label %41, !dbg !434

; <label>:41                                      ; preds = %45, %40
  %42 = load i32* %i, align 4, !dbg !434
  %43 = load i32* %n, align 4, !dbg !434
  %44 = icmp slt i32 %42, %43, !dbg !434
  br i1 %44, label %45, label %60, !dbg !434

; <label>:45                                      ; preds = %41
  %46 = load i32* %i, align 4, !dbg !436
  %47 = sext i32 %46 to i64, !dbg !436
  %48 = load i8** %a, align 8, !dbg !436
  %49 = getelementptr inbounds i8* %48, i64 %47, !dbg !436
  %50 = load i8* %49, align 1, !dbg !436
  %51 = load i32* %i, align 4, !dbg !436
  %52 = sext i32 %51 to i64, !dbg !436
  %53 = load %struct.test** @cur_test, align 8, !dbg !436
  %54 = getelementptr inbounds %struct.test* %53, i32 0, i32 2, !dbg !436
  %55 = getelementptr inbounds [4 x i8*]* %54, i32 0, i64 0, !dbg !436
  %56 = load i8** %55, align 8, !dbg !436
  %57 = getelementptr inbounds i8* %56, i64 %52, !dbg !436
  store i8 %50, i8* %57, align 1, !dbg !436
  %58 = load i32* %i, align 4, !dbg !434
  %59 = add nsw i32 %58, 1, !dbg !434
  store i32 %59, i32* %i, align 4, !dbg !434
  br label %41, !dbg !434

; <label>:60                                      ; preds = %41
  %61 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([14 x i8]* @.str5, i32 0, i32 0)), !dbg !438
  %62 = call i32 @run_core(), !dbg !439
  %63 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str6, i32 0, i32 0)), !dbg !440
  store i32 0, i32* %i, align 4, !dbg !441
  br label %64, !dbg !441

; <label>:64                                      ; preds = %68, %60
  %65 = load i32* %i, align 4, !dbg !441
  %66 = load i32* %n, align 4, !dbg !441
  %67 = icmp slt i32 %65, %66, !dbg !441
  br i1 %67, label %68, label %81, !dbg !441

; <label>:68                                      ; preds = %64
  %69 = load i32* %i, align 4, !dbg !443
  %70 = sext i32 %69 to i64, !dbg !443
  %71 = load %struct.test** @cur_test, align 8, !dbg !443
  %72 = getelementptr inbounds %struct.test* %71, i32 0, i32 5, !dbg !443
  %73 = getelementptr inbounds [4 x i8*]* %72, i32 0, i64 2, !dbg !443
  %74 = load i8** %73, align 8, !dbg !443
  %75 = getelementptr inbounds i8* %74, i64 %70, !dbg !443
  %76 = load i8* %75, align 1, !dbg !443
  %77 = zext i8 %76 to i32, !dbg !443
  %78 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str7, i32 0, i32 0), i32 %77), !dbg !443
  %79 = load i32* %i, align 4, !dbg !441
  %80 = add nsw i32 %79, 1, !dbg !441
  store i32 %80, i32* %i, align 4, !dbg !441
  br label %64, !dbg !441

; <label>:81                                      ; preds = %64
  %82 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([2 x i8]* @.str8, i32 0, i32 0)), !dbg !445
  store i32 0, i32* %1, !dbg !446
  br label %83, !dbg !446

; <label>:83                                      ; preds = %81, %8
  %84 = load i32* %1, !dbg !447
  ret i32 %84, !dbg !447
}

declare %struct.test* @init_test(i32, i32) #2

declare i32 @klee_assume(...) #2

; Function Attrs: nounwind uwtable
define i32 @main(i32 %argc, i8** %argv) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i8**, align 8
  store i32 0, i32* %1
  store i32 %argc, i32* %2, align 4
  store i8** %argv, i8*** %3, align 8
  %4 = call i32 @before(), !dbg !448
  %5 = load %struct.em8051** @cur_core, align 8, !dbg !449
  %6 = call i32 @load_obj(%struct.em8051* %5, i8* getelementptr inbounds ([9 x i8]* @.str9, i32 0, i32 0)), !dbg !449
  %7 = icmp ne i32 %6, 0, !dbg !449
  br i1 %7, label %8, label %9, !dbg !449

; <label>:8                                       ; preds = %0
  store i32 -1, i32* %1, !dbg !449
  br label %12, !dbg !449

; <label>:9                                       ; preds = %0
  %10 = call i32 @run_test(), !dbg !451
  %11 = call i32 @after(), !dbg !452
  store i32 0, i32* %1, !dbg !453
  br label %12, !dbg !453

; <label>:12                                      ; preds = %9, %8
  %13 = load i32* %1, !dbg !454
  ret i32 %13, !dbg !454
}

declare i32 @load_obj(%struct.em8051*, i8*) #2

; Function Attrs: nounwind ssp uwtable
define void @klee_div_zero_check(i64 %z) #5 {
  %1 = icmp eq i64 %z, 0, !dbg !455
  br i1 %1, label %2, label %3, !dbg !455

; <label>:2                                       ; preds = %0
  tail call void @klee_report_error(i8* getelementptr inbounds ([22 x i8]* @.str10, i64 0, i64 0), i32 14, i8* getelementptr inbounds ([15 x i8]* @.str111, i64 0, i64 0), i8* getelementptr inbounds ([8 x i8]* @.str212, i64 0, i64 0)) #7, !dbg !457
  unreachable, !dbg !457

; <label>:3                                       ; preds = %0
  ret void, !dbg !458
}

; Function Attrs: noreturn
declare void @klee_report_error(i8*, i32, i8*, i8*) #6

; Function Attrs: nounwind readnone
declare void @llvm.dbg.value(metadata, i64, metadata) #1

; Function Attrs: nounwind ssp uwtable
define i32 @klee_int(i8* %name) #5 {
  %x = alloca i32, align 4
  %1 = bitcast i32* %x to i8*, !dbg !459
  call void bitcast (i32 (...)* @klee_make_symbolic to void (i8*, i64, i8*)*)(i8* %1, i64 4, i8* %name) #8, !dbg !459
  %2 = load i32* %x, align 4, !dbg !460, !tbaa !461
  ret i32 %2, !dbg !460
}

; Function Attrs: nounwind ssp uwtable
define void @klee_overshift_check(i64 %bitWidth, i64 %shift) #5 {
  %1 = icmp ult i64 %shift, %bitWidth, !dbg !465
  br i1 %1, label %3, label %2, !dbg !465

; <label>:2                                       ; preds = %0
  tail call void @klee_report_error(i8* getelementptr inbounds ([8 x i8]* @.str313, i64 0, i64 0), i32 0, i8* getelementptr inbounds ([16 x i8]* @.str14, i64 0, i64 0), i8* getelementptr inbounds ([14 x i8]* @.str25, i64 0, i64 0)) #7, !dbg !467
  unreachable, !dbg !467

; <label>:3                                       ; preds = %0
  ret void, !dbg !469
}

; Function Attrs: nounwind ssp uwtable
define i32 @klee_range(i32 %start, i32 %end, i8* %name) #5 {
  %x = alloca i32, align 4
  %1 = icmp slt i32 %start, %end, !dbg !470
  br i1 %1, label %3, label %2, !dbg !470

; <label>:2                                       ; preds = %0
  call void @klee_report_error(i8* getelementptr inbounds ([13 x i8]* @.str614, i64 0, i64 0), i32 17, i8* getelementptr inbounds ([14 x i8]* @.str17, i64 0, i64 0), i8* getelementptr inbounds ([5 x i8]* @.str28, i64 0, i64 0)) #7, !dbg !472
  unreachable, !dbg !472

; <label>:3                                       ; preds = %0
  %4 = add nsw i32 %start, 1, !dbg !473
  %5 = icmp eq i32 %4, %end, !dbg !473
  br i1 %5, label %21, label %6, !dbg !473

; <label>:6                                       ; preds = %3
  %7 = bitcast i32* %x to i8*, !dbg !475
  call void bitcast (i32 (...)* @klee_make_symbolic to void (i8*, i64, i8*)*)(i8* %7, i64 4, i8* %name) #8, !dbg !475
  %8 = icmp eq i32 %start, 0, !dbg !477
  %9 = load i32* %x, align 4, !dbg !479, !tbaa !461
  br i1 %8, label %10, label %13, !dbg !477

; <label>:10                                      ; preds = %6
  %11 = icmp ult i32 %9, %end, !dbg !479
  %12 = zext i1 %11 to i64, !dbg !479
  call void bitcast (i32 (...)* @klee_assume to void (i64)*)(i64 %12) #8, !dbg !479
  br label %19, !dbg !481

; <label>:13                                      ; preds = %6
  %14 = icmp sge i32 %9, %start, !dbg !482
  %15 = zext i1 %14 to i64, !dbg !482
  call void bitcast (i32 (...)* @klee_assume to void (i64)*)(i64 %15) #8, !dbg !482
  %16 = load i32* %x, align 4, !dbg !484, !tbaa !461
  %17 = icmp slt i32 %16, %end, !dbg !484
  %18 = zext i1 %17 to i64, !dbg !484
  call void bitcast (i32 (...)* @klee_assume to void (i64)*)(i64 %18) #8, !dbg !484
  br label %19

; <label>:19                                      ; preds = %13, %10
  %20 = load i32* %x, align 4, !dbg !485, !tbaa !461
  br label %21, !dbg !485

; <label>:21                                      ; preds = %19, %3
  %.0 = phi i32 [ %20, %19 ], [ %start, %3 ]
  ret i32 %.0, !dbg !486
}

; Function Attrs: nounwind ssp uwtable
define weak i8* @memcpy(i8* %destaddr, i8* %srcaddr, i64 %len) #5 {
  %1 = icmp eq i64 %len, 0, !dbg !487
  br i1 %1, label %._crit_edge, label %.lr.ph.preheader, !dbg !487

.lr.ph.preheader:                                 ; preds = %0
  %n.vec = and i64 %len, -32
  %cmp.zero = icmp eq i64 %n.vec, 0
  %2 = add i64 %len, -1
  br i1 %cmp.zero, label %middle.block, label %vector.memcheck

vector.memcheck:                                  ; preds = %.lr.ph.preheader
  %scevgep4 = getelementptr i8* %srcaddr, i64 %2
  %scevgep = getelementptr i8* %destaddr, i64 %2
  %bound1 = icmp uge i8* %scevgep, %srcaddr
  %bound0 = icmp uge i8* %scevgep4, %destaddr
  %memcheck.conflict = and i1 %bound0, %bound1
  %ptr.ind.end = getelementptr i8* %srcaddr, i64 %n.vec
  %ptr.ind.end6 = getelementptr i8* %destaddr, i64 %n.vec
  %rev.ind.end = sub i64 %len, %n.vec
  br i1 %memcheck.conflict, label %middle.block, label %vector.body

vector.body:                                      ; preds = %vector.body, %vector.memcheck
  %index = phi i64 [ %index.next, %vector.body ], [ 0, %vector.memcheck ]
  %next.gep = getelementptr i8* %srcaddr, i64 %index
  %next.gep103 = getelementptr i8* %destaddr, i64 %index
  %3 = bitcast i8* %next.gep to <16 x i8>*, !dbg !488
  %wide.load = load <16 x i8>* %3, align 1, !dbg !488
  %next.gep.sum279 = or i64 %index, 16, !dbg !488
  %4 = getelementptr i8* %srcaddr, i64 %next.gep.sum279, !dbg !488
  %5 = bitcast i8* %4 to <16 x i8>*, !dbg !488
  %wide.load200 = load <16 x i8>* %5, align 1, !dbg !488
  %6 = bitcast i8* %next.gep103 to <16 x i8>*, !dbg !488
  store <16 x i8> %wide.load, <16 x i8>* %6, align 1, !dbg !488
  %7 = getelementptr i8* %destaddr, i64 %next.gep.sum279, !dbg !488
  %8 = bitcast i8* %7 to <16 x i8>*, !dbg !488
  store <16 x i8> %wide.load200, <16 x i8>* %8, align 1, !dbg !488
  %index.next = add i64 %index, 32
  %9 = icmp eq i64 %index.next, %n.vec
  br i1 %9, label %middle.block, label %vector.body, !llvm.loop !489

middle.block:                                     ; preds = %vector.body, %vector.memcheck, %.lr.ph.preheader
  %resume.val = phi i8* [ %srcaddr, %.lr.ph.preheader ], [ %srcaddr, %vector.memcheck ], [ %ptr.ind.end, %vector.body ]
  %resume.val5 = phi i8* [ %destaddr, %.lr.ph.preheader ], [ %destaddr, %vector.memcheck ], [ %ptr.ind.end6, %vector.body ]
  %resume.val7 = phi i64 [ %len, %.lr.ph.preheader ], [ %len, %vector.memcheck ], [ %rev.ind.end, %vector.body ]
  %new.indc.resume.val = phi i64 [ 0, %.lr.ph.preheader ], [ 0, %vector.memcheck ], [ %n.vec, %vector.body ]
  %cmp.n = icmp eq i64 %new.indc.resume.val, %len
  br i1 %cmp.n, label %._crit_edge, label %.lr.ph

.lr.ph:                                           ; preds = %.lr.ph, %middle.block
  %src.03 = phi i8* [ %11, %.lr.ph ], [ %resume.val, %middle.block ]
  %dest.02 = phi i8* [ %13, %.lr.ph ], [ %resume.val5, %middle.block ]
  %.01 = phi i64 [ %10, %.lr.ph ], [ %resume.val7, %middle.block ]
  %10 = add i64 %.01, -1, !dbg !487
  %11 = getelementptr inbounds i8* %src.03, i64 1, !dbg !488
  %12 = load i8* %src.03, align 1, !dbg !488, !tbaa !492
  %13 = getelementptr inbounds i8* %dest.02, i64 1, !dbg !488
  store i8 %12, i8* %dest.02, align 1, !dbg !488, !tbaa !492
  %14 = icmp eq i64 %10, 0, !dbg !487
  br i1 %14, label %._crit_edge, label %.lr.ph, !dbg !487, !llvm.loop !493

._crit_edge:                                      ; preds = %.lr.ph, %middle.block, %0
  ret i8* %destaddr, !dbg !494
}

; Function Attrs: nounwind ssp uwtable
define weak i8* @memmove(i8* %dst, i8* %src, i64 %count) #5 {
  %1 = icmp eq i8* %src, %dst, !dbg !495
  br i1 %1, label %.loopexit, label %2, !dbg !495

; <label>:2                                       ; preds = %0
  %3 = icmp ugt i8* %src, %dst, !dbg !497
  br i1 %3, label %.preheader, label %18, !dbg !497

.preheader:                                       ; preds = %2
  %4 = icmp eq i64 %count, 0, !dbg !499
  br i1 %4, label %.loopexit, label %.lr.ph.preheader, !dbg !499

.lr.ph.preheader:                                 ; preds = %.preheader
  %n.vec = and i64 %count, -32
  %cmp.zero = icmp eq i64 %n.vec, 0
  %5 = add i64 %count, -1
  br i1 %cmp.zero, label %middle.block, label %vector.memcheck

vector.memcheck:                                  ; preds = %.lr.ph.preheader
  %scevgep11 = getelementptr i8* %src, i64 %5
  %scevgep = getelementptr i8* %dst, i64 %5
  %bound1 = icmp uge i8* %scevgep, %src
  %bound0 = icmp uge i8* %scevgep11, %dst
  %memcheck.conflict = and i1 %bound0, %bound1
  %ptr.ind.end = getelementptr i8* %src, i64 %n.vec
  %ptr.ind.end13 = getelementptr i8* %dst, i64 %n.vec
  %rev.ind.end = sub i64 %count, %n.vec
  br i1 %memcheck.conflict, label %middle.block, label %vector.body

vector.body:                                      ; preds = %vector.body, %vector.memcheck
  %index = phi i64 [ %index.next, %vector.body ], [ 0, %vector.memcheck ]
  %next.gep = getelementptr i8* %src, i64 %index
  %next.gep110 = getelementptr i8* %dst, i64 %index
  %6 = bitcast i8* %next.gep to <16 x i8>*, !dbg !499
  %wide.load = load <16 x i8>* %6, align 1, !dbg !499
  %next.gep.sum586 = or i64 %index, 16, !dbg !499
  %7 = getelementptr i8* %src, i64 %next.gep.sum586, !dbg !499
  %8 = bitcast i8* %7 to <16 x i8>*, !dbg !499
  %wide.load207 = load <16 x i8>* %8, align 1, !dbg !499
  %9 = bitcast i8* %next.gep110 to <16 x i8>*, !dbg !499
  store <16 x i8> %wide.load, <16 x i8>* %9, align 1, !dbg !499
  %10 = getelementptr i8* %dst, i64 %next.gep.sum586, !dbg !499
  %11 = bitcast i8* %10 to <16 x i8>*, !dbg !499
  store <16 x i8> %wide.load207, <16 x i8>* %11, align 1, !dbg !499
  %index.next = add i64 %index, 32
  %12 = icmp eq i64 %index.next, %n.vec
  br i1 %12, label %middle.block, label %vector.body, !llvm.loop !501

middle.block:                                     ; preds = %vector.body, %vector.memcheck, %.lr.ph.preheader
  %resume.val = phi i8* [ %src, %.lr.ph.preheader ], [ %src, %vector.memcheck ], [ %ptr.ind.end, %vector.body ]
  %resume.val12 = phi i8* [ %dst, %.lr.ph.preheader ], [ %dst, %vector.memcheck ], [ %ptr.ind.end13, %vector.body ]
  %resume.val14 = phi i64 [ %count, %.lr.ph.preheader ], [ %count, %vector.memcheck ], [ %rev.ind.end, %vector.body ]
  %new.indc.resume.val = phi i64 [ 0, %.lr.ph.preheader ], [ 0, %vector.memcheck ], [ %n.vec, %vector.body ]
  %cmp.n = icmp eq i64 %new.indc.resume.val, %count
  br i1 %cmp.n, label %.loopexit, label %.lr.ph

.lr.ph:                                           ; preds = %.lr.ph, %middle.block
  %b.04 = phi i8* [ %14, %.lr.ph ], [ %resume.val, %middle.block ]
  %a.03 = phi i8* [ %16, %.lr.ph ], [ %resume.val12, %middle.block ]
  %.02 = phi i64 [ %13, %.lr.ph ], [ %resume.val14, %middle.block ]
  %13 = add i64 %.02, -1, !dbg !499
  %14 = getelementptr inbounds i8* %b.04, i64 1, !dbg !499
  %15 = load i8* %b.04, align 1, !dbg !499, !tbaa !492
  %16 = getelementptr inbounds i8* %a.03, i64 1, !dbg !499
  store i8 %15, i8* %a.03, align 1, !dbg !499, !tbaa !492
  %17 = icmp eq i64 %13, 0, !dbg !499
  br i1 %17, label %.loopexit, label %.lr.ph, !dbg !499, !llvm.loop !502

; <label>:18                                      ; preds = %2
  %19 = add i64 %count, -1, !dbg !503
  %20 = icmp eq i64 %count, 0, !dbg !505
  br i1 %20, label %.loopexit, label %.lr.ph9, !dbg !505

.lr.ph9:                                          ; preds = %18
  %21 = getelementptr inbounds i8* %src, i64 %19, !dbg !506
  %22 = getelementptr inbounds i8* %dst, i64 %19, !dbg !503
  %n.vec215 = and i64 %count, -32
  %cmp.zero217 = icmp eq i64 %n.vec215, 0
  br i1 %cmp.zero217, label %middle.block210, label %vector.memcheck224

vector.memcheck224:                               ; preds = %.lr.ph9
  %bound1221 = icmp ule i8* %21, %dst
  %bound0220 = icmp ule i8* %22, %src
  %memcheck.conflict223 = and i1 %bound0220, %bound1221
  %.sum = sub i64 %19, %n.vec215
  %rev.ptr.ind.end = getelementptr i8* %src, i64 %.sum
  %rev.ptr.ind.end229 = getelementptr i8* %dst, i64 %.sum
  %rev.ind.end231 = sub i64 %count, %n.vec215
  br i1 %memcheck.conflict223, label %middle.block210, label %vector.body209

vector.body209:                                   ; preds = %vector.body209, %vector.memcheck224
  %index212 = phi i64 [ %index.next234, %vector.body209 ], [ 0, %vector.memcheck224 ]
  %.sum440 = sub i64 %19, %index212
  %next.gep236.sum = add i64 %.sum440, -15, !dbg !505
  %23 = getelementptr i8* %src, i64 %next.gep236.sum, !dbg !505
  %24 = bitcast i8* %23 to <16 x i8>*, !dbg !505
  %wide.load434 = load <16 x i8>* %24, align 1, !dbg !505
  %reverse = shufflevector <16 x i8> %wide.load434, <16 x i8> undef, <16 x i32> <i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8, i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>, !dbg !505
  %.sum505 = add i64 %.sum440, -31, !dbg !505
  %25 = getelementptr i8* %src, i64 %.sum505, !dbg !505
  %26 = bitcast i8* %25 to <16 x i8>*, !dbg !505
  %wide.load435 = load <16 x i8>* %26, align 1, !dbg !505
  %reverse436 = shufflevector <16 x i8> %wide.load435, <16 x i8> undef, <16 x i32> <i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8, i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>, !dbg !505
  %reverse437 = shufflevector <16 x i8> %reverse, <16 x i8> undef, <16 x i32> <i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8, i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>, !dbg !505
  %27 = getelementptr i8* %dst, i64 %next.gep236.sum, !dbg !505
  %28 = bitcast i8* %27 to <16 x i8>*, !dbg !505
  store <16 x i8> %reverse437, <16 x i8>* %28, align 1, !dbg !505
  %reverse438 = shufflevector <16 x i8> %reverse436, <16 x i8> undef, <16 x i32> <i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8, i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>, !dbg !505
  %29 = getelementptr i8* %dst, i64 %.sum505, !dbg !505
  %30 = bitcast i8* %29 to <16 x i8>*, !dbg !505
  store <16 x i8> %reverse438, <16 x i8>* %30, align 1, !dbg !505
  %index.next234 = add i64 %index212, 32
  %31 = icmp eq i64 %index.next234, %n.vec215
  br i1 %31, label %middle.block210, label %vector.body209, !llvm.loop !507

middle.block210:                                  ; preds = %vector.body209, %vector.memcheck224, %.lr.ph9
  %resume.val225 = phi i8* [ %21, %.lr.ph9 ], [ %21, %vector.memcheck224 ], [ %rev.ptr.ind.end, %vector.body209 ]
  %resume.val227 = phi i8* [ %22, %.lr.ph9 ], [ %22, %vector.memcheck224 ], [ %rev.ptr.ind.end229, %vector.body209 ]
  %resume.val230 = phi i64 [ %count, %.lr.ph9 ], [ %count, %vector.memcheck224 ], [ %rev.ind.end231, %vector.body209 ]
  %new.indc.resume.val232 = phi i64 [ 0, %.lr.ph9 ], [ 0, %vector.memcheck224 ], [ %n.vec215, %vector.body209 ]
  %cmp.n233 = icmp eq i64 %new.indc.resume.val232, %count
  br i1 %cmp.n233, label %.loopexit, label %scalar.ph211

scalar.ph211:                                     ; preds = %scalar.ph211, %middle.block210
  %b.18 = phi i8* [ %33, %scalar.ph211 ], [ %resume.val225, %middle.block210 ]
  %a.17 = phi i8* [ %35, %scalar.ph211 ], [ %resume.val227, %middle.block210 ]
  %.16 = phi i64 [ %32, %scalar.ph211 ], [ %resume.val230, %middle.block210 ]
  %32 = add i64 %.16, -1, !dbg !505
  %33 = getelementptr inbounds i8* %b.18, i64 -1, !dbg !505
  %34 = load i8* %b.18, align 1, !dbg !505, !tbaa !492
  %35 = getelementptr inbounds i8* %a.17, i64 -1, !dbg !505
  store i8 %34, i8* %a.17, align 1, !dbg !505, !tbaa !492
  %36 = icmp eq i64 %32, 0, !dbg !505
  br i1 %36, label %.loopexit, label %scalar.ph211, !dbg !505, !llvm.loop !508

.loopexit:                                        ; preds = %scalar.ph211, %middle.block210, %18, %.lr.ph, %middle.block, %.preheader, %0
  ret i8* %dst, !dbg !509
}

; Function Attrs: nounwind ssp uwtable
define weak i8* @mempcpy(i8* %destaddr, i8* %srcaddr, i64 %len) #5 {
  %1 = icmp eq i64 %len, 0, !dbg !510
  br i1 %1, label %15, label %.lr.ph.preheader, !dbg !510

.lr.ph.preheader:                                 ; preds = %0
  %n.vec = and i64 %len, -32
  %cmp.zero = icmp eq i64 %n.vec, 0
  %2 = add i64 %len, -1
  br i1 %cmp.zero, label %middle.block, label %vector.memcheck

vector.memcheck:                                  ; preds = %.lr.ph.preheader
  %scevgep5 = getelementptr i8* %srcaddr, i64 %2
  %scevgep4 = getelementptr i8* %destaddr, i64 %2
  %bound1 = icmp uge i8* %scevgep4, %srcaddr
  %bound0 = icmp uge i8* %scevgep5, %destaddr
  %memcheck.conflict = and i1 %bound0, %bound1
  %ptr.ind.end = getelementptr i8* %srcaddr, i64 %n.vec
  %ptr.ind.end7 = getelementptr i8* %destaddr, i64 %n.vec
  %rev.ind.end = sub i64 %len, %n.vec
  br i1 %memcheck.conflict, label %middle.block, label %vector.body

vector.body:                                      ; preds = %vector.body, %vector.memcheck
  %index = phi i64 [ %index.next, %vector.body ], [ 0, %vector.memcheck ]
  %next.gep = getelementptr i8* %srcaddr, i64 %index
  %next.gep104 = getelementptr i8* %destaddr, i64 %index
  %3 = bitcast i8* %next.gep to <16 x i8>*, !dbg !511
  %wide.load = load <16 x i8>* %3, align 1, !dbg !511
  %next.gep.sum280 = or i64 %index, 16, !dbg !511
  %4 = getelementptr i8* %srcaddr, i64 %next.gep.sum280, !dbg !511
  %5 = bitcast i8* %4 to <16 x i8>*, !dbg !511
  %wide.load201 = load <16 x i8>* %5, align 1, !dbg !511
  %6 = bitcast i8* %next.gep104 to <16 x i8>*, !dbg !511
  store <16 x i8> %wide.load, <16 x i8>* %6, align 1, !dbg !511
  %7 = getelementptr i8* %destaddr, i64 %next.gep.sum280, !dbg !511
  %8 = bitcast i8* %7 to <16 x i8>*, !dbg !511
  store <16 x i8> %wide.load201, <16 x i8>* %8, align 1, !dbg !511
  %index.next = add i64 %index, 32
  %9 = icmp eq i64 %index.next, %n.vec
  br i1 %9, label %middle.block, label %vector.body, !llvm.loop !512

middle.block:                                     ; preds = %vector.body, %vector.memcheck, %.lr.ph.preheader
  %resume.val = phi i8* [ %srcaddr, %.lr.ph.preheader ], [ %srcaddr, %vector.memcheck ], [ %ptr.ind.end, %vector.body ]
  %resume.val6 = phi i8* [ %destaddr, %.lr.ph.preheader ], [ %destaddr, %vector.memcheck ], [ %ptr.ind.end7, %vector.body ]
  %resume.val8 = phi i64 [ %len, %.lr.ph.preheader ], [ %len, %vector.memcheck ], [ %rev.ind.end, %vector.body ]
  %new.indc.resume.val = phi i64 [ 0, %.lr.ph.preheader ], [ 0, %vector.memcheck ], [ %n.vec, %vector.body ]
  %cmp.n = icmp eq i64 %new.indc.resume.val, %len
  br i1 %cmp.n, label %._crit_edge, label %.lr.ph

.lr.ph:                                           ; preds = %.lr.ph, %middle.block
  %src.03 = phi i8* [ %11, %.lr.ph ], [ %resume.val, %middle.block ]
  %dest.02 = phi i8* [ %13, %.lr.ph ], [ %resume.val6, %middle.block ]
  %.01 = phi i64 [ %10, %.lr.ph ], [ %resume.val8, %middle.block ]
  %10 = add i64 %.01, -1, !dbg !510
  %11 = getelementptr inbounds i8* %src.03, i64 1, !dbg !511
  %12 = load i8* %src.03, align 1, !dbg !511, !tbaa !492
  %13 = getelementptr inbounds i8* %dest.02, i64 1, !dbg !511
  store i8 %12, i8* %dest.02, align 1, !dbg !511, !tbaa !492
  %14 = icmp eq i64 %10, 0, !dbg !510
  br i1 %14, label %._crit_edge, label %.lr.ph, !dbg !510, !llvm.loop !513

._crit_edge:                                      ; preds = %.lr.ph, %middle.block
  %scevgep = getelementptr i8* %destaddr, i64 %len
  br label %15, !dbg !510

; <label>:15                                      ; preds = %._crit_edge, %0
  %dest.0.lcssa = phi i8* [ %scevgep, %._crit_edge ], [ %destaddr, %0 ]
  ret i8* %dest.0.lcssa, !dbg !514
}

; Function Attrs: nounwind ssp uwtable
define weak i8* @memset(i8* %dst, i32 %s, i64 %count) #5 {
  %1 = icmp eq i64 %count, 0, !dbg !515
  br i1 %1, label %._crit_edge, label %.lr.ph, !dbg !515

.lr.ph:                                           ; preds = %0
  %2 = trunc i32 %s to i8, !dbg !516
  br label %3, !dbg !515

; <label>:3                                       ; preds = %3, %.lr.ph
  %a.02 = phi i8* [ %dst, %.lr.ph ], [ %5, %3 ]
  %.01 = phi i64 [ %count, %.lr.ph ], [ %4, %3 ]
  %4 = add i64 %.01, -1, !dbg !515
  %5 = getelementptr inbounds i8* %a.02, i64 1, !dbg !516
  store volatile i8 %2, i8* %a.02, align 1, !dbg !516, !tbaa !492
  %6 = icmp eq i64 %4, 0, !dbg !515
  br i1 %6, label %._crit_edge, label %3, !dbg !515

._crit_edge:                                      ; preds = %3, %0
  ret i8* %dst, !dbg !517
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float
attributes #1 = { nounwind readnone }
attributes #2 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false
attributes #4 = { nounwind }
attributes #5 = { nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="4" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #6 = { noreturn "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="4" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #7 = { nobuiltin noreturn nounwind }
attributes #8 = { nobuiltin nounwind }

!llvm.dbg.cu = !{!0, !170, !181, !192, !204, !217, !236, !251, !266}
!llvm.module.flags = !{!282, !283}
!llvm.ident = !{!284, !285, !285, !285, !285, !285, !285, !285, !285}

!0 = metadata !{i32 786449, metadata !1, i32 12, metadata !"Ubuntu clang version 3.4.2- (branches/release_34) (based on LLVM 3.4.2)", i1 false, metadata !"", i32 0, metadata !2, metadata !32, metadata !33, metadata !128, metadata !32, metadata !""} ; [ D
!1 = metadata !{metadata !"demo_tfx_10_klee.c", metadata !"/home/tonyxu/Downloads/TFX8051"}
!2 = metadata !{metadata !3, metadata !9}
!3 = metadata !{i32 786436, metadata !4, null, metadata !"test_status", i32 46, i64 32, i64 32, i32 0, i32 0, null, metadata !5, i32 0, null, null, null} ; [ DW_TAG_enumeration_type ] [test_status] [line 46, size 32, align 32, offset 0] [def] [from ]
!4 = metadata !{metadata !"./tfx_test.h", metadata !"/home/tonyxu/Downloads/TFX8051"}
!5 = metadata !{metadata !6, metadata !7, metadata !8}
!6 = metadata !{i32 786472, metadata !"NOTEXE", i64 0} ; [ DW_TAG_enumerator ] [NOTEXE :: 0]
!7 = metadata !{i32 786472, metadata !"SUCCESS", i64 1} ; [ DW_TAG_enumerator ] [SUCCESS :: 1]
!8 = metadata !{i32 786472, metadata !"FAIL", i64 2} ; [ DW_TAG_enumerator ] [FAIL :: 2]
!9 = metadata !{i32 786436, metadata !10, null, metadata !"SFR_REGS", i32 120, i64 32, i64 32, i32 0, i32 0, null, metadata !11, i32 0, null, null, null} ; [ DW_TAG_enumeration_type ] [SFR_REGS] [line 120, size 32, align 32, offset 0] [def] [from ]
!10 = metadata !{metadata !"./emu8051.h", metadata !"/home/tonyxu/Downloads/TFX8051"}
!11 = metadata !{metadata !12, metadata !13, metadata !14, metadata !15, metadata !16, metadata !17, metadata !18, metadata !19, metadata !20, metadata !21, metadata !22, metadata !23, metadata !24, metadata !25, metadata !26, metadata !27, metadata !28,
!12 = metadata !{i32 786472, metadata !"REG_ACC", i64 96} ; [ DW_TAG_enumerator ] [REG_ACC :: 96]
!13 = metadata !{i32 786472, metadata !"REG_B", i64 112} ; [ DW_TAG_enumerator ] [REG_B :: 112]
!14 = metadata !{i32 786472, metadata !"REG_PSW", i64 80} ; [ DW_TAG_enumerator ] [REG_PSW :: 80]
!15 = metadata !{i32 786472, metadata !"REG_SP", i64 1} ; [ DW_TAG_enumerator ] [REG_SP :: 1]
!16 = metadata !{i32 786472, metadata !"REG_DPL", i64 2} ; [ DW_TAG_enumerator ] [REG_DPL :: 2]
!17 = metadata !{i32 786472, metadata !"REG_DPH", i64 3} ; [ DW_TAG_enumerator ] [REG_DPH :: 3]
!18 = metadata !{i32 786472, metadata !"REG_P0", i64 0} ; [ DW_TAG_enumerator ] [REG_P0 :: 0]
!19 = metadata !{i32 786472, metadata !"REG_P1", i64 16} ; [ DW_TAG_enumerator ] [REG_P1 :: 16]
!20 = metadata !{i32 786472, metadata !"REG_P2", i64 32} ; [ DW_TAG_enumerator ] [REG_P2 :: 32]
!21 = metadata !{i32 786472, metadata !"REG_P3", i64 48} ; [ DW_TAG_enumerator ] [REG_P3 :: 48]
!22 = metadata !{i32 786472, metadata !"REG_IP", i64 56} ; [ DW_TAG_enumerator ] [REG_IP :: 56]
!23 = metadata !{i32 786472, metadata !"REG_IE", i64 40} ; [ DW_TAG_enumerator ] [REG_IE :: 40]
!24 = metadata !{i32 786472, metadata !"REG_TMOD", i64 9} ; [ DW_TAG_enumerator ] [REG_TMOD :: 9]
!25 = metadata !{i32 786472, metadata !"REG_TCON", i64 8} ; [ DW_TAG_enumerator ] [REG_TCON :: 8]
!26 = metadata !{i32 786472, metadata !"REG_TH0", i64 12} ; [ DW_TAG_enumerator ] [REG_TH0 :: 12]
!27 = metadata !{i32 786472, metadata !"REG_TL0", i64 10} ; [ DW_TAG_enumerator ] [REG_TL0 :: 10]
!28 = metadata !{i32 786472, metadata !"REG_TH1", i64 13} ; [ DW_TAG_enumerator ] [REG_TH1 :: 13]
!29 = metadata !{i32 786472, metadata !"REG_TL1", i64 11} ; [ DW_TAG_enumerator ] [REG_TL1 :: 11]
!30 = metadata !{i32 786472, metadata !"REG_SCON", i64 24} ; [ DW_TAG_enumerator ] [REG_SCON :: 24]
!31 = metadata !{i32 786472, metadata !"REG_PCON", i64 7} ; [ DW_TAG_enumerator ] [REG_PCON :: 7]
!32 = metadata !{i32 0}
!33 = metadata !{metadata !34, metadata !39, metadata !102, metadata !105, metadata !106, metadata !109, metadata !112, metadata !115, metadata !116, metadata !117, metadata !123, metadata !124}
!34 = metadata !{i32 786478, metadata !1, metadata !35, metadata !"getP", metadata !"getP", metadata !"", i32 45, metadata !36, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, i32 (i32)* @getP, null, null, metadata !32, i32 45} ; [ DW_TAG_subpr
!35 = metadata !{i32 786473, metadata !1}         ; [ DW_TAG_file_type ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!36 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !37, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!37 = metadata !{metadata !38, metadata !38}
!38 = metadata !{i32 786468, null, null, metadata !"int", i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ] [int] [line 0, size 32, align 32, offset 0, enc DW_ATE_signed]
!39 = metadata !{i32 786478, metadata !1, metadata !35, metadata !"tfx_sfrread", metadata !"tfx_sfrread", metadata !"", i32 63, metadata !40, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, i32 (%struct.em8051*, i32)* @tfx_sfrread, null, null, 
!40 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !41, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!41 = metadata !{metadata !38, metadata !42, metadata !38}
!42 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !43} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from core_8051]
!43 = metadata !{i32 786454, metadata !1, null, metadata !"core_8051", i32 62, i64 0, i64 0, i64 0, i32 0, metadata !44} ; [ DW_TAG_typedef ] [core_8051] [line 62, size 0, align 0, offset 0] [from em8051]
!44 = metadata !{i32 786451, metadata !10, null, metadata !"em8051", i32 63, i64 33920, i64 64, i32 0, i32 0, null, metadata !45, i32 0, null, null, null} ; [ DW_TAG_structure_type ] [em8051] [line 63, size 33920, align 64, offset 0] [def] [from ]
!45 = metadata !{metadata !46, metadata !49, metadata !51, metadata !52, metadata !53, metadata !54, metadata !55, metadata !56, metadata !57, metadata !58, metadata !59, metadata !68, metadata !76, metadata !81, metadata !86, metadata !88, metadata !90,
!46 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"mCodeMem", i32 65, i64 64, i64 64, i64 0, i32 0, metadata !47} ; [ DW_TAG_member ] [mCodeMem] [line 65, size 64, align 64, offset 0] [from ]
!47 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !48} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from unsigned char]
!48 = metadata !{i32 786468, null, null, metadata !"unsigned char", i32 0, i64 8, i64 8, i64 0, i32 0, i32 8} ; [ DW_TAG_base_type ] [unsigned char] [line 0, size 8, align 8, offset 0, enc DW_ATE_unsigned_char]
!49 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"mCodeCov", i32 66, i64 64, i64 64, i64 64, i32 0, metadata !50} ; [ DW_TAG_member ] [mCodeCov] [line 66, size 64, align 64, offset 64] [from ]
!50 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !38} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from int]
!51 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"mCodeMemSize", i32 67, i64 32, i64 32, i64 128, i32 0, metadata !38} ; [ DW_TAG_member ] [mCodeMemSize] [line 67, size 32, align 32, offset 128] [from int]
!52 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"mExtData", i32 68, i64 64, i64 64, i64 192, i32 0, metadata !47} ; [ DW_TAG_member ] [mExtData] [line 68, size 64, align 64, offset 192] [from ]
!53 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"mExtDataSize", i32 69, i64 32, i64 32, i64 256, i32 0, metadata !38} ; [ DW_TAG_member ] [mExtDataSize] [line 69, size 32, align 32, offset 256] [from int]
!54 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"mLowerData", i32 70, i64 64, i64 64, i64 320, i32 0, metadata !47} ; [ DW_TAG_member ] [mLowerData] [line 70, size 64, align 64, offset 320] [from ]
!55 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"mUpperData", i32 71, i64 64, i64 64, i64 384, i32 0, metadata !47} ; [ DW_TAG_member ] [mUpperData] [line 71, size 64, align 64, offset 384] [from ]
!56 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"mSFR", i32 72, i64 64, i64 64, i64 448, i32 0, metadata !47} ; [ DW_TAG_member ] [mSFR] [line 72, size 64, align 64, offset 448] [from ]
!57 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"mPC", i32 73, i64 32, i64 32, i64 512, i32 0, metadata !38} ; [ DW_TAG_member ] [mPC] [line 73, size 32, align 32, offset 512] [from int]
!58 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"mTickDelay", i32 74, i64 32, i64 32, i64 544, i32 0, metadata !38} ; [ DW_TAG_member ] [mTickDelay] [line 74, size 32, align 32, offset 544] [from int]
!59 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"op", i32 75, i64 16384, i64 64, i64 576, i32 0, metadata !60} ; [ DW_TAG_member ] [op] [line 75, size 16384, align 64, offset 576] [from ]
!60 = metadata !{i32 786433, null, null, metadata !"", i32 0, i64 16384, i64 64, i32 0, i32 0, metadata !61, metadata !66, i32 0, null, null, null} ; [ DW_TAG_array_type ] [line 0, size 16384, align 64, offset 0] [from em8051operation]
!61 = metadata !{i32 786454, metadata !10, null, metadata !"em8051operation", i32 35, i64 0, i64 0, i64 0, i32 0, metadata !62} ; [ DW_TAG_typedef ] [em8051operation] [line 35, size 0, align 0, offset 0] [from ]
!62 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !63} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from ]
!63 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !64, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!64 = metadata !{metadata !38, metadata !65}
!65 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !44} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from em8051]
!66 = metadata !{metadata !67}
!67 = metadata !{i32 786465, i64 0, i64 256}      ; [ DW_TAG_subrange_type ] [0, 255]
!68 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"dec", i32 76, i64 16384, i64 64, i64 16960, i32 0, metadata !69} ; [ DW_TAG_member ] [dec] [line 76, size 16384, align 64, offset 16960] [from ]
!69 = metadata !{i32 786433, null, null, metadata !"", i32 0, i64 16384, i64 64, i32 0, i32 0, metadata !70, metadata !66, i32 0, null, null, null} ; [ DW_TAG_array_type ] [line 0, size 16384, align 64, offset 0] [from em8051decoder]
!70 = metadata !{i32 786454, metadata !10, null, metadata !"em8051decoder", i32 39, i64 0, i64 0, i64 0, i32 0, metadata !71} ; [ DW_TAG_typedef ] [em8051decoder] [line 39, size 0, align 0, offset 0] [from ]
!71 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !72} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from ]
!72 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !73, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!73 = metadata !{metadata !38, metadata !65, metadata !38, metadata !74}
!74 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !75} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from char]
!75 = metadata !{i32 786468, null, null, metadata !"char", i32 0, i64 8, i64 8, i64 0, i32 0, i32 6} ; [ DW_TAG_base_type ] [char] [line 0, size 8, align 8, offset 0, enc DW_ATE_signed_char]
!76 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"except", i32 77, i64 64, i64 64, i64 33344, i32 0, metadata !77} ; [ DW_TAG_member ] [except] [line 77, size 64, align 64, offset 33344] [from em8051exception]
!77 = metadata !{i32 786454, metadata !10, null, metadata !"em8051exception", i32 42, i64 0, i64 0, i64 0, i32 0, metadata !78} ; [ DW_TAG_typedef ] [em8051exception] [line 42, size 0, align 0, offset 0] [from ]
!78 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !79} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from ]
!79 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !80, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!80 = metadata !{null, metadata !65, metadata !38}
!81 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"sfrread", i32 78, i64 64, i64 64, i64 33408, i32 0, metadata !82} ; [ DW_TAG_member ] [sfrread] [line 78, size 64, align 64, offset 33408] [from em8051sfrread]
!82 = metadata !{i32 786454, metadata !10, null, metadata !"em8051sfrread", i32 46, i64 0, i64 0, i64 0, i32 0, metadata !83} ; [ DW_TAG_typedef ] [em8051sfrread] [line 46, size 0, align 0, offset 0] [from ]
!83 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !84} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from ]
!84 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !85, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!85 = metadata !{metadata !38, metadata !65, metadata !38}
!86 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"sfrwrite", i32 79, i64 64, i64 64, i64 33472, i32 0, metadata !87} ; [ DW_TAG_member ] [sfrwrite] [line 79, size 64, align 64, offset 33472] [from em8051sfrwrite]
!87 = metadata !{i32 786454, metadata !10, null, metadata !"em8051sfrwrite", i32 50, i64 0, i64 0, i64 0, i32 0, metadata !78} ; [ DW_TAG_typedef ] [em8051sfrwrite] [line 50, size 0, align 0, offset 0] [from ]
!88 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"xread", i32 80, i64 64, i64 64, i64 33536, i32 0, metadata !89} ; [ DW_TAG_member ] [xread] [line 80, size 64, align 64, offset 33536] [from em8051xread]
!89 = metadata !{i32 786454, metadata !10, null, metadata !"em8051xread", i32 60, i64 0, i64 0, i64 0, i32 0, metadata !83} ; [ DW_TAG_typedef ] [em8051xread] [line 60, size 0, align 0, offset 0] [from ]
!90 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"xwrite", i32 81, i64 64, i64 64, i64 33600, i32 0, metadata !91} ; [ DW_TAG_member ] [xwrite] [line 81, size 64, align 64, offset 33600] [from em8051xwrite]
!91 = metadata !{i32 786454, metadata !10, null, metadata !"em8051xwrite", i32 55, i64 0, i64 0, i64 0, i32 0, metadata !92} ; [ DW_TAG_typedef ] [em8051xwrite] [line 55, size 0, align 0, offset 0] [from ]
!92 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !93} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from ]
!93 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !94, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!94 = metadata !{null, metadata !65, metadata !38, metadata !38}
!95 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"mInterruptActive", i32 84, i64 32, i64 32, i64 33664, i32 0, metadata !38} ; [ DW_TAG_member ] [mInterruptActive] [line 84, size 32, align 32, offset 33664] [from int]
!96 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"int_a", i32 86, i64 64, i64 32, i64 33696, i32 0, metadata !97} ; [ DW_TAG_member ] [int_a] [line 86, size 64, align 32, offset 33696] [from ]
!97 = metadata !{i32 786433, null, null, metadata !"", i32 0, i64 64, i64 32, i32 0, i32 0, metadata !38, metadata !98, i32 0, null, null, null} ; [ DW_TAG_array_type ] [line 0, size 64, align 32, offset 0] [from int]
!98 = metadata !{metadata !99}
!99 = metadata !{i32 786465, i64 0, i64 2}        ; [ DW_TAG_subrange_type ] [0, 1]
!100 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"int_psw", i32 87, i64 64, i64 32, i64 33760, i32 0, metadata !97} ; [ DW_TAG_member ] [int_psw] [line 87, size 64, align 32, offset 33760] [from ]
!101 = metadata !{i32 786445, metadata !10, metadata !44, metadata !"int_sp", i32 88, i64 64, i64 32, i64 33824, i32 0, metadata !97} ; [ DW_TAG_member ] [int_sp] [line 88, size 64, align 32, offset 33824] [from ]
!102 = metadata !{i32 786478, metadata !1, metadata !35, metadata !"tfx_sfrwrite", metadata !"tfx_sfrwrite", metadata !"", i32 90, metadata !103, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, void (%struct.em8051*, i32)* @tfx_sfrwrite, null, 
!103 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !104, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!104 = metadata !{null, metadata !42, metadata !38}
!105 = metadata !{i32 786478, metadata !1, metadata !35, metadata !"tfx_exception", metadata !"tfx_exception", metadata !"", i32 112, metadata !103, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, void (%struct.em8051*, i32)* @tfx_exception, nu
!106 = metadata !{i32 786478, metadata !1, metadata !35, metadata !"create_core", metadata !"create_core", metadata !"", i32 139, metadata !107, i1 false, i1 true, i32 0, i32 0, null, i32 0, i1 false, %struct.em8051* ()* @create_core, null, null, metadat
!107 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !108, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!108 = metadata !{metadata !42}
!109 = metadata !{i32 786478, metadata !1, metadata !35, metadata !"delete_core", metadata !"delete_core", metadata !"", i32 167, metadata !110, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, void (%struct.em8051*)* @delete_core, null, null, m
!110 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !111, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!111 = metadata !{null, metadata !42}
!112 = metadata !{i32 786478, metadata !1, metadata !35, metadata !"run_core", metadata !"run_core", metadata !"", i32 180, metadata !113, i1 false, i1 true, i32 0, i32 0, null, i32 0, i1 false, i32 ()* @run_core, null, null, metadata !32, i32 180} ; [ D
!113 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !114, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!114 = metadata !{metadata !38}
!115 = metadata !{i32 786478, metadata !1, metadata !35, metadata !"before", metadata !"before", metadata !"", i32 218, metadata !113, i1 false, i1 true, i32 0, i32 0, null, i32 0, i1 false, i32 ()* @before, null, null, metadata !32, i32 218} ; [ DW_TAG_
!116 = metadata !{i32 786478, metadata !1, metadata !35, metadata !"after", metadata !"after", metadata !"", i32 223, metadata !113, i1 false, i1 true, i32 0, i32 0, null, i32 0, i1 false, i32 ()* @after, null, null, metadata !32, i32 223} ; [ DW_TAG_sub
!117 = metadata !{i32 786478, metadata !1, metadata !35, metadata !"klee_byte", metadata !"klee_byte", metadata !"", i32 239, metadata !118, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, i8 (i8*)* @klee_byte, null, null, metadata !32, i32 239
!118 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !119, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!119 = metadata !{metadata !120, metadata !121}
!120 = metadata !{i32 786454, metadata !4, null, metadata !"byte", i32 33, i64 0, i64 0, i64 0, i32 0, metadata !48} ; [ DW_TAG_typedef ] [byte] [line 33, size 0, align 0, offset 0] [from unsigned char]
!121 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !122} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from ]
!122 = metadata !{i32 786470, null, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, metadata !75} ; [ DW_TAG_const_type ] [line 0, size 0, align 0, offset 0] [from char]
!123 = metadata !{i32 786478, metadata !1, metadata !35, metadata !"run_test", metadata !"run_test", metadata !"", i32 245, metadata !113, i1 false, i1 true, i32 0, i32 0, null, i32 0, i1 false, i32 ()* @run_test, null, null, metadata !32, i32 245} ; [ D
!124 = metadata !{i32 786478, metadata !1, metadata !35, metadata !"main", metadata !"main", metadata !"", i32 305, metadata !125, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, i32 (i32, i8**)* @main, null, null, metadata !32, i32 305} ; [ DW
!125 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !126, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!126 = metadata !{metadata !38, metadata !38, metadata !127}
!127 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !74} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from ]
!128 = metadata !{metadata !129, metadata !130, metadata !131, metadata !132, metadata !133, metadata !134, metadata !135, metadata !136, metadata !137, metadata !138, metadata !139, metadata !143, metadata !169}
!129 = metadata !{i32 786484, i32 0, null, metadata !"opt_exception_iret_sp", metadata !"opt_exception_iret_sp", metadata !"", metadata !35, i32 9, metadata !38, i32 0, i32 1, i32* @opt_exception_iret_sp, null} ; [ DW_TAG_variable ] [opt_exception_iret_s
!130 = metadata !{i32 786484, i32 0, null, metadata !"opt_exception_iret_acc", metadata !"opt_exception_iret_acc", metadata !"", metadata !35, i32 10, metadata !38, i32 0, i32 1, i32* @opt_exception_iret_acc, null} ; [ DW_TAG_variable ] [opt_exception_ir
!131 = metadata !{i32 786484, i32 0, null, metadata !"opt_exception_iret_psw", metadata !"opt_exception_iret_psw", metadata !"", metadata !35, i32 11, metadata !38, i32 0, i32 1, i32* @opt_exception_iret_psw, null} ; [ DW_TAG_variable ] [opt_exception_ir
!132 = metadata !{i32 786484, i32 0, null, metadata !"opt_exception_acc_to_a", metadata !"opt_exception_acc_to_a", metadata !"", metadata !35, i32 12, metadata !38, i32 0, i32 1, i32* @opt_exception_acc_to_a, null} ; [ DW_TAG_variable ] [opt_exception_ac
!133 = metadata !{i32 786484, i32 0, null, metadata !"opt_exception_stack", metadata !"opt_exception_stack", metadata !"", metadata !35, i32 13, metadata !38, i32 0, i32 1, i32* @opt_exception_stack, null} ; [ DW_TAG_variable ] [opt_exception_stack] [lin
!134 = metadata !{i32 786484, i32 0, null, metadata !"opt_exception_invalid", metadata !"opt_exception_invalid", metadata !"", metadata !35, i32 14, metadata !38, i32 0, i32 1, i32* @opt_exception_invalid, null} ; [ DW_TAG_variable ] [opt_exception_inval
!135 = metadata !{i32 786484, i32 0, null, metadata !"opt_input_outputlow", metadata !"opt_input_outputlow", metadata !"", metadata !35, i32 15, metadata !38, i32 0, i32 1, i32* @opt_input_outputlow, null} ; [ DW_TAG_variable ] [opt_input_outputlow] [lin
!136 = metadata !{i32 786484, i32 0, null, metadata !"opt_clock_select", metadata !"opt_clock_select", metadata !"", metadata !35, i32 16, metadata !38, i32 0, i32 1, i32* @opt_clock_select, null} ; [ DW_TAG_variable ] [opt_clock_select] [line 16] [def]
!137 = metadata !{i32 786484, i32 0, null, metadata !"opt_clock_hz", metadata !"opt_clock_hz", metadata !"", metadata !35, i32 17, metadata !38, i32 0, i32 1, i32* @opt_clock_hz, null} ; [ DW_TAG_variable ] [opt_clock_hz] [line 17] [def]
!138 = metadata !{i32 786484, i32 0, null, metadata !"opt_step_instruction", metadata !"opt_step_instruction", metadata !"", metadata !35, i32 18, metadata !38, i32 0, i32 1, i32* @opt_step_instruction, null} ; [ DW_TAG_variable ] [opt_step_instruction] 
!139 = metadata !{i32 786484, i32 0, null, metadata !"clockspeeds", metadata !"clockspeeds", metadata !"", metadata !35, i32 20, metadata !140, i32 0, i32 1, [12 x i32]* @clockspeeds, null} ; [ DW_TAG_variable ] [clockspeeds] [line 20] [def]
!140 = metadata !{i32 786433, null, null, metadata !"", i32 0, i64 384, i64 32, i32 0, i32 0, metadata !38, metadata !141, i32 0, null, null, null} ; [ DW_TAG_array_type ] [line 0, size 384, align 32, offset 0] [from int]
!141 = metadata !{metadata !142}
!142 = metadata !{i32 786465, i64 0, i64 12}      ; [ DW_TAG_subrange_type ] [0, 11]
!143 = metadata !{i32 786484, i32 0, null, metadata !"cur_test", metadata !"cur_test", metadata !"", metadata !35, i32 36, metadata !144, i32 0, i32 1, %struct.test** @cur_test, null} ; [ DW_TAG_variable ] [cur_test] [line 36] [def]
!144 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !145} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from test]
!145 = metadata !{i32 786454, metadata !1, null, metadata !"test", i32 52, i64 0, i64 0, i64 0, i32 0, metadata !146} ; [ DW_TAG_typedef ] [test] [line 52, size 0, align 0, offset 0] [from test]
!146 = metadata !{i32 786451, metadata !4, null, metadata !"test", i32 53, i64 2176, i64 64, i32 0, i32 0, null, metadata !147, i32 0, null, null, null} ; [ DW_TAG_structure_type ] [test] [line 53, size 2176, align 64, offset 0] [def] [from ]
!147 = metadata !{metadata !148, metadata !152, metadata !153, metadata !158, metadata !160, metadata !161, metadata !162, metadata !163, metadata !164, metadata !165, metadata !166, metadata !167}
!148 = metadata !{i32 786445, metadata !4, metadata !146, metadata !"name", i32 55, i64 512, i64 8, i64 0, i32 0, metadata !149} ; [ DW_TAG_member ] [name] [line 55, size 512, align 8, offset 0] [from ]
!149 = metadata !{i32 786433, null, null, metadata !"", i32 0, i64 512, i64 8, i32 0, i32 0, metadata !75, metadata !150, i32 0, null, null, null} ; [ DW_TAG_array_type ] [line 0, size 512, align 8, offset 0] [from char]
!150 = metadata !{metadata !151}
!151 = metadata !{i32 786465, i64 0, i64 64}      ; [ DW_TAG_subrange_type ] [0, 63]
!152 = metadata !{i32 786445, metadata !4, metadata !146, metadata !"aCPU", i32 56, i64 64, i64 64, i64 512, i32 0, metadata !65} ; [ DW_TAG_member ] [aCPU] [line 56, size 64, align 64, offset 512] [from ]
!153 = metadata !{i32 786445, metadata !4, metadata !146, metadata !"in", i32 58, i64 256, i64 64, i64 576, i32 0, metadata !154} ; [ DW_TAG_member ] [in] [line 58, size 256, align 64, offset 576] [from ]
!154 = metadata !{i32 786433, null, null, metadata !"", i32 0, i64 256, i64 64, i32 0, i32 0, metadata !155, metadata !156, i32 0, null, null, null} ; [ DW_TAG_array_type ] [line 0, size 256, align 64, offset 0] [from ]
!155 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !120} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from byte]
!156 = metadata !{metadata !157}
!157 = metadata !{i32 786465, i64 0, i64 4}       ; [ DW_TAG_subrange_type ] [0, 3]
!158 = metadata !{i32 786445, metadata !4, metadata !146, metadata !"in_size", i32 59, i64 128, i64 32, i64 832, i32 0, metadata !159} ; [ DW_TAG_member ] [in_size] [line 59, size 128, align 32, offset 832] [from ]
!159 = metadata !{i32 786433, null, null, metadata !"", i32 0, i64 128, i64 32, i32 0, i32 0, metadata !38, metadata !156, i32 0, null, null, null} ; [ DW_TAG_array_type ] [line 0, size 128, align 32, offset 0] [from int]
!160 = metadata !{i32 786445, metadata !4, metadata !146, metadata !"in_cur_loc", i32 60, i64 128, i64 32, i64 960, i32 0, metadata !159} ; [ DW_TAG_member ] [in_cur_loc] [line 60, size 128, align 32, offset 960] [from ]
!161 = metadata !{i32 786445, metadata !4, metadata !146, metadata !"out", i32 63, i64 256, i64 64, i64 1088, i32 0, metadata !154} ; [ DW_TAG_member ] [out] [line 63, size 256, align 64, offset 1088] [from ]
!162 = metadata !{i32 786445, metadata !4, metadata !146, metadata !"out_size", i32 64, i64 128, i64 32, i64 1344, i32 0, metadata !159} ; [ DW_TAG_member ] [out_size] [line 64, size 128, align 32, offset 1344] [from ]
!163 = metadata !{i32 786445, metadata !4, metadata !146, metadata !"out_cur_loc", i32 65, i64 128, i64 32, i64 1472, i32 0, metadata !159} ; [ DW_TAG_member ] [out_cur_loc] [line 65, size 128, align 32, offset 1472] [from ]
!164 = metadata !{i32 786445, metadata !4, metadata !146, metadata !"expect", i32 68, i64 256, i64 64, i64 1600, i32 0, metadata !154} ; [ DW_TAG_member ] [expect] [line 68, size 256, align 64, offset 1600] [from ]
!165 = metadata !{i32 786445, metadata !4, metadata !146, metadata !"expect_size", i32 69, i64 128, i64 32, i64 1856, i32 0, metadata !159} ; [ DW_TAG_member ] [expect_size] [line 69, size 128, align 32, offset 1856] [from ]
!166 = metadata !{i32 786445, metadata !4, metadata !146, metadata !"expect_cur_loc", i32 70, i64 128, i64 32, i64 1984, i32 0, metadata !159} ; [ DW_TAG_member ] [expect_cur_loc] [line 70, size 128, align 32, offset 1984] [from ]
!167 = metadata !{i32 786445, metadata !4, metadata !146, metadata !"status", i32 73, i64 32, i64 32, i64 2112, i32 0, metadata !168} ; [ DW_TAG_member ] [status] [line 73, size 32, align 32, offset 2112] [from test_status]
!168 = metadata !{i32 786454, metadata !4, null, metadata !"test_status", i32 45, i64 0, i64 0, i64 0, i32 0, metadata !3} ; [ DW_TAG_typedef ] [test_status] [line 45, size 0, align 0, offset 0] [from test_status]
!169 = metadata !{i32 786484, i32 0, null, metadata !"cur_core", metadata !"cur_core", metadata !"", metadata !35, i32 37, metadata !42, i32 0, i32 1, %struct.em8051** @cur_core, null} ; [ DW_TAG_variable ] [cur_core] [line 37] [def]
!170 = metadata !{i32 786449, metadata !171, i32 1, metadata !"Ubuntu clang version 3.4.2-3ubuntu2~xedgers (tags/RELEASE_34/dot2-final) (based on LLVM 3.4.2)", i1 true, metadata !"", i32 0, metadata !32, metadata !32, metadata !172, metadata !32, metadat
!171 = metadata !{metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic/klee_div_zero_check.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!172 = metadata !{metadata !173}
!173 = metadata !{i32 786478, metadata !174, metadata !175, metadata !"klee_div_zero_check", metadata !"klee_div_zero_check", metadata !"", i32 12, metadata !176, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 true, void (i64)* @klee_div_zero_check, 
!174 = metadata !{metadata !"klee_div_zero_check.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!175 = metadata !{i32 786473, metadata !174}      ; [ DW_TAG_file_type ] [/home/tonyxu/Project/klee/runtime/Intrinsic/klee_div_zero_check.c]
!176 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !177, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!177 = metadata !{null, metadata !178}
!178 = metadata !{i32 786468, null, null, metadata !"long long int", i32 0, i64 64, i64 64, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ] [long long int] [line 0, size 64, align 64, offset 0, enc DW_ATE_signed]
!179 = metadata !{metadata !180}
!180 = metadata !{i32 786689, metadata !173, metadata !"z", metadata !175, i32 16777228, metadata !178, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [z] [line 12]
!181 = metadata !{i32 786449, metadata !182, i32 1, metadata !"Ubuntu clang version 3.4.2-3ubuntu2~xedgers (tags/RELEASE_34/dot2-final) (based on LLVM 3.4.2)", i1 true, metadata !"", i32 0, metadata !32, metadata !32, metadata !183, metadata !32, metadat
!182 = metadata !{metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic/klee_int.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!183 = metadata !{metadata !184}
!184 = metadata !{i32 786478, metadata !185, metadata !186, metadata !"klee_int", metadata !"klee_int", metadata !"", i32 13, metadata !187, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 true, i32 (i8*)* @klee_int, null, null, metadata !189, i32 13}
!185 = metadata !{metadata !"klee_int.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!186 = metadata !{i32 786473, metadata !185}      ; [ DW_TAG_file_type ] [/home/tonyxu/Project/klee/runtime/Intrinsic/klee_int.c]
!187 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !188, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!188 = metadata !{metadata !38, metadata !121}
!189 = metadata !{metadata !190, metadata !191}
!190 = metadata !{i32 786689, metadata !184, metadata !"name", metadata !186, i32 16777229, metadata !121, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [name] [line 13]
!191 = metadata !{i32 786688, metadata !184, metadata !"x", metadata !186, i32 14, metadata !38, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [x] [line 14]
!192 = metadata !{i32 786449, metadata !193, i32 1, metadata !"Ubuntu clang version 3.4.2-3ubuntu2~xedgers (tags/RELEASE_34/dot2-final) (based on LLVM 3.4.2)", i1 true, metadata !"", i32 0, metadata !32, metadata !32, metadata !194, metadata !32, metadat
!193 = metadata !{metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic/klee_overshift_check.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!194 = metadata !{metadata !195}
!195 = metadata !{i32 786478, metadata !196, metadata !197, metadata !"klee_overshift_check", metadata !"klee_overshift_check", metadata !"", i32 20, metadata !198, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 true, void (i64, i64)* @klee_overshift
!196 = metadata !{metadata !"klee_overshift_check.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!197 = metadata !{i32 786473, metadata !196}      ; [ DW_TAG_file_type ] [/home/tonyxu/Project/klee/runtime/Intrinsic/klee_overshift_check.c]
!198 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !199, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!199 = metadata !{null, metadata !200, metadata !200}
!200 = metadata !{i32 786468, null, null, metadata !"long long unsigned int", i32 0, i64 64, i64 64, i64 0, i32 0, i32 7} ; [ DW_TAG_base_type ] [long long unsigned int] [line 0, size 64, align 64, offset 0, enc DW_ATE_unsigned]
!201 = metadata !{metadata !202, metadata !203}
!202 = metadata !{i32 786689, metadata !195, metadata !"bitWidth", metadata !197, i32 16777236, metadata !200, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [bitWidth] [line 20]
!203 = metadata !{i32 786689, metadata !195, metadata !"shift", metadata !197, i32 33554452, metadata !200, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [shift] [line 20]
!204 = metadata !{i32 786449, metadata !205, i32 1, metadata !"Ubuntu clang version 3.4.2-3ubuntu2~xedgers (tags/RELEASE_34/dot2-final) (based on LLVM 3.4.2)", i1 true, metadata !"", i32 0, metadata !32, metadata !32, metadata !206, metadata !32, metadat
!205 = metadata !{metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic/klee_range.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!206 = metadata !{metadata !207}
!207 = metadata !{i32 786478, metadata !208, metadata !209, metadata !"klee_range", metadata !"klee_range", metadata !"", i32 13, metadata !210, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 true, i32 (i32, i32, i8*)* @klee_range, null, null, metada
!208 = metadata !{metadata !"klee_range.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!209 = metadata !{i32 786473, metadata !208}      ; [ DW_TAG_file_type ] [/home/tonyxu/Project/klee/runtime/Intrinsic/klee_range.c]
!210 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !211, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!211 = metadata !{metadata !38, metadata !38, metadata !38, metadata !121}
!212 = metadata !{metadata !213, metadata !214, metadata !215, metadata !216}
!213 = metadata !{i32 786689, metadata !207, metadata !"start", metadata !209, i32 16777229, metadata !38, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [start] [line 13]
!214 = metadata !{i32 786689, metadata !207, metadata !"end", metadata !209, i32 33554445, metadata !38, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [end] [line 13]
!215 = metadata !{i32 786689, metadata !207, metadata !"name", metadata !209, i32 50331661, metadata !121, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [name] [line 13]
!216 = metadata !{i32 786688, metadata !207, metadata !"x", metadata !209, i32 14, metadata !38, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [x] [line 14]
!217 = metadata !{i32 786449, metadata !218, i32 1, metadata !"Ubuntu clang version 3.4.2-3ubuntu2~xedgers (tags/RELEASE_34/dot2-final) (based on LLVM 3.4.2)", i1 true, metadata !"", i32 0, metadata !32, metadata !32, metadata !219, metadata !32, metadat
!218 = metadata !{metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic/memcpy.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!219 = metadata !{metadata !220}
!220 = metadata !{i32 786478, metadata !221, metadata !222, metadata !"memcpy", metadata !"memcpy", metadata !"", i32 12, metadata !223, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 true, i8* (i8*, i8*, i64)* @memcpy, null, null, metadata !230, i32
!221 = metadata !{metadata !"memcpy.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!222 = metadata !{i32 786473, metadata !221}      ; [ DW_TAG_file_type ] [/home/tonyxu/Project/klee/runtime/Intrinsic/memcpy.c]
!223 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !224, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!224 = metadata !{metadata !225, metadata !225, metadata !226, metadata !228}
!225 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, null} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from ]
!226 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !227} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from ]
!227 = metadata !{i32 786470, null, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null} ; [ DW_TAG_const_type ] [line 0, size 0, align 0, offset 0] [from ]
!228 = metadata !{i32 786454, metadata !221, null, metadata !"size_t", i32 42, i64 0, i64 0, i64 0, i32 0, metadata !229} ; [ DW_TAG_typedef ] [size_t] [line 42, size 0, align 0, offset 0] [from long unsigned int]
!229 = metadata !{i32 786468, null, null, metadata !"long unsigned int", i32 0, i64 64, i64 64, i64 0, i32 0, i32 7} ; [ DW_TAG_base_type ] [long unsigned int] [line 0, size 64, align 64, offset 0, enc DW_ATE_unsigned]
!230 = metadata !{metadata !231, metadata !232, metadata !233, metadata !234, metadata !235}
!231 = metadata !{i32 786689, metadata !220, metadata !"destaddr", metadata !222, i32 16777228, metadata !225, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [destaddr] [line 12]
!232 = metadata !{i32 786689, metadata !220, metadata !"srcaddr", metadata !222, i32 33554444, metadata !226, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [srcaddr] [line 12]
!233 = metadata !{i32 786689, metadata !220, metadata !"len", metadata !222, i32 50331660, metadata !228, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [len] [line 12]
!234 = metadata !{i32 786688, metadata !220, metadata !"dest", metadata !222, i32 13, metadata !74, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [dest] [line 13]
!235 = metadata !{i32 786688, metadata !220, metadata !"src", metadata !222, i32 14, metadata !121, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [src] [line 14]
!236 = metadata !{i32 786449, metadata !237, i32 1, metadata !"Ubuntu clang version 3.4.2-3ubuntu2~xedgers (tags/RELEASE_34/dot2-final) (based on LLVM 3.4.2)", i1 true, metadata !"", i32 0, metadata !32, metadata !32, metadata !238, metadata !32, metadat
!237 = metadata !{metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic/memmove.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!238 = metadata !{metadata !239}
!239 = metadata !{i32 786478, metadata !240, metadata !241, metadata !"memmove", metadata !"memmove", metadata !"", i32 12, metadata !242, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 true, i8* (i8*, i8*, i64)* @memmove, null, null, metadata !245, 
!240 = metadata !{metadata !"memmove.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!241 = metadata !{i32 786473, metadata !240}      ; [ DW_TAG_file_type ] [/home/tonyxu/Project/klee/runtime/Intrinsic/memmove.c]
!242 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !243, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!243 = metadata !{metadata !225, metadata !225, metadata !226, metadata !244}
!244 = metadata !{i32 786454, metadata !240, null, metadata !"size_t", i32 42, i64 0, i64 0, i64 0, i32 0, metadata !229} ; [ DW_TAG_typedef ] [size_t] [line 42, size 0, align 0, offset 0] [from long unsigned int]
!245 = metadata !{metadata !246, metadata !247, metadata !248, metadata !249, metadata !250}
!246 = metadata !{i32 786689, metadata !239, metadata !"dst", metadata !241, i32 16777228, metadata !225, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [dst] [line 12]
!247 = metadata !{i32 786689, metadata !239, metadata !"src", metadata !241, i32 33554444, metadata !226, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [src] [line 12]
!248 = metadata !{i32 786689, metadata !239, metadata !"count", metadata !241, i32 50331660, metadata !244, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [count] [line 12]
!249 = metadata !{i32 786688, metadata !239, metadata !"a", metadata !241, i32 13, metadata !74, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [a] [line 13]
!250 = metadata !{i32 786688, metadata !239, metadata !"b", metadata !241, i32 14, metadata !121, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [b] [line 14]
!251 = metadata !{i32 786449, metadata !252, i32 1, metadata !"Ubuntu clang version 3.4.2-3ubuntu2~xedgers (tags/RELEASE_34/dot2-final) (based on LLVM 3.4.2)", i1 true, metadata !"", i32 0, metadata !32, metadata !32, metadata !253, metadata !32, metadat
!252 = metadata !{metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic/mempcpy.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!253 = metadata !{metadata !254}
!254 = metadata !{i32 786478, metadata !255, metadata !256, metadata !"mempcpy", metadata !"mempcpy", metadata !"", i32 11, metadata !257, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 true, i8* (i8*, i8*, i64)* @mempcpy, null, null, metadata !260, 
!255 = metadata !{metadata !"mempcpy.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!256 = metadata !{i32 786473, metadata !255}      ; [ DW_TAG_file_type ] [/home/tonyxu/Project/klee/runtime/Intrinsic/mempcpy.c]
!257 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !258, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!258 = metadata !{metadata !225, metadata !225, metadata !226, metadata !259}
!259 = metadata !{i32 786454, metadata !255, null, metadata !"size_t", i32 42, i64 0, i64 0, i64 0, i32 0, metadata !229} ; [ DW_TAG_typedef ] [size_t] [line 42, size 0, align 0, offset 0] [from long unsigned int]
!260 = metadata !{metadata !261, metadata !262, metadata !263, metadata !264, metadata !265}
!261 = metadata !{i32 786689, metadata !254, metadata !"destaddr", metadata !256, i32 16777227, metadata !225, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [destaddr] [line 11]
!262 = metadata !{i32 786689, metadata !254, metadata !"srcaddr", metadata !256, i32 33554443, metadata !226, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [srcaddr] [line 11]
!263 = metadata !{i32 786689, metadata !254, metadata !"len", metadata !256, i32 50331659, metadata !259, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [len] [line 11]
!264 = metadata !{i32 786688, metadata !254, metadata !"dest", metadata !256, i32 12, metadata !74, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [dest] [line 12]
!265 = metadata !{i32 786688, metadata !254, metadata !"src", metadata !256, i32 13, metadata !121, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [src] [line 13]
!266 = metadata !{i32 786449, metadata !267, i32 1, metadata !"Ubuntu clang version 3.4.2-3ubuntu2~xedgers (tags/RELEASE_34/dot2-final) (based on LLVM 3.4.2)", i1 true, metadata !"", i32 0, metadata !32, metadata !32, metadata !268, metadata !32, metadat
!267 = metadata !{metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic/memset.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!268 = metadata !{metadata !269}
!269 = metadata !{i32 786478, metadata !270, metadata !271, metadata !"memset", metadata !"memset", metadata !"", i32 11, metadata !272, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 true, i8* (i8*, i32, i64)* @memset, null, null, metadata !275, i32
!270 = metadata !{metadata !"memset.c", metadata !"/home/tonyxu/Project/klee/runtime/Intrinsic"}
!271 = metadata !{i32 786473, metadata !270}      ; [ DW_TAG_file_type ] [/home/tonyxu/Project/klee/runtime/Intrinsic/memset.c]
!272 = metadata !{i32 786453, i32 0, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !273, i32 0, null, null, null} ; [ DW_TAG_subroutine_type ] [line 0, size 0, align 0, offset 0] [from ]
!273 = metadata !{metadata !225, metadata !225, metadata !38, metadata !274}
!274 = metadata !{i32 786454, metadata !270, null, metadata !"size_t", i32 42, i64 0, i64 0, i64 0, i32 0, metadata !229} ; [ DW_TAG_typedef ] [size_t] [line 42, size 0, align 0, offset 0] [from long unsigned int]
!275 = metadata !{metadata !276, metadata !277, metadata !278, metadata !279}
!276 = metadata !{i32 786689, metadata !269, metadata !"dst", metadata !271, i32 16777227, metadata !225, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [dst] [line 11]
!277 = metadata !{i32 786689, metadata !269, metadata !"s", metadata !271, i32 33554443, metadata !38, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [s] [line 11]
!278 = metadata !{i32 786689, metadata !269, metadata !"count", metadata !271, i32 50331659, metadata !274, i32 0, i32 0} ; [ DW_TAG_arg_variable ] [count] [line 11]
!279 = metadata !{i32 786688, metadata !269, metadata !"a", metadata !271, i32 12, metadata !280, i32 0, i32 0} ; [ DW_TAG_auto_variable ] [a] [line 12]
!280 = metadata !{i32 786447, null, null, metadata !"", i32 0, i64 64, i64 64, i64 0, i32 0, metadata !281} ; [ DW_TAG_pointer_type ] [line 0, size 64, align 64, offset 0] [from ]
!281 = metadata !{i32 786485, null, null, metadata !"", i32 0, i64 0, i64 0, i64 0, i32 0, metadata !75} ; [ DW_TAG_volatile_type ] [line 0, size 0, align 0, offset 0] [from char]
!282 = metadata !{i32 2, metadata !"Dwarf Version", i32 4}
!283 = metadata !{i32 1, metadata !"Debug Info Version", i32 1}
!284 = metadata !{metadata !"Ubuntu clang version 3.4.2- (branches/release_34) (based on LLVM 3.4.2)"}
!285 = metadata !{metadata !"Ubuntu clang version 3.4.2-3ubuntu2~xedgers (tags/RELEASE_34/dot2-final) (based on LLVM 3.4.2)"}
!286 = metadata !{i32 47, i32 0, metadata !34, null}
!287 = metadata !{i32 48, i32 0, metadata !288, null}
!288 = metadata !{i32 786443, metadata !1, metadata !34, i32 48, i32 0, i32 0} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!289 = metadata !{i32 49, i32 0, metadata !290, null}
!290 = metadata !{i32 786443, metadata !1, metadata !288, i32 48, i32 0, i32 1} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!291 = metadata !{i32 50, i32 0, metadata !290, null}
!292 = metadata !{i32 50, i32 0, metadata !293, null}
!293 = metadata !{i32 786443, metadata !1, metadata !288, i32 50, i32 0, i32 2} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!294 = metadata !{i32 51, i32 0, metadata !295, null}
!295 = metadata !{i32 786443, metadata !1, metadata !293, i32 50, i32 0, i32 3} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!296 = metadata !{i32 52, i32 0, metadata !295, null}
!297 = metadata !{i32 52, i32 0, metadata !298, null}
!298 = metadata !{i32 786443, metadata !1, metadata !293, i32 52, i32 0, i32 4} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!299 = metadata !{i32 53, i32 0, metadata !300, null}
!300 = metadata !{i32 786443, metadata !1, metadata !298, i32 52, i32 0, i32 5} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!301 = metadata !{i32 54, i32 0, metadata !300, null}
!302 = metadata !{i32 54, i32 0, metadata !303, null}
!303 = metadata !{i32 786443, metadata !1, metadata !298, i32 54, i32 0, i32 6} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!304 = metadata !{i32 55, i32 0, metadata !305, null}
!305 = metadata !{i32 786443, metadata !1, metadata !303, i32 54, i32 0, i32 7} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!306 = metadata !{i32 56, i32 0, metadata !305, null}
!307 = metadata !{i32 57, i32 0, metadata !308, null}
!308 = metadata !{i32 786443, metadata !1, metadata !303, i32 56, i32 0, i32 8} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!309 = metadata !{i32 60, i32 0, metadata !34, null}
!310 = metadata !{i32 66, i32 0, metadata !39, null}
!311 = metadata !{i32 68, i32 0, metadata !312, null}
!312 = metadata !{i32 786443, metadata !1, metadata !39, i32 68, i32 0, i32 9} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!313 = metadata !{i32 73, i32 0, metadata !314, null}
!314 = metadata !{i32 786443, metadata !1, metadata !312, i32 71, i32 0, i32 10} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!315 = metadata !{i32 75, i32 0, metadata !316, null}
!316 = metadata !{i32 786443, metadata !1, metadata !314, i32 75, i32 0, i32 11} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!317 = metadata !{i32 76, i32 0, metadata !318, null}
!318 = metadata !{i32 786443, metadata !1, metadata !314, i32 76, i32 0, i32 12} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!319 = metadata !{i32 78, i32 0, metadata !314, null}
!320 = metadata !{i32 79, i32 0, metadata !314, null}
!321 = metadata !{i32 80, i32 0, metadata !314, null}
!322 = metadata !{i32 83, i32 0, metadata !39, null}
!323 = metadata !{i32 86, i32 0, metadata !39, null}
!324 = metadata !{i32 88, i32 0, metadata !39, null}
!325 = metadata !{i32 93, i32 0, metadata !326, null}
!326 = metadata !{i32 786443, metadata !1, metadata !102, i32 93, i32 0, i32 13} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!327 = metadata !{i32 98, i32 0, metadata !328, null}
!328 = metadata !{i32 786443, metadata !1, metadata !326, i32 96, i32 0, i32 14} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!329 = metadata !{i32 99, i32 0, metadata !330, null}
!330 = metadata !{i32 786443, metadata !1, metadata !328, i32 99, i32 0, i32 15} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!331 = metadata !{i32 100, i32 0, metadata !332, null}
!332 = metadata !{i32 786443, metadata !1, metadata !328, i32 100, i32 0, i32 16} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!333 = metadata !{i32 103, i32 0, metadata !328, null}
!334 = metadata !{i32 104, i32 0, metadata !328, null}
!335 = metadata !{i32 105, i32 0, metadata !328, null}
!336 = metadata !{i32 108, i32 0, metadata !102, null}
!337 = metadata !{i32 115, i32 0, metadata !105, null}
!338 = metadata !{i32 136, i32 0, metadata !105, null}
!339 = metadata !{i32 140, i32 0, metadata !106, null}
!340 = metadata !{i32 141, i32 0, metadata !106, null}
!341 = metadata !{i32 142, i32 0, metadata !106, null}
!342 = metadata !{i32 143, i32 0, metadata !106, null}
!343 = metadata !{i32 144, i32 0, metadata !106, null}
!344 = metadata !{i32 145, i32 0, metadata !106, null}
!345 = metadata !{i32 146, i32 0, metadata !106, null}
!346 = metadata !{i32 147, i32 0, metadata !106, null}
!347 = metadata !{i32 148, i32 0, metadata !106, null}
!348 = metadata !{i32 149, i32 0, metadata !106, null}
!349 = metadata !{i32 150, i32 0, metadata !106, null}
!350 = metadata !{i32 151, i32 0, metadata !106, null}
!351 = metadata !{i32 152, i32 0, metadata !106, null}
!352 = metadata !{i32 153, i32 0, metadata !106, null}
!353 = metadata !{i32 154, i32 0, metadata !106, null}
!354 = metadata !{i32 156, i32 0, metadata !106, null}
!355 = metadata !{i32 169, i32 0, metadata !356, null}
!356 = metadata !{i32 786443, metadata !1, metadata !109, i32 169, i32 0, i32 24} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!357 = metadata !{i32 171, i32 0, metadata !358, null}
!358 = metadata !{i32 786443, metadata !1, metadata !359, i32 171, i32 0, i32 26} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!359 = metadata !{i32 786443, metadata !1, metadata !109, i32 171, i32 0, i32 25} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!360 = metadata !{i32 171, i32 0, metadata !361, null}
!361 = metadata !{i32 786443, metadata !1, metadata !358, i32 171, i32 0, i32 27} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!362 = metadata !{i32 172, i32 0, metadata !363, null}
!363 = metadata !{i32 786443, metadata !1, metadata !364, i32 172, i32 0, i32 29} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!364 = metadata !{i32 786443, metadata !1, metadata !109, i32 172, i32 0, i32 28} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!365 = metadata !{i32 172, i32 0, metadata !366, null}
!366 = metadata !{i32 786443, metadata !1, metadata !363, i32 172, i32 0, i32 30} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!367 = metadata !{i32 173, i32 0, metadata !368, null}
!368 = metadata !{i32 786443, metadata !1, metadata !369, i32 173, i32 0, i32 32} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!369 = metadata !{i32 786443, metadata !1, metadata !109, i32 173, i32 0, i32 31} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!370 = metadata !{i32 173, i32 0, metadata !371, null}
!371 = metadata !{i32 786443, metadata !1, metadata !368, i32 173, i32 0, i32 33} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!372 = metadata !{i32 174, i32 0, metadata !373, null}
!373 = metadata !{i32 786443, metadata !1, metadata !374, i32 174, i32 0, i32 35} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!374 = metadata !{i32 786443, metadata !1, metadata !109, i32 174, i32 0, i32 34} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!375 = metadata !{i32 174, i32 0, metadata !376, null}
!376 = metadata !{i32 786443, metadata !1, metadata !373, i32 174, i32 0, i32 36} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!377 = metadata !{i32 175, i32 0, metadata !378, null}
!378 = metadata !{i32 786443, metadata !1, metadata !379, i32 175, i32 0, i32 38} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!379 = metadata !{i32 786443, metadata !1, metadata !109, i32 175, i32 0, i32 37} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!380 = metadata !{i32 175, i32 0, metadata !381, null}
!381 = metadata !{i32 786443, metadata !1, metadata !378, i32 175, i32 0, i32 39} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!382 = metadata !{i32 176, i32 0, metadata !109, null}
!383 = metadata !{i32 181, i32 0, metadata !112, null}
!384 = metadata !{i32 183, i32 0, metadata !112, null}
!385 = metadata !{i32 184, i32 0, metadata !386, null}
!386 = metadata !{i32 786443, metadata !1, metadata !112, i32 183, i32 0, i32 40} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!387 = metadata !{i32 185, i32 0, metadata !386, null}
!388 = metadata !{i32 187, i32 0, metadata !386, null}
!389 = metadata !{i32 188, i32 0, metadata !390, null}
!390 = metadata !{i32 786443, metadata !1, metadata !386, i32 187, i32 0, i32 41} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!391 = metadata !{i32 189, i32 0, metadata !390, null}
!392 = metadata !{i32 191, i32 0, metadata !390, null}
!393 = metadata !{i32 193, i32 0, metadata !394, null}
!394 = metadata !{i32 786443, metadata !1, metadata !390, i32 193, i32 0, i32 42} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!395 = metadata !{i32 199, i32 0, metadata !390, null}
!396 = metadata !{i32 200, i32 0, metadata !386, null}
!397 = metadata !{i32 203, i32 0, metadata !386, null}
!398 = metadata !{i32 205, i32 0, metadata !399, null}
!399 = metadata !{i32 786443, metadata !1, metadata !386, i32 204, i32 0, i32 44} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!400 = metadata !{i32 206, i32 0, metadata !399, null}
!401 = metadata !{i32 208, i32 0, metadata !386, null}
!402 = metadata !{i32 212, i32 0, metadata !112, null}
!403 = metadata !{i32 219, i32 0, metadata !115, null}
!404 = metadata !{i32 220, i32 0, metadata !115, null}
!405 = metadata !{i32 224, i32 0, metadata !406, null}
!406 = metadata !{i32 786443, metadata !1, metadata !116, i32 224, i32 0, i32 45} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!407 = metadata !{i32 225, i32 0, metadata !408, null}
!408 = metadata !{i32 786443, metadata !1, metadata !406, i32 224, i32 0, i32 46} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!409 = metadata !{i32 226, i32 0, metadata !408, null}
!410 = metadata !{i32 227, i32 0, metadata !408, null}
!411 = metadata !{i32 229, i32 0, metadata !412, null}
!412 = metadata !{i32 786443, metadata !1, metadata !116, i32 229, i32 0, i32 47} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!413 = metadata !{i32 230, i32 0, metadata !414, null}
!414 = metadata !{i32 786443, metadata !1, metadata !412, i32 229, i32 0, i32 48} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!415 = metadata !{i32 231, i32 0, metadata !414, null}
!416 = metadata !{i32 232, i32 0, metadata !414, null}
!417 = metadata !{i32 234, i32 0, metadata !116, null}
!418 = metadata !{i32 235, i32 0, metadata !116, null}
!419 = metadata !{i32 241, i32 0, metadata !117, null}
!420 = metadata !{i32 242, i32 0, metadata !117, null}
!421 = metadata !{i32 246, i32 0, metadata !123, null}
!422 = metadata !{i32 248, i32 0, metadata !123, null}
!423 = metadata !{i32 249, i32 0, metadata !123, null}
!424 = metadata !{i32 251, i32 0, metadata !123, null}
!425 = metadata !{i32 253, i32 0, metadata !426, null}
!426 = metadata !{i32 786443, metadata !1, metadata !123, i32 253, i32 0, i32 49} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!427 = metadata !{i32 255, i32 0, metadata !123, null}
!428 = metadata !{i32 256, i32 0, metadata !123, null}
!429 = metadata !{i32 259, i32 0, metadata !430, null}
!430 = metadata !{i32 786443, metadata !1, metadata !123, i32 259, i32 0, i32 50} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!431 = metadata !{i32 260, i32 0, metadata !432, null}
!432 = metadata !{i32 786443, metadata !1, metadata !430, i32 259, i32 0, i32 51} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!433 = metadata !{i32 261, i32 0, metadata !432, null}
!434 = metadata !{i32 264, i32 0, metadata !435, null}
!435 = metadata !{i32 786443, metadata !1, metadata !123, i32 264, i32 0, i32 52} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!436 = metadata !{i32 265, i32 0, metadata !437, null}
!437 = metadata !{i32 786443, metadata !1, metadata !435, i32 264, i32 0, i32 53} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!438 = metadata !{i32 290, i32 0, metadata !123, null}
!439 = metadata !{i32 291, i32 0, metadata !123, null}
!440 = metadata !{i32 293, i32 0, metadata !123, null}
!441 = metadata !{i32 294, i32 0, metadata !442, null}
!442 = metadata !{i32 786443, metadata !1, metadata !123, i32 294, i32 0, i32 54} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!443 = metadata !{i32 295, i32 0, metadata !444, null}
!444 = metadata !{i32 786443, metadata !1, metadata !442, i32 294, i32 0, i32 55} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!445 = metadata !{i32 298, i32 0, metadata !123, null}
!446 = metadata !{i32 301, i32 0, metadata !123, null}
!447 = metadata !{i32 302, i32 0, metadata !123, null}
!448 = metadata !{i32 320, i32 0, metadata !124, null}
!449 = metadata !{i32 322, i32 0, metadata !450, null}
!450 = metadata !{i32 786443, metadata !1, metadata !124, i32 322, i32 0, i32 56} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Downloads/TFX8051/demo_tfx_10_klee.c]
!451 = metadata !{i32 324, i32 0, metadata !124, null}
!452 = metadata !{i32 326, i32 0, metadata !124, null}
!453 = metadata !{i32 328, i32 0, metadata !124, null}
!454 = metadata !{i32 329, i32 0, metadata !124, null}
!455 = metadata !{i32 13, i32 0, metadata !456, null}
!456 = metadata !{i32 786443, metadata !174, metadata !173, i32 13, i32 0, i32 0} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Project/klee/runtime/Intrinsic/klee_div_zero_check.c]
!457 = metadata !{i32 14, i32 0, metadata !456, null}
!458 = metadata !{i32 15, i32 0, metadata !173, null}
!459 = metadata !{i32 15, i32 0, metadata !184, null}
!460 = metadata !{i32 16, i32 0, metadata !184, null}
!461 = metadata !{metadata !462, metadata !462, i64 0}
!462 = metadata !{metadata !"int", metadata !463, i64 0}
!463 = metadata !{metadata !"omnipotent char", metadata !464, i64 0}
!464 = metadata !{metadata !"Simple C/C++ TBAA"}
!465 = metadata !{i32 21, i32 0, metadata !466, null}
!466 = metadata !{i32 786443, metadata !196, metadata !195, i32 21, i32 0, i32 0} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Project/klee/runtime/Intrinsic/klee_overshift_check.c]
!467 = metadata !{i32 27, i32 0, metadata !468, null}
!468 = metadata !{i32 786443, metadata !196, metadata !466, i32 21, i32 0, i32 1} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Project/klee/runtime/Intrinsic/klee_overshift_check.c]
!469 = metadata !{i32 29, i32 0, metadata !195, null}
!470 = metadata !{i32 16, i32 0, metadata !471, null}
!471 = metadata !{i32 786443, metadata !208, metadata !207, i32 16, i32 0, i32 0} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Project/klee/runtime/Intrinsic/klee_range.c]
!472 = metadata !{i32 17, i32 0, metadata !471, null}
!473 = metadata !{i32 19, i32 0, metadata !474, null}
!474 = metadata !{i32 786443, metadata !208, metadata !207, i32 19, i32 0, i32 1} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Project/klee/runtime/Intrinsic/klee_range.c]
!475 = metadata !{i32 22, i32 0, metadata !476, null}
!476 = metadata !{i32 786443, metadata !208, metadata !474, i32 21, i32 0, i32 3} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Project/klee/runtime/Intrinsic/klee_range.c]
!477 = metadata !{i32 25, i32 0, metadata !478, null}
!478 = metadata !{i32 786443, metadata !208, metadata !476, i32 25, i32 0, i32 4} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Project/klee/runtime/Intrinsic/klee_range.c]
!479 = metadata !{i32 26, i32 0, metadata !480, null}
!480 = metadata !{i32 786443, metadata !208, metadata !478, i32 25, i32 0, i32 5} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Project/klee/runtime/Intrinsic/klee_range.c]
!481 = metadata !{i32 27, i32 0, metadata !480, null}
!482 = metadata !{i32 28, i32 0, metadata !483, null}
!483 = metadata !{i32 786443, metadata !208, metadata !478, i32 27, i32 0, i32 6} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Project/klee/runtime/Intrinsic/klee_range.c]
!484 = metadata !{i32 29, i32 0, metadata !483, null}
!485 = metadata !{i32 32, i32 0, metadata !476, null}
!486 = metadata !{i32 34, i32 0, metadata !207, null}
!487 = metadata !{i32 16, i32 0, metadata !220, null}
!488 = metadata !{i32 17, i32 0, metadata !220, null}
!489 = metadata !{metadata !489, metadata !490, metadata !491}
!490 = metadata !{metadata !"llvm.vectorizer.width", i32 1}
!491 = metadata !{metadata !"llvm.vectorizer.unroll", i32 1}
!492 = metadata !{metadata !463, metadata !463, i64 0}
!493 = metadata !{metadata !493, metadata !490, metadata !491}
!494 = metadata !{i32 18, i32 0, metadata !220, null}
!495 = metadata !{i32 16, i32 0, metadata !496, null}
!496 = metadata !{i32 786443, metadata !240, metadata !239, i32 16, i32 0, i32 0} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Project/klee/runtime/Intrinsic/memmove.c]
!497 = metadata !{i32 19, i32 0, metadata !498, null}
!498 = metadata !{i32 786443, metadata !240, metadata !239, i32 19, i32 0, i32 1} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Project/klee/runtime/Intrinsic/memmove.c]
!499 = metadata !{i32 20, i32 0, metadata !500, null}
!500 = metadata !{i32 786443, metadata !240, metadata !498, i32 19, i32 0, i32 2} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Project/klee/runtime/Intrinsic/memmove.c]
!501 = metadata !{metadata !501, metadata !490, metadata !491}
!502 = metadata !{metadata !502, metadata !490, metadata !491}
!503 = metadata !{i32 22, i32 0, metadata !504, null}
!504 = metadata !{i32 786443, metadata !240, metadata !498, i32 21, i32 0, i32 3} ; [ DW_TAG_lexical_block ] [/home/tonyxu/Project/klee/runtime/Intrinsic/memmove.c]
!505 = metadata !{i32 24, i32 0, metadata !504, null}
!506 = metadata !{i32 23, i32 0, metadata !504, null}
!507 = metadata !{metadata !507, metadata !490, metadata !491}
!508 = metadata !{metadata !508, metadata !490, metadata !491}
!509 = metadata !{i32 28, i32 0, metadata !239, null}
!510 = metadata !{i32 15, i32 0, metadata !254, null}
!511 = metadata !{i32 16, i32 0, metadata !254, null}
!512 = metadata !{metadata !512, metadata !490, metadata !491}
!513 = metadata !{metadata !513, metadata !490, metadata !491}
!514 = metadata !{i32 17, i32 0, metadata !254, null}
!515 = metadata !{i32 13, i32 0, metadata !269, null}
!516 = metadata !{i32 14, i32 0, metadata !269, null}
!517 = metadata !{i32 15, i32 0, metadata !269, null}
