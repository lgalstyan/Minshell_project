/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:25:38 by tyenokya          #+#    #+#             */
/*   Updated: 2023/03/10 14:34:20 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	allocate_matrix(t_node	*head)
{
	head->counts.s_infile = ft_infile_count(head->readline);
	head->counts.s_outfile = ft_outfile_count(head->readline);
	head->counts.s_heredoc = ft_heredoc_count(head->readline);
	head->counts.s_append = ft_append_count(head->readline);
	head->counts.s_all = ft_wcount(head->readline, ' ');
	head->counts.s_cmd = head->counts.s_all - ft_all_redir_size(head);
	head->infile = ft_calloc((head->counts.s_infile + 1), sizeof(char *));
	head->outfile = ft_calloc((head->counts.s_outfile + 1), sizeof(char *));
	head->heredoc = ft_calloc((head->counts.s_heredoc + 1), sizeof(char *));
	head->append = ft_calloc((head->counts.s_append + 1), sizeof(char *));
}

void	initialize(t_node	*head)
{
	while (head)
	{
		allocate_matrix(head);
		initial_nodes(head);
		head = head->next;
	}
}

t_node	*parser(t_node *head, t_env **envir)
{
	t_node	*node;

	node = head;
	if (check_quote_2(head, envir) || unexpected_tokens(head, envir))
	{
		free_node(head);
		return (0);
	}
	initialize(head);
	while (node)
	{
		ft_clean_sp_redir(node);
		ft_clean_spasec(node, envir);
		node = node->next;
	}
	return (head);
}
