/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:19:36 by tyenokya          #+#    #+#             */
/*   Updated: 2022/12/04 17:33:47 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcpy(char *dst, char *src)
{
	int		i;
//	char	c;

	i = 0;
	//src[i] = '\0';
	//c = ft_strgtav(src, ' ');
	write(1, "ttt\n", 4);
	write(1, &src[i], 1);
	while (src[i] != ' ' && src[i] != '\0' && src[i] != '>' && src[i] != '<')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
