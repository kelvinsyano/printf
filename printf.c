#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int num_printed;
	va_list args;

	var_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (*format)
			{
				case 'c':
					buffer[printed_chars++] = (char) va_arg(args, int);
					break;
				case 's':
					printed_chars += sprintf(&buffer[printed_chars], "%s", va_arg(args, char *));
					break;
				case '%':
					buffer[printed_chars++] = '%';
					break;
				case 'd':
				case 'i':
					num = va_arg(args, int);
					printed_chars += sprintf(&buffer[printed_chars], "%d", num);
					break;
				default:
					buffer[printed_chars++] = '%';
					if (format[i] != '\0')
						buffer[printed_chars++] = format[i];
					break;
			}
		}
			else
			{
				buffer[printed_chars++] = format[i];
			}
			i++;
	}
		va_end(args);
		fwrite(buffer, 1, printed_chars, stdout);
		return (printed_chars);
}
