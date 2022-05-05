#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "perso.h"

int main()
{

   
    SDL_Surface *screen,*backg;
    SDL_Rect pos_p;

    pos_p.x=0;
    pos_p.y=0;
    pos_p.w=1005;
    pos_p.h=248;

   


    personne p, p1 ;
    Uint32 dt=5;
   
 
   int done=0;
   int direction=0;
   int num=0;

SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);
   TTF_Init();
   SDL_Event event;
 

  screen=SDL_SetVideoMode(SCREEN_W ,SCREEN_H,32, SDL_HWSURFACE | SDL_DOUBLEBUF) ;
   if(!screen)
     {
         printf("unable to set video mode:%s",SDL_GetError());
      //return 1;
     }

    Mix_AllocateChannels(20);
    SDL_WM_SetCaption("SDL_Mixer", NULL);
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      printf("%s", Mix_GetError());
    }

Mix_Music *musique;


    musique = Mix_LoadMUS("music.mp3");

Mix_VolumeMusic(MIX_MAX_VOLUME);
Mix_PauseMusic();
Mix_ResumeMusic();

Mix_VolumeMusic(MIX_MAX_VOLUME/3);
Mix_ResumeMusic();

Mix_PlayMusic(musique, -1);



   backg=IMG_Load("backg.png");
   SDL_BlitSurface(backg,NULL,screen,&pos_p);
   initPerso(&p,0,59);
   initPerso(&p1,30,59);
   afficherPerso(p,num,screen);
   afficherPerso(p1,num,screen);
   SDL_Flip(screen);

while(!done)
  {
   while(SDL_PollEvent(&event))
          {
               switch(event.type )
      {

           case SDL_QUIT:
               return (0);
                break;

  case SDL_KEYDOWN:
       switch(event.key.keysym.sym)
       {    
           case SDLK_RIGHT:
                             direction=0;
           deplacer_perso(&p,dt,direction);

                    animer_perso(&p,&num,direction);

                    SDL_BlitSurface(backg,NULL,screen,&pos_p);
                     
             
                    p.vie.imvie[0] =IMG_Load("imvie0.png");
                   
                     
            afficherPerso(p,num,screen);
                     afficherPerso(p1,num,screen);
                     SDL_Flip(screen);


 
                     
                  break ;                    
             
           case SDLK_LEFT:
                             direction=1;
                    deplacer_perso(&p,dt,direction);

                    animer_perso(&p,&num,direction);

                    SDL_BlitSurface(backg,NULL,screen,&pos_p);
                     
           p.score.i--;

                   afficherPerso(p,num,screen);
                   afficherPerso(p1,num,screen);
                   SDL_Flip(screen);
               
                   break ;
                   
            case SDLK_UP:
                         
                             direction=2;
                        deplacer_perso(&p,dt,direction);
       
               jump_perso(&p,&num,direction);

                        SDL_BlitSurface(backg,NULL,screen,&pos_p);

                        p.score.i+=10;
                       
                        afficherPerso(p1,num,screen);
                        afficherPerso(p,num,screen);
                        SDL_Flip(screen);
                        SDL_Delay(200);

                        SDL_BlitSurface(backg,NULL,screen,&pos_p);

                        p.pos_p.y=59;
                        afficherPerso(p,0,screen);


                        SDL_Flip(screen);
                   
               break ;
                   
           case SDLK_LSHIFT:
                          direction=0;
                          dt=15;
                     deplacer_perso(&p,dt,direction);

                     SDL_BlitSurface(backg,NULL,screen,&pos_p);
                     
                     p.score.i+=20;
                     
                     afficherPerso(p1,num,screen);
                     afficherPerso(p,num,screen);
                     
                      SDL_Flip(screen);
                             
                   break ;
             case SDLK_SPACE:
                            direction=3;
                         
                     attack_perso(&p,&num,direction);
 
                      SDL_BlitSurface(backg,NULL,screen,&pos_p);
                       
                        afficherPerso(p1,num,screen);
                        afficherPerso(p,num,screen);

                        SDL_Flip(screen);
                       
                       
                            break ;
                                   
 
                 case SDLK_d:
                             direction=0;
           deplacer_perso(&p1,dt,direction);

                    animer_perso(&p1,&num,direction);

                    SDL_BlitSurface(backg,NULL,screen,&pos_p);
                     
             
                    p1.vie.imvie[0] =IMG_Load("imvie0.png");
                   
                     
            afficherPerso(p1,num,screen);
                     afficherPerso(p,num,screen);
                     SDL_Flip(screen);


 
                     
                  break ;                    
             
           case SDLK_q:
                             direction=1;
                    deplacer_perso(&p1,dt,direction);

                    animer_perso(&p1,&num,direction);

                    SDL_BlitSurface(backg,NULL,screen,&pos_p);
                     
           p1.score.i--;

                   
                   afficherPerso(p1,num,screen);
                   afficherPerso(p,num,screen);
                   SDL_Flip(screen);
               
                   break ;
                   
            case SDLK_z:
                         
                             direction=2;
                        deplacer_perso(&p1,dt,direction);
       
               jump_perso(&p1,&num,direction);

                        SDL_BlitSurface(backg,NULL,screen,&pos_p);

                        p1.score.i+=10;

                         
                        afficherPerso(p1,num,screen);
                        afficherPerso(p,num,screen);
                        SDL_Flip(screen);
                        SDL_Delay(200);

                        SDL_BlitSurface(backg,NULL,screen,&pos_p);

                        p1.pos_p.y=59;
                        afficherPerso(p1,0,screen);

                        SDL_Flip(screen);
                   
               break ;
                   
           case SDLK_s:
                          direction=0;
                          dt=15;

                     deplacer_perso(&p1,dt,direction);
                     afficherPerso(p,num,screen);

                     SDL_BlitSurface(backg,NULL,screen,&pos_p);
                     
                     p1.score.i+=20;

                     afficherPerso(p,num,screen);
                     afficherPerso(p1,num,screen);
                     
                      SDL_Flip(screen);
                             
                   break ;
             case SDLK_x:
                            direction=3;
                         
                     attack_perso(&p1,&num,direction);
 
                      SDL_BlitSurface(backg,NULL,screen,&pos_p);
                       
                        afficherPerso(p,num,screen);
                        afficherPerso(p1,num,screen);

                        SDL_Flip(screen);
                       
                       
                            break ;
                                     
  }
     

              }
     

              }
}


return (0);
}
