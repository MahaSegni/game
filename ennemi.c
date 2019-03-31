#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */

 
 
int main(int argc, char *argv[])//fonction principale
{
  int continuer = 1 , tempsActuel=0 , tempsPrecedent=0 ;
    SDL_Event event;

SDL_Surface *ecran = NULL, *imageDeFond = NULL, *personnage= NULL ;
SDL_Rect positionFond, positionPerso ;
 
    positionFond.x = 0;
    positionFond.y = 0;

    positionPerso.x = 0;
    positionPerso.y = 200;
    

   imageDeFond = IMG_Load("fond.jpg");
   personnage = IMG_Load("perso.png");
 
       

 SDL_SetColorKey(personnage, SDL_SRCCOLORKEY, SDL_MapRGB(personnage->format,255, 255,255));
 

SDL_Init(SDL_INIT_VIDEO);//initialisation

  ecran = SDL_SetVideoMode(600, 480, 32, SDL_HWSURFACE |SDL_DOUBLEBUF);//creation fenetre
    
    SDL_WM_SetCaption("deplacer un ennemi", NULL);

SDL_EnableKeyRepeat(10,10);

 while (continuer)
{
  SDL_PollEvent(&event);

tempsActuel = SDL_GetTicks();
    

if (tempsActuel - tempsPrecedent > 0.5) /* Si 0.5 ms se sont écoulées */
    {
    positionPerso.x++; /* On bouge le personnager */
    tempsPrecedent = tempsActuel; /* Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
    }

   else /* Si ça fait moins de 0.5 ms depuis le dernier tour de boucle, on endort le programme le temps qu'il faut */
    {
    SDL_Delay(0.5 - (tempsActuel - tempsPrecedent));  
    }


        switch(event.type)
        {
          case SDL_QUIT:
                continuer = 0;
               break;

          case SDL_KEYDOWN: /* Si appui sur une touche */
                   switch(event.key.keysym.sym)
        {
            case SDLK_UP: // Flèche haut
                positionPerso.y-=10;
           SDL_WaitEvent(&event);
                break;
            case SDLK_DOWN: // Flèche bas
                positionPerso.y+=10;
            SDL_WaitEvent(&event);       
                break;
            case SDLK_RIGHT: // Flèche droite
                positionPerso.x+=10;
             SDL_WaitEvent(&event);
                break;
            case SDLK_LEFT: // Flèche gauche
                positionPerso.x-=10;
              SDL_WaitEvent(&event);
                break;
        }
               break;

         case SDL_MOUSEMOTION:
             if(event.button.button == SDL_BUTTON_LEFT)
                {

            positionPerso.x = event.button.x;//on récupère les coordonnées
            positionPerso.y = event.button.y;

                }


            break;
        
        }
      SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
      SDL_BlitSurface(personnage, NULL, ecran, &positionPerso);

     
     
  SDL_Flip(ecran);//mise a jour
}

    
 
 
SDL_FreeSurface(imageDeFond);
SDL_FreeSurface(personnage);


  SDL_Quit();//arret de la SDL
 
    return EXIT_SUCCESS;//fermeture du programme
}
 

 

    
 
    
       

