/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:06:36 by tyenokya          #+#    #+#             */
/*   Updated: 2022/12/25 17:07:30 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strpaste(char *dst, char *src)
{
	int	i;

	i = 0;
	if (!dst || !src)
		return (0);
	while (src[i] && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		if (src[i] == '\"' || src[i] == '\'')
			break;
	}
	dst[i] = '\0';
	return (dst);
}
