/*
** Made by Jérémy Cochoy
*/

#include <stdlib.h>
#include "mlc.h"

void	mlc_close(void)
{
  mlc_cur_show();
  unlock_read();
  free_buff();
  free(mlc_link(0));
}
