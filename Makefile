NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

HANDLE = handlers

CFLAGS = -c $(FLAGS)

SRC = ft_printf.c\
	  parser.c\
	  $(HANDLE)/apply_plusspace.c\
	  $(HANDLE)/apply_blanks.c\
	  $(HANDLE)/apply_zero.c\
	  $(HANDLE)/apply_precision.c\
	  $(HANDLE)/num_handler.c\
	  $(HANDLE)/n_handler.c\
	  $(HANDLE)/char_handler.c\
	  $(HANDLE)/hex_handler.c\
	  $(HANDLE)/int_handler.c\
	  $(HANDLE)/octal_handler.c\
	  $(HANDLE)/unsigned_handler.c\
	  $(HANDLE)/perc_handler.c\
	  $(HANDLE)/wchar_handler.c\
	  $(HANDLE)/wstring_handler.c\
	  $(HANDLE)/string_handler.c\
	  $(HANDLE)/pointer_handler.c\
	  $(HANDLE)/failconv_handler.c\


LIBSRC =libft/ft_isdigit.c \
		libft/ft_isalnum.c \
		libft/ft_isascii.c \
		libft/ft_isprint.c \
		libft/ft_toupper.c \
		libft/ft_touppers.c \
		libft/ft_tolower.c \
		libft/ft_tolowers.c \
		libft/ft_isalpha.c \
		libft/ft_strdup.c \
		libft/ft_strndup.c \
		libft/ft_atoi.c \
		libft/ft_atoi_base.c \
		libft/ft_strlen.c \
		libft/ft_putchar.c \
		libft/ft_putstr.c \
		libft/ft_putendl.c \
		libft/ft_putnbr.c \
		libft/ft_strcpy.c \
		libft/ft_strncpy.c \
		libft/ft_strcmp.c \
		libft/ft_strncmp.c \
		libft/ft_strcat.c \
		libft/ft_strncat.c \
		libft/ft_strchr.c \
		libft/ft_strrchr.c \
		libft/ft_strstr.c \
		libft/ft_strnstr.c \
		libft/ft_memset.c \
		libft/ft_memcpy.c \
		libft/ft_bzero.c \
		libft/ft_memccpy.c \
		libft/ft_memcmp.c \
		libft/ft_memchr.c \
		libft/ft_memmove.c \
		libft/ft_strlcat.c \
		libft/ft_memalloc.c \
		libft/ft_strnew.c \
		libft/ft_memdel.c \
		libft/ft_strclr.c \
		libft/ft_strdel.c \
		libft/ft_strdel2.c \
		libft/ft_striter.c \
		libft/ft_striteri.c \
		libft/ft_strmap.c \
		libft/ft_strmapi.c \
		libft/ft_strequ.c \
		libft/ft_strnequ.c \
		libft/ft_strsub.c \
		libft/ft_strjoin.c \
		libft/ft_strrev.c \
		libft/ft_strtrim.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_itoa.c \
		libft/ft_itoa_base.c \
		libft/ft_utoa.c \
		libft/ft_utoa_base.c \
		libft/ft_lltoa.c \
		libft/ft_lltoa_base.c \
		libft/ft_ulltoa.c \
		libft/ft_ulltoa_base.c \
		libft/ft_strsplit.c \
		libft/ft_lstnew.c \
		libft/ft_lstdelone.c \
		libft/ft_lstdel.c \
		libft/ft_lstadd.c \
		libft/ft_lstiter.c \
		libft/ft_lstmap.c \
		libft/ft_lstaddtail.c \
		libft/ft_abs.c \
		libft/ft_swap.c \
		libft/ft_cswap.c \
		libft/ft_arrintsort.c \
		libft/ft_pow.c \
		libft/ft_max.c \
		libft/ft_min.c \
		libft/ft_unictoa.c

OBJ = $(SRC:.c=.o)

LIBOBJ = $(LIBSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBOBJ)
	ar rc $(NAME) $(OBJ) $(LIBOBJ)
	ranlib $(NAME)

#	gcc $(FLAGS) $(OBJ) libft/libft.a
clean: 
	rm -rf $(OBJ) $(LIBOBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re
