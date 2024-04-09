NAME	= libasm.a
OUT_DIR	= ./obj/

MAIN	= main.c
BMAIN	= main_bonus.c
SRCS		=	ft__strlen.s \
			ft__strcpy.s \
			ft__strcmp.s \
			ft__write.s \
			ft__read.s \
			ft__strdup.s
			
BSRCS	=	${SRCS} \
			ft__atoi_base.s \
			ft__list_push_front.s \
			ft__list_size.s \
			ft__list_sort.s \
			ft__list_remove_if.s 
			
OBJS	= ${SRCS:%.s=${OUT_DIR}%.o}
BOBJS	= ${BSRCS:%.s=${OUT_DIR}%.o}

ASM		= nasm -f elf64
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS 	+= -fsanitize=address
AR		= ar rcs
RM		= rm -rf
MKDIR	= mkdir -p
OUT		= a.out
RUN		= ./${OUT}


all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}
	
bonus:	${BOBJS}
	${AR} ${NAME} ${BOBJS}
	
${OUT_DIR}%.o: %.s
	@${MKDIR} ${@D}
	${ASM} $< -o $@
	
eval: ${NAME}
	${CC} ${CFLAGS} -o ${OUT} ${MAIN} ${NAME}
	
beval: bonus
	${CC} ${CFLAGS} -o ${OUT} ${BMAIN} ${NAME}

test: eval
	${RUN}
	
btest: beval
	${RUN}
	
clean:
	${RM} ${OBJS}
	${RM} ${OUT_DIR}
	
fclean: clean
	${RM} ${NAME}
	
re: fclean ${NAME}
	
	