#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"f.h"





int main(){
acteur acteur;
setrects_right(acteur.rects);
setrects_left(acteur.rects);
animation(&acteur);
SDL_FreeSurface(acteur.screen);
SDL_FreeSurface(acteur.image);
SDL_Quit();

 return 0;
}

