#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "csvl.h"

int main(){
	char *tab="bonjour le monde";
 	printf("%d\n",tab[7]==' ');

	
	

	char *tab2[4]={"bounjour", "le", "monde", NULL};
	printf("%d\n",compte_mots(tab2));
//	affiche_tab_mots(tab2);
/*	char **tab3 = (char**)malloc(4*sizeof(char*));
	tab3[0]="bonjour";
	tab3[1]="le";
	tab3[2]="monde";
	tab3[3]=NULL;
*/
	char **tab3 = decompose_chaine(tab);
	//printf("%d\n",compte_mots(tab3));

	affiche_tab_mots(tab3);
	detruit_tab_mots(tab3);
	return 0;
}
