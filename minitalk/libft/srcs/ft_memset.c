/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:48:24 by amismail          #+#    #+#             */
/*   Updated: 2024/09/05 22:22:24 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n)
	{
		*ptr = (char)c;
		ptr++;
		n--;
	}
	return (s);
}

/*int main()
{
	int x[10];
	ft_memset(x,0,sizeof(x));
	for (int i=0 ; i<10;i++)
		printf("%d \n",x[i]);
	return 0;
}*/
