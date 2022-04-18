#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_BUFFER_SIZE 8
#define OUTPUT_BUFFER_SIZE 64

static const char TEST_APP_NAME[] = "Lab1App";

int test_positive(float a, float b, float x, char sign)
{
	char strA[INPUT_BUFFER_SIZE];
	char strB[INPUT_BUFFER_SIZE];
	char strSign[2] = {sign, 0};
	sprintf_s(strA, INPUT_BUFFER_SIZE, "%g", a);
	sprintf_s(strB, INPUT_BUFFER_SIZE, "%g", b);
	char* cmd = (char*)malloc((sizeof(TEST_APP_NAME) / sizeof(char) + strlen(strA) + strlen(strB) + 3) / sizeof(char));
	cmd[0] = '\0';
	strcpy(cmd, TEST_APP_NAME);
	strcat(cmd, " ");
	strcat(cmd, strA);
	strcat(cmd, strSign);
	strcat(cmd, strB);

	FILE* pipe = popen(cmd, "r");
	if(!pipe)
		fprintf(stderr, "Failed to execute command \"%s\".\n", cmd);

	char strX[OUTPUT_BUFFER_SIZE];
	float outX;
	int ret = 0;

	if(fgets(strX, OUTPUT_BUFFER_SIZE, pipe) != NULL)
	{
		sscanf(strX, "%g", &outX);
		if(outX == x)
			ret = 1;
		else
			fprintf(stderr, "Command \"%s\" result \"%f\" is deffers from \"%f\".\n", cmd, outX, x);
		if(!feof(pipe))
			fprintf(stderr, "Command \"%s\" provides too much std output.\n", cmd);
	}
	else
		fprintf(stderr, "Could not read std out from command \"%s\".\n", cmd);

	pclose(pipe);
	free(cmd);
	return ret;
}

int test_negative(const char* restrict args)
{
	char* cmd = (char*)malloc(sizeof(TEST_APP_NAME) / sizeof(char) + strlen(args) + 2);
	strcpy(cmd, TEST_APP_NAME);
	strcat(cmd, " ");
	strcat(cmd, args);
	fopen(cmd, "r");
	FILE* pipe = popen(cmd, "r");
	const int ret = pclose(pipe);
	free(cmd);
	return ret;
}

int main()
{
	fclose(stderr); // Stop showing negative tests error messages

	struct planned_test
	{
		float a;
		float b;
		float x;
		char sign;
	};
	const struct planned_test tests_positive[] = {
	    {15.0f, 5.0f, 20.0f, '+'},    {2.8f, 5.6f, 8.4f, '+'},        {12.0f, -4.0f, 8.0f, '+'},
	    {5.2f, -2.4f, 2.8f, '+'},     {-2.0f, 4.0f, 2.0f, '+'},       {-6.8f, 4.2f, -2.6f, '+'},
	    {-6.0f, -10.0f, -16.0f, '+'}, {-2.4f, -8.4f, -10.8f, '+'},    {15.0f, 5.0f, 10.0f, '-'},
	    {2.8f, 5.6f, -2.8f, '-'},     {12.0f, -4.0f, 16.0f, '-'},     {5.2f, -2.4f, 7.6f, '-'},
	    {-2.0f, 4.0f, -6.0f, '-'},    {-6.8f, 4.2f, -11.0f, '-'},     {-6.0f, -10.0f, 4.0f, '-'},
	    {-2.4f, -8.4f, 6.0f, '-'},    {2.0f, 5.0f, 10.0f, '*'},       {5.2f, 2.6f, 13.52f, '*'},
	    {4.0f, -2.0f, -8.0f, '*'},    {2.4f, -1.2f, -2.88f, '*'},     {-5.0f, 4.0f, -20.0f, '*'},
	    {-4.2f, 8.8f, -36.96f, '*'},  {-6.0f, -2.0f, 12.0f, '*'},     {-2.8f, -4.4f, 12.32f, '*'},
	    {2.0f, 5.0f, 0.4f, '/'},      {5.2f, 2.6f, 2.0f, '/'},        {4.0f, -2.0f, -2.0f, '/'},
	    {2.4f, -1.2f, -2.0f, '/'},    {-5.0f, 4.0f, -1.25f, '/'},     {-4.2f, 8.8f, -0.477273f, '/'},
	    {-6.0f, -2.0f, 3.0f, '/'},    {-2.8f, -4.4f, 0.636364f, '/'},
	};
	const int tests_positive_count = (int)(sizeof(tests_positive) / sizeof(*tests_positive));

	int success = 0;
	for(const struct planned_test* test_ptr = tests_positive; test_ptr < tests_positive + tests_positive_count;
	    ++test_ptr)
		success += test_positive(test_ptr->a, test_ptr->b, test_ptr->x, test_ptr->sign);

	const char* tests_negative[] = {"onetwo", "2w+2", "+4", "1/0", ""};
	const size_t tests_negative_count = sizeof(tests_negative) / sizeof(*tests_negative);
	for(const char** test_ptr = tests_negative; test_ptr < tests_negative + tests_negative_count; ++test_ptr)
		success += test_negative(*test_ptr);

	printf("All:     %u\n", tests_positive_count + tests_negative_count);
	printf("Success: %u\n", success);
	printf("Error:   %u\n", tests_positive_count + tests_negative_count - success);

	return 0;
}
