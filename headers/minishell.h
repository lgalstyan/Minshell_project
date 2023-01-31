/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:44:17 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/24 12:00:13 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include "libft.h"
# include "structs.h"

int exit_code;

int		wcount(char *s, char c);
int		checkquotes(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split_pars(char *s, char c);
char	**ft_split_export(char *s, char c);
char	ft_strgtav(char *str, int c);
char	*ft_strcpy(char *dst, char *src);
char	*run_ft_strdup(char *s1);
char	*rm_space(char *str);
int		put_in(t_node *node, char *str, int s);
void	ft_lstadd_back(t_node **lst, t_node *new_env);



void	ft_lstadd_back_env(t_env **lst, t_env *new_env);
int		builtin(t_node node, t_env **en);
int		is_builtin(char *cmd);
void	ft_inint_env(char *elem1, char *elem2, t_env *node);
int		ft_atoi(char *str);
int		cmd_pwd();
int		cmd_cd(t_node node, t_env **en);
void	cmd_echo(t_node n, t_env **en);
void	cmd_export(t_node n, t_env **en);
void	cmd_exit(char** cmd);
void	cmd_unset(char *del_env, t_env **env);
void	print_list(t_env **node);
void	ft_strfind(char *str, t_env **en);
char	**ft_split(char *s, char c);
char	*search_list(t_env *env, char *key);
void	delete_list(t_env **env);
int		check_valid(char c);
int		check_valid_identif(char *str);
void	update_list_item(t_env **lst, char *key, char *value);
char	*get_current_path(void);
void	sort_list(t_env **env);
int		prompt(t_node node, t_env **envir);
void	environments(char **env, t_env **envir);
char	**list_to_char(t_env *env);

t_node	*lexer(char *str);
t_node	*parser(t_node *node);


//parser.h

int     ft_wcount(char *s, char c);
int		checkquotes(char *str);
t_node	*cut_redir(t_node *node);
int		*fill_redir(char *str, t_node *node);
char	*pars_ft_strjoin(char *s1, char *s2);
char	**pars_ft_split(char *s, char c);
char	ft_strgtav(char *str, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strpaste(char *dst, char *src);
char	*ft_strdup(char *s1);
char	*rm_space(char *str);
int		put_in_out(t_node *node, char c);
int		put_hd_app(t_node *node, char c);
int 	put_cmd(t_node *node, int i);
void	ft_lstadd_back(t_node **lst, t_node *n);
void	initial_nodes(t_node *node);
void	*ft_calloc(size_t c, size_t s);
char	*ft_substr(char *s, int start, int len);

int		ft_infile_count(char *line);
int		ft_outfile_count(char *line);
int		ft_heredoc_count(char *line);
int		ft_append_count(char *line);
int		ft_size_all(char *str);
int		ft_all_redir_size(t_node *node);
int		is_meta(char c);
int		is_space(char c);
int     ignore_quotes(char *str);
char    *ft_strtrim(char *s1, char *set);
char    *ft_strcut(char *readline, char *str);
int     check_quote_2(t_node *node);
int     unexpected_tokens(t_node *p);
#endif
