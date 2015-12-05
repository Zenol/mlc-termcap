/*
** Made by Jérémy Cochoy
*/

#include <string.h>
#include "mlc.h"
#include "t_view.h"
#include "key.h"
#include "display.h"

static int	key_d(t_key *key)
{
  if (key->code == KEY_DOWN)
    {
      key->h = mlc_height();
      if (key->y < key->h - 1)
	key->y++;
      else
	key->y = 0;
    }
  return (0);
}

int		key_u(t_key *key)
{
  if (key->code == KEY_UP)
    {
      key->h = mlc_height();
      if (key->y > 0)
	key->y--;
      else
	key->y = key->h - 1;
    }
  return (0);
}

static int	key_r(t_key *key)
{
  if (key->code == KEY_RIGHT)
    {
      key->w = mlc_width();
      if (key->x < key->w - 1)
	key->x++;
      else
	key->x = 0;
    }
  return (0);
}

static int	key_l(t_key *key)
{
  if (key->code == KEY_LEFT)
    {
      key->w = mlc_width();
      if (key->x > 0)
	key->x--;
      else
	key->x = key->w - 1;
    }
  return (0);
}

void	key_color(char *str, t_key *key, t_view *view)
{
  if (strcmp(str, "b") == 0)
    {
      mlc_setpos(key->x, key->y);
      mlc_putcolor(CLR_BLUE);
      view->show = 1;
    }
  if (strcmp(str, "r") == 0)
    {
      mlc_setpos(key->x, key->y);
      mlc_putcolor(CLR_RED);
      view->show = 1;
    }
  if (strcmp(str, "g") == 0)
    {
      mlc_setpos(key->x, key->y);
      mlc_putcolor(CLR_GREEN);
      view->show = 1;
    }
}

int		key(char *str, void *param)
{
  t_key		key;
  t_view	*view;

  view = (t_view*)param;
  key.code = mlc_keycode(str);
  mlc_getpos(&key.x, &key.y);
  key_l(&key);
  key_u(&key);
  key_d(&key);
  key_r(&key);
  key_color(str, &key, view);
  if (key.code == KEY_ESC)
    view->running = 1;
  if (strcmp(str, CTRLA) == 0)
    key.x = 0;
  if (strcmp(str, CTRLE) == 0)
    key.x = mlc_width() - 1;
  if (strcmp(str, CTRLW) == 0)
    key.y = 0;
  if (strcmp(str, CTRLS) == 0)
    key.y = mlc_height() - 1;
  mlc_move(key.x, key.y);
  return (0);
}
