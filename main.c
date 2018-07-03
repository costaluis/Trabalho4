#include "Rummikub.h"

int main(int argc, char const *argv[])
{
	splash();
	int n;
	int v=1;
	int t;
	int p=1;
	carta * Baralho = criabaralho();
	carta ** Maos = distribui(Baralho,&n);
	carta ** Grupos = calloc(35,sizeof(carta*));
	while(1){
		jogada(Maos,Baralho,Grupos,v,n);
		t = verifica(Maos,v,Baralho,n,&p);
		if(t==1){
			printf("Vitoria do jogador %d\n",v );
			return 1;
		}
		if(t==2){
			printf("Fim do Baralho\n");
			printf("Vitoria do jogador %d\n",p);
			return 1;
		}
		if(v+1==n){
			v=1;
		}else{
			v++;
		}
	}
	return 0;
}
