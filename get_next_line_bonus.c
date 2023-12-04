/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:07:54 by jazarago          #+#    #+#             */
/*   Updated: 2023/12/04 15:30:40 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_saving_and_reading(int fd, char *saved)
{
	char	*buff;
	int		count_bytes;

	if (!saved)
	{
		saved = ft_strdup("");
		if (!saved)
			return (NULL);
	}
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free_the_saved(saved));
	count_bytes = 1;
	while (!ft_strchr(saved, '\n') && count_bytes != 0)
	{
		count_bytes = read(fd, buff, BUFFER_SIZE);
		if (count_bytes == -1)
		{
			free(buff);
			return (free_the_saved(saved));
		}
		if (count_bytes > 0)
		{
			buff[count_bytes] = '\0';
			saved = ft_strjoin(saved, buff);
		}
	}
	free(buff);
	return (saved);
}

char	*read_from_saved(char *saved)
{
	int		i;
	int		len;
	char	*lines_saved;

	i = 0;
	len = 1;
	if (!saved || saved[i] == '\0')
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		len++;
	lines_saved = malloc((i + len) * sizeof(char));
	if (!lines_saved)
		return (free_the_saved(saved));
	i = -1;
	while (saved[++i] && saved[i] != '\n')
		lines_saved[i] = saved[i];
	if (saved[i] == '\n')
	{
		lines_saved[i] = saved[i];
		i++;
	}
	lines_saved[i] = '\0';
	return (lines_saved);
}

char	*save_update(char *saved)
{
	int		search;
	char	*up_to_date;

	if (!saved)
		return (NULL);
	search = 0;
	while (saved[search] && saved[search] != '\n')
		search++;
	if (saved[search] == '\0')
	{
		free(saved);
		return (NULL);
	}
	up_to_date = ft_strdup(saved + search + 1);
	free(saved);
	return (up_to_date);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (save[fd])
			free(save);
		return (NULL);
	}
	save[fd] = ft_saving_and_reading(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = read_from_saved(save[fd]);
	save[fd] = save_update(save[fd]);
	return (line);
}
