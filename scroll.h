#ifndef scroll_H_INCLUDED
#define scroll_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h> 
#include <unistd.h>
void scroll (SDL_Rect *camera,int direction,SDL_Rect *coll,SDL_Rect positionBack1,SDL_Rect positionBack2,SDL_Surface *collisionMap) ;
void display_scroll (SDL_Surface *screen,SDL_Surface *map,SDL_Rect camera);
int sco(int argc, char *argv[]);
#endif
