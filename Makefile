NAME	= libasm.a

OUT_DIR	= ./obj/

MAIN	= main.c
SRC		= ft__strlen.s
OBJS	= ${SRC:%.c=${OUT_DIR}%.o}

NASM	= nasm -f elf64 
CC		= gcc
CFLAGS	= 
AR		= ar rc
RM		= rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${NASM} ${SRC}
	${AR} ${NAME} ${OBJS}
	
eval: ${NAME}
	${CC} ${CFLAGS} ${MAIN} ${NAME}
	
clean:
	${RM} ${OBJS}
	${RM} ${OUT_DIR}
	
fclean: clean
	${RM} ${NAME}
	
	