mian: Paga.o Cambio.o
	g++ -Wall -Werror -o main main.cpp Cambio.o Paga.o
	
Cambio.o:
	g++ -Wall -Werror -c Cambio.h Cambio.cpp
	
Paga.o:
	g++ -Wall -Werror -c Paga.h Paga.cpp
	
Empresa.o: Empleado.o
	g++ -Wall -Werror -c Empresa.h Empresa.cpp Empleado.o
	
Empleado.o: Paga.o
	g++ -Wall -Werror -c Empleado.h Empleado.cpp Paga.o Empresa.o

Jornalero.o: Empleado.o
	g++ -Wall -Werror -c Jornalero.h Jornalero.cpp Empleado.o
	
Fijo.o: Empleado.o
	g++ -Wall -Werror -c Fijo.h Jornale.cpp Empleado.o
	
clear:
	rm Paga.o Cambio.o Empleado.o Jornalero.o Fijo.o Empresa.o main
