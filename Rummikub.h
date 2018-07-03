#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdio_ext.h>

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
int verifica(carta**,int);
void inserecarta(carta**,int,carta**,int*);
void troca(carta**,carta**,int,int*);
void jogada(carta**,carta*,carta**,int,int);
void criasequencia(int,carta**,carta**,int*);
void criagrupo(int,carta**,carta**,int*);
void pausa();