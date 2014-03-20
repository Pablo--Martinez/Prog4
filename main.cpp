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

int main(){
	
	char* comando = new char;
 
	cout << "COMANDOS"<< endl;
	cout << "-->\tcrearPaga monto moneda"<< endl;
	cout << "-->\tsumarPagas monto1 moneda1 monto2 moneda2 "<< endl;
	cout << "-->\tproductoPaga monto moneda cantidad"<< endl;
	cout << "-->\taDolar monto moneda" << endl;
	cout << "-->\taPeso monto moneda" << endl;
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
			float monto;
			char* moneda = new char;
			
			cin >> monto;
			cin >> moneda;
			
			//Intento crear la paga solicitada
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
			
			delete moneda;
		}
		
		//Sumar pagas
		else if(!strcmp(comando,"sumarPagas")){
			Paga p1,p2,p;
			float monto1, monto2;
			char* moneda1 = new char;
			char* moneda2 = new char;
			
			cin >> monto1 >> moneda1 >> monto2 >> moneda2;
			try{
				//Creo la primer paga
				if(!strcmp(moneda1,"us")){
					p1 = Paga(monto1,us);
					cout << "1er paga: " << p1 << endl;
				}
				else{
					p1 = Paga(monto1,usd);
					cout << "1er paga: " << p1 << endl;
				}
				
				//Creo la segunda paga
				try{
					if(!strcmp(moneda2,"us")){
						p2 = Paga(monto2,us);
						cout << "2da paga: " << p2 << endl;
					}
					else{
						p2 = Paga(monto2,usd);
						cout << "2da paga: " << p2 << endl;
					}
				}
				catch(std::invalid_argument){
					cout << "Argumento invalido!" << endl;
				}
				
				//Sumo ambas pagas
				try{
					p = p1 + p2;
					cout << "Suma total: " << p << endl;
				}
				catch(std::invalid_argument){
					cout << "Argumento invalido!" << endl;
				}
				
				delete moneda1;
				delete moneda2;
				
			}
			catch(std::invalid_argument){
				cout << "Argumento invalido!" << endl;
			}
		}
		
		//Producto de paga por entero
		else if(!strcmp(comando,"productoPaga")){
			Paga p;
			int cantidad;
			float monto;
			char* moneda = new char;
			
			cin >> monto;
			cin >> moneda;
			cin >> cantidad;
			
			//Creo la paga
			try{
				if(!strcmp(moneda,"us")){
					p = Paga(monto,us);
					cout << "Paga: " << p << endl;
				}
				else{
					p = Paga(monto,usd);
					cout << "Paga: " << p << endl;
				}	
				
				//Realizo la operacion
				try{
					p = p * cantidad;
					cout << "Producto: " << p << endl;
				}
				catch(std::invalid_argument){
					cout << "Argumento invalido!" << endl;
				}				
			}
			catch(std::invalid_argument){
				cout << "Argumento invalido!" << endl;
			}
			
			delete moneda;
	
		}
		
		//Convertir paga a dolares
		else if(!strcmp(comando,"aDolar")){
			Paga p;
			float monto;
			char * moneda = new char;
			try{
				cin >> monto >> moneda;
				if(!strcmp(moneda,"us")){
					p = Paga(monto,us);
					cout << "Paga: " << p << endl;
				}
				else{
					p = Paga(monto,usd);
					cout << "Paga: " << p << endl;
				}
				
				p = p.a_dolar();
				cout << "Paga en dolares: " << p << endl;
			}
			catch(std::invalid_argument){
				cout << "Argumento invalido!" << endl;
			}
			
			delete moneda;
			
		}
		
		//Convertir paga a pesos
		else if(!strcmp(comando,"aPeso")){
			Paga p;
			float monto;
			char * moneda = new char;
			try{
				cin >> monto >> moneda;
				if(!strcmp(moneda,"us")){
					p = Paga(monto,us);
					cout << "Paga: " << p << endl;
				}
				else{
					p = Paga(monto,usd);
					cout << "Paga: " << p << endl;
				}
				
				p = p.a_peso();
				cout << "Paga en pesos: " << p << endl;
			}
			catch(std::invalid_argument){
				cout << "Argumento invalido!" << endl;
			}
			
			delete moneda;
		}
		
		//Comando invalido
		else{
			cout << "Comando invalido!" << endl;
		}
			
		cout << ">> ";	
    }
    
    cout << "Termina" << endl;
    delete comando;
    return 0;
}
