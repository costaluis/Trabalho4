#include "Rummikub.h"

void criasequencia(int v,carta ** Vetores, carta ** Grupos){
	int n;
	int j;
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
			Valores[i].valor = (Vetores[v][A[i]-1].valor) - 'A' + '0' + 10;
			Valores[i].naipe = Vetores[v][A[i]-1].naipe;
		}else{
			Valores[i] = Vetores[v][A[i]-1];
		}
	}

	for(i=0;i<n;i++){
		if(Valores[i].valor=='*'){
			if(i==0){
				if(Valores[i+1].valor=='*'){
					Valores[i+1].valor = Valores[i+2].valor-1;
					Valores[i+1].naipe = Valores[i+2].naipe;
				}
				Valores[i].valor = Valores[i+1].valor-1;
				Valores[i].naipe = Valores[i+1].naipe;
			}
			if(i==n-1){
				Valores[i].valor = Valores[i-1].valor+1;
				Valores[i].naipe = Valores[i-1].naipe;
			}
			if(i>0 && i<n-1){
				Valores[i].valor = Valores[i-1].valor+1;
				Valores[i].valor = Valores[i-1].valor+1;
			}
		}
	}

	for(i=0;i<n-1;i++){
		if(Valores[i].valor==(Valores[i+1].valor)+1){
			c++;
		}
	}

	if(c!=n-1){
		printf("Nao eh uma sequencia\n");
		return;
	}
	c=0;

	for(i=0;i<n-1;i++){
		if(Valores[i].naipe==Valores[i+1].naipe){
			c++;
		}
	}

	if(c!=n-1){
		printf("Os naipes sao diferentes\n");
		return;
	}

	for(i=0;i<50;i++){
        if(Vetores[0][i].valor==0){
            c = i;
            break;
        }
    }

    for(j=0;j<n;j++,i++){
        Vetores[0][i] = Vetores[v][A[j]-1];
        Vetores[v][A[j]-1].valor = 0;
        Vetores[v][A[j]-1].naipe = 0;
    }
    for(j=0;j<35;j++){
        if(Grupos[j]==NULL){
            break;
        }
    }
    Grupos[j] = &Vetores[0][c];
    for(;c<i;c++){
        Vetores[0][c].prox = &Vetores[0][c+1];
    }
}