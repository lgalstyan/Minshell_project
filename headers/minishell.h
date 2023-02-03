/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:44:17 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/03 17:36:57 by tyenokya         ###   ########.fr       */
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

int		checkquotes(char *str);
char	ft_strgtav(char *str, int c);
void	ft_lstadd_back(t_node **lst, t_node *new_env);
void	ft_lstadd_back_env(t_env **lst, t_env *new_env);
void	ft_inint_env(char *elem1, char *elem2, t_env *node);
void	ft_strfind(char *str, t_env **en);
int		builtin(t_node node, t_env **en);
int		is_builtin(char *cmd);
int		cmd_pwd();
int     print_exit_code();
int		cmd_cd(t_node node, t_env **en);
void	cmd_echo(t_node n, t_env **en);
void	cmd_export(t_node n, t_env **en);
void	cmd_exit(char** cmd);
void	cmd_unset(char *del_env, t_env **env);
void	print_list(t_env **node);
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
int     ft_lstsize(t_node *lst);
void    ft_pipe(t_node *node, t_env **envir);
void	print_node(t_node *node);

//parser.h

t_node	*cut_redir(t_node *node);
char	*pars_ft_strjoin(char *s1, char *s2);
char	**pars_ft_split(char *s, char c);
int		put_in_out(t_node *node, char c);
int		put_hd_app(t_node *node, char c);
int 	put_cmd(t_node *node, int i);
void	initial_nodes(t_node *node);
int		ft_infile_count(char *line);
int		ft_outfile_count(char *line);
int		ft_heredoc_count(char *line);
int		ft_append_count(char *line);
int		ft_size_all(char *str);
int		ft_all_redir_size(t_node *node);
char    *ft_strcut(char *readline, char *str);
int		is_meta(char c);
int		is_space(char c);
int     ignore_quotes(char *str);
int     check_quote_2(t_node *node);
int     unexpected_tokens(t_node *p);
void	ft_list_add_back(t_node **lst, t_node *new);
#endif
