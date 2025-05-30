NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MLX42_PATH = libs/MLX42
MLX42 = $(MLX42_PATH)/build/libmlx42.a

LIBFT_PATH = libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

HEADERS = -I ./libs -I $(MLX42_PATH)/include/MLX42 -I $(LIBFT_PATH)

SRCS =	./src/map_checker.c\
		./src/img_to_window.c\
		./src/read_map.c\
		./src/so_long.c\
		./src/movement.c\
		./src/text_to_img.c\
		./src/ft_error.c\

SRCDIR = src/
OBJDIR = obj/
OBJS = $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

all : $(MLX42) $(LIBFT) $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX42) $(LIBFT) $(HEADERS) -lglfw -o $(NAME) -lm

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX42):
	cmake $(MLX42_PATH) -B $(MLX42_PATH)/build && make -C $(MLX42_PATH)/build -j4

clean:
	$(RM) obj
	make -C $(LIBFT_PATH) clean
	make -C $(MLX42_PATH)/build clean

fclean:
	$(RM) obj $(NAME)
	make -C $(LIBFT_PATH) fclean
	$(RM) $(MLX42_PATH)/build

re: fclean all