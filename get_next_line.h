/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 13:43:18 by ben               #+#    #+#             */
/*   Updated: 2026/10/16 20:52:07 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef get_next_line_h
# define get_next_line_h

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int		str_len(char *s);
char	*get_next_line(int fd);
int		str_index(const char *s, int c);
char	*str_join(char *s1, char *s2);
char	*extract(const char *s, unsigned int start, size_t len);

#endif