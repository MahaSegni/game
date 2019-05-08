#include <stdio.h>
#include "SDL/SDL.h"
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include"struct.h"
#include "enig.h"
void main(void)
{
	SDL_Surface *ecran =NULL;
	hero evan ;
	int continuer =1;
	objet chouka;
	

	background bckg;
SDL_Surface *img1=NULL;
	int k,a;
	menu menu;
int s,r,run =1,running=1,alea;
enigme q;


	
	//int i;
	SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    initialiser_background(&bckg);
    initialiser_evan(&evan);
   initialiser_objet(&chouka);
   initialiser_menu(&menu);
    SDL_Event event;
   evan.farm=0;
   Enemy e;
   int stat;
   e=InitEnemy(e,5500,350);
SDL_Rect im;
SDL_Rect im1;
im1.x=200;
im1.y=200;
char image[30]="";
	
    srand(time(NULL));

    //usleep(20000000);
	while(continuer){
		if (menu.action==1){
			 k=affcihier(&menu,ecran);

			 SDL_Flip(ecran);
		}
		//SDL_Flip(ecran);
		if(menu.action==10){

			afficher_background(bckg,ecran);
img1=IMG_Load("v.png");
SDL_BlitSurface(img1,NULL, ecran, &im1);
 SDL_Flip(ecran);



    //start
    
    

			afficher_evan(evan,ecran);
img1=IMG_Load("v.png");
SDL_BlitSurface(img1,NULL, ecran, &im1);
 SDL_Flip(ecran);
if  ((evan.pos_hero2.y+evan.pos_hero2.h>= im1.y)&&(evan.pos_hero2.y<=im1.y+im1.h
)&&((evan.pos_hero2.x+evan.pos_hero2.w>=im1.x)&&(evan.pos_hero2.x<=im1.x+im1.w)) )
{
 while (run)
	 {
	    running=1,r=0 ;
	     SDL_PollEvent(&event);
           switch(event.type)
            {
              case SDL_QUIT:
                run = 0;
			  break ;
            }	
        	
      generate_afficher ( ecran , image ,&q,&alea) ;
	        

      s=solution_e (image );
			do{
			r=resolution (&running,&run);
			}while((r>3 || r<1) && running!=0) ;
			
			
      while(running){

				afficher_resultat ( ecran ,s,r,&q) ;
			       SDL_WaitEvent(&event);
                     switch(event.type)
                       {
					     case SDL_QUIT :
                              running =0 ;
						      run=0 ;
					     break ;
                         case SDL_KEYDOWN :
						    
                             switch( event.key.keysym.sym )
                                  {
			                        case  SDLK_ESCAPE: 
			                           running= 0 ;
			                        break ;
			                      }
						 break ;
                       }
                    } 	
   }
      SDL_FreeSurface( ecran );



}


			evan.farm=animation_perso(evan);
			afficher_objet(&chouka,ecran,evan);

		
			e=MoveEnemy(e,evan.pos_hero2,&stat,evan.mouvment);
			e=AnimateEnemy(e,stat);
			 AfficherEnemy(e,ecran);

			
			printf("%d a\n",bckg.pos_background2.x);
			SDL_Flip(ecran);
			if(Collision_Bounding_Box (evan,chouka )==0){
				printf("opss\n");
			}
			evan.mouvment= mouvment(evan,&event);

			if (evan.mouvment==0){
				continuer=0;
			}
				scrolling(&evan,&bckg);
			
    
       
			
		
				a=collision_Parfaite(bckg.calque_background,evan.afficher_hero[evan.farm],evan.pos_hero2,bckg.pos_background2);
		}

  
 
		if(menu.action==0)	
			continuer=0;
	}
}
