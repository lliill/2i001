#include "score.h"
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	Score t[10];
	int i;
	initialiserTableauScores(t, 10);

	for(i=0; i < 10; i++)
		afficherScore(t[i]);
	
	return 0;
}
