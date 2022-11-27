#include "minishell.h"

void	add_oldpwd(char *path, t_env **en)
{
	t_env	*new_env;

	new_env = malloc(sizeof(t_env));
	ft_inint_env("OLDPWD", path, new_env);
	ft_lstadd_back(en, new_env);
}

//if (cd ~ || cd ) => to HOME
int	cmd_cd(t_node node, t_env **en)
{
	char cwd[256];

	if ((!node.cmd[1]) || ft_strcmp(node.cmd[1], "~") == 0)
	{
		if(!chdir(search_list(*en, "HOME")))
		{
			add_oldpwd(search_list(*en, "HOME"), en);
			return (1);
		}
		else
			return (-1);
	}
	else if (node.cmd[1])
	{
		add_oldpwd(getcwd(cwd, sizeof(cwd)), en);
		printf("%s\n", getcwd(cwd, sizeof(cwd)));
		if(!chdir(node.cmd[1]))
			return (1);
		else
			return (-1);
	}
	return (0);
}


