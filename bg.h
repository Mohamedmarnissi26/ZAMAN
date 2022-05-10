#ifndef _BG_H_
#define _BG_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "getpixel.h"
typedef struct{
SDL_Rect pos;
SDL_Surface *is[50];//imagesbg si il ya une animation
int anim;//numéro image bg
SDL_Surface *m;//masque
}bg;

void init_bg(bg *bg);
void afficher_bg(bg bg,SDL_Surface *screen);
void anim_bg(bg *bg);
void scrolling(bg *bg,int d,int pas);
void bg_in_borders(bg *bg,SDL_Surface *screen);
void changement_imagebg(bg* bg);
void animation_start(SDL_Surface *screen);
void musique();
void partage_ecran(bg bg1,bg bg2,SDL_Surface *screen);

#endif
