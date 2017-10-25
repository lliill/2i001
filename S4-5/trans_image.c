#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"
#include "noyau.h"

#define VAL(img,i,j)(img)->buff[(i)*(img)->w+(j)]

image_t *negatif(image_t *src)
        {
        image_t *dst;
        int i;
        if(src==NULL)return NULL;
        dst=creer_image();
        dst=copier_image(src);
        for(i=0;i<(src->h*src->w);i++){
                dst->buff[i]=255-src->buff[i];
        }
        return dst;
        }


image_t *rotation(image_t *src, int angle)
        {
                image_t*dst;
                int i,j;
                if(src==NULL)return NULL;
                angle=angle%360;
                if(angle%90)return NULL;
                dst=copier_image(src);
                if(angle==90){
                        dst->h=src->w;
                        dst->w=src->h;
                        for(i=0;i<dst->h;i++){
                                for(j=0;j<dst->w;j++){
                                        VAL(dst,i,j)=VAL(src,j,src->w-i-1);
                                }
                        }
                }                
		if(angle==180){
                        for(i=0;i<src->h;i++){
                                for(j=0;j<src->w;j++){
                                        VAL(dst,i,j)=VAL(src,src->h-i-1,src->w-j-1);
                                }
                        }
                }
                if(angle==270){
                        dst->h=src->w;
                        dst->w=src->h;
                        for(i=0;i<dst->h;i++){
                                for(j=0;j<dst->w;j++){
                                        VAL(dst,i,j)=VAL(src,src->h-j-1,i);
                                }
                        }
                }

        return dst;
        }



image_t *modifier_lumin(image_t *src, int pourcent)
        {
		if(pourcent<0)
			return NULL;
                image_t*dst;
                int i,l;
                dst=copier_image(src);
                if(pourcent == 100)
                        return dst;
                for(i=0;i<(src->h*src->w);i++){
                        l=(src->buff[i]*pourcent)/100;

/*                        if(l<0){
                                l=0;
                        }
*/
                        if(l>255){
                                l=255;
                        }
                        dst->buff[i]=l;
                }

        return dst;
        }



image_t *bruiter_image(image_t *src, int pourcent)
	{
	return NULL;
	}

image_t *filtrer_median(image_t *src)
	{
	return NULL;
	}

image_t *convoluer(image_t *src, noyau_t *pn){
        image_t* res = copier_image(src);
        int ligne, colonne;

        //calcul de valeur de normalisation
        int normalisation=0;
        for(ligne = 0; ligne < pn->dim; ligne++)
                for(colonne = 0; colonne < pn->dim; colonne++)	
                        normalisation += *(pn->coeffs + (ligne*pn->dim) + colonne );
        if(normalisation==0)
                normalisation = 1;	

        return NULL;
}
