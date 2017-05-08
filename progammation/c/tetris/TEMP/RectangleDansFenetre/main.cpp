#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void pause();

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL, chargement système video
    SDL_Surface *ecran=NULL, *rectangle=NULL; //Pointeur sur surface (écran et rectangle)
    SDL_Rect position; //def structure position de type SDL_Rect
    position.x=0;  // rectangle (abscisse (coin haut gauche =0))
    position.y=0;  // rectangle (ordonnée (coin haut gauche =0))
    ecran=SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE); // Ouverture de la fenêtre
    rectangle=SDL_CreateRGBSurface(SDL_HWSURFACE,100,100,32,0,0,0,0); //dimension rectangle 100 par 100
    SDL_WM_SetCaption("fenetre Laurent FERRIER",NULL);
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,255));
    SDL_FillRect(rectangle,NULL,SDL_MapRGB(rectangle -> format,255,0,0)); //remplissage rectangle en rouge
    SDL_BlitSurface(rectangle,NULL,ecran,&position); //collage rectangle dans ecran
    SDL_Flip(ecran);
    pause(); // Mise en pause du programme
    SDL_FreeSurface(rectangle);
    SDL_Quit(); // Arrêt de la SDL

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

