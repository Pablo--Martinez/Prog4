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
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();
	if(ma->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		std::invalid_argument("Se requieren permisos de administrador");

	int dia, mes, anio, hora, min;
	RelojSistema* rs = RelojSistema::getInstance();

	cout << "Nueva fecha(dia/mes/anio hora:minutos): ";
	cin >> dia >> mes >> anio >> hora >> min;
	rs->modificarFechaSistema(dia,mes,anio,hora,min);
	cu->recalcularInasistencias(rs->getFechaSistema());

	cout << "Hora modificada correctamente!" << endl << endl;
}

void verFechaSistema(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();
	if(ma->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		std::invalid_argument("Se requieren permisos de administrador");

	RelojSistema* rs = RelojSistema::getInstance();
	cout << "Fecha(dia/mes/anio hora:minutos): "
		 << rs->getFechaSistema().getDia() << "/"
		 << rs->getFechaSistema().getMes() << "/"
		 << rs->getFechaSistema().getAnio() << " "
		 << rs->getFechaSistema().getHora() << ":"
		 << rs->getFechaSistema().getMinutos() << "hs" << endl << endl;
}

void iniciarSesion(){
  
	int ci;
	bool escorrecta;
	string pass, nombreMedicamento;

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
		throw std::invalid_argument("UsuarioRolIncorrecto");

	cout << "Ingrese CI de Usuario a dar de Alta/Reactivar: " << endl;
	int ci_usuario;
	cin >> ci_usuario;

	if (cu->ingresoCI(ci_usuario)){ //Si existe
		DataUsuario* du = cu->devolverDatosUsuario();
		cout << "El usuario ya existe en el sistema \n";
		cout << "Nombre: " << du->getNombre() << "\n";
		cout << "Apellido: " << du->getApellido() << "\n";

		if (du->getSexo() == M) {
			cout << "Sexo: Masculino \n";
		}
		else{
			cout << "Sexo: Femenino \n";
		}
		cout << "Edad: " << du->getEdad() << "\n";
		cout << "Roles: \n";
		for(set<Rol*>::iterator r = du->getRoles().begin();r != du->getRoles().end();++r) {
				tipoRol tipoRol = (*r)->getTipoRol();
				if (tipoRol == administrador)
					cout << "	Administrador \n";
				else if (tipoRol == medico)
					cout << "	Medico \n";
				else
					cout << "	Socio \n";
		}

		if (du->getActivo()) {
			cout << "El estado del Usuario es Activo \n" << endl;
		}
		else{
			string reactivar;
			cout << "El estado del Usuario es Inactivo \n";
			cout << "¿Reactivar Usuario? S/N  \n";
			cin >> reactivar;
			if(reactivar == "S"){
				cu->reactivar();
				cout << "Usuario reactivado  \n" << endl;
			}
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
		cout << "Ingresar Fecha de Nacimiento: \n"; //Fecha f = ingresarFecha();

		int dia, mes, anio;
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
			cout << "Mes incorrect, ingrese nuevamente: ";
			cin >> mes;
		}

		//Se ingresa el anio
		cout << "Anio: ";
		cin >> anio;
		while(anio<= 0){
			cout << "Anio incorrecto, ingrese nuevamente: ";
			cin >> anio;
		}

		Fecha f = Fecha(dia,mes,anio);



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
		cout << "¿Desea ingresar otra categoria al Usuario? (S/N)"; cin >> otro_rol;
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
		cout << "¿Confirmar alta de Usuario? S/N \n";
		cin >> Confirmar;
		if (Confirmar == "S"){
			cu->confirmarInscripcion();
			cout << "Usuario " << nombre_user << " dado de alta \n" << endl;
		}
		else{
			cu->cancelarInscripcion();
			cout << "Se ah cancelado el alta de usuario \n" << endl;
		}
	}
}

void reservaConsulta(){

	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();

	if(!cu->usuarioLogueado())
		iniciarSesion();

	cout << "Ingresar fecha a reservar:" << endl;

	Fecha f = ingresarFecha();
	ControladorConsultas* cc = ControladorConsultas::getInstance();

	cc->ingresarFechaConsulta(f);

	try{
		set<DataUsuario*> medicos_disponibles = cc->obtenerMedicos();
		//int i=0; //disponibles[medicos_disponibles.size()];
		if(!medicos_disponibles.empty()){
			cout << "Medicos disponibles: " << endl;
			for(set<DataUsuario*>::iterator it = medicos_disponibles.begin();it!=medicos_disponibles.end();++it){
				cout << "\t" << "- " << (*it)->getCI() << ": "<< (*it)->getNombre() << " " << (*it)->getApellido() << endl;
				//disponibles[i] = (*it)->getCI();
				//i++;
			}

			int seleccionado;
			cout << "Ingrese la ci del medico: ";cin >> seleccionado;
			while(mm->find(seleccionado) == NULL || seleccionado < 0){
				cout << "Seleccion incorrecta, ingrese nuevamente: ";
				cin >> seleccionado;
			}

			cc->ingresarConsulta(seleccionado);

		}
		else{
			cout << "No hay medicos disponibles para la fecha";
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
	while(ci_socio <= 0 || ms->find(ci_socio) == NULL){ //Si no es correcto el formato de la ci, se fuerza a ingresar nuevamente
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
	Fecha fecha_consulta;

	//Se ingresa la fecha de la consulta
	fecha_consulta = ingresarFecha();

	if(tipo_consulta == "reserva"){
		int ci_doc;

		//Se procede a seleccionar el medico que va a tratar la consulta
		cout << "Ingrese ci del medico: ";
		cin >> ci_doc;
		while(ci_doc <= 0 || mm->find(ci_doc) == NULL){//Si el formato de la ci es incorrecto se fuerza
			cout << "Cedula incorrecta, ingrese nuevamente: ";
			cin >> ci_doc;
		}

		try{
			cc->registroReserva(ci_socio,ci_doc,rs->getFechaSistema(),fecha_consulta);
			cout << "Reserva registrada correctamente! " << endl;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "ERROR: " << e.what() << endl;
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
		//ManejadorMedicos* mm = ManejadorMedicos::getInstance();
		//int i=0, disponibles[mm->getMedicos().size()];

		if(!medicos_disponibles.empty()){ //El strategy dio resultados
			cout << "Medicos disponibles: " << endl;
			for(set<DataMedico*>::iterator it = medicos_disponibles.begin();it!=medicos_disponibles.end();++it){
				cout << "\t- " << (*it)->getUsuario()->getCI() << ": " << (*it)->getUsuario()->getNombre() << endl;
				//disponibles[i] = (*it)->getUsuario()->getCI();
				//i++;
			}
		}

		else{// El strategy no dio resultados
			cout << "No hay medicos disponibles, se listaran todos: " << endl;
			for(map<int,Medico*>::iterator it = mm->getMedicos().begin();it!=mm->getMedicos().end();++it){
				cout << "\t- " << it->first << ": "<< it->second->getDataMedico()->getUsuario()->getNombre() << endl;
				//disponibles[i] = it->first;
				//i++;
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
			cc->registroEmergencia(ci_socio,seleccionado,motivo,fecha_consulta);
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "ERROR: " << e.what() << endl;
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
			throw std::invalid_argument("UsuarioRolIncorrecto");

		ControladorConsultas* cc = ControladorConsultas::getInstance();
		RelojSistema* rs = RelojSistema::getInstance();
		set<DataConsulta*> consultasActivas= cc->consultasActivasXUsuario(rs->getFechaSistema(), cu->getUsuarioLogueado()->getCI());
		//set<Fecha> listadoConsultasActivas;

		cout << "Consultas activas" << endl;
		if (consultasActivas.empty()){
			cout << "El usuario logueado no tiene consultas activas \n" << endl;
		}
		else{
			for(set<DataConsulta*>::iterator it = consultasActivas.begin();it!=consultasActivas.end();++it){
				//listadoConsultasActivas.insert((*it)->getFechaConsulta());
				(*it)->getFechaConsulta().show();
			}
			//El usuario elige la consulta
			int anioSeleccionado;
			int mesSeleccionado;
			int diaSeleccionado;
			int horaSeleccionada;
			int minutosSeleccionados;
			Fecha fechaSeleccionada;

			cout << "Seleccione una fecha del listado anterior" << endl;
			cout << "Ingrese anio: ";
			cin >> anioSeleccionado;
			cout << "Ingrese mes: ";
			cin >> mesSeleccionado;
			cout << "Ingrese dia: ";
			cin >> diaSeleccionado;
			cout << "Ingrese hora: ";
			cin >> horaSeleccionada;
			cout << "Ingrese minutos: ";
			cin >> minutosSeleccionados;

			fechaSeleccionada.setAnio(anioSeleccionado);
			fechaSeleccionada.setMes(mesSeleccionado);
			fechaSeleccionada.setDia(diaSeleccionado);
			fechaSeleccionada.setHora(horaSeleccionada);
			fechaSeleccionada.setMinutos(minutosSeleccionados);

			bool bandera = false;
			while(bandera = false){
				for(set<DataConsulta*>::iterator auxIt = consultasActivas.begin();auxIt!=consultasActivas.end();++auxIt){
					if (((*auxIt)->getFechaConsulta()) == fechaSeleccionada){
						bandera = true;
					}
				}
				cout << "Seleccion incorrecta, ingrese nuevamente: \n";
				cout << "Ingrese anio: ";
				cin >> anioSeleccionado;
				cout << "Ingrese mes: ";
				cin >> mesSeleccionado;
				cout << "Ingrese dia: ";
				cin >> diaSeleccionado;
				cout << "Ingrese hora: ";
				cin >> horaSeleccionada;
				cout << "Ingrese minutos: ";
				cin >> minutosSeleccionados;

				fechaSeleccionada.setAnio(anioSeleccionado);
				fechaSeleccionada.setMes(mesSeleccionado);
				fechaSeleccionada.setDia(diaSeleccionado);
				fechaSeleccionada.setHora(horaSeleccionada);
				fechaSeleccionada.setMinutos(minutosSeleccionados);
			}

			cc->devolverConsulta(fechaSeleccionada);
			cout << "Se ah eliminado la consulta \n" << endl;
		}
}

void usuariosDadosDeAlta(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();

	if(!cu->usuarioLogueado())
		throw std::invalid_argument("No hay usuario logueado");

	if(ma->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		throw std::invalid_argument("Se deben tener privilegios de administrador");

	cout << "Usuarios dados de alta/reactivados: " << endl;
	for(set<DataAltaReactivacion*>::iterator it = ma->find(cu->getUsuarioLogueado()->getCI())->obtenerUsuariosAltaReactivacion().begin();
			it!=ma->find(cu->getUsuarioLogueado()->getCI())->obtenerUsuariosAltaReactivacion().end();++it){

		if((*it)->getTipoOperacion())
			cout << "\t-(ALTA) ";
		else
			cout << "\t-(REACTIVADO) ";

		(*it)->getFecha().show();
		cout << (*it)->getUsuario()->getCI() << ": " << (*it)->getUsuario()->getNombre() << " "
			 << (*it)->getUsuario()->getApellido() << endl;
	}
}

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
				cout << "ERROR: La categoria seleccionada no existe.\n";
			}
		}

		listo = false;

		while (!listo || letraCat == "0") {
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

void suscribirseAPaciente(){
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();

	cout << "Usuarios del sistema: " << endl;
	for(map<int,Socio*>::iterator it = ms->getSocios().begin();it != ms->getSocios().end();++it){
		DataUsuario du;
		du = *(it->second->getUsuario()->getDataUsuario());
		cout << "\t- " << du.getCI() << ": " << du.getNombre() << " " << du.getApellido() << endl;
	}
	int ci_soc;
	cout << "Ingrese la CI: "; cin >> ci_soc;
	while(ms->find(ci_soc) == NULL){
		cout << "Cedula incorrecta, ingrese nuevamente: "; cin >> ci_soc;
	}

	mm->find(cu->getUsuarioLogueado()->getCI())->seguir(ms->find(ci_soc));

}

void verNotificaciones(){
	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();

	cout << "Socios a los que esta subscirpto: " << endl;
	for(map<int,set<Notificacion*> >::iterator it = mm->find(cu->getUsuarioLogueado()->getCI())->getNotificaciones().begin();
			it!=mm->find(cu->getUsuarioLogueado()->getCI())->getNotificaciones().end();++it){
		DataUsuario du;
		du = *(ms->find(it->first)->getUsuario()->getDataUsuario());
		cout << "\t-" << it->first << ": " << du.getNombre() << " " << du.getApellido() << endl;
	}

	int ci_soc;
	cout << "Ingrese la CI: "; cin >> ci_soc;
	while(ms->find(ci_soc) == NULL){
		cout << "Cedula incorrecta, ingrese nuevamente: "; cin >> ci_soc;
	}

	mm->find(cu->getUsuarioLogueado()->getCI())->showNotificaciones(ci_soc);
}

void verMaximoInasistencias(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();

	if(!cu->usuarioLogueado())
		throw std::invalid_argument("No hay usuario logueado");

	if(ma->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		throw std::invalid_argument("Se deben tener privilegios de administrador");

	cout << "Cantidad maxima de inasistencias: " << cu->getMaximoInasistencias() << endl;
}

void setearMaximoInasistencias(){
	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();

	if(!cu->usuarioLogueado())
		throw std::invalid_argument("No hay usuario logueado");

	if(ma->find(cu->getUsuarioLogueado()->getCI()) == NULL)
		throw std::invalid_argument("Se deben tener privilegios de administrador");

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
		throw std::invalid_argument("UsuarioRolIncorrecto");

	DataEstado* estado = soc->obtenerEstadoReservas();
	estado->show();
}

//MAIN PRINCIPAL

int main(){

	ControladorUsuarios* cu = ControladorUsuarios::getInstance();
	string opcion;

	cout << "BIENBENIDO" << endl;
	while(true){
		if(!cu->usuarioLogueado()){
			cout << "- iniciarSesion" << endl
				 << "- salir" << endl;

		}
		else{
			cout << "1- altaReactivarUsuario" << endl
			     << "2- dadosDeAltaReactivados" << endl
				 << "3- altaMedicamento" << endl
				 << "4- altaRepresentacionEstandarizada" << endl
				 << "5- listarRepresentacionesEstandarizadas" << endl
				 << "6- registrarConsulta" << endl
				 << "7- cantidadConsultasPorCategoria" << endl
				 << "8- altaDiagnisticosDeConsulta" << endl
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
				 << "20- salir" << endl << endl;
		}

		cout << ">> "; cin >> opcion;

		if(opcion == "iniciarSesion"){
			try{
				iniciarSesion();
			}
			catch (const std::invalid_argument& e){
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "AltaReactivarUsuario"){
			try{
				altaReactivacionUsuario();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "dadosDeAltaReactivados"){
			try{
				usuariosDadosDeAlta();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "altaRepresentacionEstandarizada"){
			try{
				altaRepresentacionEstandarizada();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "listarRepresentacionesEstandarizadas"){
			try{
				listarRepresentacionesEstandarizadas();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "registrarConsulta"){
			try{
				registroConsulta();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "cantidadConsultasPorCategoria"){
			try{
				cantidadConsultasPorCategoria();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "altaDiagnisticosDeConsulta"){
			try{
				altaDiagnosticosConsulta();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "historialPaciente"){
			try{
				obtenerHistorialPaciente();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "reservarConsulta"){
			try{
				reservaConsulta();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "devolverReserva"){
			try{
				devolucionConsulta();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "estadoDeSituacion"){
			try{
				estadoDeSituacion();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "suscribirseAPaciente"){
			try{
				suscribirseAPaciente();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "verNotificaciones"){
			try{
				verNotificaciones();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "altaMedicamento"){
			try{
				altaMedicamento();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "verMaximoInasistencias"){
			try{
				verMaximoInasistencias();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "setearMaximoInasistencias"){
			try{
				setearMaximoInasistencias();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "verHora"){
			try{
				verFechaSistema();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "modificarHora"){
			try{
				modificarFechaSistema();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "cerrarSesion"){
			try{
				cerrarSesion();
			}
			catch (const std::invalid_argument& e) {
				std::cerr << "ERROR: " << e.what() << endl;
			}
		}

		else if(opcion == "salir"){
			if(cu->usuarioLogueado()){
				cerrarSesion();
			}
			break;
		}

		else{
			cout << "Opcion incorrecta" << endl;
		}

	}

	return 0;
}
