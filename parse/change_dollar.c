/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:44:13 by tyenokya          #+#    #+#             */
/*   Updated: 2023/02/19 15:20:28 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_fill(char *str, int start, int end, char *replace)
{	
	int		i;
	int		k;
	char	*fill;

	k = 0;
	i = 0;
	if (!str)
		return (0);
	fill = ft_calloc(sizeof(char),
			ft_strlen(str) - (end - start) + ft_strlen(replace) + 1);
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

static char	*replace(char *str,int start, int end, t_env *en)
{
	
	char	*s;
	
	s = ft_substr(str, start, ft_strlen(str) - ft_strlen(str + end));
	
	
	while (en)
	{
		if (!ft_strcmp(en->key, s))
			return (en->value);
		en = en->next;
	}
	free (s);
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
//echo "'$PWD'" chi ashxatum worovhetev replace funkcyayin PWD' a poxancum strcmp aneluc chi gtnum dra hamara ' menak tpum chem karum argumenty poxem worovhetev builtinnerum shat es et funkcyan ogtagorcum
char	*change_doll(char *str, t_env **en)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	while (str && str[i])
	{
		print_doll(str, &i);
		if (str[i] == '$' && str[i + 1] && (str[i + 1] == '_' || ft_isalpha(str[i + 1]) || str[i + 1] == '?'))// ?-i depqy woncor grac chi
		{																					//?i pahy ashxatuma bayc woch 1in angamic
			start = i;
			if (str[i] && !print_doll(str, &i))
			{
				++i;
				while (str[i] && str[i + 1] && str[i + 1] != '\'' && str[i + 1] != '\"' && str[i + 1] != ' ' && (str[i + 1] != '$' || !is_meta(str[i + 1])))//metacharacterov petqa woncor stugel
					++i;
				end = i;
				str = ft_fill(str, start, end + 1, replace(str, start+1, end, *en));
	
			}
		}
		if (str && str[i])
			i++;
	}

	return (str);
}
