#ifndef SOKOBAN_H
#define SOKOBAN_H

#define LARGEUR 24
#define HAUTEUR 12
#define MAXCH 40


typedef enum Boolean {false, true} Boolean;
typedef enum Symbole {MUR='#', CAISSE='O', CIBLE='o', SOKOBAN='S', VIDE='.'}Symbole;
typedef enum Commande {HAUT='h', BAS='b', GAUCHE='g', DROITE='d', AIDE='a', QUITTER='q' }Commande;
typedef enum CodeErreur{NO_SOKOBAN, GRILLE_INCORRECT,FAUSSE_POS, MIN_CAISSE, CIBLE_CAISSE, POS_MUR, POS_CAISSE} CodeErreur;

typedef char Ligne[LARGEUR+1];
typedef Ligne Grille[HAUTEUR];

typedef struct _Position{
  int y;
  int x;
} Position;

Position getSokoban(Grille g);
void afficheGrille(Grille g);
void error(CodeErreur code);
void nouveauJeu(Grille init, Grille g);
Boolean verif(Grille g);
int compte(Grille g, char c);
void aide();
Position pas(Position pos_depart,Commande cmd);
Boolean possible(Grille g,Position pos);
void deplace(Grille jeu,Position pos_a,Position pos_b, Grille init);
Position joue(Grille jeu, Commande dir, Position depart, Grille init);
Boolean gagne(Grille jeu, Position soko, Grille init);
#endif
