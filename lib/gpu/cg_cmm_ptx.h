const char * cg_cmm = 
"	.version 2.3\n"
"	.target sm_20\n"
"	.address_size 64\n"
"	.global .texref pos_tex;\n"
"	.entry kernel_pair (\n"
"		.param .u64 __cudaparm_kernel_pair_x_,\n"
"		.param .u64 __cudaparm_kernel_pair_lj1,\n"
"		.param .u64 __cudaparm_kernel_pair_lj3,\n"
"		.param .s32 __cudaparm_kernel_pair_lj_types,\n"
"		.param .u64 __cudaparm_kernel_pair_sp_lj_in,\n"
"		.param .u64 __cudaparm_kernel_pair_dev_nbor,\n"
"		.param .u64 __cudaparm_kernel_pair_dev_packed,\n"
"		.param .u64 __cudaparm_kernel_pair_ans,\n"
"		.param .u64 __cudaparm_kernel_pair___val_paramengv,\n"
"		.param .s32 __cudaparm_kernel_pair_eflag,\n"
"		.param .s32 __cudaparm_kernel_pair_vflag,\n"
"		.param .s32 __cudaparm_kernel_pair_inum,\n"
"		.param .s32 __cudaparm_kernel_pair_nbor_pitch,\n"
"		.param .s32 __cudaparm_kernel_pair_t_per_atom)\n"
"	{\n"
"	.reg .u32 %r<72>;\n"
"	.reg .u64 %rd<63>;\n"
"	.reg .f32 %f<111>;\n"
"	.reg .pred %p<21>;\n"
"	.shared .align 16 .b8 __cuda___cuda_local_var_32536_33_non_const_sp_lj92[16];\n"
"	.shared .align 4 .b8 __cuda___cuda_local_var_32608_55_non_const_red_acc108[3072];\n"
"	.loc	16	31	0\n"
"$LDWbegin_kernel_pair:\n"
"	.loc	16	36	0\n"
"	ld.param.u64 	%rd1, [__cudaparm_kernel_pair_sp_lj_in];\n"
"	ldu.global.f32 	%f1, [%rd1+0];\n"
"	.loc	16	37	0\n"
"	ld.global.f32 	%f2, [%rd1+4];\n"
"	.loc	16	38	0\n"
"	ld.global.f32 	%f3, [%rd1+8];\n"
"	.loc	16	39	0\n"
"	ld.global.f32 	%f4, [%rd1+12];\n"
"	st.shared.v4.f32 	[__cuda___cuda_local_var_32536_33_non_const_sp_lj92+0], {%f1,%f2,%f3,%f4};\n"
"	.loc	16	46	0\n"
"	mov.f32 	%f5, 0f00000000;     	\n"
"	mov.f32 	%f6, %f5;\n"
"	mov.f32 	%f7, 0f00000000;     	\n"
"	mov.f32 	%f8, %f7;\n"
"	mov.f32 	%f9, 0f00000000;     	\n"
"	mov.f32 	%f10, %f9;\n"
"	mov.f32 	%f11, 0f00000000;    	\n"
"	mov.f32 	%f12, %f11;\n"
"	mov.f32 	%f13, 0f00000000;    	\n"
"	mov.f32 	%f14, %f13;\n"
"	mov.f32 	%f15, 0f00000000;    	\n"
"	mov.f32 	%f16, %f15;\n"
"	ld.param.s32 	%r1, [__cudaparm_kernel_pair_t_per_atom];\n"
"	cvt.s32.u32 	%r2, %tid.x;\n"
"	div.s32 	%r3, %r2, %r1;\n"
"	cvt.s32.u32 	%r4, %ntid.x;\n"
"	div.s32 	%r5, %r4, %r1;\n"
"	cvt.s32.u32 	%r6, %ctaid.x;\n"
"	mul.lo.s32 	%r7, %r6, %r5;\n"
"	add.s32 	%r8, %r3, %r7;\n"
"	ld.param.s32 	%r9, [__cudaparm_kernel_pair_inum];\n"
"	setp.ge.s32 	%p1, %r8, %r9;\n"
"	@%p1 bra 	$Lt_0_28930;\n"
"	.loc	16	51	0\n"
"	ld.param.s32 	%r10, [__cudaparm_kernel_pair_nbor_pitch];\n"
"	cvt.s64.s32 	%rd2, %r10;\n"
"	mul.wide.s32 	%rd3, %r10, 4;\n"
"	cvt.s64.s32 	%rd4, %r8;\n"
"	mul.wide.s32 	%rd5, %r8, 4;\n"
"	ld.param.u64 	%rd6, [__cudaparm_kernel_pair_dev_nbor];\n"
"	add.u64 	%rd7, %rd5, %rd6;\n"
"	add.u64 	%rd8, %rd3, %rd7;\n"
"	ld.global.s32 	%r11, [%rd8+0];\n"
"	sub.s32 	%r12, %r1, 1;\n"
"	and.b32 	%r13, %r12, %r2;\n"
"	cvt.s64.s32 	%rd9, %r13;\n"
"	mul.wide.s32 	%rd10, %r13, 4;\n"
"	ld.param.u64 	%rd11, [__cudaparm_kernel_pair_dev_packed];\n"
"	setp.ne.u64 	%p2, %rd11, %rd6;\n"
"	@%p2 bra 	$Lt_0_20994;\n"
"	cvt.s32.s64 	%r14, %rd2;\n"
"	mul.lo.s32 	%r15, %r14, %r1;\n"
"	mov.s32 	%r16, %r15;\n"
"	mul.lo.s32 	%r17, %r12, %r8;\n"
"	add.s32 	%r18, %r14, %r17;\n"
"	cvt.s64.s32 	%rd12, %r18;\n"
"	mul.wide.s32 	%rd13, %r18, 4;\n"
"	add.u64 	%rd14, %rd8, %rd13;\n"
"	and.b32 	%r19, %r12, %r11;\n"
"	cvt.s64.s32 	%rd15, %r19;\n"
"	div.s32 	%r20, %r11, %r1;\n"
"	mul.lo.s32 	%r21, %r15, %r20;\n"
"	cvt.s64.s32 	%rd16, %r21;\n"
"	add.u64 	%rd17, %rd15, %rd16;\n"
"	mul.lo.u64 	%rd18, %rd17, 4;\n"
"	add.u64 	%rd19, %rd14, %rd18;\n"
"	add.u64 	%rd20, %rd10, %rd14;\n"
"	bra.uni 	$Lt_0_20738;\n"
"$Lt_0_20994:\n"
"	add.u64 	%rd21, %rd3, %rd8;\n"
"	ld.global.s32 	%r22, [%rd21+0];\n"
"	cvt.s64.s32 	%rd22, %r22;\n"
"	mul.wide.s32 	%rd23, %r22, 4;\n"
"	add.u64 	%rd24, %rd11, %rd23;\n"
"	cvt.s64.s32 	%rd25, %r11;\n"
"	mul.wide.s32 	%rd26, %r11, 4;\n"
"	add.u64 	%rd19, %rd24, %rd26;\n"
"	mov.s32 	%r16, %r1;\n"
"	add.u64 	%rd20, %rd10, %rd24;\n"
"$Lt_0_20738:\n"
"	.loc	16	54	0\n"
"	ld.global.s32 	%r23, [%rd7+0];\n"
"	mov.u32 	%r24, %r23;\n"
"	mov.s32 	%r25, 0;\n"
"	mov.u32 	%r26, %r25;\n"
"	mov.s32 	%r27, 0;\n"
"	mov.u32 	%r28, %r27;\n"
"	mov.s32 	%r29, 0;\n"
"	mov.u32 	%r30, %r29;\n"
"	tex.1d.v4.f32.s32 {%f17,%f18,%f19,%f20},[pos_tex,{%r24,%r26,%r28,%r30}];\n"
"	mov.f32 	%f21, %f17;\n"
"	mov.f32 	%f22, %f18;\n"
"	mov.f32 	%f23, %f19;\n"
"	mov.f32 	%f24, %f20;\n"
"	setp.ge.u64 	%p3, %rd20, %rd19;\n"
"	@%p3 bra 	$Lt_0_30466;\n"
"	cvt.rzi.ftz.s32.f32 	%r31, %f24;\n"
"	cvt.s64.s32 	%rd27, %r16;\n"
"	ld.param.s32 	%r32, [__cudaparm_kernel_pair_lj_types];\n"
"	mul.lo.s32 	%r33, %r32, %r31;\n"
"	ld.param.u64 	%rd28, [__cudaparm_kernel_pair_lj1];\n"
"	mov.f32 	%f25, 0f00000000;    	\n"
"	mov.f32 	%f26, 0f00000000;    	\n"
"	mov.f32 	%f27, 0f00000000;    	\n"
"	mov.f32 	%f28, 0f00000000;    	\n"
"	mov.u64 	%rd29, __cuda___cuda_local_var_32536_33_non_const_sp_lj92;\n"
"$Lt_0_21762:\n"
"	.loc	16	60	0\n"
"	ld.global.s32 	%r34, [%rd20+0];\n"
"	.loc	16	61	0\n"
"	shr.s32 	%r35, %r34, 30;\n"
"	and.b32 	%r36, %r35, 3;\n"
"	cvt.s64.s32 	%rd30, %r36;\n"
"	mul.wide.s32 	%rd31, %r36, 4;\n"
"	add.u64 	%rd32, %rd29, %rd31;\n"
"	ld.shared.f32 	%f29, [%rd32+0];\n"
"	.loc	16	64	0\n"
"	and.b32 	%r37, %r34, 1073741823;\n"
"	mov.u32 	%r38, %r37;\n"
"	mov.s32 	%r39, 0;\n"
"	mov.u32 	%r40, %r39;\n"
"	mov.s32 	%r41, 0;\n"
"	mov.u32 	%r42, %r41;\n"
"	mov.s32 	%r43, 0;\n"
"	mov.u32 	%r44, %r43;\n"
"	tex.1d.v4.f32.s32 {%f30,%f31,%f32,%f33},[pos_tex,{%r38,%r40,%r42,%r44}];\n"
"	mov.f32 	%f34, %f30;\n"
"	mov.f32 	%f35, %f31;\n"
"	mov.f32 	%f36, %f32;\n"
"	mov.f32 	%f37, %f33;\n"
"	cvt.rzi.ftz.s32.f32 	%r45, %f37;\n"
"	sub.ftz.f32 	%f38, %f22, %f35;\n"
"	sub.ftz.f32 	%f39, %f21, %f34;\n"
"	sub.ftz.f32 	%f40, %f23, %f36;\n"
"	mul.ftz.f32 	%f41, %f38, %f38;\n"
"	fma.rn.ftz.f32 	%f42, %f39, %f39, %f41;\n"
"	fma.rn.ftz.f32 	%f43, %f40, %f40, %f42;\n"
"	add.s32 	%r46, %r45, %r33;\n"
"	cvt.s64.s32 	%rd33, %r46;\n"
"	mul.wide.s32 	%rd34, %r46, 16;\n"
"	add.u64 	%rd35, %rd34, %rd28;\n"
"	ld.global.f32 	%f44, [%rd35+0];\n"
"	setp.gt.ftz.f32 	%p4, %f44, %f43;\n"
"	@!%p4 bra 	$Lt_0_24066;\n"
"	rcp.approx.ftz.f32 	%f45, %f43;\n"
"	ld.global.f32 	%f46, [%rd35+4];\n"
"	mov.f32 	%f47, 0f40000000;    	\n"
"	setp.eq.ftz.f32 	%p5, %f46, %f47;\n"
"	@!%p5 bra 	$Lt_0_22786;\n"
"	.loc	16	79	0\n"
"	mul.ftz.f32 	%f48, %f45, %f45;\n"
"	mov.f32 	%f49, %f48;\n"
"	.loc	16	80	0\n"
"	mul.ftz.f32 	%f50, %f48, %f48;\n"
"	bra.uni 	$Lt_0_23042;\n"
"$Lt_0_22786:\n"
"	mov.f32 	%f51, 0f3f800000;    	\n"
"	setp.eq.ftz.f32 	%p6, %f46, %f51;\n"
"	@!%p6 bra 	$Lt_0_23298;\n"
"	.loc	16	82	0\n"
"	sqrt.approx.ftz.f32 	%f52, %f45;\n"
"	mul.ftz.f32 	%f53, %f45, %f52;\n"
"	mov.f32 	%f50, %f53;\n"
"	.loc	16	83	0\n"
"	mul.ftz.f32 	%f49, %f53, %f53;\n"
"	bra.uni 	$Lt_0_23042;\n"
"$Lt_0_23298:\n"
"	.loc	16	85	0\n"
"	mul.ftz.f32 	%f54, %f45, %f45;\n"
"	mul.ftz.f32 	%f55, %f45, %f54;\n"
"	mov.f32 	%f49, %f55;\n"
"	.loc	16	86	0\n"
"	mov.f32 	%f50, %f55;\n"
"$Lt_0_23042:\n"
"$Lt_0_22530:\n"
"	.loc	16	88	0\n"
"	mul.ftz.f32 	%f56, %f45, %f29;\n"
"	mul.ftz.f32 	%f57, %f49, %f56;\n"
"	ld.global.v2.f32 	{%f58,%f59}, [%rd35+8];\n"
"	mul.ftz.f32 	%f60, %f58, %f50;\n"
"	sub.ftz.f32 	%f61, %f60, %f59;\n"
"	mul.ftz.f32 	%f62, %f57, %f61;\n"
"	.loc	16	90	0\n"
"	fma.rn.ftz.f32 	%f27, %f39, %f62, %f27;\n"
"	.loc	16	91	0\n"
"	fma.rn.ftz.f32 	%f26, %f38, %f62, %f26;\n"
"	.loc	16	92	0\n"
"	fma.rn.ftz.f32 	%f25, %f40, %f62, %f25;\n"
"	ld.param.s32 	%r47, [__cudaparm_kernel_pair_eflag];\n"
"	mov.u32 	%r48, 0;\n"
"	setp.le.s32 	%p7, %r47, %r48;\n"
"	@%p7 bra 	$Lt_0_23554;\n"
"	.loc	16	94	0\n"
"	ld.param.u64 	%rd36, [__cudaparm_kernel_pair_lj3];\n"
"	add.u64 	%rd37, %rd36, %rd34;\n"
"	ld.global.v4.f32 	{%f63,%f64,%f65,_}, [%rd37+0];\n"
"	mul.ftz.f32 	%f66, %f29, %f49;\n"
"	mul.ftz.f32 	%f67, %f63, %f50;\n"
"	sub.ftz.f32 	%f68, %f67, %f64;\n"
"	mul.ftz.f32 	%f69, %f66, %f68;\n"
"	sub.ftz.f32 	%f70, %f69, %f65;\n"
"	add.ftz.f32 	%f28, %f28, %f70;\n"
"$Lt_0_23554:\n"
"	ld.param.s32 	%r49, [__cudaparm_kernel_pair_vflag];\n"
"	mov.u32 	%r50, 0;\n"
"	setp.le.s32 	%p8, %r49, %r50;\n"
"	@%p8 bra 	$Lt_0_24066;\n"
"	.loc	16	97	0\n"
"	mov.f32 	%f71, %f6;\n"
"	mul.ftz.f32 	%f72, %f39, %f39;\n"
"	fma.rn.ftz.f32 	%f73, %f62, %f72, %f71;\n"
"	mov.f32 	%f6, %f73;\n"
"	.loc	16	98	0\n"
"	mov.f32 	%f74, %f8;\n"
"	fma.rn.ftz.f32 	%f75, %f62, %f41, %f74;\n"
"	mov.f32 	%f8, %f75;\n"
"	.loc	16	99	0\n"
"	mov.f32 	%f76, %f10;\n"
"	mul.ftz.f32 	%f77, %f40, %f40;\n"
"	fma.rn.ftz.f32 	%f78, %f62, %f77, %f76;\n"
"	mov.f32 	%f10, %f78;\n"
"	.loc	16	100	0\n"
"	mov.f32 	%f79, %f12;\n"
"	mul.ftz.f32 	%f80, %f38, %f39;\n"
"	fma.rn.ftz.f32 	%f81, %f62, %f80, %f79;\n"
"	mov.f32 	%f12, %f81;\n"
"	.loc	16	101	0\n"
"	mov.f32 	%f82, %f14;\n"
"	mul.ftz.f32 	%f83, %f39, %f40;\n"
"	fma.rn.ftz.f32 	%f84, %f62, %f83, %f82;\n"
"	mov.f32 	%f14, %f84;\n"
"	.loc	16	102	0\n"
"	mul.ftz.f32 	%f85, %f38, %f40;\n"
"	fma.rn.ftz.f32 	%f15, %f62, %f85, %f15;\n"
"	mov.f32 	%f16, %f15;\n"
"$Lt_0_24066:\n"
"$Lt_0_22018:\n"
"	.loc	16	58	0\n"
"	mul.lo.u64 	%rd38, %rd27, 4;\n"
"	add.u64 	%rd20, %rd20, %rd38;\n"
"	setp.lt.u64 	%p9, %rd20, %rd19;\n"
"	@%p9 bra 	$Lt_0_21762;\n"
"	bra.uni 	$Lt_0_21250;\n"
"$Lt_0_30466:\n"
"	mov.f32 	%f25, 0f00000000;    	\n"
"	mov.f32 	%f26, 0f00000000;    	\n"
"	mov.f32 	%f27, 0f00000000;    	\n"
"	mov.f32 	%f28, 0f00000000;    	\n"
"$Lt_0_21250:\n"
"	mov.u32 	%r51, 1;\n"
"	setp.le.s32 	%p10, %r1, %r51;\n"
"	@%p10 bra 	$Lt_0_26882;\n"
"	.loc	16	107	0\n"
"	mov.u64 	%rd39, __cuda___cuda_local_var_32608_55_non_const_red_acc108;\n"
"	cvt.s64.s32 	%rd40, %r2;\n"
"	mul.wide.s32 	%rd41, %r2, 4;\n"
"	add.u64 	%rd42, %rd39, %rd41;\n"
"	mov.f32 	%f86, %f27;\n"
"	st.shared.f32 	[%rd42+0], %f86;\n"
"	mov.f32 	%f87, %f26;\n"
"	st.shared.f32 	[%rd42+512], %f87;\n"
"	mov.f32 	%f88, %f25;\n"
"	st.shared.f32 	[%rd42+1024], %f88;\n"
"	mov.f32 	%f89, %f28;\n"
"	st.shared.f32 	[%rd42+1536], %f89;\n"
"	shr.s32 	%r52, %r1, 31;\n"
"	mov.s32 	%r53, 1;\n"
"	and.b32 	%r54, %r52, %r53;\n"
"	add.s32 	%r55, %r54, %r1;\n"
"	shr.s32 	%r56, %r55, 1;\n"
"	mov.s32 	%r57, %r56;\n"
"	mov.u32 	%r58, 0;\n"
"	setp.ne.u32 	%p11, %r56, %r58;\n"
"	@!%p11 bra 	$Lt_0_25346;\n"
"$Lt_0_25858:\n"
"	setp.ge.u32 	%p12, %r13, %r57;\n"
"	@%p12 bra 	$Lt_0_26114;\n"
"	add.u32 	%r59, %r2, %r57;\n"
"	cvt.u64.u32 	%rd43, %r59;\n"
"	mul.wide.u32 	%rd44, %r59, 4;\n"
"	add.u64 	%rd45, %rd39, %rd44;\n"
"	ld.shared.f32 	%f90, [%rd45+0];\n"
"	add.ftz.f32 	%f86, %f90, %f86;\n"
"	st.shared.f32 	[%rd42+0], %f86;\n"
"	ld.shared.f32 	%f91, [%rd45+512];\n"
"	add.ftz.f32 	%f87, %f91, %f87;\n"
"	st.shared.f32 	[%rd42+512], %f87;\n"
"	ld.shared.f32 	%f92, [%rd45+1024];\n"
"	add.ftz.f32 	%f88, %f92, %f88;\n"
"	st.shared.f32 	[%rd42+1024], %f88;\n"
"	ld.shared.f32 	%f93, [%rd45+1536];\n"
"	add.ftz.f32 	%f89, %f93, %f89;\n"
"	st.shared.f32 	[%rd42+1536], %f89;\n"
"$Lt_0_26114:\n"
"	shr.u32 	%r57, %r57, 1;\n"
"	mov.u32 	%r60, 0;\n"
"	setp.ne.u32 	%p13, %r57, %r60;\n"
"	@%p13 bra 	$Lt_0_25858;\n"
"$Lt_0_25346:\n"
"	mov.f32 	%f27, %f86;\n"
"	mov.f32 	%f26, %f87;\n"
"	mov.f32 	%f25, %f88;\n"
"	mov.f32 	%f28, %f89;\n"
"	ld.param.s32 	%r61, [__cudaparm_kernel_pair_vflag];\n"
"	mov.u32 	%r62, 0;\n"
"	setp.le.s32 	%p14, %r61, %r62;\n"
"	@%p14 bra 	$Lt_0_26882;\n"
"	mov.f32 	%f86, %f6;\n"
"	st.shared.f32 	[%rd42+0], %f86;\n"
"	mov.f32 	%f87, %f8;\n"
"	st.shared.f32 	[%rd42+512], %f87;\n"
"	mov.f32 	%f88, %f10;\n"
"	st.shared.f32 	[%rd42+1024], %f88;\n"
"	mov.f32 	%f89, %f12;\n"
"	st.shared.f32 	[%rd42+1536], %f89;\n"
"	mov.f32 	%f94, %f14;\n"
"	st.shared.f32 	[%rd42+2048], %f94;\n"
"	mov.f32 	%f95, %f15;\n"
"	st.shared.f32 	[%rd42+2560], %f95;\n"
"	mov.s32 	%r63, %r56;\n"
"	@!%p11 bra 	$Lt_0_27394;\n"
"$Lt_0_27906:\n"
"	setp.ge.u32 	%p15, %r13, %r63;\n"
"	@%p15 bra 	$Lt_0_28162;\n"
"	add.u32 	%r64, %r2, %r63;\n"
"	cvt.u64.u32 	%rd46, %r64;\n"
"	mul.wide.u32 	%rd47, %r64, 4;\n"
"	add.u64 	%rd48, %rd39, %rd47;\n"
"	ld.shared.f32 	%f96, [%rd48+0];\n"
"	add.ftz.f32 	%f86, %f96, %f86;\n"
"	st.shared.f32 	[%rd42+0], %f86;\n"
"	ld.shared.f32 	%f97, [%rd48+512];\n"
"	add.ftz.f32 	%f87, %f97, %f87;\n"
"	st.shared.f32 	[%rd42+512], %f87;\n"
"	ld.shared.f32 	%f98, [%rd48+1024];\n"
"	add.ftz.f32 	%f88, %f98, %f88;\n"
"	st.shared.f32 	[%rd42+1024], %f88;\n"
"	ld.shared.f32 	%f99, [%rd48+1536];\n"
"	add.ftz.f32 	%f89, %f99, %f89;\n"
"	st.shared.f32 	[%rd42+1536], %f89;\n"
"	ld.shared.f32 	%f100, [%rd48+2048];\n"
"	add.ftz.f32 	%f94, %f100, %f94;\n"
"	st.shared.f32 	[%rd42+2048], %f94;\n"
"	ld.shared.f32 	%f101, [%rd48+2560];\n"
"	add.ftz.f32 	%f95, %f101, %f95;\n"
"	st.shared.f32 	[%rd42+2560], %f95;\n"
"$Lt_0_28162:\n"
"	shr.u32 	%r63, %r63, 1;\n"
"	mov.u32 	%r65, 0;\n"
"	setp.ne.u32 	%p16, %r63, %r65;\n"
"	@%p16 bra 	$Lt_0_27906;\n"
"$Lt_0_27394:\n"
"	mov.f32 	%f6, %f86;\n"
"	mov.f32 	%f8, %f87;\n"
"	mov.f32 	%f10, %f88;\n"
"	mov.f32 	%f12, %f89;\n"
"	mov.f32 	%f14, %f94;\n"
"	mov.f32 	%f16, %f95;\n"
"$Lt_0_26882:\n"
"$Lt_0_24834:\n"
"	mov.u32 	%r66, 0;\n"
"	setp.ne.s32 	%p17, %r13, %r66;\n"
"	@%p17 bra 	$Lt_0_28930;\n"
"	ld.param.u64 	%rd49, [__cudaparm_kernel_pair___val_paramengv];\n"
"	add.u64 	%rd50, %rd49, %rd5;\n"
"	ld.param.s32 	%r67, [__cudaparm_kernel_pair_eflag];\n"
"	mov.u32 	%r68, 0;\n"
"	setp.le.s32 	%p18, %r67, %r68;\n"
"	@%p18 bra 	$Lt_0_29442;\n"
"	st.global.f32 	[%rd50+0], %f28;\n"
"	cvt.s64.s32 	%rd51, %r9;\n"
"	mul.wide.s32 	%rd52, %r9, 4;\n"
"	add.u64 	%rd50, %rd50, %rd52;\n"
"$Lt_0_29442:\n"
"	ld.param.s32 	%r69, [__cudaparm_kernel_pair_vflag];\n"
"	mov.u32 	%r70, 0;\n"
"	setp.le.s32 	%p19, %r69, %r70;\n"
"	@%p19 bra 	$Lt_0_29954;\n"
"	mov.f32 	%f102, %f6;\n"
"	st.global.f32 	[%rd50+0], %f102;\n"
"	cvt.s64.s32 	%rd53, %r9;\n"
"	mul.wide.s32 	%rd54, %r9, 4;\n"
"	add.u64 	%rd55, %rd54, %rd50;\n"
"	mov.f32 	%f103, %f8;\n"
"	st.global.f32 	[%rd55+0], %f103;\n"
"	add.u64 	%rd56, %rd54, %rd55;\n"
"	mov.f32 	%f104, %f10;\n"
"	st.global.f32 	[%rd56+0], %f104;\n"
"	add.u64 	%rd57, %rd54, %rd56;\n"
"	mov.f32 	%f105, %f12;\n"
"	st.global.f32 	[%rd57+0], %f105;\n"
"	add.u64 	%rd50, %rd54, %rd57;\n"
"	mov.f32 	%f106, %f14;\n"
"	st.global.f32 	[%rd50+0], %f106;\n"
"	mov.f32 	%f107, %f16;\n"
"	add.u64 	%rd58, %rd54, %rd50;\n"
"	st.global.f32 	[%rd58+0], %f107;\n"
"$Lt_0_29954:\n"
"	ld.param.u64 	%rd59, [__cudaparm_kernel_pair_ans];\n"
"	mul.lo.u64 	%rd60, %rd4, 16;\n"
"	add.u64 	%rd61, %rd59, %rd60;\n"
"	mov.f32 	%f108, %f109;\n"
"	st.global.v4.f32 	[%rd61+0], {%f27,%f26,%f25,%f108};\n"
"$Lt_0_28930:\n"
"$Lt_0_20226:\n"
"	.loc	16	110	0\n"
"	exit;\n"
"$LDWend_kernel_pair:\n"
"	}\n"
"	.entry kernel_pair_fast (\n"
"		.param .u64 __cudaparm_kernel_pair_fast_x_,\n"
"		.param .u64 __cudaparm_kernel_pair_fast_lj1_in,\n"
"		.param .u64 __cudaparm_kernel_pair_fast_lj3_in,\n"
"		.param .u64 __cudaparm_kernel_pair_fast_sp_lj_in,\n"
"		.param .u64 __cudaparm_kernel_pair_fast_dev_nbor,\n"
"		.param .u64 __cudaparm_kernel_pair_fast_dev_packed,\n"
"		.param .u64 __cudaparm_kernel_pair_fast_ans,\n"
"		.param .u64 __cudaparm_kernel_pair_fast___val_paramengv,\n"
"		.param .s32 __cudaparm_kernel_pair_fast_eflag,\n"
"		.param .s32 __cudaparm_kernel_pair_fast_vflag,\n"
"		.param .s32 __cudaparm_kernel_pair_fast_inum,\n"
"		.param .s32 __cudaparm_kernel_pair_fast_nbor_pitch,\n"
"		.param .s32 __cudaparm_kernel_pair_fast_t_per_atom)\n"
"	{\n"
"	.reg .u32 %r<74>;\n"
"	.reg .u64 %rd<75>;\n"
"	.reg .f32 %f<118>;\n"
"	.reg .pred %p<24>;\n"
"	.shared .align 4 .b8 __cuda___cuda_local_var_32625_33_non_const_sp_lj3268[16];\n"
"	.shared .align 16 .b8 __cuda___cuda_local_var_32623_34_non_const_lj13296[1936];\n"
"	.shared .align 16 .b8 __cuda___cuda_local_var_32624_34_non_const_lj35232[1936];\n"
"	.shared .align 4 .b8 __cuda___cuda_local_var_32702_55_non_const_red_acc7168[3072];\n"
"	.loc	16	118	0\n"
"$LDWbegin_kernel_pair_fast:\n"
"	cvt.s32.u32 	%r1, %tid.x;\n"
"	mov.u32 	%r2, 3;\n"
"	setp.gt.s32 	%p1, %r1, %r2;\n"
"	@%p1 bra 	$Lt_1_22530;\n"
"	.loc	16	126	0\n"
"	mov.u64 	%rd1, __cuda___cuda_local_var_32625_33_non_const_sp_lj3268;\n"
"	cvt.s64.s32 	%rd2, %r1;\n"
"	mul.wide.s32 	%rd3, %r1, 4;\n"
"	ld.param.u64 	%rd4, [__cudaparm_kernel_pair_fast_sp_lj_in];\n"
"	add.u64 	%rd5, %rd4, %rd3;\n"
"	ld.global.f32 	%f1, [%rd5+0];\n"
"	add.u64 	%rd6, %rd3, %rd1;\n"
"	st.shared.f32 	[%rd6+0], %f1;\n"
"$Lt_1_22530:\n"
"	mov.u64 	%rd1, __cuda___cuda_local_var_32625_33_non_const_sp_lj3268;\n"
"	mov.u32 	%r3, 120;\n"
"	setp.gt.s32 	%p2, %r1, %r3;\n"
"	@%p2 bra 	$Lt_1_23042;\n"
"	.loc	16	128	0\n"
"	mov.u64 	%rd7, __cuda___cuda_local_var_32623_34_non_const_lj13296;\n"
"	cvt.s64.s32 	%rd8, %r1;\n"
"	mul.wide.s32 	%rd9, %r1, 16;\n"
"	ld.param.u64 	%rd10, [__cudaparm_kernel_pair_fast_lj1_in];\n"
"	add.u64 	%rd11, %rd10, %rd9;\n"
"	add.u64 	%rd12, %rd9, %rd7;\n"
"	ld.global.v4.f32 	{%f2,%f3,%f4,%f5}, [%rd11+0];\n"
"	st.shared.v4.f32 	[%rd12+0], {%f2,%f3,%f4,%f5};\n"
"	ld.param.s32 	%r4, [__cudaparm_kernel_pair_fast_eflag];\n"
"	mov.u32 	%r5, 0;\n"
"	setp.le.s32 	%p3, %r4, %r5;\n"
"	@%p3 bra 	$Lt_1_23554;\n"
"	.loc	16	130	0\n"
"	mov.u64 	%rd13, __cuda___cuda_local_var_32624_34_non_const_lj35232;\n"
"	ld.param.u64 	%rd14, [__cudaparm_kernel_pair_fast_lj3_in];\n"
"	add.u64 	%rd15, %rd14, %rd9;\n"
"	add.u64 	%rd16, %rd9, %rd13;\n"
"	ld.global.v4.f32 	{%f6,%f7,%f8,%f9}, [%rd15+0];\n"
"	st.shared.v4.f32 	[%rd16+0], {%f6,%f7,%f8,%f9};\n"
"$Lt_1_23554:\n"
"	mov.u64 	%rd13, __cuda___cuda_local_var_32624_34_non_const_lj35232;\n"
"$Lt_1_23042:\n"
"	mov.u64 	%rd13, __cuda___cuda_local_var_32624_34_non_const_lj35232;\n"
"	mov.u64 	%rd7, __cuda___cuda_local_var_32623_34_non_const_lj13296;\n"
"	.loc	16	138	0\n"
"	mov.f32 	%f10, 0f00000000;    	\n"
"	mov.f32 	%f11, %f10;\n"
"	mov.f32 	%f12, 0f00000000;    	\n"
"	mov.f32 	%f13, %f12;\n"
"	mov.f32 	%f14, 0f00000000;    	\n"
"	mov.f32 	%f15, %f14;\n"
"	mov.f32 	%f16, 0f00000000;    	\n"
"	mov.f32 	%f17, %f16;\n"
"	mov.f32 	%f18, 0f00000000;    	\n"
"	mov.f32 	%f19, %f18;\n"
"	mov.f32 	%f20, 0f00000000;    	\n"
"	mov.f32 	%f21, %f20;\n"
"	.loc	16	140	0\n"
"	bar.sync 	0;\n"
"	ld.param.s32 	%r6, [__cudaparm_kernel_pair_fast_t_per_atom];\n"
"	div.s32 	%r7, %r1, %r6;\n"
"	cvt.s32.u32 	%r8, %ntid.x;\n"
"	div.s32 	%r9, %r8, %r6;\n"
"	cvt.s32.u32 	%r10, %ctaid.x;\n"
"	mul.lo.s32 	%r11, %r10, %r9;\n"
"	add.s32 	%r12, %r7, %r11;\n"
"	ld.param.s32 	%r13, [__cudaparm_kernel_pair_fast_inum];\n"
"	setp.ge.s32 	%p4, %r12, %r13;\n"
"	@%p4 bra 	$Lt_1_32770;\n"
"	.loc	16	145	0\n"
"	ld.param.s32 	%r14, [__cudaparm_kernel_pair_fast_nbor_pitch];\n"
"	cvt.s64.s32 	%rd17, %r14;\n"
"	mul.wide.s32 	%rd18, %r14, 4;\n"
"	cvt.s64.s32 	%rd19, %r12;\n"
"	mul.wide.s32 	%rd20, %r12, 4;\n"
"	ld.param.u64 	%rd21, [__cudaparm_kernel_pair_fast_dev_nbor];\n"
"	add.u64 	%rd22, %rd20, %rd21;\n"
"	add.u64 	%rd23, %rd18, %rd22;\n"
"	ld.global.s32 	%r15, [%rd23+0];\n"
"	sub.s32 	%r16, %r6, 1;\n"
"	and.b32 	%r17, %r16, %r1;\n"
"	cvt.s64.s32 	%rd24, %r17;\n"
"	mul.wide.s32 	%rd25, %r17, 4;\n"
"	ld.param.u64 	%rd26, [__cudaparm_kernel_pair_fast_dev_packed];\n"
"	setp.ne.u64 	%p5, %rd26, %rd21;\n"
"	@%p5 bra 	$Lt_1_24834;\n"
"	cvt.s32.s64 	%r18, %rd17;\n"
"	mul.lo.s32 	%r19, %r18, %r6;\n"
"	mov.s32 	%r20, %r19;\n"
"	mul.lo.s32 	%r21, %r16, %r12;\n"
"	add.s32 	%r22, %r18, %r21;\n"
"	cvt.s64.s32 	%rd27, %r22;\n"
"	mul.wide.s32 	%rd28, %r22, 4;\n"
"	add.u64 	%rd29, %rd23, %rd28;\n"
"	and.b32 	%r23, %r16, %r15;\n"
"	cvt.s64.s32 	%rd30, %r23;\n"
"	div.s32 	%r24, %r15, %r6;\n"
"	mul.lo.s32 	%r25, %r19, %r24;\n"
"	cvt.s64.s32 	%rd31, %r25;\n"
"	add.u64 	%rd32, %rd30, %rd31;\n"
"	mul.lo.u64 	%rd33, %rd32, 4;\n"
"	add.u64 	%rd34, %rd29, %rd33;\n"
"	add.u64 	%rd35, %rd25, %rd29;\n"
"	bra.uni 	$Lt_1_24578;\n"
"$Lt_1_24834:\n"
"	add.u64 	%rd36, %rd18, %rd23;\n"
"	ld.global.s32 	%r26, [%rd36+0];\n"
"	cvt.s64.s32 	%rd37, %r26;\n"
"	mul.wide.s32 	%rd38, %r26, 4;\n"
"	add.u64 	%rd39, %rd26, %rd38;\n"
"	cvt.s64.s32 	%rd40, %r15;\n"
"	mul.wide.s32 	%rd41, %r15, 4;\n"
"	add.u64 	%rd34, %rd39, %rd41;\n"
"	mov.s32 	%r20, %r6;\n"
"	add.u64 	%rd35, %rd25, %rd39;\n"
"$Lt_1_24578:\n"
"	.loc	16	148	0\n"
"	ld.global.s32 	%r27, [%rd22+0];\n"
"	mov.u32 	%r28, %r27;\n"
"	mov.s32 	%r29, 0;\n"
"	mov.u32 	%r30, %r29;\n"
"	mov.s32 	%r31, 0;\n"
"	mov.u32 	%r32, %r31;\n"
"	mov.s32 	%r33, 0;\n"
"	mov.u32 	%r34, %r33;\n"
"	tex.1d.v4.f32.s32 {%f22,%f23,%f24,%f25},[pos_tex,{%r28,%r30,%r32,%r34}];\n"
"	mov.f32 	%f26, %f22;\n"
"	mov.f32 	%f27, %f23;\n"
"	mov.f32 	%f28, %f24;\n"
"	mov.f32 	%f29, %f25;\n"
"	setp.ge.u64 	%p6, %rd35, %rd34;\n"
"	@%p6 bra 	$Lt_1_34306;\n"
"	cvt.rzi.ftz.s32.f32 	%r35, %f29;\n"
"	cvt.s64.s32 	%rd42, %r20;\n"
"	mul.lo.s32 	%r36, %r35, 11;\n"
"	cvt.rn.f32.s32 	%f30, %r36;\n"
"	mov.f32 	%f31, 0f00000000;    	\n"
"	mov.f32 	%f32, 0f00000000;    	\n"
"	mov.f32 	%f33, 0f00000000;    	\n"
"	mov.f32 	%f34, 0f00000000;    	\n"
"$Lt_1_25602:\n"
"	.loc	16	155	0\n"
"	ld.global.s32 	%r37, [%rd35+0];\n"
"	.loc	16	156	0\n"
"	shr.s32 	%r38, %r37, 30;\n"
"	and.b32 	%r39, %r38, 3;\n"
"	cvt.s64.s32 	%rd43, %r39;\n"
"	mul.wide.s32 	%rd44, %r39, 4;\n"
"	add.u64 	%rd45, %rd1, %rd44;\n"
"	ld.shared.f32 	%f35, [%rd45+0];\n"
"	.loc	16	159	0\n"
"	and.b32 	%r40, %r37, 1073741823;\n"
"	mov.u32 	%r41, %r40;\n"
"	mov.s32 	%r42, 0;\n"
"	mov.u32 	%r43, %r42;\n"
"	mov.s32 	%r44, 0;\n"
"	mov.u32 	%r45, %r44;\n"
"	mov.s32 	%r46, 0;\n"
"	mov.u32 	%r47, %r46;\n"
"	tex.1d.v4.f32.s32 {%f36,%f37,%f38,%f39},[pos_tex,{%r41,%r43,%r45,%r47}];\n"
"	mov.f32 	%f40, %f36;\n"
"	mov.f32 	%f41, %f37;\n"
"	mov.f32 	%f42, %f38;\n"
"	mov.f32 	%f43, %f39;\n"
"	sub.ftz.f32 	%f44, %f27, %f41;\n"
"	sub.ftz.f32 	%f45, %f26, %f40;\n"
"	sub.ftz.f32 	%f46, %f28, %f42;\n"
"	mul.ftz.f32 	%f47, %f44, %f44;\n"
"	fma.rn.ftz.f32 	%f48, %f45, %f45, %f47;\n"
"	fma.rn.ftz.f32 	%f49, %f46, %f46, %f48;\n"
"	add.ftz.f32 	%f50, %f30, %f43;\n"
"	cvt.rzi.ftz.s32.f32 	%r48, %f50;\n"
"	cvt.s64.s32 	%rd46, %r48;\n"
"	mul.wide.s32 	%rd47, %r48, 16;\n"
"	add.u64 	%rd48, %rd47, %rd7;\n"
"	ld.shared.f32 	%f51, [%rd48+0];\n"
"	setp.gt.ftz.f32 	%p7, %f51, %f49;\n"
"	@!%p7 bra 	$Lt_1_27906;\n"
"	rcp.approx.ftz.f32 	%f52, %f49;\n"
"	ld.shared.f32 	%f53, [%rd48+4];\n"
"	mov.f32 	%f54, 0f40000000;    	\n"
"	setp.eq.ftz.f32 	%p8, %f53, %f54;\n"
"	@!%p8 bra 	$Lt_1_26626;\n"
"	.loc	16	173	0\n"
"	mul.ftz.f32 	%f55, %f52, %f52;\n"
"	mov.f32 	%f56, %f55;\n"
"	.loc	16	174	0\n"
"	mul.ftz.f32 	%f57, %f55, %f55;\n"
"	bra.uni 	$Lt_1_26882;\n"
"$Lt_1_26626:\n"
"	mov.f32 	%f58, 0f3f800000;    	\n"
"	setp.eq.ftz.f32 	%p9, %f53, %f58;\n"
"	@!%p9 bra 	$Lt_1_27138;\n"
"	.loc	16	176	0\n"
"	sqrt.approx.ftz.f32 	%f59, %f52;\n"
"	mul.ftz.f32 	%f60, %f52, %f59;\n"
"	mov.f32 	%f57, %f60;\n"
"	.loc	16	177	0\n"
"	mul.ftz.f32 	%f56, %f60, %f60;\n"
"	bra.uni 	$Lt_1_26882;\n"
"$Lt_1_27138:\n"
"	.loc	16	179	0\n"
"	mul.ftz.f32 	%f61, %f52, %f52;\n"
"	mul.ftz.f32 	%f62, %f52, %f61;\n"
"	mov.f32 	%f56, %f62;\n"
"	.loc	16	180	0\n"
"	mov.f32 	%f57, %f62;\n"
"$Lt_1_26882:\n"
"$Lt_1_26370:\n"
"	.loc	16	182	0\n"
"	mul.ftz.f32 	%f63, %f52, %f35;\n"
"	mul.ftz.f32 	%f64, %f56, %f63;\n"
"	ld.shared.v2.f32 	{%f65,%f66}, [%rd48+8];\n"
"	mul.ftz.f32 	%f67, %f65, %f57;\n"
"	sub.ftz.f32 	%f68, %f67, %f66;\n"
"	mul.ftz.f32 	%f69, %f64, %f68;\n"
"	.loc	16	184	0\n"
"	fma.rn.ftz.f32 	%f33, %f45, %f69, %f33;\n"
"	.loc	16	185	0\n"
"	fma.rn.ftz.f32 	%f32, %f44, %f69, %f32;\n"
"	.loc	16	186	0\n"
"	fma.rn.ftz.f32 	%f31, %f46, %f69, %f31;\n"
"	ld.param.s32 	%r49, [__cudaparm_kernel_pair_fast_eflag];\n"
"	mov.u32 	%r50, 0;\n"
"	setp.le.s32 	%p10, %r49, %r50;\n"
"	@%p10 bra 	$Lt_1_27394;\n"
"	.loc	16	188	0\n"
"	add.u64 	%rd49, %rd47, %rd13;\n"
"	ld.shared.v4.f32 	{%f70,%f71,%f72,_}, [%rd49+0];\n"
"	mul.ftz.f32 	%f73, %f35, %f56;\n"
"	mul.ftz.f32 	%f74, %f70, %f57;\n"
"	sub.ftz.f32 	%f75, %f74, %f71;\n"
"	mul.ftz.f32 	%f76, %f73, %f75;\n"
"	sub.ftz.f32 	%f77, %f76, %f72;\n"
"	add.ftz.f32 	%f34, %f34, %f77;\n"
"$Lt_1_27394:\n"
"	ld.param.s32 	%r51, [__cudaparm_kernel_pair_fast_vflag];\n"
"	mov.u32 	%r52, 0;\n"
"	setp.le.s32 	%p11, %r51, %r52;\n"
"	@%p11 bra 	$Lt_1_27906;\n"
"	.loc	16	191	0\n"
"	mov.f32 	%f78, %f11;\n"
"	mul.ftz.f32 	%f79, %f45, %f45;\n"
"	fma.rn.ftz.f32 	%f80, %f69, %f79, %f78;\n"
"	mov.f32 	%f11, %f80;\n"
"	.loc	16	192	0\n"
"	mov.f32 	%f81, %f13;\n"
"	fma.rn.ftz.f32 	%f82, %f69, %f47, %f81;\n"
"	mov.f32 	%f13, %f82;\n"
"	.loc	16	193	0\n"
"	mov.f32 	%f83, %f15;\n"
"	mul.ftz.f32 	%f84, %f46, %f46;\n"
"	fma.rn.ftz.f32 	%f85, %f69, %f84, %f83;\n"
"	mov.f32 	%f15, %f85;\n"
"	.loc	16	194	0\n"
"	mov.f32 	%f86, %f17;\n"
"	mul.ftz.f32 	%f87, %f44, %f45;\n"
"	fma.rn.ftz.f32 	%f88, %f69, %f87, %f86;\n"
"	mov.f32 	%f17, %f88;\n"
"	.loc	16	195	0\n"
"	mov.f32 	%f89, %f19;\n"
"	mul.ftz.f32 	%f90, %f45, %f46;\n"
"	fma.rn.ftz.f32 	%f91, %f69, %f90, %f89;\n"
"	mov.f32 	%f19, %f91;\n"
"	.loc	16	196	0\n"
"	mul.ftz.f32 	%f92, %f44, %f46;\n"
"	fma.rn.ftz.f32 	%f20, %f69, %f92, %f20;\n"
"	mov.f32 	%f21, %f20;\n"
"$Lt_1_27906:\n"
"$Lt_1_25858:\n"
"	.loc	16	153	0\n"
"	mul.lo.u64 	%rd50, %rd42, 4;\n"
"	add.u64 	%rd35, %rd35, %rd50;\n"
"	setp.lt.u64 	%p12, %rd35, %rd34;\n"
"	@%p12 bra 	$Lt_1_25602;\n"
"	bra.uni 	$Lt_1_25090;\n"
"$Lt_1_34306:\n"
"	mov.f32 	%f31, 0f00000000;    	\n"
"	mov.f32 	%f32, 0f00000000;    	\n"
"	mov.f32 	%f33, 0f00000000;    	\n"
"	mov.f32 	%f34, 0f00000000;    	\n"
"$Lt_1_25090:\n"
"	mov.u32 	%r53, 1;\n"
"	setp.le.s32 	%p13, %r6, %r53;\n"
"	@%p13 bra 	$Lt_1_30722;\n"
"	.loc	16	201	0\n"
"	mov.u64 	%rd51, __cuda___cuda_local_var_32702_55_non_const_red_acc7168;\n"
"	cvt.s64.s32 	%rd52, %r1;\n"
"	mul.wide.s32 	%rd53, %r1, 4;\n"
"	add.u64 	%rd54, %rd51, %rd53;\n"
"	mov.f32 	%f93, %f33;\n"
"	st.shared.f32 	[%rd54+0], %f93;\n"
"	mov.f32 	%f94, %f32;\n"
"	st.shared.f32 	[%rd54+512], %f94;\n"
"	mov.f32 	%f95, %f31;\n"
"	st.shared.f32 	[%rd54+1024], %f95;\n"
"	mov.f32 	%f96, %f34;\n"
"	st.shared.f32 	[%rd54+1536], %f96;\n"
"	shr.s32 	%r54, %r6, 31;\n"
"	mov.s32 	%r55, 1;\n"
"	and.b32 	%r56, %r54, %r55;\n"
"	add.s32 	%r57, %r56, %r6;\n"
"	shr.s32 	%r58, %r57, 1;\n"
"	mov.s32 	%r59, %r58;\n"
"	mov.u32 	%r60, 0;\n"
"	setp.ne.u32 	%p14, %r58, %r60;\n"
"	@!%p14 bra 	$Lt_1_29186;\n"
"$Lt_1_29698:\n"
"	setp.ge.u32 	%p15, %r17, %r59;\n"
"	@%p15 bra 	$Lt_1_29954;\n"
"	add.u32 	%r61, %r1, %r59;\n"
"	cvt.u64.u32 	%rd55, %r61;\n"
"	mul.wide.u32 	%rd56, %r61, 4;\n"
"	add.u64 	%rd57, %rd51, %rd56;\n"
"	ld.shared.f32 	%f97, [%rd57+0];\n"
"	add.ftz.f32 	%f93, %f97, %f93;\n"
"	st.shared.f32 	[%rd54+0], %f93;\n"
"	ld.shared.f32 	%f98, [%rd57+512];\n"
"	add.ftz.f32 	%f94, %f98, %f94;\n"
"	st.shared.f32 	[%rd54+512], %f94;\n"
"	ld.shared.f32 	%f99, [%rd57+1024];\n"
"	add.ftz.f32 	%f95, %f99, %f95;\n"
"	st.shared.f32 	[%rd54+1024], %f95;\n"
"	ld.shared.f32 	%f100, [%rd57+1536];\n"
"	add.ftz.f32 	%f96, %f100, %f96;\n"
"	st.shared.f32 	[%rd54+1536], %f96;\n"
"$Lt_1_29954:\n"
"	shr.u32 	%r59, %r59, 1;\n"
"	mov.u32 	%r62, 0;\n"
"	setp.ne.u32 	%p16, %r59, %r62;\n"
"	@%p16 bra 	$Lt_1_29698;\n"
"$Lt_1_29186:\n"
"	mov.f32 	%f33, %f93;\n"
"	mov.f32 	%f32, %f94;\n"
"	mov.f32 	%f31, %f95;\n"
"	mov.f32 	%f34, %f96;\n"
"	ld.param.s32 	%r63, [__cudaparm_kernel_pair_fast_vflag];\n"
"	mov.u32 	%r64, 0;\n"
"	setp.le.s32 	%p17, %r63, %r64;\n"
"	@%p17 bra 	$Lt_1_30722;\n"
"	mov.f32 	%f93, %f11;\n"
"	st.shared.f32 	[%rd54+0], %f93;\n"
"	mov.f32 	%f94, %f13;\n"
"	st.shared.f32 	[%rd54+512], %f94;\n"
"	mov.f32 	%f95, %f15;\n"
"	st.shared.f32 	[%rd54+1024], %f95;\n"
"	mov.f32 	%f96, %f17;\n"
"	st.shared.f32 	[%rd54+1536], %f96;\n"
"	mov.f32 	%f101, %f19;\n"
"	st.shared.f32 	[%rd54+2048], %f101;\n"
"	mov.f32 	%f102, %f20;\n"
"	st.shared.f32 	[%rd54+2560], %f102;\n"
"	mov.s32 	%r65, %r58;\n"
"	@!%p14 bra 	$Lt_1_31234;\n"
"$Lt_1_31746:\n"
"	setp.ge.u32 	%p18, %r17, %r65;\n"
"	@%p18 bra 	$Lt_1_32002;\n"
"	add.u32 	%r66, %r1, %r65;\n"
"	cvt.u64.u32 	%rd58, %r66;\n"
"	mul.wide.u32 	%rd59, %r66, 4;\n"
"	add.u64 	%rd60, %rd51, %rd59;\n"
"	ld.shared.f32 	%f103, [%rd60+0];\n"
"	add.ftz.f32 	%f93, %f103, %f93;\n"
"	st.shared.f32 	[%rd54+0], %f93;\n"
"	ld.shared.f32 	%f104, [%rd60+512];\n"
"	add.ftz.f32 	%f94, %f104, %f94;\n"
"	st.shared.f32 	[%rd54+512], %f94;\n"
"	ld.shared.f32 	%f105, [%rd60+1024];\n"
"	add.ftz.f32 	%f95, %f105, %f95;\n"
"	st.shared.f32 	[%rd54+1024], %f95;\n"
"	ld.shared.f32 	%f106, [%rd60+1536];\n"
"	add.ftz.f32 	%f96, %f106, %f96;\n"
"	st.shared.f32 	[%rd54+1536], %f96;\n"
"	ld.shared.f32 	%f107, [%rd60+2048];\n"
"	add.ftz.f32 	%f101, %f107, %f101;\n"
"	st.shared.f32 	[%rd54+2048], %f101;\n"
"	ld.shared.f32 	%f108, [%rd60+2560];\n"
"	add.ftz.f32 	%f102, %f108, %f102;\n"
"	st.shared.f32 	[%rd54+2560], %f102;\n"
"$Lt_1_32002:\n"
"	shr.u32 	%r65, %r65, 1;\n"
"	mov.u32 	%r67, 0;\n"
"	setp.ne.u32 	%p19, %r65, %r67;\n"
"	@%p19 bra 	$Lt_1_31746;\n"
"$Lt_1_31234:\n"
"	mov.f32 	%f11, %f93;\n"
"	mov.f32 	%f13, %f94;\n"
"	mov.f32 	%f15, %f95;\n"
"	mov.f32 	%f17, %f96;\n"
"	mov.f32 	%f19, %f101;\n"
"	mov.f32 	%f21, %f102;\n"
"$Lt_1_30722:\n"
"$Lt_1_28674:\n"
"	mov.u32 	%r68, 0;\n"
"	setp.ne.s32 	%p20, %r17, %r68;\n"
"	@%p20 bra 	$Lt_1_32770;\n"
"	ld.param.u64 	%rd61, [__cudaparm_kernel_pair_fast___val_paramengv];\n"
"	add.u64 	%rd62, %rd61, %rd20;\n"
"	ld.param.s32 	%r69, [__cudaparm_kernel_pair_fast_eflag];\n"
"	mov.u32 	%r70, 0;\n"
"	setp.le.s32 	%p21, %r69, %r70;\n"
"	@%p21 bra 	$Lt_1_33282;\n"
"	st.global.f32 	[%rd62+0], %f34;\n"
"	cvt.s64.s32 	%rd63, %r13;\n"
"	mul.wide.s32 	%rd64, %r13, 4;\n"
"	add.u64 	%rd62, %rd62, %rd64;\n"
"$Lt_1_33282:\n"
"	ld.param.s32 	%r71, [__cudaparm_kernel_pair_fast_vflag];\n"
"	mov.u32 	%r72, 0;\n"
"	setp.le.s32 	%p22, %r71, %r72;\n"
"	@%p22 bra 	$Lt_1_33794;\n"
"	mov.f32 	%f109, %f11;\n"
"	st.global.f32 	[%rd62+0], %f109;\n"
"	cvt.s64.s32 	%rd65, %r13;\n"
"	mul.wide.s32 	%rd66, %r13, 4;\n"
"	add.u64 	%rd67, %rd66, %rd62;\n"
"	mov.f32 	%f110, %f13;\n"
"	st.global.f32 	[%rd67+0], %f110;\n"
"	add.u64 	%rd68, %rd66, %rd67;\n"
"	mov.f32 	%f111, %f15;\n"
"	st.global.f32 	[%rd68+0], %f111;\n"
"	add.u64 	%rd69, %rd66, %rd68;\n"
"	mov.f32 	%f112, %f17;\n"
"	st.global.f32 	[%rd69+0], %f112;\n"
"	add.u64 	%rd62, %rd66, %rd69;\n"
"	mov.f32 	%f113, %f19;\n"
"	st.global.f32 	[%rd62+0], %f113;\n"
"	mov.f32 	%f114, %f21;\n"
"	add.u64 	%rd70, %rd66, %rd62;\n"
"	st.global.f32 	[%rd70+0], %f114;\n"
"$Lt_1_33794:\n"
"	ld.param.u64 	%rd71, [__cudaparm_kernel_pair_fast_ans];\n"
"	mul.lo.u64 	%rd72, %rd19, 16;\n"
"	add.u64 	%rd73, %rd71, %rd72;\n"
"	mov.f32 	%f115, %f116;\n"
"	st.global.v4.f32 	[%rd73+0], {%f33,%f32,%f31,%f115};\n"
"$Lt_1_32770:\n"
"$Lt_1_24066:\n"
"	.loc	16	204	0\n"
"	exit;\n"
"$LDWend_kernel_pair_fast:\n"
"	}\n"
;