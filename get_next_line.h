/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazarago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:12:10 by jazarago          #+#    #+#             */
/*   Updated: 2023/12/02 18:58:57 by jazarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_saving_and_reading(int fd, char	*save);
char	*read_from_saved(char	*saved);
char	*save_update(char	*saved);
char	*get_next_line(int fd);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*free_the_saved(char	*saved);
char	*ft_strdup(char *s1);

size_t	ft_strlen(const char *str);

#endif
