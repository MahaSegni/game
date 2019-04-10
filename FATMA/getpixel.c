#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

SDL_Color GetPixel (SDL_Surface* pSurface , int x , int y)
{
    SDL_Color color;
    Uint32 col = 0 ;
    if (x >= 0 && y >= 0)
    {
        //determine position
        char* pPosition = ( char* ) pSurface->pixels ;

        //offset by y
        pPosition += ( pSurface->pitch * y ) ;

        //offset by x
        pPosition += ( pSurface->format->BytesPerPixel * x ) ;

        //copy pixel data
        memcpy ( &col , pPosition , pSurface->format->BytesPerPixel ) ;

        //convert color
    }
    SDL_GetRGB ( col , pSurface->format , &color.r , &color.g , &color.b ) ;
    return ( color ) ;
}
