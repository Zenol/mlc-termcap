/*
** Made by Jérémy Cochoy
*/

#include <unistd.h>
#include "mlc.h"

int	mlc_clear()
{
  if (write(2, TRM_CL, sizeof(TRM_CL) - 1) < 0)
    return (-1);
  return (0);
}
