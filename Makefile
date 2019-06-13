NAME = RTv1
OBJS = objs/add_obj.o objs/file_reader.o objs/hooks.o objs/hooks2.o objs/intersect.o objs/intersect2.o objs/lighting.o objs/main.o objs/math1.o objs/math2.o objs/new_obj.o objs/surface_normals.o objs/tracer.o
HEADERS = includes libft/includes minilibx_macos
HEADERS2 = includes/rtv1.h libft/includes/libft.h minilibx_macos/mlx.h
LIBFT = libft/libft.a
LIBMLX = minilibx_macos/libmlx.a
CFLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework Appkit -framework OpenGL

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	gcc $(CFLAGS) -I libft/includes -I minilibx_macos $(OBJS) $(LIBFT) $(LIBMLX) -o $(NAME) $(FRAMEWORKS)

$(OBJS): objs/%.o: srcs/%.c $(HEADERS2)
	gcc $(CFLAGS) -I libft/includes -I minilibx_macos -c $< -o $@

$(LIBFT):
	make -C libft

$(LIBMLX):
	make -C minilibx_macos

clean:
	rm -f objs/*.o
	make clean -C libft
	make clean -C minilibx_macos

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY : all clean fclean re