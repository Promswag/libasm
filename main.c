/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:48:39 by gbaumgar          #+#    #+#             */
/*   Updated: 2024/03/21 18:39:01 by gbaumgar         ###   ########.fr       */
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
		"Lana",
		"Je t'aime",
		"Un peu",
		"Beaucoup",
		"A la folie",
		0,
	};
	
	int i = -1;
	while (ft__strlen_test[++i]) {
		printf("% 15s | C-strlen % 4lu | ASM-ft__strlen % 4lu\n",
			   ft__strlen_test[i],
			   strlen(ft__strlen_test[i]),
			   ft__strlen(ft__strlen_test[i]));
	}
}
