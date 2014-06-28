#include <stdexcept>
#include <iostream>
#include "ControladorUsuarios.h"
#include "ControladorConsultas.h"
#include "ControladorDiagnosticos.h"
#include "ManejadorAdministradores.h"
#include "ManejadorMedicamentos.h"
#include "ManejadorRepresentaciones.h"

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

void iniciarSesion(){
  
	int ci;
	bool escorrecta;
	string pass, nombreMedicamento;

	cout << "Iniciar sesion" << endl;
	cout << "Ingrese el Documento: ";cin >> ci;
	cout << "Ingrese la contraseña: ";cin >> pass;

	TSesion ts;
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	try{
		ts = cu->iniciarSesion(ci);

		if((ts == APD)||(ts == CM)){ //Común o administrativo

			  escorrecta = cu->ingresarContrasenia(pass);
			  if (escorrecta){
					  cu->asignarSesion();
			  }else{
				  throw std::invalid_argument("La contraseña no es correcta.");
			  }

		}else{ //Por primera vez
			cu->activarUsuario(pass);
			cu->asignarSesion();
		}
	}catch(const std::invalid_argument& e){
		std::cerr << "ERROR: " << e.what() << endl;
		string continuar;
		cout << "Reintentar(S/N)?: ";cin >> continuar;
		if(continuar == "S")
			iniciarSesion();
	}
}

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


void reservaConsulta(){

//	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
//	ManejadorSocios* ms = ManejadorSocios::getInstance();

	// if(!cu->usuarioLogueado())
	//	iniciarSesion();

	//Socio* soc = ms->find(cu->getUsuarioLogueado()->getCI());

/*
	if(typeof 12 == int)
		throw std::invalid_argument("UsuarioRolIncorrecto");
*/


	//cout << "Ingresar fecha del sistema:" << endl;

	//Fecha f = ingresarFecha();

	cout << "Dale bo";
	ControladorConsultas* cc = ControladorConsultas::getInstance();
	//cc->ingresarFechaConsulta(f);
	cout << "Dale bo";
	set<DataUsuario*> medicos_disponibles = cc->obtenerMedicos();

	int i=0, disponibles[medicos_disponibles.size()];
	if(!medicos_disponibles.empty()){
			cout << "Medicos disponibles: " << endl;
			for(set<DataUsuario*>::iterator it = medicos_disponibles.begin();it!=medicos_disponibles.end();++it){
				cout << "\t" << i+1 << ")" << (*it)->getNombre() << " " << (*it)->getApellido() << endl;
				disponibles[i] = (*it)->getCI();
				i++;
			}

			int seleccionado;
			cout << "Seleccionar medico(1.." << i+1 << ")";
			cin >> seleccionado;
			while(seleccionado <= 0 || seleccionado > i){
				cout << "Seleccion incorrecta, ingrese nuevamente: ";
				cin >> seleccionado;
			}
			int ci_med = disponibles[seleccionado-1];

			cc->ingresarConsulta(ci_med);

	}else{
		cout << "No hay medicos disponibles para la fecha";
	}

}


void registroConsulta(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();

	//Si no existe un usuario logueado, se fuerza a loguearse
	if(!cu->usuarioLogueado())
		iniciarSesion();

	//Administrador* admin = ma->find(cu->getUsuarioLogueado()->getCI());

	//Si el usuario logueado no es del tipo requerido, se lanza una excepcion
	if(ma->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		throw std::invalid_argument("El usuario logueado no es un administrador");

	//ManejadorSocios* ms = ManejadorSocios::getInstance();

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
	while(tipo_consulta != "reserva" && tipo_consulta != "emergencia"){
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
			cout << "Reserva registrada correctamente! " << endl;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Argumento invalido: " << e.what() << endl;
		}
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
		throw std::invalid_argument("No hay usuario logueado");

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

/*
void altaRepresentacionEstandarizada(){

	cout << "Alta Representacion Estandarizada... \n";

	ManejadorRepresentaciones* mr = ManejadorRepresentaciones::getInstance();
	ControladorDiagnosticos* cr = ControladorDiagnosticos::getInstance();

	mr->agregarCategoria("A","Una categoria");
	mr->agregarCategoria("B","Otra categoria");
	mr->agregarCategoria("C","Ultima categoria");
	mr->agregarRepresentacion("A","A00","repa0");
	mr->agregarRepresentacion("A","A01","repa1");
	mr->agregarRepresentacion("A","A03","repa2");
	mr->agregarRepresentacion("B","B00","repb0");

	string letraCat = "S";
	string etiquetaCat;

	while(letraCat != "N") {

		cout << "Categorias: \n";

		map<string,DataRep*> categorias = mr->obtenerCategorias();
		for(map<string,DataRep*>::iterator cat = categorias.begin();cat!=categorias.end();++cat){
			cout << " " << cat->second->getCodigo() << " " << cat->second->getEtiqueta() << "\n";
		}

		bool listo = false;

		while (!listo && letraCat != "0") {

			cout << "Indique la letra de la categoria que desea seleccionar (0 para ingresar una nueva): ";
			cin >> letraCat;

			if (mr->existeCategoria(letraCat)) {
				cr->seleccionarCategoria(letraCat);
				listo = true;
			} else if (letraCat != "0") {
				cout << "Error: La categoria seleccionada no existe.\n";
			}
		}

		if (letraCat == "0") {
			cout << "Letra de la nueva categoria: ";
			cin >> letraCat;
			cout << "Etiqueta de la nueva categoria: ";
			cin >> etiquetaCat;

			if (mr->existeCategoria(letraCat)) {
				cout << "Error: La categoria ingresada ya existe.\n";
			} else {
				cr->ingresarCategoria(letraCat,etiquetaCat);
			}
		}

		cout << "Categoria seleccionada: " << cr->obtenerCategoriaSeleccionada() << "\n";

		set<DataRep*> reps = mr->obtenerRepresentacionesCat(cr->obtenerCategoriaSeleccionada());
		for(set<DataRep*>::iterator rep = reps.begin();rep!=reps.end();++rep){
			cout << " " << (*rep)->getCodigo() << " " << (*rep)->getEtiqueta() << "\n";
		}

		cout << "Desea ingresar una nueva representacion? (S/N): ";
		cin >> letraCat;

		string codigoRep;
		string etiquetaRep;
		listo = false;

		while (!listo && letraCat != "N") {
			cout << "Codigo de la nueva representacion: ";
			cin >> codigoRep;
			cout << "Etiqueta de la nueva representacion: ";
			cin >> etiquetaRep;
			if (mr->existeRepresentacion(cr->obtenerCategoriaSeleccionada(),codigoRep,etiquetaRep)) {
				cout << "Error: La representacion ingresada ya existe.\n";
				cout << "Desea ingresar otra? (S/N): ";
				cin >> letraCat;
			} else {
				cr->ingresarRepDiag(codigoRep,etiquetaRep);
				cout << "Representacion ingresada.\n";
				cout << "Desea ingresar otra? (S/N): ";
				cin >> letraCat;
			}
		}

		cout << "Desea seleccionar una nueva categoria? (S/N): ";
		cin >> letraCat;

	}

	cout << "Confirma los datos ingresados? (S/N): ";
	cin >> letraCat;
	if (letraCat == "S") {
		cr->confirmarRepEst();
		cout << "Datos ingresados con exito! \n";
	} else {
		cout << "Operacion cancelada! \n";
	}

}
*/
void listarRepresentacionesEstandarizadas(){

	cout << "Listar Representaciones Estandarizadas... \n";

	ManejadorRepresentaciones* mr = ManejadorRepresentaciones::getInstance();

	map<string,DataRep*> categorias = mr->obtenerCategorias();
	for(map<string,DataRep*>::iterator cat = categorias.begin();cat!=categorias.end();++cat){
		cout << " " << cat->second->getCodigo() << " " << cat->second->getEtiqueta() << "\n";

		set<DataRep*> reps = mr->obtenerRepresentacionesCat(cat->second->getCodigo());
		for(set<DataRep*>::iterator rep = reps.begin();rep!=reps.end();++rep){
			cout << "  " << (*rep)->getCodigo() << " " << (*rep)->getEtiqueta() << "\n";
		}

	}

}

void obtenerHistorialPaciente(){}

void notificarMedicos(){}

//MAIN PRINCIPAL

int main(){
	//ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	//ManejadorSocios* ms = ManejadorSocios::getInstance();
//	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();
//	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
//	ManejadorMedicamentos* MM = ManejadorMedicamentos::getInstance();


	reservaConsulta();
	//registroConsulta();
	/*	string opcion;
	altaRepresentacionEstandarizada();
	listarRepresentacionesEstandarizadas();
	do{
		cout << "HOLA CHICHE!" << endl
			 << "Que desea hacer?" << endl
			 << "-iniciarSesion" << endl
			 << "-EXIT" << endl;
		cin >> opcion;

		if(opcion == "iniciarSesion"){
			try{
				iniciarSesion();
				cerrarSesion();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

	}while(opcion != "EXIT");*/

	return 0;
}
