#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include <time.h>

int main(int argc, char **argv){
	if (argc < 3){
		fprintf(stderr, "???? pas de nb de répétition ou de mot cherché\n");
		return 1;
	}
	int i = atoi(argv[2]);
	char* mot = argv[1];
	Lm_mot *l = lire_dico_Lmot("french_za");
	puts( chercher_Lm_mot(l, mot) ? "oui trouvé\n" : "non trouvé\n");
	time_t b, e;
	time(&b);
	while(i--)
		chercher_Lm_mot(l, mot);
	time(&e);
	printf("temps écoulé: %ld seconde(s)\n", e - b);

	
  return 0;
}
