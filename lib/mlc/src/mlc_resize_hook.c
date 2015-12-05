/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

void	mlc_resize_hook(p_resize_hook hook, void *param)
{
  mlc_link(0)->presize = hook;
  mlc_link(0)->presize_dt = param;
}
