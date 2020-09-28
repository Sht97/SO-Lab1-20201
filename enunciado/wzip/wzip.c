#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    int currChar;        /* current characters */
    int prevChar;        /* previous characters */
    unsigned int count; /* number of characters in a run */
    prevChar = EOF;      /* force next char to be different */
    count = 0;

    for (int i = 1; i < argc; i++)
    {

        FILE *inFile = fopen(argv[i], "r");
        if (inFile == NULL)
        {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        while ((currChar = fgetc(inFile)) != EOF)
        {
            if (prevChar != currChar && prevChar == EOF)
            {
                prevChar = currChar;
                count = 1;
            }
            else if (prevChar == currChar)
            {
                count++;
            }
            else if (prevChar != currChar)
            {

                fwrite(&count, 4, 1, stdout);
                fwrite(&prevChar, 1, 1, stdout);
                prevChar = currChar;
                count = 1;
            }
        }

        fclose(inFile);
    }

    fwrite(&count, 1, 4, stdout);
    fwrite(&prevChar, 1, 1, stdout);
    return 0;
}
