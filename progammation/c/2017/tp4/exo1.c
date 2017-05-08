#include <stdio.h>
#include  <stdlib.h>
#define typeElem int
#define arbrevide NULL

typedef enum { false, true } booleen;


typedef struct aa{
   int elem;
   struct aa *g;
   struct aa *d;
}arbre;


int est_vide(arbre *a){
   return a==arbrevide;
}
arbre *g(arbre *a){
   return a->g;
}
arbre *de(arbre *a){
   return a->d;
}

int racine(arbre *a){
   return a->elem;
}

arbre *consa(char e,arbre*g,arbre *d){
   arbre *tmp;
   tmp=(arbre *)malloc(sizeof(arbre));
   tmp->elem=e;
   tmp->g=g;
   tmp->d=d;
   return tmp;
}

void prefixe( arbre *a) {
    if(!est_vide(a)) {
        printf ( "%c" , racine(a) );
        prefixe( a-> g );
        prefixe( a-> d );
    }
}

void infixe( arbre *a) {
    if(!est_vide(a)) {
        infixe( a-> g) ;
        printf ( "%c" , racine(a) ) ;
        infixe( a-> d ) ;
    }
}

void postfixe( arbre *a) {
    if(!est_vide(a)) {
        postfixe( a -> g) ;
        postfixe( a -> d ) ;
        printf ( "%c" , racine(a) ) ;
    }
}

int add( arbre *a) {
    if(est_vide(a)) 
       return 0;
    else
      return racine(a)+add(g(a))+add(de(a));
    
}

int avg( arbre *a) {
    if(est_vide(a)) 
       return 0;
    else
      return 1+avg(g(a))+avg(de(a));
    
}

int addi( arbre *a, int tmp) {
    if(!est_vide(a)) {
        addi( a -> g,tmp) ;
        addi( a -> d,tmp ) ;
        tmp=tmp+racine(a);
        return tmp;
    }
}


int nombre_de_noeuds (arbre *a){
    if(est_vide(a)) {
        return 0;
    }
    if(est_vide(a -> d)&& est_vide(a -> g)){
        return 0;
    }else{
        return nombre_de_noeuds(a -> d)+nombre_de_noeuds(a -> g)+1 ;
    }
}
int nombre_de_feuilles (arbre *a){
    if(est_vide(a)) {
        return 0;
    }
    if(est_vide(a-> d)&& est_vide(a-> g))
        return 1;
    else
        return nombre_de_feuilles(a-> d)+nombre_de_feuilles(a-> g);
    
}

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

int hauteur (arbre *a){
    if(est_vide(a))
        return 0;
    else
        return(1+ max(hauteur(a->d),hauteur(a->g)));
    
}


int main(){
  int tmp;
  arbre *aV,*aR,*aE,*aW,*aB,*aT,*aG;
  tmp=0;

  aV=consa(1,arbrevide,arbrevide);
  aR=consa(2,arbrevide,arbrevide);
  aE=consa(3,arbrevide,arbrevide);
  aW=consa(4,aV,arbrevide);
  aB=consa(5,aE,aW);
  aT=consa(6,arbrevide,aR);
  aG=consa(7,aT,aB);

  infixe(aG);
  printf("la somme = %i\n",add(aG));
  printf("lol%d\n",add(aG)/avg(aG));

   return 0;
}

