# jwolfLib

This library contains my personal libft library that I'm using throughout the
curriculum at [Codam](https://www.codam.nl/en/). It currently contains the following
functions:


## libc functions:

| Function   | prototype | header | Description |
|------------|-----------|--------|-------------|
| ft_atoi    |     ```int					ft_atoi(const char *str)```      |    libft.h    |      Convert a string to an integer       |
| ft_bzero   |     ```void				ft_bzero(void *s, size_t n)```      |    libft.h    |      Write zero-valued bytes       |
| ft_calloc  |     ```void				*ft_calloc(size_t nmemb, size_t size)```      |    libft.h    |      Allocate with malloc and fill block with null bytes using bzero       |
| ft_isalnum |     ```int					ft_isalnum(int c)```      |    libft.h    |      Check if number is a alphanumeric ascii character       |
| ft_isalpha |     ```int					ft_isalpha(int c)```      |    libft.h    |      Check if number is a alphabetical ascii character       |
| ft_isascii |     ```int					ft_isascii(int c)```      |    libft.h    |      Check if number is ascii character       |
| ft_isdigit |     ```int					ft_isdigit(int c)```      |    libft.h    |      Check if number is a digit ascii character      |
| ft_isprint |     ```int					ft_isprint(int c)```      |    libft.h    |      Check if number is a printable ascii character       |
| ft_itoa    |     ```char				*ft_itoa(int n)```      |    libft.h    |      Convert an integer to an ascii string       |
| ft_memccpy |     ```void				*ft_memccpy(void *s1, const void *s2, int c, size_t n)```      |    libft.h    |      Copy n bytes from s1 into s2, stop if int c is found       |
| ft_memchr  |     ```void				*ft_memchr(const void *s, int c, size_t n)```      |    libft.h    |      Scan memory for a character       |
| ft_memcmp  |     ```int					ft_memcmp(const void *s1, const void *s2, size_t n)```      |    libft.h    |      Compare memory byte by byte       |
| ft_memcpy  |     ```void				*ft_memcpy(void *dst, const void *src, size_t n)```      |    libft.h    |      Copy n bytes from s1 into s2       |
| ft_memmove |     ```void				*ft_memmove(void *s1, const void *s2, size_t n)```      |    libft.h    |      Copy memory byte by byte, taking into account memory overlap       |
| ft_memset  |     ```void				*ft_memset(void *b, int c, size_t len)```      |    libft.h    |      Set memory for len amount of byte with int c      |
| ft_strchr  |     ```char				*ft_strchr(const char *s, int c)```      |    libft.h    |      Scan a string for a character       |
| ft_strcpy  |     ```char				*ft_strcpy(char *dest, const char *src)```      |    libft.h    |      Copy a string from src to dest       |
| ft_strdup  |     ```char				*ft_strdup(const char *s)```      |    libft.h    |     Allocate a new block of strlen(s) and copy s into new string        |
| ft_strlcat |     ```size_t				ft_strlcat(char *dst, const char *src, size_t size)```      |    libft.h    |      Concatenate strings with extended safety checks       |
| ft_strlcpy |     ```size_t				ft_strlcpy(char *dst, const char *src, size_t size)```      |    libft.h    |      Copy a string from src to dest with extended safety checks       |
| ft_strlen  |     ```size_t				ft_strlen(const char *s)```      |    libft.h    |      Calculate the amount of characters in a string       |
| ft_strncmp |     ```int					ft_strncmp(const char *s1, const char *s2, size_t n)```      |   libft.h    |      Compare strings for n amount of bytes       |
| ft_strncpy |     ```char				*ft_strncpy(char *dest, const char *src, size_t n)```      |    libft.h    |      Copy a string from src to dest for n amount of bytes       |
| ft_strnstr |     ```char				*ft_strnstr(const char *s1, const char *s2, size_t n)```      |    libft.h    |      Locate a substring in a string        |
| ft_tolower |     ```int					ft_tolower(int c)```     |    libft.h    |      if isalpha(c) and isupper(c) then return corresponding lowercase       |
| ft_toupper |     ```int					ft_toupper(int c)```     |    libft.h    |      if isalpha(c) and islower(c) then return corresponding uppercase       |

## get_next_line
| Function      | Prototype | Header          | Description |
|---------------|-----------|-----------------|-------------|
| get_next_line |     ```int						get_next_line(int fd, char **line);```      | get_next_line.h |      A function which returns a line read from a file descriptor, without the newline.       |

The get_next_line function can be used in the following fashion:
1. to read from a file:
```c
#include <fcntl.h>
#include <stdio.h>
#include "includes/get_next_line.h"

int		main(void)
{
	int		fd;
	int		ret;
	char	*line;
	char	filename[] = "test.out";

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("[%d] %s\n", ret, line);
		if (line != NULL)
			free(line);
	}
	close(fd);
	return (0);
}
```

2. to read from stdin:
```c
#include <stdio.h>
#include "includes/get_next_line.h"

int		main(void)
{
	int		ret;
	char	*line;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		printf("[%d] %s\n", ret, line);
		if (line != NULL)
			free(line);
	}
	return (0);
}
```
```bash
> gcc main.c -Iincludes -L. -lft
> echo "testing123" | ./a.out
```

3. to read from multiple filedescriptors at the same time:
```c
#include <fcntl.h>
#include <stdio.h>
#include "includes/get_next_line.h"

int		main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		ret;
	char	*line;
	char	filename1[] = "test1.out";
	char	filename2[] = "test2.out";
	char	filename3[] = "test3.out";
	char	filename4[] = "test4.out";

	ret = 1;
	fd1 = open(filename1, O_RDONLY);
	fd2 = open(filename2, O_RDONLY);
	fd3 = open(filename3, O_RDONLY);
	fd4 = open(filename4, O_RDONLY);

	ret = get_next_line(fd1, &line);
	printf("[%d] %s\n", ret, line);
	ret = get_next_line(fd4, &line);
	printf("[%d] %s\n", ret, line);
	ret = get_next_line(fd2, &line);
	printf("[%d] %s\n", ret, line);
	ret = get_next_line(fd1, &line);
	printf("[%d] %s\n", ret, line);
	ret = get_next_line(fd3, &line);
	printf("[%d] %s\n", ret, line);
	ret = get_next_line(fd3, &line);
	printf("[%d] %s\n", ret, line);
	ret = get_next_line(fd4, &line);
	printf("[%d] %s\n", ret, line);
	ret = get_next_line(fd1, &line);
	printf("[%d] %s\n", ret, line);

	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}
```
```bash
> echo "test1.out line1\ntest1.out line2" >> test1.out
> echo "test2.out line1\ntest2.out line2" >> test2.out
> echo "test3.out line1\ntest3.out line2" >> test3.out
> echo "test4.out line1\ntest4.out line2" >> test4.out
> gcc main.c -Iincludes -L. -lft
> ./a.out
```

## printf
See printf [README.md](printf/README.md)

## other

| Function   | Prototype | Header  | Description                                                         |
|------------|-----------|---------|---------------------------------------------------------------------|
| ft_strjoin |    ```char				*ft_strjoin(char const *s1, char const *s2)```      | libft.h | Combine two strings in a new block of memory                        |
| ft_strtrim |    ```char				*ft_strtrim(char const *s1, char const *set)```       | libft.h | Trim a string using a string of specific characters                 |
| ft_strmapi |    ```char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))```       | libft.h | Run a function over each character in a string                      |
| ft_substr  |    ```char				*ft_substr(char const *s, unsigned int start, size_t len)```       | libft.h | Create a substring of a specified string                            |
| ft_split   |    ```char				**ft_split(char const *s, char c)```       | libft.h | Split a string into an array of strings using a delimiter character |