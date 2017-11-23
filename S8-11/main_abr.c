#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "abr.h"

int main(int argc, char **argv)
{
	Lm_mot *l = lire_dico_Lmot("french_za");
  	Nd_mot *a = Lm2abr(l);
	puts(a -> mot);
	a = a -> d;
	puts(a -> mot);
  /* A completer */

  return 0;
}
