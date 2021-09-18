![Rigor](https://img.shields.io/badge/Rigor-306998) ![Algorithms&AI](https://img.shields.io/badge/Algorithms&AI-306998)

# ft_printf :computer:
The versatility of the printf function in C represents a great exercise in programming. This project is of moderate difficulty.

- [Evaluation](https://github.com/denisgodoy/42-ft_printf#evaluation)
- [Mandatory part](https://github.com/denisgodoy/42-ft_printf#mandatory-part)
- [Bonus part](https://github.com/denisgodoy/42-ft_printf#bonus-part)

## Evaluation
![Eval](https://user-images.githubusercontent.com/56933400/133869153-408f0012-a5f5-46b2-8858-e07cfa5b4d9d.png)
![Badge](https://user-images.githubusercontent.com/56933400/133869116-9eb91697-9860-45c5-8a00-c12b20567d17.png)

## Mandatory part

| Function 	|  Description  |    Library   	|    External functions   	|
|:--------:	|:------------:	|:------------:	|:------------:	|
|  ft_printf  	|Produces output to stdout, the standard output stream, according to a format as described below.|   stdio.h   	|  malloc, free, write, va_start, va_arg, va_copy, va_end   	|

The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments. — PRINTF(3)

| Format 	|  Description  |
|:--------:	|:------------:	|
|  %c  	|Print a single character.|
|  %s  	|Print a string of characters.|
|  %p  	|The void * pointer argument is printed in hexadecimal.|
|  %d  	|Print a decimal (base 10) number.|
|  %i  	|Print an integer in base 10.|
|  %x  	|Print a number in hexadecimal (base 16) - lowercase.|
|  %X  	|Print a number in hexadecimal (base 16) - uppercase.|
|  %%  	|Print a percent sign.|

## Bonus part
Managed the following flags:

| Flag 	|  Description  |
|:--------:	|:------------:	|
|  #  	|For `x` conversions, a nonzero result has the string "0x" (or "0X" for `X` conversions) prepended to it.|
|  `space` 	|A blank should be left before a positive number produced by a signed conversion (`d` or `i`).|
|  +  	|A sign (+ or -) should always be placed before a number produced by a signed conversion.|
