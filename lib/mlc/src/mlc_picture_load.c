/*
** Made by Jérémy Cochoy
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "mlc.h"

#ifdef __sun__
static int	swap(int v)
{
  char		*ptr;

  ptr = (char*)&v;
  ptr[0] ^= ptr[3];
  ptr[3] ^= ptr[0];
  ptr[0] ^= ptr[3];
  ptr[1] ^= ptr[1];
  ptr[2] ^= ptr[2];
  ptr[1] ^= ptr[1];
  return (v);
}
#endif /* __sun__ */

static int	color_load(int fd, t_img *img, int i, int j)
{
  unsigned char	l;
  char		*mem;
  t_colorlist	*ptr;

  l = 0;
  if (read(fd, &l, 1) < 0)
    return (0);
  if (!l)
    return (1);
  mem = mlc_calloc(l + 1, 1);
  if (l && read(fd, mem, (int)l) < 0)
    return (0);
  img->color[i][j] = mem;
  ptr = mlc_calloc(1, sizeof(*ptr));
  ptr->next = img->color_list;
  ptr->color = mem;
  img->color_list = ptr;
  return (1);
}

t_img	*mlc_picture_load(char *filename)
{
  t_img	*img;
  int	fd;
  int	i;
  int	j;

  if ((fd = open(filename, O_RDONLY)) < 0)
    return (0);
  if (read(fd, (char*)&i, 4) < 0 || read(fd, (char*)&j, 4) < 0)
    return (0);
  img = mlc_create_picture(SWAP(i), SWAP(j), 0, 0);
  i = -1;
  while (++i < img->h)
    {
      if (read(fd, img->buff[i], img->w) < 0)
	{
	  close(fd);
	  return 0;
	}
      j = -1;
      while (++j < img->w)
	if (!color_load(fd, img, i, j))
	  {
	    close(fd);
	    return 0;
	  }
    }
  if (close(fd) < 0)
    return (0);
  return (img);
}
