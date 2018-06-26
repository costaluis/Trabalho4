#include "Rummikub.h"

int main(int argc, char const *argv[])
{
	int n;
	int i;
	int v; //Vez do jogar, preciso criar uma função pra ir mudando esse valor
	carta * Baralho = criabaralho();
	carta ** Maos = distribui(Baralho,&n);
	carta ** Grupos = calloc(35,sizeof(carta*));
	ordena(Maos,n);



	return 0;
}
