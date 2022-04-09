# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 15:50:21 by rantario          #+#    #+#              #
#    Updated: 2022/04/09 16:06:33 by rantario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLIBFLAGS = -lncurses
# CFLAGS += -g3 -fsanitize=address
ifeq ($(DEBUG),true)
	CFLAGS += -g
endif

RM = rm
RMFLAGS = -rf

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

HEADERS = $(wildcard $(INC_DIR)/*.h)

SRCS = $(wildcard $(SRC_DIR)/*.c)

vpath %.c $(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

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

all : $(NAME)

clean :
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	@printf "$(LF) $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)'s Object files...\n"

fclean : clean
	@$(RM) $(RMFLAGS) ../bin/$(NAME)
	@printf "$(LF) $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)\n"

re : fclean all

# ============================================================================ #
#                                   ALCHEMY                                    #
# ============================================================================ #

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c $(LIBFT_FILE) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	@printf "$(LF) $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)from $(FG_TEXT_PRIMARY)$<"

$(NAME) : $(LIBFT_FILE) $(HEADERS) $(OBJS)
	@printf "$(LF) $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@'s Object files $(FG_TEXT)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(CLIBFLAGS) $(LIBFT_FLAGS) $(OBJS) -o $@
	@printf "$(LF) $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)\n$(NO_COLOR)"

.PHONY: all clean fclean re bonus
