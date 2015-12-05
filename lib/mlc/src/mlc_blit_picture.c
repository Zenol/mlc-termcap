/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

void	mlc_blit_picture(t_img *img, int x, int y)
{
  int	img_x;
  int	img_y;
  t_mlc	*mlc;

  mlc = mlc_link(0);
  if (y < -img->h || x < -img->w)
    return ;
  img_y = 0;
  if (y < 0)
    img_y = -y;
  while (img_y < img->h && img_y + y < mlc->h)
    {
      img_x = 0;
      if (x < 0)
	img_x = -x;
      while (img_x < img->w && img_x + x < mlc->w)
	{
	  if (img->buff[img_y][img_x])
	    mlc->buff[img_y + y][img_x + x] = img->buff[img_y][img_x];
	  if (img->color[img_y][img_x])
	    mlc->color[img_y + y][img_x + x] = img->color[img_y][img_x];
	  img_x++;
	}
      img_y++;
    }
}
