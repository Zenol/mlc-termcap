/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

int	mlc_setcur(int x, int y)
{
  t_mlc	*mlc;

  mlc = mlc_link(0);
  if (x >= mlc->w || x < 0)
    return (-1);
  if (y >= mlc->h || y < 0)
    return (-1);
  mlc->cur_x = x;
  mlc->cur_y = y;
  return (0);
}
