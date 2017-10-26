
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
	return liste = animal;
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
	else if( *liste == animal){
		//liste = &( (*liste)-> suivant);//hypothèse nb d'occurrence = 1
		Animal* sui = (*liste) -> suivant;
		Animal* pre = (*liste) -> precedent;
		sui -> precedent = pre;
		pre -> suivant = sui;
		free(*liste);
		*liste = sui;	
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
  /* a completer */
}

void reproduce(Animal **liste_animal) {
  /* a completer */
}

void rafraichir_proies(Animal **liste_proie) {
  /* a completer */
}

Animal *animal_en_XY(Animal *l, int x, int y) {
  /* a completer */
  return NULL;
} 

void rafraichir_predateurs(Animal **liste_predateur, Animal **liste_proie) {
  /* a completer */

}

void afficher_ecosys(Animal *liste_proie,Animal *liste_predateur) {
  /* a completer */

}

void clear_screen() {
  printf("\x1b[2J\x1b[1;1H");  /* code ANSI X3.4 pour effacer l'ecran */
}
