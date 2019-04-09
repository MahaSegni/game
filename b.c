
 #include <stdio.h>
#include  <stdlib.h>
 #include  <SDL/SDL.h>
 #include <SDL/SDL_image.h>
 #include <stdbool.h>
#include "b.h"
 
 void deplacer(SDL_Rect positionpersonage)
  {
 SDL_Event event;

    SDL_Surface *ecran =NULL;
    SDL_Surface *image =NULL,*personage=NULL;
    SDL_Rect positionecran;
    char pause;
    int continuer =1,curseur=1;
  
    personage=IMG_Load("v.png");
    SDL_SetColorKey(personage, SDL_SRCCOLORKEY, SDL_MapRGB(personage->format, 255, 255, 255));
    positionecran.x=-10;
    positionecran.y=-10;
    positionpersonage.x=50;
    positionpersonage.y=200;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(994, 694, 24, SDL_HWSURFACE );
    while (continuer)
    {
     SDL_WaitEvent(&event);
       
        SDL_BlitSurface(personage,NULL,ecran,&positionpersonage);
        SDL_Flip(ecran);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer=0;
                break;
        case SDLK_UP:
                positionpersonage.y=positionpersonage.y-10;
SDL_Flip(ecran);
        break;
        case SDLK_DOWN:
                positionpersonage.y=positionpersonage.y+10;

        break;
            case SDLK_RIGHT:
                positionpersonage.x=positionpersonage.x+20;

                break;
            case SDLK_LEFT:
                positionpersonage.x=positionpersonage.x-20;

                break;
       
            }
SDL_Flip(personage);
       			break;
        case SDL_MOUSEBUTTONUP:              
                   
           
                positionpersonage.x=event.button.x;
                    positionpersonage.y=event.button.y;
               
                                     
                                
                    break;
      }                 
        } 
 }
   
 
   
