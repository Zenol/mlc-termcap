/*
** Made by Jérémy Cochoy
*/

#include <stdlib.h>
#include "mlc.h"

void		mlc_delete_picture(t_img *img)
{
  int		y;
  t_colorlist	*cl;

  y = -1;
  while (++y < img->h)
    {
      free(img->buff[y]);
      free(img->color[y]);
    }
  while ((cl = img->color_list))
    {
      img->color_list = cl->next;
      free(cl->color);
      free(cl);
    }
  free(img->color);
  free(img->buff);
  free(img);
}
