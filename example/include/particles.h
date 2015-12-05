/*
** Made by Jérémy Cochoy
*/

#ifndef PARTICLES_H_
# define PARTICLES_H_

t_particle	*mk_particle(int vx, int vy, char c, char *color);
void		add_particle(t_particle **list, t_particle *elm);
void		free_particles(t_particle *list);

# endif /* !PARTICLES_H_ */
