#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int filecmp(FILE *file1, FILE *file2, int line_size, char* different_line ){
	
	char *line1, *line2;
	int i = 0;
	
	line1 = malloc((line_size + 1) * sizeof(char));
	line2 = malloc((line_size + 1 ) * sizeof(char));

	if (file1 == NULL || file2 == NULL){
		printf("exited\n");
		exit(1);
	}
	
	line1 = fgets(line1,line_size,file1);
	line2 = fgets(line2,line_size,file2);
	
	while ( line1 != NULL || line2 != NULL){
		if ( strcmp(line1,line2) != 0 ){
			
			if (line1 != NULL && line2 != NULL ){
				strcpy(different_line,line1);
				different_line += strlen(different_line);
				*different_line = '|';
				different_line += 1;
				strcpy(different_line,line2);
			}
			else if (line1 == NULL)
				strcpy(different_line,line2);
			else 
				strcpy(different_line,line1);
			
			return i;
		}
		line1 = fgets(line1,line_size,file1);
		line2 = fgets(line2,line_size,file2);
		++i;
	}		
	
	return -1;	
}

void main(int argc, char * argv[])
{
	FILE *file1, *file2;
	file1 = fopen(argv[1], "r");
	file2 = fopen(argv[2], "r");
	char * different_line;
	int line_nr_diff, line_size = 100;
	
	different_line = malloc(2 * (line_size + 1) * sizeof(char));
	line_nr_diff = filecmp(file1, file2, line_size, different_line);
	
	if (line_nr_diff == -1)
		printf("same files\n");
	else
		printf("line_nr:%d, text: %s", line_nr_diff, different_line);
}


