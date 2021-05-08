#include <libft.h>

void		str_arr_free(char **str)
{
	int	idx;

	if (!str)
		return ;
	idx = 0;
	while (str[idx] != NULL)
	{
		free((void *)str[idx]);
		idx++;
	}
	free(str);
}

