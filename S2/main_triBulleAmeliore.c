#include "tri_bulle.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int tab[8];
	srand(time(NULL));
	init_tab_alea(tab, 8);
	afficher_tab(tab, 8);
	triBulleAmeliore(tab, 8);	
	afficher_tab(tab, 8);
	//int i1 =2 , i2 = 1;
	//printf("%d %d\n",i1, i2);
	return 0;
}
