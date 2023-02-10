/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:23:13 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/07 17:05:30 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_valid(char c)
{
	if (c == '_' || (c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

void	var_values(char *str, t_env *en)
{
	while (en)
	{
		if (!ft_strcmp(en->key, str))
			printf("%s", en->value);
		en = en->next;
	}
}

void	ft_strfind(char *str, t_env **en)
{
	int		i;
	int		start;
	char	*word;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '$')
		{
			if (!str[i + 1] || (is_space(str[i]) && i++))
				printf("$");
			if (str[++i] == '?' && i++)
			{
				print_exit_code(en);
				printf("%s", str + i);
				return ;
			}
			start = i;
			while (str[i] && check_valid(str[i]))
				i++;
			word = ft_substr(str, start, i - start);
			var_values(word, *en);
		}
		else
		{
			printf("%c", str[i]);
			++i;
		}
	}
}
