/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:17:03 by amismail          #+#    #+#             */
/*   Updated: 2024/10/12 19:42:12 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	pcount(const char *str);
static int	cond(char c);

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		count;
	int		prnum;

	if (!format)
		return (-1);
	prnum = 0;
	count = pcount(format);
	va_start(list, format);
	while (*format != '\0' && count >= 0)
	{
		while (*format != '\0' && *format != '%')
		{
			write(1, format, 1);
			format++;
			prnum++;
		}
		if ((count > 0) && *format == '%')
		{
			prnum += definer(&format, list);
			count--;
		}
	}
	return (prnum);
}

static int	pcount(const char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (cond(str[i]))
				count++;
			else
				return (-1);
		}
		i++;
	}
	return (count);
}

static int	cond(char c)
{
	if (c == 'c' || c == 's' || c == 'i' || c == 'd')
		return (1);
	else if (c == 'u' || c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}
