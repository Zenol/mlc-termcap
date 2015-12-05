/*
** Made by Jérémy Cochoy
*/

#ifndef KEY_H_
# define KEY_H_

# define CTRLA "\001"
# define CTRLE "\002"
# define CTRLW "\027"
# define CTRLS "\023"
# define SPACE "\040"

typedef struct
{
  int		code;
  int		w;
  int		h;
  int		x;
  int		y;
}		t_key;

int	key(char *str, void *param);

#endif /* !KEY_H_ */
