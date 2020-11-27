/*
1-	Leer números enteros hasta que aparezca un cero. Cargarlos en una pila. El cero no entra en la pila.
2-	Mostrar el contenido de la pila.
3-	Luego se vaciará la pila colocando los números no repetidos en  un árbol binario de búsqueda. 
4-	Los números repetidos  se cargarán en una lista simplemente encadenada los cuales se insertarán por delante de la lista. 
5-	Mostrar los elementos insertados en el árbol en forma ordenada.
6-	Mostrar el contenido de la lista simplemente encadenada.
7-	Luego eliminar el primer elemento de la lista si lo tuviera.
8-	Luego eliminar el último elemento de la lista si lo tuviera.
9-	Mostrar el contenido de la lista luego de dichas operaciones.
10-	Leer un número entero y mostrar en qué nivel del árbol se encuentra. Si no estuviera en el árbol se visualizará un cartel aclaratorio.
*/
//Librerias
#include <stdio.h>
#include <stdlib.h>

//pila

struct pila{
	
	int num;
	struct pila *sig;
		
};

struct arbol{
	
	int num;
	struct arbol *der;
	struct arbol *izq;
		
};

struct lista{
	
	int num;
	struct lista *sig;
	
};

int MAXPILA;

//Funciones y Procedimientos

void pausar(){
	
	printf("\n\n\n\n");
	system("pause");
	
}

bool par_impar(int n){
	
	if(n%2==0){
		
		return true;
		
	}else{
		
		return false;
		
	}
	
}

void leer_nro_ep(char cade[30],int &n){
	
	printf("\n%s ",cade);	
	scanf("%d",&n);
	fflush(stdin);

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

void mostrar_pila(struct pila *pil){
	
	struct pila *p, *aux;
	int n;
	
	p=pil;
	
	crear_pila(aux);
	
	while(!pila_vacia(p)){
		
		sacar_pila(p,n);
		printf("\n%d",n);
		insertar_pila(aux,n);
		
	}
	
}

void cargar_pila(struct pila *&pil){
	
	int n;
	bool valid;
	
	valid=false;
	
	leer_nro_ep("Ingrese un valor:",n);
	
	if(n!=0){
		
		while(n!=0&&valid==false){
			
			if(!pila_llena(pil)){
			
				insertar_pila(pil,n);
				leer_nro_ep("Ingrese un valor:",n);
				
			}else{
				
				printf("\n\nPila llena.\n\n");
				valid=true;
				
			}
					
		};
		
	}

}

void crear_arbol(struct arbol *&ra){
	
	ra=NULL;
	
}

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

void imp_arbol_rec(struct arbol *ra){
	
	if(ra!=NULL){
		
		//IRD
		imp_arbol_rec(ra->izq);
		printf("\n%d",ra->num);
		imp_arbol_rec(ra->der);
		
	}
	
}

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

void imp_lisse(struct lista *ini){
	
	struct lista *punt;
	
	punt=ini;

	while(punt!=NULL){
		
		printf("\n%d",punt->num);
		punt=punt->sig;
		
	}
			
}

void insert_p_lisse(struct lista *&ini, int n){
	
	struct lista *nue;	
	
	nue=new struct lista;
	nue->num=n;
	nue->sig=NULL;

	nue->sig=ini;
	ini=nue;
			
}


void dele_p_lisse(struct lista *&ini){
	
	struct lista *punt;
	
	if(ini!=NULL){
		
		punt=ini;
		ini=ini->sig;
		delete(punt);
			
	}else{
		
		printf("\n\nLista vacia\n\n");
		
	}
		
}

void dele_u_lisse(struct lista *&ini){
	
	struct lista *punt,*ant;
	
	if(ini!=NULL){
		
		punt=ini;
		ant=punt;
		
		while(punt->sig!=NULL){
			
			ant=punt;
			punt=punt->sig;
			
		}
		
		if(punt==ini){
			
			delete(punt);
			ini=NULL;
			
		}else{
			
			delete(punt);
			ant->sig=NULL;
			
		}
		
	}else{
		
		printf("\n\nLista vacia\n\n");	
		
	}
	
}

//Main
int main(){
	
//Variables

	struct pila *pila1;
	struct arbol *ar;
	struct lista *lis;
	int n,nivel;
	
//Ingreso de datos

	do{
		
		leer_nro_ep("Ingrese el espacio maximo de pila: ",MAXPILA);
		
		if(MAXPILA<1){
			
			printf("\n\nDebe ingresar un valor positivo mayor a 0.\n\n");
			
		}	
		
	}while(MAXPILA<1);

	crear_pila(pila1);
	crear_arbol(ar);
	
	cargar_pila(pila1);

//Proceso
	
	if(!pila_vacia(pila1)){
		
		printf("\n\nPila 1\n\n");
		mostrar_pila(pila1);
		
		while(!pila_vacia(pila1)){
		
		
			sacar_pila(pila1,n);
				
		
			if(!buscanro_arbol(ar,n)){
			
				insert_arbol(ar,n);
		
			}else{
			
				insert_p_lisse(lis,n);
			
			}
		
		}

		if(ar!=NULL){
		
			printf("\n\nArbol 1\n\n");
			imp_arbol_rec(ar);
		
		}else{
		
			printf("\n\nArbol vacio.\n\n");
		
		}
	
		if(lis!=NULL){
		
			printf("\n\nLista 1\n\n");
			imp_lisse(lis);
		
			dele_p_lisse(lis);
			dele_u_lisse(lis);
		
			if(lis!=NULL){
			
				printf("\n\nLista 1 luego de eliminar primero y %cltimo\n\n",163);
				imp_lisse(lis);
			
			}else{
			
				printf("\n\nLista vacia.\n\n");
			
			}
		
		}else{
		
			printf("\n\nLista vacia.\n\n");
		
		}
	
//Salida de datos

		if(ar!=NULL){
		
			printf("\n\nB%csqueda de nivel\n\n",163);
			leer_nro_ep("\n\nIngrese un valor: ",n);
		
			if(buscanro_arbol(ar,n)){
			
				nivel=nivel_nodo(ar,n);
				printf("\n\nEl n%cmero se encuentra en el nivel: %d",163,nivel);
			
			}else{
			
				printf("\n\nEl n%cmero no se encuentra en el arbol.\n\n",163);
			
			}
		
		}
		
	}else{
		
		printf("\n\nPila vacia no se cargaron valores, finaliza el programa.\n");
		
	}
	
//Pausa y fin de programa

	pausar();
	return 0;

}

