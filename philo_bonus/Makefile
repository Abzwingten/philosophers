# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 18:48:42 by rantario          #+#    #+#              #
#    Updated: 2022/04/26 15:23:23 by rantario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	philo_bonus

SOURCES			:=	./srcs
INCLUDES		:=	./includes
OBJECTS			:=	./objs

SRCS			:=	main.c \
					init.c \
					libft.c \
					parser.c \
					philo_proc.c \
					time.c

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
