#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		fprintf(stderr, "Usage: Lab1App number2 operator number2.\n");
		return 1;
	}

	size_t buffer_size = 1; // With '\0'
	for(char** arg = argv + 1; arg < argv + argc; ++arg)
		buffer_size += strlen(*arg);
	char* buffer = (char*)malloc(buffer_size * sizeof(char));
	char* bufptr = buffer;
	for(char** arg = argv + 1; arg < argv + argc; ++arg)
		for(char* chr = *arg; *chr != '\0'; ++chr)
		{
			if(isdigit(*chr) || *chr == '.' || *chr == '+' || *chr == '-' || *chr == '*' || *chr == '/')
				*bufptr = *chr;
			else
			{
				fprintf(stderr, "Input string contains invalid characters.\n");
				free(buffer);
				return 1;
			}
			++bufptr;
		}
	*bufptr = '\0';

	int maybe_sign = 0;
	int sign_pos = -1;
	for(bufptr = buffer; *bufptr; ++bufptr)
	{
		if(!maybe_sign && isdigit(*bufptr))
			maybe_sign = 1;
		if(maybe_sign && (*bufptr == '+' || *bufptr == '-' || *bufptr == '*' || *bufptr == '/'))
		{
			sign_pos = (int)(bufptr - buffer);
			maybe_sign = 0;
			break;
		}
	}
	if(sign_pos == -1)
	{
		fprintf(stderr, "Input string in not valid math formulae a sign b.\n");
		free(buffer);
		return 1;
	}
	const char sign = *bufptr;
	*bufptr = '\0';

	const float a = atof(buffer);
	const float b = atof(bufptr + 1);
	float x;
	switch(sign)
	{
	case '+':
		x = a + b;
		break;
	case '-':
		x = a - b;
		break;
	case '*':
		x = a * b;
		break;
	case '/':
		if(b)
			x = a / b;
		else
		{
			fprintf(stderr, "Division by zero.\n");
			free(buffer);
			return 1;
		}
		break;
	}

	printf("%g", x);

	free(buffer);

	return 0;
}
