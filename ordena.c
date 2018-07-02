#include "Rummikub.h"

void ordena(carta ** A, int n){
	int i;
	int j;
	int k;
	carta temp;
	for(i=1;i<n;i++){
		for(j=0;j<50;j++){
			for(k=j+1;k<50;k++){
                if(A[i][j].valor!=0){
                    if(A[i][j].valor>A[i][k].valor){
                        temp = A[i][j];
                        A[i][j] = A[i][k];
                        A[i][k] = temp;
                    }
				}
			}
		}
	}
	
	for(k=0;k<n;k++){
		for(i=0;i<50;i++){
			if(A[k][i].valor==0){
				for(j=i+1;j<50;j++){
					if(A[k][j].valor!=0){
						temp = A[k][j];
						A[k][j] = A[k][i];
						A[k][i] = temp;
						break;
					}
				}
			}
		}
	}
}
