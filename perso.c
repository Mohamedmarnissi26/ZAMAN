#include "perso.h"

#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


void initPerso(personne *p,int x,int y)
{  
   char A[20];
   int i;
for(i=0;i<10;i++)
    {
       sprintf(A,"img%d.bmp",i);
       p->img[i]=IMG_Load(A);
   }

      p->vitesse=15;
      p->accelerer=0;
      p->up=0;
     
      p->pos_p.x=x;
      p->pos_p.y=y;
      p->pos_p.w=0;
      p->pos_p.h=0;
     
      p->score.pos_score.x=0;
      p->score.pos_score.y=0;

      p->score.textColor.r=255;
      p->score.textColor.g=255;
      p->score.textColor.b=255;



      p->score.poli_score=TTF_OpenFont("TRAJAN.ttf",30);
      p->score.i=0;

        p->vie.pos_vie.x=900;
p->vie.pos_vie.y=20;

p->vie.nb_vie=3;


p->vie.imvie[0]=NULL;
p->vie.imvie[1]=NULL;
p->vie.imvie[2]=NULL;
p->vie.imvie[3]=NULL;

p->vie.imvie[0] =IMG_Load("imvie0.png");
p->vie.imvie[1] =IMG_Load("imvie1.png");
p->vie.imvie[2] =IMG_Load("imvie2.png");
p->vie.imvie[3] =IMG_Load("imvie3.png");
}


void afficherPerso(personne p,int num, SDL_Surface * screen)
{
      char A1[20];
      sprintf(A1,"score: %d",p.score.i);
      SDL_BlitSurface(p.img[num],NULL,screen,&p.pos_p);
     

p.score.txt_score=TTF_RenderText_Solid(p.score.poli_score,A1, p.score.textColor);
      SDL_BlitSurface(p.score.txt_score,NULL,screen,&p.score.pos_score);
     // SDL_BlitSurface(p.vie[nb_vie],NULL,screen,&p.vie.pos_vie);
SDL_BlitSurface(p.vie.imvie[p.vie.nb_vie], NULL, screen,&p.vie.pos_vie);
}

void deplacer_perso(personne *p,Uint32 dt,int direction)
{
   int dx;
   dx=((p->accelerer/2)*(dt*dt)+(p->vitesse*dt));
if (direction==0 )
       p->pos_p.x+=dx;
else if (direction==1)
       p->pos_p.x-=dx;
else
       p->pos_p.y-=dx;

}

void animer_perso(personne *p,int * num, int direction)
{
switch(direction)
{
   case 0:
          if ((*num)==0)
              (*num)=1;
            else  
               (*num)=0;
       break;
   case 1:
          if ((*num)==2)
              (*num)=3;
            else  
               (*num)=4;
        break;




}
}
void jump_perso(personne *p,int * num ,int direction)
{
         if ((*num)==0||(*num)==1)
                   (*num)=0;
  else  
         if ((*num)==2||(*num)==3)
                   (*num)=4 ;

}

void attack_perso(personne *p,int * num,int direction)

{
   
         if ((*num)==0||(*num)==1)
                   (*num)=9;
  else  
         if ((*num)==2||(*num)==3)
                   (*num)=10;


}
