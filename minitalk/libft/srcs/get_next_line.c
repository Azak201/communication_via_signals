/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:34:53 by amismail          #+#    #+#             */
/*   Updated: 2024/11/21 19:28:09 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static char	*readline(int fd, char *line);
static char	*splitter(char *str, char *reminder);
static char	*line(char *line);
static char	*ft_free(char *f1, char *f2);

char	*get_next_line(int fd)
{
	static char	*reminder = NULL;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (reminder)
	{
		str = ft_strdup(reminder);
		if (!str)
			return (ft_free(reminder, NULL));
		free(reminder);
		reminder = NULL;
	}
	else
		str = ft_strdup("");
	str = readline(fd, str);
	if (!str || str[0] == '\0')
		return (ft_free(str, reminder));
	reminder = splitter(str, reminder);
	str = line(str);
	if (!str)
		return (ft_free(str, NULL));
	return (str);
}

static char	*readline(int fd, char *line)
{
	ssize_t		r;
	char		*tmp;
	char		buffer[BUFFER_SIZE + 1];

	if (!line)
		return (NULL);
	while (1)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
			return (ft_free(line, NULL));
		buffer[r] = '\0';
		if (r > 0)
		{
			tmp = ft_strjoin(line, buffer);
			if (!tmp)
				return (ft_free(line, NULL));
			free(line);
			line = tmp;
		}
		if (ft_strchr(buffer, '\n') || r == 0)
			break ;
	}
	return (line);
}

static char	*splitter(char *str, char *reminder)
{
	int		i;
	char	*new_rem;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
	{
		new_rem = ft_substr(str, i + 1, ft_strlen(str));
		if (!new_rem)
			return (ft_free(reminder, NULL));
		free(reminder);
		reminder = new_rem;
	}
	else
	{
		free(reminder);
		reminder = NULL;
	}
	return (reminder);
}

static char	*line(char *line)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
	{
		temp = ft_substr(line, 0, (i + 1));
		if (!temp)
			return (ft_free(line, NULL));
		free(line);
		line = temp;
	}
	return (line);
}

static char	*ft_free(char *f1, char *f2)
{
	if (f1)
		free(f1);
	if (f2)
		free(f2);
	return (NULL);
}
