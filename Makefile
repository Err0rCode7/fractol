NAME = fractol

CC = gcc

HEAD = -I includes -I minilibx

LIB = minilibx

FLAG = -Wall -Wextra -Werror $(HEAD)

RM = rm -rf

SRCS = srcs/main.c \
	srcs/main_utils.c \
	srcs/fractol.c \
	srcs/mandelbrot.c \
	srcs/julia.c \
	srcs/key.c

OBJS = $(addprefix objs/, $(subst srcs/, , $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB)
	cp $(LIB)/libmlx.dylib libmlx.dylib
	$(CC) $(FLAG) libmlx.dylib $(OBJS) -o $(NAME)

$(OBJS) : $(SRCS)
	$(CC) $(FLAG) -c $(SRCS)
	mkdir -p objs
	mv -f *.o objs

clean :
	make clean -C $(LIB)
	rm objs/*

fclean :
	$(RM) $(NAME) libmlx.dylib

re : fclean all
