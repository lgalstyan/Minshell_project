/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:46:50 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/16 15:12:59 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
