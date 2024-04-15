/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:48:39 by gbaumgar          #+#    #+#             */
/*   Updated: 2024/04/15 15:20:11 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_data {
	char * s1;
	char * s2;
} t_data;

void	lst_clear(t_list **begin_list) {
	if (!begin_list)
		return;
	t_list	*cur, *tmp = *begin_list;
	while (tmp) {
		cur = tmp;
		tmp = tmp->next;
		free(cur->data);
		free(cur);
	}
}

void	lst_print(t_list *list) {
	while (list) {
		printf("lptr : %p\n", list);
		printf("data: %p\n", list->data);
		printf("data: %s\n", (char*)list->data);
		printf("next: %p\n", list->next);
		list = list->next;
		if (list)
			printf("\n");
	}
}

void	test_ft_atoi_base() {
	char *s = "FT_ATOI_BASE";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
	
	printf("%d\n", ft_atoi_base(0, 0));
	printf("%d\n", ft_atoi_base(0, ""));
	printf("%d\n", ft_atoi_base("", 0));
	printf("%d\n", ft_atoi_base("", ""));
	printf("%d\n", ft_atoi_base("aa", "abcdefg"));
	printf("%d\n", ft_atoi_base("ii", "abcdefghijkl"));
	printf("%d\n", ft_atoi_base("q", "abcdefghijklmnopqr\n\v "));
	printf("%d\n", ft_atoi_base("z", "abcdefghijklmnopqrstuvwxyz"));
	printf("%d\n", ft_atoi_base("   -+-10a0", "0123456789"));
	printf("%d\n", ft_atoi_base("   -+pomme", "abcdefghijklmnopqrstuvwxyz"));
	printf("%d\n", ft_atoi_base(" \n\v\t\r\f +-+-+-+-+10000000", "01"));
	printf("%d\n", ft_atoi_base("000000000000000", "01"));
};

void	test_ft_list_push_front() {
	char *s = "FT_LIST_PUSH_FRONT";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
	
	t_list *list = 0;
	ft_list_push_front(&list, strdup("Un"));
	lst_print(list);
	printf("---------------------------\n");
	ft_list_push_front(&list, strdup("Deux"));
	lst_print(list);
	lst_clear(&list);
};

void	test_ft_list_size() {
	char *s = "FT_LIST_SIZE";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
	
	t_list *list = 0;
	/* 1 */ ft_list_push_front(&list, strdup("Un"));
	printf("%d\n", ft_list_size(list));
	/* 2 */ ft_list_push_front(&list, strdup("Deux"));
	printf("%d\n", ft_list_size(list));
	/* 3 */  ft_list_push_front(&list, strdup(""));
	/* 4 */  ft_list_push_front(&list, strdup(""));
	/* 5 */  ft_list_push_front(&list, strdup(""));
	/* 6 */  ft_list_push_front(&list, strdup(""));
	/* 7 */  ft_list_push_front(&list, strdup(""));
	/* 8 */  ft_list_push_front(&list, strdup(""));
	printf("%d\n", ft_list_size(list));
	lst_clear(&list);
};

void	test_ft_list_sort() {
	char *s = "FT_LIST_SORT";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
	
	t_list *list = 0;
	/* 1 */ ft_list_push_front(&list, strdup(" "));
	/* 2 */ ft_list_push_front(&list, strdup("0"));
	/* 3 */ ft_list_push_front(&list, strdup("9"));
	/* 4 */ ft_list_push_front(&list, strdup("1"));
	/* 5 */ ft_list_push_front(&list, strdup("8"));
	/* 6 */ ft_list_push_front(&list, strdup("2"));
	/* 7 */ ft_list_push_front(&list, strdup("7"));
	/* 8 */ ft_list_push_front(&list, strdup("3"));
	/* 9 */ ft_list_push_front(&list, strdup("6"));
	/* 0 */ ft_list_push_front(&list, strdup("4"));
	/* 1 */ ft_list_push_front(&list, strdup("5"));
	/* 2 */ ft_list_push_front(&list, strdup("Z"));
	/* 3 */ ft_list_push_front(&list, strdup("a"));
	/* 4 */ ft_list_push_front(&list, strdup("A"));
	/* 5 */ ft_list_push_front(&list, strdup("z"));
	printf("%d\n", ft_list_size(list));
	lst_print(list);
	printf("---------------------------\n");
	ft_list_sort(&list, &strcmp);
	lst_print(list);
	lst_clear(&list);
};

void	test_ft_list_remove_if() {
	char *s = "FT_LIST_REMOVE_IF";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
	
	t_list *list = 0;
	ft_list_push_front(&list, strdup(" "));
	ft_list_push_front(&list, strdup("Pomme"));
	ft_list_push_front(&list, strdup("TEST TEST TEST"));
	lst_print(list);
	printf("---------------------------\n");
	ft_list_remove_if(&list, " ", &strcmp, &free);
	ft_list_remove_if(&list, "TEST TEST TEST", &strcmp, &free);
	ft_list_remove_if(&list, "Pommeau", &strcmp, &free);
	ft_list_sort(&list, &strcmp);
	lst_print(list);
	lst_clear(&list);
};

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	
	test_ft_atoi_base();
	test_ft_list_push_front();
	test_ft_list_size();
	test_ft_list_sort();
	test_ft_list_remove_if();
}

