#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h> 
#include <unistd.h>



typedef struct hero
{
	SDL_Surface *sprite;
	SDL_Rect possprite;
	int frameNumber;
	int etat, direction;
	SDL_Rect pos;
	int posTimer;
	int event;
} her;
void animation_perso(her *hero[],SDL_Surface *ecran, SDL_Rect positionpersonage);
void initialiser_perso(her *hero[]);
#endif
