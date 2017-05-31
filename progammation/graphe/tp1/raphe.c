#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>


struct struct_MatAdja {
	int nb_sommets;
	int ** Matrice;
};
typedef struct struct_MatAdja * MatAdja;

struct S_Sommet{
	int numero;
	int date_debut;
	int date_fin;
	int CompConnexe;
};
typedef struct S_Sommet Sommet;

MatAdja MatAdjaVide(int n){
	int i,j,k;	
	
	MatAdja adjacence = (MatAdja) malloc (sizeof(struct struct_MatAdja));//Alloue la structure
	adjacence->Matrice= (int**) malloc (n*sizeof(int*)); //Alloue les lignes
	for(i=0;i<n;i++){
		adjacence->Matrice[i]=(int*)malloc (n*sizeof(int)); //Alloue les colonnes
	}
	adjacence->nb_sommets=n;
	for(k=0;k< n;k++){        //parcours les lignes
		for(j=0;j< n;j++){//parcours les colones
			adjacence->Matrice[k][j]=0;
		}
	}
	return adjacence;
}

void AfficheMatAdja(MatAdja A){
	int i,j;
	for(i=0;i< (A->nb_sommets);i++){        //parcours les lignes
		for(j=0;j< (A->nb_sommets);j++){//parcours les colonnes
			printf(" | %d",A->Matrice[i][j]);
		}
		printf(" |\n");
	}
}

MatAdja LireGraphe(char * NOM_GRAPH){
	FILE *fichier;
	int t,a,b,c;
	MatAdja graphe;

	if ((fichier = fopen (NOM_GRAPH, "r")) == NULL) 
		{perror ("svc: fopen ");}
	else {
	fscanf(fichier,"%d", &t ) ;//lit la premiere ligne 
	graphe=MatAdjaVide(t); // Crée une matrice d'adjacence avec t sommets
  		while ( fscanf(fichier,"%d %d %d", &a ,&b,&c ) != EOF ) {
			//a est l'extremité initiale
			//b est poids de l'arc
			//c est l'extrimité finale
 			graphe->Matrice[a][c]=b; 
  	  	}
    	fclose ( fichier );
	return graphe;
 	}
	return NULL;
}

MatAdja Transpose(MatAdja A){
	int i,j,a;
	MatAdja graphe;
	graphe=MatAdjaVide(A->nb_sommets);
	for(i=0;i< (A->nb_sommets);i++){        
		for(j=0;j< (A->nb_sommets);j++){
			if(A->Matrice[i][j]!=0){
				graphe->Matrice[j][i]=A->Matrice[i][j];
				A->Matrice[i][j]=0;
			}
		}
	}
	return graphe;
}

void profondeur(MatAdja A, Sommet * S, int* date, int numSommet){
	int i;
	*(date)=*(date)+1;
	S[numSommet].date_debut=*date;
	for(i=0;i<(A->nb_sommets);i++){
		if(A->Matrice[numSommet][i]!=0 && S[i].date_debut==0 ){
			profondeur(A,S,date,i);
		}
	}
	*date=*date+1;
	S[numSommet].date_fin=*date;
}

Sommet * Parcours_Profondeur(MatAdja A){
	int date,i,j;
	Sommet * Tab_Sommet=(Sommet*) malloc(sizeof(struct S_Sommet)*A->nb_sommets);
	for(i=0;i<(A->nb_sommets);i++){
		Tab_Sommet[i].date_debut=0;
		Tab_Sommet[i].date_fin=0;
		Tab_Sommet[i].numero=i;
	}
	date=0;
	for(j=0;j<(A->nb_sommets);j++){
		if(Tab_Sommet[j].date_debut==0){
			profondeur(A,Tab_Sommet,&date,j);
		}
	}
	return Tab_Sommet;
}

void Afficher_Sommets(Sommet* S,int n){
	int i;
	for(i=0;i<n;i++){
		printf("Sommet %d Date de debut %d, date de fin %d \n",S[i].numero,S[i].date_debut,S[i].date_fin);
	}
}

Sommet* Trier(Sommet* S,int n){
	int i,j;
	struct S_Sommet STemp;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(S[i].date_fin>S[j].date_fin){
			STemp=S[j];
			S[j]=S[i];
			S[i]=STemp;		
			}
		}
	}
	return S;
}

Sommet * Parcous_Profondeur_Trans(MatAdja A,Sommet* S){
	
}

int main(){
	int sommets=7;
	char * Nom_fichier="graphe1.txt";
	
	printf("Matrice Test 1 \n");
	MatAdja graphe1,graphe2,graphe3;
	graphe1=MatAdjaVide(sommets);
	AfficheMatAdja(graphe1);

	printf("Matrice Test 2 \n");
	graphe2=LireGraphe(Nom_fichier);
	AfficheMatAdja(graphe2);

	printf("Matrice Test 3 \n");
	graphe3=Transpose(graphe2);
	AfficheMatAdja(graphe3);
	
	printf("Matrice Test 4 \n");
	Sommet * S=(Sommet*) malloc(sizeof(struct S_Sommet)*graphe3->nb_sommets);
	S=Parcours_Profondeur(graphe3);
	Afficher_Sommets(S,8);

	printf("Test 5 \n");
	S=Trier(S,8);
	Afficher_Sommets(S,8);
	return 0;
}
