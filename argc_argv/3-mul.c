#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers passed as arguments
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 *
 * Return: 0 on success, 1 if fewer or more than two arguments are passed
 */
int main(int argc, char *argv[])
{
	int a, b, prod;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	prod = a * b;
	printf("%d\n", prod);

	return (0);
}
