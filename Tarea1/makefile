mian:Paga.o Cambio.o Empleado.o Jornalero.o Fijo.o Empresa.o
	g++ -Wall -Werror -o main main.cpp Cambio.o Paga.o Empleado.o Fijo.o Jornalero.o Empresa.o

Cambio.o:
	g++ -Wall -Werror -c Cambio.h Cambio.cpp

Paga.o:
	g++ -Wall -Werror -c Paga.h Paga.cpp

Empresa.o:
	g++ -Wall -Werror -c Empresa.h Empresa.cpp

Empleado.o: Empresa.o
	g++ -Wall -Werror -c Empleado.h Empleado.cpp

Jornalero.o:
	g++ -Wall -Werror -c Jornalero.h Jornalero.cpp

Fijo.o:
	g++ -Wall -Werror -c Fijo.h Fijo.cpp

clear:
	rm Paga.o Cambio.o Empleado.o Jornalero.o Fijo.o Empresa.o main
