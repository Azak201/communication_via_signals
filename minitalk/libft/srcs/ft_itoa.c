/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:21:51 by amismail          #+#    #+#             */
/*   Updated: 2024/09/19 14:40:21 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*cond(int n)
{
	char	*str;

	if (n == 0)
	{
		str = ft_strdup("0");
	}
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
	}
	return (str);
}

static void	mines(int *n, int *sign, int *slen)
{
	*n = -*(n);
	*sign = -1;
	*slen = *slen + 1;
}

char	*ft_itoa(int n)
{
	int		slen;
	int		sign;
	char	*str;

	if (n == 0 || n == -2147483648)
		return (cond(n));
	sign = 1;
	slen = 0;
	if (n < 0)
		mines(&n, &sign, &slen);
	slen += size(n);
	str = (char *) malloc (sizeof(char) * (slen + 1));
	if (!str)
		return (NULL);
	*(str + slen) = '\0';
	while (slen > 0)
	{
		slen --;
		*(str + slen) = (n % 10) + '0';
		n = n / 10;
	}
	if (sign == -1)
		*(str + slen) = '-';
	return (str);
}
/*int main()
{
    int i = 0;
    int a[6]={53727,-155,634527,0,-2147483648,2147483647};
    while (i <= 5)
    {
        printf("%s \n",ft_itoa(a[i]));
        i++;
    }
    return (0);
}*/
