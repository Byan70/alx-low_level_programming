#include "main.h"

/**
 * get_bit - will returns the value of a bit at an index in a decimal number
 * @n: the number to find
 * @index: the index of the bit
 *
 * Return: the value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_valu;

	if (index > 63)
		return (-1);

	bit_valu = (n >> index) & 1;

	return (bit_valu);
}

