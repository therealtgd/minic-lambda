
main:
		PUSH 	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		MOV 	-0(%14),-4(%14)
		MOV 	$1,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET