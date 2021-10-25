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

Test(strnjoin, combine_multiple)
{
/*
	str = ft_strnjoin(5, "one", "-", "two", "-", "three");
	printf("[5] one-two-three: %s\n", str);
	free(str);
	str = ft_strnjoin(0);
	printf("[0] : %s\n", str);
	free(str);
	str = ft_strnjoin(3, "one ", NULL, " two");
	printf("[3] one NULL two: %s\n", str);
	free(str);
	str = ft_strnjoin(3, NULL, "one ", " two");
	printf("[3] NULL one two: %s\n", str);
	free(str);
	str = ft_strnjoin(3, "one ", " two", NULL);
	printf("[3] one NULL two: %s\n", str);
	free(str);
*/
}

Test(strnjoin, combine_zero)
{

}

Test(strnjoin, combine_multiple_with_null)
{

}

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
