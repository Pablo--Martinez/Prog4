#ifndef DATATRATAMIENTO_H_
#define DATATRATAMIENTO_H_

#include <string>
#include <iostream>

using namespace std;

class DataTratamiento {
	private:
		string descripcion;
	public:
		DataTratamiento();
		DataTratamiento(string);
		virtual ~DataTratamiento();
		string getDescripcion();
		void show();
};

#endif /* DATATRATAMIENTO_H_ */
