#include <iostream>
#include <string.h>
//#include <sstream>
//#include <stdio.h>
//#include <stdlib.h>
#include <stdexcept>

#include "Moneda.h"
#include "Cambio.h"
#include "Paga.h"
#include "Empleado.h"
#include "Jornalero.h"
#include "Fijo.h"
#include "Empresa.h"

using namespace std;

int main(){

	char* comando = new char[50];
	Empresa* empresa = NULL;
    Jornalero* j = NULL;
    Fijo* f = NULL;

	cout << "COMANDOS PAGA"<< endl;
	cout << "-->\tcrearPaga monto moneda"<< endl;
	cout << "-->\tsumarPagas monto1 moneda1 monto2 moneda2 "<< endl;
	cout << "-->\tproductoPaga monto moneda cantidad"<< endl;
	cout << "-->\taDolar monto moneda" << endl;
	cout << "-->\taPeso monto moneda" << endl << endl;

	cout << "COMANDOS EMPRESA"<< endl;
	cout << "-->\tcrearEmpresa nombre nombre_legal rut" << endl;
	cout << "-->\tagregarJornalero nombre ci edad monto_hora moneda_hora horas" << endl;
	cout << "-->\tagregarFijo nombre ci edad monto_hora moneda_hora" << endl;
	cout << "-->\tcalcularSueldoDolar" << endl;
	cout << "-->\tcalcularSueldoPeso" << endl;
	cout << "-->\tdatosEmpresa" << endl;
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
			char* moneda = new char[10];

			cin >> monto;
			cin >> moneda;

			//Intento crear la paga solicitada
			try{
				if(!strcmp(moneda,"us")){
					Paga p(monto,us);
					cout << "Paga: " << p << endl;
				}
				else if(!strcmp(moneda,"usd")){
					Paga p(monto,usd);
					cout << "Paga: " << p << endl;
				}
				else{
					cout << "Argumento ivalido: Moneda incorrecta" << endl;
				}

			}
			catch (const std::invalid_argument& e) {
				std::cerr << "Argumento invalido: " << e.what() << endl;
			}

			delete moneda;
		}

		//Sumar pagas
		else if(!strcmp(comando,"sumarPagas")){
			Paga p1,p2,p;
			float monto1, monto2;
			char* moneda1 = new char[10];
			char* moneda2 = new char[10];

			cin >> monto1 >> moneda1 >> monto2 >> moneda2;
			try{
				//Creo la primer paga
				if(!strcmp(moneda1,"us")){
					p1 = Paga(monto1,us);
					cout << "1er paga: " << p1 << endl;
				}
				else if(!strcmp(moneda1,"usd")){
					p1 = Paga(monto1,usd);
					cout << "1er paga: " << p1 << endl;
				}
				else{
					cout << "Argumento ivalido: Moneda incorrecta" << endl;
				}

				//Creo la segunda paga
				try{
					if(!strcmp(moneda2,"us")){
						p2 = Paga(monto2,us);
						cout << "2da paga: " << p2 << endl;
					}
					else if(!strcmp(moneda2,"usd")){
						p2 = Paga(monto2,usd);
						cout << "2da paga: " << p2 << endl;
					}
					else{
						cout << "Argumento ivalido: Moneda incorrecta" << endl;
					}

					//Sumo ambas pagas
					try{
						p = p1 + p2;
						cout << "Suma total: " << p << endl;
					}
					catch (const std::invalid_argument& e) {
						std::cerr << "Argumento invalido: " << e.what() << endl;
					}
				}
				catch (const std::invalid_argument& e) {
					std::cerr << "Argumento invalido: " << e.what() << endl;
				}

				delete moneda1;
				delete moneda2;

			}
			catch (const std::invalid_argument& e) {
				std::cerr << "Argumento invalido: " << e.what() << endl;
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
				else if(!strcmp(moneda,"usd")){
					p = Paga(monto,usd);
					cout << "Paga: " << p << endl;
				}
				else{
					cout << "Argumento ivalido: Moneda incorrecta" << endl;
				}

				//Realizo la operacion
				try{
					p = p * cantidad;
					cout << "Producto: " << p << endl;
				}
				catch (const std::invalid_argument& e) {
					std::cerr << "Argumento invalido: " << e.what() << endl;
				}
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "Argumento invalido: " << e.what() << endl;
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
				else if(!strcmp(moneda,"usd")){
					p = Paga(monto,usd);
					cout << "Paga: " << p << endl;
				}
				else{
					cout << "Argumento ivalido: Moneda incorrecta" << endl;
				}

				p = p.a_dolar();
				cout << "Paga en dolares: " << p << endl;
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "Argumento invalido: " << e.what() << endl;
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
				else if(!strcmp(moneda,"usd")){
					p = Paga(monto,usd);
					cout << "Paga: " << p << endl;
				}
				else{
					cout << "Argumento ivalido: Moneda incorrecta" << endl;
				}

				p = p.a_peso();
				cout << "Paga en pesos: " << p << endl;
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "Argumento invalido: " << e.what() << endl;
			}

			delete moneda;
		}

		//Crear Empresa "-->crearEmpresa nombre nombre_legal rut"
		else if(!strcmp(comando,"crearEmpresa")) {
			char* nombre = new char;
			char* nombre_legal = new char;
			int rut;

			cin >> nombre >> nombre_legal >> rut;

			//Intento crear la empresa
			if(empresa == NULL){
				try{
					empresa = new Empresa(nombre,nombre_legal,rut);
					cout << *empresa << endl;
				}
				catch (const std::invalid_argument& e) {
					std::cerr << "Argumento invalido: " << e.what() << endl;
				}
			}
			else{
				cout << "La empresa ya existe" << endl;
			}

			delete nombre;
			delete nombre_legal;
		}

		//Agregar Jornalero "-->agregarJornalero nombre ci edad monto_hora moneda_hora horas"
		else if(!strcmp(comando,"agregarJornalero")) {
			char* nombre = new char[50];
			char* ci = new char[50];
			int edad;
			float monto_hora;
			char* moneda_hora = new char[10];
			int horas;

			cin >> nombre >> ci >> edad >> monto_hora >> moneda_hora >> horas;

			//Intento crear la paga solicitada
			Paga paga;
			try{
				if(!strcmp(moneda_hora,"us")){
					paga = Paga(monto_hora,us);
					try{
						j = new Jornalero(nombre,ci,edad,paga,horas,empresa);
						cout << *j << endl;
						empresa->agregar_empleado(j);
					}
					catch (const std::invalid_argument& e) {
						std::cerr << "Argumento invalido: " << e.what() << endl;
					}
				}

				else if(!strcmp(moneda_hora,"usd")){
					paga = Paga(monto_hora,usd);
					try{
						j = new Jornalero(nombre,ci,edad,paga,horas,empresa);
						cout << *j << endl;
						empresa->agregar_empleado(j);
					}
					catch (const std::invalid_argument& e) {
						std::cerr << "Argumento invalido: " << e.what() << endl;
					}
				}

				else{
					cout << "Argumento ivalido: Moneda incorrecta" << endl;
				}
			}

			catch (const std::invalid_argument& e) {
				std::cerr << "Argumento invalido: " << e.what() << endl;
			}

			delete nombre;
			delete ci;
			delete moneda_hora;
		}

		//Agregar Fijo "-->agregarFijo nombre ci edad monto_hora moneda_hora"
		else if(!strcmp(comando,"agregarFijo")) {
			char* nombre = new char[50];
			char* ci = new char[50];
			int edad;
			float monto_hora;
			char* moneda_hora = new char[10];

			cin >> nombre >> ci >> edad >> monto_hora >> moneda_hora;

			//Intento crear la paga solicitada
			Paga paga;
			try{
				if(!strcmp(moneda_hora,"us")){
					paga = Paga(monto_hora,us);
					try{
						f = new Fijo(nombre,ci,edad,paga,empresa);
						cout << *f << endl;
						empresa->agregar_empleado(f);
					}
					catch (const std::invalid_argument& e) {
						std::cerr << "Argumento invalido: " << e.what() << endl;
					}
				}

				else if(!strcmp(moneda_hora,"usd")){
					paga = Paga(monto_hora,usd);
					try{
						f = new Fijo(nombre,ci,edad,paga,empresa);
						cout << *f << endl;
						empresa->agregar_empleado(f);
					}
					catch (const std::invalid_argument& e) {
						std::cerr << "Argumento invalido: " << e.what() << endl;
					}
				}

				else{
					cout << "Argumento ivalido: Moneda incorrecta" << endl;
				}
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "Argumento invalido: " << e.what() << endl;
			}

			delete nombre;
			delete ci;
			delete moneda_hora;
		}

		else if(!strcmp(comando,"calcularSueldoDolar")){
			Paga p = empresa->total_sueldo_dolar();
			cout << "Total: " << p << endl;
		}

		else if(!strcmp(comando,"calcularSueldoPeso")){
			Paga p = empresa->total_sueldo_peso();
			cout << "Total: " << p << endl;
		}

		else if(!strcmp(comando,"datosEmpresa")){
			if(empresa != NULL){
				cout << *empresa << endl;
				empresa->imprimir_empleados();
			}
			else{
				cout << "ERROR: Empresa inexistente"<< endl;
			}
		}

		//Comando invalido
		else{
			cout << "Comando invalido!" << endl;
		}

		cout << ">> ";
    }

    cout << "Termina" << endl;
    delete comando;
    if (j != NULL) delete j;
    if (f != NULL) delete f;
    if (empresa != NULL) delete empresa;
    return 0;
}
