//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funicones y procedimientos

void pausar(){
	
	printf("\n\n\n\n");
	system("pause");
	
}

void captura_carac(char &let){
	
	printf("Ingrese caracter: ");
	scanf("%c",&let);
	fflush(stdin);
	
}

void captura_cadena(char cade[]){
	
	printf("\nIngrese cadena: ");
	gets(cade);
	fflush(stdin);
	
}

int let_fin(char cade[],char let){
	
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

//Main
int main(){

//Variables

	char cad[30], let;
	int fin;
		
//Ingreso de datos

	captura_cadena(cad);
	captura_carac(let);

//Proceso
	
	fin=let_fin(cad,let);
 	
//Salida de datos

	if(fin==0){
		
			printf("\n\nLa letra final de la cadena es igual a la ingresada");
		
	}else{
		
			printf("\n\nLa letra final de la cadena no es igual a la ingresada");
		
	}

//Pausa y fin de programa

	pausar();
	return 0;
	
}
