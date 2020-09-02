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

//Main
int main(){
	
//Variables

	int n1,res,i;
	
	i=0;

//Ingreso de datos
	do{
		
		leer_nro_e("\n\nIngrese un valor: ",n1);

//Proceso
		
		res=div_devueltos_pos(n1);

//Salida de datos
	
		if(res!=-1){
		
			printf("\n\nCantidad de divisores: %d",res);
		
		}
		
		i++;
		
	}while(i<5);
	
	
//Pausa y fin de programa

	pausar();
	return 0;
	
}
