/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:48:39 by gbaumgar          #+#    #+#             */
/*   Updated: 2024/04/09 18:56:59 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	
	int ret;
	ret = ft__atoi_base("aa", "abcdefg");
	printf("%d\n", ret);
	ret = ft__atoi_base("ii", "abcdefghijkl");
	printf("%d\n", ret);
	ret = ft__atoi_base("q", "abcdefghijklmnopqr");
	printf("%d\n", ret);
	ret = ft__atoi_base("z", "abcdefghijklmnopqrstuvwxyz");
	printf("%d\n", ret);
	ret = ft__atoi_base("   -+-10a0", "0123456789");
	printf("%d\n", ret);
	ret = ft__atoi_base("   -+pomme", "abcdefghijklmnopqrstuvwxyz");
	printf("%d\n", ret);
	ret = ft__atoi_base(" \n\v\t\r\f +-+-+-+-+10000000", "01");
	printf("%d\n", ret);

	t_list	*b = malloc(sizeof(t_list));
	t_list	*a = malloc(sizeof(t_list));
	b->data = "b";
	b->next = 0;
	a->data = "a";
	a->next = b;
	
	ft__list_push_front(&a, "c");
	printf("%s\n", a->data);
}

