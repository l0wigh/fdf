# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomathi <thomathi@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 14:08:35 by thomathi          #+#    #+#              #
#    Updated: 2022/08/18 19:38:06 by thomathi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = fdf fdf_errors fdf_init fdf_main fdf_engines fdf_exit fdf_bonus fdf_debug

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m
TOTEM 		= 🦁

NAME				= fdf
SRCS 				= $(FILES:%=srcs/%.c)
OBJS_DIR			= objs/
PROJECT_H			= srcs/fdf.h
OBJS				= $(SRCS:.c=.o)
OBJECTS_PREFIXED 	= $(addprefix $(OBJS_DIR), $(OBJS))
CC					= gcc
CC_FLAGS			= -Wall -Wextra -Werror -g3
LDFLAGS				= ft_printf/libftprintf.a gnl/gnl.a -lmlx -framework OpenGL -framework AppKit -lm -lz
LIBMLXMAC			= printf "\n"; make -C minilibx_macos 2> /dev/null
LIBGNL				= make -C gnl
LIBPRINTFT			= make -C ft_printf

$(OBJS_DIR)%.o : %.c $(PROJECT_H)
	@$(LIBGNL)
	@$(LIBPRINTFT)
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)srcs
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@printf	"\033[2K\r${BLU}${TOTEM} [BUILD]${RST} '$<' $(END)"

$(NAME): $(OBJECTS_PREFIXED)
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) $(LDFLAGS) 
	@printf "\033[2K\r\033[0;32m${TOTEM} [END]\033[0m $(NAME)$(END)\n"

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@printf "\033[2K\r${GRN}${TOTEM} [CLEAN]${RST} done$(END)\n"

fclean: clean
	@make clean -C minilibx_macos
	@make fclean -C gnl
	@make fclean -C ft_printf
	@rm -f $(NAME)
	@rm -rf $(OBJS_DIR)
	@printf "\033[2K\r${GRN}${TOTEM} [FCLEAN]${RST} done$(END)\n"

re: fclean all

.PHONY:		all clean fclean re
