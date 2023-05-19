

#include "DriverJeuLaser.h"
#include "Affichage_Valise.h"
#include "GestionSon.h"

extern short int LeSignal;
int DFT_ModuleAuCarre( short int * , char k) ;
short int dma_buf[64];
int tabdft_joueurs[64];
//les 4 fréquences normalisés

int freq1=17;
int freq2=18;
int freq3=19;
int freq4=20;

int tab_scores[4]={0,0,0,0};
int tab_cible_touche[4]={0,0,0,0};

int compteur=0;
int seuil=24;
void fct_systick_timer(){
	
	Start_DMA1(64);
	Wait_On_End_Of_DMA1();
	Stop_DMA1;

		for (int i=0;i<=64;i++){
			tabdft_joueurs[i]=DFT_ModuleAuCarre(dma_buf , i );	
	}
		
	int val_lim_dft=25;
	int nb_tirs=3;


for (int i=0;i<4;i++){
	//si on en dessus de la valeur limite dft qui pratiquement l amplitude d un pic constaté lors de la dma
	if (tabdft_joueurs[i+17]>val_lim_dft){
		//on incrémente cette valeur puisque le point est accordé si on touche la cible 3 fois
				tab_cible_touche[i]++;
				if (tab_cible_touche[i]>=nb_tirs){
					tab_scores[i]++;
					//on reinitialise cette case pour recompter à 3
					tab_cible_touche[i]=0;
					//affichage 
					Prepare_Afficheur(i,tab_scores[i] );
					//une fois la cible est touché plus de 3 fois et y a un pic à la fréquence on lance le son
					StartSon();
				}
			}
	else{
		tab_cible_touche[i]=0;
}
	}
	Mise_A_Jour_Afficheurs_LED();
}

		
	
		

int main(void){

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

//Pour l'affichage
	Init_Affichage();
// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();
//partie_reel=calcul_partie_reel(LeSignal,1);
	
//ADC
Init_TimingADC_ActiveADC_ff( ADC1, 72 );
Single_Channel_ADC( ADC1, 2 );
Init_Conversion_On_Trig_Timer_ff( ADC1, TIM2_CC2, 225 );
Init_ADC1_DMA1( 0, dma_buf );
	
//timer Systick
Systick_Period_ff(360000000);
Systick_Prio_IT(0, fct_systick_timer);

	
//Gestion Son
		
	//PWM
GPIO_Configure(GPIOB, 0, OUTPUT, ALT_PPULL);
Timer_1234_Init_ff( TIM4, 11000);	
Active_IT_Debordement_Timer( TIM4, 2, callbackson );
PWM_Init_ff( TIM3, 3, 720);

SysTick_On;
SysTick_Enable_IT ;

//============================================================================	
	
	
while	(1){

}
}

