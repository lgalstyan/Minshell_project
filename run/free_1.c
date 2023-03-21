/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:35:53 by lgalstya          #+#    #+#             */
/*   Updated: 2023/03/21 16:22:11 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_str(char *cmd)
{	
	if (cmd != NULL)
	{
		free(cmd);
		cmd = 0;
	}
}

void	free_one_node(t_node node)
{
	if (node.heredoc)
		free_arr(node.heredoc);
	if (node.append)
		free_arr(node.append);
	if (node.outfile)
		free_arr(node.outfile);
	if (node.infile)
		free_arr(node.infile);
	if (node.cmd)
		free_arr(node.cmd);
	if (node.readline)
		free(node.readline);
}

void	free_node(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node->next;
		if (node->heredoc)
			free_arr(node->heredoc);
		if (node->append)
			free_arr(node->append);
		if (node->outfile)
			free_arr(node->outfile);
		if (node->infile)
			free_arr(node->infile);
		if (node->cmd)
			free_arr(node->cmd);
		if (node->readline)
			free(node->readline);
		free(node);
		node = NULL;
		node = tmp;
	}
}

void	free_node_for_pipe(t_node *node, int i)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node->next;
		if (node->heredoc)
			free_arr(node->heredoc);
		if (node->append)
			free_arr(node->append);
		if (node->outfile)
			free_arr(node->outfile);
		if (node->infile)
			free_arr(node->infile);
		if (node->cmd)
			free_arr(node->cmd);
		if (node->readline)
			free(node->readline);
		free(node);
		node = NULL;
		node = tmp;
	}
	exit(i);
}

void	ft_error_fork(int pid, int i, t_node *node)
{
	if (pid == -1)
	{
		free_node(node);
		child_error(pid, i);
	}
}
