/*
** Made by Jérémy Cochoy
*/

#include <stdlib.h>
#include <unistd.h>
#include "mlc.h"

void	dsp_err(char *msg)
{
  if (write(2, msg, mlc_strlen(msg)) < 0)
    exit(EXIT_FAILURE);
  exit(EXIT_FAILURE);
}
