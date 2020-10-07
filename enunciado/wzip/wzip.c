#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE *inFile;
void unzip(char *name, char *oldChar, int *characterRep);

int main(int argc, char *argv[])
{
    if (argc < 2){
        printf("%s", "wzip: file1 [file2 ...]\n");
        exit(1);
    }
    
    char oldChar;
    int characterRep;

    for (int i = 1; i < argc; i++){
        unzip(argv[i], &oldChar, &characterRep);
    }
    
    fwrite(&characterRep, 4, 1, stdout);
    fwrite(&oldChar, 1, 1, stdout);

    return (0);
}

void unzip(char *name, char *oldChar, int *characterRep)
{
    inFile = fopen(name, "r");
    if (inFile == NULL)
    {
        printf("wgrep: cannot open file\n");
        exit(1);
    }
    char actChar = fgetc(inFile);

    if (*oldChar == 0)
    {
        *oldChar = actChar;
        *characterRep = 0;
    }

    do
    {
        if (*oldChar != actChar)
        {
            fwrite(characterRep, 4, 1, stdout);
            fwrite(oldChar, 1, 1, stdout);
            *characterRep = 1;
            *oldChar = actChar;
        }
        else
        {
            (*characterRep)++;
        }
    } while ((actChar = fgetc(inFile)) != EOF);
    fclose(inFile);
}