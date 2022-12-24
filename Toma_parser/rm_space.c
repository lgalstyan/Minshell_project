/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:02:14 by tyenokya          #+#    #+#             */
/*   Updated: 2022/12/24 16:40:46 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*rm_space(char *str)
{
	int 	i;
	int		d;
	char	*dst;

	i = 0;
	d = 0;
	dst = malloc((ft_strlen(str)));
	while(str[i])
	{
		if (str[i] == ' ')
			++i;
		else if (str[i] == '\"')
		{
			printf("hello");
			while (str[i] != '\"')
			{
				dst[d++] = str[i++];
			}
		}
		else if (str[i] == '\'')
		{
			printf("hello");
			while (str[++i] != '\'')
			{
				dst[d++] = str[i++];
			}
		}
		dst[d++] = str[i++];
	}
	dst[d] = '\0';
	printf("////////%s///////\n", dst);
	return (dst);
}
