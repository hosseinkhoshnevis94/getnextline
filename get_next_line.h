/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hkhoshne <hkhoshne@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/15 09:59:44 by hkhoshne      #+#    #+#                 */
/*   Updated: 2025/07/27 15:09:09 by hkhoshne      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *s, char c);
int		ft_strlen(const char *s);
char	*ft_strjoin_and_free_first(char *s1, char *s2);
char	*ft_strndup(const char *s, size_t n);

#endif
