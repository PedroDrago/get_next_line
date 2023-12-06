#include "get_next_line_bonus.h"

int	has_break_line(const char *s)
{
	int		count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
	{
		if (s[count] == '\n')
			return (1);
		count++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		count;

	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	count = 0;
	if (s1)
	{
		while (s1[count])
		{
			joined[count] = s1[count];
			count++;
		}
		free (s1);
	}
	while (*s2)
		joined[count++] = *s2++;
	joined[count] = '\0';
	if (!(*joined))
	{
		free (joined);
		return (NULL);
	}
	return (joined);
}
