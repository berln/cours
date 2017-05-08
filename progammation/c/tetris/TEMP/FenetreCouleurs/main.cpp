#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void pause();

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL, chargement syst�me video
    SDL_Surface *ecran=NULL; //Pointeur ecran sur un SDL_Surface
    ecran=SDL_SetVideoMode(480, 480, 32, SDL_HWSURFACE); // Ouverture de la fen�tre
    SDL_WM_SetCaption("fenetre Laurent FERRIER",NULL); //titre de la fen�tre
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,116,255)); //Passage couleur RGB dans �cran
    SDL_Flip(ecran);

    pause(); // Mise en pause du programme

    SDL_Quit(); // Arr�t de la SDL

    return EXIT_SUCCESS; // Fermeture du programme
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
