/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:48:39 by gbaumgar          #+#    #+#             */
/*   Updated: 2024/03/27 18:53:57 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>


void	test_ft__strlen(void) {
	char *src[] = {
		"Lana",
		"Je t'aime",
		"Un peu",
		"Beaucoup",
		"Passionement",
		"A la folie",
		0,
	};
	
	int i = -1;
	while (src[++i]) {
		printf("%s\n%lu | C-strlen\n%lu | ASM-ft__strlen\n\n", src[i], strlen(src[i]), ft__strlen(src[i]));
	}
}

void	test_ft__strcpy(void) {
	char *src[] = {
		"Lana",
		"Je t'aime",
		"Un peu",
		"Beaucoup",
		"Passionement",
		"A la folie",
		0,
	};
	char	dest[50];
	char	ft__dest[50];
	
	int i = -1;
	while (src[++i]) {
		strcpy(dest, src[i]);
		ft__strcpy(ft__dest, src[i]);
		printf("%s\n%s | C-strcpy\n%s | ASM-ft__strcpy\n\n", src[i], dest, ft__dest);
	}
	
}

void	test_ft__strcmp(void) {
	char *src[][2] = {
		{"a", "a"},
		{"a", "b"},
		{"b", "a"},
		{"'", " "},
		{"Very", "Good"},
		{"0", "9"},
		{"9", "0"},
		{"0", "0"},
		{"kjgklwjgkwjkkge", "kjgklwjgkwjkkge"},
		{"", ""}, 
		{"'   '", "'   '"}, 
		{"'   '", "' '"}, 
		{0}
	};
	
	int i = -1;
	while (*src[++i]) {
		printf("%14s %25s | %4i | %-25s\n", "ASM-ft__strcmp", src[i][0], ft__strcmp(src[i][0], src[i][1]), src[i][1]);
		printf("%14s %25s | %4i | %-25s\n", "C-strcmp", src[i][0], strcmp(src[i][0], src[i][1]), src[i][1]);
	}
}

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	
	test_ft__strlen();
	test_ft__strcpy();
	test_ft__strcmp();
	
	// ft__write(1, "\n", 1);
	
	// printf("%15li\n", ft__write(5, "xD", 0));
	// printf("%15li\n", write(5, "xD", 0));
	// ft__write(1, "\n", 1);
	
	// printf("%15li\n", ft__write(5, "xD", 1));
	// printf("%15li\n", write(5, "xD", 1));
	// ft__write(1, "\n", 1);
	
	// printf("%15li\n", ft__write(5, "xD", 2));
	// printf("%15li\n", write(5, "xD", 2));
	// ft__write(1, "\n", 1);
	
	// printf("%15li\n", ft__write(5, "xD", 3));
	// printf("%15li\n", write(5, "xD", 3));
	// ft__write(1, "\n", 1);
	
	// printf("%15li\n", ft__write(1, "xD", 4));
	// printf("%15li\n", ft__write(1, "xD", 50));
	
	// int fd;
	// char buffer[500];
	// bzero(buffer, sizeof(buffer));
	
	// fd = open("test_file", O_RDONLY);
	// printf("%5li", ft__read(fd, buffer, 500));
	// ft__write(1, buffer, ft__strlen(buffer));
	// bzero(buffer, sizeof(buffer));
	// ft__write(1, "\n", 1);
	// close(fd);
	
	// fd = open("test_file", O_RDONLY);
	// printf("%5li", read(fd, buffer, 500));
	// write(1, buffer, strlen(buffer));
	// bzero(buffer, sizeof(buffer));
	// ft__write(1, "\n", 1);
	// close(fd);
	
	// printf("%5li", ft__read(10, buffer, 500));
	// ft__write(1, buffer, ft__strlen(buffer));
	// bzero(buffer, sizeof(buffer));
	// ft__write(1, "\n", 1);
	
	// printf("%5li", read(10, buffer, 500));
	// write(1, buffer, strlen(buffer));
	// bzero(buffer, sizeof(buffer));
	// ft__write(1, "\n", 1);
	// ft__write(1, "\n", 1);
	// ft__write(1, "\n", 1);
	// ft__write(1, "\n", 1);
	
	
	// printf("%15s", ft__strdup("Prout\n"));
	// printf("%15s", ft__strdup("Prout\n"));
	// printf("%15s", ft__strdup("Prout\n"));
	
	// free(ft__strdup("LALALA"));
	
	// char *str;
	
	// str = malloc(1);
	// *str = 0;
	// ft__write(1, str, ft__strlen(str));
	// bzero(str, ft__strlen(str));
	// free(str);
	
	// str = strdup("Cactus");
	// ft__write(1, str, ft__strlen(str));
	// bzero(str, ft__strlen(str));
	// free(str);
	
	// char lalala[8];
	// lalala[0] = 'A';
	// lalala[1] = 'r';
	// lalala[2] = 'd';
	// lalala[3] = 'o';
	// lalala[4] = 'i';
	// lalala[5] = 's';
	// lalala[6] = 'e';
	// lalala[7] = '\n';
	// printf("%15li", ft__strlen(lalala));
	// str = ft__strdup(lalala);
	// bzero(lalala, ft__strlen(lalala));
	// ft__write(1, str, ft__strlen(str));
	// bzero(str, ft__strlen(str));
	// free(str);
}
