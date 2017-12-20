#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "arbre_lexicographique_tab.h"


PNoeudTab creer_noeud(char lettre) {
    
  /* A completer */
	int i;
	PNoeudTab pnt = malloc(sizeof(PNoeudTab));
	if(!pnt){
		fprintf(stderr, "Erreur d'allocation");
		return NULL;
	}
	pnt->lettre = lettre;
	pnt->fin_de_mot = non_fin;
	for(i=0;i<26;i++){
		pnt->fils[i]=NULL;
	}
  return pnt;
}

PNoeudTab ajouter_mot(PNoeudTab racine, char *mot) {
  /* A completer */
  if (mot == NULL)
    return racine;
  else if (racine == NULL){
    if(strlen(mot) >= 1)
      return ajouter_mot(creer_noeud(*mot), mot+1);
    else
      return racine;
  }
  else{
      PNoeudTab cursor = racine;
            while(*mot != '\0'){
              cursor -> fils[*mot - 'a'] = creer_noeud(*mot);
              cursor = cursor -> fils[*mot - 'a'];
              mot++;
            }
            cursor -> fin_de_mot = fin;
      return racine;
  }
}

void afficher_mots(PNoeudTab n, char mot_en_cours[LONGUEUR_MAX_MOT], int index) {
/*
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
      mot_en_cours[index] = n->fils[i]->lettre;//faux!!!! where is   mot_en_cours[index] = n->lettre; ????
      afficher_mots(n->fils[i],mot_en_cours,index+1);
    }
  }
  */
    if (n==NULL)
        return;
    else{
    	mot_en_cours[index] = n->lettre;
    	if(n->fin_de_mot==fin) {
    		mot_en_cours[index+1]='\0';
    		printf("%s\n",mot_en_cours);
  		}
  		else{
  			int i;
			for(i=0;i<26;i++) 
				if(n->fils[i]!=NULL)
					afficher_mots(n->fils[i],mot_en_cours,index+1);
		}
    }
}

void afficher_dico(PNoeudTab racine) {
  /* A completer */
  char mot_en_cours[LONGUEUR_MAX_MOT];
  afficher_mots(racine, mot_en_cours, 0);
}

void detruire_dico(PNoeudTab dico) {
  /* A completer */
  if (dico == NULL)
    return;
  else{
    int i;
    for(i=0; i<26; i++)
      detruire_dico(dico -> fils[i]);
    free(dico);
  }
}

int rechercher_mot(PNoeudTab dico, char *mot) {
  
  /* A completer */
  if (dico == NULL || mot == NULL)
    return 0;

  else if (dico ->lettre == *mot){
    if(strlen(mot)==1)
      return dico -> fin_de_mot == fin;
    else{
      int i,s;
      for(i=0; i<26; i++)
        s += rechercher_mot(dico, mot+1);
      return s;
    }
  }
  else  return 0;
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
