/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

t_mlc		*mlc_link(t_mlc *ptr)
{
  static t_mlc	*mlc;

  if (ptr)
    mlc = ptr;
  return (mlc);
}
