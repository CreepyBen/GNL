/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:54:10 by ben               #+#    #+#             */
/*   Updated: 2026/10/18 16:39:05 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	str_len(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	str_index(const char *s, int c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

char	*str_join(char *s1, char *s2)
{
	int		i;
	char	*sub;

	if (!s1 && !s2)
		return (NULL);
	sub = malloc(str_len(s1) + str_len(s2) + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		sub[i] = s1[i];
		i++;
	}
	while (s2 && *s2)
	{
		sub[i] = *s2;
		i++;
		s2++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*extract(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = str_len(s);
	if (start >= s_len)
		len = 0;
	else if (s_len - start < len)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*copy_line(char *str, char *stash, int pos)
{
	int	i;
	int	len;

	i = 0;
	len = str_len(stash);
	if (pos == -1)
	{
		while (i < len)
		{
			str[i] = stash[i];
			i++;
		}
	}
	else
	{
		while (i <= pos)
		{
			str[i] = stash[i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
