#include <stdio.h>
#include <stdlib.h>
 
 
typedef struct {
  
    int nb_sommets;
    int nb_aretes;
    int ** Matrice;
 
} *MatIncid; 
 
 
 
 
MatIncid MatIncidVide(int n, int m){
 
   MatIncid A;
   int i,j;
 
   A = (MatIncid)malloc(sizeof(MatIncid));
  
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
           printf("%d\t",A->Matrice[i][j]);
       }
       printf("\n");
    }
 
}
 
 
MatIncid LireGraphe(const char *nom){
 
    FILE *in = fopen(nom, "r");
    int sommetNB,arretNB,extI,pArc,extF;
    int proid_prec=0, cmp=1;
 
    MatIncid mat;
     
  
    fscanf(in,"%d %d",&sommetNB,&arretNB);
 
    mat = MatIncidVide(sommetNB, arretNB);
 
    while(fscanf(in,"%d %d %d", &extI,&pArc,&extF) != EOF ){
 
       if(proid_prec > pArc){
           printf("Erreur ordre poid\n");
           exit(0); 
       }
 
       if(arretNB < cmp){
           printf("Erreur depassement du nombre d'aret\n");
           exit(0);
       }
 
       if((extI < 0) || ( extI > sommetNB) || (extF < 0) || ( extF > sommetNB)){
           printf("Erreur valeur du sommet incorrect\n");
           exit(0);
       }
             
       mat->Matrice[extI][cmp -1] = pArc;
       mat->Matrice[extF][cmp -1] = pArc;
       proid_prec = pArc;
  
       cmp++;
    }
 
    if(arretNB > (cmp -1)){
         printf("Erreur inssufisance du nombre d'aret\n");
         exit(0);
    }
 
    return mat; 
}
 
 
void Modifier(MatIncid *A, int k, int o, int p, int  b){
 
    int i;
 
 
    if((k < 0) || (k > (*A)->nb_aretes )){
       printf("Erreur valeur numero arete\n");
       exit(0);
    }
    
    for(i=0;i < (*A)->nb_sommets;i++){
        (*A)->Matrice[i][k] = 0; 
    }
 
    (*A)->Matrice[o][k] = p;
    (*A)->Matrice[b][k] = p;
 
}
 
int Cycle(int *Comp, int o,int b,int n){
 
      int V,i;
 
      if(Comp[o] == Comp[b]){
          return 1;
      }else{
 
          V = Comp[b];
          for(i=0;i <= (n-1);i++){
              if(Comp[i] == V){
                 Comp[i]=Comp[o];
              }
          }
          return 0;
      }
 
      return 0;
}
 
 
MatIncid Kruskal(MatIncid A){
 
   MatIncid arbre;
   int i, j, cp = 0, cmp_arbre=0;
   int ext[2];
 
   int * Comp = (int*)malloc(A->nb_sommets  * sizeof(int));
 
 
 
   for(i=0;i < A->nb_sommets;i++){
      Comp[i]=i;
   }
 
   arbre = MatIncidVide(A->nb_sommets, A->nb_sommets - 1);
 
   for(i=0; i < A->nb_aretes;i++){
       
      cp=0;
     
      for(j=0;j < A->nb_sommets;j++){
          
           if(A->Matrice[j][i] != 0){
              ext[cp] = j;
              cp++;
           }
      }
    
 
      if(Cycle(Comp,ext[0],ext[1],A->nb_sommets) == 0){
          Modifier(&arbre, cmp_arbre, ext[0], A->Matrice[ ext[0] ][i], ext[1]);
          cmp_arbre++;
      }
 
   }
 
   return arbre;
 
}
 
 
int main(int argc, char ** argv){
    
   MatIncid mat,mat1,mat3;
 
   printf(":::::::::: Test1 ::::::::::: Matrice vide\n");
   mat = MatIncidVide(7,5);
   AfficheMatIncid(mat);
 
   printf("\n"); 
 
 
   printf(":::::::::: Test2 ::::::::::: Lire graphe graphe2.txt\n");
   mat1 = LireGraphe("graphe2.txt");
   AfficheMatIncid(mat1);
 
   printf("\n");
 
 
   printf(":::::::::: Test3 :::::::::::Modifier Matrice\n");
 
   mat3 = MatIncidVide(7,5); 
   Modifier(&mat3, 2, 1, 7, 4);
   Modifier(&mat3, 4, 3, 6, 6);
   AfficheMatIncid(mat3);
 
   printf("\n");
    
 
 
   printf(":::::::::: Test4 ::::::::::: Kruskal\n");   
   AfficheMatIncid( Kruskal(mat1) );

   printf("\n");

   return 0;
}
