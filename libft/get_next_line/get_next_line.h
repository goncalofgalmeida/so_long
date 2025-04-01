/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:07:20 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/04/01 15:31:40 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>

void	*ft_calloc_gnl(size_t nmemb, size_t size);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strdup_gnl(const char *s);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif