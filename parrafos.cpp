#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

string read_paragraph(istream &is)
{
    stringstream ss;
    string line;
    char *ptr;
    do
    {
        getline(is, line);
        ss << " " << line;
    } while (line != "");
    return ss.str();
}
string genPhrase(string word,vector<string> palabras){
    /*Se generan las frases posibles en el parrafo*/
    string frase;
    int i = 0;
    for (int j = 0; j < palabras.size(); j++)
    {
        frase += palabras.at(j);
        frase += " ";
        cout<<"Frase:"<<frase<<endl;
    }
    return frase;
}
vector<string> getPhrases(string parrafo)
{
    istringstream iss(parrafo);
    vector<string> palabras((istream_iterator<string>(iss)),istream_iterator<string>());
    vector<string> aux = palabras;
    vector<string> frases;
    int i=0;
    while (i<palabras.size())
    {
        frases.push_back(genPhrase(palabras.at(i),aux));
        aux.erase (aux.begin());
        i++;
    }
    return frases;
}

int main(int argc, char *argv[])
{
    fstream ficheroEntrada;
    string frase;
    char *final = (char *)".\0";
    int contadorParrafos = 0;
    char cm[1000];
    vector<string> tokparag;
    //strcat(cm,"sed -i \'y/áÁàÀãÃâÂéÉêÊíÍóÓõÕôÔúÚñÑçÇ/aAaAaAaAeEeEiIoOoOoOuUnNcC\/\' ");
    //strcat(cm,argv[1]);
    //system(cm);
    //cout << cm << endl;
    ficheroEntrada.open(argv[1], ios::in);
    if (ficheroEntrada.is_open())
    {
        while (!ficheroEntrada.eof())
        {
            cout << "Parrafo tokenizado" << endl;
            tokparag = getPhrases(read_paragraph(ficheroEntrada));
            /*for (vector<string>::iterator it = tokparag.begin(); it != tokparag.end(); ++it)
            {
                cout << "Palabra: "<< *it<< endl;
            }*/
        }
        ficheroEntrada.close();
    }
    else
        cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;

    return 0;
}