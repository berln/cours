#include <stdio.h>
#include <stdlib.h>


typedef struct {
 
    int nb_sommets;
    int ** Matrice;

} *MatAdja; 

typedef struct {
    int nb_sommets;
    int ** Matrice;
    int nb_aretes;
} *MatIncid;

typedef struct sommett{
 
    int numero;
    int date_debut;
    int date_fin;
    int CompConnexe;


} Sommet; 




MatIncid MatIncidVide(int n,int m){

  MatIncid A;
   int i,j;

   A = (MatIncid)malloc( sizeof(MatIncid));
 
   A->nb_sommets = n;
   A->nb_aretes = m;

   A->Matrice = (int**)malloc( n * sizeof(int*));

   for(i=0;i<n;i++){
      A->Matrice[i]=(int*)malloc( m * sizeof(int));
   }

   for(i=0;i<n;i++){
      for(j=0;j<m;j++){
         A->Matrice[i][j] = 0;
      }
   }

   return A;   
}

void AfficheMatIncid(MatIncid A){
 int i,j;
 for(i=0;i < A->nb_sommets;i++){

       for(j=0;j < A->nb_aretes;j++){
           printf("%d ",A->Matrice[i][j]);
       }
       printf("\n");
    }
}

void SuprimmerMatIncid(MatIncid A){
  int i,J;
  for (int i = 0; i < A->nb_sommets ++i)
  {
    for (int j = 0; j < A->nb_aretes; ++j)
    {
      free(A->Matrice[i][j]);
    }
    free(A->MatIncid[i]);
  }
  free(A);
}

MatIncid LireGraphe(const char *nom){

    MatIncid mat;
    FILE *file = fopen(nom, "r");
    int NbSom,extIni,extFin;
    
    fscanf(file,"%d",&NbSom);

    mat = MatIncidVide(NbSom,0);

    while(fscanf(file,"%d %d", &extIni,&extFin) != EOF ){

       mat->Matrice[extIni][extFin] = 1;

    }



    return mat; 


}



MatIncid Transpose(MatIncid A){


   int n,i,j;
   n = A->nb_sommets;
   MatIncid tmp = MatIncidVide(n,0);

   for(i=0;i<n;i++){

      for(j=0;j<n;j++){
       
        tmp->Matrice[i][j] = A->Matrice[j][i];     
 
      }

   }

   return  tmp;
}

void profondeur(MatAdja A, Sommet * S, int * date, int numSommet){

     int i, n;
     n = A->nb_sommets;
     *date=*date+1;
     S[numSommet].date_debut= *date;

      for(i=0;i < n;i++ ){

          if((S[i].date_debut == 0 )&& (A->Matrice[numSommet][i]!=0) ){
             profondeur(A, S, date, i);
          }
          
      }

     *date=*date+1;
      S[numSommet].date_fin = *date;
}



Sommet * Parcours_Pronfondeur(MatAdja A){

    int i,n;
    n = A->nb_sommets;

    int date1 = 0;

    Sommet *sommet = (Sommet*)malloc(n * sizeof(Sommet));


    for(i=0;i < n;i++){
      sommet[i].numero = i;
      sommet[i].date_debut = 0;
      sommet[i].date_fin = 0;
    }


    for(i=0;i < n;i++){
      if(sommet[i].date_debut == 0){
         profondeur(A, sommet, &date1, sommet[i].numero);
      }
    }


    return sommet;

}

void Affiche_Sommets(Sommet *S , int n){
int i;
    for(i=0;i<n;i++)
	{
	printf("Sommet : %d ; Date debut %d ; Date fin %d \n",S[i].numero,S[i].date_debut,S[i].date_fin);
	}
}

/*
Sommet *Trier(Sommet *S,int n){


int i,j,current_value;
current_value=0;
int *tmp1;

    for(i=0;i<n;i++)
	{
	
	current_value=S[i].date_fin;
        for(j=0;j<n;j++){

	     if(S[j].date_fin>=S[current_value].date_fin)
		current_value=j;
	}
	tmp1=S[i];
	S[i]=S[current_value];
	S[current_value]=*tmp1;

//printf("%d\n",tmp1->date_fin);
	}

return tmp;
}

*/

int main(int argc, char ** argv){
   
   MatIncid mat1;

   printf("TEST 1 affiche vide 1\n");
   mat1 = MatIncidVide(3,7);
AfficheMatIncid(mat1);
   printf("\n");
/*
   printf("TEST 2 lire fichier \n");
mat2=LireGraphe("graphe1.txt");
AfficheMatAdja(mat2);

   printf("TEST 3 transpose de ^ \n");
mat3=Transpose(mat2);
AfficheMatAdja(mat3);

printf("TEST 4 affiche sommet graphe ^ \n");
Sommet *s;
int date=0;

s=Parcours_Pronfondeur(mat2);
Affiche_Sommets(s,8);

/*trie marche pas le probleme est qu'il faut verifier que la valeur  lue n'est pas déjà dans le sommet final  
printf("trie ^ \n");
s=Trier(s,8);
Affiche_Sommets(s,8);
*/

   printf("\n");

return 0;
}