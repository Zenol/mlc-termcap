/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

void	mlc_getpos(int *x, int *y)
{
  *x = mlc_link(0)->cur_x;
  *y = mlc_link(0)->cur_y;
}
