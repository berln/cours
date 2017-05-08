#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_Date{
   int jour,mois,annee;
} t_Date;

typedef struct t_Identite{
	char nom[10];
    char prenom[10];
} t_Identite;


int cmpIdentites( t_Date id1, t_Date id2){
if(id1.jour==id2.jour && id1.mois==id2.mois)
return 0;
return -1;
 }


int main(int argc, char const *argv[])
{
	t_Date lol;
	t_Date lal;

		int result;

	lol.jour=10;
	lol.mois=2;
	lol.annee=2017;

	
	lol.jour=10;
	lol.mois=2;
	lol.annee=2017;


	printf("%d\n",cmpIdentites(lol,lal));

	return 0;
}