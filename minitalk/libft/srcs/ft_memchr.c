/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:29:33 by amismail          #+#    #+#             */
/*   Updated: 2024/08/27 12:47:59 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(const char *)s == (char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
/*int main() {
    char str[] = "Hello, world!";
    char *result;

    // Search for the first occurrence of 'o'
    result = ft_memchr(str, ',', strlen(str));

        printf("The first 'o' is at index %ld\n", result - str);

    return 0;

}*/
