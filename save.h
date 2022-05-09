#ifndef save_H_INCLUDED
#define save_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//#include "perso.h"

/*typedef struct save
{
personne p;
background b;
}save;*/

void sauvegarder (personne p,background b) ;
int charger (personne *p,background *b);

#endif
