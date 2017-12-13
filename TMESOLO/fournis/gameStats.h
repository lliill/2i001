#ifndef GAME_STATS_H
#define GAME_STATS_H

/* calcul du score moyen du joueur dont le nom est passé en argument,
 * retourne -1 si le joueur est inconnu */
float scoreMoyenJoueur(Classement* cl, char* nom);

/* calcule du score médian d'une liste dont le début est passé en argument 
 * retourne -1 si la liste est vide */
float scoreMedian(Classement* cl);

#endif
