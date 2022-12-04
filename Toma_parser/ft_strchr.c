/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:46:50 by tyenokya          #+#    #+#             */
/*   Updated: 2022/11/26 17:50:38 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_strgtav(char *str, int c)
{
	int		i;
	char	sym;

	i = 0;
	sym = c;
	while (str[i] && str[i] != sym)
		i++;
	if (str[i] == sym)
		return (' ');
	return ('\0');
}
