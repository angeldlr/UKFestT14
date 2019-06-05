#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
 
using namespace std;

string read_paragraph(istream& is)
{
    stringstream ss;
    string line;

    do
    {
        getline(is, line);
        ss << " " << line;
    } while(line != "");

    return ss.str();
}

int main () {
    fstream ficheroEntrada;
    string frase;
    char* final = (char*)".\0";
	int contadorParrafos = 0;

<<<<<<< HEAD:p1.cpp
    ficheroEntrada.open("A1modif.txt", ios::in);
=======
    ficheroEntrada.open("B1.txt", ios::in);
>>>>>>> e37de1922c456a88889ff73be57d9155ad62b62f:parrafos.cpp
    if (ficheroEntrada.is_open()) {
        while (!ficheroEntrada.eof()) {
        	cout << "Parrafo: " << read_paragraph(ficheroEntrada) << endl;
            //getline (ficheroEntrada,frase);
			//cout << ">" << frase << endl;
        }
        ficheroEntrada.close();
    }
    else cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;  

 
    return 0;
}