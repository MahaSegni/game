
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"g.h"

void initialiser_joueur(perso *p)
{
	p->frame.y = 0;
	p->frame.x = 0;
	p->frame.w = 35;
	p->frame.h = 100;
	p->vie = 5;


}

	void Display_perso (perso p)
{
int continuer=1;
while (continuer){
p.screen=SDL_SetVideoMode(800,600,32,SDL_SWSURFACE | SDL_DOUBLEBUF );
p.image=IMG_Load("xc.png");
SDL_BlitSurface(p.image,NULL,p.screen, &p.position);
p.position.x=0;
p.position.y=0;
SDL_Flip(p.screen);
}
}
