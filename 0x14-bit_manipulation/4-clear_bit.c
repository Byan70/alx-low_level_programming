#include "main.h"
/**
* clear_bit - prints the value of a given bit to 0
* @n: the pointer to the number to change
* @index: the index of the bit to remove
*
* Return: return 1 success  and return  -1 if failure
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = (~(1UL << index) & *n);
		return (1);
}
