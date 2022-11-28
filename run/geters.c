#include "minishell.h"

char	*get_current_path()
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
		perror("getcwd() Error\n");
	return (path);
}