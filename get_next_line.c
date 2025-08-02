/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hkhoshne <hkhoshne@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/15 09:59:23 by hkhoshne      #+#    #+#                 */
/*   Updated: 2025/07/27 15:06:29 by hkhoshne      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_file(int fd, char *buffer)
{
	char	*new_buffer;
	int		bytes;

	new_buffer = malloc(BUFFER_SIZE + 1);
	if (!new_buffer)
		return (free(buffer), NULL);
	while (1)
	{
		bytes = read(fd, new_buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(new_buffer), free(buffer), NULL);
		if (bytes == 0)
			break ;
		new_buffer[bytes] = '\0';
		buffer = ft_strjoin_and_free_first(buffer, new_buffer);
		if (!buffer)
			return (free(new_buffer), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(new_buffer);
	return (buffer);
}

static char	*ft_get_line(char *buffer)
{
	int		len;
	char	*line;

	if (!*buffer)
		return (NULL);
	if (ft_strchr(buffer, '\n'))
		len = ft_strchr(buffer, '\n') - buffer + 1;
	else
		len = ft_strlen(buffer);
	line = ft_strndup(buffer, len);
	return (line);
}

static char	*ft_set_buffer(char *buffer)
{
	char	*new_buf;
	char	*newline_ptr;

	newline_ptr = ft_strchr(buffer, '\n');
	if (!newline_ptr)
	{
		free(buffer);
		return (NULL);
	}
	newline_ptr++;
	new_buf = ft_strndup(newline_ptr, ft_strlen(newline_ptr));
	free(buffer);
	return (new_buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_set_buffer(buffer);
	return (line);
}
