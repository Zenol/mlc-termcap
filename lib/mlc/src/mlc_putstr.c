/*
** Made by Jérémy Cochoy
*/

#include <unistd.h>
#include "mlc.h"

int	mlc_putstr(char *str)
{
  int	p;

  p = 0;
  while (str[p])
    mlc_putchar(str[p++]);
  return (0);
}
