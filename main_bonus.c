/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:48:39 by gbaumgar          #+#    #+#             */
/*   Updated: 2024/04/08 17:54:34 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	
	int ret;
	ret = ft__atoi_base(0, "abcefghj8");
	printf("%d\n", ret);

}

