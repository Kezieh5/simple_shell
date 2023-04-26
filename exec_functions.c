#include "shell.h"

/**
 * _exec - executes a command
 * @av: arguments passed to the function
 * @full_path: full path of the command
 * @buffer: buffer containing the command
 * @st: status of the command
 *
 * Return: int (status)
 */
int _exec(char **buffer, char ***av, char *full_path, int *st)
{
	int child_pid, ex, status;

	if (*av == NULL)
		return (1);

	if (**buffer == '\n' || full_path == NULL)
	{
		free(*av);
		return (1);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (-1);
	}
	if (child_pid == 0)
	{
		ex = execve(full_path, *av, environ);
		if (ex == -1)
		{
			free(*av);
			free(*buffer);
			exit(99);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			*st = WEXITSTATUS(status);
	}

	free(*av);
	free(full_path);
	return (1);
}

/**
 * check_path - checks if the command is in the PATH
 * @av: arguments passed to the function
 * @path: path of the command
 * @tokens: tokens of the path
 * @count: number of times the shell has been executed
 * @error: error
 *
 * Return: void
 */
void check_path(char ***tokens, char **path, char **av, int *cnt, int *err)
{
	char *first = NULL, buffer[33], *msg = NULL;

	if (*path != NULL || *tokens == NULL)
		return;

	first = *(tokens)[0];

	if (access(first, F_OK | X_OK) == 0)
		*path = _strdup(first);
	else
	{
		if (access(first, F_OK) != 0)
		{
			msg = "not found\n";
			pfError(av[0], itoa(*cnt, buffer, 10), first, msg);
			*err = 127;
		}
		else if (access(first, X_OK) != 0)
		{
			msg = "Permission denied\n";
			pfError(av[0], itoa(*cnt, buffer, 10), first, msg);
			*err = 126;
		}
	}
}

/**
 * check_dir - checks if the command is in the current directory
 * @av: arguments passed to the function
 * @path: path of the command
 * @tokens: tokens of the path
 * @count: number of times the shell has been executed
 * @error: error
 *
 * Return: void
 */
void check_dir(char ***tokens, char **path, char **av, int *count, int *error)
{
	struct stat st;
	char *first = NULL, buffer[33], *msg = NULL;

	if (*tokens == NULL)
		return;

	first = *(tokens)[0];

	if (stat(first, &st) == 0)
	{
		if ((st.st_mode & S_IFMT) == S_IFDIR)
		{
			msg = "Permission denied\n";
			pfError(av[0], itoa(*count, buffer, 10), first, msg);
			*error = 126;

			if (*path != NULL)
			{
				free(*path);
				*path = NULL;
			}
		}
	}
}
