/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:02:15 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/28 14:40:02 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	gtav(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	first(char *s, char *set)
{
	int	i;

	i = 0;
	while (gtav(set, s[i]) == 1)
	{
		i++;
	}
	return (i);
}

int	last(char *s, char *set)
{
	int	i;

	i = pars_ft_strlen(s) - 1;
	while (gtav(set, s[i]) == 1 && i > 0)
	{
		i--;
	}
	return (i);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		start;
	char	*trim;
	int		len;

	i = 0;
	if (last(s1, set) == 0 && first(s1, set) == pars_ft_strlen(s1))
		len = 1;
	else
		len = last(s1, set) - first(s1, set) + 1;
	trim = malloc(len);
	start = first(s1, set);
	while (i < len)
	{
		trim[i] = s1[start];
		i++;
		start++;
	}
	trim[i] = '\0';
	return (trim);
}
