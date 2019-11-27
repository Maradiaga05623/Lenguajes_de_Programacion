#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int i=0;
	char estadofinal[100];

		FILE *archivo;
	char caracter;
	
	//se lee lo que esta dentro de analizardor.txt 
	archivo = fopen("analizador.txt","r");
	
	if (archivo == NULL)
        {
            printf("\nError de apertura del archivo. \n\n");
        }
        else
        {
            printf("\nEl contenido del archivo de prueba es \n\n");
            while((caracter = fgetc(archivo)) != EOF)
	    {
		//printf("%c",caracter);
		if(caracter>='a' && caracter<='z' ){
			char estado[]="<Tkn_Min>";
			printf("%s",estado);
		}
		if(caracter>='A' && caracter<='Z' ){
			char estado[]="<Tkn_May>";
			printf("%s",estado);
		}
		if(caracter>='0' && caracter<='9' ){
			char estado[]="<Tkn_Num>";
			printf("%s",estado);
		}
		if(caracter==' '){
			char estado[]="<Tkn_Spc>";
			printf("%s",estado);
		}
	    }
        }
        fclose(archivo);
	
	
	return 0;
}
