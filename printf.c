#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int num_printed;
	va_list args;

	var_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					num_printed += printf("%c", va_arg(args, int));
					break;
				case 's':
					num_printed += printf("%s", va_arg(args, char *));
					break;
				case %:
					num_printed += putchar('%');
					break;
				default:
					putchar(*format);
					num_printed++;
					break;
			}
		}
			else
			{
				putchar(*format);
				num_printed++;
			}
			format++;
	}
		va_end(args);
		return (num_printed);
}
