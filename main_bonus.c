/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:48:39 by gbaumgar          #+#    #+#             */
/*   Updated: 2024/04/12 21:23:40 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	
	// printf("%d\n", ft__atoi_base("", ""));
	// printf("%d\n", ft__atoi_base("aa", "abcdefg"));
	// printf("%d\n", ft__atoi_base("ii", "abcdefghijkl"));
	// printf("%d\n", ft__atoi_base("q", "abcdefghijklmnopqr"));
	// printf("%d\n", ft__atoi_base("z", "abcdefghijklmnopqrstuvwxyz"));
	// printf("%d\n", ft__atoi_base("   -+-10a0", "0123456789"));
	// printf("%d\n", ft__atoi_base("   -+pomme", "abcdefghijklmnopqrstuvwxyz"));
	// printf("%d\n", ft__atoi_base(" \n\v\t\r\f +-+-+-+-+10000000", "01"));
	// printf("%d\n", ft__atoi_base(0, 0));

	// t_list	*a = malloc(sizeof(t_list));
	// t_list	*b = malloc(sizeof(t_list));
	// a->data = "A_________________";
	// a->next = b;
	// b->data = "0OOOOOOOOOOOOOOOOOOOOOO";
	// b->next = 0;
	
	// char	*str = ft__strdup("douze");
	
	t_list	*tmp;
	
	// printf("\n");
	// printf("A: %p\nA->data: %p\nA->data: %s\nA->next: %p\n", a, a->data, (char*)a->data, a->next);
	// printf("B: %p\nB->data: %p\nB->data: %s\nB->next: %p\n", b, b->data, (char*)b->data, b->next);
	// printf("\n");
	
	// ft__list_push_front(&a, "Z########################");
	// ft__list_push_front(&a, "0");
	// ft__list_push_front(&a, "5");
	// ft__list_push_front(&a, "9");
	// ft__list_push_front(&a, "+");
	// ft__list_push_front(&a, "\n");
	// ft__list_push_front(&a, "A");
	// ft__list_push_front(&a, "A #");
	// ft__list_push_front(&a, "A0");
	// ft__list_push_front(&a, "h");
	// ft__list_push_front(&a, "t");
	// ft__list_push_front(&a, "N");
	// ft__list_push_front(&a, "z");
	// ft__list_push_front(&a, "P");
	// ft__list_push_front(&a, " ");
	// tmp = a;
	// while (tmp) {
	// 	printf("tmp: %p\ntmp->data: %p\ntmp->data: %s\ntmp->next: %p\n", tmp, tmp->data, (char*)tmp->data, tmp->next);
	// 	tmp = tmp->next;
	
	// }
	// printf("\n");
	
	// tmp = a;
	// int	ret = ft__list_size(tmp);
	// printf("%d\n", ret);
	
	// tmp = a;
	// ft__list_sort(&tmp, strcmp);
	// printf("%llx\n", ptr);
	// printf("%s\n", (char *)ptr);
	
	// printf("\n");
	// tmp = a;
	// while (tmp) {
	// 	printf("tmp: %p\ntmp->data: %p\ntmp->data: %s\ntmp->next: %p\n", tmp, tmp->data, (char*)tmp->data, tmp->next);
	// 	tmp = tmp->next;
	// }
	// printf("\n");
	
	t_list *R = 0;
	t_list **REMOVE = &R;
	
	ft__list_push_front(REMOVE, strdup("a"));
	ft__list_push_front(REMOVE, strdup("A"));
	ft__list_push_front(REMOVE, strdup("a"));
	ft__list_push_front(REMOVE, strdup("A"));
	ft__list_push_front(REMOVE, strdup("A"));
	ft__list_push_front(REMOVE, strdup("A"));
	ft__list_push_front(REMOVE, strdup("A"));
	ft__list_push_front(REMOVE, strdup("a"));
	ft__list_push_front(REMOVE, strdup("A"));
	ft__list_push_front(REMOVE, strdup("A"));
	ft__list_push_front(REMOVE, strdup("a"));
	ft__list_push_front(REMOVE, strdup("a"));
	ft__list_push_front(REMOVE, strdup("a"));
	ft__list_push_front(REMOVE, strdup("a"));
	ft__list_push_front(REMOVE, strdup("cookie"));
	ft__list_push_front(REMOVE, strdup("cookie"));
	ft__list_push_front(REMOVE, strdup("a"));
	ft__list_push_front(REMOVE, strdup("cookie"));
	ft__list_push_front(REMOVE, strdup("a"));
	
	tmp = *REMOVE;
	while (tmp) {
		printf("tmp: %p\ntmp->data: %p\ntmp->data: %s\ntmp->next: %p\n", tmp, tmp->data, (char*)tmp->data, tmp->next);
		tmp = tmp->next;
	}
	void * ptr = ft__list_remove_if(REMOVE, "a", strcmp, free);
	// printf("\n%p\n\n", ptr);
	// printf("\n%s\n", (char*)ptr);
	// printf("%p\n", ptr);
	// printf("%s\n", ptr);
	printf("\n\n\n\n");
	tmp = *REMOVE;
	while (tmp) {
		printf("tmp: %p\ntmp->data: %p\ntmp->data: %s\ntmp->next: %p\n", tmp, tmp->data, (char*)tmp->data, tmp->next);
		tmp = tmp->next;
	}
	printf("\n");
	// ft__list_remove_if(REMOVE, "a", strcmp, free);
	// free(*REMOVE);
	// printf("\n");
	// tmp = a;
	// while (tmp) {
	// 	printf("tmp: %p\ntmp->data: %p\ntmp->data: %s\ntmp->next: %p\n", tmp, tmp->data, (char*)tmp->data, tmp->next);
	// 	tmp = tmp->next;
	// }
	// printf("\n");
	// t_list	*next;
	// tmp = *REMOVE;
	// while (tmp) {
	// 	next = tmp->next;
	// 	free(tmp);
	// 	tmp = next;
	// }
}

