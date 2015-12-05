/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"

int	mlc_strcmp(const char *str1, const char *str2)
{
  while (*str1 == *str2 && *str1 != '\0')
    {
      str1++;
      str2++;
    }
  return ((unsigned char)*str1 - (unsigned char)*str2);
}
