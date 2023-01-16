/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:05:54 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/16 15:12:55 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
