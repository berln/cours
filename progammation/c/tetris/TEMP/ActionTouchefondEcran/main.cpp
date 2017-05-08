#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>

void pause();

int main(int argc, char *argv[])
{

    SDL_Event event; /* Variable event contenant l'événement */
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *ecran=NULL, *fondecran=NULL; //pointeur ecran et fondecran sur type SDL_Surface
    SDL_Rect positionfondecran; //typedef structure SDL_Rect pour placer fond écran avec coordonnées
    positionfondecran.x=0; //le fond écran sera plus tard placé en haut à gauche de l'écran
    positionfondecran.y=0;

    int continuer = 1; /* Booléen pour la boucle */

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
                 ecran=SDL_SetVideoMode(480, 480, 32, SDL_HWSURFACE); // paramètre de la fenêtre (taille et couleur)
                 SDL_WM_SetCaption("fenetre Laurent FERRIER",NULL); //titre de la fenêtre
                 SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0)); //Couleur remplissage fenêtre  noire
                 fondecran=SDL_LoadBMP("FondEcranMario.bmp"); //fondecran pointe sur la BMP lac en montagne placée ds le workspace
                 SDL_BlitSurface(fondecran,NULL,ecran,&positionfondecran); //blit (collage) de l'image dans ecran
                 SDL_Flip(ecran); //update mémoire vidéo

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
