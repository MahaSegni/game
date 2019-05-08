#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"struct.h"
void scrolling (hero *evan,background *bckg )
{
	switch(evan->mouvment)
	{
				
		case 1: 
			if ((bckg->pos_background2.x<6800)&&(evan->pos_hero2.x>=300))
                		bckg->pos_background2.x=bckg->pos_background2.x+5;
			if (((evan->pos_hero2.x<300)||((bckg->pos_background2.x>=6800))&&(evan->pos_hero2.x<1100)))
				evan->pos_hero2.x=evan->pos_hero2.x+5;
	
		break;
		case 2:
			if (bckg->pos_background2.x>0)
                		bckg->pos_background2.x=bckg->pos_background2.x-5;
	    		if (((bckg->pos_background2.x!=0)&&(evan->pos_hero2.x>=150))||((bckg->pos_background2.x==0)&&(evan->pos_hero2.x=50)))
				
		break;
		case 3:

		//if (evan->pos_hero2.y>50){
			if (bckg->pos_background2.x<6800){
				evan->pos_hero2.y=evan->pos_hero2.y-50;
				//evan->pos_hero2.x=evan->pos_hero2.x+20;
				bckg->pos_background2.x=bckg->pos_background2.x+50;
			}
		//}
		break;
	}
	if ((evan->mouvment!=3)&&(evan->pos_hero2.y<290)){
		evan->pos_hero2.y=evan->pos_hero2.y+5;
	}
}




