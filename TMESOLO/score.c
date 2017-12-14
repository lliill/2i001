#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "score.h"
#include "gameTest.h"

/* initialisation d'un tableau de scores d'une taille donnée */
void initialiserTableauScores(Score tabScore[], int taille) {
	int i;
	//tabScore = malloc(taille * sizeof(Score));
	for(i=0; i < taille; i++){
		tabScore[i].nom = genereNomJoueur();
		tabScore[i].points = generePointsAleatoire();
	}
	return;
}

/* initialisation d'une structure Score avec les valeurs passées en argument */
Score* creerScore(char* nom, unsigned int pts) {
	Score* p = (Score*)malloc(sizeof(Score));
	if(!p){
		fprintf(stderr, "Erreur d'allocation d'un score\n");
		return NULL;
	}
	p -> nom = strdup(nom);
	p -> points = pts;
	return p;
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
	if (liste == NULL)
		return;
	else{
		detruireScore(liste->score);
		Classement* suiv = liste->suivant;
		free(liste);
		detruireListeClassements(suiv);
	}
}

/* affichage de la liste chaînée passée en argument */
void afficherListeClassements(Classement* cl) {
	if (cl == NULL)
		return;
	else{
		afficherScore(*(cl->score));
		afficherListeClassements(cl -> suivant);
	}
}

/* ajout d'un score dans une liste chaînée d'un classement décroissant (le plus grand en premier) */
Classement* helper(Classement* classement, Score* score){
	if(classement == NULL){
		return creerClassement(score);	
	}

	else{
		if(classement->score->points < score->points){
			Classement* i = creerClassement(score);
			i->suivant = classement;
			return i;
		}
		else{
			classement->suivant = helper(classement->suivant, score);
			return classement;
		}
	}
}
void insererDansClassement(Classement** classement, Score* score) {
	if (classement == NULL)
		return;

	else
		*classement = helper(*classement, score);
/*
	else if(*classement == NULL){
		*classement = creerClassement(score);
		return;	
	}

	else{
		if((*classement)-> score -> points < score -> points){
			Classement* i = creerClassement(score);
			i->suivant = *classement;
			*classement = i;
		}
		else{
			*classement->suivant = 
		}
	}
	while(*classement){
		if(*classement-> score -> points < score -> points){
			Classement* i = creerClassement(score);
			i->suivant = *classement;
		}
	}
*/
}

/* chargement d'un classement depuis un fichier supposé bien formaté, qui initialise la liste de scores */
void ouvrirClassement(char* nom_fichier, Classement** classementPoints) {
	FILE* f = fopen(nom_fichier, "r");
	if(!f){
		fprintf(stderr, "Erreur d'ouverture de fichier\n");
		return ;
	}
	//Classement* c = (Classement*)malloc(sizeof(Classement));
	char s[20];
	unsigned int pts;	
	while(fscanf(f, "%s", s)!=EOF){
		fscanf(f, " %d", &pts);
		Score* score = creerScore(s, pts);
		*classementPoints = helper(*classementPoints, score);
		//insererDansClassement(classementPoints, score);
		
	}
	fclose(f);
	return;
}
