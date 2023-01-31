/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:21:42 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/30 14:38:46 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	checkquotes(char *str)
{
	int	i;
	int	count[2];

	i = 0;
	count[0] = 0;
	count[1] = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			++count[0];
		if (str[i] == '\'')
			++count[1];
		++i;
	}
	if (count[0] % 2 || count[1] % 2)
		return (1);
	return (0);
}

int	check_quote_2(t_node *node)
{
	int		i;
	char	*curr;
	char	c;

	i = 0;
	curr = node->readline;
	while (curr[i])
	{
		if (curr[i] == '\'' || curr[i] == '"')
		{
			c = curr[i++];
			if (curr[i] == '\0')
			{
				printf("minishell: syntax error near unexpected token\n");
				exit_code = 258;
				return (1);
			}
			while (curr[i] && curr[i] != c)
				i++;
			if (curr[i] != c)
			{
				printf("minishell: syntax error near unexpected token\n");
				exit_code = 258;
				return (1);
			}
		}
		i++;
	}
	return (0);
}

static int	find_unexpected_token(char *s, int i)
{
	while (s[i] && ft_strchr(SPACES, s[i]))
		i++;
	if (s[i] == '\0' || ft_strchr("|&;()><", s[i]))
	{
		printf("minishell: syntax error near unexpected token\n");
		exit_code = 258;
		return (1);
	}
	return (0);
}

static int	check_redir(char	*s)
{
	int	i;

	i = -1;
	while (s[++i] && !ft_strchr("()|&;", s[i]))
	{
		if ((s[i] == '>' && s[i + 1] == '>' && ++i && ++i)
			|| (s[i] == '<' && s[i + 1] == '<' && ++i && ++i)
			|| (s[i] == '<' && ++i)
			|| (s[i] == '>' && ++i))
		{
			if (find_unexpected_token(s, i))
				return (1);
		}
	}
	return (0);
}

// static int	unexp_newline(char *tmp, int *i)
// {
// 	while (tmp[*i] && !ft_strchr("|&;()", tmp[*i]))
// 		++(*i);
// 	if (tmp[*i] && ft_strchr("|&;()", tmp[*i]) && ++(*i))
// 	{
// 		while (tmp[*i] && ft_strchr(SPACES, tmp[*i]))
// 			(*i)++;
// 		if (tmp[*i] == '\0')
// 		{
// 			printf("minishell: syntax error near unexpected token\n");
// 			exit_code = 258;
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

static int	unexp_symv(char *tmp, int i)
{
	if (tmp[i] == '\0' || ft_strchr("|&;()", tmp[i]))
	{
		if (tmp[i] == '\0' || ft_strchr("|&;()", tmp[i]))
		{
			printf("minishell: syntax error near unexpected token\n");
			exit_code = 258;
			return (1);
		}
	}
	return (0);
}

int	unexpected_tokens(t_node *node)
{
	char	*curr;
	int		i;

	i = 0;
	curr = node->readline;
	while (curr[i])
	{
		if (check_redir(curr + i))
			return (1);
		while (curr[i] && ft_strchr(SPACES, curr[i]))
			i++;
		if (curr[i] && ft_strchr("|&;()", curr[i]))
		{
			if (unexp_symv(curr, i))
				return (1);
		}
		// else
		// 	if (unexp_newline(curr, &i))
		// 		return (1);
		if (curr[i] && !ft_strchr("|&;()", curr[i]))
			i++;
	}
	return (0);
}