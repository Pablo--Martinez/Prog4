#ifndef DATATRATAMIENTO_H_
#define DATATRATAMIENTO_H_

#include <string>

using namespace std;

class DataTratamiento {
	private:
		string descripcion;
	public:
		DataTratamiento();
		DataTratamiento(string);
		virtual ~DataTratamiento();
		string getDescripcion();
};

#endif /* DATATRATAMIENTO_H_ */
