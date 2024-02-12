CC = cc
CFLAGS = -Wall -Wextra
NAME = push_swap
INCLUDES = include
FORMATS = formats/


SRCS = $(wildcard src/*.c)
LIBFT = libft
OBJS_DIR = obj/
OBJS = $(patsubst %,$(OBJS_DIR)%,$(SRCS:.c=.o))
GREEN = \033[0;92m

all: $(NAME)

$(NAME): $(OBJS)
	@${CC} ${CFLAGS} main.c ${OBJS} -I $(INCLUDES) ./libft/libft.a -o $(NAME)
	@echo "$(GREEN) $(NAME) has been created."

$(OBJS_DIR)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJS): | $(LIBFT)/libft.a

$(LIBFT)/libft.a:
	make -C $(LIBFT)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -rf $(NAME)
	rm -f libft.a
	rm -rf $(OBJS_DIR)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
