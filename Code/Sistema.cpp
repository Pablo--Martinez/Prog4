#include <stdexcept>
#include "ControladorUsuarios.h"
#include "ControladorConsultas.h"
#include "ManejadorAdministradores.h"
#include "ManejadorMedicamentos.h"

using namespace std;

//FUNCIONES AUXILIARES
Fecha ingresarFecha(){
	int dia, mes, anio, hora, minutos;
	cout << "Dia: ";
	cin >> dia;
	while(dia <= 0 || dia > 31){
		cout << "Dia incorrecto, ingrese nuevamente: ";
		cin >> dia;
	}

	//Se ingresa el mes
	cout << "Mes: ";
	cin >> mes;
	while(mes <= 0 || mes > 12){
		cout << "Mes incorrecto, ingrese nuevamente: ";
		cin >> mes;
	}

	//Se ingresa el anio
	cout << "Anio: ";
	cin >> anio;
	while(anio<= 0){
		cout << "Anio incorrecto, ingrese nuevamente: ";
		cin >> anio;
	}

	//Se ingresa la hora
	cout << "Hora: ";
	cin >> hora;
	while(hora< 0 || hora > 23){
		cout << "Hora incorrecto, ingrese nuevamente: ";
		cin >> anio;
	}

	//Se ingresan los minutos ?????
	cout << "Minutos: ";
	cin >> minutos;
	while(minutos< 0 || minutos > 59){
		cout << "Minutos incorrecto, ingrese nuevamente: ";
		cin >> minutos;
	}

	return Fecha(dia,mes,anio,hora,minutos);
}

// CASOS DE USO

void modificarFechaSistema(){
	int dia, mes, anio, hora, min;
	RelojSistema* rs = RelojSistema::getInstance();
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();

	cout << "Nueva fecha: ";
	cin >> dia >> mes >> anio >> hora >> min;
	rs->modificarFechaSistema(dia,mes,anio,hora,min);
	cu->recalcularInasistencias(rs->getFechaSistema());
}

void iniciarSesion(){}

void cerrarSesion(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();

	try{
		cu->cerrarSesion();
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "ERROR: " << e.what() << endl;
	}
}

void altaReactivacionUsuario(){}

void altaRepresentacionDiagnosticos(){}

void reservaConsulta(){}

void registroConsulta(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();

	//Si no existe un usuario logueado, se fuerza a loguearse
	if(!cu->usuarioLogueado())
		iniciarSesion();
		Administrador* admin = ma->find(cu->getUsuarioLogueado()->getCI());

	//Si el usuario logueado no es del tipo requerido, se lanza una excepcion
	if(admin == NULL)
		throw std::invalid_argument("UsuarioRolIncorrecto");

	ManejadorSocios* ms = ManejadorSocios::getInstance();

	//Se procede a ingresar los datos del socio
	int ci_socio;
	cout << "Ingrese ci del socio: ";
	cin >> ci_socio;
	while(ci_socio <= 0){ //Si no es correcto el formato de la ci, se fuerza a ingresar nuevamente
		cout << "Cedula incorrecta, ingrese nuevamente: ";
		cin >> ci_socio;
	}

	//Se selecciona el tipo de consulta a registrar
	string tipo_consulta;
	cout << "Ingrese tipo de consulta(reserva/emergencia): ";
	cin >> tipo_consulta;
	while(tipo_consulta != "reserva" || tipo_consulta != "emergencia"){
		cout << "Tipo incorrecto, ingrese nuevamente: ";
		cin >> tipo_consulta;
	}

	ControladorConsultas* cc = ControladorConsultas::getInstance();
	RelojSistema* rs = RelojSistema::getInstance();
	Fecha fecha_consulta;

	//Se ingresa la fecha de la consulta
	fecha_consulta = ingresarFecha();

	if(tipo_consulta == "reserva"){
		int ci_doc;

		//Se procede a seleccionar el medico que va a tratar la consulta
		cout << "Ingrese ci del medico: ";
		cin >> ci_doc;
		while(ci_doc <= 0){//Si el formato de la ci es incorrecto se fuerza
			cout << "Cedula incorrecta, ingrese nuevamente: ";
			cin >> ci_doc;
		}

		try{
			cc->registroReserva(ci_socio,ci_doc,rs->getFechaSistema(),fecha_consulta);
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Argumento invalido: " << e.what() << endl;
		}

		cout << "Reserva registrada correctamente! " << endl;
	}
	else{
		int criterio, cantidad, ci_doc;
		string motivo;

		cout << "Criterio de seleccion de medico: " << endl <<
				"1) Medicos libres" << endl <<
				"2) Medicos del paciente";
		cin >> criterio;
		while(criterio <= 0 || criterio > 2){
			cout << "Criterio incorrecto, ingrese nuevamente: ";
			cin >> criterio;
		}

		if(criterio == 1){
			cout << "Ingrese una cantidad: ";
			cin >> cantidad;
			while(cantidad <= 0){
				cout << "Cantidad incorrecta, ingrese nuevamente: ";
				cin >> cantidad;
			}
			cc->setCantidad(cantidad);
		}
		cc->seleccionarCriterio(criterio);
		set<DataMedico*> medicos_disponibles = cc->ejecutarStrategy();
		ManejadorMedicos* mm = ManejadorMedicos::getInstance();
		int i=0, disponibles[mm->getMedicos().size()];

		if(!medicos_disponibles.empty()){ //El strategy dio resultados
			cout << "Medicos disponibles: " << endl;
			for(set<DataMedico*>::iterator it = medicos_disponibles.begin();it!=medicos_disponibles.end();++it){
				cout << "\t" << i+1 << ")" << (*it)->getUsuario()->getCI() << ":" << (*it)->getUsuario()->getNombre() << endl;
				disponibles[i] = (*it)->getUsuario()->getCI();
				i++;
			}
		}

		else{// El strategy no dio resultados
			cout << "No hay medicos disponibles, se listaran todos: " << endl;
			for(map<int,Medico*>::iterator it = mm->getMedicos().begin();it!=mm->getMedicos().end();++it){
				cout << "\t" << i+1 << ")" << it->first << it->second->getDataMedico()->getUsuario()->getNombre() << endl;
				disponibles[i] = it->first;
				i++;
			}

		}
		int seleccionado;
		cout << "Seleccionar medico(1.." << i+1 << ")";
		cin >> seleccionado;
		while(seleccionado <= 0 || seleccionado > i){
			cout << "Seleccion incorrecta, ingrese nuevamente: ";
			cin >> seleccionado;
		}
		ci_doc = disponibles[seleccionado-1];

		cout << "Motivo de la emergencia: ";
		cin >> motivo;

		try{
			cc->registroEmergencia(ci_socio,ci_doc,motivo,fecha_consulta);
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Argumento invalido: " << e.what() << endl;
		}
	}
}

void altaDiagnosticosConsulta(){}

void altaMedicamento(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();

	if(!cu->usuarioLogueado())
		iniciarSesion();

	Administrador* admin = ma->find(cu->getUsuarioLogueado()->getCI());
	if(admin == NULL)
		throw std::invalid_argument("UsuarioRolIncorrecto");

	ManejadorMedicamentos* mm = ManejadorMedicamentos::getInstance();
	string nombre;
	cout << "Nombre nuevo medicamento: ";
	cin >> nombre;
	bool existe_medicamento = mm->existeMedicamento(nombre);
	while(existe_medicamento){
		cout << "Medicamento existente, ingrese nuevamente: ";
		cin >> nombre;
		existe_medicamento = mm->existeMedicamento(nombre);
	}
	mm->ingresarMedicamento();
}

void devolucionConsulta(){}

void usuariosDadosDeAlta(){}

void listarRepresentacionDiagnosticos(){}

void obtenerHistorialPaciente(){}

void notificarMedicos(){}

//MAIN PRINCIPAL

int main(){

	return 0;
}
