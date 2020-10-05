#include <stdio.h>
#include<stdlib.h>

void unzip(char *nombre);
FILE *inFile;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }

    //Para descomprimir multiples archivos
    for(int i=1; i<argc; i++){
        unzip(argv[i]);
    }
    return 0;
}

void unzip(char *nombre){
    char letra;
    int numero;
    inFile = fopen(nombre,"r"); //Se intenta abrir el archivo
    if(inFile == NULL) {
        exit(1);
    }
    while (fread(&numero, 4, 1, inFile)) { //Primero lee la letra 
        fread(&letra, 1, 1, inFile); //Luego lee el número

        for (int a = 0; a < numero; a++)//Imprime la letra el número de veces
        {
            printf("%c", letra);
        }
    }
    fclose(inFile);
    }
