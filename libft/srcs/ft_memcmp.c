/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjose-fr <gjose-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:45:12 by gjose-fr          #+#    #+#             */
/*   Updated: 2025/06/09 14:31:39 by gjose-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*conv1;
	unsigned char	*conv2;
	size_t			i;

	conv1 = (unsigned char *)s1;
	conv2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (conv1[i] != conv2[i])
			return (conv1[i] - conv2[i]);
		i++;
	}
	return (0);
}
