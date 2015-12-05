/*
** Made by Jérémy Cochoy
**
** This header isn't made for exportation.
*/

#ifndef MLC_H_
# define MLC_H_

/*
** Key code
*/
# define	KEY_UNKNOW	0
# define	KEY_UP		1
# define	KEY_DOWN	2
# define	KEY_LEFT	3
# define	KEY_RIGHT	4
# define	KEY_ESC		5
# define	KEY_CTRLA	6
# define	KEY_CTRLE	7
# define	KEY_CTRLW	8
# define	KEY_CTRLS	9

/*
** Termcap code
*/
# define	TRM_RK		"\033[C"
# define	TRM_LK		"\033[D"
# define	TRM_UK		"\033[A"
# define	TRM_DK		"\033[B"
# define	TRM_CL		"\033[H\033[2J"
# define	TRM_CUR_H	"\033[?25l"
# define	TRM_CUR_S	"\033[?25h"
# define	TRM_MOVE_A	"\033["
# define	TRM_MOVE_S	";"
# define	TRM_MOVE_B	"f"
# define	TRM_ESC		"\033"
# define	TRM_CTRLA	"\001"
# define	TRM_CTRLE	"\002"
# define	TRM_CTRLW	"\027"
# define	TRM_CTRLS	"\023"


/*
** Colors
*/

# define	CLR_NONE		"\033[0;0;0m"
/*
** Input buff
*/
# define	IBUFF	15

/*
** Output buff
*/
# define	OBUFF	4096

/*
** Loop hook
*/
typedef	int (*p_loop_hook)(void *param);

/*
** Key Hook
*/
typedef	void (*p_key_hook)(char *str, void *param);

/*
** Resize hook
*/
typedef	void (*p_resize_hook)(int w, int h, void *param);

/*
** Color List (index)
*/
typedef struct		s_colorlist
{
  char			*color;
  struct s_colorlist	*next;
}			t_colorlist;

/*
** A picture
*/
typedef struct		s_img
{
  int			w;
  int			h;
  char			**buff;
  char			***color;
  t_colorlist		*color_list;
}			t_img;

/*
** MLC lib
*/
typedef struct		s_mlc
{
  /*
  ** Pos
  */
  int			x;
  int			y;
  int			cur_x;
  int			cur_y;

  /*
  ** Dims
  */
  int			w;
  int			h;

  /*
  ** Buffers
  */
  char			**buff;
  char			***color;

  /*
  ** Callbacks
  */
  p_loop_hook		ploop;
  void			*ploop_dt;

  p_key_hook		pkey;
  void			*pkey_dt;

  p_resize_hook		presize;
  void			*presize_dt;

  /*
  ** Resized?
  */
  char			sz;

  /*
  ** Cursor state
  */
  char			curst;
}			t_mlc;

/*
** Endianness
*/

#ifdef __sun__
# define	SWAP(x)	swap(x)
#else  /* !__sun__ */
# define	SWAP(x)	(x)
#endif /* !__sun__ */


/*
** Library functions
*/

t_mlc	*mlc_link(t_mlc *ptr);

int	mlc_clear(void);
int	mlc_width(void);
int	mlc_height(void);

void	*mlc_calloc(unsigned int nb, unsigned int len);

void	mlc_getcur(int *x, int *y);
int	mlc_setpos(int x, int y);
char	mlc_getchar(void);

void	mlc_resize_hook(p_resize_hook hook, void *param);

int	mlc_strcmp(const char *a, const char *b);
int	mlc_strlen(char *str);

int	mlc_putstr(char *str);
int	mlc_putnbr(int n);
int	mlc_putchar(char c);
int	mlc_putcolor(char *c);

t_img	*mlc_create_picture(int w, int h, char c, char *color);
int	mlc_picture_save(t_img *img, char *filename);
char	**mlc_picture_data(t_img *img);
void	mlc_delete_picture(t_img *img);
t_img	*mlc_picture_load(char *filename);
char	***mlc_picture_color(t_img *img);
t_img	*mlc_capture(void);
void	mlc_blit_picture(t_img *img, int x, int y);

int	mlc_move(int x, int y);
int	mlc_setcur(int x, int y);
void	mlc_loop(void);
int	mlc_show(void);

void	mlc_key_hook(p_key_hook hook, void *param);
void	mlc_loop_hook(p_loop_hook hook, void *param);

void	mlc_init(void);
void	init_size(void);

int	mlc_cur_hide(void);
void	mlc_close(void);

int	mlc_keycode(char *str);

typedef void	(*ptr_resize)(int);
void	mlc_resize(long sig);

void	mlc_getpos(int *x, int *y);
char	*mlc_getcolor(void);

void	mlc_fill_picture(t_img *img, char c, char *color);
int	mlc_cur_show(void);


/* Usefull */
void	lock_read(void);
void	unlock_read(void);
int	nonblock_read(int fd, void *buff, int len);
void	realloc_buff(void);
void	free_buff(void);
int	buff_write(char *str, int len);
void	dsp_err(char *msg);


#endif /* !MLC_H_ */
