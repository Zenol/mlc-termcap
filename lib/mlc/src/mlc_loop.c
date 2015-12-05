/*
** Made by Jérémy Cochoy
*/


#ifdef __linux__
/* Activate usleep */
#define  _BSD_SOURCE 
#endif

#include <unistd.h>
#include "mlc.h"

static void	mlc_loop_rz(t_mlc *mlc)
{
  if (mlc->sz)
    {
      mlc->sz = 0;
      init_size();
      if (mlc->presize)
	mlc->presize(mlc->w, mlc->h, mlc->presize_dt);
    }
}

void	mlc_loop(void)
{
  char	buff[IBUFF + 1];
  int	len;
  t_mlc	*mlc;

  mlc = mlc_link(0);
  len = 0;
  while (42)
    {
      mlc_loop_rz(mlc);
      if ((len = nonblock_read(2, buff, IBUFF)) > 0)
	{
	  buff[len] = 0;
	  if (mlc->pkey)
	    mlc->pkey(buff, mlc->pkey_dt);
	}
      if (mlc->ploop)
	if (mlc->ploop(mlc->ploop_dt))
	  return ;
      usleep(10);
    }
}
