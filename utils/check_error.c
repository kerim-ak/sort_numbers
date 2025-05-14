#include "../inc/push_swap.h"

static int	check_char_error(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] != '+' || s[i] != '-'))
			return (1);
		i++;
	}
	return (0);
}

int	check_error(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (check_char_error(str))
		return (1);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i != len)
		return (1);
	if (len == 1 && (str[0] == '-' || str[0] == '+'))
		return (1);
	return (0);
}
