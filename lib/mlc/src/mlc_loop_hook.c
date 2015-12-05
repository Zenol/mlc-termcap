/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

void	mlc_loop_hook(p_loop_hook hook, void *param)
{
  mlc_link(0)->ploop = hook;
  mlc_link(0)->ploop_dt = param;
}
