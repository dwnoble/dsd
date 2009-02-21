global vidtest
vidtest:
	jmp done
	jmp realmode
	[bits 16]
	realmode:
	mov ax, 0x1234
	
	
	jmp promode
	[bits 32]
	promode:
	
	
	done:
	mov ax, 0x4321
	ret
