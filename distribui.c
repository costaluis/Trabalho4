#include "Rummikub.h"

carta ** distribui(carta *A, int *n){
	int i;
	int j;
	int k=0;
	printf("Insira o numero de jogadores: ");
	scanf("%d",n);
	(*n)++;
	carta * * maos = calloc(*n,sizeof(carta*));
	for(i=0;i<*n;i++){
		maos[i] = calloc(50,sizeof(carta));
	}
	for(i=0;i<14;i++){
		for(j=1;j<*n;j++){
			maos[j][i] = A[k];
			A[k].valor = 0;
			A[k].naipe = 0;
			k++;
		}
	}
	return maos;
}