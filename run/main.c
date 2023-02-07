/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:10:37 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/07 17:02:57 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ignore_signals(void)
{
	// "Ctrl-C"
   	signal(SIGINT, SIG_IGN);
	// "Ctrl-Z"
    signal(SIGTSTP, SIG_IGN);
	// "Ctrl-\"
    signal(SIGQUIT, SIG_IGN);
}

static void	take_pars_val(t_node *node, t_env **envir)
{
	if (node->counts.s_pipe > 0)
		ft_pipe(node, envir);
	else
		commands(*node, envir);
}

void	shlvl(t_env **en)
{
	t_env	*curr;
	char	*value;

	curr = *en;
	value = NULL;
	while (curr)
	{
		if (!ft_strcmp(curr->key, "SHLVL"))
		{
			value = ft_strdup(curr->value);
			free(curr->value);
			curr->value = ft_itoa(ft_atoi(value) + 1);
			free(value);
		}
		curr = curr->next;
	}
}

void	readline_main(t_node *node, t_env *envir)
{
	char	*line;

	line = NULL;
	(void)envir;
	while (1)
	{
		printf(ESC_GREEN);
		line = readline("minishell :"ESC_WHITE);
		if (line[0])
			add_history(line);
		else
			continue ;
		node = lexer(line);
		if (!node)
			continue ;
		node = parser(node, &envir);
		if (!node)
			continue ;
		take_pars_val(node, &envir);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_node	*node;
	t_env	*envir;

	(void)argv;
	(void)argc;
	envir = NULL;
	node = NULL;
	rl_catch_signals = 0;
	environments(env, &envir);
	shlvl(&envir);
	readline_main(node, envir);
	return (0);
}
