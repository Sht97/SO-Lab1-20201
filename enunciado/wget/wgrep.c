#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Search_in_File(char *str, char *fname);

int main(int argc, char *argv[]) {

	if(argc == 1 ) {
		printf("wgrep: searchterm [file ...]\n");
		exit(1);
	}
	
	char *str = argv[1];
    if (argc == 2)
    {
        char buffer[500];
        while ( fgets(buffer, 500, stdin) ){
            if (strstr(buffer, str) != NULL)
            {
                printf("%s", buffer);
            }
        }
    }

	for(int i=2; i<argc; i++){

    Search_in_File(argv[i],str);
  	}

	return(0);
}

void Search_in_File(char *fname, char *str) {

	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE *inFile = fopen(fname, "r");
	if (inFile == NULL)
	{
		printf("wgrep: cannot open file\n");
		exit(1);
	}
	while ((read = getline(&line, &len, inFile)) != -1)
	{
		if (strstr(line, str) != NULL)
		{
			printf("%s", line);
		}
	}
	fclose(inFile);
}
