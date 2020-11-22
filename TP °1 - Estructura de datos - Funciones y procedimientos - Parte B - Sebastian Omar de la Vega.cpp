//Librerias
#include <stdio.h>
#include <stdlib.h>

//Funciones y procedimientos

void pausar(){
	
	printf("\n\n\n\n");
	system("pause");
	
}

void leer_nro_e(char cade[30],int &n){
	
	printf("\n %s: ",cade);
	fflush(stdin);	
	scanf("%d",&n);

}

void leer_nro_f(char cade[30],int &n){
	
	printf("\n %s: ",cade);
	fflush(stdin);	
	scanf("%f",&n);

}

int may_func(int n1, int n2){
		
	int may;
	
	if(n1>n2){
		
		may=n1;
		
	}else{
		
		may=n2;
		
	}
	
	return may;
	
}

bool par_impar(int n){
	
	if(n%2==0){
		
		return true;
		
	}else{
		
		return false;
		
	}
	
}

//1) Un procedimiento que lea un entero positivo validado. Leer varios positivos y mostrar cuantos de ello fueran pares. Para ello hacer una función que  reciba un entero y devuelva 1  si el entero fuera par y 0 en caso contrario.

void leer_positivo(int &n){	
	
	do{
		
		printf("\nIngrese un valor positivo: ");
		scanf("%d",&n);
		fflush(stdin);
		
		if(n<0){
			
			printf("\n\nPor favor ingrese un valor positivo.\n\n");
			
		}
		
	}while(n<0);
					
}

//2) Un procedimiento que lea un nro impar. Leer varios pares de enteros  impares y por cada par mostrar una leyenda aclaratoria dependiendo de cual fuera el mayor. Para ello hacer  una función que reciba dos enteros y devuelva el mayor de ambos. 

void leer_impar(int &n){
	
		do{
			
			leer_nro_e("\nIngrese un valor: ",n);
				
			if(par_impar(n)==true){
				
				printf("\n\nDebe ingresar un n%cmero impar por favor.\n\n",163);
				
			}
			
		}while(par_impar(n)==true);
	
}

//3) Una función que reciba un entero positivo  y devuelva la cantidad divisores que tiene el mismo. Luego leer 5 enteros positivos y por cada uno  mostrar cuantos divisores tiene cada uno.
int div_devueltos_pos(int n){
	
	int i,cont,x;
	
	cont=1;
	
	if(n>0){
		
		if(n%2==0){
			
			x=n/2;
			
		}else{
			
			x=(n-1)/2;
			
		}
		
		for(i=1;i<=x;i++){
			
			if(n%i==0){
				
				cont++;
				
			}
			
		}
		
	}else{
		
		cont=-1;
		
	}
			
	return cont;
	
}

//4) Idem anterior pero con enteros positivos o negativos.  
int div_devueltos_posneg(int n){
	
	int i,cont,x,y;
	
	cont=1;
	y=abs(n);

		
	if(y%2==0){
			
		x=y/2;
			
	}else{
			
		x=(y-1)/2;
		
	}
		
	for(i=1;i<=x;i++){
			
		if(y%i==0){
				
			cont++;
				
		}
			
	}
				
	return cont;
		
}

//5) Leer 5 enteros y por cada uno de ellos calcular su factorial. Usar una función que calcule el factorial.
double factoriales(int n){
	
	int i; 
	double fact;
	
	fact=1;
	
	for(i=1;i<=abs(n);i++){
		
		fact=fact*i;
		
	}
	
	return fact;
	
}

//6) Leer una cantidad positiva y luego  leer dicha cantidad de enteros no nulos y por cada uno calcular la suma de valores desde 1 a dicho nro. Ejemplo, si el nro es 4 devolvera 1+2+3+4.
int suma_consecutiva(int n){
	
	int i,cont;
	
	cont=0;
	
	for(i=1;i<=n;i++){
		
		cont+=i;
		
	}
	
	return cont;
	
}
//Main
int main(){

//Variables
	int i,n1,n2,contpar,may,div,sum;
	double fact;
	contpar=0;
	
//Ingreso de datos

	for(i=0;i<5;i++){
		
		leer_positivo(n1);
		
		if(par_impar(n1)){
			
			contpar++;
			
		}
		
	}
	
	printf("\n\nLa cantidad de numeros par ingresados: %d",contpar);
	
	for(i=0;i<5;i++){
		
		leer_impar(n1);
		leer_impar(n2);
		
		may=may_func(n1,n2);
		
		printf("\n\nEl mayor es %d",may);
		
	}
	
	for(i=0;i<5;i++){
		
		leer_positivo(n1);
		div=div_devueltos_pos(n1);
		
		printf("\n\nLa cantidad de divisores que tiene el n%cmero %d es: %d\n",163,n1,div);
		
	}
	
	for(i=0;i<5;i++){
		
		leer_nro_e("\n\nIngrese un valor: ",n1);
		
		div=div_devueltos_posneg(n1);
		
		printf("\n\nLa cantidad de divisores que tiene el n%cmero %d es: %d",163,n1,div);
		
	}
	
	for(i=0;i<5;i++){
		
		leer_nro_e("\n\nIngrese un valor a factorizar: ",n1);
		fact=factoriales(n1);
		printf("\n\nEl factorial del n%cmero %d: %.0f",163,n1,fact);
				
	}
	
	for(i=0;i<5;i++){
		
		leer_positivo(n1);
		sum=suma_consecutiva(n1);
		
		printf("\n\nLa suma de numeros consecutivos es: %d\n",sum);
		
	}

//Pausa y fin de programa

	pausar();
	return 0;
	
}
