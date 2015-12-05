/*
** Made by Jérémy Cochoy
*/

#include <unistd.h>
#include "mlc.h"

char	mlc_getchar()
{
  t_mlc *mlc;

  mlc = mlc_link(0);
  return (mlc->buff[mlc->y][mlc->x]);
}
