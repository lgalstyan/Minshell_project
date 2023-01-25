/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:25:38 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/25 13:27:06 by lgalstya         ###   ########.fr       */
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
			printf("cmd = %s\n", node->cmd[i]);
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

t_node *lexer(char *str)
{
	int		i;
	char	**sp;
	t_node	*node;
	t_node	*new;
  
	new = malloc(sizeof(t_node));
	i = 0;
	node = NULL;
	if (!checkquotes(str))
	{
		printf("Syntax error: the number of quotes is incorrect\n");
		return (0);
	}
	sp = pars_ft_split(str, '|');
	while (i < wcount(str, '|') && sp[i])
	{
		initialize(sp[i], new);
		ft_lstadd_back(&node, new);
		++i;
	}
	return (node);
}

void	allocate_matrix(t_node	*head)
{
	head->counts.s_infile = ft_infile_count(head->readline);
	head->counts.s_outfile = ft_outfile_count(head->readline);
	head->counts.s_heredoc = ft_heredoc_count(head->readline);
	head->counts.s_append = ft_append_count(head->readline);

	printf("s_inf < %d, s_outf > %d, s_here << %d, s_app>> %d\n", head->counts.s_infile, head->counts.s_outfile, head->counts.s_heredoc, head->counts.s_append);
	head->infile = ft_calloc((head->counts.s_infile + 1), sizeof(char *));
	head->outfile = ft_calloc((head->counts.s_outfile + 1), sizeof(char *));
	head->heredoc = ft_calloc((head->counts.s_heredoc + 1), sizeof(char *));
	head->append = ft_calloc((head->counts.s_append + 1), sizeof(char *));
}

void	initial_nodes(t_node *node)
{
	int	i;
	// int r;

	// r = 0;
	i = 0;
	while (node->readline && node->readline[i])
	{
		// if (node->readline[i] == '\"')
		// 	while (node->readline[++i] != '\"')
		// 		; 
		if (node->readline[i] == '>' && node->readline[i + 1] == '>')
			put_hd_app(node, ">>");
		else if (node->readline[i] == '<' && node->readline[i + 1] == '<')
			put_hd_app(node, "<<");
		else if (node->readline[i] == '>' && node->readline[i + 1] != '>')
			put_in_out(node, '>');
		else if (node->readline[i] == '<' && node->readline[i + 1] != '<')
			put_in_out(node, '<');
		++i;
	}
	// i += put_cmd(node, r);
}

// cat a >> asas asasa < sasa >  ds < sda >> dsd < << < <

t_node	*parser(t_node *head)
{	
	allocate_matrix(head);
	initial_nodes(head);
	print_node(head);
	// printf("line = %s\n", head->infile[0]);
	return (head);
}
