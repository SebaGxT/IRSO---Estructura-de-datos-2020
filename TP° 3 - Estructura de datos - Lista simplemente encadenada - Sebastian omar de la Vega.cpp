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

void leer_nro_e(char cade[30],int &n){
	
	printf("\n %s",cade);
	scanf("%d",&n);
	fflush(stdin);	
	
}

void leer_nro_epar(char cade[30],int &n){
	
	do{
		
		printf("\n %s",cade);
		scanf("%d",&n);
		fflush(stdin);
		
		if(n%2==1){
			
			printf("\n\nDebe ingresar un valor par\n\n");
			
		}	
		
	}while(n%2==1);	
	
}

bool par_impar(int n){
	
	if(abs(n)%2==0){
		
		return true;
		
	}else{
		
		return false;
		
	}
	
}

//1) Armar una lista simplemente encadenada con nros enteros que se leen sabiendo la cantidad que se deben leer. Usar un procedimiento.
void CNE_limit_lisse(struct lista *&ini,int cant){
	
	struct lista *punact,*punant;
	int n,i;
	
	
	
	if(cant<=0){
		
		ini=NULL;
		
	}else{
		
		leer_nro_e("\nIngrese un valor entero: ",n);
		
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

//2) Armar una lista simplemente encadenada con nros enteros que se leen hasta que aparezca una cero. Usar un procedimiento.
void CNE_lisse_ccero(struct lista *&ini){
	
	struct lista *punact,*punant;
	int n;
	
	leer_nro_e("\nIngrese un valor entero: ",n);
	
	if(n==0){
		
		ini=NULL;
		
	}else{
		
		ini= new struct lista;
		ini->num=n;
		ini->sig=NULL;
		punant=ini;
		
		leer_nro_e("\nIngrese un valor entero: ",n);
		
		while(n!=0){
			
			if(n!=0){
				
				punact= new struct lista;
				punact->num=n;
				punact->sig=NULL;
				punant->sig=punact;
				punant=punact;
				
			}
			
			leer_nro_e("\nIngrese un valor entero: ",n);
			
		}
		
	}
		
}

//3) Recorrer una lista simplemente encadenada mostrando su contenido. Usar un procedimiento.
void imp_lisse(struct lista *ini){
	
	struct lista *punt;
	
	punt=ini;
	
	if(punt!=NULL){
		
		printf("\n%d",punt->num);
		punt=punt->sig;
		imp_lisse(punt);
		
	}
	
	
/*	while(punt!=NULL){
		
		printf("\n%d",punt->num);
		punt=punt->sig;
		
	}*/
		
	
}

//4) Dada una lista simplemente encadenada y un valor entero, mostrar una leyenda aclaratoria dependiendo si el número está o no en la lista. Usar una función que devuelva 1 si está o 0 si no está en la lista.
bool busnro_lisse(struct lista *ini, int n){
	
	struct lista *punt;
	bool valid;
	
	punt=ini;
	
	if(punt!=NULL){
		
		if(punt->num==n){
			
			valid=true;
			
		}else{
			
			punt=punt->sig;
			valid=busnro_lisse(punt,n);
			
		}
		
		return valid;
		
	}else{
		
		return false;
		
	}
	
}

//5) Dada una lista simplemente encadenada y un valor entero, mostrar cuantas veces dicho número está en la lista. Usar una función.
int cantnro_lisse(struct lista *ini, int n){
	
	int cant;
	struct lista *punt;
	
	punt=ini;
	
	cant=0;
	
	while(punt!=NULL){
		
		if(punt->num == n){
		
			cant++;
			punt=punt->sig;
		
		}else{
		
			punt=punt->sig;
		
		}
		
	}
	
	return cant;
	
}

//6) Dada una lista simplemente encadenada mostrar cuantos nodos con contenido par tiene  la lista. Usar una función.
//16) Codificar una funcion cuenta_pares que reciba una lista simplemente encadenada y devuelva la cantidad  de nros pares que contiene.
int cantpar_lisse(struct lista *ini){
	
	int cant;
	struct lista *punt;
	
	punt=ini;
	
	cant=0;
	
	while(punt!=NULL){
		
		if(par_impar(punt->num)){
			
			cant++;
			punt=punt->sig;
			
		}else{
			
			punt=punt->sig;
			
		}
		
	}
	
	return cant;
	
}

//7) Dada una lista simplemente encadenada mostrar una leyenda aclaratoria dependiendo si la lista esta ordenada de menor a mayor. Usar una función.
bool in_orden_menma_lisse(struct lista *ini){
	
	struct lista *punt,*sige;
	bool valid=true;
	
	punt=ini;//Iguala punteros en inicial.
	sige=punt;
	
	if(punt!=NULL){//Si punt es NULL sale con false.
		
		sige=punt->sig;//Cambio al siguiente de punt para comparación.
		
		if(sige!=NULL){
	
			while(sige!=NULL&&valid==true){
			
				if(punt->num<=sige->num){

					sige=sige->sig;
					punt=punt->sig;
					valid=true;
				
				}else{

					sige=sige->sig;
					punt=punt->sig;
					valid=false;
				
				}
				
			}
					
		}else if(punt==ini&&sige==NULL){//Si el punto sige es NULL y punt esta en inicial sale por verdadero ya que esta ordenado.
			
			valid=true;
			
		}
			
	}else{
		
		valid=false;
		
	}
	
	return valid;
		
}

//8) Dada una lista simplemente encadenada ordenar  de menor a mayor su contenido. Usar un procedimiento.
void ordena_menma_lisse(struct lista *&ini){
	
	struct lista *punt,*sige;
	int aux;
	
	punt=ini;
	sige=punt;
	
	while(punt!=NULL){
		
		sige=punt->sig;
		
		while(sige!=NULL){
			
			if(punt->num>=sige->num){
				
				aux=sige->num;
				sige->num=punt->num;
				punt->num=aux;
				
			}
			
			sige=sige->sig;
			
		}
		
		punt=punt->sig;
		
	}
	
	if(punt==ini&&punt==NULL){
		
		printf("\n\nLista vacia.\n\n");
		
	}
			
}

//9) Dada una lista simplemente encadenada  y un valor entero insertarlo por delante de la misma. Usar un procedimiento.
void insert_p_lisse(struct lista *&ini, int n){
	
	struct lista *nue;	
	
	nue=new struct lista;
	nue->num=n;
	nue->sig=NULL;

	nue->sig=ini;
	ini=nue;
			
}

//10) Dada una lista simplemente encadenada  y un valor entero insertarlo por atras de la misma. Usar un procedimiento.
void insert_u_lisse(struct lista *&ini, int n){
	
	struct lista *nue,*punt,*ant;
	
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

//11) Dada una lista simplemente encadenada con valor ordenados de menor a mayor y un valor entero insertarlo en el lugar que le corresponda para que la lista continúe ordenada . Usar un procedimiento.
void insert_ordmenmay_lisse(struct lista *&ini, int n){
	
	struct lista *nue,*punt,*ant;
	bool valid;
	
	nue=new struct lista;
	nue->num=n;
	nue->sig=NULL;
	
	punt=ini;
	ant=punt;
	valid=false;
	
	if(ini==NULL){
		
		ini=nue;
		
	}else{
		
		while(punt!=NULL&&valid==false){
			
			if(punt->num>n){
				
				valid=true;
				
			}else{
				
				ant=punt;
				punt=punt->sig;
				
			}
			
		}
		
		nue->sig=punt;
		ant->sig=nue;	
		
	}
	
	
	
}

//12) Dada una lista simplemente encadenada eliminar el primer nodo de la misma . Usar un procedimiento.
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

//13) Dada una lista simplemente encadenada eliminar el último nodo de la misma . Usar un procedimiento.
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

//14) Dada una lista simplemente encadenada y un número entero, eliminar la primera ocurrencia de dicho entero. Usar un procedimiento.
void dele_ocu_lisse(struct lista *&ini, int n){
	
	struct lista *punt,*ant;
	bool valid;
	
	valid=false;
	
	punt=ini;
	ant=punt;
		
	while(punt!=NULL&&valid==false){
			
		if(punt->num==n){
				
			valid=true;
				
		}else{
				
			ant=punt;
			punt=punt->sig;
				
		}
			
	}
	
	if(valid==true){
		
		if(punt==ini){
			
			ini=ini->sig;
			delete(punt);
			
		}else{
			
			ant->sig=punt->sig;
			delete(punt);
			
		}
		
	}else{
		
		printf("\n\nNo se encuentra el valor en la lista\n\n");
		
	}
	
}

//15) Leer numeros hasta que aparezca un cero. Cargar una lista simplemente encadenada con solo aquellos numeros que fueran pares. Usar un procedimiento.
void CNE_par_ccero(struct lista *&ini){
	
	struct lista *punact,*punant;
	int n;
	
	leer_nro_epar("\nIngrese un valor par: ",n);
	
	if(n==0){
		
		ini=NULL;
		
	}else{
		
		ini= new struct lista;
		ini->num=n;
		ini->sig=NULL;
		punant=ini;
		
		leer_nro_epar("\nIngrese un valor par: ",n);
		
		while(n!=0){
			
			if(n!=0){
				
				punact= new struct lista;
				punact->num=n;
				punact->sig=NULL;
				punant->sig=punact;
				punant=punact;
				
			}
			
			leer_nro_epar("\nIngrese un valor par: ",n);
			
		}
		
	}
	
}

//17) Codificar  un procedimiento cargar_adelante_atras que reciba una lista simplemente encadenada (cargada o nula) y un nro entero y devuelva la lista con dicho nro insertado adelante y atrás de la lista.
void CNE_priult_lisse(struct lista *&ini,int n){
	
	struct lista *punt,*nue,*ant;
	
	punt=ini;
	ant=punt;
	
	nue=new struct lista;
	nue->num=n;
	nue->sig=NULL;
	
	if(ini==NULL){
		
		ini=nue;
		
	}else{
		
		nue->sig=ini;
		ini=nue;
		
		while(punt!=NULL){
			
			ant=punt;
			punt=punt->sig;
			
		}
		
		nue=new struct lista;
		nue->num=n;
		nue->sig=NULL;
		
		nue->sig=punt;
		ant->sig=nue;
		
	}
		
	
}

//18) Codificar  un procedimiento sacar_adelante_atras que reciba una lista simplemente encadenada (cargada o nula) y devuelva la lista sin el primer y ultimo nro.
void del_priult_lisse(struct lista *&ini){
	
	struct lista *punt,*ant;
	
	punt=ini;
	ant=punt;
	
	if(ini==NULL){
		
		printf("\n\nLista vacia\n\n");
		
	}else{
		
		ini=ini->sig;
		ant=ini;
		delete(punt);
		punt=ini;
		
		while(punt!=NULL){
			
			ant=punt;
			punt=punt->sig;
			
		}
		
		
		
		
	}
	
}

//19) Codificar  un procedimiento cargar_recursivo  que cargue una  lista simplemente encadenada  en forma recursiva con nros que se lean hasta que aparezca una cero.
void CNE_ccero_r(struct lista *&ini){
	
	struct lista *punt;
	int n;
	
	punt=ini;

	if(ini!=NULL){
		
		leer_nro_e("\nIngrese un valor entero: ",n);
		
		if(n!=0){
			
			punt= new struct lista;
			punt->num=n;
			punt->sig=NULL;
			punt->sig=ini;
			ini=punt;
			
			CNE_ccero_r(punt->sig);	
			
		}else{
			
			ini=NULL;
			
		}
		
	}
	
}

//20) Codificar  un procedimiento que reciba una  lista simplemente encadenada  y si se puede intercambiar el primero con el último elemento.
void intercambio_lisse(struct lista*&ini){
	
	struct lista *punt,*ant;
	int aux;
	
	punt=ini;
	ant=punt;
	
	if(punt==NULL){
		
		printf("\n\nLista vacia\n\n");
		
	}	
	
	while(punt!=NULL){
		
		ant=punt;
		punt=punt->sig;
		
	}
	
	aux=ant->num;
	ant->num=ini->num;
	ini->num=aux;
	
	
}

//21) Codificar  una función  que sume los elementos de una lista simplemente encadenada que tuvieran contenido impar.
int suma_impar_lisse(struct lista *ini){
	
	struct lista *punt;
	int cont;
	
	cont=0;
	
	punt=ini;
	
	while(punt!=NULL){
		
		if(!par_impar(punt->num)){
			
			cont+=punt->num;
			punt=punt->sig;
			
		}else{
			
			punt=punt->sig;
			
		}
		
	}
	
	return cont;
		
}

//22) Codificar  una función  que sume los elementos de una lista simplemente encadenada que estuvieran en posición impar.
int suma_posimpar_lisse(struct lista *ini){
	
	struct lista *punt;
	int cont,pos;
	
	cont=0;
	pos=1;
	
	punt=ini;
	
	while(punt!=NULL){
		
		if(!par_impar(pos)){
			
			cont+=punt->num;
			punt=punt->sig;
			
		}else{
			
			punt=punt->sig;
			
		}
		
		pos++;
		
	}
	
	return cont;
		
}
//23) Codificar  un procedimiento muestre solo los nodos de una lista simplemente encadenada que tuvieran contenido impar.
void imp_impar_lisse(struct lista *ini){
	
	struct lista *punt;
	
	punt=ini;
		
	while(punt!=NULL){
		
		if(!par_impar(punt->num)){
			
			printf("\n%d",punt->num);
			punt=punt->sig;
			
		}else{
			
			punt=punt->sig;
			
		}
		
	}
	
}

//24) Codificar  un procedimiento muestre solo los nodos de una lista simplemente encadenada que tuvieran contenido impar, en forma recursiva.
void imp_impar_lisse_r(struct lista *ini){
	
	struct lista *punt;
	
	punt=ini;
	
	if(punt!=NULL){
		
		if(!par_impar(punt->num)){
			
			printf("\n%d",punt->num);
			punt=punt->sig;
			imp_impar_lisse_r(punt);
			
		}else{
			
			punt=punt->sig;
			imp_impar_lisse_r(punt);
			
		}
		
	}
	
}

//Main
int main(){

//Variables
	
	int n,cant;
	struct lista *in;
	
//Ingreso de datos
	
	leer_nro_e("Ingrese cantidad de nodos a crear: ",cant);
		
	CNE_limit_lisse(in,cant);
		
	if(in!=NULL){
			
		imp_lisse(in);
			
	}else{
			
		printf("\n\nNo se cargaron nodos\n\n");	
			
	}
	
	printf("\n\nIngrese valores a la lista. Finaliza el ingreso con 0\n\n");
	CNE_lisse_ccero(in);
	
	if(in!=NULL){
		
		imp_lisse(in);
	
	
//Proceso //Salida de datos
	
		leer_nro_e("\n\nIngrese un valor a buscar: ",n);
	
		if(busnro_lisse(in,n)){
		
			printf("\n\nEl valor %d esta en la lista\n\n",n);
			
			cant=cantnro_lisse(in,n);
		
			printf("Cantidad de veces que aparece el n%cmero: %d",163,cant);
			
			
		}else{
		
			printf("\n\nEl valor %d no esta en la lista\n\n",n);
		
		}
		
		cant=cantpar_lisse(in);
			
		printf("\n\nCantidad de numeros par: %d",cant);	
		
		if(in_orden_menma_lisse(in)){
			
			printf("\n\nLa lista esta ordenada de menor a mayor.\n\n");
			
		}else{
			
			printf("\n\nLa lista no esta ordenada de menor a mayor.\n\n");
			ordena_menma_lisse(in);
			printf("Lista ordenada: \n");
			imp_lisse(in);
			
		}
		
		printf("\n\nIngreso de nodo adelante de la lista.\n\n");
		leer_nro_e("\nIngrese un valor: ",n);
		insert_p_lisse(in,n);
		imp_lisse(in);
		
		printf("\n\nIngreso de nodo al fin de la lista.\n\n");
		leer_nro_e("\nIngrese un valor: ",n);
		insert_u_lisse(in,n);
		imp_lisse(in);
		
		printf("\n\nIngreso de nodo, ingreso manteniendo el orden de menor a mayor de los valores enteros\n\n");
		leer_nro_e("\nIngrese un valor: ",n);
		insert_ordmenmay_lisse(in,n);
		imp_lisse(in);
		
		printf("\n\nSe elimina el primer nodo\n\n");
		dele_p_lisse(in);
		imp_lisse(in);
		
		printf("\n\nSe eliminal el ultimo nodo\n\n");
		dele_u_lisse(in);
		imp_lisse(in);
		
		printf("\n\nEliminacion de valores, borrara el primer valor que encuentre.\n\n");
		leer_nro_e("\n\nIngrese un valor a eliminar: ",n);
		dele_ocu_lisse(in,n);
		imp_lisse(in);
		
		
	}else{
		
		printf("\n\nNo se cargaron nodos\n\n");
			
	}
	
	printf("\n\nIngrese valores par a la lista. Finaliza el ingreso con 0\n\n");
	CNE_par_ccero(in);
	imp_lisse(in);
	
	leer_nro_epar("\n\nIngrese un valor par: ",n);
	CNE_priult_lisse(in,n);
	imp_lisse(in);
	
	CNE_ccero_r(in);
	imp_lisse(in);
		
	intercambio_lisse(in);
	printf("\n");
	imp_lisse(in);
	
	cant=suma_impar_lisse(in);
	printf("\n\nLa suma de los impares es: %d",cant);
	
	cant=suma_posimpar_lisse(in);
	printf("\n\nLa suma de las posiciones impares es: %d",cant);
	
	printf("\n\n");
	imp_impar_lisse(in);
	printf("\n\n");
	imp_impar_lisse_r(in);
	
//Pausa y fin de programa

	pausar();
	return 0;

}
