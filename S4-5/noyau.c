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
	noyau_t* n;
	int d;
	char ligne_lue[TMP_STR_SIZE];
	char* cursor;
	int i = 0;

	if(!( f=fopen(nom_fichier, "r") ))
		exit(1);
	
	if ( !fscanf(f, "%d", &d) )
		exit(1);
	n = creer_noyau(d);

	while( fgets(ligne_lue, TMP_STR_SIZE, f) ){
		cursor = ligne_lue;
		do{
		n->coeffs[i] = strtol(cursor, &cursor, 0);
		i++;
		}while(cursor != ligne_lue );
	}

	//noyau_t * noyau = creer_noyau();
	return n;
	}
