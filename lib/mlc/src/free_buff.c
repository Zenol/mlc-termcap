/*
** Made by Jérémy Cochoy
*/

#include <stdlib.h>
#include "mlc.h"

void	free_buff(void)
{
  int	y;
  t_mlc	*mlc;

  mlc = mlc_link(0);
  y = -1;
  if (mlc->buff)
    while (++y < mlc->h)
      free(mlc->buff[y]);
  y = -1;
  if (mlc->color)
    while (++y < mlc->h)
      free(mlc->color[y]);
  free(mlc->buff);
  free(mlc->color);
  mlc->buff = 0;
  mlc->color = 0;
}
