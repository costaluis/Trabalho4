#include "Rummikub.h"

void troca(carta ** Vetores,carta ** Grupos,int v){
	int p,g;
	carta temp;
	carta * Percorre;
	printf("Digite a posicao da carta que deseja trocar: ");
	scanf("%d",&p);
	p--;
	printf("Digite a posicao do grupo ou sequencia com o curinga: ");
	scanf("%d",&g);
	g--;
	Percorre = Grupos[g];
	if(Percorre->valor==Percorre->prox->valor){
		while(Percorre!=NULL){
			if(Percorre->naipe==Vetores[v][p].naipe){
				printf("Carta invalida\n");
				return;
			}
			Percorre = Percorre->prox;
		}
		Percorre = Grupos[g];
		if(Vetores[v][p].valor!=Percorre->valor){
			printf("Carta invalida\n");
			return;
		}
		while(Percorre->valor!='*'){
			Percorre = Percorre->prox;
		}
		temp = *Percorre;
		*Percorre = Vetores[v][p];
		Vetores[v][p] = temp;
	}else{
		if(Percorre->naipe!=Vetores[v][p].naipe){
			printf("Carta invalida\n");
			return;
		}
		while(Percorre->prox->valor!='*'){
			Percorre = Percorre->prox;
		}
		if(Percorre->valor+1!=Vetores[v][p].valor || Vetores[v][p].valor!=Percorre->prox->prox->valor-1){
			printf("Carta invalida\n");
			return;
		}
		Percorre = Percorre->prox;
		temp = *Percorre;
		*Percorre = Vetores[v][p];
		Vetores[v][p] = temp;
	}
}