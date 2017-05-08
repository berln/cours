#include "sokoban.h"
#include <stdio.h>
#include <string.h>


int main(int argc, char ** argv)
{
  Position sokoban;
      char commande[MAXCH+1];
      Boolean encore=true;
      int tour=0,i;
  Grille initiale = {
  "####....################",
  "#.........#......#.....#",
  "##......###............#",
  "###..............#.....#",
  "####.............#.....#",
  "##################.....#",
  "####.............#.....#",
  "###..................###",
  "##...........#########.#",
  "#......O..o............#",
  "#S.....O..o............#",
  "########################"
  };
  Grille jeu ;

  sokoban = getSokoban(initiale);
  nouveauJeu(initiale, jeu);


  while (encore==true) {
     afficheGrille(jeu);
     tour++;
     printf("\n>");
     fgets(commande,MAXCH,stdin) ;

     for(i=0;i<strlen(commande)-1;i++){
           switch(commande[i])
              {
                 case QUITTER:
                 encore=false;
                 break;
                 case AIDE:
                 aide();
                 break;
                 case HAUT:
                 sokoban=joue(jeu, commande[i], getSokoban(jeu), initiale);
                 break;
                 case BAS:
                 sokoban=joue(jeu, commande[i], getSokoban(jeu), initiale);
                 break;
                 case GAUCHE:
                 sokoban=joue(jeu, commande[i], getSokoban(jeu), initiale);
                 break;
                 case DROITE:
                 sokoban=joue(jeu, commande[i], getSokoban(jeu), initiale);
                 break;
                 default:
                 printf("commande inconnue\n");
              }

           if(gagne(jeu, getSokoban(jeu), initiale) == true)
           {
              encore = false;
              afficheGrille(jeu);
              printf(" Bien joué !! \n Tu as gagné en %d tours !\n\n", tour);
           }
        }
  }
  return 0;
}

