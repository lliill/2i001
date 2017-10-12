#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "image.h"

image_t *creer_image(){
	image_t *p;
	p=(image_t*)malloc(sizeof(image_t));
	if(p==NULL){
		printf("Erreur d'allocation\n");
		exit(1);	
	}
	p->w=0;
	p->h=0;
	p->path=NULL;
	p->buff=NULL;

	return p;
}

image_t *copier_image(image_t *src){
	image_t *p;
	p=creer_image();
	p->w = src->w;
	p->h = src->h;
	p->path = strdup(src->path);
	p->buff=malloc(sizeof(unsigned char)*p->w*p->h);
	memcpy(p->buff,src->buff,sizeof(unsigned char)*p->w*p->h);

	return p;
}

void detruire_image(image_t *p){
	if(p==NULL)
		return ;
	free(p->path);
	free(p->buff);
	free(p);
}
