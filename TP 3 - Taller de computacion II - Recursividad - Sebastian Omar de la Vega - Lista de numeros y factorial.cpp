//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funciones y procedimientos

void pausar(){
	
	printf("\n\n\n\n");
	system("pause");
	
}

void leer_positivo(char cade[30], int &n){	
		
	printf("\n %s",cade);
	scanf("%d",&n);
	fflush(stdin);
	
	while(n<0){
		
		printf("\n\nPor favor ingrese un valor positivo.\n");
		printf("\n %s",cade);
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

int factorial(int n){
	
	int res;
	
	if(n==0){
		
		res=1;
		
	}else{
		
		res=n*factorial(n-1);
		
	}
	
	return res;
	
}

void factoriales(int n){
	
	
	if(n>0){
		
		printf("%d ..... factorial: %d\n",n,factorial(n));
		factoriales(n-1);
		
	}
	
}

//Main
int main(){
	
//Variables
	
	int n1;
	
//Ingreso de datos
	
	leer_positivo("Ingrese un valor positivo: ",n1);
	

//Salida de datos
	
	printf("\n");
	factoriales(n1);
	

//Pausa y fin de programa
	
	pausar();
	return 0;
	
}
