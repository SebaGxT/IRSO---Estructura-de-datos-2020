//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructuras

//1)Definir una estructura capaz de almacenar los siguientes datos  nombre, edad, sueldo y rol que desempeña en la empresa IRSO. A saber: 1 cadete, 2 administrativo, 3 jefe y 4 gerente. 
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

//2)Hacer un procedimiento que lea los datos de un empleado de la empresa IRSO.
void ingreso_emp(struct IRSO &emp){
	
	printf("\nIngrese el nombre del empleado: ");
	gets(emp.nombre);
	fflush(stdin);
	
	do{
		printf("\nIngrese edad: ");
		scanf("%d",&emp.edad);
		fflush(stdin);
		
		if(emp.edad<=0){
			
			printf("\n\nEdad inv%clida, vuelva a ingresar porfavor.\n\n",160);
			
		}
		
	}while(emp.edad<=0);
	
	do{
		
		printf("\nIngrese sueldo: ");
		scanf("%f",&emp.sueldo);
		fflush(stdin);
		
		if(emp.sueldo<=0){
			
			printf("\n\nSueldo inv%clido, vuelva a ingresar porfavor.\n\n",160);
			
		}
		
	}while(emp.sueldo<=0);
	
	printf("\nPuesto del empleado: ");
	gets(emp.rol);
	fflush(stdin);
		
}

//3)Hacer un procedimiento que muestre por pantalla los datos de un empleado de la empresa IRSO.
void impresion_strucemp(struct IRSO emp){
	
	printf("\nNombre del empleado: %s",emp.nombre);
	printf("\nEdad: %d",emp.edad);
	printf("\nSueldo: %.2f",emp.sueldo);
	printf("\nPuesto: %s",emp.rol);
	printf("\n");
	
}

//5)Hacer un procedimiento que lea los datos de los 10  empleados de la empresa IRSO.
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

//6)Hacer un procedimiento que muestre por pantalla los 10  empleados de la empresa IRSO.
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

//7)Hacer una función que reciba los datos de todos  los empleados de la empresa IRSO y devuelva cuántos son cadetes.
int emp_contcad(struct IRSO emp[],int tamanio){
	
	int i,cont;
	cont=0;
	
	for(i=0;i<tamanio;i++){
		
		strlwr(emp[i].rol);
		if(strcmp(emp[i].rol,"cadete")==0){
			
			cont++;
			
		}
				
	}
	
	return cont;
	
}

//8)Hacer una función que reciba los datos de todos  los empleados de la empresa IRSO y devuelva cuántos son mayores a 30 años.
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

//9)Hacer una función que reciba los datos de todos  los empleados de la empresa IRSO y devuelva cuántos ganan mas de 20000$.
int emp_contsuel(struct IRSO emp[],int tamanio){
	
	int i,cont;
	cont=0;
	
	for(i=0;i<tamanio;i++){
		
		if(emp[i].sueldo>=20000){
			
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
	int i,cantcad1,cantcad2,contedad1,contedad2,contsuel1,contsuel2;
	
//Ingreso de datos
	
	printf("Legajo de empleados\n\n");
	
	for(i=0;i<EMP;i++){
		
		ingreso_emp(empleado);
		strcpy(legajo[i].nombre,empleado.nombre);
		strcpy(legajo[i].rol,empleado.rol);
		legajo[i].edad=empleado.edad;
		legajo[i].sueldo=empleado.sueldo;
		
	}
	
	ingreso_emp_vec(legajo2,EMP);
	
//Proceso
	
	cantcad1=emp_contcad(legajo,EMP);
	cantcad2=emp_contcad(legajo2,EMP);
	contedad1=emp_contedad(legajo,EMP);
	contedad2=emp_contedad(legajo2,EMP);
	contsuel1=emp_contsuel(legajo,EMP);
	contsuel2=emp_contsuel(legajo2,EMP);
	
//Salida de datos

	for(i=0;i<EMP;i++){
		
		strcpy(empleado.nombre,legajo[i].nombre);
		strcpy(empleado.rol,legajo[i].rol);
		empleado.edad=legajo[i].edad;
		empleado.sueldo=legajo[i].sueldo;
		impresion_strucemp(empleado);
		
	}
	
	impresion_strucemp_vec(legajo2,EMP);
	printf("\n\n");
	printf("Cantidad de cadetes de legajo1: %d",cantcad1);
	printf("\nCantidad de cadetes de legajo2: %d",cantcad2);
	printf("\nCantidad de mayores de 30 a%cos legajo1: %d",164,contedad1);
	printf("\nCantidad de mayores de 30 a%cos legajo2: %d",164,contedad2);
	printf("\nCantidad con sueldo mayor a 20000 legajo1: %d",contsuel1);
	printf("\nCantidad con sueldo mayor a 20000 legajo2: %d",contsuel2);

//Pausa y fin de programa
	
	pausar();
	return 0;
	
}
