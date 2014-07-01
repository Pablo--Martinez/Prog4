#include <stdexcept>
#include <iostream>
#include "ControladorUsuarios.h"
#include "ControladorConsultas.h"
#include "ControladorDiagnosticos.h"
#include "ControladorTratamientos.h"
#include "ManejadorAdministradores.h"
#include "ManejadorMedicamentos.h"
#include "ManejadorRepresentaciones.h"
#include "ControladorTratamientos.h"


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
		cin >> hora;
	}

	//Se ingresan los minutos
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
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();
	if(ma->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		throw std::invalid_argument("Se requieren permisos de administrador");

	int dia, mes, anio, hora, min;
	RelojSistema* rs = RelojSistema::getInstance();

	cout << "Nueva fecha(dia mes anio hora minutos): ";
	cin >> dia >> mes >> anio >> hora >> min;
	rs->modificarFechaSistema(dia,mes,anio,hora,min);
	cu->recalcularInasistencias(rs->getFechaSistema());

	cout << "Hora modificada correctamente!" << endl << endl;
}

void verFechaSistema(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	//ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();
	//if(ma->find(cu->getUsuarioLogueado()->getCI()) == NULL)
	//	throw std::invalid_argument("Se requieren permisos de administrador");

	if(!cu->usuarioLogueado())
		throw std::invalid_argument("No hay usuario logueado");

	RelojSistema* rs = RelojSistema::getInstance();
	cout << "Fecha(dia/mes/anio hora:minutos): "
		 << rs->getFechaSistema().getDia() << "/"
		 << rs->getFechaSistema().getMes() << "/"
		 << rs->getFechaSistema().getAnio() << " "
		 << rs->getFechaSistema().getHora() << ":"
		 << rs->getFechaSistema().getMinutos() << "hs" << endl << endl;
}

void iniciarSesion(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	if(cu->usuarioLogueado())
		throw std::invalid_argument("Ya existe sesion activa");
  
	int ci;
	bool escorrecta;
	string pass, nombreMedicamento;

	cout << "Ingrese el Documento: ";cin >> ci;
	cout << "Ingrese la contraseña: ";cin >> pass;

	TSesion ts;
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
		cout << "Sesion iniciada correctamente!" << endl << endl;

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
		cout << "Sesion terminada correctamente" << endl;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "ERROR: " << e.what() << endl;
	}
}

void altaReactivacionUsuario(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();

	if(!cu->usuarioLogueado())
		throw std::invalid_argument("No hay usuario logueado");

	Administrador* admin = ma->find(cu->getUsuarioLogueado()->getCI());
	if(admin == NULL)
		throw std::invalid_argument("Se requieren permisos de administrador");

	cout << "Ingrese CI de Usuario a dar de Alta/Reactivar: ";
	int ci_usuario;
	cin >> ci_usuario;

	if (cu->ingresoCI(ci_usuario)){ //Si existe
		DataUsuario* du = cu->devolverDatosUsuario();
		cout << "El usuario ya existe en el sistema \n";
		cout << "\t-Nombre: " << du->getNombre() << "\n";
		cout << "\t-Apellido: " << du->getApellido() << "\n";

		if (du->getSexo() == M) {
			cout << "\t-Sexo: Masculino \n";
		}
		else{
			cout << "\t-Sexo: Femenino \n";
		}
		cout << "\t-Edad: " << du->getEdad() << "\n";
		cout << "\t-Roles: \n";

		if (du->esAdmin())
			cout << "\t\t-Administrador \n";
		if (du->esMedico())
			cout << "\t\t-Medico \n";
		if (du->esSocio())
			cout << "\t\t-Socio \n";

		if (du->getActivo()) {
			cout << "\t-Estado: activo \n" << endl;
		}
		else if(!du->getActivo() && !(du->getPass() == "")){
			string reactivar;
			cout << "\t-Estado: inactivo \n";
			cout << "¿Reactivar Usuario?(S/N)  \n";
			cin >> reactivar;
			if(reactivar == "S"){
				cu->reactivar();
				cout << "Usuario reactivado  \n" << endl;
			}
		}
		else if(du->getActivo()){
			cout << "\t-Estado: inactivo \n" << endl;
		}
	}
	else{
		string nombre_user;
		string apellido_user;
		string sexo_user;
		Sexo sex;
		Categoria rol1_usuario;
		string rol_usuario;
		string otro_rol;
		cout << "Usuario Inexistente - Se procedera a dar de alta \n";
		cout << "Nombre: "; cin >> nombre_user;
		cout << "Apellido: "; cin >> apellido_user;
		cout << "Sexo (M/F): "; cin >> sexo_user;
		if (sexo_user == "M")
			sex = M;
		else
			sex = F;
		cout << "Ingresar Fecha de Nacimiento: \n";

		Fecha f = ingresarFecha();

		ControladorUsuarios* cu = ControladorUsuarios::getInstance();
		cu->ingresarDatosUser(nombre_user, apellido_user, sex, f);

		cout << "Ingrese una categoria para el usuario (Administrador/Medico/Socio): ";
		do {
			cin >> rol_usuario;
			if (rol_usuario == "Administrador")
				rol1_usuario = Admin;
			else if (rol_usuario == "Medico")
				rol1_usuario = Med;
			else if (rol_usuario == "Socio")
				rol1_usuario = Soc;
			else{
				cout << "Categoria inexistente  \n";
				cout << "Ingrese nuevamente: ";
			}
		}
		while ((rol_usuario != "Administrador") and (rol_usuario != "Medico") and (rol_usuario != "Socio"));
		cu->ingresarCategoria(rol1_usuario);
		cout << "¿Desea ingresar otra categoria al Usuario?(S/N) "; cin >> otro_rol;
		if(otro_rol == "S"){
			string rol_usuario2;
			Categoria rol2_usuario;
			cout << "Ingrese otra categoria para el usuario (Administrador/Medico/Socio): ";
			do {
				cin >> rol_usuario2;
				if (rol_usuario == rol_usuario2){
					cout << "Ya se ah ingresado esta categoria \n";
					cout << "Ingrese nuevamente: ";
				}
				else if ((rol_usuario == "Administrador" and rol_usuario2 == "Medico")
						or (rol_usuario == "Medico" and rol_usuario2 == "Administrador")){
					cout << "Roles incompatibles \n";
					cout << "Ingrese nuevamente: ";
				}
				else if (rol_usuario2 == "Administrador")
					rol2_usuario = Admin;
				else if (rol_usuario2 == "Medico")
					rol2_usuario = Med;
				else if (rol_usuario2 == "Socio")
					rol2_usuario = Soc;
				else{
					cout << "Categoria inexistente";
					cout << "Ingrese nuevamente: ";
				}
			} while (((rol_usuario2 != "Administrador") and (rol_usuario2 != "Medico") and (rol_usuario2 != "Socio"))
					or (((rol_usuario == "Administrador" and rol_usuario2 == "Medico")
					or (rol_usuario == "Medico" and rol_usuario2 == "Administrador")))
					or (rol_usuario == rol_usuario2));
			cu->ingresarCategoria(rol2_usuario);
		}

		string Confirmar;
		cout << "¿Confirmar alta de Usuario? (S/N): ";
		cin >> Confirmar;
		if (Confirmar == "S"){
			cu->confirmarInscripcion();
			cout << "Usuario " << nombre_user << " dado de alta \n" << endl;
		}
		else{
			cu->cancelarInscripcion();
			cout << "Se ha cancelado el alta de usuario \n" << endl;
		}
	}
}

void reservaConsulta(){

	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	RelojSistema* rs = RelojSistema::getInstance();

	if(!cu->usuarioLogueado())
		iniciarSesion();

	if(ms->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		throw std::invalid_argument("Se requieren privilegios de socio");

	cout << "Ingresar fecha a reservar:" << endl;

	Fecha f = ingresarFecha();
	while(f < rs->getFechaSistema()){
		cout << "Fecha incorrecta, ingresar nuevamente: " << endl;
		f = ingresarFecha();
	}
	ControladorConsultas* cc = ControladorConsultas::getInstance();

	cc->ingresarFechaConsulta(f);
	cc->ingresarFechaReserva(rs->getFechaSistema());

	try{
		set<DataUsuario*> medicos_disponibles = cc->obtenerMedicos();
		if(!medicos_disponibles.empty()){
			cout << "Medicos disponibles: " << endl;
			for(set<DataUsuario*>::iterator it = medicos_disponibles.begin();it!=medicos_disponibles.end();++it){
				cout << "\t" << "- " << (*it)->getCI() << ": "<< (*it)->getNombre() << " " << (*it)->getApellido() << endl;
			}

			int seleccionado;
			cout << "Ingrese la ci del medico: ";cin >> seleccionado;
			while(mm->find(seleccionado) == NULL || seleccionado < 0){
				cout << "Seleccion incorrecta, ingrese nuevamente: ";
				cin >> seleccionado;
			}

			cc->ingresarConsulta(seleccionado);
			cout << "Consulta reservada satisfactoriamente" << endl << endl;

		}
		else{
			cout << "No hay medicos disponibles para la fecha" << endl;
		}
	}
	catch(const std::invalid_argument& e){
		std::cerr << "ERROR: " << e.what() << endl;
	}
}


void registroConsulta(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	ControladorConsultas* cc = ControladorConsultas::getInstance();

	//Si no existe un usuario logueado, se fuerza a loguearse
	if(!cu->usuarioLogueado())
		iniciarSesion();

	//Si el usuario logueado no es del tipo requerido, se lanza una excepcion
	if(ma->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		throw std::invalid_argument("Se requieren permisos de administrador");

	//Se procede a ingresar los datos del socio
	int ci_socio;
	cout << "Ingrese ci del socio: ";
	cin >> ci_socio;
	while(ms->find(ci_socio) == NULL || ci_socio <= 0){ //Si no es correcto el formato de la ci, se fuerza a ingresar nuevamente
		cout << "Cedula incorrecta, ingrese nuevamente: ";
		cin >> ci_socio;
	}
	cc->ingresarCITratante(ci_socio);

	//Se selecciona el tipo de consulta a registrar
	string tipo_consulta;
	cout << "Ingrese tipo de consulta(reserva/emergencia): ";
	cin >> tipo_consulta;
	while(tipo_consulta != "reserva" && tipo_consulta != "emergencia"){
		cout << "Tipo incorrecto, ingrese nuevamente: ";
		cin >> tipo_consulta;
	}

	RelojSistema* rs = RelojSistema::getInstance();
	cout << "Ingresar la fecha de la consulta: " << endl;
	Fecha fecha_consulta;

	if(tipo_consulta == "reserva"){
		int ci_doc;

		//Se ingresa la fecha de la consulta
		fecha_consulta = ingresarFecha();

		//Se procede a seleccionar el medico que va a tratar la consulta
		cout << "Ingrese ci del medico: ";
		cin >> ci_doc;
		while(mm->find(ci_doc) == NULL ||ci_doc <= 0){//Si el formato de la ci es incorrecto se fuerza
			cout << "Cedula incorrecta, ingrese nuevamente: ";
			cin >> ci_doc;
		}

		try{
			cc->registroReserva(ci_socio,ci_doc,fecha_consulta);
			cout << "Reserva registrada correctamente! " << endl;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "ERROR: " << e.what() << endl;
		}
	}
	else{
		int criterio, cantidad;
		string motivo;

		cout << "Criterio de seleccion de medico: " << endl <<
				"1) Medicos libres" << endl <<
				"2) Medicos del paciente" << endl;
		cout << "Criterio(1/2): ";cin >> criterio;
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

		if(!medicos_disponibles.empty()){ //El strategy dio resultados
			cout << "Medicos disponibles: " << endl;
			for(set<DataMedico*>::iterator it = medicos_disponibles.begin();it!=medicos_disponibles.end();++it){
				cout << "\t- " << (*it)->getUsuario()->getCI() << ": " << (*it)->getUsuario()->getNombre() << endl;
			}
		}

		else{// El strategy no dio resultados
			cout << "No hay medicos disponibles, se listaran todos: " << endl;
			for(map<int,Medico*>::iterator it = mm->getMedicos().begin();it!=mm->getMedicos().end();++it){
				cout << "\t- " << it->first << ": "<< it->second->getDataMedico()->getUsuario()->getNombre() << " "
					 << it->second->getDataMedico()->getUsuario()->getApellido() << endl;
			}

		}
		int seleccionado;
		cout << "Ingrese ci de medico seleccionado: ";cin >> seleccionado;
		while(seleccionado <= 0 || mm->find(seleccionado) == NULL){
			cout << "Seleccion incorrecta, ingrese nuevamente: ";
			cin >> seleccionado;
		}

		cout << "Motivo de la emergencia: ";
		cin >> motivo;

		try{
			fecha_consulta = rs->getFechaSistema();
			cc->registroEmergencia(ci_socio,seleccionado,motivo,fecha_consulta);
			cout << "Emergencia registrada correctamente" << endl << endl;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "ERROR: " << e.what() << endl;
		}
	}
}

void altaDiagnosticosConsulta(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();

	//Si no existe un usuario logueado, se fuerza a loguearse
	if(!cu->usuarioLogueado())
	iniciarSesion();
	Medico* medico = mm->find(cu->getUsuarioLogueado()->getCI());

	//Si el usuario logueado no es del tipo requerido, se lanza una excepcion
	if(medico == NULL)
		throw std::invalid_argument("Se requieren permisos de Medico");

	ControladorConsultas* cc = ControladorConsultas::getInstance();
	RelojSistema* rs = RelojSistema::getInstance();

	//Muestro todas las consultas del dia
	set<DataConsulta*> consultasDelDia = cc->consultasDelDia(rs->getFechaSistema());
	if(consultasDelDia.empty())
		throw std::invalid_argument("No hay consultas para el dia de hoy");

	set<int> listadoCedulas;

	cout << "Consultas del dia" << endl;
	for(set<DataConsulta*>::iterator it = consultasDelDia.begin();it!=consultasDelDia.end();++it){
		listadoCedulas.insert((*it)->getCI());
		cout << "\t-" << (*it)->getCI() << endl;
	}

	//El usuario elige la consulta
	int ciSeleccionada;
	cout << "Ingrese la cedula seleccionada del listado anterior: ";
	cin >> ciSeleccionada;
	while(listadoCedulas.count(ciSeleccionada) == 0){
		cout << "Seleccion incorrecta, ingrese nuevamente: ";
		cin >> ciSeleccionada;
	}

	Consulta* consulta = cc->getConsulta(ciSeleccionada,rs->getFechaSistema());

	ManejadorRepresentaciones* mr = ManejadorRepresentaciones::getInstance();
	string categoriaSeleccionada;
	string codigoSeleccionado;

	string agregarDiagnosticos = "S";

	while (agregarDiagnosticos == "S") {

		codigoSeleccionado = "C";

		while (codigoSeleccionado == "C") {

			map<string,DataRep*> categorias = mr->obtenerCategorias();
			for(map<string,DataRep*>::iterator cat = categorias.begin();cat!=categorias.end();++cat){
				cout << " " << cat->second->getCodigo() << " " << cat->second->getEtiqueta() << "\n";
			}
			cout << "Ingrese la categoria a seleccionar del listado anterior: ";
			cin >> categoriaSeleccionada;
			while(!mr->existeCategoria(categoriaSeleccionada)){
				cout << "Seleccion incorrecta, ingrese nuevamente: ";
				cin >> categoriaSeleccionada;
			}

			set<DataRep*> reps = mr->obtenerRepresentacionesCat(categoriaSeleccionada);
			for(set<DataRep*>::iterator rep = reps.begin();rep!=reps.end();++rep){
				cout << "  " << (*rep)->getCodigo() << " " << (*rep)->getEtiqueta() << "\n";
			}

			cout << "Ingrese el codigo de la representacion seleccionada (C para volver a categorias): ";
			cin >> codigoSeleccionado;
			while(codigoSeleccionado != "C" && !mr->existeRepresentacion(categoriaSeleccionada,codigoSeleccionado)){
				cout << "Seleccion incorrecta, ingrese nuevamente: ";
				cin >> codigoSeleccionado;
			}

		}

		DataRep* rep = mr->obtenerRepresentacion(categoriaSeleccionada,codigoSeleccionado);
		cout << "Seleccionado: " << rep->getCodigo() << " " << rep->getEtiqueta() << "\n";

		string descripcion;
		cout << "Ingrese una descripcion: ";
		cin >> descripcion;

		ControladorDiagnosticos* cd = ControladorDiagnosticos::getInstance();
		Diagnostico* diag = cd->altaDiagnostico(rep->getCodigo(), rep->getEtiqueta(), descripcion, consulta);
		consulta->agregarDiagnostico(diag);
		consulta->getSocioSolicitante()->notifyall(consulta->getMedico(),consulta->getFechaConsulta(),true);
		cout << "Diagnostico agregado.\n";

		string agregarTratamientos = "S";

		while (agregarTratamientos == "S") {
			string tipoTratamiento;
			cout << "Que tipo de tratamiento desea agregar? (F/Q): ";
			cin >> tipoTratamiento;
			while((tipoTratamiento != "F") && (tipoTratamiento != "Q")){
				cout << "Seleccion incorrecta, ingrese nuevamente: ";
				cin >> tipoTratamiento;
			}
			ControladorTratamientos* ct = ControladorTratamientos::getInstance();
			cout << "Ingrese una descripcion del tratamiento: ";
			string desc;
			cin >> desc;
			//getline(cin, desc);
			if(tipoTratamiento == "Q"){
				cout << "Ingrese la fecha de la operacion. \n";
				Fecha fechaOper = ingresarFecha();
				int cedulaMedico;
				cout << "Ingrese CI de medico a realizar el tratamiento: ";
				cin >> cedulaMedico;
				ct->agregarTratamientoQuirurjico(cedulaMedico,desc,fechaOper,diag);
			} else if (tipoTratamiento == "F") {
				Farmacologico* tfarm = new Farmacologico(desc);
				string medicamento, opcionMedicamento;
				cout << "Ingrese los medicamentos correspondientes al Tratamiento \n";	//(*it)->show();
				opcionMedicamento = "S";
				while(opcionMedicamento == "S") {

					//Farmacologico* tfarm = new Farmacologico();

					ManejadorMedicamentos* mmed = ManejadorMedicamentos::getInstance();
					mmed->show();

					cout << "Seleccione un medicamento: ";
					cin >> medicamento;
					tfarm->agregarMedicamento(mmed->find(medicamento));

					//diag->agregarTratamiento(tfarm);

					cout << "Desea agregar otro medicamento? (S/N): "; cin >> opcionMedicamento;
				}
				diag->agregarTratamiento(tfarm);
			}
			cout << "Desea agregar otro tratamiento? (S/N): "; cin >> agregarTratamientos;
		}
		cout << "Desea agregar otro diagnostico? (S/N): "; cin >> agregarDiagnosticos;
	}
	cout << "Diagnosticos agregados satisfactoriamente" << endl;
}

void altaMedicamento(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();

	if(!cu->usuarioLogueado())
		throw std::invalid_argument("No hay usuario logueado");

	Administrador* admin = ma->find(cu->getUsuarioLogueado()->getCI());
	if(admin == NULL)
		throw std::invalid_argument("Se requieren permisos de administrador");

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
	cout << "Medicamento ingresado correctamente!" << endl << endl;
}

void devolucionConsulta(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorSocios* ms = ManejadorSocios::getInstance();

	//Si no existe un usuario logueado, se fuerza a loguearse
	if(!cu->usuarioLogueado())
		iniciarSesion();
	Socio* socio = ms->find(cu->getUsuarioLogueado()->getCI());

	//Si el usuario logueado no es del tipo requerido, se lanza una excepcion
	if(socio == NULL)
		throw std::invalid_argument("Se requieren privilegios de socio");

	ControladorConsultas* cc = ControladorConsultas::getInstance();
	set<DataConsulta*> consultasActivas= cc->consultasActivasXUsuario();

		if (consultasActivas.empty()){
		cout << "El usuario logueado no tiene consultas activas \n" << endl;
	}
	else{
		cout << "Consultas activas" << endl;
		for(set<DataConsulta*>::iterator it = consultasActivas.begin();it!=consultasActivas.end();++it){
			//listadoConsultasActivas.insert((*it)->getFechaConsulta());
			(*it)->getFechaConsulta().show();
			cout << endl;
		}
		//El usuario elige la consulta
		Fecha fechaSeleccionada;

		cout << "Seleccione una fecha del listado anterior" << endl;
		fechaSeleccionada = ingresarFecha();

		bool bandera = false;
		while(!bandera){
			for(set<DataConsulta*>::iterator auxIt = consultasActivas.begin();auxIt!=consultasActivas.end();++auxIt){
				if (((*auxIt)->getFechaConsulta()) == fechaSeleccionada){
					bandera = true;
					break;
				}
			}
			if(!bandera){
				cout << "Seleccion incorrecta, ingrese nuevamente: \n";
				fechaSeleccionada = ingresarFecha();
			}

		}
		cc->devolverConsulta(fechaSeleccionada);
		cout << "Se ha eliminado la consulta \n" << endl;
	}
}

void usuariosDadosDeAlta(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();

	if(!cu->usuarioLogueado())
		throw std::invalid_argument("No hay usuario logueado");

	if(ma->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		throw std::invalid_argument("Se requieren privilegios de administrador");

	set<DataAltaReactivacion*> alta_reactivados = ma->find(cu->getUsuarioLogueado()->getCI())->obtenerUsuariosAltaReactivacion();

	if(alta_reactivados.empty())
		cout << "No reactivo/ingreso usuarios" << endl << endl;
	else{
		cout << "Usuarios dados de alta/reactivados: " << endl;
		for(set<DataAltaReactivacion*>::iterator it = alta_reactivados.begin();it!= alta_reactivados.end();++it){
			if((*it)->getTipoOperacion())
				cout << "\t-(ALTA  ";
			else
				cout << "\t-(REACTIVADO ";

			(*it)->getFecha().show();
			cout << ") " << (*it)->getUsuario()->getCI() << ": " << (*it)->getUsuario()->getNombre() << " "
				 << (*it)->getUsuario()->getApellido() << endl;
		}
	}
}

void altaRepresentacionEstandarizada(){
	ManejadorRepresentaciones* mr = ManejadorRepresentaciones::getInstance();
	ControladorDiagnosticos* cr = ControladorDiagnosticos::getInstance();
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();

	if(!cu->usuarioLogueado())
		throw std::invalid_argument("No hay usuario logueado");

	if(ma->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		throw std::invalid_argument("Se requieren privilegios de administrador");

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
				cout << "ERROR: La categoria seleccionada no existe.\n";
			}
		}

		if (letraCat == "0") {

			listo = false;

			while (!listo) {
				cout << "Letra de la nueva categoria: ";
				cin >> letraCat;
				cout << "Etiqueta de la nueva categoria: ";
				cin >> etiquetaCat;

				if (mr->existeCategoria(letraCat)) {
					cout << "ERROR: La categoria ingresada ya existe.\n";
				} else {
					cr->ingresarCategoria(letraCat,etiquetaCat);
					listo = true;
				}
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
			if (mr->existeRepresentacion(cr->obtenerCategoriaSeleccionada(),cr->obtenerCategoriaSeleccionada()+codigoRep,etiquetaRep)) {
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
		cr->clearRepEst();
		cout << "Operacion cancelada! \n";
	}

}

void listarRepresentacionesEstandarizadas(){

	cout << "Listar Representaciones Estandarizadas... \n";

	ManejadorRepresentaciones* mr = ManejadorRepresentaciones::getInstance();
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();

	if(!cu->usuarioLogueado())
		throw std::invalid_argument("No hay usuario logueado");

	if(ma->find(cu->getUsuarioLogueado()->getCI()) == NULL && mm->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		throw std::invalid_argument("Se requieren privilegios de administrador o medico");

	map<string,DataRep*> categorias = mr->obtenerCategorias();
	for(map<string,DataRep*>::iterator cat = categorias.begin();cat!=categorias.end();++cat){
		cout << " " << cat->second->getCodigo() << " " << cat->second->getEtiqueta() << "\n";

		set<DataRep*> reps = mr->obtenerRepresentacionesCat(cat->second->getCodigo());
		for(set<DataRep*>::iterator rep = reps.begin();rep!=reps.end();++rep){
			cout << "  " << (*rep)->getCodigo() << " " << (*rep)->getEtiqueta() << "\n";
		}

	}

}

void obtenerHistorialPaciente(){
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();

	if(!cu->usuarioLogueado())
		throw std::invalid_argument("No hay usuario logueado");

	if(mm->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		throw std::invalid_argument("Se requieren privilegios de medico");

	int ci_soc;
	cout << "Ingrese la cedula del socio: "; cin >> ci_soc;
	while(ms->find(ci_soc) == NULL){
		cout << "Cedula incorrecta, ingrese nuevamente: "; cin >> ci_soc;
	}

	DataHistorial* historial = new DataHistorial(ms->find(ci_soc)->getUsuario()->getDataUsuario());
	map<int,Medico*> medicos = mm->getMedicos();
	for(map<int,Medico*>::iterator it = medicos.begin();it!=medicos.end();++it){
		if(mm->find(it->first)->obtenerHistorial(ci_soc) != NULL)
			historial->agregarMedico(mm->find(it->first)->obtenerHistorial(ci_soc));
	}
	historial->show();
}

void suscribirseAPaciente(){
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();

	if(!cu->usuarioLogueado())
		throw std::invalid_argument("No hay usuario logueado");

	if(mm->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		throw std::invalid_argument("Se requieren privilegios de medico");

	cout << "Usuarios del sistema: " << endl;
	for(map<int,Socio*>::iterator it = ms->getSocios().begin();it != ms->getSocios().end();++it){
		DataUsuario* du = it->second->getUsuario()->getDataUsuario();
		cout << " - " << du->getCI() << ": " << du->getNombre() << " " << du->getApellido() << endl;
	}
	int ci_soc;
	cout << "Ingrese la CI: "; cin >> ci_soc;
	while(ms->find(ci_soc) == NULL){
		cout << "Cedula incorrecta, ingrese nuevamente: "; cin >> ci_soc;
	}

	int ci_med = cu->getUsuarioLogueado()->getCI();
	Socio* s = ms->find(ci_soc);
	Medico* m = mm->find(ci_med);
	m->seguir(s);
	cout << "Se ha realizado la suscripcion satisfactoriamente" << endl << endl;


}

void verNotificaciones(){
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();

	if(!cu->usuarioLogueado())
		throw std::invalid_argument("No hay usuario logueado");

	if(mm->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		throw std::invalid_argument("Se requieren privilegios de medico");



	map<int,set<Notificacion*> > notificaciones = mm->find(cu->getUsuarioLogueado()->getCI())->getNotificaciones();

	if(notificaciones.empty())
		cout << "No hay notificaciones" << endl << endl;
	else{
		cout << "Notificaciones recibidas: " << endl;
		for(map<int,set<Notificacion*> >::iterator it = notificaciones.begin();	it!=notificaciones.end();++it){
			DataUsuario du;
			du = *(ms->find(it->first)->getUsuario()->getDataUsuario());
			cout << "\t-" << it->first << ": " << du.getNombre() << " " << du.getApellido() << endl;
		}

		int ci_soc;
		cout << "Ingrese la CI: "; cin >> ci_soc;
		while(ms->find(ci_soc) == NULL){
			cout << "Cedula incorrecta, ingrese nuevamente: "; cin >> ci_soc;
		}

		int ci_med = cu->getUsuarioLogueado()->getCI();
		Medico* m = mm->find(ci_med);
		m->showNotificaciones(ci_soc);
	}
}

void verMaximoInasistencias(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();

	if(!cu->usuarioLogueado())
		throw std::invalid_argument("No hay usuario logueado");

	if(ma->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		throw std::invalid_argument("Se requieren privilegios de administrador");

	cout << "Cantidad maxima de inasistencias: " << cu->getMaximoInasistencias() << endl;
}

void setearMaximoInasistencias(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();

	if(!cu->usuarioLogueado())
		throw std::invalid_argument("No hay usuario logueado");

	if(ma->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		throw std::invalid_argument("Se requieren privilegios de administrador");

	int inasistencias;
	cout << "Cantidad maxima de inasistencas: ";cin >> inasistencias;
	cu->setMaximoInasistencias(inasistencias);
}

void cantidadConsultasPorCategoria(){

}

void estadoDeSituacion(){
  
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorSocios* ms = ManejadorSocios::getInstance();

	if(!cu->usuarioLogueado())
		throw std::invalid_argument("No hay usuario logueado");

	Socio* soc = ms->find(cu->getUsuarioLogueado()->getCI());
	if(soc == NULL)
		throw std::invalid_argument("Se requieren permisos de socio");

	DataEstado* estado = soc->obtenerEstadoReservas();
	estado->show();
}

void eliminarMemoria(){
	delete ControladorUsuarios::getInstance();
	delete ControladorConsultas::getInstance();
	delete ControladorDiagnosticos::getInstance();
	delete ControladorTratamientos::getInstance();
	delete ManejadorAdministradores::getInstance();
	delete ManejadorMedicamentos::getInstance();
	delete ManejadorMedicos::getInstance();
	delete ManejadorSocios::getInstance();
	delete ManejadorRepresentaciones::getInstance();
	delete RelojSistema::getInstance();
}

void agregarDatosDePrueba() {

	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ControladorConsultas* cc = ControladorConsultas::getInstance();
	ControladorDiagnosticos* cd = ControladorDiagnosticos::getInstance();
	ControladorTratamientos* ct = ControladorTratamientos::getInstance();
	ManejadorRepresentaciones* mr = ManejadorRepresentaciones::getInstance();
	ManejadorMedicamentos* mmed = ManejadorMedicamentos::getInstance();
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	ManejadorSocios* ms = ManejadorSocios::getInstance();

	if(cu->usuarioLogueado())
		throw std::invalid_argument("Debes cerrar sesion antes de ejecutar este comando");

	// INICIAR SESION DEL ADMINISTRADOR

	cu->iniciarSesion(34567645);
	cu->asignarSesion();

	// USUARIOS

	cu->ingresoCI(34562345);
	cu->ingresarDatosUser("Tifany", "McKensey", F, Fecha(1,1,1990));
	cu->ingresarCategoria(Soc);
	cu->confirmarInscripcion();

	cu->ingresoCI(12345435);
	cu->ingresarDatosUser("Diego", "Perez", M, Fecha(3,3,1980));
	cu->ingresarCategoria(Soc);
	cu->confirmarInscripcion();

	cu->ingresoCI(65436667);
	cu->ingresarDatosUser("Juan", "Montoya", M, Fecha(7,4,1970));
	cu->ingresarCategoria(Soc);
	cu->ingresarCategoria(Med);
	cu->confirmarInscripcion();

	cu->ingresoCI(43521343);
	cu->ingresarDatosUser("Debora", "Corral", F, Fecha(13,7,1993));
	cu->ingresarCategoria(Med);
	cu->confirmarInscripcion();

	cu->ingresoCI(98056743);
	cu->ingresarDatosUser("Ana", "Lopez", F, Fecha(24,9,1981));
	cu->ingresarCategoria(Med);
	cu->confirmarInscripcion();

	cu->cerrarSesion();

	// RESERVAS COMUNES

	cu->iniciarSesion(34562345);
	cu->asignarSesion();
	cc->ingresarFechaConsulta(Fecha(23,6,2014));
	cc->ingresarFechaReserva(Fecha(21,6,2014));
	cc->ingresarConsulta(65436667);

	cc->ingresarFechaConsulta(Fecha(22,6,2014));
	cc->ingresarFechaReserva(Fecha(22,5,2014));
	cc->ingresarConsulta(43521343);

	cu->cerrarSesion();

	cu->iniciarSesion(65436667);
	cu->asignarSesion();
	cc->ingresarFechaConsulta(Fecha(16,3,2014));
	cc->ingresarFechaReserva(Fecha(15,3,2014));
	cc->ingresarConsulta(43521343);

	cu->cerrarSesion();

	cu->iniciarSesion(12345435);
	cu->asignarSesion();
	cc->ingresarFechaConsulta(Fecha(1,3,2014));
	cc->ingresarFechaReserva(Fecha(28,2,2014));
	cc->ingresarConsulta(98056743);

	cu->cerrarSesion();

	// RESERVAS DE EMERGENCIA

	cu->iniciarSesion(34567645);
	cu->asignarSesion();
	//cc->registroEmergencia(34562345,65436667,"Fiebre alta",Fecha(23,5,2014));
	cc->registroEmergencia(34562345,98056743,"Fiebre alta",Fecha(23,5,2014));
	cc->registroEmergencia(65436667,43521343,"Asma",Fecha(24,5,2014));
	cc->registroEmergencia(65436667,98056743,"Mareos",Fecha(3,3,2014));

	// REPRESENTACIONES ESTANDARIZADAS

	mr->agregarCategoria("A","Afecciones pulmonares");
	mr->agregarCategoria("B","Aparato Digestivo");
	mr->agregarRepresentacion("A","A01","Asma");
	mr->agregarRepresentacion("A","A02","Congestion");
	mr->agregarRepresentacion("B","B01","Nauseas");

	// MEDICAMENTOS

	mmed->existeMedicamento("M1");
	mmed->ingresarMedicamento();
	mmed->existeMedicamento("M2");
	mmed->ingresarMedicamento();
	mmed->existeMedicamento("M3");
	mmed->ingresarMedicamento();

	// SUSCRIPCIONES

	Socio* s;
	Medico* m;

	s = ms->find(34562345);
	m = mm->find(65436667);
	m->seguir(s);

	s = ms->find(65436667);
	m = mm->find(43521343);
	m->seguir(s);

	// DIAGNOSTICOS DE CONSULTAS

	DataRep* rep = mr->obtenerRepresentacion("A","A02");
	Consulta* cons = cc->getConsulta(34562345,Fecha(23,6,2014));
	Diagnostico* D1 = cd->altaDiagnostico(rep->getCodigo(), rep->getEtiqueta(),"Desc 1",cons);
	cons->getSocioSolicitante()->notifyall(cons->getMedico(),Fecha(23,6,2014),true);

	rep = mr->obtenerRepresentacion("B","B01");
	Diagnostico* D2 = cd->altaDiagnostico(rep->getCodigo(),rep->getEtiqueta(),"Desc 2",cons);
	cons->getSocioSolicitante()->notifyall(cons->getMedico(),Fecha(23,6,2014),true);

	rep = mr->obtenerRepresentacion("A","A02");
	cons = cc->getConsulta(65436667,Fecha(16,3,2014));
	Diagnostico* D3 = cd->altaDiagnostico(rep->getCodigo(),rep->getEtiqueta(),"Desc 3",cons);
	cons->getSocioSolicitante()->notifyall(cons->getMedico(),Fecha(16,3,2014),true);

	rep = mr->obtenerRepresentacion("B","B01");
	cons = cc->getConsulta(34562345,Fecha(23,05,2014));
	Diagnostico* D4 = cd->altaDiagnostico(rep->getCodigo(),rep->getEtiqueta(),"Desc 4",cons);
	cons->getSocioSolicitante()->notifyall(cons->getMedico(),Fecha(23,5,2014),true);

	rep = mr->obtenerRepresentacion("A","A01");
	cons = cc->getConsulta(65436667,Fecha(24,05,2014));
	Diagnostico* D5 = cd->altaDiagnostico(rep->getCodigo(),rep->getEtiqueta(),"Desc 5",cons);
	cons->getSocioSolicitante()->notifyall(cons->getMedico(),Fecha(24,5,2014),true);

	rep = mr->obtenerRepresentacion("A","A02");
	Diagnostico* D6 = cd->altaDiagnostico(rep->getCodigo(),rep->getEtiqueta(),"Desc 6",cons);
	cons->getSocioSolicitante()->notifyall(cons->getMedico(),Fecha(23,6,2014),true);


	// TRATAMIENTOS FARMACOLOGICOS

	Farmacologico* tfarm;

	tfarm = new Farmacologico("Desc 1");
	tfarm->agregarMedicamento(mmed->find("M1"));
	D1->agregarTratamiento(tfarm);

	tfarm = new Farmacologico("Desc 2");
	tfarm->agregarMedicamento(mmed->find("M2"));
	D1->agregarTratamiento(tfarm);

	tfarm = new Farmacologico("Desc 3");
	tfarm->agregarMedicamento(mmed->find("M3"));
	D1->agregarTratamiento(tfarm);

	tfarm = new Farmacologico("Desc 4");
	tfarm->agregarMedicamento(mmed->find("M1"));
	D4->agregarTratamiento(tfarm);

	tfarm = new Farmacologico("Desc 5");
	tfarm->agregarMedicamento(mmed->find("M2"));
	D5->agregarTratamiento(tfarm);

	tfarm = new Farmacologico("Desc 6");
	tfarm->agregarMedicamento(mmed->find("M3"));
	D6->agregarTratamiento(tfarm);

	// TRATAMIENTOS QUIRURGICOS

	ct->agregarTratamientoQuirurjico(65436667,"Desc 11",Fecha(25,7,2014),D2);
	ct->agregarTratamientoQuirurjico(43521343,"Desc 22",Fecha(01,02,2014),D3);


	// CERRAR LA SESION DEL ADMINISTRADOR
	cu->cerrarSesion();
}

//MAIN PRINCIPAL

int main(){

	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	string opcion;
	bool vermenu = true;

	cout << "BIENVENIDO" << endl;
	while(true){
		if(!cu->usuarioLogueado()){
			cout << "A- iniciarSesion" << endl
				 << "B- agregarDatosDePrueba" << endl
				 << "C- salir" << endl;

		}
		else{
			if (vermenu) {
			cout << "1- altaReactivarUsuario" << endl
			     << "2- dadosDeAltaReactivados" << endl
				 << "3- altaMedicamento" << endl
				 << "4- altaRepresentacionEstandarizada" << endl
				 << "5- listarRepresentacionesEstandarizadas" << endl
				 << "6- registrarConsulta" << endl
				 << "7- cantidadConsultasPorCategoria" << endl
				 << "8- altaDiagnosticosDeConsulta" << endl
				 << "9- historialPaciente" << endl
				 << "10- reservarConsulta" << endl
				 << "11- devolverReserva" << endl
				 << "12- estadoDeSituacion" << endl
				 << "13- suscribirseAPaciente" << endl
				 << "14- verNotificaciones" << endl
				 << "15- verHora" << endl
				 << "16- modificarHora" << endl
				 << "17- verMaximoInasistencias" << endl
				 << "18- setearMaximoInasistencias" << endl
				 << "19- cerrarSesion" << endl
				 << "20- salir" << endl
				 << "? - menu" << endl << endl;
				vermenu = false;
			}
		}

		cout << ">> "; cin >> opcion;

		if(opcion == "iniciarSesion" || opcion == "A"){
			try{
				iniciarSesion();
			}
			catch (const std::invalid_argument& e){
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "altaReactivarUsuario" || opcion == "1"){
			try{
				altaReactivacionUsuario();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "dadosDeAltaReactivados" || opcion == "2"){
			try{
				usuariosDadosDeAlta();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "altaRepresentacionEstandarizada" || opcion == "4"){
			try{
				altaRepresentacionEstandarizada();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "listarRepresentacionesEstandarizadas" || opcion == "5"){
			try{
				listarRepresentacionesEstandarizadas();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "registrarConsulta" || opcion == "6"){
			try{
				registroConsulta();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "cantidadConsultasPorCategoria" || opcion == "7"){
			try{
				cantidadConsultasPorCategoria();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "altaDiagnosticosDeConsulta" || opcion == "8"){
			try{
				altaDiagnosticosConsulta();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "historialPaciente" || opcion == "9"){
			try{
				obtenerHistorialPaciente();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "reservarConsulta" || opcion == "10"){
			try{
				reservaConsulta();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "devolverReserva" || opcion == "11"){
			try{
				devolucionConsulta();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "estadoDeSituacion" || opcion == "12"){
			try{
				estadoDeSituacion();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "suscribirseAPaciente" || opcion == "13"){
			try{
				suscribirseAPaciente();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "verNotificaciones" || opcion == "14"){
			try{
				verNotificaciones();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "altaMedicamento" || opcion == "3"){
			try{
				altaMedicamento();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "verMaximoInasistencias" || opcion == "17"){
			try{
				verMaximoInasistencias();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "setearMaximoInasistencias" || opcion == "18"){
			try{
				setearMaximoInasistencias();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "verHora" || opcion == "15"){
			try{
				verFechaSistema();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "modificarHora" || opcion == "16"){
			try{
				modificarFechaSistema();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "agregarDatosDePrueba" || opcion == "B"){
			try{
				agregarDatosDePrueba();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "cerrarSesion" || opcion == "19"){
			try{
				cerrarSesion();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "salir" || opcion == "20" || opcion == "C"){
			if(cu->usuarioLogueado()){
				cerrarSesion();
			}
			break;
		}

		else if(opcion == "?"){
			vermenu = true;
		}

		else{
			cout << "Opcion incorrecta" << endl;
		}

	}
	eliminarMemoria();
	return 0;
}
