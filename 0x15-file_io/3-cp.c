#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *bufer;

	bufer = malloc(sizeof(char) * 1024);

	if (bufer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (bufer);
}

/**
 * close_file - Closes all file descriptors.
 * @fd: file descriptor to close.
 */
void close_file(int fd)
{
	int a;

	a = close(fd);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - this copies the contents of a file to another file.
 * @argc: The number of arguments to suppli for the program.
 * @argv: array of pointers to the arguments.
 *
 * Return: if success return 0.
 *
 * Description: exit code 97 - If the argument count is not correct
 *              exit code 98. - If file_from does not exist or cannot be read
 *              exit code 99. - If file_to cannot be created or written to
 *              exit code 100.- If file_to or file_from cannot be closed
 */
int main(int argc, char *argv[])
{
	int from, to, ri, wr;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	ri = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || ri == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		wr = write(to, buffer, ri);
		if (to == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		ri = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (ri > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

