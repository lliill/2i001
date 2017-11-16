#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "ecosys.h"

/* Pour utiliser la correction automatique:
cavecorrector 6-7 repertoire
 */

Animal *creer_animal(int x, int y, float energie) {
	Animal* na = malloc(sizeof(Animal));
	if(na==NULL){
		printf("Erreur d'allocation");
		exit(1);	
	}
	na->x = x;
	na->y = y;
	na->energie = energie;
	na->dir[0]=rand()%3-1;
	na->dir[1]=rand()%3-1;
	na->precedent = NULL;
	na->suivant = NULL;
	
	return na;
} 

Animal *ajouter_en_tete_animal(Animal *liste, Animal *animal) {
/* circulaire

	Animal* fin;
	fin = liste->precedent;
	liste->precedent = animal;
	fin->suivant = animal;
	animal->suivant = liste;
	animal->precedent = fin;
  return animal;
*/
	animal->suivant = liste;
	animal-> precedent = NULL;
	if(liste) 
		liste->precedent = animal;
	return animal;
}

void ajouter_animal(int x, int y, Animal **liste_animal) {
	if(x< 0 || x > SIZE_X || y < 0 || y > SIZE_Y)
		return;
	else
		*liste_animal = ajouter_en_tete_animal(*liste_animal, creer_animal(x, y, energie));
}


void enlever_animal(Animal **liste, Animal *animal) {
	if (liste) return;
	else if (*liste) return;
	//Animal* i=*liste;
	else if( *liste == animal){
		//liste = &( (*liste)-> suivant);//hypothèse nb d'occurrence = 1
		Animal* sui = (*liste) -> suivant;
		Animal* pre = (*liste) -> precedent;
		sui -> precedent = pre;
		pre -> suivant = sui;
		//free(*liste);
		*liste = sui;	//...
	}
	else
		return enlever_animal( &((*liste)->suivant), animal);
}

unsigned int compte_animal_rec(Animal *la) {
	if(!la)  return 0;
	else	return 1 + compte_animal_rec(la->suivant);
}

unsigned int compte_animal_it(Animal *la) {
	unsigned int sum = 0;
	Animal* i = la;
	while(i){
		sum++;
		i = i->suivant;
	}
	return sum;
}

void bouger_animaux(Animal *la) {
	if(!la)	return;
	la->x=(la->x + la->dir[0])%SIZE_X;
	la->y=(la->y + la->dir[1])%SIZE_Y;
	if(rand()/RAND_MAX < p_ch_dir){
		la->dir[0]=rand()%3-1;
		la->dir[1]=rand()%3-1;
	}
	bouger_animaux(la->suivant);	
}

void reproduce(Animal **liste_animal) {
	if(!liste_animal) return;
	Animal* ani = *liste_animal;
	while(ani){
		if(rand()/RAND_MAX < p_reproduce)
			ajouter_animal(ani->x, ani->y, liste_animal);
		ani=ani->suivant;
	}		
}

void lowerEnergy(Animal **liste, float d){
	//assert(!liste && !*liste);//..
	Animal* ani= *liste;
	Animal* tmp = NULL;
	while(ani){
		ani->energie -= d;
		if(ani->energie < 0){
			enlever_animal(liste, ani);
			tmp = ani->suivant;
			free(ani);
			ani = tmp;
		}
		ani = ani->suivant;//il faut un else
	}
}

void rafraichir_proies(Animal **liste_proie) {//erreur de segmentation à partir d'une certaine tour
	if(!liste_proie) return;
	if(!*liste_proie) return;
	bouger_animaux(*liste_proie);
	lowerEnergy(liste_proie, d_proie);
	reproduce(liste_proie);
}

Animal *animal_en_XY(Animal *l, int x, int y) {
	if(!l)
		return NULL;
	else if(l->x == x && l->y == y)
		return l;
	else
		return animal_en_XY(l->suivant, x, y);
} 

void eat(Animal *predateur, Animal **liste_proie){
	if (!predateur || !liste_proie || !*liste_proie) return;
	Animal* malheureux = animal_en_XY(*liste_proie, predateur->x, predateur->y);
	if(malheureux){
		predateur->energie += malheureux->energie;
		enlever_animal(liste_proie, malheureux);
		//free(malheureux);
	}
	return 	eat(predateur->suivant, liste_proie);
}

void rafraichir_predateurs(Animal **liste_predateur, Animal **liste_proie) {
	if(!liste_proie) return;
	if(!*liste_proie) return;
	if(!liste_predateur) return;
	if(!*liste_predateur) return;
	bouger_animaux(*liste_predateur);
	eat(*liste_predateur, liste_proie);
	lowerEnergy(liste_predateur, d_predateur);
	reproduce(liste_predateur);
}

void afficher_ecosys(Animal *liste_proie,Animal *liste_predateur) {
	char ecosys[SIZE_X][SIZE_Y]; 
	int i,j;
	
	for(i=0; i < SIZE_X; i++)
		for(j=0; j < SIZE_Y; j++)
			ecosys[i][j]=' ';

	while(liste_proie){
		ecosys[liste_proie->x][liste_proie->y]='*';
		liste_proie=liste_proie->suivant;
	}
	while(liste_predateur){
		if(ecosys[liste_predateur->x][liste_predateur->y]=='*')
			ecosys[liste_predateur->x][liste_predateur->y]='@';
		else if(ecosys[liste_predateur->x][liste_predateur->y]==' ')
			ecosys[liste_predateur->x][liste_predateur->y]='O';
		liste_predateur=liste_predateur->suivant;
	}
	for(i=0; i < SIZE_X; i++){
		for(j=0; j < SIZE_Y; j++)
			//if(ecosys[i][j]=='*' ||ecosys[i][j]=='O' ||ecosys[i][j]=='@')
				putchar(ecosys[i][j]);
			//else
			//	putchar(' ');
		putchar('\n');
	}
				

}

void clear_screen() {
  printf("\x1b[2J\x1b[1;1H");  /* code ANSI X3.4 pour effacer l'ecran */
}

void freeListAnimals(Animal* l){
	//if(!l)	return;
	Animal* tmp;
	while(l){
		tmp=l->suivant;
		free(l);
		l = tmp;
	}
}
		
