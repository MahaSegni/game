#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
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



int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap)
{
  SDL_Color col,col2,col22;
  //if(d==0)//imin
  //{
    col=GetPixel(calque,posperso.x+100+posmap.x ,posperso.y+280);

    col2=GetPixel(calque,posperso.x+100+posmap.x ,posperso.y+280);
    col22=GetPixel(calque,posperso.x+100+posmap.x ,posperso.y+250);

  //}
//else  if(d==1)
  //{
   // col=GetPixel(calque,posperso.x ,posperso.y+(perso->h/2));
  //}
//else  if(d==2)
  //{
    //col=GetPixel(calque,posperso.x+(perso->w/2)+ posmap ,posperso.y);
  //}
//else  if(d==3)
  //{
    //col=GetPixel(calque,posperso.x+(perso->w/2),posperso.y+perso->h );
 // }
  printf("%d    %d   %d\n",col.r,col.b,col.g );
if ((col.r==0)&&(col.b==0)&&(col.g==255))
  return 1;
else if ((col.r==0)&&(col.b==0)&&(col.g==0))
  return 2;
else if ((col.r==0)&&(col.b==255)&&(col.g==0))
  return 1;
else if ((col.r==255)&&(col.b==0)&&(col.g==0))
  return 3;
else
{
	return 0;
}
}