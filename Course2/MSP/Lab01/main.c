#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// KMP Algorithm O(m + n)
const char* strsub(const char* haystack, const char* needle, int m, int n)
{
	if (*needle == '\0' || n == 0)
		return haystack;

	if (*haystack == '\0' || n > m)
		return NULL;

	int next[n + 1];

	for (int i = 0; i < n + 1; i++)
		next[i] = 0;

	for (int i = 1; i < n; i++)
	{
		int j = next[i + 1];
		while (j > 0 && needle[j] != needle[i])
			j = next[j];
		if (j > 0 || needle[j] == needle[i])
			next[i + 1] = j + 1;
	}

	for (int i = 0, j = 0; i < m; i++)
	{
		if (*(haystack + i) == *(needle + j))
		{
			if (++j == n)
				return (haystack + i - j + 1);
		}
		else if (j > 0)
		{
			j = next[j];
			i--;
		}
	}

	return NULL;
}

void strrep(char** string, const char* find, const char* replace)
{
	size_t string_size	= strlen(*string);
	size_t find_size	= strlen(find);
	size_t replace_size	= strlen(replace);
	char* left = "";
	char* right = "";

	while (1)
	{
		const char* substr_ptr = strsub(*string, find, string_size, find_size);
		if (!substr_ptr)
			return;
		char* substr = (char*)calloc(sizeof(char), find_size + 1);
		strncpy(substr, substr_ptr, find_size);

		const size_t left_size = (size_t)(substr_ptr - *string);

		const char* right_ptr = *string + left_size + find_size;
		const size_t right_size = string_size - (size_t)(right_ptr - *string);

		if (left_size)
		{
			left = (char*)calloc(sizeof(char), left_size + 1);
			strncpy(left, *string, left_size);
		}
		if (right_size)
		{
			right = (char*)calloc(sizeof(char), right_size + 1);
			strcpy(right, right_ptr);
		}

		free(*string);
		size_t result_size = left_size + right_size + replace_size;
		*string = (char*)calloc(sizeof(char), result_size);

		if (left_size)
		{
			strcat(*string, left);
			free(left);
		}
		strcat(*string, replace);
		free(substr);
		if (right_size)
		{
			strcat(*string, right);
			free(right);
		}
	}
}

int main()
{
	enum { BUFFER_SIZE = 512 };
	char* str = (char*)calloc(sizeof(char), BUFFER_SIZE);
	char substr[BUFFER_SIZE] = "";
	char repstr[BUFFER_SIZE] = "";

	printf("String:            ");
	gets(str);

	printf("Find substring:    ");
	gets(substr);

	printf("Replace substring: ");
	gets(repstr);

	strrep(&str, substr, repstr);
	printf("Result:         %s\n", str);

	free(str);

	return 0;
}
