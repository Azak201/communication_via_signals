/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:21:54 by amismail          #+#    #+#             */
/*   Updated: 2024/10/12 16:10:33 by amismail         ###   ########.fr       */
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

int	ft_putnbr(int n)
{
	char	num[12];
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	if (n == -2147483648 || n == 0)
		return (cond(n));
	if (n < 0)
	{
		sign *= -1;
		n = -n;
	}
	while (n > 0)
	{
		num[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		num[i++] = '-';
	num[i] = '\0';
	ft_printnum(num);
	return (i);
}

static int	cond(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	ft_putchar('0');
	return (1);
}

/*int main(void)
{
	ft_putnbr(42);          // Should write "42"
	ft_putchar('\n');       // Newline for readability
	ft_putnbr(-42);         // Should write "-42"
	ft_putchar('\n');       // Newline for readability
	ft_putnbr(0);           // Should write "0"
	ft_putchar('\n');       // Newline for readability
	ft_putnbr(2147483647);  // Should write "2147483647"
	ft_putchar('\n');       // Newline for readability
	ft_putnbr(-2147483648); // Should write "-2147483648"
	ft_putchar('\n');       // Newline for readability

	// Close the file descriptor

	return 0;
}*/
