#include "main.h"

/**
 * _printf - function produces output according to format
 * @format: Character string
 * @%: special character specifier
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	int str_print = 0;
	va_list ls_args;

	if (format == NULL)
		return (-1);
	va_start(ls_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			str_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				str_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(ls_args, int);

				write(1, &c, 1);
				str_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(ls_args, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;

				write(1, str, str_len);
				str_print += str_len;
			}
		}
		format++;
	}
	va_end(ls_args);
	return (str_print);
}
