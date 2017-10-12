#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "image.h"
#define TMP_STR_SIZE 256

image_t *charger_image_pgm(char *nom_fichier)
	{
	
	FILE *f;
	image_t *img;
	unsigned int nb_niveaux_gris;
	char ligne_lue[TMP_STR_SIZE];
	enum format {BIN, ASCII} pgm_form;
/*	
	FILE *f;
	char ligne_lue[TMP_STR_SIZE];
	int format;
	image_t * img;
*/
	//ouverture du fichier 
	f= fopen(nom_fichier,"r");
	if(!f){
		fprintf(stderr,"Impossible d'ouvrir le fichier");
		return NULL;	
	}
	do{
		fgets(ligne_lue,TMP_STR_SIZE,f);
	}while(*ligne_lue=='#');

	if(!strcmp(ligne_lue,"P5\n")){
		pgm_form = BIN;
	}else{
		if(!strcmp(ligne_lue,"P2\n")){
			pgm_form = ASCII;
		}else{
			fprintf(stderr,"Impossible de lire le format\n");
			return NULL;
		}	
	}
	
	do{
		fgets(ligne_lue,TMP_STR_SIZE,f);
	}while(*ligne_lue=='#');	

//HAUTEUR largeur
	img= creer_image();
	if(sscanf(ligne_lue,"%ld %ld\n",&(img->w),&(img->h))!=2){
		fprintf(stderr,"erreur");
		detruire_image(img);
		return NULL;
	}

	do{
		fgets(ligne_lue,TMP_STR_SIZE,f);
	}while(*ligne_lue=='#');

//nb_niveaux_gris
	if(sscanf(ligne_lue,"%u\n",&nb_niveaux_gris)!=1){
		fprintf(stderr,"erreur");
		detruire_image(img);
		return NULL;
	}


	/*do{
		fgets(ligne_lue,TMP_STR_SIZE,f);
	}while(*ligne_lue=='#');
*/
//pixels in initialtized buff 
	img->buff = (unsigned char *) malloc(sizeof(unsigned char)*img->h*img->w);
	if(pgm_form==BIN){
		fread(img->buff, sizeof(unsigned char), img->h*img->w, f);		
	}else{
		int i,j;
		for(i=0; i<img->h; i++){//i indice de ligne
			for(j=0; j<img->w; j++)//j indice de colonne
				fscanf(f, "%hhu", &((img->buff)[i*(img->w) +j]));
		}
	}
	return img;
	}

int sauver_image_pgm(char *nom_fichier, image_t *img)
	{
	return 1;
	}
