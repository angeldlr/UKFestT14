#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream ficheroEntrada;
 string frase;
 int lin=0;
 
 ficheroEntrada.open ("A2.txt");
 while(ficheroEntrada.good()) if(ficheroEntrada.get()=='.') {
     if (ficheroEntrada.get()=='\n')
     lin++;
 }
  
 ficheroEntrada.close();

cout << "Prárrafos: " << lin << endl;
 
 
  
 
 return 0;
}