//Librerias
#include <stdio.h>
#include <stdlib.h>

//Funciones y procedimientos
int divis_func(int n1, int n2){
	
	int cont,res;
	
	cont=0;
	res=n1;
	
	while((res>=0)&&(res>=n2)){
			
		res=res-n2;
		cont++;
				
	}
	
	return cont;
	
}

//Main
int main(){

//Variables

	int num1,num2,res;

//Ingreso de datos
	
	printf("Division por restas sucesivas.\n\n");
	printf("Ingrese el primer n%cmero: ",163);
	scanf("%d",&num1);
	fflush(stdin);
	printf("\nIngrese el segundo n%cmero: ",163);
	scanf("%d",&num2);
	fflush(stdin);

//Proceso
	
	res=divis_func(num1,num2);
	
//Salida de datos
	
	printf("\n\nEl resultado es: %d",res);

//Pausa y fin de programa

	printf("\n\n\n\n");
	system("pause");
	return 0;
	
}
