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
# include "commands.h"
# include "structs.h"

# define BLACK		 "\033[0;30m"
# define BOLD_BLACK  "\033[1;30m"
# define RED		 "\033[0;31m"
# define BOLD_RED	 "\033[1;31m"
# define GREEN 		 "\033[0;32m"
# define BOLD_GREEN  "\033[1;32m"
# define YELLOW 	 "\033[0;33m"
# define BOLD_YELLOW "\033[1;33m"
# define BLUE 		 "\033[0;34m"
# define BOLD_BLUE 	 "\033[1;34m"
# define PURPLE 	 "\033[0;35m"
# define BOLD_PURPLE "\033[1;35m"
# define CYAN 		 "\033[0;36m"
# define BOLD_CYAN   "\033[1;36m"
# define WHITE 		 "\033[0;37m"
# define BOLD_WHITE  "\033[1;37m"
# define RESET_COLOR "\033[0m"
# define ESC_BLACK		 "\001\033[0;30m"
# define ESC_BOLD_BLACK  "\001\033[1;30m\002"
# define ESC_RED 		 "\001\033[0;31m\002"
# define ESC_BOLD_RED 	 "\001\033[1;31m\002"
# define ESC_GREEN 		 "\001\033[0;32m\002"
# define ESC_BOLD_GREEN  "\001\033[1;32m\002"
# define ESC_YELLOW 	 "\001\033[0;33m\002"
# define ESC_BOLD_YELLOW "\001\033[1;33m\002"
# define ESC_BLUE 		 "\001\033[0;34m\002"
# define ESC_BOLD_BLUE   "\001\033[1;34m\002"
# define ESC_PURPLE 	 "\001\033[0;35m\002"
# define ESC_BOLD_PURPLE "\001\033[1;35m\002"
# define ESC_CYAN 		 "\001\033[0;36m\002"
# define ESC_BOLD_CYAN   "\001\033[1;36m\002"
# define ESC_WHITE 		 "\001\033[0;37m\002"
# define ESC_BOLD_WHITE  "\001\033[1;37m\002"
# define ESC_RESET_COLOR "\001\033[0m\002"
# define METACHARACTERS  "|&;()<> \n\t"
# define SPACES  " \n\t"

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
int		put_cmd(t_node *node, char *str, int s);
void	ft_lstadd_back(t_node **lst, t_node *new_env);
t_node	*initialize(char *str, t_node *node);
t_node	*ft_lstlast(t_node *lst);



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

#endif
