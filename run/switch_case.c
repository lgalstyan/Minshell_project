#include "minishell.h"

// stanum e char **, stugum e te inch hramar e u kanchum e hamapatasxany

void	switch_commands(t_node node, t_env **en)
{
	if (!ft_strcmp(node.cmd[0], "echo"))
	{
		printf(BOLD_BLUE);
		cmd_echo(node, en);
	}	
	else if (!ft_strcmp(node.cmd[0], "cd"))
		printf("%s\n",getcwd(node.cmd[1], ft_strlen(node.cmd[1])));
	else if (!ft_strcmp(node.cmd[0], "pwd"))
		cmd_pwd();
	else if (!ft_strcmp(node.cmd[0], "export"))
		cmd_export(node.cmd[1], en);
	else if (!ft_strcmp(node.cmd[0], "unset"))
		cmd_unset(node.cmd[1], en);
	else if (!ft_strcmp(node.cmd[0], "env"))
		print_list(en);
	else if (!ft_strcmp(node.cmd[0], "exit"))
		cmd_exit();
	else 
		printf("%s: command not found\n", node.cmd[0]);
}