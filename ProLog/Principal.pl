%Nombre de los alumnos.
alumno(miguel).
alumno(alonzo).
alumno(sergio).
alumno(rosa).
alumno(kevin).
alumno(marcela).
alumno(fausto).
alumno(hector).
alumno(marlen).
alumno(daniela).
alumno(daniel).
alumno(cindy).
alumno(gerson).
alumno(paola).
alumno(maria).


%lista alumnos con su respectivo sexo.
sexo_alumno(masculino,miguel).
sexo_alumno(masculino,alonzo).
sexo_alumno(masculino,sergio).
sexo_alumno(femenino,rosa).
sexo_alumno(masculino,kevin).
sexo_alumno(femenino,marcela).
sexo_alumno(masculino,fausto).
sexo_alumno(masculino,hector).
sexo_alumno(femenino,marlen).
sexo_alumno(femenino,daniela).
sexo_alumno(masculino,daniel).
sexo_alumno(femenino,cindy).
sexo_alumno(masculino,gerson).
sexo_alumno(femenino,paola).
sexo_alumno(femenino,maria).

%Nombre de las carreras en existencia.
carrera(ing_sistemas).
carrera(ing_electrica).
carrera(ing_civil).
carrera(ing_mecanica).
carrera(lic_matematica).
carrera(lic_banca_y_finanzas).
carrera(abogacia).





%lista de carreras con sus  respectivos alumnos.
carrera_alumno(ing_sistemas,sergio).
carrera_alumno(ing_sistemas,hector).
carrera_alumno(ing_mecanica,gerson).
carrera_alumno(lic_banca_y_finanzas,kevin).
carrera_alumno(abogacia,daniela).
carrera_alumno(lic_matematica,rosa).
carrera_alumno(ing_civil,paola).
carrera_alumno(nutricion,maria).

%Lista de Clases correspondientes a cada carrera.
clase_carrera(concreto1,ing_civil).
clase_carrera(intro_mecanica,ing_mecanica).
clase_carrera(calculo3,lic_matematicas).
clase_carrera(mercadotecnia,lic_banca_y_finanzas).
clase_carrera(codigo_penal,abogacia).
clase_carrera(redes,ing_sistemas).
clase_carrera(calculo4,lic_matematicas).
clase_carrera(compiladores,ing_sistemas).
clase_carrera(eletromagnetismo,ing_electrica).
clase_carrera(estructuras,ing_civil).
clase_carrera(derecho_laboral,abogacia).
clase_carrera(termodinamica,ing_electrica).
clase_carrera(topicos,ing_sistemas).
clase_carrera(herbalife,nutricion).
clase_carrera(dietetica,nutricion).

%Nombre de alumno con su respectivo promedio en la clase.
alumno_clase_promedio(hector,redes,65).
alumno_clase_promedio(sergio,topicos,56).
alumno_clase_promedio(paola,concreto1,43).
alumno_clase_promedio(gerson,intro_mecanica,65).
alumno_clase_promedio(daniela,codigo_penal,74).
alumno_clase_promedio(maria,herbalife,95).
alumno_clase_promedio(maria,dietetica,100).

% Esta regla nos sirve para verificar que el alumno tenga la clase
% correpondiente a su carrera.
alumno_clase(X,Y):-carrera_alumno(Z,X),clase_carrera(Y,Z),alumno(X).

% Esta regla nos sirve para mostrar el promedio del alumno en la clase y
% lo imprime en la consola.
promedio(X,Y):- alumno_clase(X,Y),alumno_clase_promedio(X,Y,Z),write(Z).

% Esta regla nos sirve para comprobar si el alumno aprobo o reprobo la
% clase.
paso(X,Y):-alumno_clase_promedio(X,Y,Z),alumno_clase(X,Y),(Z>=65,write(aprobo:Z);Z<65,write(reprobo:Z)).










