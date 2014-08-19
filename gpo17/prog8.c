/*
*	Estructuras con memoria dinámica
*/
#include <stdio.h>
#include <stdlib.h>

struct Alumno{
	char nombre[30];
	int edad;
	float promedio;
	struct Alumno *sig;
};

int main(){
	
	int i;

	struct Alumno *fi;
	struct Alumno *lista, *auxiliar;

	lista = (struct Alumno *)malloc(sizeof(struct Alumno));
	lista->sig = NULL;

	/*Pedir alumnos*/	
	
	for(i=0; i<4; i++){
		
		fi = (struct Alumno *)malloc(sizeof(struct Alumno));
		fi->sig = NULL;
		
		printf("\nNombre del alumno %d: ", i+1);
		gets(fi->nombre);
		
		printf("Edad: ", i+1);
		scanf("%d", &fi->edad);
		getchar();
		
		printf("Promedio: ");
		scanf("%f", &fi->promedio);
		getchar();
		
		fi->sig = lista->sig;
		lista->sig = fi;
	}
	
	/*Mostrar alumnos*/

	auxiliar= lista->sig;

	while(auxiliar != NULL){
		
		printf("\n %s , %d , %.1f ", auxiliar->nombre, auxiliar->edad, auxiliar->promedio);
		auxiliar = auxiliar->sig;
	}
		

	printf("\n\n");



	return 0;
}
