#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototipo de funciones
void analizar(char c);  //funcion encargada de cambiar los estados o retornar error
void Estado();			//verifica el estado y retorna su valor debido
void Buscar();			//compara  identificador con palabrasReservadas, retorna la palabra si la encuentra, error de lo contrario

//variable globales
char *palabrasReservadas[] = {"definir","repetir","mientras","hasta","fin","finsi","si","imprimir"};
char identificador[100];
char idNum[2];				//aqui guardaremos el signo "-" para verificar si un numero es positivo o negativo
char temp[2]; 			 //aqui guardaremos un caracter a la ves, y se concatena al array identificador
int tamPalabrasReservadas=sizeof(palabrasReservadas)/sizeof(char *); //sizeof() devuelve el tamano en bytes que abarca la variable 
int i;				 //maneja el numero de ciclos de la funcion
int estado=0; 		 //el estado del programa que definira que esta permitido y que no

int main( )
{
	char caracter;
    FILE *fp2;
	FILE *fp ;
	printf( "abriendo el archivo\n" ) ;
    fp2 = fopen("Guardar.txt", "wt"); //Archivo donde se guardan los tokens 
	fp =  fopen ( "Archivo.txt", "r" ) ; // Archivo de donde se lee . 
   
     if ( fp == NULL ){
     printf ( "EL fichero  Archivo.txt  no existe\n" ) ;
     return 1;
	}
   printf( "leyendo fichero Archivo.txt \n" ) ;
    
   while (1){
	  caracter=fgetc(fp);
	  if(caracter==EOF){break;}
	 
	  while(i==0){
		   if(caracter!='{'){printf("impossible de analizar"); exit(-1);}
		   i=1;
	    }
	  
	  analizar(caracter);
	  
	  switch(caracter){
		  case '{':printf("<Tkn_corchete_abierto>"); fputs("<Tkn_corchete_abierto>",fp2); break;
		  case '}':printf("<Tkn_corchete_cerrado>"); fputs("<Tkn_corchete_cerrado>",fp2); break;
		  case '(':printf("<Tkn_parentesis>");fputs("<Tkn_parentesis>",fp2);break;
		  case ')':printf("<Tkn_parentesis>");fputs("<Tkn_parentesis>",fp2);break;
		
		  }
	  i++;
	   }
 
 
}

void buscar(){
	int i ;
	for( i=0;i<tamPalabrasReservadas;i++){
		if(strcmp(palabrasReservadas[i],identificador)==0){
			printf("<Tkn_%s>",palabrasReservadas[i]);
			identificador[0]='\0';
			break;
			}
		if(i==(tamPalabrasReservadas)-1){printf("\nError no hay ID");exit(-1);}
		}
	}

void Estado(){
	switch(estado){
			//en el caso de ser un numero, analizamos si tiene un menos antes, con eso sabremos si es positivo o negativo
			case 1: if(idNum[0]=='-'){printf("<Tkn_numeroNegativo>");idNum[0]='\0';}else printf("<Tkn_numero>"); estado=0;break;
			case 2: if(idNum[0]=='-'){printf("<Tkn_numeroNegativo>");idNum[0]='\0';}else printf("<Tkn_numero>");estado=0;break;
			case 4: if(idNum[0]=='-'){printf("<Tkn_decimalNegativo>");idNum[0]='\0';}else printf("<Tkn_Decimal>");estado=0;break;
			
			//cuando detectamos un identificador, revisamos si esta en la tabla de palabras reservadas
			case 5:buscar();estado=0; break;
			
			case 6:printf("<Tkn_variable>"); estado=0;break;
			case 7:printf("<Tkn_variable>");estado=0;break;
			case 9:printf("<Tkn_operadorRelacional>");estado=0;break;
			case 10:printf("<Tkn_operadorAritmetico>");estado=0;break;
			case 11:printf("<Tkn_operadorMQ>");estado=0;break;
			case 12:printf("<Tkn_Asignador>");estado=0;break;
			case 13:printf("<Tkn_MenorIgualQ>");estado=0;break;
			case 14:printf("<Tkn_MayorQ>");estado=0;break;
			case 15:printf("<Tkn_MayorIgualQ>");estado=0;break;	
			case 16:printf("<Tkn_OperadorMenos>");estado=0;break;	
			case 18:printf("<Tkn_Cadena>");estado=0;break;	
			}
	}

void analizar(char c){
	
	//comprobar el ultimo estado para devolver el Tkn adecuado
	if(c==32||c=='}'||c=='{'||c=='('||c==')'||c==';'){
		//printf("%i \n",estado);
		if(estado==17){estado=17;}else{
		Estado();}
		}
	//Mayuscula
	if( c>=65 && c<=90 ){
		if(estado==0){estado=6;}else if(estado==6||estado==7){estado=7;}
		else if(estado==17){estado=17;}else{printf("\n error");exit(-1);}
		//printf("<Caracter Mayuscula>");
		}
	//Minuscula 
	if(c>=96 && c<=122){
		if(estado==0){temp[0]=c; strcat(identificador,temp); estado=5;}else if(estado==6||estado==7){estado=7;}
		else if(estado==5){temp[0]=c; strcat(identificador,temp);estado=5;}
		else if(estado==17){estado=17;}else{printf("\n errorCM"); exit(-1);}
		//printf("<Caracter Minuscula>");
		}
	//Numero
	if(c<=57&&c>=48){
		if(estado==0){estado=1;}else if(estado==1||estado==2){estado=2;}else if(estado==3||estado==4){estado=4;}
		else if(estado==6||estado==7){estado=7;}else if(estado==16){estado=1;}
		else if(estado==17){estado=17;}else{printf("\n errorN"); exit(-1);}
		}
	//punto decimal	
	if(c=='.'){
		if(estado==1||estado==2){estado=3;}
		else if(estado==17){estado=17;}else{printf("\n error"); exit(-1);}
		 }
	//signo "menos"
	if(c=='-'){if(estado==0){estado=16; idNum[0]='-';}
		else if(estado==11){estado=12;}else if(estado==17){estado=17;}else{printf("Error -");}
		}	
	//operador Aritmetico
	if(c=='+'||c=='/'||c=='*'){
		if(estado==0){estado=10;}else if(estado==17){estado=17;}else{printf("Error aritmetico");exit(-1);}
		
		}
	//operador menor que
	if(c=='<'){                
	
		if(estado==0){estado=11;}else if(estado==17){estado=17;}else{printf("error <");}
		}
	//operador mayor que
	if(c=='>'){   
		if(estado==0){estado=14;}else if(estado==17){estado=17;}else{printf("error >");}
		 }	
	//operador igual
	if(c=='='){
		 if(estado==0){estado=8;}
		 else if(estado==8){estado=9;}else if(estado==11){estado=13;}
		 else if(estado==14){estado=15;}
		 else if(estado==17){estado=17;}else{printf("error =");exit(-1);}
		}
	//operador distinto
	if(c=='!='){
		if(estado==0){estado=8;}else if(estado==17){estado=17;}else{printf("\n error !");exit(-1);} 
		}
	//comillas
	if(c=='"'){
		if(estado==0){estado=17;}else if(estado==17){estado=18;}else{printf("error \" ");}
		
		}
}	
