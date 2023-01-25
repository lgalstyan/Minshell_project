/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpaste.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:06:36 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/16 15:13:13 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
