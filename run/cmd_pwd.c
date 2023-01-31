/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:06:10 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/20 16:08:02 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_pwd(void)
{
	char	cwd[256];

	if (!(getcwd(cwd, sizeof(cwd))))
	{
		exit_code = 1;
		perror("minishell: ");
		return (-1);
	}
	else
		printf("%s\n", get_current_path());
	return (0);
}
