#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>


int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;
    SDL_Event event; /* Variable event contenant l'événement */
    int continuer = 1; /* Booléen pour la boucle */

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE); //Def fenêtre
    SDL_WM_SetCaption("Gestion des événements en SDL", NULL); //titre sur fenêtre
    printf("SALUT\n");

  while (continuer) /* TANT QUE la variable ne vaut pas 0 */
    {
        SDL_WaitEvent(&event); /*Attente d'un évènement récupéré dans la variable event; possibilité d'utiliser SDL_Pollevent*/
        switch(event.type) /* Test du type d'événement --> Test de event.type */
        {
            case SDL_QUIT: /* Evènement QUITTER */
                 continuer = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
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
