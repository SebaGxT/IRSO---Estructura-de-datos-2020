//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Funciones y procedimientos
void leer_nro_e(char cade[30],int &n){
	
	printf("\n %s: ",cade);
	fflush(stdin);	
	scanf("%d",&n);

}

void leer_nro_f(char cade[30],float &n){
	
	printf("\n %s: ",cade);
	fflush(stdin);	
	scanf("%f",&n);

}

//1) Una función que reciba dos enteros y devuelva la suma de ellos.
int suma_func(int n1, int n2){
	
	int res;
	
	res=n1+n2;
	
	return res;
	
}

//2) Idem ejercicio anterior pero con un procedimiento. Utilizar un parámetro de salida.
void suma_proced(int n1, int n2, int &res){
	
	res=n1+n2;
		
}

//3) Un procedimiento que lea y devuelva un entero.
void entero_n(int &n){
	
	printf("\nIngrese un valor: ");
	scanf("%d",&n);
	fflush(stdin);
	
}

//4) Una función que reciba dos enteros y devuelva el producto de ambos por sumas sucesivas. 
int producto_suce_func(int n1, int n2){
	
	int i,res;
	
	res=0;
	
	for(i=1;i<=abs(n2);i++){
		
		res+=n1;
		
	}
	
	if(n2<0){
		
		res=res*(-1);
		
	}
	
	return res;
	
}

//5) Idem ejercicio anterior pero con un procedimiento.
void producto_suce_proced(int n1, int n2, int &res){
	
	int i;
	
	res=0;
	
	for(i=1;i<=abs(n2);i++){
		
		res+=n1;
		
	}
	
	if(n2<0){
		
		res=res*(-1);
		
	}
	
}

//6) Una función que reciba dos enteros y devuelva el mayor de ambos.
int may_func(int n1, int n2){
		
	int may;
	
	if(n1>n2){
		
		may=n1;
		
	}else{
		
		may=n2;
		
	}
	
	return may;
	
}

//7) Un procedimiento que reciba dos enteros e imprima el menor de ellos.
void men_proced(int n1, int n2,int &res){
		
	if(n1<n2){
		
		res=n1;
		
	}else{
		
		res=n2;
		
	}
	
}

//8) Una función que reciba dos enteros y devuelva la división  de ambos por restas sucesivas. 
int divis_func(int n1, int n2){
	
	int cont,res;
	
	cont=0;
	res=abs(n1);
	
	while(res>=abs(n2)){
			
		res=res-abs(n2);
		cont++;
				
	}
	
	if((n1<0)&&(n2>0)||(n1>0)&&(n2<0)){
		
		cont=cont*(-1);
		
	}
	
	return cont;
	
}

//9) Idem ejercicio anterior pero con un procedimiento.
void divis_proced(int n1, int n2, int &res){
	
	int cont;
	
	cont=0;
	res=abs(n1);
	
	while(res>=abs(n2)){
			
		res=res-abs(n2);
		cont++;
				
	}
	
	if((n1<0)&&(n2>0)||(n1>0)&&(n2<0)){
		
		cont=cont*(-1);
		
	}
	
	res=cont;
		
}

//10) Una función que reciba dos enteros a y b y devuelva ab . a elevado b - potencia
float potencia(float n1, float n2){
	
	int i;
	
	float x;
	
	x=n1;
	
	for(i=1;i<abs(n2);i++){
		
		x=x*n1;
		
	}
	
	if(n2<0){
		
		x=1/x;
		
	}
	
	
	return x;
	
}

//Main
int main(){

//Variables
	
	int num1,num2,num5,rese,rese2,rese3,rese4,rese5,rese6,may,men;
	float num3,num4,resf;
	
//Ingreso de datos
	
	leer_nro_e("\nIngrese valor  1: ",num1);
	leer_nro_e("\nIngrese valor  2: ",num2);
	leer_nro_f("\nIngrese un base: ",num3);
	leer_nro_f("\nIngrese un exponente: ",num4);

	
//Proceso

	rese=suma_func(num1,num2);
	suma_proced(num1,num2,rese2);
	resf=potencia(num3,num4);
	entero_n(num5);
	rese3=producto_suce_func(num1,num2);
	producto_suce_proced(num1,num2,rese4);
	may=may_func(num1,num2);
	men_proced(num1,num2,men);
	rese5=divis_func(num1,num2);
	divis_proced(num1,num2,rese6);
	
//Salida de datos
	
	printf("\n\nValor ingresado procedimiento entero_n: %d",num5);
	printf("\n\nResultado funcion suma: %d",rese);
	printf("\n\nResultado procedimiento suma: %d",rese2);
	printf("\n\nProducto funcion suma sucesiva: %d",rese3);
	printf("\n\nProducto procedimiento suma sucesiva: %d",rese4);
	printf("\n\nMayor funcion: %d",may);
	printf("\n\nMenor procedimiento: %d",men);
	printf("\n\nDivision funcion: %d",rese5);
	printf("\n\nDivision procedimiento: %d",rese6);
	printf("\n\nFuncion potencia: %f",resf);

//Pausa y fin de programa

	printf("\n\n\n\n");
	system("pause");
	return 0;
	
}
