
main:
		PUSH 	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$4,-4(%14)
		DIVS 	-4(%14), $2,-4(%14)
		MULS 	-4(%14), $4,-4(%14)
		MOV 	-4(%14),-8(%14)
		MOV 	-8(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET