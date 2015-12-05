/*
** Made by Jérémy Cochoy
*/

#include <unistd.h>
#include "mlc.h"

char	*mlc_getcolor()
{
  t_mlc *mlc;

  mlc = mlc_link(0);
  return (mlc->color[mlc->y][mlc->x]);
}
