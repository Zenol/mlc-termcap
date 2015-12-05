/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

void	mlc_getcur(int *x, int *y)
{
  t_mlc *mlc;

  mlc = mlc_link(0);
  *x = mlc->cur_x;
  *y = mlc->cur_y;
}
