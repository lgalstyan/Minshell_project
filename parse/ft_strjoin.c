/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:08:38 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/16 15:15:26 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*pars_ft_strjoin(char *s1, char *s2)
{
	char	*ns;
	size_t	i;
	size_t	k;

	i = 0;
	ns = malloc(pars_ft_strlen(s1) + pars_ft_strlen(s2));
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
