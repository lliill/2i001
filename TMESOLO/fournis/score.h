#ifndef GAME_SCORES_H
#define GAME_SCORES_H

#define NBCHARS_MAX 1024

typedef struct _Score {
	char* nom;		/* nom du joueur */
	unsigned int points;	/* nombre de points obtenus */
} Score;

typedef struct _Classement {
	Score* score;			
	struct _Classement* suivant;
} Classement;

/* initialisation d'un tableau de scores d'une taille donnée */
void initialiserTableauScores(Score tabScore[], int taille);

/* initialisation d'une structure Score avec les valeurs passées en argument */
Score* creerScore(char* nom, unsigned int pts);
/* destruction d'une structure Score */
void detruireScore(Score* sc);
/* affichage d'un score */
void afficherScore(Score sc);

/* initialisation d'une structure Classement */
Classement* creerClassement(Score* score);
/* destruction d'une liste de structures Classement */
void detruireListeClassements(Classement* liste);
/* affichage de la liste chaînée passée en argument */
void afficherListeClassements(Classement* cl);

/* ajout d'un score dans une liste chaînée d'un classement décroissant (le plus grand en premier) */
void insererDansClassement(Classement** classement, Score* score);
/* chargement d'un classement depuis un fichier supposé bien formaté, qui initialise la liste de scores */
void ouvrirClassement(char* nom_fichier, Classement** classementPoints);

#endif
