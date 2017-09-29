#include "utilitaires_tableaux.h"

void triBulle(int tab[], int n)
{	int i,j;
	for(i=n-1; 1<i; i--){
		for(j=0; j<i; j++){
			if(tab[j] > tab[j+1])
				echanger_elem_tab(tab, j, j+1);
		}
	} 
}

void triBulleAmeliore(int tab[], int n)
{	int i,j; _Bool permutee = 0;
	for(i=n-1; 1<i; i--){
		for(j=0; j<i; j++){
			if(tab[j] > tab[j+1]){
				echanger_elem_tab(tab, j, j+1);
				permutee = 1;
			}
		}
		if(permutee == 0)
			break;
		else
			permutee = 0;
	} 
}

