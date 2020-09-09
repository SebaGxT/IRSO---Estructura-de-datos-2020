//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funciones y procedimientos

void pausar(){
	
	printf("\n\n\n\n");
	system("pause");
	
}

void captura_carac(char &let){
	
	printf("Ingrese caracter: ");
	scanf("%c",&let);
	fflush(stdin);
	
}

void imp_letinifin(int ini,int fin, int cod){
	
	if(ini==0){
		
		printf("\n\nLa letra inicial de la cadena %d es igual a la ingresada",cod);
		
	}else{
		
		printf("\n\nLa letra inicial de la cadena %d no es igual a la ingresada",cod);
		
	}
	if(fin==0){
		
		printf("\n\nLa letra final de la cadena %d es igual a la ingresada",cod);
		
	}else{
		
		printf("\n\nLa letra final de la cadena %d no es igual a la ingresada",cod);
		
	}
	
}

//1)Hacer un procedimiento que lea una cadena de caracteres.
void captura_cadena(char cade[]){
	
	printf("\nIngrese cadena: ");
	gets(cade);
	fflush(stdin);
	
}

//2)Hacer un procedimiento que muestre una cadena de caracteres  por pantalla. 
void cadena_imprimir(char cade[]){
	
	int i;
	
	for(i=0;i<strlen(cade);i++){
		
		printf("%c",cade[i]);
		
		if(i==strlen(cade)-1){
			
			printf("\n");
			
		}
		
	}
	
}

//3)Hacer una función que cuente cuantos carateres tiene.
char cont_carac(char cade[]){
	
	int i,cont;
	
	i=0;
	cont=0;
	
	while(cade[i]!='\0'){
		
		if(cade[i]!='\0'){
			
			cont++;
			i++;
			
		}
		
	}
	
	return cont;
	
}

//4)Hacer una función que cuente cuantas letras iguales a una letra dada tiene. La letra se pasará por parámetro.
char let_igual(char cade[],char let){
	
	int i,cont;

	cont=0;
	
	for(i=0;i<strlen(cade);i++){
		
		if(cade[i]==let){
			
			cont++;
			
		}
		
	}
	
	return cont;
	
}

//5)Hacer una función que determine si una cadena de caracteres empieza con una letra dada. La letra se pasará por parámetro.
char let_ini(char cade[],char let){
	
	int cmp;
	
	if(cade[0]==let){
		
		cmp=0;
		
	}else if(cade[0]<let){
		
		cmp=-1;
		
	}else{
		
		cmp=1;
		
	}
	
	return cmp;
	
}

//6)Hacer una función que determine si una cadena de caracteres termina  con una letra dada. La letra se pasará por parámetro.
char let_fin(char cade[],char let){
	
	int cmp,leng;
	
	leng=strlen(cade)-1;
	
	if(cade[leng]==let){
		
		cmp=0;
		
	}else if(cade[leng]<let){
		
		cmp=-1;
		
	}else{
		
		cmp=1;
		
	}
	
	return cmp;
	
}
//7)Hacer un procedimiento  que reciba dos cadenas de caracteres e imprima si ambas cadenas son iguales, la primera menor o mayor que la segunda.
void orden_cad(char cade1[],char cade2[]){
	
	int cmp;
	
	cmp=strcmp(cade1,cade2);
	
	if(cmp==0){
		
		printf("\n\nLas cadenas son iguales\n\n");
		
	}else if(cmp==-1){
		
		printf("\n\nLa primer cadena esta antes que la segunda cadena\n\n");
		
	}else{
		
		printf("\n\nLa segunda cadena esta antes que la primera cadena\n\n");
		
	}
	
}
//Main
int main(){

//Variables

	char cad1[30],cad2[30], let1,let2;
	int con1,con2,letig1,letig2,ini1,ini2,fin1,fin2;
	

//Ingreso de datos
	
	captura_cadena(cad1);
	printf("\n");
	captura_cadena(cad2);
	printf("\n");
	captura_carac(let1);
	printf("\n");
	captura_carac(let2);
	printf("\n");
	
//Proceso
	
	printf("\n");
	cadena_imprimir(cad1);
	printf("\n");
	
	con1=cont_carac(cad1);
	con2=cont_carac(cad2);
	letig1=let_igual(cad1,let1);
	letig2=let_igual(cad2,let2);
	ini1=let_ini(cad1,let1);
	ini2=let_ini(cad2,let2);
	fin1=let_fin(cad1,let1);
	fin2=let_fin(cad2,let2);
	

//Salida de datos

	printf("\n\nCantidad de caracteres de cadena 1 es: %d",con2);
	printf("\n\nCantidad de caracteres de cadena 2 es: %d",con2);
	printf("\n\nLa letra 1 es: %c",let1);
	printf("\n\nLa letra 2 es: %c",let2);
	printf("\n\nCantidad de letras iguales %c:  %d",let1,letig1);
	printf("\n\nCantidad de letras iguales %c:  %d",let2,letig2);
	imp_letinifin(ini1,fin1,1);
	imp_letinifin(ini2,fin2,2);
	orden_cad(cad1,cad2);

//Pausa y fin de programa

	pausar();
	return 0;
	
}
