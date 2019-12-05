#include <stdio.h>   //
#include <stdlib.h>	//
#include <string.h> //


int (){
		
	char estadofinal[100];
	FILE *archivo; 			//FILE nos permite abrir y crear ficheros en el disco
	char caracter;
	char stringFinal[1000]="";     
	char caract[50]="";
	char estado[50]="";
	int i=0,est=0;
	int igualdad;
	
	
	
	/* El estado=1 es numero.
	   El estado=2 es numero con punto 
	   El estado=3 es numero decimal
       El estado=4 es letra(s)
	   El estado=5 es letra(s) con numero(s) {Cadena}
	   El estado=6 es Mayuscula(s)
	   El estado=7 es Mayuscula(s) con letras(s) o numero(s) {Variable}
	   El estado=8 es cadena Alphanum
	 */
	 
	 
	 archivo = fopen("Entrada.txt","r");   //fopen , abre el fichero.	
										  //entrada.txt es el nombre del fichero donde se guarda los archivoz a leer por el analizador lexico
	 									 //y la r es de reading en español lectura. que solo va a leer ese fichero
		
		printf("Para que el archivo sea leido correctamente cada instruccion o palabra reservada deben estar separadas por espacios.");
		printf("\n--------------------------------------------------------------------------------------------------------------------- \n\n");
	if (archivo == NULL){
		
        printf("\nError No se pudo abrir el fichero. \n\n");
       
	    }else{
            while((caracter = fgetc(archivo)) != EOF){	  //fgetc lee caracter a caracter mientras no termine de leer el ultimo caracter
            											  //EOF es el fin del fichero.
	    
		
		if (caracter!=' '){
	    	caract[i]=caracter;
            i++;
        	}
			if(caracter>='0' && caracter<='9' ){
				if (est==0|| est==1)
					est=1;
					
				else if(est==2||est==3){
					est=3;
				}
				else if(est==4||est==8){
					est=8;
				}
				}
				
			else if(caracter=='.' && (est==1)){
					est=2;		
			}
			else if(caracter>='a' && caracter<='z' ){
				if(est==0||est==4){
					est=4;
				}
				else if(est==1||est==8){
					est=8;
				}	
			}
			else if(caracter>='A' && caracter<='Z' ){
				strcat(estado, "<Tkn_Num>");
			}
			else if(caracter=='+' || caracter=='-'|| caracter=='*'|| caracter=='/'){
				strcat(estado, "<Tkn_Operador_Aritmetico>");
			}
			else if(caracter=='<' || caracter=='>'){
				strcat(estado, "<Tkn_Operador_Logico>");
			}
		}
		
		
	 
	 
}
