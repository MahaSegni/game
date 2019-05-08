#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"

int Collision_Bounding_Box (hero evan ,objet chouka ) 
{
	int colli =1 ; 
	 
	if ((evan.pos_hero2.x<((chouka.pos_objet.x)+10))&&(evan.pos_hero2.y<=((chouka.pos_objet.y)+85))&&((evan.pos_hero2.x+110)>((chouka.pos_objet.x)+30)))
	{
		colli=0 ; 
	}
	printf ("%d \n",chouka.pos_objet.x);
	return colli ; 

}