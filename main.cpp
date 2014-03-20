#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>

#include "Moneda.h"
#include "Cambio.h"
#include "Paga.h"

using namespace std;

int main(int argc, char* argv[])
{
    //system("cls");
    char comando[20];
    float monto;
    char moneda[5];
    
	cout << "Comandos"<< endl;
	cout << "-->\tcrearPaga monto moneda"<< endl;
	cout << "-->\tsumarPagas monto1 moneda1 monto2 moneda2 "<< endl;
	cout << "-->\tproductoPaga monto moneda cantidad"<< endl;
	cout << "-->\tsalir"<< endl << endl;
	cout << ">> ";
     
    while (true) {
		cin >> comando;
		
		//Salir
		if(!strcmp(comando,"salir")){
			break;
		}
		
		//Crear paga
		else if(!strcmp(comando,"crearPaga")){
			cin >> monto;
			cin >> moneda;
			try{
				if(!strcmp(moneda,"us")){
					Paga p(monto,us);
					cout << "Paga: " << p << endl;
				}
				else{
					Paga p(monto,usd);
					cout << "Paga: " << p << endl;
				}	
							
			}
			catch(std::invalid_argument){
				cout << "Argumento invalido!" << endl;
			}
		}
		
		//Sumar pagas
		else if(!strcmp(comando,"sumarPagas")){
			Paga p1,p2,p;
			
			cin >> monto;
			cin >> moneda;
			try{
				if(!strcmp(moneda,"us")){
					p1 = Paga(monto,us);
					cout << "Paga: " << p1 << endl;
				}
				else{
					p1 = Paga(monto,usd);
					cout << "Paga: " << p1 << endl;
				}					
			}
			catch(std::invalid_argument){
				cout << "Argumento invalido!" << endl;
			}
			
			cin >> monto;
			cin >> moneda;
			try{
				if(!strcmp(moneda,"us")){
					p2 = Paga(monto,us);
					cout << "Paga: " << p2 << endl;
				}
				else{
					p2 = Paga(monto,usd);
					cout << "Paga: " << p2 << endl;
				}					
			}
			catch(std::invalid_argument){
				cout << "Argumento invalido!" << endl;
			}
			
			try{
				p = p1 + p2;
				cout << "Suma: " << p << endl;
			}
			
			catch(std::invalid_argument){
				cout << "Argumento invalido!" << endl;
			}
		}
		
		//Producto de paga por entero
		else if(!strcmp(comando,"productoPaga")){
			Paga p;
			int cantidad;
			
			cin >> monto;
			cin >> moneda;
			cin >> cantidad;
			
			try{
				if(!strcmp(moneda,"us")){
					p = Paga(monto,us);
					cout << "Paga: " << p << endl;
				}
				else{
					p = Paga(monto,usd);
					cout << "Paga: " << p << endl;
				}					
			}
			catch(std::invalid_argument){
				cout << "Argumento invalido!" << endl;
			}
			
			try{
				p = p * cantidad;
				cout << "Producto: " << p << endl;
			}
			
			catch(std::invalid_argument){
				cout << "Argumento invalido!" << endl;
			}
		}
		
		//Comando invalido
		else{
			cout << "Comando invalido!" << endl;
		}
			
		cout << ">> ";	
    }
    
    printf ("Termina %s \n","");
    
    return 0;
}
