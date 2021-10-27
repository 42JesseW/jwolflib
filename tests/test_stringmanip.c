#include <criterion/criterion.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>

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
** strnjoin (variadic arguments NOT NORM)
*/

Test(strnjoin, combine_multiple)
{
	char	*str;

	str = ft_strnjoin(5, "one", "-", "two", "-", "three");
	cr_expect(strcmp(str, "one-two-three") == 0, "Pointer str should point to a new string");
	free(str);
}

Test(strnjoin, combine_zero)
{
	char	*str;

	str = ft_strnjoin(0);
	cr_expect_null(str, "Pointer str should be NULL if n=0");
	str = ft_strnjoin(0, "one", "two", "three");
	cr_expect_null(str, "Pointer str should be NULL if n=0");
}

Test(strnjoin, combine_multiple_with_null)
{
	char	*str;

	str = ft_strnjoin(3, "one ", NULL, " two");
	cr_expect(strcmp(str, "one  two") == 0, "strnjoin should ignore NULL strings");
	free(str);
	str = ft_strnjoin(3, NULL, "one ", " two");
	cr_expect(strcmp(str, "one  two") == 0, "strnjoin should ignore NULL strings");
	free(str);
	str = ft_strnjoin(3, "one ", " two", NULL);
	cr_expect(strcmp(str, "one  two") == 0, "strnjoin should ignore NULL strings");
	free(str);
}

/*
** strarrfree()
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
