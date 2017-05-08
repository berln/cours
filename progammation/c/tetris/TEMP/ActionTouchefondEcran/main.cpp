#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>

void pause();

int main(int argc, char *argv[])
{

    SDL_Event event; /* Variable event contenant l'�v�nement */
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *ecran=NULL, *fondecran=NULL; //pointeur ecran et fondecran sur type SDL_Surface
    SDL_Rect positionfondecran; //typedef structure SDL_Rect pour placer fond �cran avec coordonn�es
    positionfondecran.x=0; //le fond �cran sera plus tard plac� en haut � gauche de l'�cran
    positionfondecran.y=0;

    int continuer = 1; /* Bool�en pour la boucle */

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE); //Def fen�tre
    SDL_WM_SetCaption("Gestion des �v�nements en SDL", NULL); //titre sur fen�tre
    printf("SALUT\n");

  while (continuer) /* TANT QUE la variable ne vaut pas 0 */
    {
        SDL_WaitEvent(&event); /*Attente d'un �v�nement r�cup�r� dans la variable event; possibilit� d'utiliser SDL_Pollevent*/
        switch(event.type) /* Test du type d'�v�nement --> Test de event.type */
        {
            case SDL_QUIT: /* Ev�nement QUITTER */
                 continuer = 0; /* On met le bool�en � 0, donc la boucle va s'arr�ter */
                 break;
            case SDL_KEYDOWN:
                 printf("appui sur la touche fleche bas\n");
                 ecran=SDL_SetVideoMode(480, 480, 32, SDL_HWSURFACE); // param�tre de la fen�tre (taille et couleur)
                 SDL_WM_SetCaption("fenetre Laurent FERRIER",NULL); //titre de la fen�tre
                 SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0)); //Couleur remplissage fen�tre  noire
                 fondecran=SDL_LoadBMP("FondEcranMario.bmp"); //fondecran pointe sur la BMP lac en montagne plac�e ds le workspace
                 SDL_BlitSurface(fondecran,NULL,ecran,&positionfondecran); //blit (collage) de l'image dans ecran
                 SDL_Flip(ecran); //update m�moire vid�o

                 pause(); // Mise en pause du programme
                 SDL_FreeSurface(fondecran);
                 continuer=0;
                 break;
            default:
                 continuer=1;

        }
    }

    SDL_Quit();

    return 0;
}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
