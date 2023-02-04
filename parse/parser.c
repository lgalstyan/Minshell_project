/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:25:38 by tyenokya          #+#    #+#             */
/*   Updated: 2023/02/03 17:45:05 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// stugel "-eri qanaky zuyg lini
// stugel | piperi qanaky lini spliti qanak -1
// amen mi pipe qcel mi nodei mej
// hanel redirectionnery
//cat >> djh <<< dic > duhi  < jcoe <k >j

void	print_node(t_node *node)
{
	int	i;

	i = 0;
	if (node)
	{
		while (node->cmd && node->cmd[i])
		{
			printf("cmd%d=%s_\n", i, node->cmd[i]);
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
	}
}


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
	head->cmd = ft_calloc((head->counts.s_cmd + 1), sizeof(char *));
}

// cat a >> asas asasa < sasa >  ds < sda >> dsd < << < <

char	**ft_clean(char **str)
{
	int	i;
	
	i = 0;
	while (str && str[i])
	{
		str[i] = ft_strtrim(str[i], SPACES);
		i++;
	}
	return (str);
}

void	ft_clean_spasec(t_node *head)
{
	t_node	*node;

	node = head;	
	while (node)
	{
		node->cmd = ft_clean(node->cmd);
		node->infile = ft_clean(node->infile);	
		node->outfile = ft_clean(node->outfile);	
		node->append = ft_clean(node->append);	
		node->heredoc = ft_clean(node->heredoc);	
		node = node->next;
	}
}

t_node	*parser(t_node *head)
{
	if ((check_quote_2(head)|| unexpected_tokens(head)))
		return (0);
	while(head)
	{
		allocate_matrix(head);
		initial_nodes(head);
		head = head->next;
	}
	// print_node(head);
	ft_clean_spasec(head);
	// print_node(head);
	return (head);
}
