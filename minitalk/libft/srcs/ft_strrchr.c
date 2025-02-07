/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:06:19 by amismail          #+#    #+#             */
/*   Updated: 2024/09/17 18:36:12 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
/*int main() {
    char str[] = "hello world";
    char c = 'o';
    char *ptr = strrchr(str, c);

    if (ptr != NULL) {
        printf("Last occurrence of '%c' found at index %ld\n", c, ptr - str);
    } else {
        printf("Character '%c' not found\n", c);
    }

    return 0;
}*/
