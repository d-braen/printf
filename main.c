#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;

    len = _printf("Let's count the letters.\n");
	printf("count: %d\n", len);
    len = _printf("%c %c %c\n", 'Y', 'e', 'A');
	printf("count: %d\n", len);
    len = _printf("%%%%%% %% %%%\n");
	printf("count: %d\n", len);
    return (0);
}
