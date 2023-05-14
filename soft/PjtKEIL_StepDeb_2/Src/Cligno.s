 
		
    include Driver/DriverJeuLaser.inc
	EXPORT timer_callback;
	EXPORT FlagCligno;
	PRESERVE8
	THUMB  
; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :

	area    mesdata,data,readonly

;Section RAM (read write):
	area    maram,data,readwrite
		
FlagCligno	dcd 1
	
; ===============================================================================================
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		
	
timer_callback proc
		push {lr}
		ldr r2,=FlagCligno
		ldr r3,[r2]
		cmp r3, #0 ;on branche si c'est égal à 0
		beq egal0
		
		mov r3,#0
		str r3,[r2]
		mov r0,#1
		bl GPIOB_Set  ;FlagCligno=1;
		b end
		
egal0
		mov r3,#1
		str r3,[r2]
		mov r0,#1 ;parametre de GPIOB_Clear
		BL GPIOB_Clear
		
end
		pop {lr}
		bx lr		
		END	

