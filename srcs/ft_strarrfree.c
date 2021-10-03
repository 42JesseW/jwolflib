#include "../includes/libft.h"

void		ft_strarrfree(char ***str)
{
	char	**p;
	int		idx;

	if (!(*str))
		return ;
	idx = 0;
	p = *str;
	while (p[idx] != NULL)
	{
		free((void *)p[idx]);
		idx++;
	}
	free(p);
	*str = NULL;
}
