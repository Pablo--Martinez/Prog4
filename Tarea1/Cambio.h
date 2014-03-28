#ifndef CAMBIO
#define CAMBIO

class Cambio{
	private:
		static float cotizacion;
		
	public:
		static float a_peso(float importe);
		static float a_dolar(float importe); 
};

#endif

