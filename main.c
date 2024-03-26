/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:48:39 by gbaumgar          #+#    #+#             */
/*   Updated: 2024/03/26 17:16:16 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	
	char *ft__strlen_test[] = {
		// "Lana",
		// "Je t'aime",
		// "Un peu",
		// "Beaucoup",
		// "Passionement",
		// "A la folie",
		0,
	};
	
	int i = -1;
	while (ft__strlen_test[++i]) {
		printf("%15s | C-strlen %4lu | ASM-ft__strlen %4lu\n",
			   ft__strlen_test[i],
			   strlen(ft__strlen_test[i]),
			   ft__strlen(ft__strlen_test[i]));
	}
	
	
	
	// char *ft__strcpy_test[] = {
	// 	"a",
	// 	"ab",
	// 	"abc",
	// 	"abcd",
	// 	"abcde",
	// 	0
	// }
	
	// char *ft_strcpy_dest[5][10];
	
	// int i = -1;
	// while (ft__strcpy_test[++i]) {
	// 	printf("%15s | C-strlen %4lu | ASM-ft__strlen %4lu\n",
	// 		ft__strcpy_test[i],
	// 		strcpy(ft__strcpy_test[i]),
	// 		ft__strcpy(ft__strcpy_test[i]));
	// }
	
	char p[] = "Bonjour";
	char p2[] = "p";
	char p3[] = "AAAAA";
	char p4[] = "xDxDxD";
	char t[8];
	char t2[8];
	char t3[8];
	char t4[8];
	
	printf("%15s\n", ft__strcpy(t, p));
	printf("%15s\n", ft__strcpy(t2, p2));
	printf("%15s\n", ft__strcpy(t3, p3));
	printf("%15s\n", ft__strcpy(t4, p4));
	// printf("%15s\n", strcpy(t, p));
	
	
	printf("%15i\n", ft__strcmp("a", "a"));
	printf("%15i\n", ft__strcmp("a", "b"));
	printf("%15i\n", ft__strcmp("b", "a"));
	printf("%15i\n", ft__strcmp("aa", "a"));
	printf("%15i\n", ft__strcmp("aa", "aa"));
	printf("%15i\n", ft__strcmp("a", "aa"));
	printf("%15i\n", ft__strcmp("", "Test"));
	printf("\n\n");
	printf("%15i\n", strcmp("a", "a"));
	printf("%15i\n", strcmp("a", "b"));
	printf("%15i\n", strcmp("b", "a"));
	printf("%15i\n", strcmp("aa", "a"));
	printf("%15i\n", strcmp("aa", "aa"));
	printf("%15i\n", strcmp("a", "aa"));
	printf("%15i\n", strcmp("", "Test"));
}
