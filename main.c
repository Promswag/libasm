/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:48:39 by gbaumgar          #+#    #+#             */
/*   Updated: 2024/04/15 14:26:24 by gbaumgar         ###   ########.fr       */
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
	
void	test_ft_strlen(void) {
	char *src[] = {
		"Ceci",
		"Est",
		"Un",
		"Test",
		";)",
		"Je suis une mite en pull-over, le WQT est un animal aquatique nocture",
		0,
	};
	
	char *s = "ft_STRLEN";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
	
	int i = -1;
	while (src[++i]) {
		printf("%s\n", src[i]);
		printf("%lu | C-strlen\n", strlen(src[i]));
		printf("%lu | ASM-ft_strlen\n", ft_strlen(src[i]));
		printf("\n");
	}
}

void	test_ft_strcpy(void) {
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
	char	ft_dest[100];
	
	char *s = "ft_STRCPY";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
	
	int i = -1;
	while (src[++i]) {
		strcpy(dest, src[i]);
		ft_strcpy(ft_dest, src[i]);
		printf("%s\n", src[i]);
		printf("%s | C-strcpy\n", dest);
		printf("%s | ASM-ft_strcpy\n", ft_dest);
		printf("\n");
	}
	
}

void	test_ft_strcmp(void) {
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
	
	char *s = "ft_STRCMP";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
	
	int i = -1;
	while (*src[++i]) {
		printf("%14s %25s | %4i | %-25s\n", "ASM-ft_strcmp", src[i][0], ft_strcmp(src[i][0], src[i][1]), src[i][1]);
		printf("%14s %25s | %4i | %-25s\n", "C-strcmp", src[i][0], strcmp(src[i][0], src[i][1]), src[i][1]);
	}
}

void	test_ft_write(void) {
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
	char *s = "ft_WRITE";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
		
	int ret_write, ret_ft_write;
	int i = -1;
	while (++i * sizeof(t_data) < sizeof(src)) {
		ret_ft_write = ft_write((src[i].fd), src[i].str, ft_strlen(src[i].str));
		if (ret_ft_write == -1)
			printf("%s\n", strerror(errno));
		errno = 0;
		ret_write = write((src[i].fd), src[i].str, ft_strlen(src[i].str));
		if (ret_write == -1)
			printf("%s\n", strerror(errno));
		printf("write: %5d | %-5d :ft_write\n", ret_write, ret_ft_write);
	}
	close(fd);
	close(fd2);
	close(fd3);
}

void	test_ft_read(void) {
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
	
	char *s = "ft_READ";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
	
	int	ret_read = 0, ret_ft_read = 0;
	int i = -1;
	while (++i * sizeof(t_data) < sizeof(src)) {
		ret_ft_read = ft_read((src[i].fd) & 15, src[i].str, 99);
		if (ret_ft_read == -1)
			printf("%s\n", strerror(errno));
		else {
			printf("%s\n", src[i].str);
			bzero(src[i].str, ft_strlen(src[i].str));
		}
		errno = 0;
		ret_read = read((src[i].fd) >> 4, src[i].str, 99);
		if (ret_read == -1)
			printf("%s\n", strerror(errno));
		else {
			printf("%s\n", src[i].str);
			bzero(src[i].str, ft_strlen(src[i].str));
		}
		errno = 0;
		printf("read: %5d | %-5d :ft_read\n", ret_read, ret_ft_read);
	}
	close(fd);
	close(fdr);
	close(fd2);
	close(fdr2);
	close(fd3);
	close(fdr3);
}
	

void	test_ft_strdup(void) {
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
	char	*ft_dest;
	
	char *s = "ft_STRDUP";
	printf("\n-------%*s%*s-------\n\n", (int)(20 + strlen(s) / 2), s, (int)(20 - strlen(s) / 2), "");
	
	int i = -1;
	while (src[++i]) {
		dest = strdup(src[i]);
		ft_dest = ft_strdup(src[i]);
		printf("%s\n%s | C-strdup\n%s | ASM-ft_strdup\n\n", src[i], dest, ft_dest);
		bzero(dest, ft_strlen(dest));
		bzero(ft_dest, ft_strlen(ft_dest));
		free(dest);
		free(ft_dest);
	}
}

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	test_ft_write();
	test_ft_read();
	test_ft_strdup();
}

