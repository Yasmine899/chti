

#include "DriverJeuLaser.h"
int bouton=1;
extern void StartSon(void);
void callbackson(void);
int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
	
CLOCK_Configure();
	
Timer_1234_Init_ff( TIM4, 11000);	

Active_IT_Debordement_Timer( TIM4, 2, callbackson );

//configuration du Timer 3
	
//TIM 3 va 15 fois plus vite que TIM 4	
	
PWM_Init_ff( TIM3, 3, 720);

GPIO_Configure(GPIOB, 0, OUTPUT, ALT_PPULL);
//============================================================================	
	
	
while	(1)
	{
		if (bouton==1){
			StartSon();
			bouton=0;
	}
}
}
