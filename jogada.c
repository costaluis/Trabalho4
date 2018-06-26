#include "Rummikub.h"

void jogada(carta ** Vetores,carta *Baralho,carta ** Grupos,int v,int n){
    system("cls");
    int o;
    carta * Card;
    int i;
    printf("Mesa:\n");
    for(i=0;i<35;i++){
        if(Grupos[i]!=NULL){
            Card = Grupos[i];
            printf("Grupo %d: ",i+1);
            while(Card!=NULL){
                printf("%c%c ",Card->valor,Card->naipe);
                Card = Card->prox;
            }
            printf("\n");
        }
    }
    printf("Jogador %d\n",v);
    for(i=0;i<50;i++){
        if(Vetores[v][i].valor!=0){
            printf("%d-[%c%c] ",i+1,Vetores[v][i].valor,Vetores[v][i].naipe);
        }
    }
    printf("\n");
    printf("Escolha sua opcao:\n");
    printf("[1 - Criar Grupo]\n");
    printf("[2 - Criar Sequencia]\n");
    printf("[3 - Inserir Carta em Grupo/Sequencia]\n");
    printf("[4 - Comprar Carta]\n");

    scanf("%d",&o);

    switch(o){
    case 1:
        printf("Insira os valores");
    }




}
