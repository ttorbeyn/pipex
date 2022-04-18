#include "../pipex.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*new;

	i = 0;
	len = ft_strlen(s1);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
