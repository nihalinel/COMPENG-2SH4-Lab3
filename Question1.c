#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"


int my_strlen(const char * const str1)
{
	// Returns the length of the string - the number of characters, but IGNORING the terminating NULL character
	
	int length = 0;

    // Iterate through the characters of the string until the NULL character is encountered.
    while (str1[length] != '\0')
	{
    	length++;
    }

    return length;
}

int my_strcmp(const char * const str1, const char * const str2)
{
	// Return 0 if the two strings are not identical.  Return 1 otherwise.
	
	int equal = 0;
	int i;

	// Criteria 1: Check their lenghts.  If not the same length, not equal
	if (my_strlen(str1) != my_strlen(str2))
	{
		return 0;
	}
	else
	{	// Criteria 2: Check their contents char-by-char.  If mismatch found, not equal
		for (i = 0; i < my_strlen(str1); i++)
		{
			if (str1[i] == str2[i])
			{
				equal++;
			}
			else{break;}
		}

		if (equal == my_strlen(str1))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	// if passing the two criteria, strings equal
}


int my_strcmpOrder(const char * const str1, const char * const str2)
{
	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/

	// if two strings are completely identical in order, return -1.

	// We are NOT looking for any custom alphabetical order - just use the integer values of ASCII character

	int i = 0;

    while (str1[i] != '\0' || str2[i] != '\0') 
	{
        if (str1[i] < str2[i])
		{
            return 0;
        }
        else if (str1[i] > str2[i])
		{
            return 1;
        }
	/*	else
		{
			return -1;
		}
	*/
        i++;
    }	

	if (str1[i] == '\0' && str2[i] == '\0') 
	{
        return -1;
    } 
	else if (str1[i] == '\0') 
	{
        return 0;
    }
	else 
	{
        return 1;
    }
}


char *my_strcat(const char * const str1, const char * const str2)
{
	int i, j;

	/* this is the pointer holding the string to return */
	char *z = NULL;

	int size = my_strlen(str1) + my_strlen(str2) + 1;
	
	/*write your implementation here*/
	z = (char*)malloc(size);

	if(z == NULL)
	{
		return NULL;
	}

	for (i = 0; str1[i] != '\0'; i++)
	{
		z[i] = str1[i];
	}

	for (j = 0; str2[j] != '\0'; j++)
	{
		z[i] = str2[j];
		i++;
	}

	z[size-1] = '\0';

	/* finally, return the string*/
	return z;
	free(z);

	// IMPORTANT!!  Where did the newly allocated memory being released?
	// THINK ABOUT MEMORY MANAGEMENT
	
}