# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csakamot <csakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 14:21:20 by csakamot          #+#    #+#              #
#    Updated: 2024/04/24 18:16:46 by csakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##----Executable File Name-----##
NAME			= FragTrap
##-----------------------------##

##-----Directory Location------##
SRCDIR			= ./

INCDIR			= ./

OBJDIR			= objs/
##-----------------------------##

##------------Srcs-------------##
MAINSRC			=	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

SRCS			= $(addprefix $(SRCDIR), ${MAINSRC})
##-----------------------------##

##-----------Object------------##
OBJS			= ${subst ${SRCDIR}, $(OBJDIR), ${SRCS:.cpp=.o}}
##-----------------------------##

##----------conpiler-----------##
CC				= g++
CFLAGS			= -Wall -Wextra -Werror -std=c++98 -fsanitize=address
##-----------------------------##

##-----------archive-----------##
ARFLAG			= rcs
##-----------------------------##

##--------Makefile rule--------##
all:			${NAME}

${NAME}:${OBJS}
				@echo "object file				compiled"
				@$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)%.o:$(SRCDIR)%.cpp
				@mkdir -p $(OBJDIR)
				@$(CC) $(CFLAGS) -I $(INCDIR)  -c $< -o $@

clean:
				@${RM} -rf ${OBJDIR}
				@echo "object file				removed"

fclean:			clean
				@${RM} -rf ${NAME}

re:				fclean all

exe:			re
				@make -s clean

.PHONY:			all clean fclean re exe
##-----------------------------##
