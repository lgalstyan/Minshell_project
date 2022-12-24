/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:21:42 by tyenokya          #+#    #+#             */
/*   Updated: 2022/11/06 13:32:41 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	checkquotes(char	*str)
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
		return (0);
	return (1);
}
