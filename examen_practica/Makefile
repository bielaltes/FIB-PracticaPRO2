OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Jugador.o Cjt_jugadors.o Torneig.o Cjt_tornejos.o Cjt_categories.o 
	g++ -o program.exe program.o Jugador.o Cjt_jugadors.o Torneig.o Cjt_tornejos.o  Cjt_categories.o  

Jugador.o:  Jugador.cc Jugador.hh 
	g++ -c Jugador.cc $(OPCIONS)

Cjt_jugadors.o:  Cjt_jugadors.cc Cjt_jugadors.hh
	g++ -c Cjt_jugadors.cc $(OPCIONS)

Torneig.o:  Torneig.cc Torneig.hh
	g++ -c Torneig.cc $(OPCIONS)
	
Cjt_tornejos.o:  Cjt_tornejos.cc Cjt_tornejos.hh
	g++ -c Cjt_tornejos.cc $(OPCIONS)


Cjt_categories.o:  Cjt_categories.cc Cjt_categories.hh
	g++ -c Cjt_categories.cc $(OPCIONS)
	

program.o: program.cc
	g++ -c program.cc $(OPCIONS)
	
practica.tar: Jugador.hh Cjt_jugadors.hh Torneig.hh Cjt_tornejos.hh Cjt_categories.hh Jugador.cc Cjt_jugadors.cc Torneig.cc 		Cjt_tornejos.cc Cjt_categories.cc BinTree.hh Makefile program.cc
	tar -cvf practica.tar Jugador.hh Cjt_jugadors.hh Torneig.hh Cjt_tornejos.hh Cjt_categories.hh Jugador.cc Cjt_jugadors.cc Torneig.cc Cjt_tornejos.cc Cjt_categories.cc BinTree.hh Makefile program.cc 

clean:
	rm *.o
	rm *.exe
