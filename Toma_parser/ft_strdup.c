/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:19:36 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/09 15:15:39 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(char *s1)
{
	char	*dest;

	dest = malloc(ft_strlen(s1) + 1);
	if (dest == NULL)
		return (NULL);
	if (*s1 == '\"' || *s1 == '\'')
		ft_strpaste(dest, s1);
	else
		ft_strcpy(dest, s1);
	return (dest);
}
