/*
** Made by Jérémy Cochoy
*/

#ifdef __sun__
# include <sys/ioctl.h>
# include <stropts.h>
# include <sys/termios.h>
#else
# include <term.h>
# include <sys/ioctl.h>
#endif /* __sun__ */

#include <signal.h>

#include <stdlib.h>
#include "mlc.h"

void	init_size(void)
{
  struct winsize	w;

  if (ioctl(0, TIOCGWINSZ, &w) < 0)
    dsp_err("Can't get win_size!\n");
  free_buff();
  mlc_link(0)->h = w.ws_row;
  mlc_link(0)->w = w.ws_col;
  realloc_buff();
  mlc_move(0, 0);
  mlc_setpos(0, 0);
}

void	mlc_init(void)
{
  t_mlc	*mlc;

  mlc = mlc_calloc(sizeof(*mlc), 1);
  mlc_link(mlc);
  init_size();
  unlock_read();
  mlc_clear();
  mlc_setpos(0, 0);
  mlc_move(0, 0);
  mlc_cur_show();
  signal(SIGWINCH, (ptr_resize)mlc_resize);
}
