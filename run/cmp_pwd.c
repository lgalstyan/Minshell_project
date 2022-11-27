#include "minishell.h"

void	*get_path()
{
	char cwd[256];
	printf("%s\n", getcwd(cwd, sizeof(cwd)));
	return (0);
}

int	cmd_pwd()
{
	char cwd[256];

    if (!getcwd(cwd, sizeof(cwd)))
	{
		perror("getcwd() error");
		return (-1);
	}
	else
		get_path();
	  return 0;
}