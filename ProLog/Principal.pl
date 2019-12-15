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

carrera(ing_sistemas).
carrera(ing_electrica).
carrera(ing_civil).
carrera(ing_mecanica).
carrera(lic_matematica).
carrera(lic_banca_y_finanzas).
carrera(abogacia).

sexo(masculino).
sexo(femenino).

carrera_alumno(ing_sistemas,sergio).
carrera_alumno(ing_sistemas,hector).
carrera_alumno(ing_mecanica,gerson).
carrera_alumno(lic_banca_y_finanzas,kevin).
carrera_alumno(abogacia,daniela).
carrera_alumno(lic_matematica,rosa).
carrera_alumno(ing_civil,paola).

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

alumno_clase_promedio(hector,redes,65).
alumno_clase_promedio(sergio,topicos,56).
alumno_clase_promedio(paola,concreto1,43).
alumno_clase_promedio(gerson,intro_mecanica,65).
alumno_clase_promedio(daniela,codigo_penal,74).


alumno_clase(X,Y):-carrera_alumno(Z,X),clase_carrera(Y,Z),alumno(X).
promedio(X,Y):- alumno_clase(X,Y),alumno_clase_promedio(X,Y,Z),write(Z).
paso(X,Y):-alumno_clase_promedio(X,Y,Z),alumno_clase(X,Y),Z>=65,write(aprobo:Z).










