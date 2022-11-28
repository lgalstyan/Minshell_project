#include "minishell.h"

int	cmd_pwd()
{
	char cwd[256];

    if (!getcwd(cwd, sizeof(cwd)))
	{
		perror("getcwd() error");
		return (-1);
	}
	else
		printf("%s\n", get_current_path());
		//get_path();
	  return 0;
}