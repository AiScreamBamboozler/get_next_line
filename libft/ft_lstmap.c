/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 17:09:01 by mschempe          #+#    #+#             */
/*   Updated: 2018/06/16 17:09:28 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*res_start;

	if (lst == NULL)
		return (NULL);
	res_start = f(lst);
	lst = lst->next;
	res = res_start;
	while (lst)
	{
		res->next = f(lst);
		res = res->next;
		lst = lst->next;
	}
	res = NULL;
	return (res_start);
}
