/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:02:06 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/22 16:37:04 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_valid_identif(char *str)
{
	int		i;
	char	**array;

	i = 0;
	if (ft_strnstr(str, "+=", ft_strlen(str)))
	{
		array = ft_split(str, '+');
		++i;
	}
	else
	{
		array = ft_split(str, '=');
	}
	if (!array[0])
	{
		free(array);
		return (0);
	}
	while (array[0] && array[0][i])
	{
		if (!check_valid(array[0][i]))
		{
			exit_code = 1;
			return (0);
		}
		++i;
	}
	return (1);
}
