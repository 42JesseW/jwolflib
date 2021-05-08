# printf

> Because putnbr and putstr aren’t enough

| Function  | Prototype | Header         | Description |
|-----------|-----------|----------------|-------------|
| ft_printf |    ```int			ft_printf(const char *format, ...)```       | printf/utils.h |      A function that will mimic the real printf       |

This printf implementation does not do buffer management like the real printf. It manages
the flags down below together with minimum field width for all conversions down below.

### Conversions

| Conversion | Data type                   | Description                                                                    |
|------------|-----------------------------|--------------------------------------------------------------------------------|
| %c         | int : unsigned char         | Write a character to stdout                                                    |
| %s         | char * : char *             | Write a string to stdout                                                       |
| %p         | void * : unsigned long      | Write a memory address to stdout                                               |
| %d         | int : int                   | Write an integer value to stdout                                               |
| %i         | int : int                   | Write an integer value to stdout                                               |
| %u         | unsigned int : unsigned int | Write an unsigned int to stdout                                                |
| %x         | unsigned int : unsigned int | Write an unsigned int to stdout in hexadecimal format                          |
| %X         | unsigned int : unsigned int | Write an unsigned int to stdout in hexadecimal format with capitalized letters |
| %%         | '%' : '%'                   | Write a '%' character to stdout                                                |

### Flags

* '+' : A sign (+ or -) should always be placed before a number produced by a signed conversion.
* ' ' : (a space) A blank should be left before a positive number (or empty string) produced by a signed conversion
* '#' : For x and X conversions, a nonzero result has the string "0x" (or "0X" for X conversions) prepended to it.
* '-' : The converted value is to be left adjusted on the field boundary.
* '0' : The  value  should be zero padded.
* '.' : An optional precision, in the form of a period ('.')  followed by an optional decimal digit string.

### Usage

Formats must always be done in the following order:
```
"%[FLAGS][WIDTH][PRECISION][CONVERSION]"
```

Some examples:
```c
#include "includes/printf/utils.h"

int		main(void)
{
	int	day = 7;
	int	month = 7;
	int year = 2020;
	int	err = 5;

	ft_printf("Hi, my name is %s and i'm celebrating my %d'th birthday\n", "jesse", 22);
	ft_printf("[%02d-%02d-%d] I'm writing a log for error %i at memory address %p\n", day, month, year, err, &err);
	ft_printf("01. %####--------+ 0000.13x\n", 255);
	ft_printf("01. %####--------+ 0000.13x\n", 255);
	return (0);
}
```