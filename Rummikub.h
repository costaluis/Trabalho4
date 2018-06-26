#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct{
    char valor;
    char naipe;
    int pos;
}carta;

carta * criabaralho();
carta ** distribui(carta *, int *);
void ordena(carta **, int);
void compra(carta *, carta **, int);