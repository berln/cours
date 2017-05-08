#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
int main(int argc, char const *argv[])
{
	SDL_Surface *ecran = NULL; // Le pointeur qui va stocker la surface de l'écran

	SDL_Init(SDL_INIT_VIDEO);

	ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE); // On tente d'ouvrir une 
	/* code */
	Uint32 bleuVert = SDL_MapRGB(ecran->format, 17, 206, 112);

	return 0;
}