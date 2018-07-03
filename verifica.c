#include "Rummikub.h"

int verifica(carta ** Vetores, int v,carta * Baralho, int n,int*p){
	int i,j;
	int c=0;
	int t=0;
	for(i=0;i<106;i++){
		if(Baralho[i].valor!=0){
			t++;
		}
	}
	if(t==0){
		int A[n];
		for(i=0;i<n;i++){
			A[i] = 0;
		}
		for(i=1;i<n;i++){
			for(j=0;j<50;j++){
				if(Vetores[i][j].valor!=0){
					if(Vetores[i][j].valor=='*'){
						A[i] += 20;
					}else{
						if(Vetores[i][j].valor>='A' && Vetores[i][j].valor<='D'){
							A[i] += Vetores[i][j].valor-'A'+10;
						}else{
							A[i] += Vetores[i][j].valor-'0';
						}
					}
				}
			}
		}
		j = A[1];
		for(i=1;i<n-1;i++){
			if(j>A[i]){
				j = A[i];
				*p = i;
			}
		}
		return 2;
	}
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
