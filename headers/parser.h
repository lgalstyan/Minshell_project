/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:33:14 by tyenokya          #+#    #+#             */
/*   Updated: 2023/01/25 13:10:14 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
 
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "structs.h"
# define METACHARACTERS  "|&;()<> \n\t"

int		wcount(char *s, char c);
int		checkquotes(char *str);
int		count_redir(t_node *node);
int		*fill_redir(char *str, t_node *node);
char	*pars_ft_strjoin(char *s1, char *s2);
char	**pars_ft_split(char *s, char c);
char	ft_strgtav(char *str, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strpaste(char *dst, char *src);
char	*ft_strdup(char *s1);
char	*rm_space(char *str);
int		pars_ft_strlen(const char *s);
// int		put_in(t_node *node, char *str, int s);
int		put_in_out(t_node *node, char c);
int		put_hd_app(t_node *node, char *c);
int		put_cmd(t_node *node, int s);
void	ft_lstadd_back(t_node **lst, t_node *n);
t_node	*initialize(char *str, t_node *node);
void	*ft_calloc(size_t c, size_t s);
char	*ft_substr(char *s, int start, int len);

int		ft_infile_count(char *line);
int		ft_outfile_count(char *line);
int		ft_heredoc_count(char *line);
int		ft_append_count(char *line);
int		is_meta(char c);


#endif