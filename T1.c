#include "Rummikub.h"

carta * criabaralho(){

carta *Baralho = (carta *) calloc(106, sizeof(carta));

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
for(i=0;i<106;i++){
}
return Baralho;
}
