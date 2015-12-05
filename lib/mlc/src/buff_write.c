/*
** Made by Jérémy Cochoy
*/

#include <unistd.h>
#include "mlc.h"

int	buff_write(char *str, int len)
{
  static int	pos;
  static char	buff[OBUFF];
  int		cnt;

  if (!str)
    {
      if (write(2, buff, pos) < 0)
	return (-1);
      return (pos = 0);
    }
  cnt = 0;
  while (cnt < len)
    {
      if (pos < OBUFF)
	buff[pos++] = str[cnt++];
      else
	{
	  if (write(2, buff, pos) < 0)
	    return (-1);
	  pos = 0;
	}
    }
  return (0);
}
