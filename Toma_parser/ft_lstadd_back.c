/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:17:43 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/16 15:12:52 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*back;

	back = *lst;
	if (!(lst))
	{
		//write(1, "cucu\n", 5);
		return ;
	}
	if (!*lst)
	{
		//write(1, "kuku\n", 5);
		*lst = new;
	}
	else
	{
		//write(1, "tutu\n", 5);	
		back = ft_lstlast(*lst);
		back->next = new;
	}
}
