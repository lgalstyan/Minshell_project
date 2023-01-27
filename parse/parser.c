/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:25:38 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/26 15:44:45 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
// stugel "-eri qanaky zuyg lini
// stugel | piperi qanaky lini spliti qanak -1
// amen mi pipe qcel mi nodei mej
// hanel redirectionnery

void	print_node(t_node *node)
{
	int	i;

	i = 0;
	if (node)
	{
		while (node->cmd && node->cmd[i])
		{
			printf("cmd%d = %s\n", i, node->cmd[i]);
			i++;
		}
		i = 0; 
		while (node->heredoc && node->heredoc[i])
		{
			printf("heredoc = %s\n", node->heredoc[i]);
			i++;
		}
		i = 0; 
		while (node->append && node->append[i])
		{
			printf("append = %s\n", node->append[i]);
			i++;
		}
		i = 0; 
		while (node->outfile && node->outfile[i])
		{
			printf("outfile = %s\n", node->outfile[i]);
			i++;
		}
		i = 0; 
		while (node->infile && node->infile[i])
		{
			printf("infile = %s\n", node->infile[i]);
			i++;
		}
		// i = 0;
		// while (node->redir[i])
		// {
		// 	printf("redir = %d\n", node->redir[i]);
		// 	i++;
		// }
	}
}


void	allocate_matrix(t_node	*head)
{
	head->counts.s_infile = ft_infile_count(head->readline);
	head->counts.s_outfile = ft_outfile_count(head->readline);
	head->counts.s_heredoc = ft_heredoc_count(head->readline);
	head->counts.s_append = ft_append_count(head->readline);
	head->counts.s_all = ft_size_all(head->readline);
	head->counts.s_cmd = head->counts.s_all - ft_all_redir_size(head);

	printf("s_inf < %d, s_outf > %d, s_here << %d, s_app>> %d, s_cmd %d\n", head->counts.s_infile, head->counts.s_outfile, head->counts.s_heredoc, head->counts.s_append, head->counts.s_cmd);
	head->infile = ft_calloc((head->counts.s_infile + 1), sizeof(char *));
	head->outfile = ft_calloc((head->counts.s_outfile + 1), sizeof(char *));
	head->heredoc = ft_calloc((head->counts.s_heredoc + 1), sizeof(char *));
	head->append = ft_calloc((head->counts.s_append + 1), sizeof(char *));
	head->cmd = ft_calloc((head->counts.s_cmd + 1), sizeof(char *));
}

// cat a >> asas asasa < sasa >  ds < sda >> dsd < << < <

t_node	*parser(t_node *head)
{
	allocate_matrix(head);
	initial_nodes(head);
	print_node(head);
	return (head);
}
