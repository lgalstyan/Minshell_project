#include "minishell.h"

// int main( int argc, char **argv, char **envp)
// {
//     int numberLines = 0;
//     if ( (argc == 2) && strcmp(argv[1], "/n" ) == 0 )
//          numberLines = 1;

//     for ( int i = 0; envp[i] != NULL; ++i )
//     {
//         if ( numberLines )
//             printf("%d : ", i);
//         printf("%s\n", envp[i]);
//     }
// 	return (0);
// }

void ignore_signals()
{
	// "Ctrl-C"
   	signal(SIGINT, SIG_IGN);
	// "Ctrl-Z"
    signal(SIGTSTP, SIG_IGN);
	// "Ctrl-\"
    signal(SIGQUIT, SIG_IGN);
}

void environments(char **env, t_env *envir)
{
	int	i;
	i = 0;
	while (env[i])
	{
		printf("%s", env[i]);
		i++;
	}
}

int main(int argc, char **argv, char **env)
{
	char *line;
	t_node node;
	t_env *envir;
	envir = malloc(sizeof(t_env));
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