#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"f.h"

void setrects_right(SDL_Rect clip[]){
clip[0].x=0;
clip[0].y=191.25;
clip[0].w=113.75;
clip[0].h=191.2;

clip[1].x=113.75;
clip[1].y=191.25;
clip[1].w=113.75;
clip[1].h=191.2;

clip[2].x=227.5;
clip[2].y=191.25;
clip[2].w=100;
clip[2].h=191.2;

clip[3].x=341.25;
clip[3].y=191.25;
clip[3].w=113.75;
clip[3].h=191.2;

clip[4].x=455;
clip[4].y=191.25;
clip[4].w=113.75;
clip[4].h=191.2;

clip[5].x=568.75;
clip[5].y=191.25;
clip[5].w=113.75;
clip[5].h=191.2;


}

void setrects_left(SDL_Rect clip[]){
clip[0].x=0;
clip[0].y=382.5;
clip[0].w=113.75;
clip[0].h=191.2;

clip[1].x=113.75;
clip[1].y=382.5;
clip[1].w=113.75;
clip[1].h=191.2;

clip[2].x=227.5;
clip[2].y=382.5;
clip[2].w=100;
clip[2].h=191.2;

clip[3].x=341.25;
clip[3].y=382.5;
clip[3].w=113.75;
clip[3].h=191.2;

clip[4].x=455;
clip[4].y=382.5;
clip[4].w=113.75;
clip[4].h=191.2;

clip[5].x=568.75;
clip[5].y=382.5;
clip[5].w=113.75;
clip[5].h=191.2;

}
void setrects_crouchright(SDL_Rect clip[]){
clip[0].x=0;
clip[0].y=573.75;
clip[0].w=113.75;
clip[0].h=191.2;

clip[1].x=113.75;
clip[1].y=573.75;
clip[1].w=113.75;
clip[1].h=191.2;

clip[2].x=227.5;
clip[2].y=573.75;
clip[2].w=100;
clip[2].h=191.2;

clip[3].x=341.25;
clip[3].y=573.75;
clip[3].w=113.75;
clip[3].h=191.2;

}

void setrects_crouchleft(SDL_Rect clip[]){
clip[0].x=0;
clip[0].y=765;
clip[0].w=113.75;
clip[0].h=191.2;

clip[1].x=113.75;
clip[1].y=765;
clip[1].w=113.75;
clip[1].h=191.2;

clip[2].x=227.5;
clip[2].y=765;
clip[2].w=100;
clip[2].h=191.2;

clip[3].x=341.25;
clip[3].y=765;
clip[3].w=113.75;
clip[3].h=191.2;

}

void animation(acteur *acteur){
int tempsPrecedent = 0, tempsActuel = 0;
char temps[20];
SDL_Init(SDL_INIT_VIDEO);
acteur->screen=SDL_SetVideoMode(640,480,32,SDL_SWSURFACE | SDL_DOUBLEBUF );
acteur->frame=0;
acteur->running=1;
acteur->image=IMG_Load("b.png");
SDL_FillRect(acteur->screen,&acteur->screen->clip_rect,0x00);
acteur->rect.x=200;
acteur->rect.y=100;
SDL_EnableKeyRepeat(100,100);

while (acteur->running)
    {
        SDL_WaitEvent(&acteur->event);
        switch(acteur->event.type)
        {
            case SDL_QUIT:
                acteur->running = 0;
                break;
            case SDL_KEYDOWN:
                switch(acteur->event.key.keysym.sym)
                {
                    case SDLK_RIGHT: // Flèche droite
tempsActuel = SDL_GetTicks();
if (tempsActuel - tempsPrecedent >100){
                        acteur->rect.x=10+acteur->rect.x;
setrects_right(acteur->rects);
acteur->frame++;
if(acteur->frame==5){
acteur->frame=0;
}	
tempsPrecedent = tempsActuel;
}	
                        break;
                    case SDLK_LEFT: // Flèche gauche
tempsActuel = SDL_GetTicks();
if (tempsActuel - tempsPrecedent >100){
                        acteur->rect.x=-10+acteur->rect.x;
setrects_left(acteur->rects);
acteur->frame++;
if(acteur->frame==5){
acteur->frame=0;
}
tempsPrecedent = tempsActuel;
}


                        break;
                    case SDLK_a: // Flèche gauche
tempsActuel = SDL_GetTicks();
if (tempsActuel - tempsPrecedent >10){
                        acteur->rect.x=-10+acteur->rect.x;
setrects_crouchleft(acteur->rects);
acteur->frame=0;
acteur->frame=1;
acteur->frame=2;
acteur->frame=3;
tempsPrecedent = tempsActuel;
}


                        break;
                    case SDLK_z: // Flèche gauche
tempsActuel = SDL_GetTicks();
if (tempsActuel - tempsPrecedent >10){
                        acteur->rect.x=10+acteur->rect.x;
setrects_crouchright(acteur->rects);
acteur->frame=0;
acteur->frame=1;
acteur->frame=2;
acteur->frame=3;
tempsPrecedent = tempsActuel;
}


                        break;
                }
                break;
        }

SDL_FillRect(acteur->screen, NULL, SDL_MapRGB(acteur->screen->format, 0, 0, 0));
SDL_BlitSurface(acteur->image,&acteur->rects[acteur->frame],acteur->screen,&acteur->rect);
SDL_Flip(acteur->screen);
}
}

