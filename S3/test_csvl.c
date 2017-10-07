#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "csvl.h"

int main(){
	char *tab="mot1 et mot2 et mot3";
	printf("compte_mots_chaine %d\n",compte_mots_chaine(tab));

	
	

	//char *tab2[4]={"bounjour", "le", "monde", NULL};
	//printf("compte_mots %d\n",compte_mots(tab2));
//	affiche_tab_mots(tab2);
/*	char **tab3 = (char**)malloc(4*sizeof(char*));
	tab3[0]="bonjour";
	tab3[1]="le";
	tab3[2]="monde";
	tab3[3]=NULL;
*/
	char **tab3 = decompose_chaine(tab);
	printf("compte_mots %d\n",compte_mots(tab3));
	//printf("%d\n",tab3[0]=="bonjour ");
	affiche_tab_mots(tab3);

	char* s= compose_chaine(tab3);
	printf("%s\n", s);

	//printf("%d\n","et"=="ett");
	//char** tab4 = reduit_tab_mots(tab3);
	//printf("compte_mots %d\n",compte_mots(tab4));
	//affiche_tab_mots(tab4);
	detruit_tab_mots(tab3);
	//detruit_tab_mots(tab4);
	return 0;
}
