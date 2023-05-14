	PRESERVE8
	THUMB   
		

; ====================== zone de r�servation de donn�es,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
		
VarTime	dcd 0

	
; ===============================================================================================
	
;constantes (�quivalent du #define en C)
TimeValue	equ 900000

	EXPORT Delay_100ms ; la fonction Delay_100ms est rendue publique donc utilisable par d'autres modules.
	EXPORT  VarTime; afin de rendre globale provisoirement pour le test

		
;Section ROM code (read only) :		
	area    moncode,code,readonly
		


; REMARQUE IMPORTANTE 
; Cette mani�re de cr�er une temporisation n'est clairement pas la bonne mani�re de proc�der :
; - elle est peu pr�cise
; - la fonction prend tout le temps CPU pour... ne rien faire...
;
; Pour autant, la fonction montre :
; - les boucles en ASM
; - l'acc�s �cr/lec de variable en RAM
; - le m�canisme d'appel / retour sous programme
;
; et donc poss�de un int�r�t pour d�buter en ASM pur

Delay_100ms proc
		;
	    ldr r0,=VarTime  ;r0=&VarTime;en C		  
						  
		ldr r1,=TimeValue ;r1=9000 en C;
		str r1,[r0] ;*r0=r1          VarTime=r1 en C
		;
		
BoucleTempo	
		ldr r1,[r0]  ;  r1=*r0 				
						
		subs r1,#1 ;  r1--
		str  r1,[r0] ; *r0=r1 
		bne	 BoucleTempo ;voir si on r�entre dans la boucle ou pas
			
		bx lr
		endp
		
		
	END	