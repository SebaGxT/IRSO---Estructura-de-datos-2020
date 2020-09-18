//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funciones y procedimientos

void pausar(){
	
	printf("\n\n\n\n");
	system("pause");
	
}

void leer_positivo(int &n){	
		
	printf("\nIngrese un valor positivo: ");
	scanf("%d",&n);
	fflush(stdin);
	
	while(n<0){
		
		printf("\n\nPor favor ingrese un valor positivo.\n");
		printf("\nIngrese un valor positivo: ");
		scanf("%d",&n);
		fflush(stdin);
		
	}	
					
}

/*1) Una función recursiva que reciba un entero no negativo y devuelva el n-ésimo número de Fibonacci. Los números de Fibonacci se definen de la siguiente manera:
F(0) = 0
      F(1) = 1
      F(i) = F(i-1) + F(i-2).*/
int fibonacci_func(int n){

	int res;
	
	if(n<2){
		
		res=n;
		
	}else{
		
		res=fibonacci_func(n-1)+fibonacci_func(n-2);
		
	}
	
	return res;
	
}

/*2) Luego leer un entero positivo y mostrar la serie de Fibonacci. Por ejemplo:
    N = 6 muestra    F(6) F(5) F(4) F(3) F(2) F(1) F(0), es decir,
    N = 6 muestra    13    8      5      3      2      1 */
//Main
int main(){
	
//Variables

	int n1,res;

//Ingreso de datos
	
	leer_positivo(n1);

//Proceso
	
	res=fibonacci_func(n1);

//Salida de datos

	printf("\n\nEl resultado fibonacci es: %d",res);

//Pausa y fin de programa
	
	pausar();
	return 0;
	
}
