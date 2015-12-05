/*
** Made by Jérémy Cochoy
*/

#include <unistd.h>
#include "mlc.h"

int	mlc_putcolor(char *c)
{
  t_mlc	*mlc;

  mlc = mlc_link(0);
  mlc->color[mlc->y][mlc->x] = c;
  return (0);
}
