/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:08:27 by amismail          #+#    #+#             */
/*   Updated: 2024/08/26 14:33:24 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*x;

	x = (char *) s;
	while (n--)
	{
		*x = 0;
		x++;
	}
}
/*int main()
{
	int x[10];
	char c[10];
	
	ft_bzero(x,sizeof(x));
	ft_bzero(c,sizeof(c));

	for(int i=0; i < 10; i++)
		printf("%d \n",x[i]);

	printf("\n\n");
	for(int i=0; i < 10; i++)
                printf("%c \n",c[i]);

}*/
