#ifndef FONCTION_H_
#define FONCTION_H_
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct  {
SDL_Surface *screen,*image;
SDL_Event event ;
SDL_Rect rect ;
int running;
int frame;
SDL_Rect rects[6];
}acteur;

void setrects_right(SDL_Rect clip[]);
void setrects_left(SDL_Rect clip[]);
void setrects_crouchright(SDL_Rect clip[]);
void setrects_crouchleft(SDL_Rect clip[]);
void animation(acteur *acteur);

#endif
