#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void pause();

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL, chargement syst�me video
    SDL_Surface *ecran=NULL, *fondecran=NULL; //pointeur ecran et fondecran sur type SDL_Surface
    SDL_Rect positionfondecran; //typedef structure SDL_Rect pour placer fond �cran avec coordonn�es
    positionfondecran.x=0; //le fond �cran sera plus tard plac� en haut � gauche de l'�cran
    positionfondecran.y=0;
    ecran=SDL_SetVideoMode(480, 480, 32, SDL_HWSURFACE); // param�tre de la fen�tre (taille et couleur)
    SDL_WM_SetCaption("fenetre Laurent FERRIER",NULL); //titre de la fen�tre
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0)); //Couleur remplissage fen�tre  noire
    fondecran=SDL_LoadBMP("FondEcranMario.bmp"); //fondecran pointe sur la BMP lac en montagne plac�e ds le workspace
    SDL_BlitSurface(fondecran,NULL,ecran,&positionfondecran); //blit (collage) de l'image dans ecran
    SDL_Flip(ecran); //update m�moire vid�o

    pause(); // Mise en pause du programme
    SDL_FreeSurface(fondecran);
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
