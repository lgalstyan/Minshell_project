/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:19:36 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/16 15:51:49 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// char	*ft_strdup(char *src)
// {
// 	int		i;
// 	char	*tox;

// 	i = 0;
// 	if (!src)
// 		return (0);
// 	tox = (char *)malloc(pars_ft_strlen(src) + 1);
// 	if (!tox)
// 		return (0);
// 	while (src[i])
// 	{
// 		tox[i] = src[i];
// 		i++;
// 	}
// 	tox[i] = 0;
// 	return (tox);
// }


char	*ft_strdup(char *s1)
{
	char	*dest;

	dest = malloc(pars_ft_strlen(s1) + 1);
	if (dest == NULL)
		return (NULL);
	if (*s1 == '\"' || *s1 == '\'')
		ft_strpaste(dest, s1);
	else
		ft_strcpy(dest, s1);
	return (dest);
}


