/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:06:07 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/04/01 15:20:06 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*p;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strptr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	strptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!strptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		strptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		strptr[i] = s2[j];
		i++;
		j++;
	}
	strptr[i] = '\0';
	return (strptr);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
 */