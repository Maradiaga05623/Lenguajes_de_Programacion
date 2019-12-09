%{
#include <math.h>
void Salir();
%}

DIGITO   [0-9]
ID       [a-z][a-z0-9]*
MAY	 [A-Z]
min	  [a-z]


%%
{MAY}  {printf("Letra Mayuscula: %s\n",yytext);}
{min}  {printf("Letra Minuscula: %s\n",yytext);}


{DIGITO}+   {
            printf( "Un entero: %s (%d)\n", yytext,
                    atoi( yytext ) );
            }

{DIGITO}+"."{DIGITO}*      {
            printf( "Un real: %s (%g)\n", yytext,
                    atof( yytext ) );
            }

Carácter|cursor|Decimal|Definir|Entero|finsi|Hasta|imprimir|Leer|Mientras|Repetir|si|sino {
            printf( "Una palabra clave: %s\n", yytext );
            }
Salir	    { Salir();}
		/*
{ID}        printf( "Un identificador: %s\n", yytext );*/

"+"|"-"|"*"|"/"   printf( "Un operador: %s\n", yytext );

"{"[^}\n]*"}"     

[ \t\n]+      

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
