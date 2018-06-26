#include "Rummikub.h"

void compra(carta * A, carta ** B, int v){
	int i;
	int j;
	for(i=0;i<106;i++){
		if(A[i].valor!=0){
			for(j=0;j<50;j++){
				if(B[v][j].valor==0){
					B[v][j] = A[i];
					A[i].valor = 0;
					A[i].naipe = 0;
					break;
				}
			}
			break;
		}
	}
}