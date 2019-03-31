#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *hero = NULL,*vie = NULL;
 SDL_Rect positionvie, positionhero;
    SDL_Event event;
    int continuer = 1;


    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Gestion des événements en SDL", NULL);



hero = IMG_Load("ini.png");
  SDL_BlitSurface(hero, NULL, ecran, &positionhero);
   SDL_SetColorKey(hero, SDL_SRCCOLORKEY, SDL_MapRGB(hero->format, 0, 0, 255));
vie = IMG_Load("vie.png");
  SDL_BlitSurface(vie, NULL, ecran, &positionvie);
 

    /* On centre hero à l'écran */
    positionhero.x = ecran->w / 2 - hero->w / 2;
    positionhero.y = ecran->h / 2 - hero->h / 2;

   
    
        /* On efface l'écran */
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
       
        SDL_BlitSurface(hero, NULL, ecran, &positionhero);
        SDL_BlitSurface(vie, NULL, ecran, &positionvie);
        /* On met à jour l'affichage */
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(hero);
 SDL_FreeSurface(vie);
    SDL_Quit();

    return EXIT_SUCCESS;
}
