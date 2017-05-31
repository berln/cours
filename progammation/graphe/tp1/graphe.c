#include <stdio.h>
#include <stdlib.h>


typedef struct {
 
    int nb_sommets;
    int ** Matrice;

} *MatAdja; 

typedef struct sommett{
 
    int numero;
    int date_debut;
    int date_fin;
    int CompConnexe;


} Sommet; 




MatAdja MatAdjaVide(int n){

  MatAdja A;
   int i,j;

   A = (MatAdja)malloc( sizeof(MatAdja));
 
   A->nb_sommets = n;

   A->Matrice = (int**)malloc( n * sizeof(int*));

   for(i=0;i<n;i++){
      A->Matrice[i]=(int*)malloc( n * sizeof(int));
   }

   for(i=0;i<n;i++){
      for(j=0;j<n;j++){
         A->Matrice[i][j] = 0;
      }
   }

   return A;   
}

void AfficheMatAdja(MatAdja A){
 int i,j;
 for(i=0;i < A->nb_sommets;i++){

       for(j=0;j < A->nb_sommets;j++){
           printf("%d ",A->Matrice[i][j]);
       }
       printf("\n");
    }
}

MatAdja LireGraphe(const char *nom){

    MatAdja mat;
    FILE *file = fopen(nom, "r");
    int NbSom,extIni,extFin;
    
    fscanf(file,"%d",&NbSom);

    mat = MatAdjaVide(NbSom);

    while(fscanf(file,"%d %d", &extIni,&extFin) != EOF ){

       mat->Matrice[extIni][extFin] = 1;

    }



    return mat; 


}



MatAdja Transpose(MatAdja A){


   int n,i,j;
   n = A->nb_sommets;
   MatAdja temp = MatAdjaVide(n);

   for(i=0;i<n;i++){

      for(j=0;j<n;j++){
       
        temp->Matrice[i][j] = A->Matrice[j][i];     
 
      }

   }

   return  temp;
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

Sommet *Trier(Sommet *S,int n){

  int i,j;
   Sommet STemp;
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

Sommet * Parcours_Profondeur_Trans(MatAdja A, Sommet *S){
 
     Sommet * temp = (Sommet*)malloc(A->nb_sommets*sizeof(Sommet));
      
     int i,j=0;
     int date= 0;
 
     for(i=0;i<A->nb_sommets;i++){
           temp[i].numero=S[i].numero;
           temp[i].date_debut=0;
           temp[i].date_fin=0;
           temp[i].CompConnexe=0;
     }
 
     for(i=0;i<A->nb_sommets;i++){
 
           if(temp[i].date_debut==0){
                profondeur(Transpose(A), temp, &date, temp[i].numero);
               j++;
           }
           S[i].CompConnexe=j;
     }
 
 
     return S;
}


int CompFortementConnexes(MatAdja A, int * B){ 
     int i,nbgroup=0;
     Sommet *S;
     S = Parcours_Pronfondeur(A); 
     S = Parcours_Profondeur_Trans(A,Trier(S,A->nb_sommets)); 
     for(i=0;i<A->nb_sommets;i++){ 
           B[S[i].numero]=S[i].CompConnexe;    
           if(nbgroup < S[i].CompConnexe){
              nbgroup =S[i].CompConnexe;
           }
     }
     return nbgroup;
}

int main(int argc, char ** argv){
  int B[8];
   
   MatAdja mat1,mat2,mat3;

   printf("TEST 1 affiche vide 1\n");
   mat1 = MatAdjaVide(8);
AfficheMatAdja(mat1);
   printf("\n");

   printf("TEST 2 lire fichier \n");
mat2=LireGraphe("graphe1.txt");
AfficheMatAdja(mat2);

   printf("TEST 3 transpose de ^ \n");
mat3=Transpose(mat2);
AfficheMatAdja(mat3);

printf("TEST 4 affiche sommet graphe ^ \n");
Sommet *s;

s=Parcours_Pronfondeur(mat2);
Affiche_Sommets(s,8);

printf("trie des sommets\n");
s=Trier(s,8);
Affiche_Sommets(s,8);

printf("compfotementconnex %d",CompFortementConnexes(mat2,B));

   printf("\n");

return 0;
}
