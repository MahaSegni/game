#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>


int main()
{
    int i=0;
    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
    SDL_Surface *ecran =NULL,*imageDeFond = NULL,*image=NULL,*image2=NULL,*image3=NULL,*image4=NULL,*image5=NULL,*image6=NULL;
    ecran=SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE); // Ouverture de la fenêtre
    SDL_Rect positionFond,positionim,positionim2,positionim3,positionim4,positionim5;
    //bach yefhem les cordonnée
    SDL_WM_SetCaption("Menu", NULL);// esm l fenetre 
    
   
    positionFond.x =  0 ;
    positionFond.y =  0 ;
    positionim.x =0 ;
    positionim.y = 0 ;
    positionim2.x =0 ;
    positionim2.y = 0 ;
    positionim3.x =0 ;
    positionim3.y = 0 ;
    positionim4.x =0 ;
    positionim4.y = 0 ;
positionim5.x =0 ;
    positionim5.y = 0 ;
    imageDeFond = IMG_Load("menu.gif");// hata wahda matech3el
    image= IMG_Load("play.gif");// l play tech3el
    image2= IMG_Load("setting.gif");//setting tech3el
    image3= IMG_Load("help.gif");//l help tech3el
    image4= IMG_Load("exit.gif");//l exit tech3el
image5= IMG_Load("khra.jpg");
image6= IMG_Load("setting.jpg");
    SDL_Flip(ecran);// mise a jours
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)// initiliser mixer
    {
        printf("%s",Mix_GetError());
    }
    Mix_Music *musique;//pointeur musique jeux
    Mix_AllocateChannels(20);//
    musique = Mix_LoadMUS("musique.mp3");//musique jeux
    Mix_PlayMusic(musique, -1);//repeter la music de jeux (boucle infinie)
    Mix_VolumeMusic(MIX_MAX_VOLUME / 1);//MIX_MAX_VOLUME se defere de chaque pc (peut etre 1 ou 2 selement)
    Mix_Chunk *MB;//pointeur music boutton(chunk se defere de formart) chunk pour format wav ; Music pour format mp3
    MB = Mix_LoadWAV("button.wav");// clique de bouton
    SDL_Event event;//clavier et souris
    int continuer = 1;//si continuer=1 il reste dans la boucle while ; si 0 il quite la boucle

    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);//affichage de menu

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_MOUSEBUTTONDOWN:// nzelt ala felsa f souris
           if (event.button.button == SDL_BUTTON_LEFT)// itha kan nzelt ysar
            {

                if ( event.button.x >60 && event.button.y >290 && event.button.x < 230 && event.button.y <340)//les cordonnee win bch tenzel b souris(cordonnee mtaa bouton play)
                {Mix_PlayChannel(1, MB, 0); 
                    SDL_BlitSurface(image,NULL, ecran, &positionim);//l play tech3el
                    SDL_Flip(ecran);//mise a jours 
                    SDL_Delay(400);
                    

                    SDL_BlitSurface(image5,NULL, ecran, &positionim);
 SDL_Flip(ecran);
 SDL_Delay(400);

                }

                if ( event.button.x >60 && event.button.y >365 && event.button.x <230 && event.button.y <395)
                { Mix_PlayChannel(1, MB, 0);
                    SDL_BlitSurface(image2,NULL, ecran, &positionim2);//settings tech3el
                    SDL_Flip(ecran);
                    SDL_Delay(400);
                   

                    SDL_BlitSurface(image6,NULL, ecran, &positionim2);//settings tech3el
                    SDL_Flip(ecran);
                    SDL_Delay(400);
                   
                }
                if ( event.button.x >60 && event.button.y >430 && event.button.x < 230 && event.button.y <485)

                { Mix_PlayChannel(1, MB, 0);
                    SDL_BlitSurface(image3,NULL, ecran, &positionim3);//help tech3el
                    SDL_Flip(ecran);
                    SDL_Delay(400);
                   

                }
                if ( event.button.x >60 && event.button.y >510 && event.button.x < 230 && event.button.y <585)
                { Mix_PlayChannel(1, MB, 0);
                    SDL_BlitSurface(image4,NULL, ecran, &positionim4);//exit tech3el
                    SDL_Flip(ecran);
                    SDL_Delay(400);
                   
                    continuer=0;
                }
            }
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)// win teta9ra l click
            {

            case SDLK_RETURN: //bouton entrer
                if (i==1)
                {

                }
                else if (i==2)
                {
                }
                else if (i==3)
                {

                }
                else if (i==4)
                {
                    continuer=0;
                };
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
                    SDL_Delay(500);
                    Mix_PlayChannel(1, MB, 0);
                }


                break;
            }
        }
          
        SDL_Flip(ecran);//mise a jours
    }

    Mix_FreeMusic(musique);//free espace memoire
    Mix_CloseAudio();//tsakr e sout 
    SDL_Quit(); // Arrêt de la SDL


    return EXIT_SUCCESS; // Fermeture du programme
}
