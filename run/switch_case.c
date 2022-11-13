#include "minishell.h"

// stanum e char **, stugum e te inch hramar e u kanchum e hamapatasxany 
void	switch_commands(t_node node)
{
	if (!ft_strcmp(node.cmd[0], "echo"))
	{
		printf("                      -> echo <-\n");
		//cmd_echo(node);                         //????????????harc Tomayin "vortexa pahvac linelu echo -ic heto ekox toxy?????????" ||| vortex en pahvelu optionnery
	}
	if (!ft_strcmp(node.cmd[0], "cd"))
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
		//cmp_export();
	}
	else if (!ft_strcmp(node.cmd[0], "unset"))
	{
		printf("                      -> unset <-\n");
		//cmp_unset();
	}
	else if (!ft_strcmp(node.cmd[0], "env"))
	{
		printf("                      -> env <-\n");
		//cmd_env();
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