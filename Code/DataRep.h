#ifndef DATAREP_H_
#define DATAREP_H_

#include <string>
#include <iostream>

using namespace std;

class DataRep {
	private:
		string codigo;
		string etiqueta;
	public:
		DataRep();
		DataRep(string,string);
		virtual ~DataRep();
		string getCodigo();
		string getEtiqueta();
		void show();
};

#endif /* DATAREP_H_ */
