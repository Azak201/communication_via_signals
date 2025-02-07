/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:22:04 by amismail          #+#    #+#             */
/*   Updated: 2024/08/31 12:24:12 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*x;
	int		i;

	i = 0;
	x = (char *) malloc (ft_strlen(src) * sizeof (char) + 1);
	if (!x)
		return (NULL);
	while (src[i])
	{
		x[i] = src[i];
		i++;
	}
	x[i] = '\0';
	return (x);
}
