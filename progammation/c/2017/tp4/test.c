#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define arbre_vide NULL
#define typeElem char
#define MAXE ((a)>(b))?(a):(b))
#define liste_vide NULL
#define  boolean   int


typedef struct aa {
    typeElem valeur;
    struct aa *gauche ;
    struct aa *droit;
} arbre ;

typedef struct ll
{
typeElem e;
struct ll *suiv;
} typeListe ;

typedef typeListe *liste ;

arbre *consa( typeElem E , arbre *g , arbre *d) {
    arbre *tmp= (arbre *)malloc ( sizeof ( arbre) ) ;
    tmp->valeur = E ;
    tmp->gauche = g ;
    tmp->droit = d;
    return tmp ;
}

typeElem est_vide(arbre *a)
{ 
    return a == arbre_vide ; 
}
arbre *gauche(arbre *a ) {
    if(!est_vide(a)) return a->gauche; 
}
arbre *droit(arbre *a ) {
    if(!est_vide(a)) return a->droit; 
}

typeElem racine (arbre *tree){
    if(!est_vide(tree)) return tree->valeur;
}

/* les parcours */
void prefixe( arbre *a) {
    if(!est_vide(a)) {
        printf ( "%c" , racine(a) );
        prefixe( gauche(a)) ;
        prefixe( droit (a) ) ;
    }
}

void infixe( arbre *a) {
    if(!est_vide(a)) {
        infixe( gauche(a)) ;
        printf ( "%c" , racine(a) ) ;
        infixe( droit (a) ) ;
    }
}

void postfixe( arbre *a) {
    if(!est_vide(a)) {
        postfixe( gauche(a)) ;
        postfixe( droit (a) ) ;
        printf ( "%c" , racine(a) ) ;
    }
}
/*fonction arbre*/
int nombre (arbre *a){
    if(!est_vide(a)) {
        return nombre( droit (a))+nombre( gauche(a))+1 ;
    }else{
        return 0;
    }
}

int nombre_de_noeuds (arbre *a){
    if(est_vide(a)) {
        return 0;
    }
    if(est_vide(droit(a))&& est_vide(gauche(a))){
        return 0;
    }else{
        return nombre_de_noeuds(droit(a))+nombre_de_noeuds(gauche(a))+1 ;
    }
}
int nombre_de_feuilles (arbre *a){
    if(est_vide(a)) {
        return 0;
    }
    if(est_vide(droit(a))&& est_vide(gauche(a))){
        return 1;
    }else{
        return nombre_de_feuilles(droit(a))+nombre_de_feuilles(gauche(a));
    }
}

int max(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }

}

int hauteur (arbre *a){
    if(est_vide(a)) {
        return 0;
    }else{
        return  1+max(hauteur(droit(a)),hauteur(gauche(a)));
    }
}

/* TP4 */

/* algo question 1b
int  calculer (arbre   *noeud  )
debut
si (racine(a) = '+') alors
    retourner calculer(gauche(a)) + calculer(droit(a))
sinon (racine(a) = '-') alors
    retourner calculer(gauche(a)) - calculer(droit(a))
sinon (racine(a) = '*') alors
    retourner calculer(gauche(a)) * calculer(droit(a))
sinon (racine(a) = '/') alors
    retourner calculer(gauche(a)) / calculer(droit(a))
sinon
    retourner int (racine(a));
fin
*/

arbre * ajout_feuille ( typeElem X ,arbre * a){
      if (a == arbre_vide){
        return consa(X,arbre_vide, arbre_vide);
    }
     if (X <= racine(a)){
        a->gauche = ajout_feuille(X, a->gauche);
    }
     else{
        if (X > racine(a)){
                a->droit = ajout_feuille(X, a->droit);
        }
    }
     return a;
}

boolean recherche_noeud ( typeElem X, arbre * a){
    if(est_vide(a))     return 0;    
    if(X == a->valeur)     return 1;
    if (X <= racine(a)){
         return recherche_noeud(X, gauche(a));
    }else{
        return recherche_noeud(X, droit(a));
    }
}

arbre *recherche_adr ( typeElem X, arbre * a){
    if(est_vide(a))     return arbre_vide;
    if(X == a->valeur)    return a;
      if (X <= racine(a)){
        return recherche_adr(X, gauche(a));
    }else{
        return recherche_adr(X, droit(a));
    }                
}

boolean compare(arbre *a1, arbre *a2){
        if(!est_vide(a1) || !est_vide(a2)) {
            if(a1->valeur != a2->valeur){
                return 1;
            }
            return 0;
            return compare( gauche(a1),gauche(a2)) ;
            return compare( droit (a1),droit (a2) ) ;
        }
    return 1;
}

boolean verifie(arbre *a){
    if(!est_vide(a)){
        return verifie(gauche(a));
        return verifie(droit(a));
        if(racine(gauche(a)) <= racine(a) && racine(droit(a)) > racine(a) ){
            return 1;
        }
    }
    return 0;
}
/*abstrai liste*/
typeElem Lest_vide (liste L){
    return L==liste_vide;
}

liste suite (liste L){
    return L->suiv;
}

typeElem tete (liste L){
    return L->e;
}

liste cons (int element, liste L){
    liste tmp;
    tmp=(liste) malloc (sizeof(typeListe));
    tmp->e=element;
    tmp->suiv=L;
    return tmp;
}
/*liste fonction*/
void affiche(liste L){
    liste tmp=L;
    while(! Lest_vide(tmp)){
        printf(" %d ",tete(tmp));
        tmp=suite(tmp);
    }
}
/**/
liste *transform(arbre *a){
    liste l1=liste_vide;
    if(!est_vide(a)) {
        return cons(racine(a),transform( gauche(a) ))  ;
        return cons(racine(a),transform( droit (a) ))  ;
    }
}

int main (){
    int res=0;
    arbre *a1,*a2,*a3,*a4,*a5,*a6,*a7,*a8,*a9,*a10,*a11;
    arbre *b1,*c1,*d1,*d2,*d3,*d4;
    int bo;
    liste liste1;
    typeElem var;
    a8=consa('2',arbre_vide,arbre_vide);
    a9=consa('3',arbre_vide,arbre_vide);
    a5=consa('*',a8,a9);
    a4=consa('8',arbre_vide,arbre_vide);
    a3=consa('-',a4,a5);
    a10=consa('4',arbre_vide,arbre_vide);
    a11=consa('2',arbre_vide,arbre_vide);
    a7=consa('/',a10,a11);
    a6=consa('3',arbre_vide,arbre_vide);
    a2=consa('+',a6,a7);
    a1=consa('*',a2,a3);

    b1=consa('o',arbre_vide,arbre_vide);
    
    postfixe(a1);
    printf("\n");
    prefixe(a1);
    printf("\n");
    infixe(a1);
    printf("\n");
    
    b1=ajout_feuille('j',b1);
    b1=ajout_feuille('a',b1);    
    b1=ajout_feuille('z',b1);
    postfixe(b1);
    printf("\n");

    var='0';
    bo=recherche_noeud(var,b1);
    printf("%c est dans b1 ? %d \n",var,bo);
    
    c1=recherche_adr(var,b1);
    postfixe(c1);
    printf("\n");

    var='j';
    bo=recherche_noeud(var,b1);
    printf("%c est dans b1 ? %d \n",var,bo);
    
    c1=recherche_adr(var,b1);
    postfixe(c1);
    printf("\n");
    
    res=compare(c1,b1);
    printf("Resultat compare %d \n",res);

    d3=consa('g',arbre_vide,arbre_vide);
    d4=consa('a',arbre_vide,arbre_vide);
    d2=consa('a',d4,arbre_vide);
    d1=consa('b',d2,d3);

    res=verifie(d1);
    printf("Resultat verifie %d \n",res);

    
    return 0;
}



