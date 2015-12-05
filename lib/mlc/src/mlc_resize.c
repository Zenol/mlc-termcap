/*
** Made by Jérémy Cochoy
*/

#ifdef __sun__
#else
# include <term.h>
# include <sys/ioctl.h>
#endif /* __sun__ */
#include <signal.h>

#include "mlc.h"

void			mlc_resize(long sig)
{
  if (sig == SIGWINCH)
    mlc_link(0)->sz = 1;
}
