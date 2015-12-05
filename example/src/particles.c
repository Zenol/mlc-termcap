/*
** Made by Jérémy Cochoy
*/

#include <stdlib.h>
#include "mlc.h"
#include "t_view.h"
#include "particles.h"

t_particle	*mk_particle(int vx, int vy, char c, char *color)
{
  t_particle	*particle;

  if ((particle = calloc(sizeof(*particle), 1)))
    {
      particle->vx = vx;
      particle->vy = vy;
      particle->c = c;
      particle->color = color;
      particle->x = (unsigned short)random() % mlc_width();
      particle->y = (unsigned short)random() % mlc_height();
    }
  return (particle);
}

void		add_particle(t_particle **list, t_particle *elm)
{
  elm->next = *list;
  *list = elm;
}

void		free_particles(t_particle *list)
{
  t_particle	*tmp;

  while (list)
    {
      tmp = list;
      list = list->next;
      free(tmp);
    }
}
