
 include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
 

void jouer(SDL_Surface* ecran)
{
 SDL_Surface *harrygauche = NULL; 
SDL_Surface *harrydroit = NULL;
SDL_Surface *harryhaut = NULL; 
SDL_Surface *harrybas = NULL;  
    SDL_Surface *ecran = NULL;
  SDL_Surface *imageDeFond = NULL;
 SDL_Surface *harry= NULL;
 SDL_Surface *vie=NULL;
SDL_Surface *harry= NULL;
    SDL_Rect positionFond, positionharry,positionvie;
   SDL_Event event;
    int continuer = 1;
 
    positionFond.x = 0;
    positionFond.y = 0;
 positionvie.x = 0;
    positionvie.y = 0;
positionharry.x=250;
positionharry.y=350;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    
 
    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
 
    imageDeFond = IMG_Load("x.jpg");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
 
  
    harry = IMG_Load("w.png");
    SDL_BlitSurface(harry , NULL, ecran, &positionharry);
  
    vie = IMG_Load("o.jpg");
    SDL_BlitSurface(vie, NULL, ecran, &positionvie);
while (continuer)
    {
        SDL_WaitEvent(&event);
switch(event.type)
{
    case SDL_QUIT:
        continuer = 0;
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
            case SDLK_ESCAPE:
                continuer = 0;
                break;
            case SDLK_UP:
         
                 if (positionharry.y - 1 < 0) // Si le joueur dépasse l'écran, on arrête
                break;
           
        positionharry.y--;
   harryhaut  = IMG_Load("x.jpg");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionharry);
  

            break;

                break;
            case SDLK_DOWN:
 if (positionharry .y+ 1 >= 0)
                break;
        
positionharry.y++;
                harrybas  = IMG_Load("x.jpg");
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionharry);
                break;
            case SDLK_RIGHT:
                 if (positionharry.x - 1 < 0)
                break;
positionharry.x--;
 harrydroit = IMG_Load("x.jpg");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionharry);
  
breaak;
  
            case SDLK_LEFT:
if (positionharry .x+ 1 >= 0)
                break;
                positionharry .x++;
 harrygauche = IMG_Load("x.jpg");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionharry);
                break;
        }
        break;
SDL_Flip(ecran);
return 0;
}

