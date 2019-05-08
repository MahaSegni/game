/** 
 * @file enigf.c 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enig.h"

void init_enigme(enigme * en)
{
	en->p.x=0;
	en->p.y=0;	
	en->img=NULL;


}
/**  * @brief  generer et afficher l enigme e . 
*/
 void generate_afficher (SDL_Surface * screen  , char image [],enigme *en,int *alea)
{ 
	int test=*alea ;
do{
 *alea = 1+ rand()%6;
}while(*alea==test) ;
 sprintf(image ,"h%d.jpg",*alea);
en->img = IMG_Load(image);
 SDL_BlitSurface(en->img,NULL,screen,&(en->p)) ;
  SDL_Flip(screen) ;
}
 /**  * @brief solution de l enigme . 
 * @param image char    
 * @return int
 */
 int solution_e (char image [])
 {
 	int solution =0 ;
 	
 	if(strcmp(image,"h1.jpg")==0)
 	{
     solution =3 ;
 	}
 	else  	if(strcmp(image,"h2.jpg")==0)
 	{
 		solution =1;

 	}
 	else 	if(strcmp(image,"h3.jpg")==0)
 	{
 		solution =3;	
 	}
        else 	if(strcmp(image,"h4.jpg")==0)
 	{
 		solution =1;	
 	}
        else 	if(strcmp(image,"5.jpg")==0)
 	{
 		solution =3;	
 	}
        else 	if(strcmp(image,"6.jpg")==0)
 	{
 		solution =3;	
 	}
 	return solution;
 }
/**  * @brief  resolution de lenigme . 
 * @param run eint
 * @param running int  
 * @return int
 */
int resolution (int * running,int *run )
{
	SDL_Event event ;
  int r=0 ;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
			        *running= 0 ;
                *run = 0;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  r= 1;
			   break ;
			   case  SDLK_z :
			   r= 2;
			   break;
			   case SDLK_e: 
			   r=3 ;
			   break;
			    }
       break ;

                 
	}
  return r ;
}
 /**  * @brief  affichage de resultat .
 * @param screen surface 
 * @params int
 * @paramr int 
 * @paramen enigme  
 * @return Nothing 
 */
 void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en)
 {
 
 	if (r==s)
 	{
 		en->img=IMG_Load("10.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
 	else
 	{
 		en->img=IMG_Load("01.png");
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
 	}
 }
 
