/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:16:32 by pingpanu          #+#    #+#             */
/*   Updated: 2022/03/21 23:05:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_getline(char *s)
{
    char    *line;
    int         i;

    i = 0;
    if (!s[i])
        return (NULL);
    while (s[i] && s[i] != '\n')
        i++;
    if (s[i] == '\n')
        i++;
    line = (char *)malloc((i + 1) * sizeof(char));
    if (!line)
        return (NULL);
    i = 0;
    while (s[i] && s[i] != '\n')
    {
        line[i] = s[i];
        i++;
    }
    if (s[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char    *remove_prev_line(char *str)
{
    char    *removed;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!str[i])
    {
        free(str);
        return (NULL);
    }
    removed = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
    if (!removed)
        return (NULL);
    i++;
    while (str[i])
        removed[j++] = str[i++];
    removed[j] = '\0';
    free(str);
    return (removed);
}

char    *ft_readfile(int fd, char *str)
{
    char    *buf;
    int         rd;

    buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buf)
        return (NULL);
    rd = 1;
    while ((!ft_strchr(str,'\n')) && rd != 0)
    {
        rd = read(fd, buf, BUFFER_SIZE);
        if (rd == -1)
        {
            free(buf);
            return (NULL);
        }
        buf[rd] = '\0';
        str = ft_strjoin(str, buf);
    }
    free (buf);
    return (str);
}

char    *get_next_line(int fd)
{
    static char *file;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    file = ft_readfile(fd, file);
    if (!file)
        return (NULL);
    line = ft_getline(file);
    file = remove_prev_line(file);
    return (line);
}