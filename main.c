/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:48:39 by gbaumgar          #+#    #+#             */
/*   Updated: 2024/04/12 14:31:49 by gbaumgar         ###   ########.fr       */
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
#include <errno.h>

typedef struct data {
	int		fd;
	char	*str;
} t_data; 
	
void	test_ft__strlen(void) {
	char *src[] = {
		"Ceci",
		"Est",
		"Un",
		"Test",
		";)",
		"Je suis une mite en pull-over, le WQT est un animal aquatique nocture",
		0,
	};
	
	char *s = "FT__STRLEN";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
	
	int i = -1;
	while (src[++i]) {
		printf("%s\n", src[i]);
		printf("%lu | C-strlen\n", strlen(src[i]));
		printf("%lu | ASM-ft__strlen\n", ft__strlen(src[i]));
		printf("\n");
	}
}

void	test_ft__strcpy(void) {
	char *src[] = {
		"est-ce théière copine?",
		"Inchalatte",
		"0",
		"9876543210",
		"",
		"'e'e'e'''e'f'e'f'r'fer'fre'g'g'reg're'ger'gre'ger'g'erg'gre'rge'gre'g'erg'reh'tr'h'trhtrh''",
		0,
	};
	char	dest[100];
	char	ft__dest[100];
	
	char *s = "FT__STRCPY";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
	
	int i = -1;
	while (src[++i]) {
		strcpy(dest, src[i]);
		ft__strcpy(ft__dest, src[i]);
		printf("%s\n", src[i]);
		printf("%s | C-strcpy\n", dest);
		printf("%s | ASM-ft__strcpy\n", ft__dest);
		printf("\n");
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
	
	char *s = "FT__STRCMP";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
	
	int i = -1;
	while (*src[++i]) {
		printf("%14s %25s | %4i | %-25s\n", "ASM-ft__strcmp", src[i][0], ft__strcmp(src[i][0], src[i][1]), src[i][1]);
		printf("%14s %25s | %4i | %-25s\n", "C-strcmp", src[i][0], strcmp(src[i][0], src[i][1]), src[i][1]);
	}
}

void	test_ft__write(void) {
	int fd = open("test_file", O_WRONLY | O_CREAT, 0700);
	int fd2 = open("test_file2", O_RDWR | O_CREAT, 0700);
	int fd3 = open("test_file3", O_RDONLY | O_CREAT, 0700);
	t_data src[] = {
		{fd, "Poney\n"},
		{fd, "XD"},
		{fd, "\n"},
		{fd, ""},
		{fd2, "Poney\n"},
		{fd2, "XD"},
		{fd2, "\n"},
		{fd2, ""},
		{10, "INVALID FD"},
		{fd3, "WRONG FLAGS"},
	};
	printf("%lu\n", sizeof(t_data));
	char *s = "FT__WRITE";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
		
	int ret_write, ret_ft__write;
	int i = -1;
	while (++i * sizeof(t_data) < sizeof(src)) {
		ret_ft__write = ft__write((src[i].fd), src[i].str, ft__strlen(src[i].str));
		if (ret_ft__write == -1)
			printf("%s\n", strerror(errno));
		errno = 0;
		ret_write = write((src[i].fd), src[i].str, ft__strlen(src[i].str));
		if (ret_write == -1)
			printf("%s\n", strerror(errno));
		printf("write: %5d | %-5d :ft__write\n", ret_write, ret_ft__write);
	}
	close(fd);
	close(fd2);
	close(fd3);
}

void	test_ft__read(void) {
	int fd = open("test_file", O_RDONLY | O_CREAT, 0700);
	int fdr = open("test_file", O_RDONLY | O_CREAT, 0700);
	int fd2 = open("test_file2", O_RDWR | O_CREAT, 0700);
	int fdr2 = open("test_file2", O_RDWR | O_CREAT, 0700);
	int fd3 = open("test_file3", O_WRONLY | O_CREAT, 0700);
	int fdr3 = open("test_file3", O_WRONLY | O_CREAT, 0700);
	char	small[10];
	char	med[30];
	char	big[100];
	bzero(small, sizeof(small));
	bzero(med, sizeof(med));
	bzero(big, sizeof(big));
	t_data src[] = {
		{fd | fdr << 4, small},
		{fd | fdr << 4, med},
		{fd | fdr << 4, big},
		{fd | fdr << 4, small},
		{fd2 | fdr2 << 4, med},
		{fd2 | fdr2 << 4, big},
		{fd2 | fdr2 << 4, small},
		{fd2 | fdr2 << 4, med},
		{10 | 10 << 4, big},
		{fd3 | fdr3 << 4, small},
	};
	
	char *s = "FT__READ";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
	
	int	ret_read = 0, ret_ft__read = 0;
	int i = -1;
	while (++i * sizeof(t_data) < sizeof(src)) {
		ret_ft__read = ft__read((src[i].fd) & 15, src[i].str, 99);
		if (ret_ft__read == -1)
			printf("%s\n", strerror(errno));
		else {
			printf("%s\n", src[i].str);
			bzero(src[i].str, ft__strlen(src[i].str));
		}
		errno = 0;
		ret_read = read((src[i].fd) >> 4, src[i].str, 99);
		if (ret_read == -1)
			printf("%s\n", strerror(errno));
		else {
			printf("%s\n", src[i].str);
			bzero(src[i].str, ft__strlen(src[i].str));
		}
		errno = 0;
		printf("read: %5d | %-5d :ft__read\n", ret_read, ret_ft__read);
	}
	close(fd);
	close(fdr);
	close(fd2);
	close(fdr2);
	close(fd3);
	close(fdr3);
}
	

void	test_ft__strdup(void) {
	char *src[] = {
		"xd",
		"pomme",
		"POMME",
		"poire",
		"HAHAHAHAHHAHAHA",
		"42",
		"",
		0,
	};
	char	*dest;
	char	*ft__dest;
	
	char *s = "FT__STRDUP";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
	
	int i = -1;
	while (src[++i]) {
		dest = strdup(src[i]);
		ft__dest = ft__strdup(src[i]);
		printf("%s\n%s | C-strdup\n%s | ASM-ft__strdup\n\n", src[i], dest, ft__dest);
		bzero(dest, ft__strlen(dest));
		bzero(ft__dest, ft__strlen(ft__dest));
		free(dest);
		free(ft__dest);
	}
}

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	
	test_ft__strlen();
	test_ft__strcpy();
	test_ft__strcmp();
	test_ft__write();
	test_ft__read();
	test_ft__strdup();

}

