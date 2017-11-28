#include <stdlib.h>
#include <stdio.h>
#include "liste.h"
#include "abr.h"
#include <time.h>

int main(int argc, char **argv){
	if (argc < 3){
		fprintf(stderr, "???? pas de nb de répétition ou de mot cherché\n");
		return 1;
	}
	int i = atoi(argv[2]);
	char* mot = argv[1];
	Lm_mot *l = lire_dico_Lmot("french_za");
	Nd_mot *a = Lm2abr(l);
	/*
	puts(a -> mot);
	a = a -> d;
	puts(a -> mot);

	/* A completer */
	puts( chercher_Nd_mot(a, mot) ? "oui trouvé\n" : "non trouvé\n");

	time_t b, e;
	time(&b);
	while(i--)
		chercher_Nd_mot(a, mot);
	time(&e);
	printf("temps écoulé: %ld seconde(s)\n", e - b);

  return 0;
}
