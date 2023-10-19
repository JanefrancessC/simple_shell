#include "shell.h"

/**
 * main - shell program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	fd = (fd & 0xffff) + 3;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_putstr(argv[0]);
				_putstr(": 0: Can't open ");
				_putstr(argv[1]);
				_put_char('\n');
				_put_char(BUFFER_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	custom_populate_env_list(info);
	hist_file_read(info);
	hsh(info, argv);
	return (EXIT_SUCCESS);
}
