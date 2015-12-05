/*
** Made by Jérémy Cochoy
*/

#include <stdlib.h>
#include "mlc.h"

void	*mlc_calloc(unsigned int nb, unsigned int len)
{
  char	*ptr;
  
  len *= nb;
  if (!(ptr = malloc(len)))
    exit(EXIT_FAILURE);
  nb = 0;
  while (nb < len)
    ptr[nb++] = 0;
  return ((void*)ptr);
}
