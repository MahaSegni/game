#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"

void menu()
{
int i = 0 ;
    SDL_Init(SDL_INIT_VIDEO); 
    SDL_Surface *ecran =NULL,*imageDeFond = NULL,*image=NULL,*image2=NULL,*image3=NULL,*image8=NULL,*image7=NULL,*image4=NULL,*imagedefond2=NULL,*image5=NULL,*image6=NULL;
    ecran=SDL_SetVideoMode(901, 606, 32, SDL_HWSURFACE);
    SDL_Rect positionFond,positionim,positionim2,positionim3,positionim7,positionim4,positionfond2,pos5,positionp;
    SDL_WM_SetCaption("DREAM CHALLENGE ", NULL);

   





    positionFond.x =  0 ;
    positionFond.y =  0 ;
    positionim.x =0 ;
    positionim.y = 0 ;
    positionim2.x =0 ;
    positionim2.y = 0 ;
    positionim3.x =0 ;
    positionim3.y = 0 ;
positionim7.x =0 ;
    positionim7.y = 400 ;
positionim4.x =0 ;
    positionim4.y = 0 ;
positionfond2.x = 0 ;
positionfond2.y = 0 ;
pos5.x = 0 ;
pos5.y = 0 ;
positionp.x = 0 ;
positionp.y = 0 ;

  
    imageDeFond = IMG_Load("menu.gif");
    image= IMG_Load("play.jpg");
    image2= IMG_Load("setting.jpg");
    image3= IMG_Load("exit.jpg");
    image4= IMG_Load("help.jpg");
imagedefond2= IMG_Load("menu.jpg");
image5= IMG_Load("sett.jpg");
image6=IMG_Load("backgro.jpg");
image7=IMG_Load("ini.png");
 
image8=IMG_Load("0.png");



    
    SDL_Flip(ecran);
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s",Mix_GetError());
    }


Mix_Music *musique;
    Mix_AllocateChannels(20);
    musique = Mix_LoadMUS("menu.mp3");
    Mix_PlayMusic(musique, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 1);
    Mix_Chunk *MB;
    MB = Mix_LoadWAV("button.wav");
    SDL_Event event;
    int continuer = 1;

    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);



 while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;

            break;
        case SDL_MOUSEBUTTONDOWN:
           if (event.button.button == SDL_BUTTON_LEFT)
            {

                if ( event.button.x >85.4 && event.button.y >270 && event.button.x < 251.7 && event.button.y <318)
                {
                    SDL_BlitSurface(image,NULL, ecran, &positionim);
                    SDL_Flip(ecran); 
                    SDL_Delay(500);
Mix_PlayChannel(1, MB, 0);
SDL_BlitSurface(image6,NULL, ecran, &positionim);
SDL_BlitSurface(image7,NULL, ecran, &positionim7);
SDL_BlitSurface(image8,NULL, ecran, &positionim);

                }

                if ( event.button.x >85.4 && event.button.y >340.5 && event.button.x <251.7 && event.button.y <385.5)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim2);
                    SDL_Flip(ecran);
                    SDL_Delay(400);
                    Mix_PlayChannel(1, MB, 0);
                  SDL_BlitSurface(image5, NULL, ecran, &positionFond); 
                }
  if ( event.button.x >85.4 && event.button.y >406.5 && event.button.x <251.7 && event.button.y <453)
                {
                    SDL_BlitSurface(image4,NULL, ecran, &positionim4);
                    SDL_Flip(ecran);
                    SDL_Delay(400);
                    Mix_PlayChannel(1, MB, 0);
                   
                }
                      
                

                 if ( event.button.x >85.4 && event.button.y >480 && event.button.x < 251.7 && event.button.y <526.5)

                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim3);
                    SDL_Flip(ecran);
                    SDL_Delay(400);
                    Mix_PlayChannel(1, MB, 0);
                          continuer = 0 ;

                }

                          if ( event.button.x >85.4 && event.button.y >39 && event.button.x < 251.7 && event.button.y <44)

                {
                    SDL_BlitSurface(imagedefond2,NULL, ecran, &positionfond2);
                    SDL_Flip(ecran);
                     SDL_Delay(400);
                    Mix_PlayChannel(1, MB, 0);
                }
                
                }
            
            break;




case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {

            case SDLK_RETURN: 
                if (i==1)
                {
SDL_BlitSurface(image5,NULL, ecran, &pos5);
                }
                else if (i==2)
                {
//SDL_BlitSurface(image4,NULL, ecran, &positionim4);
                }
                else if (i==3)
                {
                continuer=0;
                }else if (i==4)
                {
                
                }
                
                break;

            case SDLK_DOWN:
                i++;
                if(i==5)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);

                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim2);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);

                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim3);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
Mix_PlayChannel(1, MB, 0);

                }
if(i==4)
                {
                    SDL_BlitSurface(image4,NULL, ecran, &positionim4);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
Mix_PlayChannel(1, MB, 0);

                }
                
                
                
                break;
            case SDLK_UP:
                i--;
                if(i==-1)
                {
                    i=5;
                }
                if(i==5)
                {
                    i=4;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim2);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);
    
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim3);
                    SDL_Flip(ecran);
                    SDL_Delay(500) ;  
                    Mix_PlayChannel(1, MB, 0);
                }
  if(i==4)
                {
                     SDL_BlitSurface(image4,NULL, ecran, &positionim4);
                    SDL_Flip(ecran);
                    SDL_Delay(500) ;  
                    Mix_PlayChannel(1, MB, 0);
                }
                


                break;
}



}

          
 


 SDL_Flip(ecran);
    }
     Mix_FreeMusic(musique);
    Mix_CloseAudio();
    SDL_Quit(); 


    
}


























