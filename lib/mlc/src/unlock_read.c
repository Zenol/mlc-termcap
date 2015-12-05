/*
** Made by Jérémy Cochoy
*/

#include <unistd.h>
#include <stdlib.h>
#include <termios.h>

#ifndef TIOCGETA
# define TIOCGETA TCGETS
#endif /* !TIOCGETA */
#ifndef TIOCSETA
# define TIOCSETA TCSETS
#endif /* !TIOCSETA */

#include <sys/fcntl.h>
#include <sys/ioctl.h>
#include <sys/termios.h>

#include "mlc.h"

void			unlock_read(void)
{
  struct termios	att;

  if (ioctl(2, TIOCGETA, &att) < 0)
    dsp_err("Can't get att from ioctl\n");
  att.c_lflag &= ~ECHO;
  att.c_lflag &= ~ICANON;
  att.c_lflag &= ~ISIG;
  att.c_cc[VMIN] = 1;
  att.c_cc[VTIME] = 0;
  if (ioctl(2, TIOCSETA, &att) < 0)
    dsp_err("Can't set att to ioctl\n");
}
