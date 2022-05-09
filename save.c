#include "save.h"

void sauvegarder (personne p,background b)
{
FILE *fichier;
/*save s;
s.p=p;
s.b=b;*/
fichier=fopen("save_perso.txt","w");
if (fichier !=NULL)
{
  fprintf(fichier,"%d %d %d %d %d %d",p.score,p.vie,p.position.x,p.position.y,b.camera.x,b.camera.y);
  printf("game saved \n");
  }
  else
  {
  printf("save failed \n");
  }
fclose(fichier);
}

void charger(personne *p,background *b)
{
FILE *fichier;
save s;
fichier=fopen("save_perso.txt","r");
fscanf(fichier,"%d %d %d %d %d %d",p.score,p.vie,p.position.x,p.position.y,b.camera.x,b.camera.y);
fclose(fichier);
/*p->position.x=s.p.position.x;
p->position.y=s.p.position.y;
b->camera.x=s.b.camera.x;
b->camera.y=s.b.camera.y;*/

printf("perso et background chargés\n");

}
