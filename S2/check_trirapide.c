#include "utilitaires_tableaux.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tri_rapide.h"

int main(void){
	//int tab[] = {6,5,4,8,1,3,2,9,7};
	int tab[8];
	srand(time(NULL));
	init_tab_alea(tab, 8);
	afficher_tab(tab, 8);
	triRapide(tab, 8);
	afficher_tab(tab,8);
	return 0;
}
