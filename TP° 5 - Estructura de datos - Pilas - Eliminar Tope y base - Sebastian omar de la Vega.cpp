/*
Ejercicio 7 Pilas.

-Armar un programa  usando los procedimientos y funciones definidas que lea varios nros (con cualquier criterio) y intente insertarlos en una pila que comenzará vacía. 
-Se deben descartar los que hagan desbordar la pila.
-Luego mostrar su contenido. Usar un procedimiento.
-Luego intentar eliminar el tope de la pila, mostrar su contenido.
-Luego intentar eliminar la base de la pila, mostrar su contenido.
-Finalmente mostrar cuantos elementos quedaron en la pila. Esto último hacerlo con una función. 

*/
//Librerias
#include <stdio.h>
#include <stdlib.h>

//Pilas
struct pila{
	
	int num;
	struct pila *sig;

};

int MAXPILA;

//Funciones y Procedimientos

void pausar(){

	printf("\n\n\n\n");
	system("pause");

}

void leer_nro_e(char cade[30],int &n){
	
	printf("\n %s",cade);
	fflush(stdin);	
	scanf("%d",&n);

}

void mostrar_pila(struct pila *pil){
	
	struct pila *p;
	
	p=pil;
	
	while(p!=NULL){
		
		printf("\n%d",p->num);
		p=p->sig;
		
	}
	
}

int cant_pila(struct pila *pil){
	
	struct pila *p;
	int cant;
	
	cant=0;
	p=pil;
	
	while(p!=NULL){
		
		cant++;
		p=p->sig;
		
	}
	
	return cant;
	
}

void crear_pila(struct pila *&pil){
	
	pil=NULL;
	
}

bool pila_vacia(struct pila *pil){
	
	if(pil==NULL){
		
		return true;
		
	}else{
		
		return false;
		
	}
	
}

bool pila_llena(struct pila *pil){
	
	int cont;
	struct pila *p;
	
	cont=0;
	p=pil;
	
	while(p!=NULL){
		
		cont++;
		p=p->sig;
		
	}
	
	if(cont==MAXPILA){
		
		return true;
		
	}else{
		
		return false;
		
	}	
	
}

void insertar_pila(struct pila *&pil, int n){
	
	struct pila *nue;
	
	nue= new struct pila;
	nue->num=n;
	nue->sig=pil;
	pil=nue;
	
}

void sacar_pila(struct pila *&pil, int &n){
	
	struct pila *p;
	
	n=pil->num;
	p=pil;
	pil=pil->sig;
	delete(p);
	
}

//Main
int main(){

//Variables
	
	struct pila *pila1, *aux1;
	int n, cantpil;
	bool valid;
	
//Ingreso de datos
	
	do{
		
		leer_nro_e("Ingrese el espacio maximo de pila: ",MAXPILA);
		
		if(MAXPILA<1){
			
			printf("\n\nDebe ingresar un valor positivo mayor a 0.\n\n");
			
		}	
		
	}while(MAXPILA<1);
	
	crear_pila(pila1);
	crear_pila(aux1);

//Proceso //Salida de datos

	printf("\n\nEliminar tope y base de la pila\n\n");
	printf("\n\nInserci%cn de valores en la pila, finaliza con 0 o al llenar la pila\n\n",162);
	leer_nro_e("\nIngrese un valor: ",n);
	
	valid=false;
	
	if(n!=0){
		
			while(n!=0&&valid==false){
			
				if(!pila_llena(pila1)){
				
					insertar_pila(pila1,n);
					
					leer_nro_e("\nIngrese un valor: ",n);
					
				}else{
				
					printf("\n\nPila llena, no hay espacio.\n\n");
					valid=true;
					
				}
					
			}
		
		printf("\n\nPila\n");
		mostrar_pila(pila1);
		//Elimina tope
		sacar_pila(pila1,n);
		printf("\n\nTope Eliminado\n");
		if(pila1!=NULL){
			
			mostrar_pila(pila1);
	
			//Transferencia a auxiliar
			while(!pila_vacia(pila1)){
		
				sacar_pila(pila1,n);
				if(!pila_llena(aux1)){
				
						insertar_pila(aux1,n);
				
					}
		
			}
			//Elimina base
			sacar_pila(aux1,n);
	
			//Tranferencia a pila
			while(!pila_vacia(aux1)){
		
				sacar_pila(aux1,n);
				if(!pila_llena(pila1)){
			
					insertar_pila(pila1,n);
			
				}
		
			}
	
			if(pila1!=NULL){
				
				printf("\n\nBase Eliminada\n");
				mostrar_pila(pila1);
				
			}else{
			
				printf("\n\npila vacia\n\n");
				crear_pila(pila1);
			
			}
	
			cantpil=cant_pila(pila1);
			printf("\n\nCantidad de elementos en la pila: %d\n\n",cantpil);	
		
		}else{
			
			printf("\n\npila vacia\n\n");
			crear_pila(pila1);
			
		}
		
	}else{
		
		printf("\n\nPila vacia no se cargaron valores.\n");
		
	}

//Pausa y fin de programa

	pausar();
	return 0;

}
