#include <stdio.h>   //
#include <stdlib.h>	//
#include <string.h> //


int main (){
		
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
		
		printf("\n");
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
		else if(caracter=='{'){
				strcat(estado, "<Tkn_Abrir_Instruccion>");
			}
			else if(caracter=='}'){
				strcat(estado, "<Tkn_Cerrar_Instruccion>");
			}
			else if(caracter==' '){
				if(est==1){
					strcat(estado, "<Tkn_Entero>");
					est=0;
					i=0;
				}
				else if(est==3){
						strcat(estado, "<Tkn_Decimal>");
						est=0;
						i=0;
				}
				else if(est==4){
						strcat(estado, "<Tkn_Cadena>");
						est=0;
						i=0;
				}
				else if(est==8){
						strcat(estado, "<Tkn_Alphanum>");
						est=0;
						i=0;
				}
			
			strcat(estado, "<Tkn_Spc>");
			PReservada(caract,stringFinal,estado,i);
			memset(caract, 0, sizeof caract);
			i=0;
			 
		}
			 
		}
		if(caracter== EOF){
				if(est==1){
				strcat(estado, "<Tkn_Entero>");
				est=0;
				i=0;
			}
			else if(est==3){
					strcat(estado, "<Tkn_Decimal>");
					est=0;
					i=0;
			}
			else if(est==4){
					strcat(estado, "<Tkn_Cadena>");
					est=0;
					i=0;
			}
			else if(est==8){
					strcat(estado, "<Tkn_Alphanum>");
					est=0;
					i=0;
			}
			strcat(estado, "<Tkn_EOF>");
			PReservada(caract,stringFinal,estado,i);
			memset(caract, 0, sizeof caract);
			i=0;
	    }
	    
	    printf("%s \n",stringFinal);
        }
        fclose(archivo);
	
	
	return 0;
}

void Limpiar(c,e){
		memset(e, 0, sizeof c);
		memset(e, 0, sizeof c);
};

int PReservada(caract,stringFinal,estado,i){   // se declaran las palabras reservadas en un arreglo 
											   //Para que depues sea mas facil identificarlos.
	int x=0;
	int igualdad=1;
	char PReservadas[13][20] =
	{ "definir",
	  "leer",
	  "imprimir",
	  "cursor",
	  "repetir",
	  "mientras",
	  "hacer",
	  "hasta",
	  "repetir",
	  "si",
	  "sino",
	  "finsi",
	  "<-",
	  "<=",
	  ">=",
	  "==",
	  "!="
	};
	
	for (x = 0; x < 17; x++)
	{	
			
		int igualdad = strcmp(caract,PReservadas[x]);
		if (igualdad==0){
			if(x==12){
				strcat(stringFinal, "<Tkn_Asignacion>");
				strcat(stringFinal, "<Tkn_Spc>");
				Limpiar(caract,estado);
				i=0;	
			}
			else{
			
			strcat(stringFinal, "<Tkn_");
			strcat(stringFinal, PReservadas[x]);
			strcat(stringFinal, ">");
			strcat(stringFinal, "<Tkn_Spc>");
			Limpiar(caract,estado);
			i=0;
			}
			break;
		}
		else if(igualdad==0 && (x>=13||x<=16)){
		strcat(stringFinal, "<Tkn_Operador_Logico>");;
			strcat(stringFinal, "<Tkn_Spc>");
			Limpiar(caract,estado);
			i=0;	
		}
	}
		if(igualdad!=0){
				strcat(stringFinal, estado);
				Limpiar(caract,estado);
				i=0;
				
				
		}
	
	
}

		
		
	 
	 

