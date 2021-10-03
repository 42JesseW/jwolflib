#include "../includes/libft.h"
#include "../includes/printf.h"

int		ft_strarrexists(char **arr, char *str)
{
	int 	idx;

	if (!arr || !(*arr) || !str)
		return (0);
	idx = 0;
	while (arr[idx])
	{
		if (ft_strcmp(arr[idx], str) == 0)
			return (1);
		idx++;
	}
	return (0);
}
