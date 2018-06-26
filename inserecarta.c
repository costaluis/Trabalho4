#include "Rummikub.h"

void inserecarta(carta ** Vetores, int v, carta ** Grupos){
	int c;
	int f=0;
	int g;
	int r;
	int i;
	int B[4];

	for(i=0;i<4;i++){
		B[i] = 0;
	}

	printf("Deseja inserir em um grupo ou sequencia? (0/1)\n");
	scanf("%d",&r);

	if(r==0){
		printf("Digite o indice da carta a ser inserida: ");
		scanf("%d",&c);
		c--;
		printf("Digite o indice do grupo em que a carta sera inserida: ");
		scanf("%d",&g);
		g--;

		if(Vetores[v][c].valor==(*(Grupos[g])).valor){
			carta * Percorre = Grupos[g];
			while(Percorre!=NULL){
				if(Percorre->naipe == '@'){
					B[0] = 1;
				}else{
					if(Percorre->naipe == '!'){
						B[1] = 1;
					}else{
						if(Percorre->naipe == '$'){
							B[2] = 1;
						}else{
							B[3] = 1;
						}
					}
				}
				Percorre = Percorre->prox;
			}
			if(Vetores[v][c].naipe=='@'){
				if(B[0]==1){
					printf("Naipe ja utilizado\n");
					return;
				}
			}else{
				if(Vetores[v][c].naipe=='!'){
					if(B[1]==1){
						printf("Naipe ja utilizado\n");
						return;
					}
				}else{
					if(Vetores[v][c].naipe=='$'){
						if(B[2]==1){
							printf("Naipe ja utilizado\n");
							return;
						}
					}else{
						if(B[3]==1){
							printf("Naipe ja utilizado\n");
							return;
						}
					}
				}
			}
		}else{
			printf("A carta nao possui o mesmo valor\n");
			return;
		}
		for(i=0;i<50;i++){
			if(Vetores[0][i].valor==0){
				Vetores[0][i] = Vetores[v][c];
				Vetores[v][c].valor = 0;
				Vetores[v][c].naipe = 0;
				break;
			}
		}
		Percorre = Grupos[g];
		while(Percorre!=NULL){
			if(Percorre->prox==NULL){
				Percorre->prox = &Vetores[0][i];
				break;
			}
		}
	}else{
		if(r==1){
			carta * Percorre;
			printf("Digite o indice da carta a ser inserida: ");
			scanf("%d",&c);
			c--;
			printf("Digite o indice da sequencia em que a carta sera inserida: ");
			scanf("%d",&g);
			g--;
			if(Grupos[g]->valor=='*'){
				if(Vetores[v][c].valor==Grupos[g]->valor-2){
					f = 1;
				}
			}else{
				if(Vetores[v][c].valor==Grupos[g]->valor-1){
					f = 2;
				}else{
					Percorre = Grupos[g];
					while(Percorre->prox!=NULL){
						Percorre = Percorre->prox;
					}
					if(*(Percorre).valor=='*'){
						if(Vetores[v][c].valor==*(Percorre).valor+2){
							f = 3;
						}
					}else{
						if(Vetores[v][c].valor==*(Percorre).valor+1){
							f = 4;
						}
					}
				}
			}
			if(f==0){
				printf("Carta escolhida nao eh valida\n");
				return;
			}
			for(i=0;i<50;i++){
				if(Vetores[0][i].valor==0){
					Vetores[0][i] = Vetores[v][c];
					Vetores[v][c].valor = 0;
					Vetores[v][c].naipe = 0;
					if(f==1 || f==2){
						Vetores[0][i].prox = Grupos[g];
						Grupos[g] = &Vetores[0][i];
					}else{
						Percorre = Grupos[g];
						while(Percorre->prox!=NULL){
							Percorre = Percorre->prox;
						}
						Percorre->prox = &Vetores[0][i];
					}
					break;
				}
			}
		}else{
			printf("Valor Invalido\n");
			return;
		}
	}
}