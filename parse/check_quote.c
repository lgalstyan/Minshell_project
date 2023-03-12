/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:39:59 by tyenokya          #+#    #+#             */
/*   Updated: 2023/03/10 14:44:52 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_qcount(char *str, int *i, char c)
{
	int	count;

	count = 1;
	while (str && str[++*i] && str[*i] != c)
		;
	if (str[*i] == c)
		++count;
	return (count);
}

int	checkquotes(char *str)
{
	int	i;
	int	count[2];

	i = -1;
	count[0] = 0;
	count[1] = 0;
	while (str && str[++i])
	{
		if (str[i] == '\"')
			count[0] += ft_qcount(str, &i, '\"');
		else if (str[i] == '\'')
			count[1] += ft_qcount(str, &i, '\'');
		if (!str[i])
			break ;
	}
	if (count[0] % 2 || count[1] % 2)
		return (1);
	return (0);
}

void	skipquotes(char **promt, int *j)
{
	int	i;

	i = *j;
	if (i > 0 && (*promt)[i - 1] && (*promt)[i - 1] == 92)
	{
		(*j)++;
		return ;
	}
	if ((*promt)[i] && (*promt)[i] == 34)
	{
		i++;
		while ((*promt)[i] && (*promt)[i] != 34)
			i++;
		if ((*promt)[i])
			i++;
	}
	if ((*promt)[i] && (*promt)[i] == 39)
	{
		i++;
		while ((*promt)[i] && (*promt)[i] != 39)
			i++;
		if ((*promt)[i])
			i++;
	}
	*j = i;
}
