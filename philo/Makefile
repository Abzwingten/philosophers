# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 18:47:38 by rantario          #+#    #+#              #
#    Updated: 2022/04/21 18:47:39 by rantario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	philo

SOURCES			:=	./sources
INCLUDES		:=	./includes
OBJECTS			:=	./obj

SRCS			:=	main.c \
					ft_libft.c \
					ft_check.c \
					ft_parse.c \
					ft_time.c \
					ft_print.c \
					ft_philo.c \
					ft_philo_actions.c \
					ft_threads.c

OBJS			:=	$(addprefix ${OBJECTS}/, $(SRCS:.c=.o))

CC				:=	clang
CFLAGS			:=	-Wall -Wextra -Werror #-g #-fsanitize=address
CINCLUDES		:=	-I ${INCLUDES}
CDEPENDENCIES	:=	-pthread -lpthread


# ============================================================================ #
#                                   COLOR                                      #
# ============================================================================ #

CL_BOLD	 = \e[1m
CL_DIM	= \e[2m
CL_UDLINE = \e[4m

NO_COLOR = \e[0m

BG_TEXT = \e[48;2;45;55;72m
BG_BLACK = \e[48;2;30;31;33m

FG_WHITE = $(NO_COLOR)\e[0;37m
FG_TEXT = $(NO_COLOR)\e[38;2;189;147;249m
FG_TEXT_PRIMARY = $(NO_COLOR)$(CL_BOLD)\e[38;2;255;121;198m

LF = \e[1K\r$(NO_COLOR)
CRLF= \n$(LF)


# ============================================================================ #
#                                   COLOR                                      #
# ============================================================================ #

CL_BOLD	 = \e[1m
CL_DIM	= \e[2m
CL_UDLINE = \e[4m

NO_COLOR = \e[0m

BG_TEXT = \e[48;2;45;55;72m
BG_BLACK = \e[48;2;30;31;33m

FG_WHITE = $(NO_COLOR)\e[0;37m
FG_TEXT = $(NO_COLOR)\e[38;2;189;147;249m
FG_TEXT_PRIMARY = $(NO_COLOR)$(CL_BOLD)\e[38;2;255;121;198m

LF = \e[1K\r$(NO_COLOR)
CRLF= \n$(LF)


# ============================================================================ #
#                                   RULES                                      #
# ============================================================================ #

${OBJECTS}/%.o: ${SOURCES}/%.c
	@mkdir -p $(dir $@)
	@printf "$(LF) $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@'s Object files $(FG_TEXT)"
	@${CC} ${CFLAGS} -o $@ -c $< ${CINCLUDES}

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${CDEPENDENCIES}
	@printf "$(LF) $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)\n$(NO_COLOR)"


clean:
	@printf "$(LF) $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)'s Object files...\n"
	@rm -rf ${OBJECTS}

fclean: clean
	@printf "$(LF) $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)\n"
	@rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re
