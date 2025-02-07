/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:30:45 by amismail          #+#    #+#             */
/*   Updated: 2024/08/28 16:38:15 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	count;
	int	negative;
	int	number;

	count = 0;
	negative = 1;
	number = 0;
	while ((nptr[count] > 8 && nptr[count] < 14) || (nptr[count] == 32))
		count++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			negative = -1;
		count++;
	}
	while ((nptr[count] != '\0') && (nptr[count] >= 48 && nptr[count] <= 57))
	{
		number = (number * 10) + nptr[count] - 48;
		count++;
	}
	return (number * negative);
}
/*int main(void)
{
    char str[] = "-422796";
    int num;

    num = ft_atoi(str);
    printf("%d\n", num);

    return 0;
}*/
