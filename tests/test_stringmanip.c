#include <criterion/criterion.h>
#include <time.h>
#include <stdlib.h>

#include "../includes/libft.h"

static char *rand_string(char *str, size_t size)
{
	const char	charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK...";
	int			key;

	if (size) {
		--size;
		for (size_t n = 0; n < size; n++) {
			key = rand() % (int) (sizeof charset - 1);
			str[n] = charset[key];
		}
		str[size] = '\0';
	}
	return (str);
}

/*
** void	ft_strarrfree(char ***str);
**
**	DESCRIPTION:
**		- A simple function that takes the memory address
**		  of an array of strings as its argument. It frees
**		  all char pointers inside of the array until it
**		  finds a NULL pointer. It then frees the original
**		  pointer and sets it to NULL.
*/

Test(strarrfree, nullvalue)
{
	char	**p = NULL;

	ft_strarrfree(&p);
	cr_expect_null(p, "Pointer p should not be affected by str_arr_free.");
}

Test(strarrfree, singlestring)
{
	char	**p;

	p = (char**)malloc(sizeof(char*) * 2);
	p[0] = (char*)malloc(sizeof(char));
	p[1] = NULL;
	ft_strarrfree(&p);
	cr_expect_null(p, "Pointer p should be NULL");
}

Test(strarrfree, multiplestrings)
{
	char	**p;
	char	*str;
	int		size;

	size = 4;
	srand(time(NULL));
	p = (char**)malloc(sizeof(char*) * size);
	for (int i = 0; i < size -1; i++) {
		str = (char*)malloc(sizeof(char) * size);
		p[i] = rand_string(str, size);
	}
	p[size - 1] = NULL;
	ft_strarrfree(&p);
	cr_expect_null(p, "Pointer p should be NULL");
}
