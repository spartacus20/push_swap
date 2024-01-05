CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap.a
INCLUDES = include
FORMATS = formats/


SRCS = $(wildcard src/*.c)
LIBFT = libft
OBJS_DIR = obj/
OBJS = $(patsubst %,$(OBJS_DIR)%,$(SRCS:.c=.o))
GREEN = \033[0;92m

all: $(NAME)

$(NAME): $(OBJS)
	cp $(LIBFT)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)
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
	rm -f $(NAME)
	rm -rf $(OBJS_DIR)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
