/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:49:32 by amismail          #+#    #+#             */
/*   Updated: 2024/09/18 17:59:46 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*p;

	p = dest;
	if (n == 0)
		return (dest);
	if (!src && !dest)
		return (NULL);
	while (n--)
	{
		*(char *) p = *(const char *) src;
		p ++;
		src ++;
	}
	return (dest);
}

/*int main()
{
	char	src[10] = "thisiste";
	char	dest[10];

	ft_memcpy(dest,src,4);
	printf("%s\n",dest);
	return 0;

}*/
