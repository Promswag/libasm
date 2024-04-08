/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:20:44 by gbaumgar          #+#    #+#             */
/*   Updated: 2024/04/08 15:30:05 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

#include <unistd.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;


size_t	ft__strlen(const char *s);
char	*ft__strcpy(char *dest, const char *src);
int		ft__strcmp(const char *s1, const char *s2);
ssize_t	ft__write(int fd, const void *buf, size_t count);
ssize_t	ft__read(int fd, void *buf, size_t count);
char	*ft__strdup(const char *s);

int		ft__atoi_base(char *str, char *base);
void	ft__list_push_front(t_list **begin_list, void *data);
int		ft__list_size(t_list *begin_list);
void	ft__list_sort(t_list *begin_list, int (*cmp)());
void	ft__list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));


#endif