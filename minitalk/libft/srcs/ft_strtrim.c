/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:48:09 by amismail          #+#    #+#             */
/*   Updated: 2024/09/02 18:22:29 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		strt;
	int		end;
	char	*str;

	strt = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[strt]) && strt <= end)
		strt++;
	if (strt >= end)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	str = (char *)malloc(sizeof(char) * (end - strt + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + strt, end - strt + 2);
	return (str);
}

/*int main()
{
    char test[30] = " ***+*a*mjed tes*t *   =*";
    char *tremmed;
    tremmed = ft_strtrim(test, " *+=");
    printf("%s---\n", tremmed);
}*/
