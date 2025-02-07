/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:30:12 by amismail          #+#    #+#             */
/*   Updated: 2024/09/05 22:31:29 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	size_t	x;
	size_t	slen;

	if (s == NULL || f == NULL)
		return (NULL);
	slen = ft_strlen(s);
	x = 0;
	newstr = (char *)malloc(sizeof(char) * (slen + 1));
	if (!newstr)
		return (NULL);
	while (s[x] != '\0')
	{
		newstr[x] = f((unsigned int)x, s[x]);
		x++;
	}
	newstr[x] = '\0';
	return (newstr);
}
