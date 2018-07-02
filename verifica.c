#include "Rummikub.h"

int verifica(carta ** Vetores, int v){
	int i;
	int c=0;
	for(i=0;i<50;i++){
		if(Vetores[v][i].valor!=0){
			c++;
		}
	}
	if(c==0){
		return 1;
	}else{
		return 0;
	}
}
