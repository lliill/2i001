#include "ecosys.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>

#define NB_PROIES 20
#define NB_PREDATEURS 20
#define T_WAIT 40000


  /* Parametres globaux de l'ecosysteme (externes dans le ecosys.h)*/
float p_ch_dir=0.01;
float d_proie=1;
float d_predateur=1;
float p_manger=0.2;
float p_reproduce=0.01;
float energie=50;


int main(void) {

  srand(time(NULL));

	Animal* lproie;
	Animal *lpreda = NULL; //très important!!
	int i;
	int nproie = rand()%NB_PROIES, npreda= rand()%NB_PREDATEURS;
	for(i=0; i< nproie; i++)
		ajouter_animal(rand()%SIZE_X, rand()%SIZE_Y, &lproie);
	for(i = 0; i < npreda; i++)
		//printf("%d",i);
		ajouter_animal(rand()%SIZE_X, rand()%SIZE_Y, &lpreda);
	clear_screen();
	//printf("Nombre des proies: %4d\n", nproie);
	printf("Nombre des proies compté: %4d\n", compte_animal_rec(lproie));
	//printf("Nombre des predateurs: %4d\n", npreda);
	printf("Nombre des predateurs compté: %4d\n", compte_animal_rec(lpreda));
	afficher_ecosys(lproie, lpreda);

	i=1;
	while(1){//erreur de segmentation à partir d'une certaine tour
	
	rafraichir_proies(&lproie);
	rafraichir_predateurs(&lpreda, &lproie);
	clear_screen();
	
	usleep(T_WAIT+1000000);
	printf("%d eme tour\n", i);
	printf("Nombre des proies compté: %4d\n", compte_animal_rec(lproie));
	printf("Nombre des predateurs compté: %4d\n", compte_animal_rec(lpreda));
	afficher_ecosys(lproie, lpreda);
	i++;
	}
	//free...
	freeListAnimals(lproie);
	freeListAnimals(lpreda);
/**/
  return 0;
}

