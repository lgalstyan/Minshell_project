#include "libft.h"

static int	cnt_word(char *str, char delim)
{
	int	prev_del;
	int	i;
	int	count;

	i = 0;
	count = 0;
	prev_del = 1;
	while (str[i])
	{
		if (str[i] == delim)
			prev_del = 1;
		else if (prev_del)
			count++;
		if (str[i] != delim)
			prev_del = 0;
		i++;
	}
	return (count);
}

static char	*ml(char *s, int st, int len)
{
	char	*tab;
	int	i;

	i = 0;
	tab = malloc(len + 1);
	if (!tab)
		return (NULL);
	while (s[st] && i < len)
	{
		tab[i] = s[st];
		st++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static void	*fr(char **s, int i)
{
	while (i > 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (0);
}

char	**ft_split(char *s, char c)
{
	int	i;
	char	**tab;
	int	start;
	int	end;

	start = 0;
	end = 0;
	i = -1;
	tab = malloc(sizeof(char *) * (cnt_word (s, c) + 1));
	if (!(tab) || !s)
		return (0);
	while (++i < cnt_word (s, c))
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		tab[i] = ml(s, start, end - start);
		if (!tab[i])
			fr (tab, i);
		start = end;
	}
	tab[i] = 0;
	return (tab);
}