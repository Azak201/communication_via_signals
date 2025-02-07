/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:50:27 by amismail          #+#    #+#             */
/*   Updated: 2024/09/17 18:38:50 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*int main() {
    char str[] = "hello world";
    char c = 'z';
    char *ptr = ft_strchr(str, c);

    if (ptr != NULL) {
        printf("Character '%c' found at index %ld\n", c, ptr - str);
    } else {
        printf("Character '%c' not found\n", c);
    }

    return 0;
}*/
