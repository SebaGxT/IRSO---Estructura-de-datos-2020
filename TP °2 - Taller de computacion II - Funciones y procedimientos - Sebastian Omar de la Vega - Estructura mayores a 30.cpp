//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructuras
 
struct IRSO{
	
	char nombre[40];
	int edad;
	float sueldo;
	char rol[20];
	
};

//Funciones y procedimientos
void pausar(){
	
	printf("\n\n\n\n");
	system("pause");
	
}

void ingreso_emp_vec(struct IRSO emp[], int tamanio){
	
	int i;
	
	for(i=0;i<tamanio;i++){
		
		printf("\nIngrese el nombre del empleado: ");
		gets(emp[i].nombre);
		fflush(stdin);
	
		do{
			
			printf("\nIngrese edad: ");
			scanf("%d",&emp[i].edad);
			fflush(stdin);
		
			if(emp[i].edad<=0){
			
				printf("\n\nEdad inv%clida, vuelva a ingresar porfavor.\n\n",160);
			
			}
		
		}while(emp[i].edad<=0);
	
		do{
		
			printf("\nIngrese sueldo: ");
			scanf("%f",&emp[i].sueldo);
			fflush(stdin);
		
			if(emp[i].sueldo<=0){
			
				printf("\n\nSueldo inv%clido, vuelva a ingresar porfavor.\n\n",160);
			
			}
		
		}while(emp[i].sueldo<=0);
	
		printf("\nPuesto del empleado: ");
		gets(emp[i].rol);
		fflush(stdin);
		
	}
		
}

void impresion_strucemp_vec(struct IRSO emp[], int tamanio){
	
	int i;
	
	for(i=0;i<tamanio;i++){
		
		printf("\nNombre del empleado: %s",emp[i].nombre);
		printf("\nEdad: %d",emp[i].edad);
		printf("\nSueldo: %.2f",emp[i].sueldo);
		printf("\nPuesto: %s",emp[i].rol);
		printf("\n");
		
	}
	
}

int emp_contedad(struct IRSO emp[],int tamanio){
	
	int i,cont;
	cont=0;
	
	for(i=0;i<tamanio;i++){
		
		if(emp[i].edad>=30){
			
			cont++;
			
		}
		
	}
	
	return cont;
	
}

//Main
int main(){

//Variables
	
	const int EMP=2;
	
//4)Definir una estructura capaz de almacenar varios legajos de empleados de la empresa IRSO.	
	struct IRSO empleado,legajo[EMP],legajo2[EMP];
	int i,contedad;
	
//Ingreso de datos
	
	printf("Legajo de empleados\n\n");

	ingreso_emp_vec(legajo,EMP);
	
//Proceso
	
	contedad=emp_contedad(legajo,EMP);
	
//Salida de datos

	impresion_strucemp_vec(legajo,EMP);
	printf("\n\n");
	printf("\nCantidad de mayores de 30 a%cos legajo: %d",164,contedad);

//Pausa y fin de programa
	
	pausar();
	return 0;
	
}
