#include <stdio.h>
#define liste_vide NULL

typedef int type_elem;
typedef enum {FALSE, TRUE} booleen;

typedef struct ll {

type_elem e;

struct ll *suiv;

} type_liste ;

typedef type_liste *liste;

type_elem max_liste(liste L){
	int i;
	liste tmp;
	type_elem tmp_eleme;
	tmp=L;
	tmp_eleme=L -> e;
	while(L -> suiv != liste_vide){
		tmp=tmp -> suiv;
		if (tmp_eleme >= tmp -> suiv -> e)
			tmp_eleme = tmp -> suiv -> e;
	}
	return (tmp_eleme);
}

booleen est_dernier(liste L){
	if (L -> suiv == liste_vide)
		return TRUE;
	return FALSE;

}

type_elem Le_dernier (liste L){
	int i;
	liste tmp;
	tmp=L;
	while(L -> suiv != liste_vide)
		tmp=tmp -> suiv;
	return (tmp -> e);
}

int longueur(liste L){
	int i;
	while(L -> suiv != liste_vide){
		i ++;
		L=L->suiv;
	}
	return (i);
}

booleen recherche(type_elem X ,liste L){
	while(L -> suiv != liste_vide){
		if (L->e==X)
			return TRUE;
		L=L->suiv;
		}
	return FALSE;
}

void afficher(liste L){
	while(L -> suiv != liste_vide){
		L=L->suiv;
		printf("%d\n",L->e );
	}
}


type_elem kieme(liste L, int k){
	for (int i = 0; i < k; ++i)
	{
		if (L->suiv==liste_vide)
			return -1;
		L=L->suiv;
	}
	return L->suiv->e;
}

int ieme(liste L, type_elem E){
	int i;
	i=0;
	while(L -> suiv != liste_vide){
		if (L->e==E)
			return i;
		i++;
		L=L->suiv;
	}
	return -1;
}

void  ajoutAukieme(liste  *L, int k, type_eleme){
	int i;
	liste tmp;
	for (int i = 0; i < k; ++i)
	{
		if(L->suiv==liste_vide)
			exit;
		L=L->suiv;
	}
	tmp =malloc(sizeof(liste));
	if (tmp=liste_vide)
		exit;
	tmp->suic=L->suiv;
	L->suiv=tmp;
}

void  supprime_debut(liste  *L){
	L=L->suiv;
	free(L);
}

void ajout_fin(liste *L, typeElem X){
	liste tmp;
	while(L -> suiv != liste_vide){
		L=L->suiv;
	}
	tmp=malloc(sizeof(liste));
	tmp->suiv=liste_vide;
	L->suive=tmp;
}
void catenate(liste *L1, liste *L2){
	liste tmp;
	tmp=L1;
	if(L1==liste_vide||L2==liste_vide)
		return;
	while(L1->suive!=liste_vide){
		L1=L1->suive;
	}
	L1->suive=L2;
}
void couper(liste *L1, liste*L2,liste *L3){

}

int main(int argc, char const *argv[])
{
	liste L;
	L=malloc(sizeof(liste));
	L->suiv=liste_vide;
	afficher(L);
	return 0;
}
