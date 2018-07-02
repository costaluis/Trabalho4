#include "Rummikub.h"

void criagrupo(int v,carta ** Vetores, carta ** Grupos){
    int n;
    int i;
    int j;
    int B[4];
    int c=0;
    int d=0;
    printf("Insira quantas cartas formarao o grupo: ");
    scanf("%d",&n);
    int A[n];
    printf("Insira as posicoes das cartas: ");
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    carta Valores[n];
    for(i=0;i<n;i++){
        Valores[i] = Vetores[v][A[i]-1];
    }

    for(i=0;i<4;i++){
        B[i] = 0;
    }

    for(i=0;i<n;i++){
        if(Valores[i].naipe=='@'){
            B[0] = 1;
        }else{
            if(Valores[i].naipe=='$'){
                B[1] = 1;
            }else{
                if(Valores[i].naipe=='!'){
                    B[2] = 1;
                }else{
                    if(Valores[i].naipe=='#'){
                        B[3] = 1;
                    }
                }
            }
        }
    }

    for(i=0;i<n;i++){
        if(i==0){
            if(Valores[i].valor=='*'){
                if(Valores[i+1].valor!='*'){
                    Valores[i].valor = Valores[i+1].valor;
                }else{
                    Valores[i].valor = Valores[i+2].valor;
                }
            }
        }else{
            if(i==n-1){
                if(Valores[i].valor=='*'){
                    Valores[i].valor = Valores[i-1].valor;
                }
            }else{
                if(Valores[i].valor=='*'){
                    Valores[i].valor = Valores[i-1].valor;
                }
            }
        }
    }

    for(i=0;i<n;i++){
        if(Valores[i].naipe=='*'){
            for(j=0;j<4;j++){
                if(B[j]==0){
                    if(j==0){
                        Valores[i].naipe = '@';
                        B[j] = 1;
                    }else{
                        if(j==1){
                            Valores[i].naipe = '$';
                            B[j] = 1;
                        }else{
                            if(j==2){
                                Valores[i].naipe = '!';
                                B[j] = 1;
                            }else{
                                Valores[i].naipe = '#';
                                B[j] = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(Valores[i].valor!=Valores[j].valor){
                printf("Os valores sao diferentes\n");
                return;
            }
        }
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
