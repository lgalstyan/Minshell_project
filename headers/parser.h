/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:33:14 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/22 15:18:22 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

typedef struct s_node
{
	char			**heardock;
	char			**append;
	char			**infile;
	char			**outfile;
	char			**cmd;
	struct	s_node	*next;
	int				*redir;
}			t_node;

int		wcount(char *s, char c);
int		checkquotes(char *str);
int		count_redir(t_node *node);
int		*fill_redir(char *str, t_node *node);
char	*pars_ft_strjoin(char *s1, char *s2);
char	**pars_ft_split(char *s, char c);
char	ft_strgtav(char *str, int c);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strpaste(char *dst, char *src);
char	*ft_strdup(char *s1);
char	*rm_space(char *str);
int		pars_ft_strlen(const char *s);
int		put_in(t_node *node, char *str, int s);
int		put_out(t_node *node, char *str, int s);
int		put_hd(t_node *node, char *str, int s);
int		put_ap(t_node *node, char *str, int s);
int		put_cmd(t_node *node, char *str, int s);
void	ft_lstadd_back(t_node **lst, t_node *n);
t_node	*initialize(char *str, t_node *node);
t_node	*ft_lstlast(t_node *lst);

#endif