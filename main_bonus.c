/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:48:39 by gbaumgar          #+#    #+#             */
/*   Updated: 2024/04/13 20:01:58 by gbaumgar         ###   ########.fr       */
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
	
void	test_ft_atoi_base() {

	// printf("%d\n", ft_atoi_base(0, 0));
	// printf("%d\n", ft_atoi_base(0, ""));
	// printf("%d\n", ft_atoi_base("", 0));
	// printf("%d\n", ft_atoi_base("", ""));
	// printf("%d\n", ft_atoi_base("aa", "abcdefg"));
	// printf("%d\n", ft_atoi_base("ii", "abcdefghijkl"));
	// printf("%d\n", ft_atoi_base("q", "abcdefghijklmnopqr"));
	// printf("%d\n", ft_atoi_base("z", "abcdefghijklmnopqrstuvwxyz"));
	// printf("%d\n", ft_atoi_base("   -+-10a0", "0123456789"));
	// printf("%d\n", ft_atoi_base("   -+pomme", "abcdefghijklmnopqrstuvwxyz"));
	// printf("%d\n", ft_atoi_base(" \n\v\t\r\f +-+-+-+-+10000000", "01"));
	
	t_data src[] = {
		{0, 0},
		{0, ""},
		{"", 0},
		{"", ""},
		{"aa", "abcdefg"},
		{"ii", "abcdefghijkl"},
		{"q", "abcdefghijklmnopqr"},
		{"z", "abcdefghijklmnopqrstuvwxyz"},
		{"   -+-10a0", "0123456789"},
		{"   -+pomme", "abcdefghijklmnopqrstuvwxyz"},
		{" \n\v\t\r\f +-+-+-+-+11111111", "01"},
		{"1", "0231"}
	};
	
	int	i = -1;
	while (++i * sizeof(t_data) < sizeof(src)) {
		printf("%p\n", src[i].s1);
		printf("%p\n", src[i].s2);
		printf("%d\n\n", ft_atoi_base(src[i].s1, src[i].s2));
	}
};

void	test_ft_list_push_front() {
	
};

void	test_ft_list_size() {
	
};

void	test_ft_list_sort() {
	
};

void	test_ft_list_remove_if() {
	
};

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	
	test_ft_atoi_base();
	exit(0);
	// return (0);

	// t_list	*a = malloc(sizeof(t_list));
	// t_list	*b = malloc(sizeof(t_list));
	// a->data = "A_________________";
	// a->next = b;
	// b->data = "0OOOOOOOOOOOOOOOOOOOOOO";
	// b->next = 0;
	
	// char	*str = ft_strdup("douze");
	
	// t_list	*tmp;
	
	// printf("\n");
	// printf("A: %p\nA->data: %p\nA->data: %s\nA->next: %p\n", a, a->data, (char*)a->data, a->next);
	// printf("B: %p\nB->data: %p\nB->data: %s\nB->next: %p\n", b, b->data, (char*)b->data, b->next);
	// printf("\n");
	
	// ft_list_push_front(&a, "Z########################");
	// ft_list_push_front(&a, "0");
	// ft_list_push_front(&a, "5");
	// ft_list_push_front(&a, "9");
	// ft_list_push_front(&a, "+");
	// ft_list_push_front(&a, "\n");
	// ft_list_push_front(&a, "A");
	// ft_list_push_front(&a, "A #");
	// ft_list_push_front(&a, "A0");
	// ft_list_push_front(&a, "h");
	// ft_list_push_front(&a, "t");
	// ft_list_push_front(&a, "N");
	// ft_list_push_front(&a, "z");
	// ft_list_push_front(&a, "P");
	// ft_list_push_front(&a, " ");
	// tmp = a;
	// while (tmp) {
	// 	printf("tmp: %p\ntmp->data: %p\ntmp->data: %s\ntmp->next: %p\n", tmp, tmp->data, (char*)tmp->data, tmp->next);
	// 	tmp = tmp->next;
	
	// }
	// printf("\n");
	
	// tmp = a;
	// int	ret = ft_list_size(tmp);
	// printf("%d\n", ret);
	
	// tmp = a;
	// ft_list_sort(&tmp, strcmp);
	// printf("%llx\n", ptr);
	// printf("%s\n", (char *)ptr);
	
	// printf("\n");
	// tmp = a;
	// while (tmp) {
	// 	printf("tmp: %p\ntmp->data: %p\ntmp->data: %s\ntmp->next: %p\n", tmp, tmp->data, (char*)tmp->data, tmp->next);
	// 	tmp = tmp->next;
	// }
	// printf("\n");
	
	// t_list *R = 0;
	// t_list **REMOVE = &R;
	
	// ft_list_push_front(REMOVE, strdup("a"));
	// ft_list_push_front(REMOVE, strdup("A"));
	// ft_list_push_front(REMOVE, strdup("a"));
	// ft_list_push_front(REMOVE, strdup("A"));
	// ft_list_push_front(REMOVE, strdup("A"));
	// ft_list_push_front(REMOVE, strdup("A"));
	// ft_list_push_front(REMOVE, strdup("A"));
	// ft_list_push_front(REMOVE, strdup("a"));
	// ft_list_push_front(REMOVE, strdup("A"));
	// ft_list_push_front(REMOVE, strdup("A"));
	// ft_list_push_front(REMOVE, strdup("a"));
	// ft_list_push_front(REMOVE, strdup("a"));
	// ft_list_push_front(REMOVE, strdup("a"));
	// ft_list_push_front(REMOVE, strdup("a"));
	// ft_list_push_front(REMOVE, strdup("cookie"));
	// ft_list_push_front(REMOVE, strdup("cookie"));
	// ft_list_push_front(REMOVE, strdup("a"));
	// ft_list_push_front(REMOVE, strdup("cookie"));
	// ft_list_push_front(REMOVE, strdup("a"));
	
	// tmp = *REMOVE;
	// while (tmp) {
	// 	printf("tmp: %p\ntmp->data: %p\ntmp->data: %s\ntmp->next: %p\n", tmp, tmp->data, (char*)tmp->data, tmp->next);
	// 	tmp = tmp->next;
	// }
	// ft_list_remove_if(REMOVE, "a", strcmp, free);

	// printf("\n\n\n\n");
	// tmp = *REMOVE;
	// while (tmp) {
	// 	printf("tmp: %p\ntmp->data: %p\ntmp->data: %s\ntmp->next: %p\n", tmp, tmp->data, (char*)tmp->data, tmp->next);
	// 	tmp = tmp->next;
	// }
	// printf("\n");

	// t_list	*next;
	// tmp = *REMOVE;
	// while (tmp) {
	// 	next = tmp->next;
	// 	free(tmp->data);
	// 	free(tmp);
	// 	tmp = next;
	// }
}

