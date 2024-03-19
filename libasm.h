/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:48:45 by gbaumgar          #+#    #+#             */
/*   Updated: 2024/03/19 17:56:45 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

size_t	ft__strlen(const char *s);
char	*ft__strcpy(char *dest, const char *src);
int		ft__strcmp(const char *s1, const char *s2);
ssize_t	ft__write(int fd, const void *buf, size_t count);
ssize_t	ft__read(int fd, void *buf, size_t count);
char	*ft__strdup(const char *s);

#endif