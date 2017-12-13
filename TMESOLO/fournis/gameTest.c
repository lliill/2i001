#include <stdlib.h>
#include "gameTest.h"
#include "game.h"

char* listeNomsJoueurs[NB_NOMS_JOUEURS] = {"Alice","Bob","Charlie","Dave","Eve","Frank","Grace","Heidi","Judy","Mallory","Oscar","Peggy","Sybil","Ted","Victor","Wendy"};

/* génère un nombre de points aléatoire entrer MIN_POINTS et MAX_POINTS */
unsigned int generePointsAleatoire() {
	unsigned int u = MIN_POINTS + rand() % (MAX_POINTS - MIN_POINTS + 1);
	return u;
}

/* génère un nom de joueur aléatoire parmi une liste prédéfinie */
char* genereNomJoueur() {
	int nb = rand() % (NB_NOMS_JOUEURS);
	return listeNomsJoueurs[nb];
}
