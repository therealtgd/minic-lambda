
main:
		PUSH 	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
@main_body:
		JMP 	@main_body_0
@lambda_x_0:
		PUSH 	%14
		MOV 	%15,%14
		JMP 	@lambda_x_0_body
@lambda_x_0_body:
		SUBS	ovde 8(%14),ovde 12(%14),%0
		ADDS	%0,$1,%0
		MOV 	%0,%13
		JMP 	@lambda_x_0_exit
@lambda_x_0_exit:
		MOV 	%14, %15
		POP 	%14
		RET
@main_body_0:
		MOV 	$2,-8(%14)
		MOV 	$3,-12(%14)
		PUSH	$3
		PUSH	-8(%14)
		CALL	@lambda_x_0
		ADDS 	%15,$8,%15
		MOV 	%13,%0
		MOV 	%0,-4(%14)
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET