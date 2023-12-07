# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 13:19:00 by fsalimba          #+#    #+#              #
#    Updated: 2023/09/19 13:19:05 by fsalimba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g -Iheaders/

SRCS			=	srcs/drawing_engine.c srcs/drawing_utility.c \
					srcs/event_handler.c srcs/win_utility.c \
					srcs/floor_organiser.c srcs/game_manager.c \
					srcs/keypress_utility.c srcs/malloc_utility.c \
					srcs/map_checker.c srcs/map_loader.c \
					srcs/wall_organiser.c srcs/win_handler.c \

MLXFLAGS		= -Lminilibx -lmlx -framework OpenGL -framework AppKit -lz
MLX				= minilibx/
LIBFT			= libft/
LIBRARY			= libft/libft.a minilibx/libmlx.a
X86				= arch -x86_64
OBJS			= $(SRCS:%.c=%.o)

all:				$(NAME)

%.o: %.c
					$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):		$(OBJS)
					$(X86) make -C $(MLX)
					$(X86) make -C $(LIBFT)
					$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) $(MLXFLAGS) -o $(NAME)

clean:
					make -C $(MLX) clean
					make -C $(LIBFT) clean
					$(RM) $(OBJS)

fclean:			clean
					make -C $(LIBFT) fclean
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re