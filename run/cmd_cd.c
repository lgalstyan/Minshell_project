#include "minishell.h"

void	add_oldpwd(char *path, t_env **en)
{
	t_env	*new_env;

	new_env = malloc(sizeof(t_env));
	if (!search_list(*en, "OLDPWD"))
	{
		ft_inint_env("OLDPWD", path, new_env);
		ft_lstadd_back(en, new_env);
	}
	else
		update_list_item(en, "OLDPWD", path);
}

int	cmd_cd(t_node node, t_env **en)
{
	char	*path;

	if ((!node.cmd[1]) || ft_strcmp(node.cmd[1], "~") == 0)
	{
		if(!chdir(search_list(*en, "HOME")))
		{
			add_oldpwd(search_list(*en, "HOME"), en);
			return (0);
		}
		else
			return (-1);
	}
	else if (node.cmd[1])
	{
		path = get_current_path();
		add_oldpwd(path, en);
		if(!chdir(node.cmd[1]))
			return (0);
		else
			return (-1);
	}
	return (0);
}
