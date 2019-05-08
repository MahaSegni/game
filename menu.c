#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <unistd.h>
#include"struct.h"

void  affichier_quit(menu *menu,SDL_Surface *ecran,int x,int y){
	SDL_BlitSurface(menu->sousmenuquit, NULL, ecran, &menu->positionsousmenuquit);
	if ((470<=x)&&(x<=510)&&(y<=510)&&(300<=y)) //no
		menu->boutoneffet=331;
	else if((400<=x)&&(x<=435)&&(y<=453)&&(300<=y))//yes
		menu->boutoneffet=332;
}
void affichier_option(menu *menu,SDL_Surface *ecran,int x,int y);
int isMouseEvent(const SDL_Event* event)
{
    if (event->type == SDL_MOUSEMOTION)
        return 0;
    return 1;
}


/*void sousmenu(){

	SDL_BlitSurface(msetting, NULL, ecran, &menu->positionecran);

}*/

int controle_menu (){

	SDL_Event e;
	SDL_PollEvent(&e);

	switch (e.type)
        {
        case SDL_QUIT:
            	return 0;
            break;
        case SDL_KEYDOWN:
            switch (e.key.keysym.sym)
            {
            case SDLK_ESCAPE:
            	return 10;
                break;
            case SDLK_RIGHT:
            	return 1;
            break;

            case SDLK_LEFT:
            	return 2;
           }
           break;
        	case SDL_MOUSEBUTTONUP:
        		return 5;

                    break;
            default: 	return 9;
		}



}
void initialiser_menu(menu *menu){
	
	menu->background=NULL;
	menu->bplay=NULL;
	menu->beplay=NULL;
	menu->droit=NULL;
	menu->droite=NULL;
	menu->gauche=NULL;
	menu->gauchee=NULL;
	menu->msetting=NULL;
	menu->besetting=NULL,
	menu->bsetting=NULL;
	menu->bquit=NULL;
	menu->bequit=NULL;


	menu->sousmenuquit=NULL;
	menu->positionsousmenuquit.x=0;
	menu->positionsousmenuquit.y=0;
	menu->sousmenuquit=IMG_Load("exit.png");
	//menu->sousmenuquit=IMG_Load("exit1q.png");
	
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
    Mix_OpenAudio(48000, AUDIO_S16SYS, 1, 2048);
	Mix_VolumeMusic(MIX_MAX_VOLUME/2);
	menu->son=Mix_LoadMUS("switchoff.wav");


	menu->background=IMG_Load("menu1.png");
	menu->bplay=IMG_Load("play.png");
	menu->beplay=IMG_Load("playe.png");
	menu->gauche=IMG_Load("g1.png");
	menu->droit=IMG_Load("d1.png");
	menu->gauchee=IMG_Load("g2.png");
	menu->droite=IMG_Load("d2.png");
	menu->bsetting=IMG_Load("setting.png");
	menu->besetting=IMG_Load("settinge.png");
	menu->bquit=IMG_Load("quit.png");
	menu->bequit=IMG_Load("quite.png");
	menu->msetting=IMG_Load("sett.jpg");

	menu->positionbplay.x=320;
	menu->positionbplay.y=180;

	menu->positiondroit.x=600;
	menu->positiondroit.y=255;

	menu->positiongauche.x=240;
	menu->positiongauche.y=250;

	menu->positionecran.x=0;
	menu->positionecran.y=0;
	menu->action=1;
	menu->po=1;
}

int affcihier(menu *menu,SDL_Surface *ecran){	
	int x,y;
	int d;
 if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)// initiliser mixer
    {
        printf("%s",Mix_GetError());
    }
Mix_Music *musique;//pointeur musique
    Mix_AllocateChannels(20);
    musique = Mix_LoadMUS("menu.mp3");//musique
    Mix_PlayMusic(musique, -1);//repeter la music de jeux (boucle infinie)
    Mix_VolumeMusic(MIX_MAX_VOLUME / 1);//volume 
		//SDL_SetEventFilter(isMouseEvent);
		//SDL_PollEvent(&e);
		SDL_GetMouseState(&x,&y);
	if(menu->po==2){
		       if ((340<=x)&&(x<=602)&&(y<=464)&&(198<=y)){

			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->droit, NULL, ecran, &menu->positiondroit);
			SDL_BlitSurface(menu->besetting,NULL,ecran,&menu->positionbplay);
			SDL_BlitSurface(menu->gauche, NULL, ecran, &menu->positiongauche);
			menu->boutoneffet=22;
		}

		else if ((619<=x)&&(x<=688)&&(y<=384)&&(274<=y)){
			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->bsetting,NULL,ecran,&menu->positionbplay);
			SDL_BlitSurface(menu->droite, NULL, ecran, &menu->positiondroit);
			SDL_BlitSurface(menu->gauche, NULL, ecran, &menu->positiongauche);

			menu->boutoneffet=23;
		}
		else if ((260<=x)&&(x<=324)&&(y<=381)&&(274<=y)){
			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->bsetting,NULL,ecran,&menu->positionbplay);
			SDL_BlitSurface(menu->droit, NULL, ecran, &menu->positiondroit);
			SDL_BlitSurface(menu->gauchee, NULL, ecran, &menu->positiongauche);
			menu->boutoneffet=21;

		}
		else{
			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->bsetting,NULL,ecran,&menu->positionbplay);
			SDL_BlitSurface(menu->droit, NULL, ecran, &menu->positiondroit);
			SDL_BlitSurface(menu->gauche, NULL, ecran, &menu->positiongauche);
			menu->boutoneffet=0;

		}
			}

	else if (menu->po==1){
		       if ((340<=x)&&(x<=602)&&(y<=464)&&(198<=y)){

			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->droit, NULL, ecran, &menu->positiondroit);
			SDL_BlitSurface(menu->beplay,NULL,ecran,&menu->positionbplay);
			menu->boutoneffet=12;

		}

		else if ((619<=x)&&(x<=688)&&(y<=384)&&(274<=y)){
			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->bplay,NULL,ecran,&menu->positionbplay);
			SDL_BlitSurface(menu->droite, NULL, ecran, &menu->positiondroit);
			menu->boutoneffet=13;
		}
		else{
			SDL_BlitSurface(menu->background, NULL, ecran, &(menu->positionecran));
			SDL_BlitSurface(menu->bplay,NULL,ecran,&(menu->positionbplay));
			SDL_BlitSurface(menu->droit, NULL, ecran, &(menu->positiondroit));
			SDL_Flip(ecran);
			menu->boutoneffet=10;
		}
	}

	else if (menu->po==3){
		       if ((340<=x)&&(x<=602)&&(y<=464)&&(198<=y)){

			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->bequit,NULL,ecran,&menu->positionbplay);
			SDL_BlitSurface(menu->gauche, NULL, ecran, &menu->positiongauche);
			menu->boutoneffet=32;
		}
		else if ((260<=x)&&(x<=324)&&(y<=381)&&(274<=y)){
			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->bquit,NULL,ecran,&menu->positionbplay);
			SDL_BlitSurface(menu->gauchee, NULL, ecran, &menu->positiongauche);
			menu->boutoneffet=31;
		}
		else{
			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->bquit,NULL,ecran,&menu->positionbplay);
			SDL_BlitSurface(menu->gauche, NULL, ecran, &menu->positiongauche);
			menu->boutoneffet=30;
		}
	}
	else if(menu->po==22){ // setting 
			SDL_BlitSurface(menu->msetting, NULL, ecran, &menu->positionecran);

         if ((282<=x)&&(x<=488)&&(y<=461)&&(416<=y)){
                        SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->droit, NULL, ecran, &menu->positiondroit);
			SDL_BlitSurface(menu->besetting,NULL,ecran,&menu->positionbplay);
			SDL_BlitSurface(menu->gauche, NULL, ecran, &menu->positiongauche);
			//menu->boutoneffet=22;
//affichier_quit(menu,ecran,x,y);
		   }else if ((282<=x)&&(x<=488)&&(y<=308)&&(267<=y)){
			SDL_BlitSurface(menu->background, NULL, ecran, &menu->positionecran);
			SDL_BlitSurface(menu->bquit,NULL,ecran,&menu->positionbplay);
			SDL_BlitSurface(menu->gauchee, NULL, ecran, &menu->positiongauche);
		
SDL_Surface *screen , *red, *blue, *bg;
	SDL_Event event;
	int running = 1;

	screen = SDL_SetVideoMode(700,480,32,SDL_HWSURFACE);
	
	red = SDL_CreateRGBSurface(0,32,32,32,0,0,0,0);
	SDL_FillRect(red,NULL,0xff0000);

	blue = SDL_CreateRGBSurface(0,32,32,32,0,0,0,0);
	SDL_FillRect(blue,NULL,0xff);

	bg = IMG_Load("back3.png");

	SDL_Rect topClip = {0,300,8000,240};
	SDL_Rect topPosition = {0,0};

	SDL_Rect bottomClip = {0,300,8000,240};
	SDL_Rect bottomPosition = {0,240};

	SDL_Rect player1 = {400-16-32,300-32};
	SDL_Rect player2 = {400-16+32,600-32};

	SDL_EnableKeyRepeat(10,10);

	while(running) {
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
					running = 0;
			if(event.type == SDL_KEYDOWN) {
				if(event.key.keysym.sym == SDLK_ESCAPE)
						running = 0;
				if(event.key.keysym.sym == SDLK_RIGHT) {
					player1.x += 5;
				}
				if(event.key.keysym.sym == SDLK_LEFT) {
					player1.x -= 5;
				}
				if(event.key.keysym.sym == SDLK_d) {
					player2.x += 5;
				}
				if(event.key.keysym.sym == SDLK_s) {
					player2.x -= 5;
				}
			}
		}
		
		SDL_BlitSurface(bg,&bottomClip,screen,&bottomPosition);
		SDL_BlitSurface(bg,&topClip,screen,&topPosition);

		SDL_Rect player1Top = {player1.x - topClip.x,240-32};
		SDL_BlitSurface(red,NULL,screen,&player1Top);
		SDL_Rect player1Bottom = {player1.x - bottomClip.x,480-32};
		SDL_BlitSurface(red,NULL,screen,&player1Bottom);

		SDL_Rect player2Top = {player2.x - topClip.x,240-32};
		SDL_BlitSurface(blue,NULL,screen,&player2Top);
		SDL_Rect player2Bottom = {player2.x - bottomClip.x,480-32};
		SDL_BlitSurface(blue,NULL,screen,&player2Bottom);

		topClip.x = player1.x - 384;
		if(topClip.x < 0)
			topClip.x = 0;
		if(topClip.x > 7100)
			topClip.x = 7100;

		bottomClip.x = player2.x - 384;
		if(bottomClip.x < 0)
			bottomClip.x = 0;
		if(bottomClip.x > 7100)
			bottomClip.x = 7100;


		SDL_Flip(screen);
		SDL_Delay(16);
	}
		}
	else if (menu->po==33){
		affichier_quit(menu,ecran,x,y);
	}}

	SDL_Flip(ecran);
		printf("%d \t %d \n",x,y);

		if (controle_menu()==0)
            menu->action=0;

        if (controle_menu()==10){
			if (menu->po==22)
				menu->po=1;
			else
                 menu->action=0;
        }
 		if (controle_menu()==1){
			Mix_PlayMusic(menu->son,0);
 Mix_PlayMusic(musique, 0);
 		
			if(menu->po==1){
    			menu->po=2;
				SDL_BlitSurface(menu->droite, NULL, ecran, &menu->positiondroit);
				SDL_Flip(ecran);
				usleep(300000);
			}
			else if (menu->po==2){
				menu->po=3;
				SDL_BlitSurface(menu->droite, NULL, ecran, &menu->positiondroit);
				SDL_Flip(ecran);
				usleep(300000);
			}
	}
		if (controle_menu()==2){
			Mix_PlayMusic(menu->son,0);
Mix_PlayMusic(musique, 0);
			if (menu->po==2){
	                menu->po=1;
				SDL_BlitSurface(menu->gauchee, NULL, ecran, &menu->positiongauche);
				SDL_Flip(ecran);
				usleep(300000);
			}

			else if(menu->po==3){
				menu->po=2;
				SDL_BlitSurface(menu->gauchee, NULL, ecran, &menu->positiongauche);
				SDL_Flip(ecran);
				usleep(300000);
            	}
            }

        if(controle_menu()==5){
        	
       		if((menu->boutoneffet==13)&&(menu->po==1)){
				menu->po=2;
				Mix_PlayMusic(menu->son,0);
Mix_PlayMusic(musique, 0);
			}
			else if ((menu->boutoneffet==23)&&(menu->po==2)){
				menu->po=3;
				Mix_PlayMusic(menu->son,0);
Mix_PlayMusic(musique, 0);
			}
			else if ((menu->boutoneffet==21)&&(menu->po==2)){
				menu->po=1;
				Mix_PlayMusic(menu->son,0);
Mix_PlayMusic(musique, 0);
			}
			else if ((menu->boutoneffet==31)&&(menu->po==3)){
				menu->po=2;
				Mix_PlayMusic(menu->son,0);
Mix_PlayMusic(musique, 0);
			}
			else if ((menu->boutoneffet==32)&&(menu->po==3)){
				menu->po=33;
				Mix_PlayMusic(menu->son,0);
Mix_PlayMusic(musique, 0);
			}
			else if ((menu->boutoneffet==22)&&(menu->po==2)){
				menu->po=22;
				Mix_PlayMusic(menu->son,0);
Mix_PlayMusic(musique, 0);
			}
			else if(((menu->boutoneffet==12)&&(menu->po==1)))
				menu->action=10;
			else if ((menu->boutoneffet==331)&&(menu->po==33))
				menu->po=1;
			else if ((menu->boutoneffet==332)&&(menu->po==33))
				menu->action=0;
		}
      printf("%d\n\n",menu->boutoneffet );
	return menu->action;
}

