/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

int	mlc_strlen(char *str)
{
  int	len;

  len = 0;
  if (!str)
    return (0);
  while (str[len])
    len++;
  return (len);
}
