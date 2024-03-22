NAME	= libasm.a
OUT_DIR	= ./obj/

MAIN	= main.c
SRC		= ft__strlen.s ft__strcpy.s
OBJS	= ${SRC:%.s=${OUT_DIR}%.o}

ASM		= nasm -f elf64
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
# CFLAGS 	+= -fsanitize=address
AR		= ar rcs
RM		= rm -rf
MKDIR	= mkdir -p
OUT		= libasm.out
RUN		= ./${OUT}


all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}
	
${OUT_DIR}%.o: %.s
	@${MKDIR} ${@D}
	${ASM} $< -o -g $@
	
eval: ${NAME}
	${CC} ${CFLAGS} -o ${OUT} ${MAIN} ${NAME}
	
test: eval
	${RUN}
	
clean:
	${RM} ${OBJS}
	${RM} ${OUT_DIR}
	
fclean: clean
	${RM} ${NAME}
	
re: fclean ${NAME}
	
	