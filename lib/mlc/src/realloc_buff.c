/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

void	realloc_buff(void)
{
  int	ctn;
  t_mlc	*mlc;

  mlc = mlc_link(0);
  free_buff();
  mlc->buff = mlc_calloc(sizeof(*mlc->buff), mlc->h);
  ctn = 0;
  while (ctn < mlc->h)
    mlc->buff[ctn++] = mlc_calloc(sizeof(**mlc->buff), mlc->w + 1);
  mlc->color = mlc_calloc(sizeof(*mlc->color), mlc->h);
  ctn = 0;
  while (ctn < mlc->h)
    mlc->color[ctn++] = mlc_calloc(sizeof(**mlc->color), mlc->w + 1);
}
