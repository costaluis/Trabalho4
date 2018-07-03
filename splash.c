#include "Rummikub.h"

void splash()
{
	__fpurge(stdin);
	system("clear");
	FILE *Arq;
	char imagem[96];
	Arq=fopen("imagem.txt","rt");
	while(fgets(imagem,sizeof(imagem),Arq)!=NULL)
	{
		printf("%s",imagem);
	}
	sleep(4);
	printf("\n");
	fclose(Arq);
	system("clear");
}