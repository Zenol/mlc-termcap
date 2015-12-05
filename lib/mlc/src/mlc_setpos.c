/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

int	mlc_setpos(int x, int y)
{
  t_mlc	*mlc;

  mlc = mlc_link(0);
  if (x >= mlc->w || x < 0)
    return (-1);
  if (y >= mlc->h || y < 0)
    return (-1);
  mlc->x = x;
  mlc->y = y;
  return (0);
}
