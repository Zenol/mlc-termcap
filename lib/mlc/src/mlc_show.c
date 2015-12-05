/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

static void	push_in_buff(t_mlc *mlc)
{
  int	x;
  int	y;

  buff_write(CLR_NONE, sizeof(CLR_NONE) - 1);
  y = -1;
  while (++y < mlc->h)
    {
      x = -1;
      while(++x < mlc->w)
	{
	  if (mlc->color[y][x])
	    buff_write(mlc->color[y][x], mlc_strlen(mlc->color[y][x]));
	  if (mlc->buff[y][x] >= ' ' && mlc->buff[y][x] <= '~')
	    buff_write(mlc->buff[y] + x, 1);
	  else
	    buff_write(" ", 1);
	}
    }
  buff_write(CLR_NONE, sizeof(CLR_NONE) - 1);
  buff_write(0, 0);
}

int	mlc_show(void)
{
  int	x;
  int	y;
  int	st;
  t_mlc	*mlc;

  mlc = mlc_link(0);
  x = mlc->cur_x;
  y = mlc->cur_y;
  if ((st = mlc->curst))
    mlc_cur_hide();
  mlc_move(0, 0);
  push_in_buff(mlc);
  mlc_move(x, y);
  if (st)
    mlc_cur_show();
  return (0);
}
