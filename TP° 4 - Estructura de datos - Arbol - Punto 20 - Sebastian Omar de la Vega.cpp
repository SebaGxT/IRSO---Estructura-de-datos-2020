/*20) Leer 20 nros e intentar insertarlos en  árbol vacío. Contar y mostrar  cuantos ingresaron a la estructura  y cuantos estaban repetidos. Luego leer nros hasta que 
aparezca un 9 y por cada uno intentar eliminarlos del árbol. Contar y mostrar cuantos se pudo o no eliminar del mismo.*/
//Librerias
#include <stdio.h>
#include <stdlib.h>

//Arbol
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
	
	printf("\n %s",cade);
	fflush(stdin);	
	scanf("%d",&n);

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

//Main
int main(){

//Variables
	
	const int N=5;
	struct arbol *ar;
	int i,n,contingre,conting,conteli,contneli;
	
	conting=0;
	contingre=0;
	conteli=0;
	contneli=0;
	
	crear_arbol(ar);
	
//Ingreso de datos
	
	printf("Se ingresaran 20 valores a un arbol\n");
	printf("Si los valores ya existen se rechazan\n\n");
	
	for(i=0;i<N;i++){
		
		leer_nro_e("\nIngrese un valor: ",n);
		
		if(!buscanro_arbol(ar,n)){
			
			insert_arbol(ar,n);
			conting++;
			
		}else{
			
			printf("\n\nEl n%cmero ingresado esta en el Arbol\n\n",163);
			conting++;
			
		}
			
	}
	
	
//Proceso //Salida de datos
	
	printf("\n");
	imp_arbol_rec(ar);
	printf("\nLa cantidad de valores ingresados son: %d",conting);
	printf("\nLa cantidad de valores rechazados son: %d",contingre);
	
	printf("\n\nIngresar valores para eliminar, se corta el proceso con 9\n\n");
	leer_nro_e("\nIngrese un valor: ",n);
	
	do{
		
		if(buscanro_arbol(ar,n)){
			
			eliminar_arbol(ar,n);
			conteli++;
			
		}else{
			
			printf("\n\nEl n%cmero ingresado no esta en el Arbol\n\n",163);
			contneli++;	
			
		}
		
	}while(n!=9);
	
	printf("\n");
	imp_arbol_rec(ar);
	printf("\nLa cantidad de valores eliminados son: %d",conteli);
	printf("\nLa cantidad de valores que no se pudo eliminar son: %d",contneli);

//Pausa y fin de programa

	pausar();
	return 0;

}
