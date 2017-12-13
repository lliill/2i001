#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "score.h"
#include "gameTest.h"

/* initialisation d'un tableau de scores d'une taille donnée */
void initialiserTableauScores(Score tabScore[], int taille) {
	return;
}

/* initialisation d'une structure Score avec les valeurs passées en argument */
Score* creerScore(char* nom, unsigned int pts) {
	return NULL;
}

/* destruction d'une structure Score */
void detruireScore(Score* sc) {
	if (sc) {
		free(sc->nom);
		free(sc);
	}
}

/* affichage d'un score */
void afficherScore(Score sc) {
	printf("%s\t%d\n", sc.nom, sc.points);
}

/* initialisation d'une structure Classement */
Classement* creerClassement(Score* score) {
	Classement* nouv = (Classement*)malloc(sizeof(Classement));
	if (!nouv) {
		fprintf(stderr, "Erreur d'allocation d'une structure classement\n");
		return NULL;
	}
	nouv->score = score;
	nouv->suivant = NULL;
	return nouv;
}

/* destruction d'une liste de structures Classement */
void detruireListeClassements(Classement* liste) {
	return;
}

/* affichage de la liste chaînée passée en argument */
void afficherListeClassements(Classement* cl) {
	return;
}

/* ajout d'un score dans une liste chaînée d'un classement décroissant (le plus grand en premier) */
void insererDansClassement(Classement** classement, Score* score) {
	return;
}

/* chargement d'un classement depuis un fichier supposé bien formaté, qui initialise la liste de scores */
void ouvrirClassement(char* nom_fichier, Classement** classementPoints) {
	return;
}
