/*
** Made by Jérémy Cochoy
*/

#include <stdlib.h>
#include <string.h>
#include "t_view.h"
#include "mlc.h"

static void	p_do(t_particle *p)
{
  p->x += p->vx;
  p->y += p->vy;
  if (p->x >= mlc_width())
    {
      p->vx = -p->vx;
      p->x = mlc_width() - 1;
    }
  if (p->y >= mlc_height())
    {
      p->vy = -p->vy;
      p->y = mlc_height() - 1;
    }
  if (p->y <= 0)
    {
      p->y = 0;
      p->vy = -p->vy;
    }
  if (p->x <= 0)
    {
      p->x = 0;
      p->vx = - p->vx;
    }
  mlc_setpos(p->x, p->y);
  mlc_putcolor(p->color);
  mlc_putchar(p->c);
  /*   mlc_putcolor(CLR_NONE); */
}

static void	refresh(t_view *view)
{
  int		w;
  int		h;
  int		y;
  int		x;
  t_particle	*p;

  w = mlc_width();
  h = mlc_height();
  mlc_setpos(0, 0);
  y = -1;
  while (++y < h)
    {
      x = -1;
      while (++x < w)
  	mlc_putchar(' ');
    }
  p = view->particle;
  while (p)
    {
      p_do(p);
      p = p->next;
    }
  mlc_show();
}

int		display(t_view *view)
{
  refresh(view);
  return (view->running);
}
