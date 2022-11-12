#include "minishell.h"

void	cmd_pwd()
{
	char cwd[256];

    if (!getcwd(cwd, sizeof(cwd)))
      perror("getcwd() error");
    else
      printf("%s\n", cwd);
}