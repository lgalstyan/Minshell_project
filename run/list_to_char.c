/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:14:32 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/28 14:21:54 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lst_size(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}

char	**list_to_char(t_env *env)
{
	int		i;
	char	**res;

	i = 0;
	res = malloc(sizeof(char *) * (ft_lst_size(env) + 1));
	while (env)
	{
		if (env->key)
			res[i] = ft_strjoin(env->key, "=");
		if (env->value)
			res[i] = ft_strjoin(res[i], env->value);
		i++;
		env = env->next;
	}
	res[i] = NULL;
	return (res);
}
