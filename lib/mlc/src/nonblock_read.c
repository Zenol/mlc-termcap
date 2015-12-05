/*
** Made by Jérémy Cochoy
*/

#ifdef __sun__
# include <stropts.h>
# include <fcntl.h>
#else /* !__sun__ */
# include <sys/fcntl.h>
#endif /* !__sun__ */

#include <unistd.h>
#include <stdlib.h>
#include <term.h>
#include <termios.h>

#ifndef TIOCGETA
# define TIOCGETA TCGETS
#endif /* !TIOCGETA */
#ifndef TIOCSETA
# define TIOCSETA TCSETS
#endif /* !TIOCSETA */

#include "mlc.h"

int	nonblock_read(int fd, void *buff, int len)
{
  int	mode;

  if ((mode = fcntl(2, F_GETFL, 0)) < 0)
    dsp_err("Can't get att[nonblock] from fcntl\n");
  mode |= O_NONBLOCK;
  if (fcntl(2, F_SETFL, mode) < 0)
    dsp_err("Can't set att[nonblock] to fcntl\n");
  len = read(fd, buff, len);
  mode &= ~O_NONBLOCK;
  if (fcntl(2, F_SETFL, mode) < 0)
    dsp_err("Can't set att[nonblock] to fcntl\n");
  if (len < 0)
    return (-1);
  return (len);
}
