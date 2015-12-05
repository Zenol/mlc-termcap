/*
** Made by Jérémy Cochoy
*/

#ifndef T_VIEW_H_
# define T_VIEW_H_

typedef struct		s_particle
{
  struct s_particle	*next;
  int			x;
  int			y;
  int			vx;
  int			vy;
  char			*color;
  char			c;
}			t_particle;

typedef struct
{
  int		w;
  int		h;
  int		x;
  int		y;
  int		px;
  int		py;
  int		show;
  int		nb_p;
  char		*map;
  t_particle	*particle;
  char		running;
}		t_view;

#endif /* !T_VIEW_H_ */
