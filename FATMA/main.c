#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <stdbool.h> 
#include "enigme.c" 
int main()
{
SDL_Rect *col;
SDL_Surface *collisionMap = NULL;
char image [20] ;
SDL_Surface *ecran = NULL;
collisionMap =SDL_LoadBMP("i1.bmp");
SDL_BlitSurface(image, NULL, ecran, &col);
afficher_enigme(image,ecran);
resolution_enigme(col);
collisionenigme(1,col,collisionMap,ecran);
enigmeh(ecran);
return 0 ;
}


