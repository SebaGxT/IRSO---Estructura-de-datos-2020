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
		scanf("%d",&n);
		fflush(stdin);
		
	}	
					
}

bool par_impar(int n){
	
	if(n%2==0){
		
		return true;
		
	}else{
		
		return false;
		
	}
	
}

//1) Una función recursiva que reciba un entero no negativo y devuelva su factorial.
int factorial(int n){
	
	int res;
	
	if(n==0){
		
		res=1;
		
	}else{
		
		res=n*factorial(n-1);
		
	}
	
	return res;
	
}

//2) Un procedimiento recursivo que reciba un entero no negativo  y muestre todos los enteros hasta el 0. Ejemplo: si el nro es 4, muestra 4, 3, 2, 1, 0.
void imp_num(int n){
	
	printf("\n%d",n);
	if(n>0){
		
		imp_num(n-1);
		
	}
		
}

/*3) Un procedimiento recursivo que reciba un entero no negativo y muestre  el entero si es impar  y los impares menores.
     Ejemplo: si n = 7, muestra 7, 5, 3, 1. Si n = 6, muestra 5, 3, 1.*/
void imp_impar_rec(int n){
	
	if(par_impar(n)==false&&n>=0){
		
		printf("\n%d",n);
		imp_impar_rec(n-2);
		
	}
	
}

/*4) Un procedimiento recursivo que reciba un entero no negativo y muestre  el entero si es par  y los pares menores.
     Ejemplo: si n = 8, muestra 8, 6, 2. Si n = 7, muestra 6, 4, 2.*/
void imp_par_rec(int n){
	
	if(par_impar(n)==true&&n>=0){
		
		printf("\n%d",n);
		imp_par_rec(n-2);
		
	}
	
}

/*5) Una función recursiva que calcule: Suma(n) = n + (n-1) + (n-2) +…….+1.
    Ejemplo: Suma(5)=  5 + 4 + 3 + 2 + 1.*/
int suma_suce_rec(int n){
	
	int res;
	
	res=0;
	
	if(n==1){
		
		res=1;
		
	}else{
		
		res=n+suma_suce_rec(n-1);
		
	}
	
	return res;
	
}

/*6) Un procedimiento recursivo , dado un n, lo siguiente:
     n      ….  n!
     (n-1) …. (n-1)!
     (n-2) …. (n-2)!
      ………………
1	1
*/
void factoriales(int n){
	
	
	if(n>0){
		
		printf("%d ..... factorial: %d\n",n,factorial(n));
		factoriales(n-1);
		
	}
	
}

//Main
int main(){
	
//Variables
	
	int n1,fact,suma;
	
//Ingreso de datos
	
	leer_positivo(n1);
	
//Proceso

	fact=factorial(n1);
	suma=suma_suce_rec(n1);

//Salida de datos
	
	printf("\n\nEl factorial de %d es: %d",n1,fact);
	printf("\n\nLa suma sucesiva de %d es: %d\n\n",n1,suma);
	imp_num(n1);
	printf("\n");
	imp_impar_rec(n1);
	printf("\n");
	imp_par_rec(n1);
	printf("\n\n");
	factoriales(n1);
	

//Pausa y fin de programa
	
	pausar();
	return 0;
	
}
