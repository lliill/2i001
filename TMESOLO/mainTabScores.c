#include "score.h"

int main(){
	Score[10] t;
	int i;
	initialiserTableauScores(t, 10);

	for(i=0; i < 10; i++)
		afficherScore(t[i]);
	
	return 0;
}
