#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <time.h>
/**
*@struct enigme
*@brief struct for enigme
*/

typedef struct{

SDL_Surface *image;  /*!< Surface */
SDL_Rect pos_image;/*!< Rectangle.  */

SDL_Surface *reponse1; /*!< Surface */
SDL_Surface *reponse2; /*!< Surface */
SDL_Surface *reponse3; /*!< Surface */
SDL_Rect pos_reponse;/*!< Rectangle.  */

SDL_Surface *correct; /*!< Surface */
SDL_Rect pos_correct;/*!< Cercle.  */

SDL_Surface *wrong; /*!< Surface */
SDL_Rect pos_wrong;/*!< Cercle.  */

/*SDL_Surface *solution;
SDL_Rect pos_solution;*/

int d; //l noumrou mta3 l question yama 1 ou 2 ou 3 ..... ou 7 o ali ikoune aléatoire a l'aide de la fonction rand ();

}enigme;

void InitEnigme(enigme *e ,char *nomfichier[] );
void afficherEnigme(enigme e,SDL_Surface *screen);
void resolution(SDL_Surface *screen,enigme *e);
void correct(SDL_Surface *screen,enigme *e);
void wrong(SDL_Surface *screen,enigme *e);
//void animer(enigmeif t1[]);
void generer(enigme *e);


#endif 
