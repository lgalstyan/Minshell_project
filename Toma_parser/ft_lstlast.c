/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:05:54 by tyenokya          #+#    #+#             */
/*   Updated: 2022/12/17 16:18:46 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*ft_lstlast(t_node *node)
{
	if (node == NULL)
		return (0);
	while (node -> next != NULL)
	{
		node = node -> next;
	}
	return (node);
}
