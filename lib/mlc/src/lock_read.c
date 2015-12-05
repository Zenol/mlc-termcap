/*
** Made by Jérémy Cochoy
*/

#ifdef __sun__
# include <stropts.h>
# include <sys/types.h>

#define TIOCGETA TCGETA
#define TIOCSETA TCSETA
#define termios termio

# include <fcntl.h>
#else
# include <sys/fcntl.h>
# ifdef __linux__
#  define TIOCGETA TCGETA
#  define TIOCSETA TCSETA
# endif /* __linux__ */
#endif /* __sun__ */
#include <sys/ioctl.h>
#include <sys/termios.h>

#include "mlc.h"

void	lock_read(void)
{
  struct termios	att;

  if (ioctl(2, TIOCGETA, &att) < 0)
    dsp_err("Can't get att from ioctl\n");
  att.c_lflag |= ECHO;
  att.c_lflag |= ICANON;
  if (ioctl(2, TIOCSETA, &att) < 0)
    dsp_err("Can't set att to ioctl\n");
}
