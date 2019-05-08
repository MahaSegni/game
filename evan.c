#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
#include <time.h>
void initialiser_evan(hero *evan){
		
		//evan->afficher_hero=NULL;
		//evan->afficher_hero=IMG_Load("walk.png");


		evan->afficher_hero[0]=IMG_Load("1.png");
		evan->afficher_hero[1]=IMG_Load("2.png");
		evan->afficher_hero[2]=IMG_Load("3.png");
		evan->afficher_hero[3]=IMG_Load("4.png");
		evan->afficher_hero[4]=IMG_Load("5.png");
		evan->afficher_hero[5]=IMG_Load("6.png");
		evan->afficher_hero[6]=IMG_Load("7.png");
		evan->afficher_hero[7]=IMG_Load("8.png");
		//evan->afficher_hero[8]=IMG_Load("9.png");


	evan->farm=0;
	
	evan->pos_hero2.x=0;
	evan->pos_hero2.y=0;
}
void afficher_evan(hero evan,SDL_Surface *ecran){
	
	SDL_BlitSurface(evan.afficher_hero[evan.farm],NULL,ecran,&(evan.pos_hero2));
}
