#include "minishell.h"

void	cmd_exit(char** cmd)
{
	int dig;

	dig = 255;
	if (cmd[1])
	{
		if (ft_isdigit(cmd[1][0]))
		{
			dig = ft_atoi(&cmd[1][0]) % 256;
			printf("%d", dig);
		}
	}
	exit(0);
}