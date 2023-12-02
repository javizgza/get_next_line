/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:59:20 by jazarago          #+#    #+#             */
/*   Updated: 2023/12/02 18:54:49 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_saving_and_reading(int fd, char *saved)
{
	char	*buff;
	int		count_bytes;

	buff = malloc(BUFFER_SIZE + 1) * sizeof(char);
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
		buff[count_bytes] = '\0';
		saved = ft_strjoin(saved, buff);
	}
	free(buff);
	return (saved);
}

char	*read_from_saved(char *saved)
{
	int		i;
	char	*lines_saved;

	i = 0;
	if (saved[i] == '\0' || !saved)
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	lines_saved = malloc((i + 1) * sizeof(char));
	if (!lines_saved)
		return (free_the_saved(saved));
	while (saved[i] && saved[i] != '\n')
	{
		lines_saved[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
	{
		lines_saved[i] = saved[i];
		i++;
	}
	lines_saved = '\0';
	return (lines_saved);
}

char	*save_update(char *saved)
{
	int		i;
	int		search;
	char	*up_to_date;

	search = 0;
	while (saved[search] && saved[search] != '\n')
		search++;
	if (saved[search] == '\0')
		return (free_the_saved(saved));
	up_to_date = malloc((ft_strlen(saved) - search + 1));
	if (!up_to_date)
		return (free_the_saved(saved));
	search = 0;
	while (saved[search])
		up_to_date[i++] = saved[search++];
	up_to_date = '\0';
	free(saved);
	return (up_to_date);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_saving_and_reading(fd, save);
	if (!save)
		return (NULL);
	line = read_from_saved(save);
	save = save_update(save);
	return (line);
}
