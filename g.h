#ifndef FONCTION_H_
#define FONCTION_H_
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

  typedef struct
{
	SDL_Surface *image;
	SDL_Rect frame;
	SDL_Rect position;
	int vie;
	int coins;
	int HP;
SDL_Surface *screen;
} perso;

void initialiser_joueur(perso *p);
void Display_perso(perso p);


#endif
