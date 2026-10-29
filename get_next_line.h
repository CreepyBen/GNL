/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 13:43:18 by ben               #+#    #+#             */
/*   Updated: 2026/10/18 15:39:27 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int		str_len(const char *s);
char	*get_next_line(int fd);
int		str_index(const char *s, int c);
char	*str_join(char *s1, char *s2);
char	*extract(const char *s, unsigned int start, size_t len);
char	*copy_line(char *str, char *stash, int pos);
char	*append(char *stash, char *buf);
char	*fill_stash(int fd, char *stash);
char	*extract_line(char *stash);
char	*update_stash(char *stash);

#endif