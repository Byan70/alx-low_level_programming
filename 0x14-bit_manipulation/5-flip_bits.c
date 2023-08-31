#include "main.h"
/**
* flip_bits -it counts the number of bits to change
* to get from one number to another
* @n: the first number
* @m: the second number
*
* Return: the  number of bits to change
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int j, coun = 0;
	unsigned long int curent;
	unsigned long int exclusive = n ^ m;

	for (j = 63; j >= 0; j--)
	{
		curent = exclusive >> j;
		if (curent & 1)
			coun++;
	}
	return (coun);
}
