#include <stdio.h>
#include <errno.h>
#include <unistd.h>

main(int argc, char *argv[]) 
{
	int T_descripteur[2];
	char buffer_1[25];
	char buffer_2[100];
	int i,y;
	int retour1;
	int retour2;

	for(i=0;i<25;i++)
	{
		buffer_1[i]='a';
	}
	

	pipe(T_descripteur);

	printf("\n- DEBUT -\n");

	for (i=0;i<8;i++)
	{
		retour1 = write(T_descripteur[1], buffer_1, 25);
		if (retour1 == -1 )
		{
			printf("\nerreurs\n");
		}
		else printf("\nnombre de caracteres ecrit : %d\n",retour1);

		for(y=0;y<25;y++)
		{
			printf("%c", buffer_1[y]);
		}
	}


	for (i=0;i<2;i++)
	{
		retour2 = read(T_descripteur[0], buffer_2, 100);
		if (retour2 == -1 )
		{
			printf("\nerreurs\n");
		}
		else printf("\nnombre de caracteres lus : %d\n",retour2);

		for(y=0;y<100;y++)
		{
			printf("%c", buffer_2[y]);
		}

	}
	
	printf("\n- FIN -\n");

}