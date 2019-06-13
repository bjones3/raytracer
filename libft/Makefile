NAME = libft.a
OBJS = ft_memset.o ft_bzero.o ft_memcpy.o \
		ft_memccpy.o ft_memmove.o ft_memchr.o \
		ft_memcmp.o ft_strlen.o ft_strdup.o \
		ft_strcpy.o ft_strncpy.o ft_strcat.o \
		ft_strncat.o ft_strlcat.o ft_strchr.o \
		ft_strrchr.o ft_strstr.o ft_strnstr.o \
		ft_strcmp.o ft_strncmp.o ft_atoi.o \
		ft_isalpha.o ft_isdigit.o ft_isalnum.o \
		ft_isascii.o ft_isprint.o ft_toupper.o \
		ft_tolower.o ft_memalloc.o ft_memdel.o \
		ft_strnew.o ft_strdel.o ft_strclr.o \
		ft_striter.o ft_striteri.o ft_strmap.o \
		ft_strmapi.o ft_strequ.o ft_strnequ.o \
		ft_strsub.o ft_strjoin.o ft_strtrim.o \
		ft_strsplit.o ft_itoa.o ft_putchar.o \
		ft_putstr.o ft_putendl.o ft_putnbr.o \
		ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o \
		ft_putnbr_fd.o ft_lstnew.o ft_lstdelone.o \
		ft_lstdel.o ft_lstadd.o ft_lstiter.o \
		ft_lstmap.o ft_islower.o ft_isupper.o \
		ft_wordct.o ft_isspace.o ft_swap.o \
		ft_printbits.o ft_putmem.o ft_putmem_endl.o \
		ft_strjoin_free.o ft_strcpy_until.o ft_strcpy_after_free.o \
		ft_strarrdel.o ft_intdel.o ft_intarrdel.o \
		ft_atof.o
GNL = get_next_line.o
CFLAGS = -Wall -Wextra -Werror -I includes

all: $(NAME)

$(NAME) : $(OBJS) $(GNL)
	ar rcs $(NAME) $(OBJS) $(GNL)

$(OBJS) : %.o: %.c includes/libft.h
	gcc $(CFLAGS) -c $<

$(GNL) : %.o: %.c includes/libft.h includes/get_next_line.h
	gcc $(CFLAGS) -c $<

clean :
	rm -f $(OBJS) $(GNL)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re