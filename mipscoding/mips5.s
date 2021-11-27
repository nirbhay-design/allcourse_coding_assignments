.data
	myMessage: .asciiz "hello world"
	another: .byte 'a'
	b: .word 23
	pi: .float 3.14
	my:.double 7.02
	myzero : .double 0.0

.text
	ldc1 $f2 my
	ldc1 $f0 myzero #double takes two register
	# use even register number;
	
	
	li $v0, 3
	add.d $f12, $f2 , $f0
	syscall
	
