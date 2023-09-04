#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- read text file to print to the STDOUT.
 * @filename: the text file to read
 * @letters: the number of letters to be read
 * Return: w- the actual number of bytes to read and print
 *        0 if function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t wr;
	ssize_t r;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	r = read(fd, buf, letters);
	wr = write(STDOUT_FILENO, buf, r);

	free(buf);
	close(fd);
	return (wr);
}
