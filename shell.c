#include "shell.h"

/**
 * main - code to pass betty
 * @a:  argument counts
 * @argv: arguments
 *
 * Return: 0(success)
 */

int main(int a, char **argv)
{
	char *prompt = "(simple_shell)$ ";
	char *lineptr = NULL, *copy_lineptr = NULL;
	size_t n = 0;
	ssize_t checkread;
	const char *delin = " \n";
	int sum_token = 0, i;
	char *token;

	(void)a;
	while (1)
	{
	printf("%s", prompt);
	checkread = getline(&lineptr, &n, stdin);
	if (checkread == -1)
	{
		printf("Error\n");
		return (-1); }
	copy_lineptr = malloc(sizeof(char) * checkread);
	if (copy_lineptr == NULL)
	{
		printf("allocation error");
		return (-1); }
	strcpy(copy_lineptr, lineptr);
	token = strtok(lineptr, delin);
	while (token != NULL)
	{
		sum_token++;
		token = strtok(NULL, delin); }
	sum_token++;
	argv = malloc(sizeof(char *) * sum_token);
	token = strtok(copy_lineptr, delin);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delin); }
	argv[i] = NULL;
	execmd(argv); }
	free(lineptr);
	free(copy_lineptr);
	return (0); }
