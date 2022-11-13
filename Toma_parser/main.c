/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:32:22 by tyenokya          #+#    #+#             */
/*   Updated: 2022/11/13 15:58:48 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//heardock <<
//append >>
//infile >
//outfile <

int main(int argc, char **argv)
{
	int		i;
	char	*str;
	char	**sp;
	t_node	*node;

	i = 0;
	str = "";
	while (++i < argc)
		str = ft_strjoin(str, argv[i]);
	if (!checkquotes(str))
		return (0);
	sp = ft_split(str, '|');
	printf("aaaaaaaaaa: %s\n", sp[0]);
	i = 0;
	node = initialize(sp[0]);
	/*while (sp[++i])
	{
		node = node->next;
		node = initialize(sp[i]);
	}*/
	//printf("bbbbbbbb: %s\n", sp[0]);
}
