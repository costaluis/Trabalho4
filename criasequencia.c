#include "Rummikub.h"

void criasequencia(int v,carta ** Vetores, carta ** Grupos){
	int n;
	int i;
	int c=0;
	printf("Insira quantas cartas formarao a sequencia: ");	
	scanf("%d",&n);
	int A[n];
	printf("Insira as posicoes das cartas: ");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}

	carta Valores[n];

	for(i=0;i<n;i++){
		if(Vetores[v][A[i]-1].valor>='A'&& Vetores[v][A[i]-1].valor <='D'){
			Valores[i].valor = (Vetores[v][A[i]-1].valor) - 'A' + '0';
			Valores[i].naipe - 
		}
	}

	for(i=0;i<n-1;i++){
		if(Vetores[v][A[i]-1]==Vetores[v][A[i+1]-1]){
			c++;
		}
	}

	if(c!=n-1){

	}
}