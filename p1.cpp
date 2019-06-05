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

    ficheroEntrada.open("A1m.txt", ios::in);
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