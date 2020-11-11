//Librerias
#include <stdio.h>
#include <stdlib.h>

//1) Definir la estructura de pila.
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

bool par_impar(int n){
	
	if(n%2==0){
		
		return true;
		
	}else{
		
		return false;
		
	}
	
}

bool enc_n_pil(struct pila *pil,int n){
	
	struct pila *p;
	bool valid;
	
	valid=false;
	p=pil;
	
	while(p!=NULL&&valid==false){
		
		if(p->num==n){
			
			valid=true;
			
		}else{
			
			p=p->sig;
			
		}
		
	}
	
	return valid;
	
}

//2) Un procedimiento para empezar a usar una pila vacía. void crear_pila (struct pila *&pil).
void crear_pila(struct pila *&pil){
	
	pil=NULL;
	
}

//4) Una función que determina si la pila esta vacia. Devuelve 0 si está vacía  y 1 en caso contrario. int  pila_vacía (struct pila *pil).
bool pila_vacia(struct pila *pil){
	
	if(pil==NULL){
		
		return true;
		
	}else{
		
		return false;
		
	}
	
}

//5) Una función que determina si la pila esta llena. Devuelve 0 si está llena  y 1 en caso contrario. int  pila_llena (struct pila *pil).
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

//3) Un procedimiento para insertar en una pila un nro entero que no debe hacer desbodar la misma. void insertar _pila (struct pila *&pil, int n).
void insertar_pila(struct pila *&pil, int n){
	
	struct pila *nue;
	
	nue= new struct pila;
	nue->num=n;
	nue->sig=pil;
	pil=nue;
	
}

//6) Un procedimiento para sacar un elemento de la pila si esta no esta vacía. void sacar_arbol (struct pila *&pil, int &n).
void sacar_pila(struct pila *&pil, int &n){
	
	struct pila *p;
	
	n=pil->num;
	p=pil;
	pil=pil->sig;
	delete(p);
	
}

void vaciar_pila(struct pila *&pil){
	
	int n;
	
	while(!pila_vacia(pil)){
		
		sacar_pila(pil,n);
		
	}
	
	crear_pila(pil);
	
}

/*7) 
-Armar un programa  usando los procedimientos y funciones definidas que lea varios nros (con cualquier criterio) e intente insertarlos en una pila que comenzará 
vacía.
- Se deben descartar los que hagan desbordar la pila. 
-Luego mostrar su contenido. Usar un procedimiento.
- Luego intentar eliminar el tope de la pila, mostrar su contenido.
- Luego intentar eliminar la base de la pila, mostrar su contenido.
- Finalmente mostrar cuantos elementos quedaron en la pila. Esto último hacerlo con una función. */

//Main
int main(){

//Variables

	struct pila *pila1,*pila2, *aux1, *aux2;
	int n,n2,cantpil,cmp;
	bool valid;


//Ingreso de datos
	
	do{
		
		leer_nro_e("Ingrese el espacio maximo de pila: ",MAXPILA);
		
		if(MAXPILA<1){
			
			printf("\n\nDebe ingresar un valor positivo mayor a 0.\n\n");
			
		}	
		
	}while(MAXPILA<1);
	
	crear_pila(pila1);
	crear_pila(pila2);
	crear_pila(aux1);
	crear_pila(aux2);

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
	
	vaciar_pila(pila1);	
			
	printf("\n\n********************8 y 9********************");

//8) Cargar una pila. Mostrar su contenido. Luego mostrar su contenido en orden inverso al dado, dejando la pila como estaba originalmente.
//9) Cargar una pila. Mostrar su contenido. Luego leer un número y mostrar cuantas veces dicho número estaba en la pila,  dejando la pila como estaba originalmente.
	
	printf("\n\nSe mostrara la pila al derecho y al inverso\n\n");
	printf("\n\nInserci%cn de valores en la pila, finaliza con 0 o al llenar la pila\n\n",162);
	leer_nro_e("\nIngrese un valor: ",n);
	
	cantpil=0;
	valid=false;
	
	if(n!=0){
		
		while(n!=0&&valid==false){
			
			if(!pila_llena(pila2)){
				
				insertar_pila(pila2,n);
				leer_nro_e("\nIngrese un valor: ",n);
				
			}else{
				
				printf("\n\nPila llena, no hay espacio.\n\n");
				valid=true;
				
			}
	
		}
		
		if(pila2!=NULL){
			
			printf("\n\nBusqueda de n%cmero cantidad de veces existente en la pila\n\n",163);
			leer_nro_e("Ingrese un valor a buscar: ",cmp);	
		
			while(!pila_vacia(pila2)){
			
				//Transferencia a pilas aux
				sacar_pila(pila2,n);
				if(!pila_llena(aux1)&&!pila_llena(aux2)){
					
						if(cmp==n){
						
							cantpil++;
						
						}
					
						insertar_pila(aux1,n);
						insertar_pila(aux2,n);
					
					}
				
			}
		
			//Tranferencia a pila principal
			while(!pila_vacia(aux2)){
		
				sacar_pila(aux2,n);
				if(!pila_llena(pila2)){
			
					insertar_pila(pila2,n);
			
				}
		
			}
	
			printf("\n\nPila\n");
			mostrar_pila(pila2);
			printf("\n\nPila al inverso\n");
			mostrar_pila(aux1);
			
			if(cantpil>0){
				
				printf("\n\nCantidad de veces que se repite el n%cmero: %d",163,cantpil);	
				
			}else{
				
				printf("\n\nEl n%cmero no se encuentra en la pila.\n\n",163);
				
			}
		
		}else{
			
			printf("\n\nPila vacia.\n\n");
			crear_pila(pila2);
			
		}
		
	}else{
		
		printf("\n\nPila vacia no se cargaron valores.\n");
		
	}
	
	vaciar_pila(pila2);
	printf("\n\n********************10********************");
		
//10) Cargar una pila. Mostrar su contenido. Luego leer un número y eliminarlo todas las veces que aparece en la pila. Mostrar como quedó la pila.
	
	printf("\n\nLeer un n%cmero a borrar\n\n",163);
	printf("\n\nInserci%cn de valores en la pila, finaliza con 0 o al llenar la pila\n\n",162);
	leer_nro_e("\nIngrese un valor: ",n);
	
	valid=false;
	
	if(n!=0){
		
			while(n!=0&&valid==false){
			
				if(!pila_llena(pila2)){
				
					insertar_pila(pila2,n);
					
					leer_nro_e("\nIngrese un valor: ",n);
					
				}else{
				
					printf("\n\nPila llena, no hay espacio.\n\n");
					valid=true;
					
				}
			
			}
			
			if(pila2!=NULL){
				
				printf("\n\nPila\n");
				mostrar_pila(pila2);
				printf("\n\nEliminar un n%cmero, se borrara todas las veces que aparesca.\n\n",163);
				leer_nro_e("Ingrese un valor: ",cmp);
				
				if(enc_n_pil(pila2,cmp)){
					
					while(!pila_vacia(pila2)){
				
						sacar_pila(pila2,n);
				
						if(n!=cmp){
					
							if(!pila_llena(aux2)){
					
							insertar_pila(aux2,n);
						
							}
					
						}
					
					}
			
					while(!pila_vacia(aux2)){
				
						sacar_pila(aux2,n);
				
						if(!pila_llena(pila2)){
					
							insertar_pila(pila2,n);
					
						}
				
					}
			
					if(pila2!=NULL){
				
						printf("\n\nPila luego de eliminar n%cmero\n",163);
						mostrar_pila(pila2);
				
					}else{
				
						printf("\n\nPila vacia");
						crear_pila(pila2);
				
					}
					
				}else{
					
					printf("\n\nEl n%cmero no se encuentra en la pila.\n\n",163);
					
				}
				
				
			}else{
				
				printf("\n\nPila vacia.\n\n");
				crear_pila(pila2);
				
			}
			
	}else{
		
		printf("\n\nPila vacia no se cargaron valores.\n");
		
	}
	
	vaciar_pila(pila2);
	printf("\n\n********************11********************");
	
//11) Cargar una pila. Mostrar su contenido. Luego intercambiar el tope con la base de la misma. Mostrar como quedó la pila.
	
	printf("\n\nIntercambio de base y tope\n\n");
	printf("\n\nInserci%cn de valores en la pila, finaliza con 0 o al llenar la pila\n\n",162);
	leer_nro_e("\nIngrese un valor: ",n);
	
	n2=0;
	cantpil=0;
	cmp=0;
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
			
			if(pila1!=NULL){
				
				printf("\n\nPila\n");
				mostrar_pila(pila1);
				
				cantpil=cant_pila(pila1);
				
				if(cantpil>1){
					
					//Transfiere tope a variable auxiliar
					sacar_pila(pila1,cmp);
			
					//Transfiere pila principal a pila auxiliar
					while(!pila_vacia(pila1)){
				
						sacar_pila(pila1,n);
				
						if(!pila_llena(aux1)){
					
							insertar_pila(aux1,n);
					
						}
				
					}
			
					//Transfiere base a variable auxiliar
					sacar_pila(aux1,n2);
			
					//Transfiere tope a pila principal como base
					if(!pila_llena(pila1)){
				
						insertar_pila(pila1,cmp);
				
					}
			
					//Transfiere de pila auxiliar a pila principal
					while(!pila_vacia(aux1)){
				
						sacar_pila(aux1,n);
				
						if(!pila_llena(pila1)){
					
							insertar_pila(pila1,n);
					
						}
					
					}
			
					//Transfiere base a pila principal como tope desde variable auxiliar
					if(!pila_llena(pila1)){
				
						insertar_pila(pila1,n2);
				
					}
			
					printf("\n\nPila, tope y base intercambiados\n");
					mostrar_pila(pila1);
					
				}else{
					
					printf("\n\nLa pila no tiene elementos suficientes.\n\n");
					
				}
				
				
			}else{
				
				printf("\n\nPila vacia.\n\n");
				crear_pila(pila1);
				
			}
			
	}else{
		
		printf("\n\nPila vacia no se cargaron valores.\n");
		
	}
	
	vaciar_pila(pila1);
	printf("\n\n********************12********************");

/*12) Cargar una pila. Mostrar su contenido. Luego quitarle los elementos que estuvieran en posicion par desde la base, es decir, el segundo, el cuarto, el sexto, etc.
 Mostrar como quedó la pila.*/
	
	printf("\n\nEliminar n%cmeros en posici%cn par.\n\n",163,162);
	printf("\n\nInserci%cn de valores en la pila, finaliza con 0 o al llenar la pila\n\n",162);
	leer_nro_e("\nIngrese un valor: ",n);
	
	valid=false;
	n2=1;
	
	if(n!=0){
		
			while(n!=0&&valid==false){
			
				if(!pila_llena(pila2)){
				
					insertar_pila(pila2,n);
					
					leer_nro_e("\nIngrese un valor: ",n);
					
				}else{
				
					printf("\n\nPila llena, no hay espacio.\n\n");
					valid=true;
					
				}
			
			}
			
			printf("\n\nPila\n");
			mostrar_pila(pila2);
			
			//Transfiere los de posición impar a pila auxiliar, elimina los de posición par
			while(!pila_vacia(pila2)){
				
				if(par_impar(n2)){
					
					sacar_pila(pila2,n);
					
				}else{
					
					sacar_pila(pila2,n);
					
					if(!pila_llena(aux2)){
						
						insertar_pila(aux2,n);
						
					}
					
				}
				
				n2++;
				
			}
			
			//Transfiere los de posición impar a pila principal
			while(!pila_vacia(aux2)){
				
				sacar_pila(aux2,n);
				
				if(!pila_llena(pila2)){
					
					insertar_pila(pila2,n);
					
				}
				
			}
			
			printf("\n\nPila\n");
			mostrar_pila(pila2);
			
	}else{
		
		printf("\n\nPila vacia no se cargaron valores.\n");
		
	}
	
	vaciar_pila(pila2);
	printf("\n\n********************13********************");

/*13) Cargar una pila. Mostrar su contenido. Luego quitarle los elementos que estuvieran en posicion impar desde la base, es decir, el primer, el tercero, el quinto, etc.
 Mostrar como quedó la pila.*/
	
	printf("\n\nEliminar n%cmeros en posici%cn impar.\n\n",163,162);
	printf("\n\nInserci%cn de valores en la pila, finaliza con 0 o al llenar la pila\n\n",162);
	leer_nro_e("\nIngrese un valor: ",n);
	
	valid=false;
	n2=1;
	
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
			
			//Transfiere los de posición par a pila auxiliar, elimina los de posición impar
			while(!pila_vacia(pila1)){
				
				if(!par_impar(n2)){
					
					sacar_pila(pila1,n);
					
				}else{
					
					sacar_pila(pila1,n);
					
					if(!pila_llena(aux1)){
						
						insertar_pila(aux1,n);
						
					}
					
				}
				
				n2++;
				
			}
			
			//Transfiere los de posición par a pila principal
			while(!pila_vacia(aux1)){
				
				sacar_pila(aux1,n);
				
				if(!pila_llena(pila1)){
					
					insertar_pila(pila1,n);
					
				}
				
			}
			
			printf("\n\nPila\n");
			mostrar_pila(pila1);
			
	}else{
		
		printf("\n\nPila vacia no se cargaron valores.\n");
		
	}
	
	vaciar_pila(pila1);

//Pausa y fin de programa

	pausar();
	return 0;

}
