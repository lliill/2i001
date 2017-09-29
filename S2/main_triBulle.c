#include "tri_bulle.h"
//#include "u

#include <stdlib.h>
#include <time.h>

int main(void) {
	int tab[8];
	srand(time(NULL));
	init_tab_alea(tab, 8);
	afficher_tab(tab, 8);
	triBulle(tab, 8);	
	afficher_tab(tab, 8);
	return 0;
}
