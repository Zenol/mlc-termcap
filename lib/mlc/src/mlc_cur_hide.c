/*
** Made by Jérémy Cochoy
*/

#include <unistd.h>
#include "mlc.h"

int	mlc_cur_hide()
{
  t_mlc *mlc;

  mlc = mlc_link(0);
  if (write(2, TRM_CUR_H, sizeof(TRM_CUR_H) - 1) < 0)
    return (-1);
  mlc->curst = 0;
  return (0);
}
