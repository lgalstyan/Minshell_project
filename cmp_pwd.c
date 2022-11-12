#include "minishell.h"

void	cmp_pwd()
{
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
}