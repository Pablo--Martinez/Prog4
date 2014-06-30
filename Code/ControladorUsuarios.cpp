#include "ControladorUsuarios.h"

ControladorUsuarios* ControladorUsuarios::instancia = NULL;

ControladorUsuarios::ControladorUsuarios(){
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();
	this->logueado = NULL;
	this->a_tratar = NULL;
	this->maximo_inasistencias = 3;

	Usuario* u = new Usuario(123456789,"admin","admin",M,true,Fecha());
	Administrador* admin =  new Administrador(u);
	u->agregarRol(admin);
	u->activar("admin");
	this->usuarios[u->getCI()] = u;
	ma->agregarAdministrador(admin);

	Usuario* ud = new Usuario(34567645,"James","Peer",M,true,Fecha(28,12,1988));
	Administrador* admind =  new Administrador(ud);
	ud->agregarRol(admind);
	this->usuarios[ud->getCI()] = ud;
	ma->agregarAdministrador(admind);

	/*Usuario* u1 = new Usuario(51708245,"Medico","Medico",M,true,Fecha(15,7,1992,0,0));
	Usuario* u2 = new Usuario(51708240,"Socio","Socio",F,true,Fecha(15,7,1992,0,0));
	Medico* m = new Medico(u1);
	Socio* s = new Socio(u2);
	this->usuarios[51708245] = u1;
	this->usuarios[51708240] = u2;

	ManejadorMedicos* mm = ManejadorMedicos::getInstance();
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	mm->agregarMedico(m);
	ms->agregarSocio(s);*/

}

ControladorUsuarios::~ControladorUsuarios(){
	delete this->logueado;
	delete this->a_tratar;
	for(map<int,Usuario*>::iterator it = this->usuarios.begin();it != this->usuarios.end();++it){
		delete (it->second);
	}
	this->usuarios.clear();
}

ControladorUsuarios* ControladorUsuarios::getInstance(){
	if (instancia == NULL)
		instancia = new ControladorUsuarios();
	return instancia;
}

void ControladorUsuarios::setMaximoInasistencias(int cantidad){
	ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();
	if(ma->find(this->logueado->getCI()) == NULL)
		throw std::invalid_argument("Se deben tener permisos de administrador");

	this->maximo_inasistencias = cantidad;
}

int ControladorUsuarios::getMaximoInasistencias(){
	return this->maximo_inasistencias;
}

Usuario* ControladorUsuarios::getUsuarioLogueado(){
	return this->logueado;
}

/*set<DataAltaReactivacion*> ControladorUsuarios::obtenerDaDeAltaReactiva() {
	return this->logueado->obtenerUsuariosAltaReactivacion();
}*/

TSesion ControladorUsuarios::iniciarSesion(int ci){
	this->a_tratar = this->usuarios[ci];
	if(this->a_tratar == NULL)
		throw std::invalid_argument("Usuario inexistente");

	TSesion tipo = this->a_tratar->getTipoSesion();
	if(tipo == CM && !this->a_tratar->getEstado()){
		this->a_tratar = NULL;
		throw std::invalid_argument("Usuario inactivo");
	}
	return tipo;
}

bool ControladorUsuarios::ingresarContrasenia(string pass){
	return this->a_tratar->verificarPass(pass);
}

void ControladorUsuarios::asignarSesion(){
	this->logueado = this->a_tratar;
	this->a_tratar = NULL;
}

void ControladorUsuarios::activarUsuario(string pass){
	this->a_tratar->activar(pass);
}

void ControladorUsuarios::reactivar(){
	this->a_tratar->reactivar();
	ManejadorAdministradores* madmin = ManejadorAdministradores::getInstance();
	Administrador* aLogueado = madmin->find(this->getUsuarioLogueado()->getCI());
	DataUsuario* du = this->a_tratar->getDataUsuario();
	RelojSistema* rs = RelojSistema::getInstance();
	aLogueado->agregarUsuarioAltaReactivacion(du, rs->getFechaSistema(), false);//Cuando es False es porque es reactivación
}

void ControladorUsuarios::cerrarSesion(){
	if(this->logueado == NULL)
			throw std::invalid_argument("No hay usuario legueado");
	this->logueado = NULL;
}

bool ControladorUsuarios::usuarioLogueado(){
	return this->logueado != NULL;
}

bool ControladorUsuarios::ingresoCI(int ci){
	if(this->usuarios.find(ci) == this->usuarios.end()){
		this->a_tratar = this->usuarios.find(ci)->second;
		this->ci = ci;
		return false;
	}
	else{
		this->ci = ci;
		return true;
	}
}

void ControladorUsuarios::ingresarDatosUser(string nombre, string apellido, Sexo sexo, Fecha fecha){
	this->nombre = nombre;
	this->apellido = apellido;
	this->sexo = sexo;
	this->nacimiento = fecha;
}

void ControladorUsuarios::ingresarCategoria(Categoria cat){
    this->categorias.insert(cat);
}


void ControladorUsuarios::confirmarInscripcion(){
	Usuario* u = new Usuario(this->ci,this->nombre,this->apellido,this->sexo,false,this->nacimiento);
	for(set<Categoria>::iterator it = this->categorias.begin(); it != this->categorias.end(); ++it){
        if(*it == Soc){
            Socio* s = new Socio(u);
            u->agregarRol(s);
            ManejadorSocios* ms = ManejadorSocios::getInstance();
            ms->agregarSocio(s);
        }
        else if(*it == Med){
            Medico* m = new Medico(u);
            u->agregarRol(m);
            ManejadorMedicos* mm = ManejadorMedicos::getInstance();
            mm->agregarMedico(m);
        }
        else if(*it == Admin){
            Administrador* a = new Administrador(u);
            u->agregarRol(a);
            ManejadorAdministradores* ma = ManejadorAdministradores::getInstance();
            ma->agregarAdministrador(a);
        }
	}
	ManejadorAdministradores* madmin = ManejadorAdministradores::getInstance();
	Administrador* aLogueado = madmin->find(this->getUsuarioLogueado()->getCI());
	DataUsuario* du = u->getDataUsuario();
	RelojSistema* rs = RelojSistema::getInstance();
    aLogueado->agregarUsuarioAltaReactivacion(du, rs->getFechaSistema(), true);//Cuando es True es porque es alta
	this->usuarios[this->ci] = u;
}

void ControladorUsuarios::cancelarInscripcion(){
	this->ci = 0;
	this->nombre = "";
	this->apellido = "";
	this->pass = "";
	this->sexo = M;
}


DataUsuario* ControladorUsuarios::devolverDatosUsuario(){
	this->a_tratar = this->usuarios[this->ci];
	return this->a_tratar->getDataUsuario();
}

void ControladorUsuarios::recalcularInasistencias(Fecha fecha_sistema){
	ManejadorSocios* ms = ManejadorSocios::getInstance();
	map<int,Socio*> socios = ms->getSocios();
	for(map<int,Socio*>::iterator socio = socios.begin();socio!= socios.end();++socio){
		int cantidad = 0;
		set<Consulta*> consultas = socio->second->getConsultasSolicitadas();
		for(set<Consulta*>::iterator consulta = consultas.begin();consulta!=consultas.end();++consulta){
			if(typeid(*consulta) == typeid(ConReserva)){
				ConReserva* r = dynamic_cast<ConReserva*>(*consulta);
				if(r->getFechaConsulta() > fecha_sistema && r->getAsiste())
					cantidad++;
			}
		if(cantidad > this->maximo_inasistencias)
			this->usuarios[socio->first]->desactivar();
		}
	}
}
