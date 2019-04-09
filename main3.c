    
#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "d.h"
#include "q.h"

int main()
{
SDL_Surface *screen ; 
Objet Obj, Obj1 ; 
SDL_Event event ; 
int done=0 , x ; 

 if  ( SDL_Init ( SDL_INIT_VIDEO )  == -1 )  { 
         printf ( "Can not init SDL \n " ); 
 
     } 

     screen  =  SDL_SetVideoMode ( 1280 ,  720 ,  32 ,  SDL_HWSURFACE  |  SDL_DOUBLEBUF ); 
     if  ( screen  ==  NULL )  { 
         printf ( "Can not set video mode: \n "); 
         
     } 
     SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255)); 

    initialiserObj( &Obj ,"xc.png" ,  0 ,  0 ) ; 
    affichageObj (Obj ,screen) ;
    initialiserObj( &Obj1 ,"vc.png" ,  500 ,  200 ) ; 
    affichageObj (Obj1 ,screen) ;
   SDL_EnableKeyRepeat(10,10) ; 
    while  ( done==0 )  { 
         while  (SDL_PollEvent ( &event ))  { 
             switch  ( event.type )  { 
             case  SDL_QUIT : 
                 done  =  1 ; 
                 break ;  
    case SDL_KEYDOWN:

        switch(event.key.keysym.sym)

        {
      case SDLK_ESCAPE : 
done=1 ; 

case SDLK_LEFT : 

Obj.position.x-=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;

break ; 

case SDLK_RIGHT : 

Obj.position.x+=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;
break ; 
case SDLK_UP : 

Obj.position.y-=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;
break ; 
case SDLK_DOWN : 

Obj.position.y+=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;
break ; 


                 
			 }
x=CollisionTrigoCir(Obj.position,Obj1.position) ;

if(x==1) 
{
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  0 , 0));
SDL_Flip(screen) ; 
}
break ; 

		 }
	 }


}

return 0 ; 
}
