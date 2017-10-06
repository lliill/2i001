
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compte_mots(char **ptab_mots);

int compte_mots_chaine(char *chaine) {
	int i=0;//indices
	int j =0;//nb de mots
	while (chaine[i]!='\0'){
		if(chaine[i]==' ')  j++;
		i++;}
	return j+1;
}


char **decompose_chaine(char *chaine)
{
	int n,i = 0, j = 0, k; //k indice de debut de mot
	n = compte_mots_chaine(chaine);
	char **tab = (char**)malloc( n * sizeof(char*));
	while(chaine[i]!='\0' && j < n){
		printf("while\n");
		if(chaine[i]==' ') {
			printf("if\n");
			strncpy(tab[j], chaine+k, i-k);
			j++;
		}
		//printf("%s\n",tab[j]);
		k=i;
		i++;
	}
	return tab;
		
}

char *compose_chaine(char **ptab_mots)
{
  /* a completer */
}
		
char **detruit_tab_mots(char **ptab_mots)
{
/*
	int n,i;
	n=compte_mots(ptab_mots);
	for (i=0; i<n; i++)
		{
		free(ptab_mots[i]);
		}
	return NULL;
*/
	free(ptab_mots);
	return NULL;
}

int compte_mots(char **ptab_mots)
{
	int cpt=0;
	while (ptab_mots[cpt]!=NULL)
		{
		cpt++;
		}
	return cpt;
}

void affiche_tab_mots(char **ptab_mots)
{	printf("aff\n");
	int nb,i;
	nb=compte_mots(ptab_mots);
	printf("%d\n",nb);
	for ( i=0; i<nb ; i++)
		{
		printf("%s\n",ptab_mots[i]);
		}
}

char **reduit_tab_mots(char **ptab_mots)
{
  /* a completer */
}
