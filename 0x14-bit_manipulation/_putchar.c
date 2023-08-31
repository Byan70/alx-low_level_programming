#include "main.h"
#include <unistd>
/**
 * _putchar -write the character c to stout 
 * @c: thecharacter to print
 *
 * Return:On success 1.
 * on error, -1 is returned,and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
 
