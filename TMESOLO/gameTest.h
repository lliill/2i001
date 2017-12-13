#ifndef GAMETEST_H
#define GAMETEST_H

#define NB_NOMS_JOUEURS 16
extern char* listeNomsJoueurs[NB_NOMS_JOUEURS];

/* génère un nombre de points aléatoire entrer MIN_POINTS et MAX_POINTS */
unsigned int generePointsAleatoire();
/* génère un temps aléatoire entre 0 et MAX_TIME */
float genereTempsAleatoire();
/* génère un nom de joueur aléatoire parmi une liste prédéfinie */
char* genereNomJoueur();

#endif
