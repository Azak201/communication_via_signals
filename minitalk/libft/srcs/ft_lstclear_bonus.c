/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:16:38 by amismail          #+#    #+#             */
/*   Updated: 2024/09/25 17:36:06 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	if (*lst)
	{
		ft_lstclear (&(*lst)-> next, del);
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}
