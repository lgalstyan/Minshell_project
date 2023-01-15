/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:19:36 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/15 16:19:49 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcpy(char *dst, char *src)
{
	int		i;

	i = 0;
	if (src[i] == '-' || src[i] == '>' || src[i] == '<' )
	{
		dst[i] = src[i];
		++i;
		if (src[i] == '>' && src[i - 1] == '>')
		{
			dst[i] = src[i];
			++i;
		}
		if (src[i] == '<' && src[i - 1] == '<')
		{
			dst[i] = src[i];
			++i;
		}
	}
	while (src[i] != ' ' && src[i] != '\0' && src[i] != '<'
		&& src[i] != '>' && src[i] != '\'' && src[i] != '\"' && src[i] != '-')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
