/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:04:31 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/16 15:12:44 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	count_redir(t_node *node)
{
	int	i;
	int count;

	count = 0;
	if (!node)
		return(0);
	while ((i = 0) && node->infile[++i])
		++count;
	while ((i = 0) && node->outfile[++i])
		++count;
	while ((i = 0) && node->heardock[++i])
		++count;
	while ((i = 0) && node->append[++i])
		++count;
	return (count);
}
