%{
#include <math.h>
void Salir();
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

Carácter|cursor|Decimal|Definir|Entero|finsi|Hasta|Imprimir|Leer|Mientras|Repetir|si|sino {
            printf( "Una palabra clave: %s\n", yytext );
		if(yytext=="Imprimir"){
			printf("imprimiendo\n");}
            }

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
