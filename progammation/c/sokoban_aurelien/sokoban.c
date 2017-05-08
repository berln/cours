#include "sokoban.h"
#include <stdio.h>



void afficheGrille(Grille g)
{
  int i;
  printf("\n");
  for(i=0 ; i<HAUTEUR ; i++)
     printf("%s\n", g[i]);
}

Position getSokoban(Grille g)
{
  int Xpos, Ypos;
  Boolean err=true;
  Position coord;

  for(Xpos=0; Xpos < HAUTEUR ; Xpos++)
  {
     for(Ypos=0 ; Ypos < LARGEUR ; Ypos++)
     {
        if(g[Xpos][Ypos]==SOKOBAN)
        {
           coord.x=Xpos+1;
           coord.y=Ypos+1;
           err=false;
        }
     }
  }
 
  if(err==true)
      error(NO_SOKOBAN);

  return coord;
}


void nouveauJeu(Grille init, Grille g)
{
  int i, j;
  verif(init);

  for (i=0 ; i<HAUTEUR ; i++) {
    for (j=0 ; j<=LARGEUR ; j++) {
        g[i][j]=init[i][j];

       if(init[i][j] == SOKOBAN || init[i][j] == CAISSE){
          init[i][j]=VIDE;
     }
    }
  }
}


Boolean verif(Grille g)
{

  int i, j,cptCaisse=0, cptCible=0;

  for (j=0 ; j< HAUTEUR ; j++) {
     i=0;
     while(g[j][i] != '\0') {
        if(g[j][i] == CAISSE ) cptCaisse++ ;
        else if (g[j][i] == CIBLE) cptCible++;
        i++;
     }

     if (i != LARGEUR )
         error(GRILLE_INCORRECT);
  }

  if(cptCaisse>=1){

     if(cptCaisse != cptCible) {
        printf("nombre caisse : %d, nbCible : %d\n",cptCaisse, cptCible);
        error(CIBLE_CAISSE);
     }
  } else
        error(MIN_CAISSE);

  return true;
}


int compte(Grille g, char c){

  int i, j,cpt=0;

  for (i=0 ; i<HAUTEUR ; i++) {
     for (j=0 ; j<=LARGEUR ; j++) {
        if(g[i][j] == c)
            cpt++;
     }
  }
  return cpt;
}

Position pas(Position pos_depart,Commande cmd)
{

  switch (cmd) {
     case HAUT:
        pos_depart.x--;
        break;
     case BAS:
        pos_depart.x++;
        break;
     case DROITE:
        pos_depart.y++;
        break;
     case GAUCHE:
        pos_depart.y--;
        break;
     default:
        error(FAUSSE_POS);
        break;
  }
 
  return pos_depart;
}

Boolean possible(Grille g,Position pos)
{ 
  if(pos.x < 0 || pos.x > HAUTEUR)
     return false;
  else if(pos.y < 0 || pos.y > LARGEUR+1)
     return false;
  else if(g[pos.x][pos.y] == MUR || g[pos.x][pos.y] == CAISSE)
     return false;
  else return true;
}

void deplace(Grille jeu,Position pos_a,Position pos_b, Grille init)
{
  jeu[pos_b.x][pos_b.y] = jeu[pos_a.x][pos_a.y];
  jeu[pos_a.x][pos_a.y]= init[pos_a.x][pos_a.y];
}

Position joue(Grille jeu, Commande dir, Position depart, Grille init)
{
  Position new_pos;
  Position pos_caisse;

  depart.y--;
  depart.x--;

  new_pos=pas(depart,dir);

  if(possible(jeu, new_pos) == false)
  {
     if(jeu[new_pos.x][new_pos.y] == MUR)
        error(POS_MUR);
     else if(jeu[new_pos.x][new_pos.y] == CAISSE)
     {
        pos_caisse=pas(new_pos,dir);
        if(possible(jeu, pos_caisse) == false)
           error(POS_CAISSE);
        else
        {
           deplace(jeu, new_pos, pos_caisse, init);
           deplace(jeu, depart, new_pos, init);
        }
     }
  }
  else {
     deplace(jeu, depart, new_pos, init);
  }
  return new_pos;


}

Boolean gagne(Grille jeu, Position soko, Grille init)
{
  int x, y;
  for(y=0 ; y < HAUTEUR ; y++)
  {
     for(x=0 ; x < LARGEUR ; x++)
     {
        if(jeu[y][x]==CIBLE)return false;
        else if(init[y][x]==CIBLE && jeu[y][x]==SOKOBAN)return false;
     }
  }
  return true;
}
void aide(){
  printf(" ------------- \n");
  printf("Legende de la carte:n\n");
  printf("#: mur\n");
  printf("S : le personnage Sokoban\n");
  printf("O : une caisse\n");
  printf("o : une cible\n");
  printf(". : une case vide\n");
  printf(" ------------- \n");
  printf("Commandes disponible\n");
  printf("q: pour Quitter\n");
  printf("a: pour afficher l'aide\n");
  printf("h: pour aller en Haut\n");
  printf("b: pour aller en Bas\n");
  printf("g: pour aller à  Gauche\n");
  printf("d: pour aller à  Droite\n");
  printf(" ------------- \n");

}

void error(CodeErreur code)
{
   switch (code) {
     case NO_SOKOBAN :fprintf(stderr,"Sokoban n'est pas dans la grille!\n"); break;
     case GRILLE_INCORRECT : fprintf(stderr,"grille incorrect\n"); break;
     case MIN_CAISSE : fprintf(stderr,"il doit y avoir au moins une caisse\n"); break;
     case FAUSSE_POS : fprintf(stderr,"mauvaise position\n"); break;
     case CIBLE_CAISSE : fprintf(stderr,"il doit y avoir autant de cible que de caisses\n"); break;
     case POS_MUR : fprintf(stderr,"impossible déplacer un mur gene\n"); break;
     case POS_CAISSE : fprintf(stderr,"impossible de déplacer la caisse un mur gene\n"); break;
     default: fprintf(stderr,"code erreur inconnu!\n");
   }

}

