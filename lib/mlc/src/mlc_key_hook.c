/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

void	mlc_key_hook(p_key_hook hook, void *param)
{
  mlc_link(0)->pkey = hook;
  mlc_link(0)->pkey_dt = param;
}
