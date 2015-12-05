/*
** Made by Jérémy Cochoy
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "mlc.h"

# define	SAVE_MODE	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

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

static int	header(t_img *img, char *filename)
{
  int		fd;
  int		i;
  int		j;

  if ((fd = open(filename, O_WRONLY | O_CREAT, SAVE_MODE)) < 0)
    return (0);
  i = SWAP(img->w);
  j = SWAP(img->h);
  if (write(fd, (char*)&i, 4) < 0 || write(fd, (char*)&j, 4) < 0)
    return (0);
  return (fd);
}

int	mlc_picture_save(t_img *img, char *filename)
{
  int	fd;
  int	i;
  int	j;
  char	l;

  if (!(fd = header(img, filename)))
    return (0);
  i = -1;
  while (++i < img->h)
    {
      if (write(fd, img->buff[i], img->w) < 0)
	return (0);
      j = -1;
      while (++j < img->w)
      	{
	  l = (char)mlc_strlen(img->color[i][j]);
	  if (write(fd, &l, 1) < 0)
	    return (close(fd) && 0);
	  if (l && write(fd, img->color[i][j], (int)l) < 0)
	    return (close(fd) && 0);
      	}
    }
  return (close(fd) > -1);
}
