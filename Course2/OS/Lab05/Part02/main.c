#include <sys/stat.h>
#include <sys/unistd.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	printf("PID = %llu\n", getpid());

	FILE*		file;
	struct stat	st;
	size_t		file_size;
	char*		file_buffer;
	char*		file_buffer_end;
	size_t		line_count = 0;
	char		line_temp[256];
	char*		line_ptr;
	char*		line_ptr_delim;
	size_t		line_size;

	for (int i = 1; i < argc; i++)
	{
		const char* file_name = argv[i];
		printf("Name\t: %s\n", file_name);

		file = fopen(file_name, "ra");
		if (!file)
		{
			perror("fopen");
			return -1;
		}

		stat(file_name, &st);
		file_size = st.st_size;
		printf("Size\t: %llu\n", file_size);

		file_buffer = (char*)malloc(file_size * sizeof(char));

		while (!feof(file))
		{
			line_count++;
			fgets(line_temp, 128, file);
			strcat(file_buffer, line_temp);
		}

		fclose(file);

		printf("Lines\t: %llu\n", line_count);

		file_buffer_end = file_buffer + file_size;
		for (line_ptr = file_buffer; line_ptr <= file_buffer_end; )
		{
			line_ptr_delim = strchr(line_ptr, '\n');
			line_size = line_ptr_delim - line_ptr;
			printf("%llu ", line_size);
			line_ptr += line_size;
			line_ptr++;
			//printf("%llu ", strlen(line_ptr));
		}
		printf("\n");

		free(file_buffer);

		printf("\n");
	}
	return 0;
}
