

#include "DriverJeuLaser.h"

void timer_callback(void);

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();

// configuration du Timer 4 en débordement 100ms
	
//** Placez votre code là ** // 

	
	//La fonction permet au Timer considéré de compter modulo Duree_ticks.
	
Timer_1234_Init_ff( TIM4, 7200000);
	/*Cette fonction suppose que le timer 1 est déjà lancé avec une certaine périodicité. 
Une fois que la ligne donnée en exemple est exécutée :
? une demande d'interruption est faite lors de chaque débordement du timer 1 (mise à '1' d'un signal
d'interruption provenant du Timer),*/
	
	
	
	
// Activation des interruptions issues du Timer 4
// Association de la fonction à exécuter lors de l'interruption : timer_callback
// cette fonction (si écrite en ASM) doit être conforme à l'AAPCS
	
//** Placez votre code là ** // 	
	
Active_IT_Debordement_Timer(TIM4, 2, timer_callback );
	
// configuration de PortB.1 (PB1) en sortie push-pull
GPIO_Configure(GPIOB, 1, OUTPUT, OUTPUT_PPULL);
	
	
	

//============================================================================	
	
	
while	(1)
	{
	}
}

/*char FlagCligno;

void timer_callback(void)
{
	if (FlagCligno==1)
	{
		FlagCligno=0;
		GPIOB_Set(1);
	}
	else
	{
		FlagCligno=1;
		GPIOB_Clear(1);
	}
		
}*/

