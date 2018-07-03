#include "Rummikub.h"

carta * criabaralho(){

carta *Baralho = (carta *) calloc(106, sizeof(carta));

int v;

printf("Voce deseja jogar com:\n");
printf("1 - Baralho aleatorio\n");
printf("2 - Baralho pre-definido(Arquivo)\n");
scanf("%d",&v);

if(v==1){

    srand(time(NULL));

    char valores[14] = {'1','2','3','4','5','6','7','8','9','A','B','C','D','*'};
    char naipes[5] = {'#','!','@','$','*'};

    int i=0, j, k, r, c;

    while(i<106){
        j = rand() % 14;
        if(j!=13){
            k = rand() % 4;
        }else{
            k = 4;
        }
        c = 0;
        for(r=0;r<106;r++){
            if(Baralho[r].valor==valores[j] && Baralho[r].naipe==naipes[k]){
                c++;
            }
        }
        if(c>=2){continue;}

        Baralho[i].valor = valores[j];
        Baralho[i].naipe = naipes[k];
        i++;
    }
    return Baralho;
    }else{
        if(v==2){
            int i;
            char carta[3];
            char nome[20];
            FILE * Arq;
            printf("Insira o nome do arquivo a ser lido: ");
            scanf("%s",nome);
            Arq = fopen(nome,"rt");
            if(Arq==NULL){
                printf("Arquivo nao encontrado\n");
                return NULL;
            }
            for(i=0;i<106;i++){
                fscanf(Arq,"%s",carta);
                Baralho[i].valor = carta[0];
                Baralho[i].naipe = carta[1];
            }
            fclose(Arq);
            return Baralho;
        }else{
            printf("Valor invalido\n");
            return NULL;
        }
    }
}
