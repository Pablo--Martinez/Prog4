mian: Paga.o Cambio.o
	g++ -Wall -Werror -g -o main main.cpp Cambio.o Paga.o
	
Cambio.o:
	g++ -Wall -Werror -g -c Cambio.h Cambio.cpp
	
Paga.o:
	g++ -Wall -Werror -g -c Paga.h Paga.cpp
	
Empresa.o:
	g++ -Wall -Werror -c Empresa.h Empresa.cpp Paga.o
	
Empleado.o:
	g++ -Wall -Werror -c Empleado.h Empleado.cpp Paga.o

Jornalero.o:
	g++ -Wall -Werror -c Jornalero.h Jornalero.cpp Empleado.o Paga.o
	
Fijo.o:
	g++ -Wall -Werror -c Fijo.h Fijo.cpp Empleado.o
	
clear:
	rm Paga.o Cambio.o Empleado.o Jornalero.o Fijo.o Empresa.o main
