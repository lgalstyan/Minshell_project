/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:57:52 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/30 12:52:00 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	pars_ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s && *s++)
		length++;
	return (length);
}
