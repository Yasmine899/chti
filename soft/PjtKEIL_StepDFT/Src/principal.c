

#include "DriverJeuLaser.h"

extern short int LeSignal[];
extern int DFT_ModuleAuCarre( short int * , char ) ;
extern int calcul_partie_reel( short int * , char) ;
extern int calcul_partie_imag( short int * , char) ;
int partie_reel;
int partie_imagin;

int tabdft[64];
int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();
//partie_reel=calcul_partie_reel(LeSignal,1);


for (int i=0;i<63;i++){
	tabdft[i]=DFT_ModuleAuCarre(LeSignal , i );
}	
	

//============================================================================	
	
	
while	(1)
	{
	}
}

