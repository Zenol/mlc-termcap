/*
** Made by Jérémy Cochoy
*/

#include <unistd.h>
#include "mlc.h"

int	mlc_cur_show(void)
{
  if (write(2, TRM_CUR_S, sizeof(TRM_CUR_S) - 1) < 0)
    return (-1);
  mlc_link(0)->curst = 1;
  return (0);
}
