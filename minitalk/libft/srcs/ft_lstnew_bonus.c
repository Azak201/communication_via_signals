/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:23:52 by amismail          #+#    #+#             */
/*   Updated: 2024/09/29 13:35:22 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newitem;

	newitem = malloc (sizeof(t_list));
	if (!newitem)
		return (NULL);
	newitem -> content = content;
	newitem -> next = NULL;
	return (newitem);
}
