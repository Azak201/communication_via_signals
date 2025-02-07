/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:26:12 by amismail          #+#    #+#             */
/*   Updated: 2024/10/12 16:42:43 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cond(int n);

static void	ft_printnum(char *n)
{
	int	len;

	len = ft_strlen(n) - 1;
	while (len >= 0)
	{
		ft_putchar((n[len]));
		len--;
	}
}

int	ft_putu(unsigned int n)
{
	char	num[12];
	int		i;

	i = 0;
	if (n == 0)
		return (cond (n));
	while (n > 0)
	{
		num[i++] = (n % 10) + '0';
		n /= 10;
	}
	num[i] = '\0';
	ft_printnum(num);
	return (i);
}

static int	cond(int n)
{
	(void)n;
	ft_putchar ('0');
	return (1);
}
