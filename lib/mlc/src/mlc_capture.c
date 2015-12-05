/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

t_img	*mlc_capture(void)
{
  t_mlc	*mlc;
  t_img	*img;
  int	x;
  int	y;

  mlc = mlc_link(0);
  img = mlc_create_picture(mlc->w, mlc->h, 0, 0);
  y = -1;
  while (++y < img->h)
    {
      x = -1;
      while (++x < img->w)
	{
	  img->buff[y][x] = mlc->buff[y][x];
	  img->color[y][x] = mlc->color[y][x];
	}
    }
  return (img);
}
