![Rigor](https://img.shields.io/badge/Rigor-306998) ![Algorithms&AI](https://img.shields.io/badge/Algorithms&AI-306998)

[IN PROGRESS]

# ft_printf :computer:
The versatility of the printf function in C represents a great exercise in programming. This project is of moderate difficulty.

### Mandatory part

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

### Bonus part
Managed the following flags:

| Flag 	|  Description  |
|:--------:	|:------------:	|
|  #  	|For `x` conversions, a nonzero result has the string "0x" (or "0X" for `X` conversions) prepended to it.|
|  `space` 	|A blank should be left before a positive number produced by a signed conversion (`d` or `i`).|
|  +  	|A sign (+ or -) should always be placed before a number produced by a signed conversion.|
