/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroments.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:17:28 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/15 13:52:44 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_inint_env(char *elem1, char *elem2, t_env *node)
{
	node->key = elem1;
	node->value = elem2;
	node->next = NULL;
}

void	environments(char **env, t_env **envir)
{
	int		i;
	char	**array;
	t_env	*new_node;

	i = 0;
	while (env[i])
	{
		new_node = malloc(sizeof(t_env));
		array = ft_split(env[i], '=');
		ft_inint_env(array[0], array[1], new_node);
		ft_lstadd_back_env(envir, new_node);
		++i;
	}
	set_exit_code("0", envir);
}
