#include "main.h"
/**
* get_endianness - we checks if a machine is little or big endian
* Return: 0 if it big, 1 if it little
*/
int get_endianness(void)
{
	unsigned int j = 1;
	char *a = (char *) &j;

	return (*a);
}
