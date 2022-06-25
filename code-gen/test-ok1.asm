
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		ADDS	$10,$1,%0
		MOV 	%0,-8(%14)
		ADDS	$2,$1,%0
		ADDS	$2,8(%14),%1
		MOV 	%13,%2
		MOV 	%2,-4(%14)
		MOV 	$1,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET