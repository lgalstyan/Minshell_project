#include "minishell.h"

// stanum e char **, stugum e te inch hramar e u kanchum e hamapatasxany

void	switch_commands(t_node node, t_env **en)
{
	if (!ft_strcmp(node.cmd[0], "echo"))
	{
		printf("                      -> echo <-\n");
		cmd_echo(node, en);
	}
	else if (!ft_strcmp(node.cmd[0], "cd"))
	{
		printf("                      -> cd <-\n");
		//cmp_cd();
	}
	else if (!ft_strcmp(node.cmd[0], "pwd"))
	{
		printf("                      -> pwd <-\n");
		cmd_pwd();
	}
	else if (!ft_strcmp(node.cmd[0], "export"))
	{
		printf("                      -> export <-\n");
		cmd_export(node.cmd[1], en);
	}
	else if (!ft_strcmp(node.cmd[0], "unset"))
	{
		printf("                      -> unset <-\n");
		cmd_unset(node.cmd[1], *en);
	}
	else if (!ft_strcmp(node.cmd[0], "env"))
	{
		printf("                      -> env <-\n");
		print_list(en);
	}
	else if (!ft_strcmp(node.cmd[0], "exit"))
	{
		printf("                      -> exit <-\n");
		//cmd_exit();
	}
	else {
		printf("                      -> unknown commands <-\n");
	}
}