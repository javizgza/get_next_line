/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:41:39 by jazarago          #+#    #+#             */
/*   Updated: 2023/11/30 15:46:45 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "get_next_line.h"

char	*read_file(int	i, char	*buffer)
{

char	*save_first_line(char	*buffer)
{
	if (!buffer)
		return (NULL);

	int	size;

	size = 0;
	while (buffer[size] != '\0' && buffer[size] != '\n')
	{
		size++;
	}
	char	*line;

	line = (char *)malloc((size + 1) * sizeof(char));
	if (!line)
		return (NULL);
	int	i;

	i = 0;
	while (i < size)
	{
		line[i] = buffer[i];
		i++;
	}
	line[size] = '\0';
	return (line);
}

void	delete_line(char	*buffer)
{
	if (!buffer)
		return  (0);
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			int	j;

			j = i + 1;
			while (buffer[j] != '\0')
			{
				buffer[j - (i + 1)] = buffer[j];
				j++;
			}
			buffer[j - (i + 1)] = '\0';
			return (0);
		}
		i++;
	}
	buffer[0] = '\0';
}

int	does_exist(const char	*str, char	symbol)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == symbol)
			return (1);
		str++;
	}
	return (0);
}
