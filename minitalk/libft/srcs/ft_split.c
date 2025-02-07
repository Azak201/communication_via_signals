/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:12:22 by amismail          #+#    #+#             */
/*   Updated: 2024/09/25 16:15:50 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordnum(char *str, char del)
{
	char	*cp;
	int		count;

	count = 0;
	cp = str;
	while (*cp != '\0')
	{
		while (*cp == del)
			cp++;
		if (*cp)
			count++;
		while (*cp != '\0' && *cp != del)
			cp++;
	}
	return (count);
}

static void	*ft_free(char **spstr)
{
	int	i;

	i = 0;
	while (spstr[i])
	{
		free(spstr[i]);
		i++;
	}
	free (spstr);
	return (NULL);
}

static void	ft_worlen(int *worlen, char const *s, char c)
{
	if (!ft_strchr(s, c))
		*worlen = ft_strlen(s);
	else
		*worlen = ft_strchr(s, c) - s;
}

char	**ft_split(char const *s, char c)
{
	char	**spstr;
	int		ind;
	int		worlen;

	ind = 0;
	if (!s)
		return (NULL);
	spstr = (char **)malloc(sizeof(char *) * (wordnum((char *)s, c) + 1));
	if (!spstr)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			ft_worlen(&worlen, s, c);
			spstr[ind++] = ft_substr(s, 0, worlen);
			if (!spstr[ind - 1])
				return (ft_free(spstr));
			s += worlen;
		}
	}
	spstr[ind] = NULL;
	return (spstr);
}
/*
if(*s)
its find if thier still delemeter or no
if true (no delem left)
all the string are the worlen
if not (thier is delem)
calculate the size of string from the start of delem to end
and subract it from the orginal one to find the string len
then sub the strin and stor it in index and move the pointer
 to the next delem

 else
    worlen = ft_strchr(s,c) - s;
find the first occerance and return pointer to it in calculate the
deference between the founded element and the 0 elemnt(first elemnt)
the founded one is the larger in index so we did put the s
in the right side
*/

/*int main(void)
{
    // Example input string and delimiter
    char str[] = "Hello,world,this,is,a,test";
    char delimiter = ',';

    // Call the ft_split function
    char **result = ft_split(str, delimiter);

    // Check if the result is not NULL
    if (result == NULL)
    {
        printf("Error: Memory allocation failed or empty string\n");
        return (1);
    }

    // Print the result
    for (int i = 0; result[i] != NULL; i++)
    {
        printf("Word %d: %s\n", i, result[i]);
        free(result[i]); // Free each allocated substring
    }

    // Free the array of pointers
    free(result);

    return (0);
}*/
