#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_W 1005
#define SCREEN_H 248

typedef struct
{

  TTF_Font    * poli_score;
  SDL_Surface * txt_score;
  SDL_Rect    pos_score;
  SDL_Color  textColor;
  int i;  
}score_personne;
   
typedef struct
{
  SDL_Surface * imvie[4];
  SDL_Rect      pos_vie;
  int         nb_vie;
}vie_personne;

typedef struct
{

                SDL_Surface * img[10];
               
                   
SDL_Rect    pos_p;
vie_personne   vie  ;
score_personne score ;

int        accelerer ;
int        vitesse;      
 
    int        direction;// 0:right,1:left
                int        num ; //num img 0:walk,1:run,2:jump,3:superjump,4:attack
                int        up;                          
     
    }personne;
   



void initPerso(personne *p,int x, int y);

void afficherPerso(personne p,int num, SDL_Surface * screen);

void deplacer_perso(personne *p,Uint32 dt,int direction);

void jump_perso(personne *p,int * num,int direction );
       
        void animer_perso(personne *p,int * num,int direction );

void attack_perso(personne *p,int* num,int direction);


#endif
