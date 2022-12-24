#include "minishell.h"

void	cmd_exit(char arg)
{
	int dig;

	dig = 255;
	if (ft_isdigit(arg))
	{
		dig = ft_atoi(&arg) % 256;
		printf("%d", dig);
	}
	exit(0);
}