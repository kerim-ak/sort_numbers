#include "../inc/push_swap.h"

static int	count_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	return (i);
}

static int	counter(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (ft_strlen(s) == 0)
		return (0);
	if ((int)ft_strlen(s) == count_spaces(s))
		return (0);
	while (i < (int)ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	if (s[0] != c && s[0] != '\0')
		return (count + 1);
	return (count);
}

static char	*word_picker(char *s, char c)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	i = 0;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (s[i] != c && s[i] != '\0')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static void	ft_free_list(char **list)
{
	int	i;

	i = 0;
	if (list == NULL)
		return ;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

char	**split(char *s, char c)
{
	char	**list;
	char	*temp;
	int		k;

	k = 0;
	list = (char **)malloc((counter(s, c) + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	while (*s && counter(s, c))
	{
		if (*s != c)
		{
			temp = word_picker(s, c);
			list[k++] = temp;
			if (!temp)
			{
				ft_free_list(list);
				return (NULL);
			}
			s += (int)ft_strlen(temp) - 1;
		}
		s++;
	}
	list[k] = NULL;
	return (list);
}
