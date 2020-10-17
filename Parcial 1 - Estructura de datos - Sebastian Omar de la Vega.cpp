//Librerias
#include <stdio.h>
#include <stdlib.h>

//Lista
struct lista{
	
	int num;
	struct lista *sig;
	
};

//Funciones y Procedimientos

void pausar(){

	printf("\n\n\n\n");
	system("pause");

}

void leer_nro_e(char cade[30],int &n){
	
	printf("\n %s",cade);
	scanf("%d",&n);
	fflush(stdin);	
	
}

bool par_impar(int n){
	
	if(abs(n)%2==0){
		
		return true;
		
	}else{
		
		return false;
		
	}
	
}

void imp_lisse(struct lista *ini){
	
	struct lista *punt;
	
	punt=ini;
	
	if(punt!=NULL){
		
		printf("\n%d",punt->num);
		punt=punt->sig;
		imp_lisse(punt);
		
	}
	
}

/*1- Codificar un procedimiento que lea nros. hasta que aparezca un 0 y cargar una lista simplemente encadenada  con dichos nros. donde los mismos queden insertados de 
atrás hacia adelante.  Es decir, si se leen 1, 2, 3, 4, 0 se generara la LSE 4,  3, 2 , 1.
Su declaración será   void cargareves (struct lista *&com)*/
void cargareves(struct lista *&ini){
	
	struct lista *punt,*nue;
	int n,aux;
	
	leer_nro_e("\nIngrese un valor: ",n);
	
	if(n==0){
		
		ini=NULL;
		
	}else{
		
		ini=new struct lista;
		ini->num=n;
		ini->sig=NULL;
		punt=ini;
		
		leer_nro_e("\nIngrese un valor: ",n);
		
		while(n!=0){
			
			if(n!=0){
				
				nue=new struct lista;
				nue->num=n;
				nue->sig=NULL;
				nue->sig=punt;
				ini=nue;
				punt=ini;
				
			}
			
			leer_nro_e("\nIngrese un valor: ",n);
			
		}
		
	}
	
}

/*2- Codificar un procedimiento que muestre los contenidos impares de los nodos de una lista simplemente encadenada en forma recursiva.  
(Aclaración: es el contenido par, y no la posición par).
Su declaración será   void mostrarrecursivaimpar (struct lista *com)*/
void mostrarrecursivaimpar(struct lista *ini){
	
	struct lista *punt;
	
	punt=ini;
	
	if(punt!=NULL){
		
		if(!par_impar(punt->num)){
			
			printf("\n%d",punt->num);
			mostrarrecursivaimpar(punt->sig);
			
		}else{
			
			mostrarrecursivaimpar(punt->sig);
			
		}
			
	}
	
}

/*3- Codificar una función que  reciba una lista simplemente encadenada y devuelva verdadero si tiene por lo menos dos nodos y falso en caso contrario. 
Su declaración será   bool tienedos (struct lista  *com)*/
bool tienedos(struct lista *ini){
	
	struct lista *punt;
	bool valid=false;
	int cont;
	
	cont=0;
	punt=ini;
	
	while(punt!=NULL&&valid==false){
		
		cont++;
		punt=punt->sig;
		
		if(cont>=2){
		
			valid=true;
		
		}
		
	}
		
	return valid;	
	
}

/*4- Codificar un algoritmo que reciba una lista simplemente  encadenada y le  elimine  el segundo elemento si la lista tiene por lo menos dos nodos. 
Para ello, se invocará a la funcion tienedos del ejercicio 3.
Su declaración será   void eliminarsegundo (struct lista *&com).*/
void eliminarsegundo(struct lista *ini){
	
	struct lista *punt,*ant;
	int cont;
	
	cont=1;
	
	punt=ini;
	ant=punt;
	
	if(tienedos(punt)){
		
		while(punt!=NULL&&cont!=2){
			
			cont++;
			ant=punt;
			punt=punt->sig;
			
		}
		
		if(punt->sig==NULL){
			
			delete(punt);
			
		}else{
			
			ant->sig=punt->sig;
			delete(punt);
			punt=ant->sig;
			
		}
		
	}else{
		
		printf("\n\nLa lista tiene menos de dos nodos.\n\n");
		
	}
	
	
}

/*5- Codificar un programa principal (main) que cargue una lista simplemente encadenada desde el comienzo, muestre los impares de la misma por pantalla. 
Luego elimine el segundo nodo si lo tuviera y la muestre. */

//Main
int main(){

//Variables
	
	struct lista *in;
	
//Ingreso de datos
	
	cargareves(in);

	imp_lisse(in);
//Proceso
/*	if(in!=NULL){
		
		mostrarrecursivaimpar(in);
		printf("\n\n");
		eliminarsegundo(in);
	
//Salida de datos

		imp_lisse(in);
		
	}else{
		
		printf("\n\nLista Vacia\n\n");
		
	}
	*/
//Pausa y fin de programa

	pausar();
	return 0;

}

