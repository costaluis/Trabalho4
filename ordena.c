#include "Rummikub.h"

void ordena(carta ** A, int n){
	int i;
	int j;
	int k;
	carta temp;
	for(i=0;i<n;i++){
		for(j=0;j<50;j++){
			for(k=j+1;k<50;k++){
				if(A[i][j].valor>A[i][k].valor){
					temp = A[i][j];
					A[i][j] = A[i][k];
					A[i][k] = temp;
				}
			}
		}
	}	
}