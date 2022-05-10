#include "bg.h"
void init_bg(bg *bg)
{
bg->pos.x=0;
bg->pos.y=0;
char ch[50];
for(int i=1;i<51;i++)//boucle pour charger les images background
{
sprintf(ch,"sunset/Layer %d.png",i);
bg->is[i-1] = IMG_Load(ch);
}
bg->m = IMG_Load("masque.png");//chargement du masque mais on n'a pas utilisé
bg->pos.w=bg->is[1]->w;
bg->pos.h=bg->is[1]->h;
bg->anim=0;
}
void scrolling(bg *bg,int d,int pas)
{//on scrolle verticalement ou horizontalement
if(d==1) bg->pos.x+=pas;
if(d==2) bg->pos.y+=pas;
}
void bg_in_borders(bg *bg,SDL_Surface *screen) // garder l'image sur l'ecran 
{//ki bsh tokhrej taswira mel ajneb tarja3 
if(bg->pos.x>0) bg->pos.x=0;
if(bg->pos.y>0) bg->pos.y=0;
if(screen->w-bg->pos.x>bg->pos.w) bg->pos.x=screen->w-bg->pos.w;
if(screen->h-bg->pos.y>bg->pos.h) bg->pos.y=screen->h-bg->pos.h;
}
void afficher_bg(bg bg,SDL_Surface *screen)
{
SDL_BlitSurface(bg.is[bg.anim],NULL,screen,&bg.pos);//image,shnowa bsh taffichi menha,3la shnowa bsh tafficheha,win bsh tafficheha
}
void changement_imagebg(bg* bg)
{//anim malezmch tfout 50
bg->anim++;
if(bg->anim==50)bg->anim=0;
}

void animation_start(SDL_Surface *screen)
{//animation début
//principe enou taswiret lbackground loula tji mel yssar lel ymin 9bal ma tebda jeu
SDL_Surface *image;
image= IMG_Load("sunset/Layer 1.png");
SDL_Rect pos;pos.x=screen->w+1000;pos.y=0;
SDL_Delay(500);//pause 0.5 secondes
while(pos.x>10)
{
SDL_BlitSurface(image,NULL,screen,&pos);
pos.x-=10;
SDL_Flip(screen);//actualiser
}
}

void musique()//juste hot musique f blaset musique.mp3
{
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);//initialisation audio
   Mix_Music *musique; //Création du pointeur de type Mix_Music
   musique = Mix_LoadMUS("musique.mp3"); //Chargement de la musique
   Mix_PlayMusic(musique, -1);//-1:boucle infinie
}

void partage_ecran(bg bg1,bg bg2,SDL_Surface *screen)
{
SDL_BlitSurface(bg1.is[bg1.anim],NULL,screen,&bg1.pos);//affichage bg1
//ne9lbou l pos mta3 bg2 khater bch naffichiw menha chtar
bg2.pos.x=-bg2.pos.x;
bg2.pos.y=-bg2.pos.y;
SDL_Rect pos;pos.x=screen->w/2;//ndeclariw position w nhotoha f chtar
SDL_BlitSurface(bg2.is[bg2.anim],&bg2.pos,screen,&pos);
}
