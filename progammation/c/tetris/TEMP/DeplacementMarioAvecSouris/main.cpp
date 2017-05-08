#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *Mario = NULL;
    SDL_Rect positionMario;
    SDL_Event event;
    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); /* Double Buffering */
    SDL_WM_SetCaption("Gestion des évènements en SDL", NULL); //Titre écran

    Mario = SDL_LoadBMP("Mario.bmp"); //Chargement bmp Mario
    SDL_SetColorKey(Mario, SDL_SRCCOLORKEY, SDL_MapRGB(Mario->format, 255, 255, 255));

    positionMario.x = ecran->w / 2 - Mario->w / 2; //Mario placé au centre  (largeur  ecran)/2 - (largeur Mario)/2
    positionMario.y = ecran->h / 2 - Mario->h / 2; //Mario placé au centre  (hauteur  ecran)/2 - (hauteur Mario)/2

    SDL_EnableKeyRepeat(10, 10); /* Evite un déplacement pixel par pixel --> déplacement pendant 10 ms de 10 pixels */

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type) //recherche d'un évènement
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_MOUSEBUTTONUP: //Clic Souris --> placement de Mario à l'endroit de la souris
                positionMario.x = event.button.x; //Récupération abscisse souris et passage à abscisse de Mario
                positionMario.y = event.button.y; //Récupération ordonnées souris et passage à ordonnées de Mario
                break;
        }
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(Mario, NULL, ecran, &positionMario); /* Placement de Mario à sa nouvelle position */
        SDL_Flip(ecran);
    }



   // SDL_FreeSurface(Mario);
    SDL_Quit();

    return EXIT_SUCCESS;
}
