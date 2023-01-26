// #include "parser.h"

// static void	clean_quotes_helper(char **res, char *tmp, int *i, int *k)
// {
// 	char	c;
// 	int		j;

// 	j = 0;
// 	while (res[*i][j])
// 	{
// 		while (res[*i][j] && (!ft_strchr("\'\"", res[*i][j])
// 			|| res[*i][j + 1] == UNPRINTABLE))
// 			tmp[(*k)++] = res[*i][j++];
// 		if (res[*i][j] == '\0')
// 			break ;
// 		c = res[*i][(j)++];
// 		while (res[*i][j] && res[*i][j] != c)
// 			tmp[(*k)++] = res[*i][j++];
// 		if (res[*i][j])
// 			j++;
// 	}
// }

// static int	clean_quotes(char ***arr)
// {
// 	int		i;
// 	char	**res;
// 	int		k;
// 	char	*tmp;

// 	res = *arr;
// 	if (*arr == NULL)
// 		return (0);
// 	i = 0;
// 	while (res[i])
// 	{
// 		k = 0;
// 		tmp = malloc(ft_strlen(res[i]) + 1);
// 		if (tmp == NULL && !ft_perror("minishell: malloc: "))
// 			exit (1);
// 		clean_quotes_helper(res, tmp, &i, &k);
// 		tmp[k] = '\0';
// 		tmp = clean_unprintable(tmp);
// 		free_arr(&res[i]);
// 		res[i] = tmp;
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_clean_all_qutoes(t_spl_pipe *head)
// {
// 	while (head)
// 	{
// 		clean_quotes(&head->cmd);
// 		clean_quotes(&head->heredoc);
// 		head = head->next;
// 	}
// 	return (0);
// }

// int	clean_quotes_single_arr(char **s)
// {
// 	char	c;
// 	int		i;
// 	char	*res;
// 	char	*tmp;

// 	i = 0;
// 	tmp = *s;
// 	res = malloc(ft_strlen(tmp) + 1);
// 	if (res == NULL && !ft_perror("minishell: malloc: "))
// 		exit (1);
// 	while (*tmp)
// 	{
// 		while (*tmp && (!ft_strchr(QUOTES, *tmp) || *(tmp + 1) == UNPRINTABLE))
// 			res[i++] = *tmp++;
// 		if (*tmp == '\0')
// 			break ;
// 		c = *tmp++;
// 		while (*tmp && *tmp != c)
// 			res[i++] = *tmp++;
// 		if (*tmp)
// 			tmp++;
// 	}
// 	res[i] = free_arr(s);
// 	*s = clean_unprintable(res);
// 	return (0);
// }