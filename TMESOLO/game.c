#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "score.h"
#define TAILLE 30

int main() {
	Classement *cl = NULL;
/*	Classement* l = (Classement*)malloc(TAILLE * sizeof(Classement));
	if(!l){
		fprintf(stderr, "Erreur d'allocation\n");
		return 1;
	}*/
	ouvrirClassement("scores.txt", &cl);
	//cl = *l;
	afficherListeClassements(cl);
/*	while(!cl){
		afficherListeClassements(cl);
		cl = cl->suivant;
	}*/
	detruireListeClassements(cl);
	return 0;
}
