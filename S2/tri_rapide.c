#include "utilitaires_tableaux.h"
#include <stdlib.h>
#include <stdio.h>



void triRapide(int tab[], int n) {
	int p = tab[0];//pivot
	int i;
	int *t1 = nouveau_tableau(n-1);//tab où les elems sont plus petits
	int *t2 = nouveau_tableau(n-1);
	int i1 = 0, i2 = 0;//indices de tableaux

	if(n==1 || n==0)
		return ;
//récursion
	for(i=1; i<n; i++){

		if(p > tab[i]){
			t1[i1] = tab[i];
			i1++;
		}
		else{
			t2[i2] = tab[i];
			i2++;
		}
	}
	//construction de 2 tableaux

	/*
	i1 == 0 ? :triRapide(t1, i1);
	i2 == 0 ? :triRapide(t2, i2);
	*/

	if(i1 != 0)  {
		triRapide(t1, i1);
		for(i=0; i<i1; i++)
			tab[i] = t1[i];
		//copie de t1
	}

	tab[i1] = p;
	//copie de p

	if(i2 != 0) {
 		triRapide(t2, i2);
		for(i=i1+1; i<n; i++)
			tab[i] = t2[i-i1-1];
	//copie de t2

}

	detruire_tableau(t1);
	detruire_tableau(t2);

		
	

}


int partitionner(int tab[], int s, int n)
	{
      int p = 0;


      return p;
	}

void triRapideAmeliore(int tab[], int s, int n)
	{

	}

