%{
#include <math.h>
#include <stdio.h>
void Salir();
void imprimir();
void leer();
void mientras();
void repetir();
void si();
%}

Entero	  [0-9]+
Decimal   [0-9]+"."[0-9]+
digito    [0-9]
Cadena   [a-z][a-z0-9]+
%%

{Cadena} {printf("Cadena: %s\n",yytext);}

{Entero}   {printf( "Un entero: %s (%d)\n", yytext,
                    atoi( yytext ) );
            }

{Decimal}      {
            printf( "Un decimal: %s (%g)\n", yytext,
                    atof( yytext ) );
            }

Carácter|cursor|Decimal|Definir|Entero|finsi|Hasta|sino {
          {
			printf("imprimiendo...:%s\n",yytext);}
	    if(yytext="Leer"){
		int i;
		scanf("%i",&i);
			}		
		else
	    printf( "Una palabra clave: %s\n", yytext );}
Imprimir  {imprimir();}
Leer      {leer();}
Mientras   {mientras();}
Repetir    {repetir();}
Si	    {si();}

		
Salir	    { Salir();}
		
"+"|"-"|"*"|"/"   printf( "Un operador: %s\n", yytext );

"{"[^}\n]*"}"     ;

[ \t\n]+      ;

.           printf( "Caracter no reconocido: %s\n", yytext );

%%

int main(int argc, char *argv[]){
	if (argc == 2){
		yyin= fopen(argv[1], "rt");
		if (yyin == NULL){
			printf("no se puede abrir %s ", argv[1]);
			exit(1);
		}
	}
	else{
	    yyin = stdin;
	}
	yylex();
	return 0;
}
void Salir(){
	printf("Saliendo...");
	exit(0);
}
void imprimir(){
	printf("estoy imprimiendo\n");
}
void leer(){printf("estoy leyendo\n");
		int i;
		scanf("%i",&i)	;
               printf("estoy imprimiendo: %i\n",i);  }
void repetir(){printf("metodo iteracion :repetir\n");}
void mientras(){printf("metodo iteracion: mientras\n");}
void si(){printf("metodo condicion :si\n");}
