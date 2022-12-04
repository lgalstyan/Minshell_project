/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:08:38 by tyenokya          #+#    #+#             */
/*   Updated: 2022/11/26 17:29:23 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ns;
	size_t	i;
	size_t	k;

	i = 0;
	ns = malloc(ft_strlen(s1) + ft_strlen(s2));
	while (s1[i] != '\0')
	{
		ns[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k] != '\0')
	{
		ns[i] = s2[k];
		k++;
		i++;
	}
	ns[i] = '\0';
	//free(s1);
	return (ns);
}
