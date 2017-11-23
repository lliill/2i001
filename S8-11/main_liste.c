#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include <time.h>

int main(int argc, char **argv){
	if (argc < 3){
		fprintf(stderr, "???? pas de nb de répétition ou de mot cherché");
		return 1;
	}
	int i = atoi(argv[1]);
	char* mot = argv[2];
	Lm_mot *l = lire_dico_Lmot("french_za");
	time_t b, e;
	time(&b);
	while(i--)
		chercher_Lm_mot(l, mot);
	time(&e);
	printf("%ld\n", e - b);

	
  return 0;
}
