#ifndef EVAN_H_INCLUDED
#define EVAN_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <time.h>
#include<SDL/SDL_ttf.h>
#include <unistd.h>
#include"struct.h"
	extern hero evan;
	extern void initialiser_evan(hero *evan);
	extern void afficher_evan(hero *evan,SDL_Surface *ecran);
#endif