#include <stdio.h>
#include "variadic_functions.h"

/**
* print_char - prints a char argument
* @args: va_list pointing to the argument
* @sep: separator string
*
* Return: nothing
*/
void print_char(va_list args, char *sep)
{
printf("%s%c", sep, va_arg(args, int));
}

/**
* print_int - prints an int argument
* @args: va_list pointing to the argument
* @sep: separator string
*
* Return: nothing
*/
void print_int(va_list args, char *sep)
{
printf("%s%d", sep, va_arg(args, int));
}

/**
* print_float - prints a float argument
* @args: va_list pointing to the argument
* @sep: separator string
*
* Return: nothing
*/
void print_float(va_list args, char *sep)
{
printf("%s%f", sep, va_arg(args, double));
}

/**
* print_str - prints a string argument or (nil) if NULL
* @args: va_list pointing to the argument
* @sep: separator string
*
* Return: nothing
*/
void print_str(va_list args, char *sep)
{
char *str;

str = va_arg(args, char *);
if (str == NULL)
{
printf("%s(nil)", sep);
return;
}
printf("%s%s", sep, str);
}

/**
* print_all - prints anything according to format specifiers
* @format: list of types of arguments passed to the function
*
* Return: nothing
*/
void print_all(const char * const format, ...)
{
va_list args;
unsigned int i = 0, j;
char *sep = "";
char spec[] = {'c', 'i', 'f', 's'};
void (*funcs[])(va_list, char *) = {
print_char, print_int, print_float, print_str
};

va_start(args, format);

while (format != NULL && format[i] != '\0')
{
j = 0;
while (j < 4)
{
if (format[i] == spec[j])
{
funcs[j](args, sep);
sep = ", ";
}
j++;
}
i++;
}

va_end(args);
printf("\n");
}
