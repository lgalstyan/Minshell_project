#include "minishell.h"

void ft_inint_env(char *elem1, char *elem2, t_env *node)
{
	node->key = elem1;
	node->value = elem2;
	node->next = NULL;
}

void environments(char **env, t_env **envir)
{
	int		i;
	char 	**array;
	t_env	*new_node;

	i = 0;
	while (env[i])
	{
		new_node = malloc(sizeof(t_env));
		array = ft_split(env[i], '='); 
		
		ft_inint_env(array[0], array[1], new_node);
		ft_lstadd_back_env(envir, new_node);
		++i;
	}
}

void ignore_signals()
{
	// "Ctrl-C"
   	signal(SIGINT, SIG_IGN);
	// "Ctrl-Z"
    signal(SIGTSTP, SIG_IGN);
	// "Ctrl-\"
    signal(SIGQUIT, SIG_IGN);
}

int prompt(t_node node, t_env **env, char ** envir)
{
	int status;

	status = 0;
	if (!is_builtin(node.cmd[0]))
	{
		builtin(node, env);
	}
	else if(execve(node.cmd[0], node.cmd, envir) != 0)
	{
		printf("minishell: %s: command not found", node.cmd[0]);
		return (-1);
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	int status = 1;
	char *line;
	t_node node;
	t_env **envir;
	envir = malloc(sizeof(t_env*));
	*envir = NULL;

	environments(env, envir);
	int fd = open("./../dup.txt", O_CREAT | O_WRONLY);
	// if(fd < 0)
    //     printf("Error: File not found\n");
	// dup(fd);
	// ignore_signals();
	// dup2(fd, 1);
	// printf(BOLD_GREEN);
	while (1)
	{
		//execve();
		// system("leaks minishell");
		printf(ESC_GREEN);
		line = readline("minishell :"ESC_WHITE);
		if (line[0])
			add_history(line);
		else
			continue ;
		// parser_node();
		node.cmd = ft_split(line, ' '); //Tomayi grac parsy
		// printf("%s\n%s\n%s", node.cmd[0], node.cmd[1], node.cmd[2]);
		// status = builtin(node, envir);
		status = prompt(node, envir, env);
		write(fd, line, ft_strlen(line));
		// print_list(envir);
	}
	return (0);
}