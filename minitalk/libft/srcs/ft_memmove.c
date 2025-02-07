/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:47:41 by amismail          #+#    #+#             */
/*   Updated: 2024/08/27 16:42:18 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*des;
	char	*sr;

	if (dest == src)
		return (dest);
	if (dest < src)
	{
		des = (char *)dest;
		sr = (char *)src;
		while (n--)
		{
			*des++ = *sr++;
		}
	}
	else
	{
		des = (char *)dest + n - 1;
		sr = (char *)src + n - 1;
		while (n--)
		{
			*des-- = *sr--;
		}
	}
	return (dest);
}
/*int main()
{
    char source[] = "Hello, world!";
    char destination[20];

    // Copy the first 5 characters from source to destination
    ft_memmove(destination, source, 5);

    printf("Destination: %s\n", destination);
    return 0;
}*/
