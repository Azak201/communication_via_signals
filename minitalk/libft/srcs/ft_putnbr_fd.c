/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:31:56 by amismail          #+#    #+#             */
/*   Updated: 2024/09/05 22:42:04 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cond(int n, int fd);

static void	ft_printnum(char *n, int fd)
{
	int	len;

	len = ft_strlen(n) - 1;
	while (len >= 0)
	{
		ft_putchar_fd((n[len]), fd);
		len--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num[12];
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	if (n == -2147483648 || n == 0)
	{
		cond(n, fd);
		return ;
	}
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
	ft_printnum(num, fd);
}

static void	cond(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n == 0)
		ft_putchar_fd('0', fd);
}

/*int main(void)
{
    int fd;

    fd = 1;
    ft_putnbr_fd(42, fd);          // Should write "42"
    ft_putchar_fd('\n', fd);       // Newline for readability
    ft_putnbr_fd(-42, fd);         // Should write "-42"
    ft_putchar_fd('\n', fd);       // Newline for readability
    ft_putnbr_fd(0, fd);           // Should write "0"
    ft_putchar_fd('\n', fd);       // Newline for readability
    ft_putnbr_fd(2147483647, fd);  // Should write "2147483647"
    ft_putchar_fd('\n', fd);       // Newline for readability
    ft_putnbr_fd(-2147483648, fd); // Should write "-2147483648"
    ft_putchar_fd('\n', fd);       // Newline for readability

    // Close the file descriptor

    return 0;
}*/
