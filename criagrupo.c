#include "Rummikub.h"

void criagrupo(int v,carta ** Vetores, carta ** Grupos){
    int n;
    int i;
    int j;
    int c=0;
    int d=0;
    printf("Insira quantas cartas formarao o grupo: ");
    scanf("%d",&n);
    int A[n];
    printf("Insira as posicoes das cartas: ");
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<n-1;i++){
        if(Vetores[v][A[i]-1].valor==Vetores[v][A[i+1]-1].valor){
            c++;
        }
    }
    if(c!=(n-1)){
        printf("Os valores nao sao iguais.");
        return;
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(Vetores[v][A[i]-1].naipe==Vetores[v][A[j]-1].naipe){
                d++;
            }
        }
    }

    if(d!=0){
        printf("Os naipes devem ser diferentes");
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
