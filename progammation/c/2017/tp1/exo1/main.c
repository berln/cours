#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*http://perso.esiee.fr/~djebalia/e4fr/TP4/TP1-IN4R11.pdf*/


typedef struct t_Date{
   int jour,mois,annee;
} t_Date;
typedef struct t_Identite{
   char nom[10];
    char prenom[10];

} t_Identite;
typedef struct t_Adresse{
   int codePostal;
   char ville[10];
} t_Adresse;


typedef struct  t_Eleve{
   t_Identite id;
   t_Date naiss;
}  t_Eleve;

typedef struct  Annuaire{
   t_Eleve ** tabeleve;
   int cpt;
}  Annuaire;

int cmpDates( t_Date d1, t_Date d2){
if(d1.jour==d2.jour && d1.mois==d2.mois && d1.annee==d2.annee)
return 0;
return -1;
}

int cmpIdentites( t_Identite id1, t_Identite id2){
if(strcmp(id1.nom,id2.nom)==0 &&strcmp(id1.prenom,id2.prenom)==0 )
return 0;
return -1;
 }

int cmpAdresses(t_Adresse ad1, t_Adresse ad2) {
if(ad1.codePostal && ad2.codePostal==0 &&strcmp(ad1.ville,ad2.ville)==0)
return 0;
return -1;

}

t_Eleve* saisie_Elebe(Annuaire pone, t_Eleve * peleve){
	int i;
	LOL=malloc(sizeof(t_Eleve));
	t_Eleve *LOL;
	for (i=0; pone.cpt < i; i++)
	  {
	  	if (pone.tabeleve[i] ==NULL){
	  		
	  		}
	  }  
}

Annuaire* init_struct(){
	Annuaire *plop;
	plop=malloc(sizeof(Annuaire));
	plop -> cpt=10;
	plop -> tabeleve= calloc(plop -> cpt*sizeof (t_Eleve*));
	return plop;
}

int main(int argc, char ** argv)
{

return 0;

}