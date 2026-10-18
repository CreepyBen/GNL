/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:13:32 by ben               #+#    #+#             */
/*   Updated: 2026/10/18 15:11:47 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append(char *stash, char *buf)
{
	char	*temp;

	temp = str_join(stash, buf);
	free(stash);
	return (temp);
}

char	*fill_stash(int fd, char *stash)
{
	char	*buf;
	int		bytes_read;
	char	*temp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (str_index(stash, '\n') == -1 && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		stash = append(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*extract_line(char *stash)
{
	int		i;
	int		pos;
	char	*str;

	if (!stash || stash[0] == '\0')
		return (NULL);
	pos = str_index(stash, '\n');
	if (pos == -1)
		str = malloc(str_len(stash) + 1);
	else
		str = malloc(pos + 2);
	if (!str)
		return (NULL);
	return (copy_line(str, stash, pos));
}

char	*update_stash(char *stash)
{
	int		i;
	int		pos;
	char	*str;

	pos = str_index(stash, '\n');
	if (pos == -1)
	{
		free(stash);
		return (NULL);
	}
	str = malloc(str_len(stash) - pos);
	i = 0;
	pos++;
	while (pos < str_len(stash))
	{
		str[i] = stash[pos];
		i++;
		pos++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char *temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	temp = update_stash(stash);
	free(stash);
	stash = temp;
	return (line);
}
