/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:32:22 by tyenokya          #+#    #+#             */
/*   Updated: 2022/12/04 16:02:29 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//heardock <<
//append >>
//output >
//input <
//./a.out "  ls -l | echo -s | vhewgvdhwe |djbhc jhw | echo"

int main(int argc, char **argv)
{
	int		i;
	char	*str;
	char	**sp;
	t_node	**node;
	t_node	*new;

	new = malloc(sizeof(t_node));
	i = 0;
	str = "";
	while (++i < argc)
		str = ft_strjoin(str, argv[i]);
	if (!checkquotes(str))
		return (0);
	sp = ft_split(str, '|');
	i = 0;
	//printf("%d", wcount(str, '|'));
	node = malloc(sizeof(t_node) * wcount(str, '|'));
	while (i < wcount(str, '|') && sp[i])
	{
		initialize(sp[i], new);
		printf("%s = %s\n", new->cmd[0], sp[i]);
		//write(1, "aytex hasnum e\n", 15);
		ft_lstadd_back(node, new);
		++i;
	}
	return (0);
}
