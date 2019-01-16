/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:43:47 by erli              #+#    #+#             */
/*   Updated: 2019/01/16 16:11:23 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static	int			add_to_line(char **line, char *str_add, char **hist, int f)
{
	char *old;

	if (f == 1)
	{
		if (!(*line = ft_strdup(*hist)))
			return (-1);
	}
	if (str_add[0] != '\0')
	{
		old = *line;
		if (!(*line = ft_strjoin(*line, str_add)))
		{
			free(old);
			return (-1);
		}
		free(old);
	}
	return (1);
}

static	int			read_line(const int fd, char **line, char **old, char *buf)
{
	int		ret;
	char	str_add[BUFF_SIZE + 1];
	int		first_read;

	ret = BUFF_SIZE;
	first_read = 1;
	while (ft_strchr(buf, 10) == NULL && ret == BUFF_SIZE)
	{
		ft_bzero(buf, BUFF_SIZE + 1);
		ft_bzero(str_add, BUFF_SIZE + 1);
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == 0 && first_read == 1 && (*old)[0] == '\0')
			return (0);
		ft_strncpy(str_add, buf, ft_char_at_pos('\n', buf) + 1);
		if (!(add_to_line(line, str_add, old, first_read)))
			return (-1);
		first_read = 0;
	}
	if (ft_strchr(buf, 10) != NULL)
		buf = ft_strncpy(buf, ft_strchr(buf, 10) + 1, BUFF_SIZE);
	else if (ft_strchr(buf, 0) != buf + BUFF_SIZE)
		ft_bzero(buf, BUFF_SIZE + 1);
	*old = ft_strncpy(*old, buf, BUFF_SIZE + 1);
	return (1);
}

int					ps_next_line(const int fd, char **line)
{
	static	char	*old = NULL;
	char			buf[BUFF_SIZE + 1];
	int				read_out;

	if (old == NULL)
		old = ft_strnew(BUFF_SIZE + 1);
	if (line == 0 || read(fd, buf, 0) == -1)
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (ft_strchr(old, 10) != NULL)
	{
		ft_strncpy(buf, old, ft_char_at_pos('\n', old) + 1);
		old = ft_strncpy(old, ft_strchr(old, 10) + 1, BUFF_SIZE);
		if (!(*line = ft_strdup(buf)))
			return (-1);
	}
	else if (!(read_out = read_line(fd, line, &old, buf)))
		return (0);
	else if (read_out == -1)
		return (-1);
	return (1);
}
