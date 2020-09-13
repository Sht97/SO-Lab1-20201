#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leerArchivo(char *nombre);
FILE *inFile;

int main(int argc, char *argv[])
{ 
  if (argc < 2)
    {
        exit(0);
    }
    
  for(int i=1; i<argc; i++){
    leerArchivo(argv[i]);
  }
  
  return 0;
}

void leerArchivo(char *nombre){

inFile = fopen(nombre,"r");
char data[50] ;
if(inFile == NULL) {
  printf("wcat: cannot open file\n");
  exit(1);
}
while( fgets ( data, 50, inFile ) != NULL ){
      printf( "%s" , data ) ;

  }
fclose(inFile); 

}
