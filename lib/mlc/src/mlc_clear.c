/*
** Made by Jérémy Cochoy
*/

#include <unistd.h>
#include "mlc.h"

int	mlc_clear()
{
  int   x, y;
  t_mlc *mlc;

  mlc = mlc_link(0);
  if (write(2, TRM_CL, sizeof(TRM_CL) - 1) < 0)
    return (-1);
  y = -1;
  while (++y < mlc->h)
  {
      x = -1;
      while(++x < mlc->w)
      {
          mlc->color[y][x] = 0;
          mlc->buff[y][x] = 0;
      }
  }
  return (0);
}
