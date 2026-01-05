#include <string.h>
#include <stdio.h>


int main(void)
{
	char str[] = "On va split ce string";
	char *split;

	if (str != NULL)
		split = strtok(str, " ");

	while (split != NULL)
	{
		printf("%s\n", split);
		split = strtok(NULL, " ");
	}

	return (0);
}
