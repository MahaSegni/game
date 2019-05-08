#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "struct.h"






SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;

	
	char* pPosition = ( char* ) surface->pixels ;

	
	pPosition += ( surface->pitch * y ) ;

	
	pPosition += ( surface->format->BytesPerPixel * x ) ;

	
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;

	
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}


int collision_parfaite(SDL_Surface *calque , hero evan)
{
	SDL_Color col;
	SDL_Event event;
	int d;




SDL_PollEvent(event);
 	switch (event->type)
        {
        case SDL_KEYDOWN:
            switch (event->key.keysym.sym)
            {
            case SDLK_RIGHT:
				d=1;
                break;
            case SDLK_LEFT:
            	d=2;
                break;
            }
            break;
 		}












	 if(d==1)//imin
  {
    col=GetPixel(calque,evan.pos_hero2.x,evan.pos_hero2.y);
  }
	else  if(d==2)//issarr
  {
    col=GetPixel(calque,evan.pos_hero2.x,evan.pos_hero2.y);
  }

  if ((col.r==0)&&(col.b==0)&&(col.g==0))
{
  return 1; //ak7el
}
else if ((col.r==0)&&(col.b==0)&&(col.g==255))
{
  return 2; //a5dher
}
else if ((col.r==0)&&(col.b==255)&&(col.g==0))
{
  return 3; //azra9
}
else if ((col.r==2500)&&(col.b==0)&&(col.g==0))
{
  return 4; //a7mer
}
else return 0;
}