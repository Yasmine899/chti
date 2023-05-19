	PRESERVE8
	THUMB   
		
	include ../../Driver/DriverJeuLaser.inc
; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
		
	import PeriodeSonMicroSec
	import Son
	import LongueurSon
	EXPORT callbackson;
	EXPORT SortieSon
	EXPORT index
		EXPORT StartSon
; ===============================================================================================
	
index DCD 0

SortieSon dcd 0		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		

callbackson proc
	push {lr,r4-r6}
	ldr r0,=Son ;r0=&Son
	ldr r1,=index
	ldr r2,[r1] ;r2 contient la valeur de l'index
	ldr r3,=LongueurSon
	ldr r4,[r3] ;r4 contient la taille
	cmp r2,r4
	beq sortie

	;on est toujours dans le tableau
	;ldr r3,[r0,r2]
	ldr r5,=SortieSon
	ldrsh r6, [r0,r2, LSL #1]
	add r6,#32768
	mov r7,#720
	mul r6,r7
	asr r6,#16
	add r2,r2,#1 ;on incremente l indice
	str r6,[r5] ;
	str r2,[r1];incrémenter l'index
	mov r0,r6
	
	bl PWM_Set_Value_TIM3_Ch3
	
;on est sortis du tableau
	
sortie
	pop {lr,r4-r6}
	bx lr		
	ENDP
		
StartSon proc 
	ldr r1,=index
	mov r2,#0;mise de l'index à 0
	str r2,[r1] ;mise de l'index à 0 
	bx LR
		
	ENDP	
	END
	