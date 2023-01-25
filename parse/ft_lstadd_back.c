/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:17:43 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/23 13:20:50 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_node	*ft_lstlast(t_node *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*back;

	back = *lst;
	if (!(lst))
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		back = ft_lstlast(*lst);
		back->next = new;
	}
}
