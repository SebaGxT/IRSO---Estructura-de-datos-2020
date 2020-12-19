//Librerias
#include "Lib_io_seba.h"
#include <time.h>
#include <ctype.h>

/*1) Definir una clase para manejar una alcancia. Tener en cuenta lo siguiente:

"	La alcancia maneja monedas de 50centavos (0,50$), de 1$ y de 2$.
"	Se puede insertar en  la alcancia cada una  de estas monedas. 
"	La alcancia admite hasta 500 monedas en total ya que las tres monedas son mas o menos del mismo tamaño. Es decir, si quiero insertar  la moneda nro. 501 no puedo hacerlo.
"	Esta alcancia mediante una palanquita permite sacar una moneda. Pero devuelve una cualquiera, es decir, no puedo pedir por tipo de moneda.
"	Tambien mediante una segunda palanquita permite vaciar su contenido, emitiendo cuantas monedas de cada tipo hay y el total en $ y centavos.

¿Qué se puede hacer con la alcancia?

"	Inicializar la alcancia vacia.
"	Insertar una moneda de 0,50$ o 1$ o 2$.
"	Sacar una moneda al azar.
"	Vaciar toda la alcancia mostrando la cantidad de monedas por tipo que da y el total en pesos.
"	Mostar cuantas monedas hay por tipo.
"	Mostrar el total en $ y centavos que hay por cada tipo de moneda.
"	Mostrar la cantidad total de monedas que hay.
"	Mostrar el total en $ y centavos que hay.
"	Verificar si la alcancia esta vacia.
"	Verificar si la alcancia esta llena.

Definir las propiedades de la clase y los metodos que crea convenientes para el manejo de la alcancia.*/

//Clases y Objetos

class alcancia{
	
	private:
		
		int cant_moneda_50;
		int cant_moneda_1;
		int cant_moneda_2;
		int cant_moneda_t;
		int capacidad;
		float balance;
	
	public:
		
		alcancia(void);
		alcancia(int cantm50, int cantm1, int cantm2);
		void capacidad_mon(void);
		void mostrar_info(void);
		void ingresar_moneda(float mon);
		void retirar_moneda(void);
		void retiro_total(void);
		~alcancia();
	
};

//Funciones y Procedimientos
alcancia::alcancia(void){
	
	cant_moneda_50=0;
	cant_moneda_1=0;
	cant_moneda_2=0;
	cant_moneda_t=0;
	capacidad=500;
	balance=0;
	printf("\n\nSe creo una alcancia vacia, limite maximo %d monedas\n\n",capacidad);
	
}

alcancia::alcancia(int cantmo50, int cantmo1, int cantmo2){
		
		capacidad=500;
		cant_moneda_t=cantmo50+cantmo1+cantmo2;
		if(cant_moneda_t<=capacidad){
			
			balance=cantmo50*0.50+cantmo1+cantmo2*2;
			printf("\n\nSe creo una alcancia:\nBalance: %d\nCantidad de monedas de 50: %d\nCantidad de monedas de 1: %d\nCantidad de monedas de 2: %d\n\n",balance,cantmo50,cantmo1,cantmo2);
			
		}else{
			
			printf("\nNo es posible ingresar esa cantidad de monedas, excede el limite.\n\n");
			balance=0;
			cant_moneda_50=0;
			cant_moneda_1=0;
			cant_moneda_2=0;
			cant_moneda_t=0;
			printf("Se creo una alcancia vacia, limite maximo %d\n\n",capacidad);
			
		}
	
}

void opciones(){
	
	printf("\n\n1. Mostrar cantidad de monedas.\n\n");
	printf("2. Mostrar balance.\n\n");
	printf("3. Capacidad maxima de la alcancia.\n\n");
	printf("4. Opciones.\n\n");
	printf("5. Salir.\n\n");
	
}

void alcancia::mostrar_info(void){
	
	int n;
	char a;
	bool valid;
	
	valid=false;
	
	opciones();
	
	while(valid==false){
		
		leer_nro_ep("\nIngrese una opcion: ",n);
		
		switch (n){
			
			case 1:{
				
				printf("\n\nCantidad de monedas en alcancia: %d\n\n",cant_moneda_t);
				break;
				
			}
			
			case 2:{
				
				printf("\n\nEl balance actual es: %.2f\n\n",balance);
				break;
				
			}
			
			case 3:{
				
				printf("\n\nLa capacidad m%cxima de la alcancia es: %d\n\n",160,capacidad);
				break;
				
			}
			
			case 4:{
				
				opciones();
				break;
				
			}
			
			case 5:{
				
				valid=true;
				break;
				
			}
			
			default: 
				
				printf("\n\nOpcion invalida, vuelva a ingresar.\n\n");
			
		}
		
	}
				
}	

void alcancia::ingresar_moneda(float m){
	
	if(cant_moneda_t<=capacidad){
		
		if(m==0.50){
			
			cant_moneda_50++;
			cant_moneda_t++;
			balance+=m;
			
		}else if(m==1.00){
			
			cant_moneda_1++;
			cant_moneda_t++;
			balance+=m;
			
		}else if(m==2.00){
			
			cant_moneda_2++;
			cant_moneda_t++;
			balance+=m;
			
		}else{
			
			printf("\n\nTipo de moneda incorrecta. Inserte de %c0.50, %c1.00 o %c2.00",36,36,36);
			
		}
		
	}else{
		
		printf("\nno es posible ingresar esa cantidad de monedas, excede el limite.\n\n");
		
	}
	
}

void alcancia::retirar_moneda(void){
	
	int n;
	bool valid;
	
	valid=false;
			
	
	n=1+rand()%(3);
	
	if(cant_moneda_t>0){
		
		while(valid==false){
			
			if(n==1&&cant_moneda_50>0){
			
				cant_moneda_50--;
				cant_moneda_t--;
				balance=balance-0.50;
				valid=true;
				printf("\n\nSe retiro una moneda de %c0.50.\n\n",36);
			
			}else{
			
				n=1+rand()%(3);
				
			}
			
			if(n==2&&cant_moneda_1>0){
			
				cant_moneda_1--;
				cant_moneda_t--;
				balance=balance-1;
				valid=true;
				printf("\n\nSe retiro una moneda de %c1.00.\n\n",36);
			
			}else{
			
				n=1+rand()%(3);
				
			}
			
			if(n==3&&cant_moneda_2>0){
			
				cant_moneda_2--;
				cant_moneda_t--;
				balance=balance-2;
				valid=true;
				printf("\n\nSe retiro una moneda de %c2.00.\n\n",36);
			
			}else{
			
				n=1+rand()%(3);
				
			}
			
		}
		
	}else{
		
		printf("\n\nAlcancia vacia.\n\n");
		
	}
	
}

void alcancia::retiro_total(void){
	
	printf("\n\nEl total del balance es: %.2f",balance);
	balance=0;
	printf("\n\nLa cantidad de monedas retiradas es: %d\n\n",cant_moneda_t);
	cant_moneda_t=0;
	
}

alcancia::~alcancia(){};

void opciones2(){
	
	printf("\n\n1. Ingresar monedas.\n\n");
	printf("2. Retirar una moneda.\n\n");
	printf("3. Mostrar informacion.\n\n");
	printf("4. Retirar todo.\n\n");
	printf("5. Opciones.\n\n");
	printf("6. Salir.\n\n");
	
}

/*2) El programa principal debera poder trabajar con una o dos alcancias. El usuario debera setear la alcancia para comenzar, es decir, vacia. Y luego llenarla con monedas, sacar monedas,
 verificar si esta llena, vacia o no, ver cuantas monedas quedan, que monto tiene la alcancia, etc.*/

//Main
int main(){

//Variables
	
	int n, moneda;
	bool valid,valid2;
	
	valid=false;
	valid2=false;

//Ingreso de datos
	
	alcancia alc1;
	
	printf("\n\nAlcancia\n\n");
	
	while(valid==false){
		
		opciones2();
		
		leer_nro_ep("\nIngrese una opcion: ",n);
		
		switch(n){
			
			case 1:{
				
				printf("\nAl seleccionar una opcion ingresara una moneda.\n\n");
				
				do{
					
					printf("\n1.%c0.50\n",36);
					printf("\n2.%c1.00\n",36);
					printf("\n3.%c2.00\n",36);
					printf("\n4.Salir\n\n");
					
					leer_nro_ep("\nIngrese la opcion: ",moneda);
					
					switch(moneda){
						
						case 1:{
							
							
							alc1.ingresar_moneda(0.50);
							break;
							
						}
						
						case 2:{
							
							
							alc1.ingresar_moneda(1.00);
							break;
							
						}
						
						case 3:{
							
							
							alc1.ingresar_moneda(2.00);
							break;
							
						}
						
						case 4:{
							
							
							valid2=true;
							break;
							
						}
						
						default:
							
							printf("\n\nOpcion inv%clida. Vuelva a intentarlo.\n\n",160);
						
					}
					
				}while(valid2==false);
				
				valid2=false;
								
				break;
//Proceso				
			}
			
			case 2:{
				
				
				alc1.retirar_moneda();
				break;
				
			}
			
			case 3:{
				
				
				alc1.mostrar_info();
				break;
				
			}
			
			case 4:{
				
				
				alc1.retiro_total();
				break;
				
			}
			
			case 5:{
				
				
				opciones2();
				break;
				
			}
			
			case 6:{
				
				
				valid=true;
				break;
				
			}
			
			default:
				
				printf("\n\nOpcion inv%clida, ingrese otra opcion.\n\n",160);
			
		}
		
	}	

//Pausa y fin de programa

	pausar();
	return 0;

}
