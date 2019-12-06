SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strdup.c \
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_split.c ft_substr.c ft_strtrim.c ft_tolower.c \
		ft_toupper.c ft_strlcpy.c ft_calloc.c

BON = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJ = $(SRC:%.c=%.o)
BON_OBJ = $(BON:%.c=%.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc libft.a $(OBJ)

bonus: $(BON_OBJ)
	ar rc libft.a $(BON_OBJ)

%.o: %.c
	gcc -c -Wall -Werror -Wextra $^ -o $@

clean:
	rm -f $(OBJ)
	rm -f $(BON_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
