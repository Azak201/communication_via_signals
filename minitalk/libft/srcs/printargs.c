/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:54:25 by amismail          #+#    #+#             */
/*   Updated: 2024/10/12 19:39:06 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	printarg(const char **str, va_list arglist);
static int	printarg2(const char **str, va_list arglist);
static int	printarg3(const char **str, va_list arglist);
static int	spcase(const char **str);

int	definer(const char **str, va_list arglist)
{
	(*str)++;
	if (**str == 'c')
		return (printarg(str, arglist));
	else if (**str == 's')
		return (printarg(str, arglist));
	else if (**str == 'u')
		return (printarg2(str, arglist));
	else if (**str == 'd' || **str == 'i')
		return (printarg2(str, arglist));
	else if (**str == 'p')
		return (printarg3(str, arglist));
	else if (**str == 'X')
		return (printarg3(str, arglist));
	else if (**str == 'x')
		return (printarg3(str, arglist));
	else if (**str == '%')
		return (spcase(str));
	return (0);
}

static int	printarg(const char **str, va_list arglist)
{
	char	c;
	char	*s;
	int		i;

	i = 0;
	if ((**str) == 'c')
	{
		c = va_arg(arglist, int);
		i = ft_putchar(c);
		(*str)++;
		return (i);
	}
	else if ((**str) == 's')
	{
		s = va_arg(arglist, char *);
		i = ft_putstr(s);
		(*str)++;
		return (i);
	}
	return (i);
}

static int	printarg2(const char **str, va_list arglist)
{
	int				num;
	unsigned int	un;
	int				i;

	i = 0;
	if ((**str) == 'd' || (**str) == 'i')
	{
		num = va_arg(arglist, int);
		i = ft_putnbr(num);
		(*str)++;
		return (i);
	}
	else if ((**str) == 'u')
	{
		un = va_arg(arglist, unsigned int);
		i = ft_putu(un);
		(*str)++;
		return (i);
	}
	return (i);
}

static int	printarg3(const char **str, va_list arglist)
{
	void			*p;
	unsigned long	hex;
	int				i;

	i = 0;
	if ((**str) == 'p')
	{
		p = va_arg(arglist, void *);
		hex = (unsigned long)p;
		i = ft_putp(hex, 1);
		(*str)++;
		return (i);
	}
	else if ((**str) == 'x' || (**str) == 'X')
	{
		hex = va_arg(arglist, unsigned int);
		if ((**str) == 'x')
			i = ft_puthex(hex, 1);
		if ((**str) == 'X')
			i = ft_puthex(hex, 2);
		(*str)++;
		return (i);
	}
	return (i);
}

static int	spcase(const char **str)
{
	int	i;

	i = ft_putchar('%');
	(*str)++;
	return (i);
}
