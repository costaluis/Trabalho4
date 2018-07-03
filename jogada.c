#include "Rummikub.h"

void jogada(carta ** Vetores,carta *Baralho,carta ** Grupos,int v,int n){
    int o;
    int f=1;
    carta * Card;
    int i;
    system("clear");
    while(1){
    system("clear");
    ordena(Vetores,n);
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
    printf("[4 - Trocar Carta por Coringa]\n");
    if(f){
        printf("[5 - Comprar Carta]\n");
    }else{
        printf("[5 - Pular a vez]\n");
    }

    scanf("%d",&o);

    switch(o){
    case 1:
        criagrupo(v,Vetores,Grupos,&f);
        pausa();
        break;
    case 2:
        criasequencia(v,Vetores,Grupos,&f);
        pausa();
        break;
    case 3:
        inserecarta(Vetores,v,Grupos,&f);
        pausa();
        break;
    case 4:
        troca(Vetores,Grupos,v,&f);
        pausa();
        break;
    case 5:
        if(f){
            compra(Baralho,Vetores,v);
            return;
        }else{
            return;
        }
        break;
    default:
        printf("Valor invalido\n");
        break;
    }
}
}
