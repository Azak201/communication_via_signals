/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:43:15 by amismail          #+#    #+#             */
/*   Updated: 2024/08/27 17:42:17 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && (i + j) < len)
			{
				if (little[j + 1] == 0)
					return ((char *)big + i);
				j++;
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}
