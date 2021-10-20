#include "listfiles.h"
/**
 * main - ls
 * @argc: arguments count
 * @argv: argument array
 * Return: 0 sucess -1 on failure
 */
int main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *read;

	if (argc < 2)
	{
		dir = opendir(".");
	}
	else
	{
		dir = opendir(argv[1]);
	}
	if (dir == NULL)
	{
		printf("%s: cannot access '%s': No such file or directory\n",
			   argv[0], argv[1]);
		return (-1);
	}

	while ((read = readdir(dir)) != NULL)
	{
		if (strcmp(read->d_name, ".") != 0 && strcmp(read->d_name, "..") != 0)
			printf("%s\n", read->d_name);
	}

	closedir(dir);

	return (0);
}
