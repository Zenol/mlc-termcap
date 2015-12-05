/*
** Made by Jérémy Cochoy
*/

#include <unistd.h>
#include "mlc.h"

int	mlc_move(int x, int y)
{
  if (mlc_setcur(x, y) < 0)
    return (-1);
  if (write(2, TRM_MOVE_A, sizeof(TRM_MOVE_A) - 1) < 0)
    return (-1);
  mlc_putnbr(y + 1);
  if (write(2, TRM_MOVE_S, sizeof(TRM_MOVE_A) - 1) < 0)
    return (-1);
  mlc_putnbr(x + 1);
  if (write(2, TRM_MOVE_B, sizeof(TRM_MOVE_A) - 1) < 0)
    return (-1);
  return (0);
}
