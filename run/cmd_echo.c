/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:57:27 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/27 18:29:06 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_valid(char c)
{
	if (c == '_' || (c > 47 && c < 58)
		|| (c > 64 && c < 91) || (c > 96 && c < 123))
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
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			start = i;
			while (check_valid(str[i]))
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

static int	ft_option_check(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] == 'n')
		i++;
	if (str[i])
		return (0);
	return (1);
}

static int	ft_wait_n(char **cmd)
{
	int	flag;
	int	i;

	i = 1;
	flag = 0;
	while (cmd[i][0] == '-')
	{
		if (ft_option_check(cmd[i]) == 0)
			return (i);		
		i++;
	}
	return (i);
}

void	cmd_echo(t_node node, t_env **en)
{
	int		flag;
	int		i;

	flag = 0;
	i = 1;
	if (!node.cmd[i])
	{
		printf("\n");
		return ;
	}
	if (node.cmd[i][0] == '-')
	{
		i = ft_wait_n(node.cmd);
		flag = 1;
		printf("i = %d\n", i);
		if (!node.cmd[i])
			return ;
	}
	ft_strfind(node.cmd[i], en);
	if (!flag)
		printf("\n");
}
