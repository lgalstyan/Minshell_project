/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:18:26 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/06 18:18:27 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_meta(char c)
{
	if (ft_strchr(METACHARACTERS, c) != 0)
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (ft_strchr(SPACES, c) != 0)
		return (1);
	return (0);
}
