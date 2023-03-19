/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:44:13 by tyenokya          #+#    #+#             */
/*   Updated: 2023/03/10 14:51:24 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace(char *str, int start, int end, t_env *en)
{
	char	*s;

	s = ft_substr(str, start, end - start + 1);
	while (en)
	{
		if (!ft_strcmp(en->key, s))
		{
			free(s);
			return (en->value);
		}
		en = en->next;
	}
	if (!ft_strcmp("?", s))
	{
		free(s);
		return ("0");
	}
	free (s);
	return (NULL);
}

int	print_doll(char *str, int *i)
{
	if (str[*i] == '$' && (!str[*i + 1] || (is_space(str[*i]))))
	{
		i++;
		return (1);
	}
	return (0);
}

char	*change_doll(char *str, t_env **en)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		ignore_single_quotes(str, &i);
		print_doll(str, &i);
		if (str[i] == '$')
		{
			str = change(str, en, i);
		}
		if (!str || !str[i])
			break ;
		i++;
	}
	return (str);
}
