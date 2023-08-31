#include "main.h"

/**
 * set_bit - sets a bit at a given index to 1
 * @n: the pointer to the number to replace
 * @index: the index of the bit to put to 1
 *
 * Return: for success return 1 and for failure -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}

