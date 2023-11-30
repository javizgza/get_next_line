/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:40:56 by jazarago          #+#    #+#             */
/*   Updated: 2023/11/30 14:05:56 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_next_line1(int	i)
{
	static char	*buffer;
	char		*line;

	buffer = read_file(i, buffer);
	line = save_first_line(buffer);
	buffer = delete_line(buffer);
	return (line);
}

char	*get_next_line2(int i)
{
	char		*line;
	static char	*buffer;

	buffer = read_file(i, buffer);
	if (!buffer)
		return (NULL);
	line = save_first_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = delete_line(buffer);
	if (!buffer)
		return (NULL);

	return (line);
}

char	*get_next_line3(int i)
{
	char		*line;
	static char	*buffer;

	if (does_exist(buffer, '\n'));
	{
		line = save_first_line(buffer);
		buffer = delete_line(buffer);
		return (line);
	}
	buffer = read_file(i, buffer);
	if (!buffer)
		return (NULL);
	line = save_first_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = delete_line(buffer);
	if (!buffer)
		return (NULL);
	return (line);
}
