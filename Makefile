# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbrichau <cbrichau@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 17:11:54 by cbrichau          #+#    #+#              #
#    Updated: 2020/02/22 19:13:26 by aben-azz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
GREEN = \x1b[32m
RED = \x1b[31m
END = \x1b[0m
LIB = libft/libft.a
EXCEPTIONS = $(NAME).dSYM .DS_Store

all: getlibft $(NAME)

$(NAME): *.o
	@gcc $(FLAGS) *.c libft/libft.a -o $(NAME)
	@#for check if your code is strong
<<<<<<< HEAD
	@#gcc $(FLAGS) *.c libft/libft.a -o $(NAME)
=======
	@#gcc $(FLAGS) *.c libft/libft.a -fsanitize=address -o $(NAME)
>>>>>>> 013b98f415153171ca627e0bde26d963b20acdb3
	@#for check leaks and location of segfault (if there is) and code problem +
	@#gcc  $(FLAGS) *.c libft/libft.a -g -v -o $(NAME)
	@printf "$(GREEN)Compilation of fillit with fsanitize succeded.\n$(END)"

getlibft:
	@make -C libft

valgrind:
	@gcc $(FLAGS) *.c libft/libft.a -g -v -o $(NAME)
	@printf "$(GREEN)Compilation with valgrind succeded\n"
	@printf "Use 'valgrind --leak-check=full --show-leak-kinds=all ./fillit MAP' for check leak\n$(END)"

fsanitize:
	@gcc $(FLAGS) *.c libft/libft.a -fsanitize=address -o $(NAME)
	@printf "$(GREEN)Compilation with fsanitize succeded.\n$(END)"
clean:
	@/bin/rm -rf srcs/*.o
	@/bin/rm -rf libft/*.o
	@/bin/rm -rf $(EXCEPTIONS)
	@printf "$(RED)Objects are removed correctly.\n$(END)"

fclean: clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(LIB)
	@printf "$(RED)$(NAME) and $(LIB) are removed correctly.\n$(END)"


re: fclean all
