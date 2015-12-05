##
## Makefile for mlc in /home/cochoy_j/rendu/mlc
## 
## Made by Jeremy Cochoy
##

NAME	=	libmlc_${MACHTYPE}-${OSTYPE}-${HOSTTYPE}.a

NDBG	=	libmlc_${MACHTYPE}-${OSTYPE}-${HOSTTYPE}-d.a

OBJS	=	\
		out/dsp_err.o \
		out/mlc_delete_picture.o \
		out/mlc_strlen.o \
		out/nonblock_read.o \
		out/mlc_blit_picture.o \
		out/mlc_show.o \
		out/mlc_picture_data.o \
		out/mlc_init.o \
		out/mlc_loop.o \
		out/mlc_cur_hide.o \
		out/mlc_getcolor.o \
		out/mlc_clear.o \
		out/mlc_link.o \
		out/mlc_move.o \
		out/mlc_calloc.o \
		out/mlc_key_hook.o \
		out/lock_read.o \
		out/mlc_picture_load.o \
		out/mlc_getchar.o \
		out/mlc_picture_save.o \
		out/mlc_height.o \
		out/mlc_getpos.o \
		out/mlc_picture_color.o \
		out/mlc_setcur.o \
		out/realloc_buff.o \
		out/mlc_setpos.o \
		out/mlc_resize_hook.o \
		out/mlc_create_picture.o \
		out/mlc_putchar.o \
		out/buff_write.o \
		out/unlock_read.o \
		out/mlc_capture.o \
		out/mlc_close.o \
		out/free_buff.o \
		out/mlc_cur_show.o \
		out/mlc_loop_hook.o \
		out/mlc_putcolor.o \
		out/mlc_strcmp.o \
		out/mlc_putnbr.o \
		out/mlc_resize.o \
		out/mlc_putstr.o \
		out/mlc_fill_picture.o \
		out/mlc_getcur.o \
		out/mlc_keycode.o \
		out/mlc_width.o \

#####################################################
CC	=	gcc
RM	=	rm -f
AR	=	ar -crs
CP	=	cp

INCS	=	-I./include -I. 

CFLAGS	=	-W -Wall -Wstrict-prototypes -ansi
CFLAGS	+=	-pedantic -fomit-frame-pointer -O2 -O3
CFLAGS	+=	$(INCS)
DBGF	=	-W -Wall -Wstrict-prototypes -DDEBUG
DBGF	+=	-ansi -pedantic -O0 -ggdb3 -I../include -I.. 

LIBFS	=	
LIBNS	+=	

LFLAGS	=	$(LIBFS) $(LIBNS)

#####################################################
$(NAME):	$(OBJS)
	@printf "[%-9s]\t%s\n" "Linking" $@
	@$(AR) $(NAME) $(OBJS)
	@$(CP) $(NAME) ../
	@$(CP) mlc.h ../
#####################################################

out/dsp_err.o:	src/dsp_err.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/dsp_err.c out/dsp_err.o
	@$(CC) $(CFLAGS) -c src/dsp_err.c -o out/dsp_err.o

out/mlc_delete_picture.o:	src/mlc_delete_picture.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_delete_picture.c out/mlc_delete_picture.o
	@$(CC) $(CFLAGS) -c src/mlc_delete_picture.c -o out/mlc_delete_picture.o

out/mlc_strlen.o:	src/mlc_strlen.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_strlen.c out/mlc_strlen.o
	@$(CC) $(CFLAGS) -c src/mlc_strlen.c -o out/mlc_strlen.o

out/nonblock_read.o:	src/nonblock_read.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/nonblock_read.c out/nonblock_read.o
	@$(CC) $(CFLAGS) -c src/nonblock_read.c -o out/nonblock_read.o

out/mlc_blit_picture.o:	src/mlc_blit_picture.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_blit_picture.c out/mlc_blit_picture.o
	@$(CC) $(CFLAGS) -c src/mlc_blit_picture.c -o out/mlc_blit_picture.o

out/mlc_show.o:	src/mlc_show.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_show.c out/mlc_show.o
	@$(CC) $(CFLAGS) -c src/mlc_show.c -o out/mlc_show.o

out/mlc_picture_data.o:	src/mlc_picture_data.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_picture_data.c out/mlc_picture_data.o
	@$(CC) $(CFLAGS) -c src/mlc_picture_data.c -o out/mlc_picture_data.o

out/mlc_init.o:	src/mlc_init.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_init.c out/mlc_init.o
	@$(CC) $(CFLAGS) -c src/mlc_init.c -o out/mlc_init.o

out/mlc_loop.o:	src/mlc_loop.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_loop.c out/mlc_loop.o
	@$(CC) $(CFLAGS) -c src/mlc_loop.c -o out/mlc_loop.o

out/mlc_cur_hide.o:	src/mlc_cur_hide.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_cur_hide.c out/mlc_cur_hide.o
	@$(CC) $(CFLAGS) -c src/mlc_cur_hide.c -o out/mlc_cur_hide.o

out/mlc_getcolor.o:	src/mlc_getcolor.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_getcolor.c out/mlc_getcolor.o
	@$(CC) $(CFLAGS) -c src/mlc_getcolor.c -o out/mlc_getcolor.o

out/mlc_clear.o:	src/mlc_clear.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_clear.c out/mlc_clear.o
	@$(CC) $(CFLAGS) -c src/mlc_clear.c -o out/mlc_clear.o

out/mlc_link.o:	src/mlc_link.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_link.c out/mlc_link.o
	@$(CC) $(CFLAGS) -c src/mlc_link.c -o out/mlc_link.o

out/mlc_move.o:	src/mlc_move.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_move.c out/mlc_move.o
	@$(CC) $(CFLAGS) -c src/mlc_move.c -o out/mlc_move.o

out/mlc_calloc.o:	src/mlc_calloc.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_calloc.c out/mlc_calloc.o
	@$(CC) $(CFLAGS) -c src/mlc_calloc.c -o out/mlc_calloc.o

out/mlc_key_hook.o:	src/mlc_key_hook.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_key_hook.c out/mlc_key_hook.o
	@$(CC) $(CFLAGS) -c src/mlc_key_hook.c -o out/mlc_key_hook.o

out/lock_read.o:	src/lock_read.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/lock_read.c out/lock_read.o
	@$(CC) $(CFLAGS) -c src/lock_read.c -o out/lock_read.o

out/mlc_picture_load.o:	src/mlc_picture_load.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_picture_load.c out/mlc_picture_load.o
	@$(CC) $(CFLAGS) -c src/mlc_picture_load.c -o out/mlc_picture_load.o

out/mlc_getchar.o:	src/mlc_getchar.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_getchar.c out/mlc_getchar.o
	@$(CC) $(CFLAGS) -c src/mlc_getchar.c -o out/mlc_getchar.o

out/mlc_picture_save.o:	src/mlc_picture_save.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_picture_save.c out/mlc_picture_save.o
	@$(CC) $(CFLAGS) -c src/mlc_picture_save.c -o out/mlc_picture_save.o

out/mlc_height.o:	src/mlc_height.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_height.c out/mlc_height.o
	@$(CC) $(CFLAGS) -c src/mlc_height.c -o out/mlc_height.o

out/mlc_getpos.o:	src/mlc_getpos.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_getpos.c out/mlc_getpos.o
	@$(CC) $(CFLAGS) -c src/mlc_getpos.c -o out/mlc_getpos.o

out/mlc_picture_color.o:	src/mlc_picture_color.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_picture_color.c out/mlc_picture_color.o
	@$(CC) $(CFLAGS) -c src/mlc_picture_color.c -o out/mlc_picture_color.o

out/mlc_setcur.o:	src/mlc_setcur.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_setcur.c out/mlc_setcur.o
	@$(CC) $(CFLAGS) -c src/mlc_setcur.c -o out/mlc_setcur.o

out/realloc_buff.o:	src/realloc_buff.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/realloc_buff.c out/realloc_buff.o
	@$(CC) $(CFLAGS) -c src/realloc_buff.c -o out/realloc_buff.o

out/mlc_setpos.o:	src/mlc_setpos.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_setpos.c out/mlc_setpos.o
	@$(CC) $(CFLAGS) -c src/mlc_setpos.c -o out/mlc_setpos.o

out/mlc_resize_hook.o:	src/mlc_resize_hook.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_resize_hook.c out/mlc_resize_hook.o
	@$(CC) $(CFLAGS) -c src/mlc_resize_hook.c -o out/mlc_resize_hook.o

out/mlc_create_picture.o:	src/mlc_create_picture.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_create_picture.c out/mlc_create_picture.o
	@$(CC) $(CFLAGS) -c src/mlc_create_picture.c -o out/mlc_create_picture.o

out/mlc_putchar.o:	src/mlc_putchar.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_putchar.c out/mlc_putchar.o
	@$(CC) $(CFLAGS) -c src/mlc_putchar.c -o out/mlc_putchar.o

out/buff_write.o:	src/buff_write.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/buff_write.c out/buff_write.o
	@$(CC) $(CFLAGS) -c src/buff_write.c -o out/buff_write.o

out/unlock_read.o:	src/unlock_read.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/unlock_read.c out/unlock_read.o
	@$(CC) $(CFLAGS) -c src/unlock_read.c -o out/unlock_read.o

out/mlc_capture.o:	src/mlc_capture.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_capture.c out/mlc_capture.o
	@$(CC) $(CFLAGS) -c src/mlc_capture.c -o out/mlc_capture.o

out/mlc_close.o:	src/mlc_close.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_close.c out/mlc_close.o
	@$(CC) $(CFLAGS) -c src/mlc_close.c -o out/mlc_close.o

out/free_buff.o:	src/free_buff.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/free_buff.c out/free_buff.o
	@$(CC) $(CFLAGS) -c src/free_buff.c -o out/free_buff.o

out/mlc_cur_show.o:	src/mlc_cur_show.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_cur_show.c out/mlc_cur_show.o
	@$(CC) $(CFLAGS) -c src/mlc_cur_show.c -o out/mlc_cur_show.o

out/mlc_loop_hook.o:	src/mlc_loop_hook.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_loop_hook.c out/mlc_loop_hook.o
	@$(CC) $(CFLAGS) -c src/mlc_loop_hook.c -o out/mlc_loop_hook.o

out/mlc_putcolor.o:	src/mlc_putcolor.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_putcolor.c out/mlc_putcolor.o
	@$(CC) $(CFLAGS) -c src/mlc_putcolor.c -o out/mlc_putcolor.o

out/mlc_strcmp.o:	src/mlc_strcmp.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_strcmp.c out/mlc_strcmp.o
	@$(CC) $(CFLAGS) -c src/mlc_strcmp.c -o out/mlc_strcmp.o

out/mlc_putnbr.o:	src/mlc_putnbr.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_putnbr.c out/mlc_putnbr.o
	@$(CC) $(CFLAGS) -c src/mlc_putnbr.c -o out/mlc_putnbr.o

out/mlc_resize.o:	src/mlc_resize.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_resize.c out/mlc_resize.o
	@$(CC) $(CFLAGS) -c src/mlc_resize.c -o out/mlc_resize.o

out/mlc_putstr.o:	src/mlc_putstr.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_putstr.c out/mlc_putstr.o
	@$(CC) $(CFLAGS) -c src/mlc_putstr.c -o out/mlc_putstr.o

out/mlc_fill_picture.o:	src/mlc_fill_picture.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_fill_picture.c out/mlc_fill_picture.o
	@$(CC) $(CFLAGS) -c src/mlc_fill_picture.c -o out/mlc_fill_picture.o

out/mlc_getcur.o:	src/mlc_getcur.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_getcur.c out/mlc_getcur.o
	@$(CC) $(CFLAGS) -c src/mlc_getcur.c -o out/mlc_getcur.o

out/mlc_keycode.o:	src/mlc_keycode.c \
		include/mlc.h\
		include/mlc_keycode.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_keycode.c out/mlc_keycode.o
	@$(CC) $(CFLAGS) -c src/mlc_keycode.c -o out/mlc_keycode.o

out/mlc_width.o:	src/mlc_width.c \
		include/mlc.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/mlc_width.c out/mlc_width.o
	@$(CC) $(CFLAGS) -c src/mlc_width.c -o out/mlc_width.o

all:	$(NAME)

re:	fclean all

debug:  fclean
	@printf "[Making Debug] . . .\n"
	@cd src && $(CC) $(DBGF) *.c -c && mv *.o ../
	@$(AR) $(NAME) *.o
	@$(CP) $(NAME) ../
	@$(CP) $(NAME) $(NDBG)
	@$(CP) $(NDBG) ../
	@$(CP) mlc.h ../
	@$(RM) src/*.o
	@$(RM) *.o
	@printf "[Done]\n"

clean:
	@printf "[%-9s]\n" "Clean"
	@$(RM) $(OBJS)
	@$(RM) *~
	@$(RM) \#*#

fclean: clean
	@printf "[%-9s]\n" "Fclean"
	@$(RM) $(NAME)

.PHONY: all clean fclean debug re
