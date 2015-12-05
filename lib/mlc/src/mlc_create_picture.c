/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

t_img	*mlc_create_picture(int w, int h, char c, char *color)
{
  t_img	*img;
  int	y;

  img = mlc_calloc(sizeof(*img), 1);
  img->buff = mlc_calloc(sizeof(*img->buff), h + 1);
  img->color = mlc_calloc(sizeof(*img->color), h + 1);
  y = -1;
  while (++y < h)
    {
      img->buff[y] = mlc_calloc(sizeof(*img->buff), w + 1);
      img->color[y] = mlc_calloc(sizeof(*img->color), w + 1);
    }
  img->w = w;
  img->h = h;
  if (c || color)
    mlc_fill_picture(img, c, color);
  return (img);
}
