#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int num_printed;
	va_list args;
	int printed_chars;
	char buffer[1024];
	int i, num;
	unsigned int binary_num;
	unsigned int uint_num;

	var_start(args, format);
	printed_chars = 0;
	binary_num = 0;
	i = 0;
	num = 0;
	uint_num = 0;

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
				case 'u':
					uint_num = va_arg(args, unsigned int);
					printed_chars += sprintf(&buffer[printed_chars], "%u", uint_num);
					break;
				case 'x':
					uint_num = va_arg(args, unsigned int);
					printed_chars += sprintf(&buffer[printed_chars], "%x", uint_num);
					break;
				case 'X':
					uint_num = va_arg(args, unsigned int);
					printed_chars += sprintf(&buffer[printed_chars], "%X", uint_num);
					break;
				case 'o':
					uint_num = va_arg(args, unsigned int);
					printed_chars += sprintf(&buffer[printed_chars], "%o", uint_num);
					break;
				case 'b':
					binary_num = va_arg(args, unsigned int);
					printed_chars += print_binary(&buffer[printed_chars], binary_num);
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
			if (printed_chars == 1024)
			{
				write(1, buffer, printed_chars);
				printed_chars = 0;
			}
			i++;
	}
		va_end(args);
		write(1, buffer, printed_chars);
		return (printed_chars);
}
/**
 * print_binary - converts unsigned int to binary
 * @buffer: pointer to buffer
 * @num: unsigned int
 *
 * Return: returns no of chars
 */
int print_binary(char *buffer, unsigned int num)
{
	if (num / 2)
		print_binary(buffer, num / 2);
	*buffer = (num % 2) + '0';
	return (1);
}
