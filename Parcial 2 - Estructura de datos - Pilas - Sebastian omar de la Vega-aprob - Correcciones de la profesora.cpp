//Librerias
#include <stdio.h>
#include <stdlib.h>

//Pila
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
// mostrar pila usa la estuctura de lista simplemente encadenada paula
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

void pasar_pila(struct pila *&pil, struct pila *&pil1){
	
	int n1;
	
	while(!pila_vacia(pil)){
		
		sacar_pila(pil,n1);
		
		if(!pila_llena(pil1)){
			
			insertar_pila(pil1,n1);
		//  ojo que si la segunda pila esta llena te quedas con la que sacaste ahi	
		}
		
	}
	
}

int cant_pila(struct pila *pil,int n){
	
	struct pila *p;
	int cant;
	
	cant=0;
	p=pil;
	
	while(p!=NULL){
		
		if(p->num==n){
			
			cant++;
			
		}	
		p=p->sig;
		
	}
	
	return cant;
	
}
// usaste la estructura de la lista paula
bool par_impar(int n){
	
	if(n%2==0){
		
		return true;
		
	}else{
		
		return false;
		
	}
	
}

void sacar_par_pila(struct pila *&pil){
	
	struct pila*p;
	int n;
	
	crear_pila(p);
	
	while(!pila_vacia(pil)){
		
		sacar_pila(pil,n);
		
		if(!pila_llena(p)){
			
			if(!par_impar(n)){
				
				insertar_pila(p,n);
				
			}
			
		}
		
	}
// bien ojo el if paula	
	pasar_pila(p,pil);
	
}

//Main
int main(){

//Variables

	struct pila *pila1,*pila2, *aux1, *aux2;
	int n,cant;
	bool valid;
	
	valid=false;

//Ingreso de datos

	do{
		
		leer_nro_e("Ingrese el espacio maximo de pila: ",MAXPILA);
		
		if(MAXPILA<1){
			
			printf("\n\nDebe ingresar un valor positivo mayor a 0.\n\n");
			
		}	
		
	}while(MAXPILA<1);
// muy bien	
	crear_pila(pila1);
	crear_pila(pila2);
	crear_pila(aux1);
	crear_pila(aux2);
	
	printf("\n\nCarga de pila 1.\n\n");
	leer_nro_e("Ingrese un valor:",n);
	
	if(n!=0){
		
		while(n!=0&&valid==false){
			
			if(!pila_llena(pila1)){
			
				insertar_pila(pila1,n);
				leer_nro_e("Ingrese un valor:",n);
				
			}else{
				
				printf("\n\nPila llena.\n\n");
				valid=true;
				
			}
					
		};
		
	}else{
		
		printf("\n\nPila vacia no se cargaron valores.\n");
		
	}
// cargo la pila pero se debe modularizar paula	
	valid=false;
	printf("\n\nCarga de pila 2.\n\n");
	leer_nro_e("Ingrese un valor:",n);
	
	if(n!=0){
		
		while(n!=0&&valid==false){
			
			if(!pila_llena(pila2)){
			
				insertar_pila(pila2,n);
				leer_nro_e("Ingrese un valor:",n);
				
			}else{
				
				printf("\n\nPila llena.\n\n");
				valid=true;
				
			}
					
		};
		
	}else{
		
		printf("\n\nPila vacia no se cargaron valores.\n");
		
	}
// cargo la pila pero se debe modularizar paula	
//Proceso

	if(!pila_vacia(pila1)){
		
		printf("\n\nPila 1\n\n");
		mostrar_pila(pila1);
		
	}else{
		
		printf("\n\nNo se puede mostrar pila 1, esta vacia.\n\n");
		
	}
		
	if(!pila_vacia(pila2)){
		
		printf("\n\nPila 2\n\n");
		mostrar_pila(pila2);
		
	}else{
		
		printf("\n\nNo se puede mostrar pila 2, esta vacia.\n\n");
		
	}
//muy bien	paula
	if(!pila_vacia(pila1)){
		
		printf("\n\nIngrese un valor a buscar en pila 1, indicara cuantas veces esta.\n\n");
		leer_nro_e("Ingrese un valor:",n);
		cant=cant_pila(pila1,n);
		printf("\n\nLa cantidad es: %d\n\n",cant);
		
	}else{
		
		printf("\n\nPila 1 vacia\n\n");
		
	}	
// muy bien paula
	printf("\n\nEliminar tope y base de la pila\n\n");
	
	//Eliminar tope
	sacar_pila(pila1,n);
	sacar_pila(pila2,n);
	
	//Transferencia a pila aux
	if(!pila_vacia(pila1)){
		
		pasar_pila(pila1,aux1);
		//Eliminar base
		sacar_pila(aux1,n);
		
	}else{
		
		printf("\n\nPila vacia.\n\n");
		
	}
	if(!pila_vacia(pila2)){
		
		pasar_pila(pila2,aux2);
		//Eliminar base
		sacar_pila(aux2,n);
		
	}else{
		
		printf("\n\nPila vacia.\n\n");
		
	}	
	
	//transferencia a pila principal
	if(!pila_vacia(aux1)){
		
		pasar_pila(aux1,pila1);
		
	}else{
		
		printf("\n\nPila vacia.\n\n");
		
	}	
	
	if(!pila_vacia(aux2)){
		
		pasar_pila(aux2,pila2);
		
	}else{
		
		printf("\n\nPila vacia.\n\n");
		
	}
	
	printf("\n\nTope y base eliminados\n\n");
// muy bien
	if(!pila_vacia(pila1)){
		
		printf("\n\nPila 1\n\n");
		mostrar_pila(pila1);
		
	}else{
		
		printf("\n\nNo se puede mostrar pila 1, esta vacia.\n\n");
		
	}
// muy bien		
	if(!pila_vacia(pila2)){
			
		printf("\n\nPila 2\n\n");
		mostrar_pila(pila2);
		
	}else{
		
		printf("\n\nNo se puede mostrar pila 2, esta vacia.\n\n");
		
	}
	
	if(!pila_vacia(pila1)){
		
		sacar_par_pila(pila1);
		
	}else{
		
		printf("\n\nPila 1 vacia\n\n");
		
	}
// muy bien	
	if(!pila_vacia(pila2)){
		
		sacar_par_pila(pila2);
		
	}else{
		
		printf("\n\nPila 2 vacia\n\n");
		
	}	
	
//Salida de datos

	printf("\n\nSe eliminan los n%cmeros par\n\n",163);
	if(!pila_vacia(pila1)){
		
		printf("\n\nPila 1\n\n");
		mostrar_pila(pila1);
		
	}else{
		
		printf("\n\nNo se puede mostrar pila 1, esta vacia.\n\n");
		
	}
		
	if(!pila_vacia(pila2)){
			
		printf("\n\nPila 2\n\n");
		mostrar_pila(pila2);
		
	}else{
		
		printf("\n\nNo se puede mostrar pila 2, esta vacia.\n\n");
		
	}
// muy bien
//Pausa y fin de programa

	pausar();
	return 0;

}

