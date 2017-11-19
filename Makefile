# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guiricha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:55:06 by guiricha          #+#    #+#              #
#    Updated: 2017/11/19 15:12:32 by guiricha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c init_structs.c parse_options.c debug_print_funcs.c \
		   seperate_files_and_folders.c ft_ls.c add_file_to_list.c \
		   link_list_create.c list_debug.c handle_error.c
NAME = ft_ls
CC = gcc
CFLAGS =  -Wall -Wextra -Werror
INCS = -Ilibft -Iprintf -Iincludes
SRC_DIR = ./sources/
SRC_NDIR=$(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ_NAME = $(SRC_NAME:.c=.o)
O_D = ./objects/
OBJ_NDIR=$(addprefix $(O_D), $(OBJ_NAME))
STCS = libft.a libftprintf.a

all: $(NAME)

$(NAME): $(OBJ_NDIR)
	@make -s -C libft && cp -f libft/libft.a ./
	@echo "\033[97mLIBRARY \033[95mLIBFT \033[97mhas been created...\033[0m";
	@make -s -C printf && cp -f printf/libftprintf.a ./
	@echo "\033[97mLIBRARY \033[95mFT_PRINTF \033[97mhas been created...\033[0m";
	@$(CC) -o $(NAME) $(OBJ_NDIR) $(STCS)
	@echo "\033[97mEXECUTABLE \033[92m$(NAME) \033[97mhas been created...\033[0m";
$(OBJ_NDIR):
	@echo "\033[91mMaking\033[0m";
	@mkdir -p $(O_D)
	@echo "\033[97mOBJECT FOLDER \033[33m$(O_D) \033[97mhas been created...\033[0m";
	@$(CC) $(CFLAGS) -c $(SRC_NDIR) $(INCS) $(SDL_CMP)
	@echo "\033[97mOBJECTS \033[33m$(OBJ_NAME) \033[97mhave been created...\033[0m";
	@echo "\033[97mMOVING \033[33m$(OBJ_NAME) \033[97mTO\033[33m $(O_D)\033[97m...\033[0m";
	@mv $(OBJ_NAME) $(O_D)
clean:
	@rm -rf $(O_D)
	@echo "\033[97mOBJECT FOLDER \033[31m$(O_D) \033[97mhas been removed...\033[0m";
	@rm -f $(STCS)
	@echo "\033[97mLIBRARIES \033[31m$(STCS) \033[97mhave been removed...\033[0m";

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@make -C printf fclean
	@echo "\033[97mBINARY \033[92m$(NAME) \033[97mhas been removed...\033[0m";
re: fclean all

.PHONY: re fclean clean all
