#include "minishell.h"

// stanum e char **, stugum e te inch hramar e u kanchum e hamapatasxany 
void	switch_commands(t_node node)
{
	if (!ft_strcmp(node.cmd[0], "echo"))
	{
		printf("->echo<-");
		//cmp_echo();
	}
	if (!ft_strcmp(node.cmd[0], "cd"))
	{
		printf("-> cd <-");
		//cmp_cd();
	}
	else if (!ft_strcmp(node.cmd[0], "pwd"))
	{
		printf("-> pwd <-");
		// cmp_pwd();
	}
	else if (!ft_strcmp(node.cmd[0], "export"))
	{
		printf("-> export <-");
		//cmp_export();
	}
	else if (!ft_strcmp(node.cmd[0], "unset"))
	{
		printf("-> unset <-");
		//cmp_unset();
	}
	else if (!ft_strcmp(node.cmd[0], "env"))
	{
		printf("-> env <-");
		//cmp_env();
	}
	else if (!ft_strcmp(node.cmd[0], "exit"))
	{
		printf("-> exit <-");
		//cmp_exit();
	}
}