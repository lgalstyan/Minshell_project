/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:32:22 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/16 16:29:24 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
//heardock <<
//append >>
//output >
//input <
//./a.out "  ls -l | echo -s | vhewgvdhwe |djbhc jhw | echo"

t_node	*pars(char *argv)
{
	int		i;
	char	*str;
	char	**sp;
	t_node	*node;
	t_node	*new;

	new = malloc(sizeof(t_node));
	str = "";
	node = NULL;
	str = pars_ft_strjoin(str, argv);
	if (!checkquotes(str))
		return (0);
	sp = pars_ft_split(str, '|');
	i = 0;
	while (i < wcount(str, '|') && sp[i])
	{
		
		initialize(sp[i], new);
		// if (new)
			// write(1, "aystex hasnum e\n", 15);
		ft_lstadd_back(&node, new);
		++i;
	}
	return (node);
}
