#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *zozor = NULL,*fond=NULL;
    SDL_Rect positionZozor,pos,poss;
    SDL_Event event;
    int continuer = 1;


    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Gestion des évènements en SDL", NULL);
    fond=IMG_Load("backgro.jpg");
    zozor = IMG_Load("1.png");





    positionZozor.x = 0;
    positionZozor.y = 260;
    pos.x=0;
    pos.y=0;

    poss.x=0;
    poss.y=0;
    SDL_EnableKeyRepeat(10, 10); /* Activation de la répétition des touches */




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
                    case SDLK_UP:
                        positionZozor.y=positionZozor.y-90;positionZozor.x=positionZozor.x+50;
                        break;
                    case SDLK_DOWN:
                        positionZozor.y++;
                        break;
                    case SDLK_RIGHT:
                        positionZozor.x++;
                        break;
                    case SDLK_LEFT:
                        positionZozor.x--;
                        break;
                    case SDLK_SPACE	:
                    positionZozor.x=positionZozor.x+10;
                }
                break;
        }
        SDL_BlitSurface(fond,NULL,ecran,&pos);
        SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
        SDL_Flip(ecran);
        }







   SDL_FreeSurface(fond);
    SDL_FreeSurface(zozor);
    SDL_Quit();

    return EXIT_SUCCESS;
}
