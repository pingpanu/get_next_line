/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:55:21 by user              #+#    #+#             */
/*   Updated: 2022/03/21 23:07:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

char    *get_next_line(int fd);
char    *ft_readfile(int fd, char *str);
char    *ft_getline(char *s);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strchr(char *s, int c);
char    *remove_prev_line(char *s);
size_t  ft_strlen(char *s);
#endif
