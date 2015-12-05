/*
** Made by Jérémy Cochoy
*/

#include <unistd.h>
#include "mlc.h"

int	mlc_putchar(char c)
{
  t_mlc	*mlc;

  mlc = mlc_link(0);
  mlc->buff[mlc->y][mlc->x] = c;
  mlc->x++;
  if (mlc->x >= mlc->w)
    {
      mlc->x = 0;
      mlc->y++;
      if (mlc->y >= mlc->h)
	mlc->y = 0;
    }
  return (0);
}
