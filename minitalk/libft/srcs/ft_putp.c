/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:23:07 by amismail          #+#    #+#             */
/*   Updated: 2024/10/12 16:43:01 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_printnum(char *n, int flag)
{
	int	len;

	len = ft_strlen(n) - 1;
	if (flag == 1)
	{
		while (len >= 0)
		{
			ft_putchar(ft_tolower(n[len]));
			len--;
		}
		return ;
	}
	while (len >= 0)
	{
		ft_putchar((n[len]));
		len--;
	}
}

int	ft_putp(unsigned long num, int flag)
{
	char	hex[17];
	char	x[17];
	int		i;

	i = -1;
	while (i++ < 8)
		x[i] = 0;
	if (num == 0)
		return (ft_putstr("(nil)"));
	ft_strlcpy(hex, "0123456789ABCDEF", 17);
	i = 0;
	ft_putstr("0x");
	while (num > 0)
	{
		x[i] = hex[num % 16];
		i++;
		num /= 16;
	}
	x[i] = '\0';
	ft_printnum(x, flag);
	return (i + 2);
}
