#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "object.h"


int collisiontrigoinscrit (SDL_Rect posj ,SDL_Rect posobj) 
{
SDL_Rect rayon , rayonobj ; 
int x ; 

rayon.x=(posj.x+posj.w)/2 ;
rayon.y=(posj.y+posj.h)/2; 

rayonobj.x=(posobj.x+posobj.w)/2 ;
rayonobj.y=(posobj.y+posobj.h)/2 ;

if ((rayon.x>=rayonobj.x)&&(rayon.x<=rayonobj.x+(posobj.w/2))&&(rayon.y>=posobj.y))
x=1 ; 
else 
x=0 ;

 return x ; 

}


