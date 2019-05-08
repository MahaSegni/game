
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
/** 
 * @struct enigme
* @brief struct for enigmas
 */
typedef struct 
{
 SDL_Surface * img; /*!< Surface. */ 
 SDL_Rect 	p; /*!< rectangle. */ 
}enigme;

void init_enigme(enigme * en) ;
void  generate_afficher (SDL_Surface * screen  , char image [],enigme *en,int *alea) ;
 int solution_e (char image []) ;
int resolution (int * running,int *run);
void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en) ;
