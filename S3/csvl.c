
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
	int n,i = 0, j = 0, k = 0; //k indice de debut de mot
	n = compte_mots_chaine(chaine);
	char **tab = (char**)malloc( (n+1) * sizeof(char*));
	while(j < n+1){
		//printf("while\n");
		if(chaine[i]==' ' || chaine[i]=='\0') {
			//printf("if\n");
			tab[j] = (char*)malloc(i-k+1); 
			//printf("malloc\n");
			strncpy(tab[j], chaine+k, i-k);
			// printf("strncpy \n");
			j++;
			tab[j] = NULL;
			k=i+1;
			if(chaine[i]=='\0') break;
		}
		//printf("%s\n",tab[j]);
		
		i++;
	}
	return tab;
		
}

char *compose_chaine(char **ptab_mots)
{
	int ia=0, lens=0, cursor = 0;
	while(ptab_mots[ia]!=NULL){
		lens+=strlen(ptab_mots[ia]);
		ia++;
	}
	lens+= compte_mots(ptab_mots);
	char *s =(char*)malloc( lens   );
	for(ia=0; ptab_mots[ia]!=NULL ;ia++){
		strncpy(s+cursor, ptab_mots[ia], strlen(ptab_mots[ia]) );
		cursor += strlen(ptab_mots[ia]);
		if(ia < compte_mots(ptab_mots) ) {
		s[cursor]=' ';
		cursor++;
		}
	}
	s[cursor]='\0';
	return s;
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
{	//printf("aff\n");
	int nb,i;
	nb=compte_mots(ptab_mots);
	//printf("%d\n",nb);
	for ( i=0; i<nb ; i++)
		{
		printf("%s\n",ptab_mots[i]);
		}
}

char **reduit_tab_mots(char **ptab_mots)
{   /*
	int i=0, j=0, k, nb=compte_mots(ptab_mots);//i indice de ptab, j indice de t, k parcourt t
	//_Bool same = 0;
	  char* t[nb];//tab pseudo-reduit
	  for(i=0;i<=nb; i++){
		  t[i]=NULL;
	  }
	for(i=0;i<=nb; i++){
		//t[j]=ptab_mots[i];
		t[j]=ptab_mots[i];

		for(k=0; k<j; k++){
			//printf("t[j] %s ;t[k] %s\n", t[j], t[k]);
			if( strcmp(t[j],t[k]) ){
				printf("null");
				t[j]= NULL;
				break;
				
			}
		}
		
		
		j++;
		//same = 0;
	}
	t[j]=NULL;
	//copy of array

	int ii=0, nb2=compte_mots(t);
	char** tr=(char**)malloc( (nb+1) * sizeof(char*) );
	for(; ii<=nb; ii++){
		if (t[ii])
			tr[ii] = t[ii];
	}
	affiche_tab_mots(tr);
	return tr;
	

*/
}
