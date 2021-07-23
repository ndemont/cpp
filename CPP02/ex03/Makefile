NAME		= binaryspacepartitioning
CC			= clang++
RM			= rm -rf
CLEAR		= \033[2K\c

SRCS_DIR	= .
INC_DIR		= .
OBJS_DIR	= objs

CFLAGS		= -Wall -Wextra -Werror -std=c++98
IFLAGS		= -I${INC_DIR}

INC			= $(shell find ${INC_DIR} -type f -name "*.h")
SRCS 		= $(notdir $(shell find ${SRCS_DIR} -type f -name "*.cpp"))
OBJS 		= $(addprefix ${OBJS_DIR}/, $(SRCS:.cpp=.o))
vpath		%.cpp $(shell find ${SRCS_DIR} -type d)

all:		init ${NAME}

init:
			$(shell mkdir -p ${OBJS_DIR})

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o $@ $^

${OBJS_DIR}/%.o:	%.cpp
			@echo "${CLEAR}"
			@echo "compiling $<\r\c"
			@${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

clean:
			${RM} ${OBJS_DIR}

fclean:
			${RM} ${OBJS_DIR}
			${RM} ${NAME}

re:			fclean all

.SUFFIXES:	.cpp .o .h .hpp
.PHONY:		all clean fclean re