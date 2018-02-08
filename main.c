#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING "company=redprarie and city=waukesha and state=wisconsin"

char *sGetToken(char *string, char *delim, char **leftover)
{
    char *ptr;

    /* Don't bother if we don't have a string to parse. */
    if (!string)
	return NULL;

    /* Get a pointer to the delimiter within the string. */
    ptr = strstr(string, delim);
    if (ptr) 
    {
	*ptr = '\0';
	*leftover = ptr + strlen(delim);
    }
    else
    {
	*leftover = NULL;
    }

    return string;
}

int main(int argc, char *argv[])
{
    char *ptr,
	 *pair,
	 *pairsLeft,
	 *name,
	 *value;

    char string[100];

    /* Make a copy of our string. */
    strcpy(string, STRING);

    /* Get a pointer to our string. */
    ptr = string;

    /* Cycle through each name/value pair in the string. */
    while ((pair = sGetToken(ptr, "and", &pairsLeft)) != NULL)
    {
        printf("PAIR [%s]\n", pair);

	/* Get the name and value of this pair. */
	name = sGetToken(pair, "=", &value);
	if (name && value)
	{
	    printf("    NAME  [%s]\n", name);
	    printf("    VALUE [%s]\n", value);
	}

	/* Advance to the pairs left in the string. */
	ptr = pairsLeft;
    }

    exit(0);
}
