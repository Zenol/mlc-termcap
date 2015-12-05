/*
** Made by Jérémy Cochoy
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "t_view.h"
#include "mlc.h"
#include "display.h"
#include "key.h"
#include "particles.h"

void		resize(int w, int h, t_view *view)
{
  view->w = w;
  view->h = h;
  view->show = 1;
}

void		add_particles(t_view *view)
{
  int		cnt;
  char		*color;
  int		idx;

  cnt = -1;
  color = 0;
  while (++cnt < view->nb_p)
    {
      idx = (unsigned)random() % 5;
      if (idx == 0)
	color = CLR_RED;
      if (idx == 1)
	color = CLR_BLUE;
      if (idx == 2)
	color = CLR_GREEN;
      if (idx == 3)
	color = CLR_ORANGE;
      if (idx == 4)
	color = CLR_VIOLET;
      add_particle(&view->particle,
		   mk_particle((unsigned)random() % 3 - 1,
			       (unsigned)random() % 3 - 1,
			       (unsigned)random() % 26 + 'a',
			       color));
    }
}

int		viewer(t_view *view)
{
  mlc_init();
  mlc_loop_hook((p_loop_hook)display, (void*)view);
  mlc_key_hook((p_key_hook)key, (void*)view);
  mlc_resize_hook((p_resize_hook)resize, (void*)view);
  mlc_cur_hide();
  if (view->nb_p <= 0)
    view->nb_p = 100;
  add_particles(view);
  mlc_loop();
  free_particles(view->particle);
  mlc_clear();
  mlc_close();
  return (0);
}

void	param(int ac, char **av, t_view *view)
{
  int	idx;
  int	err;

  idx = 0;
  err = 0;
  while (++idx < ac && !err)
    {
      if (!strcmp(av[idx], "-p"))
	{
	  if (idx + 1 < ac)
	    view->nb_p = atoi(av[idx++ + 1]);
	  else
	    err = 1;
	}
      else
	err = 1;
    }
  if (err)
    {
      printf("%s: -p nb_particles\n", av[0]);
      exit(EXIT_FAILURE);
    }
}

int		main(int ac, char **av)
{
  t_view	view;

  srandom(time(0));
  bzero(&view, sizeof(view));
  view.px = -10;
  view.py = -10;
  param(ac, av, &view);
  if (viewer(&view))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
