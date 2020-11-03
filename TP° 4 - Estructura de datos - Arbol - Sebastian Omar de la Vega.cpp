//Librerias
#include <stdio.h>
#include <stdlib.h>

//Arbol
//1) Definir la estructura de árbol.
struct arbol{
	
	int num;
	struct arbol *der;
	struct arbol *izq;
		
};

//Funciones y Procedimientos

void pausar(){

	printf("\n\n\n\n");
	system("pause");

}

void leer_nro_e(char cade[30],int &n){
	
	printf("\n %s: ",cade);
	fflush(stdin);	
	scanf("%d",&n);

}

//2) Un procedimiento para empezar a usar un árbol con la raíz vacía. void crear_arbol (struct árbol *&raiz).
void crear_arbol(struct arbol *&ra){
	
	ra=NULL;
	
}

//4) Una función que determina si un nro entero está o no en el árbol. Devuelve 0 si no está y 1 si está.int  esta _arbol (struct árbol *raíz, int n).
bool buscanro_arbol(struct arbol *&ra, int n){
	
	struct arbol *punt;
	bool valid;
	
	valid=false;
	punt=ra;
	
	while(punt!=NULL&&valid==false){
		
		if(punt->num==n){
			
			valid=true;
			
		}else{
			
			if(punt->num>n){
				
				punt=punt->izq;
				
			}else{
				
				punt=punt->der;
				
			}
			
		}
		
	}
	
	return valid;
	
}

//3) Un procedimiento para insertar en un árbol un nro entero que no debe existir en el mismo.void insertar _arbol (struct árbol *&raíz, int n).
void insert_arbol(struct arbol *&ra,int n){
	
	struct arbol *punt,*ant,*nue;
	
	nue=new struct arbol;
	nue->num=n;
	nue->der=NULL;
	nue->izq=NULL;
	
	if(ra!=NULL){
		
		punt=ra;
		ant=ra;
		
		while(punt!=NULL){
			
			ant=punt;
			
			if(punt->num>n){
				
				punt=punt->izq;
				
			}else{
				
				punt=punt->der;
				
			}
			
		}
		
		if(ant->num>n){
			
			ant->izq=nue;
			
		}else{
			
			ant->der=nue;
			
		}
		
	}else{
		
		ra=nue;
		
	}
	
}

//5) Un procedimiento para recorrer o mostrar los nodos de un árbol con cualquier criterio. void mostrar _arbol (struct árbol *raíz).
void imp_arbol_rec(struct arbol *ra){
	
	if(ra!=NULL){
		
		//IRD
		imp_arbol_rec(ra->izq);
		printf("\n%d",ra->num);
		imp_arbol_rec(ra->der);
		
		/*
		
		//IDR
		
		imp_arbol_rec(ra->izq);
		imp_arbol_rec(ra->der);
		printf("\n%d",ra->num);
		
		//RID
		
		printf("\n%d",ra->num);
		imp_arbol_rec(ra->izq);
		imp_arbol_rec(ra->der);
		
		//RDI
		
		printf("\n%d",ra->num);
		imp_arbol_rec(ra->der);
		imp_arbol_rec(ra->izq);
		
		//DIR
		
		imp_arbol_rec(ra->der);
		imp_arbol_rec(ra->izq);
		printf("\n%d",ra->num);
		
		//DRI
		
		imp_arbol_rec(ra->der);
		printf("\n%d",ra->num);
		imp_arbol_rec(ra->izq);
		
		*/
		
	}
	
}

//6) Un procedimiento para eliminar de un árbol un nro entero que debe existir en el mismo.void eliminar _arbol (struct árbol *&raíz, int n).
void borrar_hoja(struct arbol *&ra, struct arbol *punt, struct arbol *ant, int n){
	
	if(punt==ra){
		
		ra=NULL;
		
	}else{
		
		if(ant->izq==punt){
			
			ant->izq=NULL;
			
		}else{
			
			ant->der=NULL;
			
		}
		
	}
	
	delete(punt);
	
}

void borrar_un_hijo(struct arbol *&ra, struct arbol *punt, struct arbol *ant, int n){
	
	if(punt==ra){
		
		if(ra->izq!=NULL){
			
			ra=ra->izq;
			
		}else{
			
			ra=ra->der;
			
		}
		
	}else{
		
		if(ant->izq==punt){
			
			if(punt->izq!=NULL){
				
				ant->izq=punt->izq;
				
			}else{
				
				ant->izq=punt->der;
				
			}
			
		}else{
			
			if(punt->izq!=NULL){
				
				ant->der=punt->izq;
				
			}else{
				
				ant->der=punt->der;
				
			}		
			
		}
		
	}
	
	delete(punt);
	
}

void borrar_dos_hijos(struct arbol *&ra, struct arbol *punt, struct arbol *ant, int n){
	
	struct arbol *izqu,*dere,*an;
	
	izqu=punt->izq;
	an=izqu;
	dere=an;
	
	while(dere!=NULL){
		
		an=dere;
		dere=dere->der;
		
	}
	
	if(izqu->der!=NULL){
		
		an->der=dere->izq;
		punt->num=dere->num;
		delete(dere);
		
	}else{
		
		punt->izq=izqu->izq;
		punt->num=izqu->num;
		delete(izqu);
		
	}
	
}

void borrar_nodo_arbol(struct arbol *&ra, struct arbol *punt, struct arbol *ant, int n){
	
	if(punt->izq==NULL&&punt->der==NULL){
		
		borrar_hoja(ra,punt,ant,n);
		
	}else{
		
		if(punt->izq!=NULL&&punt->der!=NULL){
			
			borrar_dos_hijos(ra,punt,ant,n);
			
		}else{
			
			borrar_un_hijo(ra,punt,ant,n);
			
		}
		
	}
	
}

void eliminar_arbol(struct arbol *&ra, int n){
	
	struct arbol *punt,*ant;
	bool valid;
	
	valid=false;
	
	punt=ra;
	ant=punt;
	
	while(valid==false){
		
		if(punt->num==n){
			
			valid=true;
			
		}else{
			
			ant=punt;
			
			if(punt->num>n){
			
				punt=punt->izq;
			
			}else{
			
				punt=punt->der;
			
			}
		
		}	
		
	}
	
/*	while(punt->num!=n){
	
		ant=punt;
			
		if(punt->num>n){
			
			punt=punt->izq;
			
		}else{
			
			punt=punt->der;
			
		}
				
	}
	*/
	
	borrar_nodo_arbol(ra,punt,ant,n);
		
}

/*17) Codificar una función recursiva  que reciba una estructura de árbol y un nro que pertenezca al mismo y devuelva el número de nivel donde se encuentra dicho nro.   
int  nivel _arbol (struct árbol *raíz, int n).*/
int nivel_nodo(struct arbol *ra, int n){
	
	int cont;
	
	cont=0;
	
	if(ra->num==n){
		
		return cont++;
		
	}else{
		
		if(ra->num<n){
			
			cont=nivel_nodo(ra->der,n)+1;
			
		}else{
			
			cont=nivel_nodo(ra->izq,n)+1;	
			
		}
		
	}
	
}

/*18) Codificar un procedimiento  que recorra el árbol y muestre solamente los múltiplos de 3.   
void mostrar_3 _arbol (struct árbol *raíz).*/
void mostrar_3_arbol(struct arbol *ra){
	
	if(ra!=NULL){
		
		mostrar_3_arbol(ra->izq);
	
		if(ra->num%3==0){
		
			printf("\n%d",ra->num);
		
		}
		
		mostrar_3_arbol(ra->der);
		
	}
	
}

/*19) Codificar un procedimiento  que recorra el árbol y muestre solamente los múltiplos de 3 ordenado de mayor a menor.  
void mostrar_3.1 _arbol (struct árbol *raíz).*/
void mostrar_3_maymenarbol(struct arbol *ra){
	
	if(ra!=NULL){
		
		mostrar_3_maymenarbol(ra->der);
	
		if(ra->num%3==0){
		
			printf("\n%d",ra->num);
		
		}
		
		mostrar_3_maymenarbol(ra->izq);
		
	}	
	
}

/*16) Armar un programa  usando los procedimientos y funciones definidas que lea varios nros (con cualquier criterio) e intente insertarlos en un árbol que comenzará 
vacío. Se deben descartar los repetidos. Luego mostrar su contenido. Luego otra vez leer varios nros (con cualquier criterio) e intentar eleiminarlos de la estructura.
Se deberán descartar los no existentes. Finalmente mostrar su contenido para verificar cómo quedo la estructura.*/

//Main
int main(){

//Variables
	
	struct arbol *ar;
	int n,nivel;
	
	crear_arbol(ar);
	
//Ingreso de datos
	
	printf("Ingreso de valores al arbol, finaliza con 0.\n\n");
	
	leer_nro_e("\nIngrese un valor: ",n);
	
	if(n!=0){
		
		while(n!=0){
			
			if(!buscanro_arbol(ar,n)){
			
				insert_arbol(ar,n);
			
			}else{
			
				printf("\n\nEl n%cmero ingresado esta en el Arbol\n\n",163);
			
			}
			
			leer_nro_e("\nIngrese un valor: ",n);
				
		}

		printf("\n");
		imp_arbol_rec(ar);
	
//Proceso
		
		printf("\n\nEliminaci%cn de valores del arbol, finaliza con 0.\n\n",162);
		leer_nro_e("\nIngrese un valor a eliminar: ",n);
		if(n!=0){
			
			while(n!=0){
				
				if(buscanro_arbol(ar,n)){
					
					eliminar_arbol(ar,n);
					
				}else{
					
					printf("\n\nEl n%cmero ingresado no esta en el Arbol\n\n",163);
					
				}
				
				leer_nro_e("\nIngrese un valor a eliminar: ",n);
				
			}
			
		}else{
			
			printf("\n\nNo se eliminaron valores del Arbol.\n\n");
			
		}
		
		printf("\n\nArbol luego de eliminaci%cn.\n\n",162);
		imp_arbol_rec(ar);
		
//Salida de datos
	
		printf("\n\nB%csqueda de nivel nodo\n",163);
		leer_nro_e("\n\nIngrese valor: ",n);
		if(buscanro_arbol(ar,n)){
		
			nivel=nivel_nodo(ar,n);
			printf("\n\nEl n%cmero %d esta en el nivel %d",163,n,nivel);
		
		}else{
		
			printf("\n\nEl n%cmero ingresado no esta en el Arbol\n\n",163);
		
		}
		printf("\n\nLos m%cltiplos de 3.\n",163);
		mostrar_3_arbol(ar);
		printf("\n\nLos m%cltiplos de 3 ordenados de mayor a menor.\n",163);
		mostrar_3_maymenarbol(ar);
		
	}else{
		
		printf("\n\nArbol vacio finaliza el programa.\n\n");
		
	}
	
//Pausa y fin de programa

	pausar();
	return 0;

}
