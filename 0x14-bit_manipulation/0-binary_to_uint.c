#include "main.h"
/**
 * binary_to_unit-cnvert a binary number to a unsigned int
 * @b:sting that contains the binary number
 *
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	int de_valu = 0;

	if (!b)
		return (0);
	for (i = 0 ; b[i] ; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		de_valu = 2 * de_valu + (b[i] - '0');
	}
	return (de_valu);
}

