##
## Makefile generated
##

NAME	=	termcap_view

OBJS	=	\
		out/display.o \
		out/key.o \
		out/particles.o \
		out/main.o \

#####################################################
CC	=	gcc
RM	=	@rm -f

INCS	=	-I. -I./include -I../lib

CFLAGS	=	-W -Wall -Wstrict-prototypes -ansi
CFLAGS	+=	-pedantic -fomit-frame-pointer -O2 -O3
CFLAGS	+=	$(INCS)
DBGF	=	-W -Wall -Wstrict-prototypes -DDEBUG
DBGF	+=	-ansi -pedantic -fomit-frame-pointer -O0 -ggdb3 $(INCS)

LIBFS	=	-L. -L../lib/ -L/usr/lib/ -L/usr/local/lib/
LIBNS	+=	-lmlc_${MACHTYPE}-${OSTYPE}-${HOSTTYPE} -ltermcap

LFLAGS	=	$(LIBFS) $(LIBNS)

#####################################################
$(NAME):	$(OBJS)
	@printf "[%-9s]\t%s\n" "Linking" $@
	@$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

#####################################################

out/display.o:	src/display.c \
		include/t_view.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/display.c out/display.o
	@$(CC) $(CFLAGS) -c src/display.c -o out/display.o

out/key.o:	src/key.c \
		include/t_view.h\
		include/key.h\
		include/display.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/key.c out/key.o
	@$(CC) $(CFLAGS) -c src/key.c -o out/key.o

out/particles.o:	src/particles.c \
		include/t_view.h\
		include/particles.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/particles.c out/particles.o
	@$(CC) $(CFLAGS) -c src/particles.c -o out/particles.o

out/main.o:	src/main.c \
		include/t_view.h\
		include/display.h\
		include/key.h\
		include/particles.h\

	@printf "[Compiling]\t%-65s -> %s\n" src/main.c out/main.o
	@$(CC) $(CFLAGS) -c src/main.c -o out/main.o

all:	$(NAME)

re:	fclean all

debug:
	@printf "[Making Debug] . . .\n"
	@$(CC) $(DBGF) src/*.c -o $(NAME) $(LFLAGS) -pipe
	@rm -rf *.o
	@printf "[Done]\n"

clean:
	@printf "[%-9s]\n" "Clean"
	$(RM) $(OBJS)
	$(RM) *~
	$(RM) \#*#

fclean: clean
	@printf "[%-9s]\n" "Fclean"
	$(RM) $(NAME)

.PHONY: all clean fclean debug re
