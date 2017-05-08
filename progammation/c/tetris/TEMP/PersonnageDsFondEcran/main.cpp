#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void pause();

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL, chargement système video
    SDL_Surface *ecran=NULL, *fondecran=NULL, *personnage =NULL; //pointeur ecran,fondecran et personnage sur type SDL_Surface
    SDL_Rect positionfondecran, positionpersonnage; //typedef structure SDL_Rect pour placer fond écran avec coordonnées
    positionfondecran.x=0; //le fond écran sera plus tard placé en haut à gauche de l'écran
    positionfondecran.y=0;
    positionpersonnage.x=100; //initialisation abscisse Mario à 100
    positionpersonnage.y=100; //initialisation ordonnée Mario à 100
    ecran=SDL_SetVideoMode(600, 400, 32, SDL_HWSURFACE); // paramètre de la fenêtre (taille et couleur)
    fondecran=SDL_LoadBMP("FondEcranMario.bmp"); //fondecran pointe sur la BMP lac en montagne placée ds le workspace
    personnage=SDL_LoadBMP("Mario.bmp");
    SDL_WM_SetCaption("fenetre Laurent FERRIER",NULL); //titre de la fenêtre
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0)); //Couleur remplissage fenêtre  noire
    SDL_BlitSurface(fondecran,NULL,ecran,&positionfondecran); //blit (collage) de l'image dans ecran
    SDL_SetColorKey(personnage,SDL_SRCCOLORKEY,SDL_MapRGB(personnage->format,255,255,255));
    //SDL_SetAlpha(personnage, SDL_SRCALPHA, 50); //réalise un fondu de l'image.
    SDL_BlitSurface(personnage,NULL,ecran,&positionpersonnage);
    SDL_Flip(ecran); //update mémoire vidéo

    pause(); // Mise en pause du programme
    SDL_FreeSurface(fondecran);
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
