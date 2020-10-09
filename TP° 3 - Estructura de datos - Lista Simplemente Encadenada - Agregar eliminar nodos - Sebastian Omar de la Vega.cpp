//Generar una lista, mostrarla, agregarle nodos adelante y atras  y volver a mostrarla. Luego eliminar nodos adelante y atras y volver a mostrarla.
//Librerias
#include <stdio.h>
#include <stdlib.h>

//Listas
struct lista{
	
	int num;
	struct lista *sig;
	
};

//Funciones y Procedimientos

void pausar(){

	printf("\n\n\n\n");
	system("pause");

}

void leer_nro_epos(char cade[30],int &n){
	
	do{
		
		printf("\n %s: ",cade);
		scanf("%d",&n);
		fflush(stdin);
		
		if(n<0){
			
			printf("\n\nDebe ingresar un valor positivo\n\n");
			
		}
		
	}while(n<0);
			
}

void leer_nro_e(char cade[30],int &n){
	
	printf("\n %s: ",cade);
	scanf("%d",&n);
	fflush(stdin);	
	
}

void CNE_limit_lisse(struct lista *&ini,int cant){
	
	struct lista *punact,*punant;
	int n,i;
	
	leer_nro_e("\nIngrese un valor entero: ",n);
	
	if(n==0){
		
		ini=NULL;
		
	}else{
		
		ini= new struct lista;
		ini->num=n;
		ini->sig=NULL;
		punant=ini;
		
		for(i=2;i<=cant;i++){
			
			leer_nro_e("\nIngrese un valor entero: ",n);
			punact= new struct lista;
			punact->num=n;
			punact->sig=NULL;
			punant->sig=punact;
			punant=punact;
			
			
		}
		
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

void insert_p_lisse(struct lista *&ini, int n){
	
	struct lista *nue;	
	
	nue=new struct lista;
	nue->num=n;
	nue->sig=NULL;

	nue->sig=ini;
	ini=nue;
			
}

void insert_u_lisse(struct lista *&ini, int n){
	
	struct lista *nue;
	struct lista *punt;
	struct lista *ant;
	
	nue=new struct lista;
	nue->num=n;
	nue->sig=NULL;
	
	punt=ini;
	ant=punt;
	
	if(ini==NULL){
		
		ini=nue;
		
	}else{
		
		while(punt!=NULL){

			ant=punt;
			punt=punt->sig;
		
		}
		
		
		nue->sig=punt;
		ant->sig=nue;
		
	}	
	
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
	
	struct lista *punt;
	struct lista *ant;
	
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
	
	struct lista *in;
	int cant,n;
	
//Ingreso de datos
	
	leer_nro_epos("Ingrese cantidad de nodos a crear: ",cant);
	
	if(cant>0){
		
		CNE_limit_lisse(in,cant);
		if(n>0){
			imp_lisse(in);
			printf("\n\n");

//Proceso //Salida de datos
		
			leer_nro_e("Ingrese un valor primera posicion: ",n);
			insert_p_lisse(in,n);
			imp_lisse(in);
			printf("\n\n");
	
			dele_p_lisse(in);
			imp_lisse(in);
			printf("\n\n");
	
			leer_nro_e("Ingrese un valor ultima posicion: ",n);
			insert_u_lisse(in,n);
			imp_lisse(in);
			printf("\n\n");
	
			dele_u_lisse(in);
			imp_lisse(in);
			printf("\n\n");
			
		}else{
			
			printf("\n\nFinaliza el programa.\n\n");
			
		}
		
	}else{
		
		printf("\n\nFinaliza el programa.\n\n");
		
	}	
	
//Pausa y fin de programa

	pausar();
	return 0;

}

