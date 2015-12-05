/*
** Made by Jérémy Cochoy
*/

#include <unistd.h>
#include "mlc.h"

static int	_putchar(char c)
{
  if (write(2, &c, 1) < 0)
    return (-1);
  return (0);
}

int	mlc_putnbr(int n)
{
  if (n < 0)
    return (_putchar('-') | mlc_putnbr(-n));
  if (n >= 10)
    return (mlc_putnbr(n / 10) | _putchar(n % 10 + '0'));
  _putchar(n + '0');
  return (1);
}
