#ifndef DATAREP_H_
#define DATAREP_H_

#include <string>

using namespace std;

class DataRep {
	private:
		//string letra;
		string codigo;
		string etiqueta;
	public:
		DataRep();
		DataRep(string,string);
		virtual ~DataRep();
		//string getLetra();
		string getCodigo();
		string getEtiqueta();
};

#endif /* DATAREP_H_ */
