/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:06:21 by jazarago          #+#    #+#             */
/*   Updated: 2023/12/02 18:58:29 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	index;
	size_t	i;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	joined = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!joined)
		return (free_the_saved(s1));
	index = 0;
	i = 0;
	while (s1[i] != '\0')
		joined[index++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		joined[index++] = s2[i++];
	joined[index] = '\0';
	free(s1);
	return (joined);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	find;
	int				i;

	find = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (0);
}

char	*free_the_saved(char	*saved)
{
	if (saved)
		free (saved);
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	char	*rtn;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	rtn = malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (NULL);
	while (s1[i])
	{
		rtn[i] = s1[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
