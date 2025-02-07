SRC_1=srcs/server.c

SRC_2=srcs/client.c

OBJ_1=$(SRC_1:srcs/%.c=obj/%.o)

OBJ_2=$(SRC_2:srcs/%.c=obj/%.o)

NAME_1=server

NAME_2=client

CC=cc

CFLAGS=-Wall -Werror -Wextra -I./libft/includes -I./includes

LINK=-L./libft -lft

LIBFT_PATH=./libft

all: LIB $(NAME_1) $(NAME_2) 

LIB: 
	make -C $(LIBFT_PATH)

$(NAME_1): $(OBJ_1)
	$(CC) $^ $(LINK) -o $@

$(NAME_2): $(OBJ_2)
	$(CC) $^ $(LINK) -o $@

obj/%.o: srcs/%.c 
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJ_1) $(OBJ_2)
	rm -rf obj

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME_1)
	rm -f $(NAME_2)
re: fclean all

.PHONY: all clean fclean re LIB