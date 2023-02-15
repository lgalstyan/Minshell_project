#include "minishell.h"

char *ft_fill(char *str, int start, int end, char *replace)
{
	int		i;
	int		k;
	char	*fill;

	k = 0;
	i = 0;
	// if (!str)
	// 	return (0);
	fill = ft_calloc(sizeof(char), ft_strlen(str) - (end - start) + ft_strlen(replace));
	while (str && str[i] && i < start)
	{
		fill[i] = str[i];
		++i;
	}
	while (replace && replace[k])
	{
		fill[i] = replace[k];
		++i;
		++k;
	}
	while (str && str[end])
	{
		fill[i] = str[end];
		++i;
		++end;
	}
	fill[i] = '\0';
	free(str);
	return (fill);
}

static char	*replace(char *str, t_env *en)
{
	while (en)
	{
		if (!ft_strcmp(en->key, str))
			return (en->value);
			// printf("value = %s\n", en->value);
		en = en->next;
	}
	return (0);
}

int	print_doll(char *str, int *i)
{
	if (str[*i] == '$' && (!str[*i + 1] || (is_space(str[*i]))))
	{
		printf("$");
		i++;
		return (1);
	}
	return (0);
}

// static void	assist(char **str, int i, t_env **en)
// {
// 	int	start;
// 	int	end;

// 	start = i;
// 	// while (str[i] != ' ' || str[i] != '$')
// 		// ++i;
// 	if (*str[i] == '$')
// 	{
// 		start = i;
// 		if (i++ && *str[i] && !print_doll(*str, &i))
// 		{
// 			while (*str[i] != ' ' || *str[i] != '$')
// 				++i;
// 			end = i;
// 			*str = ft_fill(*str, start, end, replace(*(str + i), *en));
// 		}
// 	}
// 	// end = i;
// 	// str = ft_fill(str, start, end, replace(str + i, *en));
// }


char	*change_doll(char *str, t_env **en)
{
	int		i;
	int		start;
	char	*word;
	int	end;

	//(void)en;
	i = 0;
	start = 0;
	word = NULL;
	while (str && str[i])
	{
		//printf("str - %s, str[i] - %c\n", str, str[i]);
		print_doll(str, &i);
		if (str[i] == '$')
		{
			start = i;
			// if (str[i])
			// 	write(1, "h\n", 2);
			if (str[i] && !print_doll(str, &i))
			{
				++i;
			//printf("stri -%c, i = %d\n", str[i], start);
				//write(1, "h\n", 2);	
				while (str[i] && (str[i] != ' ' || str[i] != '$'))
					++i;
				end = i;
				str = ft_fill(str, start, end, replace(str + start + 1, *en));
				//printf("doll str |%s|\n", str);
			}
		// {
		// 	i++;
		// 	//assist(str, i, en);
		// 	start = i;
		// 	while (str[i] && check_valid(str[i]))
		// 		i++;
		// 	word = ft_substr(str, start, i - start);
		}
		i++;
		//write(1, "kuku\n", 5);
		// if (str[i] == '\'')
		// {
		// 	++i;
		// 	while (str[i] && str[i] != '\'')
		// 		++i;
		// }
		// if (str[i] == '\"')
		// {
		// 	// if (str[i] == '$')
		// 		assist(&str, i, en);
		// 	// if (str[i] == '$')
		// 	// {
		// 	// 	start = i;
		// 	// 	if (i++ && str[i] == '?')
		// 	// 		++i;
		// 	// 	if (str[i] && !print_doll(str, &i))
		// 	// 	{
		// 	// 		while (str[i] != ' ' || str[i] != '$')
		// 	// 			++i;
		// 	// 		end = i;
		// 	// 		str = ft_fill(str, start, end, replace(str + i, en));
		// 	// 	}
		// 	// }
		// }
	}
	// printf("repleced is->%s\n", str);
	return (str);
}