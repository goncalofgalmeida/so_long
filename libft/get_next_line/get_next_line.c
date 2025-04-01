/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:06:45 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/04/01 15:33:00 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_line_gnl(char *stash, char *line)
{
	int	i;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = (char *)ft_calloc_gnl((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_update_stash_gnl(char *stash, char *buf)
{
	char	*updated_stash;

	if (!stash)
		return (ft_strdup_gnl(buf));
	if (!buf || buf[0] == '\0')
		return (stash);
	updated_stash = ft_strjoin_gnl(stash, buf);
	free(stash);
	return (updated_stash);
}

char	*ft_clear_stash_gnl(char *stash)
{
	char	*nl_position;
	char	*new_stash;

	if (!stash)
		return (NULL);
	nl_position = ft_strchr_gnl(stash, '\n');
	if (!nl_position || *(nl_position + 1) == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup_gnl(nl_position + 1);
	free(stash);
	return (new_stash);
}

char	*read_line_gnl(int fd, char *stash)
{
	char	*buf;
	int		c_read;

	buf = (char *) ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	c_read = 1;
	while (c_read > 0)
	{
		c_read = read(fd, buf, BUFFER_SIZE);
		if (c_read < 0)
		{
			free(buf);
			return (NULL);
		}
		if (c_read == 0)
			break ;
		buf[c_read] = '\0';
		stash = ft_update_stash_gnl(stash, buf);
		if (ft_strchr_gnl(stash, '\n'))
			break ;
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line_gnl(fd, stash);
	if (!stash || *stash == '\0')
	{
		free(stash);
		return (NULL);
	}
	line = NULL;
	line = ft_fill_line_gnl(stash, line);
	stash = ft_clear_stash_gnl(stash);
	return (line);
}

/* int	main(void)
{
	int 	fd = open("test.txt", O_RDONLY);
	char 	*line;

	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
} */
