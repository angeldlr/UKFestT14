server3: server3.cpp SocketDatagrama.o PaqueteDatagrama.o 
	g++ server3.cpp SocketDatagrama.o PaqueteDatagrama.o Mensaje.h mongoose.cpp Archivo.o Mensaje.o -o server3
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h Mensaje.o
	g++ PaqueteDatagrama.cpp -c
Archivo.o: Archivo.cpp Archivo.h Header.h
	g++ Archivo.cpp -c
Mensaje.o: Mensaje.cpp Mensaje.h
	g++ Mensaje.cpp -c