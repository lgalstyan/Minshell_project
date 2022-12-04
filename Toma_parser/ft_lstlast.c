/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:05:54 by tyenokya          #+#    #+#             */
/*   Updated: 2022/11/26 17:15:26 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*node;

	node = lst;
	if (node == NULL)
		return (NULL);
	while (node -> next != NULL)
	{
		write(1, "here\n", 5);
		node = node -> next;
	}
	return (node);
}
