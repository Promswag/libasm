NAME	= libasm.a
OUT_DIR	= ./obj/

MAIN	= main.c
BMAIN	= main_bonus.c
SRCS	=	ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s
			
BSRCS	=	${SRCS} \
			ft_atoi_base_bonus.s \
			ft_list_push_front_bonus.s \
			ft_list_size_bonus.s \
			ft_list_sort_bonus.s \
			ft_list_remove_if_bonus.s 
			
OBJS	= ${SRCS:%.s=${OUT_DIR}%.o}
BOBJS	= ${BSRCS:%.s=${OUT_DIR}%.o}

ASM		= nasm -f elf64
CC		= gcc -g
CFLAGS	= -g -Wall -Wextra -Werror
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
	${ASM} $< -g -o $@
	
eval: ${NAME}
	${CC} ${CFLAGS} -o ${OUT} ${MAIN} ${NAME}
	${RUN}
	
beval: bonus
	${CC} ${CFLAGS} -o ${OUT} ${BMAIN} ${NAME}
	${RUN}
	
clean:
	${RM} ${OBJS}
	${RM} ${OUT_DIR}
	
fclean: clean
	${RM} ${NAME}
	
re: fclean ${NAME}
	
	