mian: Paga.o Cambio.o
	g++ -Wall -Werror -o main main.cpp Cambio.o Paga.o
	
Cambio.o:
	g++ -Wall -Werror -c Cambio.h Cambio.cpp
	
Paga.o:
	g++ -Wall -Werror -c Paga.h Paga.cpp
	
clear:
	rm Paga.o Cambio.o main
