#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "arbre_lexicographique_tab.h"


PNoeudTab creer_noeud(char lettre) {
    
  /* A completer */
  
  return NULL;
}

PNoeudTab ajouter_mot(PNoeudTab racine, char *mot) {
  
  /* A completer */
  
  return NULL;
}

void afficher_mots(PNoeudTab n, char mot_en_cours[LONGUEUR_MAX_MOT], int index) {
  if (n==NULL)
    return;

  if(n->fin_de_mot==fin) {
    mot_en_cours[index]='\0';
    printf("%s\n",mot_en_cours);
  }

  int i;
  for(i=0;i<26;i++) {
    // On affiche les fils
    if (n->fils[i]!=NULL) {
      mot_en_cours[index] = n->fils[i]->lettre;
      afficher_mots(n->fils[i],mot_en_cours,index+1);
    }
  }
}

void afficher_dico(PNoeudTab racine) {
  
  /* A completer */
  
}

void detruire_dico(PNoeudTab dico) {
  
  /* A completer */
  
}

int rechercher_mot(PNoeudTab dico, char *mot) {
  
  /* A completer */
  
   return 0;
}

PNoeudTab lire_dico(const char *nom_fichier) {
  
  /* A completer */
  
   return NULL;
}

Lm_mot *tous_les_mots_longueur_donnee_rec(PNoeudTab n, char mot_en_cours[LONGUEUR_MAX_MOT], 
                                                 int index, int l, Lm_mot *res) {
  
  /* A completer (Exercice 7) */

  return NULL;
}

Lm_mot *tous_les_mots_longueur_donnee(PNoeudTab racine, const char* prefixe, int l) {
  
  /* A completer (Exercice 7) */

   return NULL;
}

Lm_mot *mots_commencant_par(const char *mot_a_completer, PNoeudTab dico) {
  Lm_mot *res=NULL;
  
  /* A completer (Exercice 7) */

  return res;
}
