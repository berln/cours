#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>


int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;
    SDL_Event event; /* Variable event contenant l'�v�nement */
    int continuer = 1; /* Bool�en pour la boucle */

    SDL_Init(SDL_INIT_VIDEO);

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
                 continuer=0;
                 break;
            default:
                 continuer=1;

        }
    }

    SDL_Quit();

    return 0;
}
