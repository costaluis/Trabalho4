#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct carta{
    char valor;
    char naipe;
    int pos;
    struct carta *prox;
}carta;

carta * criabaralho();
carta ** distribui(carta *, int *);
void ordena(carta **, int);
void compra(carta *, carta **, int);
