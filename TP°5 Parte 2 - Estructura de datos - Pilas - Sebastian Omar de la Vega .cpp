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

bool par_impar(int n){
	
	if(n%2==0){
		
		return true;
		
	}else{
		
		return false;
		
	}
	
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

void vaciar_pila(struct pila *&pil){
	
	int n;
	
	while(!pila_vacia(pil)){
		
		sacar_pila(pil,n);
		
	}
	
	crear_pila(pil);
	
}

void pasar_pila(struct pila *&pil, struct pila *&pil1){
	
	int n;
	bool valid;
	
	valid=false;
	
	while(!pila_vacia(pil)&&valid==false){
		
		sacar_pila(pil,n);
		
		if(!pila_llena(pil1)){
			
			insertar_pila(pil1,n);
				
		}else{
			
			valid=true;
			insertar_pila(pil,n);
			printf("\n\nNo se completo la transferencia, pila llena\n\n");
			
		}
		
	}
	
}

int cantidad_nro_pila(struct pila *pil){
	
	struct pila *p,*aux;
	int cant,n;
	
	p=pil;
	cant=0;

	while(!pila_vacia(p)){
		
		cant++;
		sacar_pila(p,n);	
					
	}
	
	return cant;
	
}

void cargar_pila(struct pila *&pil){
	
	int n;
	bool valid;
	
	valid=false;
	
	leer_nro_e("Ingrese un valor:",n);
	
	if(n!=0){
		
		while(n!=0&&valid==false){
			
			if(!pila_llena(pil)){
			
				insertar_pila(pil,n);
				leer_nro_e("Ingrese un valor:",n);
				
			}else{
				
				printf("\n\nPila llena.\n\n");
				valid=true;
				
			}
					
		};
		
	}

}

void cargar_pila_cantimp(struct pila *&pil){
	
	int n,cant;
	bool valid;
	
	valid=false;
	cant=0;
	
	leer_nro_e("Ingrese un valor: ",n);
	
	if(!par_impar(MAXPILA)){
		
		if(n!=0){
			
			cant++;
			
			while(valid==false&&cant<=MAXPILA){
				
				if(!pila_llena(pil)){
					
					insertar_pila(pil,n);
					leer_nro_e("Ingrese un valor: ",n);
					cant++;
					
				}else if(n!=0&&cant==MAXPILA){
					
					printf("\n\nPila llena.\n\n");
					valid=true;
					
				}else if(n==0&&!par_impar(cant)){
					
					valid=true;
					
				}else{
					
					printf("\n\nLa cantidad de n%cmeros ingresados debe ser impar. La cantidad es: %d",cant);
					
				}
				
			}
			
		}
		
	}else{
		
		if(n!=0){
			
			cant++;
			
			while(valid==false&&cant<=MAXPILA-1){
				
				if(!pila_llena(pil)){
					
					insertar_pila(pil,n);
					leer_nro_e("Ingrese un valor: ",n);
					cant++;
					
				}else if(n!=0&&cant==MAXPILA-1){
					
					printf("\n\nPila llena.\n\n");
					valid=true;
					
				}else if(n==0&&!par_impar(cant)){
					
					valid=true;
					
				}else{
					
					printf("\n\nLa cantidad de n%cmeros ingresados debe ser impar. La cantidad es: %d",cant);
					
				}
				
			}
			
		}
		
	}
		
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

void espacios_vacios_pila(struct pila *&pil,int &cont){
	
	int n;
	cont=0;
	
	while(!pila_llena(pil)){
	
		n=1;
		insertar_pila(pil,n);
		cont++;
			
	}
	
}

void msj_pila_vacia(int pil){
	
	printf("\n\nPila %d vacia, no se cargaron valores.\n\n",pil);
	
}

//Main
int main(){

//Variables

	struct pila *pila1,*pila2, *aux1, *aux2,*arriba,*abajo,*medio;
	int n,cantpil1,cantpil2;
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

//14) Cargar una pila. Mostrar su contenido. Luego dar vuelta su contenido y mostarla.	
	cargar_pila(pila1);	
	if(!pila_vacia(pila1)){
		
		printf("\n\npila 1\n\n");
		mostrar_pila(pila1);
		pasar_pila(pila1,aux1);
		pasar_pila(aux1,pila2);
		pasar_pila(aux1,pila1);
		printf("\n\npila 1 invertida\n\n");
		mostrar_pila(pila1);
		vaciar_pila(pila1);
		
	}else{
		
		msj_pila_vacia(1);
		
	}
		
//15) Cargar dos pilas. Mostrar su contenido. Luego intercambiar su contenido y mostrarlas.
	cargar_pila(pila1);
	cargar_pila(pila2);
	if(!pila_vacia(pila1)){
		
		printf("\n\npila 1\n\n");
		mostrar_pila(pila1);
		
		if(!pila_vacia(pila2)){
			
			printf("\n\nPila 2\n\n");
			mostrar_pila(pila2);
			//intercambio de pilas
			pasar_pila(pila1,aux2);
			pasar_pila(pila2,aux1);
			pasar_pila(aux2,pila2);
			pasar_pila(aux1,pila1);
			//mostrar pilas intercambiadas
			printf("\n\nPilas intercambiadas");
			printf("\n\npila 1\n\n");
			mostrar_pila(pila1);
			printf("\n\nPila 2\n\n");
			mostrar_pila(pila2);
			vaciar_pila(pila1);
			vaciar_pila(pila2);	
			
		}else{
			
			msj_pila_vacia(2);
			printf("No se puede realizar el intercambio.\n\n");
			
		}
		
	}else{
		
		msj_pila_vacia(1);
		printf("No se puede realizar el intercambio.\n\n");
		
	}
		
//16) Cargar dos pilas. Mostrar su contenido. Luego intercambiar su base y su tope. Mostrarlas.
	cargar_pila(pila1);
	cargar_pila(pila2);	
	if(!pila_vacia(pila1)&&!pila_vacia(pila2)){
		
		//Intercambio de topes
		sacar_pila(pila1,n);
		if(!pila_llena(aux1)){
		
			insertar_pila(aux1,n);
		
		}
		sacar_pila(pila2,n);
		if(!pila_llena(aux2)){
		
			insertar_pila(aux2,n);
		
		}
		sacar_pila(aux1,n);
		if(!pila_llena(pila2)){
		
			insertar_pila(pila2,n);
		
		}
		sacar_pila(aux2,n);
		if(!pila_llena(pila1)){
		
			insertar_pila(pila1,n);
		
		}
		//Intercambio de bases
		pasar_pila(pila1,aux1);
		pasar_pila(pila2,aux2);
		sacar_pila(aux2,n);
		if(!pila_llena(pila1)){
		
			insertar_pila(pila1,n);
		
		}
		sacar_pila(aux1,n);
		if(!pila_llena(pila2)){
		
			insertar_pila(pila2,n);
		
		}
		sacar_pila(pila1,n);
		if(!pila_llena(aux1)){
		
			insertar_pila(aux1,n);
		
		}
		sacar_pila(pila2,n);
		if(!pila_llena(aux2)){
		
			insertar_pila(aux2,n);
		
		}
		//Base y tope intercambiados
		printf("\n\nPilas base y topes intercambiados");
		printf("\n\npila 1\n\n");
		mostrar_pila(pila1);
		printf("\n\nPila 2\n\n");
		mostrar_pila(pila2);
		vaciar_pila(pila1);
		vaciar_pila(pila2);
		
	}else{
		
		if(pila_vacia(pila1)){
			
			msj_pila_vacia(1);
			
		}
		
		if(pila_vacia(pila2)){
			
			msj_pila_vacia(2);
			
		}
		
		printf("No se puede realizar el intercambio.\n\n");
		
	}
	
	
//17) Cargar una pila. Mostrar su contenido. Sin contar mostrar una leyenda aclaratoria dependiendo si la cantidad de elementos es par o impar.
	cargar_pila(pila1);
	if(!pila_vacia(pila1)){
		
		printf("\n\npila 1\n\n");
		mostrar_pila(pila1);
		if(pila_llena(pila1)){
		
			if(par_impar(MAXPILA)){
			
				printf("\n\nLa cantidad de elementos de la pila 1 es par\n\n");
				
			}else{
			
				printf("\n\nLa cantidad de elementos de la pila 1 es impar\n\n");
			
			}
		
		}else{
		
			espacios_vacios_pila(pila1,cantpil1);
		
			n=MAXPILA-cantpil1;
		
			if(par_impar(n)){
			
				printf("\n\nLa cantidad de elementos de la pila 1 es par\n\n");
			
			}else{
			
				printf("\n\nLa cantidad de elementos de la pila 1 es impar\n\n");
			
			}
		
			for(int i=0;i<cantpil1;i++){
			
				sacar_pila(pila1,n);
				
			}
		
		}
		vaciar_pila(pila1);
		
	}else{
		
		msj_pila_vacia(1);
		
	}
		
//18) Cargar dos pilas. Mostrar su contenido. Luego sin contar mostrar una leyenda aclaratoria dependiendo si la cantidad de elementos de ambas pilas es igual o no.
	cargar_pila(pila1);
	cargar_pila(pila2);
	if(!pila_vacia(pila1)&&!pila_vacia(pila2)){
		
		printf("\n\npila 1\n\n");
		mostrar_pila(pila1);
		printf("\n\nPila 2\n\n");
		mostrar_pila(pila2);
		if(pila_llena(pila1)&&pila_llena(pila2)){
		
			printf("\n\nLa cantidad de elementos de la pila 1 y pila 2 son iguales\n\n");
		
		}else{
		
			cantpil1=0;
			cantpil2=0;
			espacios_vacios_pila(pila1,cantpil1);
			espacios_vacios_pila(pila2,cantpil2);
		
			if(cantpil1==cantpil2){
			
				printf("\n\nLa cantidad de elementos de la pila 1 y pila 2 son iguales\n\n");
			
			}else{
			
				printf("\n\nLa cantidad de elementos de la pila 1 y pila 2 no son iguales\n\n");
			
			}
		
			for(int i=0;i<cantpil1;i++){
			
				sacar_pila(pila1,n);
			
			}
		
			for(int i=0;i<cantpil2;i++){
			
				sacar_pila(pila2,n);
			
			}
		
		}
		vaciar_pila(pila1);
		vaciar_pila(pila2);
		
	}else{
		
		if(pila_vacia(pila1)){
			
			msj_pila_vacia(1);
			
		}
		
		if(pila_vacia(pila2)){
			
			msj_pila_vacia(2);
			
		}
		
		printf("No se puede realizar la comparaci%cn.\n\n",162);
		
	}
	
/*19) Cargar dos pilas. Mostrar su contenido. Luego cargar una pila con el contenido de ambas de la siguiente manera: una de la primera y otra de la segunda. 
Si quedaran elementos de alguna pasarlas a la pila resultado en el tope de la misma.*/
	cargar_pila(aux1);
	cargar_pila(aux2);
	valid=false;
	if(!pila_vacia(aux1)&&!pila_vacia(aux2)){
		
		printf("\n\npila 1\n\n");
		mostrar_pila(aux1);
		printf("\n\nPila 2\n\n");
		mostrar_pila(aux2);
		
		while(valid==false){
			
			sacar_pila(aux1,n);
			if(!pila_llena(pila1)){
				
				insertar_pila(pila1,n);
				sacar_pila(aux2,n);
				if(!pila_llena(pila1)){
				
					insertar_pila(pila1,n);
				
				}else{
					
					insertar_pila(aux2,n);
					valid=true;
					
				}
				
			}else{
				
				insertar_pila(aux1,n);
				valid=true;
				
			}
			
			
		}
		
		printf("\n\nPila resultado\n\n");
		mostrar_pila(pila1);
		if(!pila_vacia(aux1)){
			
			printf("\nNo pudieron ingresar los siguientes de la pila 1\n\n");
			mostrar_pila(aux1);
			
		}
		if(!pila_vacia(aux2)){
			
			printf("\nNo pudieron ingresar los siguientes de la pila 2\n\n");
			mostrar_pila(aux2);
			
		}
		
	}else{
		
		if(pila_vacia(pila1)){
			
			msj_pila_vacia(1);
			
		}
		
		if(pila_vacia(pila2)){
			
			msj_pila_vacia(2);
			
		}
		
		printf("No se puede realizar la operaci%cn.\n\n",162);
		
	}	
	
/*20) Cargar una pila con cantidad de elementos impar. Mostrar su contenido. Luego generar tres pilas ARRIBA, ABAJO y MEDIO. En la pila MEDIO ira el elemento 
que esta en el medio de la pila original. En la pila ARRIBA, los elementos que estan por arriba del medio. En la pila ABAJO, los elementos que estan por abajo del medio.
*/
	cargar_pila_cantimp(pila1);
	crear_pila(arriba);
	crear_pila(medio);
	crear_pila(abajo);
	cantpil1=cantidad_nro_pila(pila1);
	if(!pila_vacia(pila1)){
		
		printf("\n\npila 1\n\n");
		mostrar_pila(pila1);
		
		cantpil1=(cantpil1/2)-1;
		
		while(cantpil1>=0){
			
			cantpil1--;
			sacar_pila(pila1,n);
			if(!pila_llena(arriba)){
				
				insertar_pila(arriba,n);
				
			}
			
		}
		
		sacar_pila(pila1,n);
		if(!pila_llena(medio)){
			
			insertar_pila(medio,n);
			
		}
		
		while(!pila_vacia(pila1)){
			
			sacar_pila(pila1,n);
			if(!pila_llena(abajo)){
				
				insertar_pila(abajo,n);
				
			}
			
		}
		
	}else{
		
		msj_pila_vacia(1);
		
	}
	
//Pausa y fin de programa

	pausar();
	return 0;

}
