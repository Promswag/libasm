/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:48:39 by gbaumgar          #+#    #+#             */
/*   Updated: 2024/04/10 18:23:12 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	
	// int ret;
	// ret = ft__atoi_base("aa", "abcdefg");
	// printf("%d\n", ret);
	// ret = ft__atoi_base("ii", "abcdefghijkl");
	// printf("%d\n", ret);
	// ret = ft__atoi_base("q", "abcdefghijklmnopqr");
	// printf("%d\n", ret);
	// ret = ft__atoi_base("z", "abcdefghijklmnopqrstuvwxyz");
	// printf("%d\n", ret);
	// ret = ft__atoi_base("   -+-10a0", "0123456789");
	// printf("%d\n", ret);
	// ret = ft__atoi_base("   -+pomme", "abcdefghijklmnopqrstuvwxyz");
	// printf("%d\n", ret);
	// ret = ft__atoi_base(" \n\v\t\r\f +-+-+-+-+10000000", "01");
	// printf("%d\n", ret);

	t_list	*a = malloc(sizeof(t_list));
	t_list	*b = malloc(sizeof(t_list));
	a->data = "a";
	a->next = b;
	b->data = "b";
	b->next = 0;
	
	// char	*str = ft__strdup("douze");
	
	t_list	*tmp;
	t_list	*next;
	
	printf("\n");
	printf("A: %p\nA->data: %p\nA->data: %s\nA->next: %p\n", a, a->data, (char*)a->data, a->next);
	printf("B: %p\nB->data: %p\nB->data: %s\nB->next: %p\n", b, b->data, (char*)b->data, b->next);
	printf("\n");
	
	ft__list_push_front(&a, "c");
	// printf("%s\n", (char*)ptr);
	// printf("\n");
	
	printf("\n%p\n", a);
	printf("%s\n", (char*)a->data);
	tmp = a;
	while (tmp) {
		printf("tmp: %p\ntmp->data: %p\ntmp->data: %s\ntmp->next: %p\n", tmp, tmp->data, (char*)tmp->data, tmp->next);
		tmp = tmp->next;
	}
	
	printf("\n");
	tmp = a;
	while (tmp) {
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

