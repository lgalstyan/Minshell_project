/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:02:14 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/16 16:14:21 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*rm_space(char *str)
{
	int 	i;
	int		d;
	int		flag;
	char	*dst;

	i = 0;
	d = 0;
	flag = 0;
	dst = malloc((pars_ft_strlen(str)));
	while(str[i])
	{
		while (str[i] == ' ')
		{
			flag = 1;
			++i;
		}
		if (flag)
		{
			dst[d++] = ' ';
			flag = 0;
		}
		else if (str[i] == '\"')
			while (str[i] != '\"')
				dst[d++] = str[i++];
		else if (str[i] == '\'')
			while (str[++i] != '\'')
				dst[d++] = str[i++];
		dst[d++] = str[i++];
	}
	dst[d] = '\0';
	return (dst);
}
