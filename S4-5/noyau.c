#include <stdlib.h>
#include "noyau.h"
#include <stdio.h>
#include <string.h>

#define TMP_STR_SIZE 128

noyau_t *creer_noyau(unsigned int dim){
	noyau_t *noyau;
	noyau = (noyau_t*)malloc(sizeof(noyau_t));
	if(noyau==NULL)
		return NULL;
	noyau->dim=dim;
	if(( noyau->coeffs=(int*)malloc(dim*dim*sizeof(int)) ))
		return noyau;
	else{
		puts("erreur d'allocation\n");
		exit(1);
	}
}

void detruire_noyau(noyau_t *pn){
	if(pn==NULL)
		return ;
	free(pn->coeffs);
	free(pn);
	}

noyau_t *charger_noyau(char *nom_fichier){
	FILE* f;
	if(!( f=fopen(nom_fichier, "r") ))
		exit(1);
	int d=getc(f);

	//noyau_t * noyau = creer_noyau();
	return NULL;
	}
