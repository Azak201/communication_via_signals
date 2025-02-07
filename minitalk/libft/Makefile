SRCS =	srcs/ft_atoi.c srcs/ft_itoa.c srcs/ft_lstnew_bonus.c srcs/ft_putchar.c srcs/ft_putstr_fd.c srcs/ft_strlcpy.c \
srcs/ft_tolower.c srcs/ft_bzero.c srcs/ft_lstadd_back_bonus.c srcs/ft_lstsize_bonus.c srcs/ft_putchar_fd.c srcs/ft_putu.c \
srcs/ft_strlen.c srcs/ft_toupper.c srcs/ft_calloc.c srcs/ft_lstadd_front_bonus.c  srcs/ft_memchr.c srcs/ft_putendl_fd.c \
srcs/ft_split.c srcs/ft_strmapi.c srcs/get_next_line.c srcs/ft_isalnum.c srcs/ft_lstclear_bonus.c srcs/ft_memcmp.c srcs/ft_puthex.c \
srcs/ft_strchr.c srcs/ft_strncmp.c srcs/printargs.c srcs/ft_isalpha.c srcs/ft_lstdelone_bonus.c srcs/ft_memcpy.c srcs/ft_putnbr.c \
srcs/ft_strdup.c srcs/ft_strnstr.c srcs/ft_isascii.c srcs/ft_lstiter_bonus.c srcs/ft_memmove.c srcs/ft_putnbr_fd.c srcs/ft_striteri.c\
srcs/ft_strrchr.c srcs/ft_isdigit.c srcs/ft_lstlast_bonus.c srcs/ft_memset.c srcs/ft_putp.c srcs/ft_strjoin.c srcs/ft_strtrim.c\
srcs/ft_isprint.c srcs/ft_lstmap_bonus.c srcs/ft_printf.c srcs/ft_putstr.c srcs/ft_strlcat.c srcs/ft_substr.c

OBJS = $(SRCS:srcs/%.c=obj/%.o)

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./includes

LINK = -L. -lft

all : $(NAME)

$(NAME) : $(OBJS)
	ar crs $@ $^

obj/%.o : srcs/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

bonus :	$(NAME) $(BONOBJ)
	ar rcs $(NAME) $(BONOBJ)
clean :
	rm -f $(OBJS) $(BONOBJ)
	rm -rf obj
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re bonus 

