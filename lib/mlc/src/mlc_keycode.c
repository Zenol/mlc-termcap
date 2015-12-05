/*
** Made by Jérémy Cochoy
*/

#include "mlc.h"
#include "mlc_keycode.h"

int	mlc_keycode(char *str)
{
  if (!mlc_strcmp(str, TRM_RK))
    return (KEY_RIGHT);
  if (!mlc_strcmp(str, TRM_LK))
    return (KEY_LEFT);
  if (!mlc_strcmp(str, TRM_UK))
    return (KEY_UP);
  if (!mlc_strcmp(str, TRM_DK))
    return (KEY_DOWN);
  if (!mlc_strcmp(str, TRM_ESC))
    return (KEY_ESC);
  if (!mlc_strcmp(str, TRM_CTRLW))
    return (KEY_CTRLW);
  if (!mlc_strcmp(str, TRM_CTRLA))
    return (KEY_CTRLA);
  if (!mlc_strcmp(str, TRM_CTRLE))
    return (KEY_CTRLE);
  if (!mlc_strcmp(str, TRM_CTRLS))
    return (KEY_CTRLS);
  if (IS_ALNUM(*str) && !str[1])
    return (*str);
  return (KEY_UNKNOW);
}
