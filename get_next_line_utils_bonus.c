/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:25:07 by pingpanu          #+#    #+#             */
/*   Updated: 2022/03/21 23:08:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t  count;

    count = 0;
    while (str[count] != '\0')
        count++;
    return (count);
}

char    *ft_strchr(const char *s, int c)
{
    size_t          i;

    if (!s)
        return (NULL);
    i = 0;
    while (s[i])
    {
        if (i == (char)c)
            return ((char *)&s);
        i++;
    }
    return (NULL);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *join;
    size_t  i;
    size_t  j;

    if (!s1)
    {
        s1 = (char *)malloc(sizeof(char) * 1);
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    join = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!join)
        return (NULL);
    i = -1;
    j = 0;
    if (s1)
        while (s1[++i])
            join[i] = s1[i];
    while (s2[j])
        join[i++] = s2[j++];
    join[ft_strlen(s1) + ft_strlen(s2)] = '\0';
    free (s1);
    return (join);
}