/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:06:04 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/09 14:31:39 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strptr;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!strptr)
		return (NULL);
	ft_strlcpy(strptr, s1, s1_len + 1);
	ft_strlcat(strptr, s2, s1_len + s2_len + 1);
	return (strptr);
}
