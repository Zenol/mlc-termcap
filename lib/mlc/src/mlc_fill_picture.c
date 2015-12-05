/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

void	mlc_fill_picture(t_img *img, char c, char *color)
{
  int	x;
  int	y;

  y = 0;
  while (y < img->h)
    {
      x = 0;
      while (x < img->w)
	{
	  img->buff[y][x] = c;
	  img->color[y][x] = color;
	  x++;
	}
      y++;
    }
}
