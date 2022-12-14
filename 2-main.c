#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "malloc.h"

#define LOWER 1
#define UPPER 1000000000
#define ITERATIONS 100

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	char *str;
	int i;
	size_t s;
	void *chunk;

	setbuf(stdout, NULL);
	printf("Starting break is %p\n", sbrk(0));
	srand(time(0));
	for (i = 0; i < ITERATIONS; i++)
	{

		s = LOWER + (rand() % (UPPER - LOWER + 1));
		printf("%lu\n", s);
		str = _malloc(s);
		strcpy(str, "Holberton");
		str[21] = '\0';
		printf("%p: %s, ", (void *)str, str);
		chunk = (void *)(str - sizeof(size_t));
		printf("chunk addr: %p, ", (void *)chunk);
		printf("size: %lu, ", *((size_t *)chunk));
		_free(str);
		/* _free(str); */
		printf("break: %p\n", sbrk(0));
	}

	printf("Final break is %p\n", sbrk(0));
	print_heap();
	return (EXIT_SUCCESS);
}

