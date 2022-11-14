#include "minishell.h"


void ft_inint_env(char *elem1, char *elem2, t_env *node)
{
	node->key = elem1;
	node->value = elem2;
	node->next = NULL;
}

void print_list(t_env **node)
{

	while(*(node))
	{
		printf("%s=", (*node)->key);
		printf("%s\n", (*node)->value);
		(*node) = (*node)->next;
	}
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
		ft_lstadd_back(envir, new_node);
		++i;
	}
	// print_list(envir);
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

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	char *line;
	t_node node;
	t_env **envir;
	envir = malloc(sizeof(t_env*));
	*envir = NULL;
	int i  = 0; 
	environments(env, envir);
	int fd = open("./../dup.txt", O_CREAT | O_WRONLY);
	if(fd < 0)
        printf("Error: File not found\n");
	// dup(fd);
	// ignore_signals();
	// dup2(fd, 1);
	while (i < 5)
	{
		//execve();
		line = readline("Line :");
		// parser_node();
		node.cmd = &line;
		switch_commands(node);
		write(fd, line, ft_strlen(line));
		++i;
	}
	return (0);
}