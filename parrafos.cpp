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
        // cout<<"Frase:"<<frase<<endl;
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
    // cout << "frases :" << frases.size() << endl;
    return frases;
}

vector<string> compareToken(vector<vector<string> > tokens1,vector<vector<string> > tokens2){
    vector<string> cadenas;
    cout << "Size: " << tokens1.size() << endl; 

    for(int i = 0; i < tokens1.size(); i++){
        for(int j = 0; j < tokens1.at(i).size(); j++ ){
          for(int k = 0; k < tokens2.size(); k++){
                for(int l = 0; l < tokens2.at(k).size(); l++ ){
                    if(tokens1.at(i).at(j) == tokens2.at(k).at(l)){
                        cadenas.push_back(tokens1.at(i).at(j));
                    }
                }
            }  
        }
    }
    return cadenas;
}

string cadenaFinal(vector<string> cadenas){
    int aux = 0, tmp = 0;
    for(int i = 0; i < cadenas.size(); i++){
        if(aux <= cadenas.at(i).size()){
            aux = cadenas.at(i).size();
            tmp = i;
        }
    }
    return cadenas.at(tmp);
}

int main(int argc, char *argv[])
{
    fstream ficheroEntrada;
    string frase;
    char *final = (char *)".\0";
    int contadorParrafos = 0;
    vector<vector<string>> tokparag, tokparag2;
    vector<string> cadenas;
    ficheroEntrada.open(argv[1], ios::in);
    if (ficheroEntrada.is_open()){
        while (!ficheroEntrada.eof()){
            tokparag.push_back(getPhrases(read_paragraph(ficheroEntrada)));
        }
        ficheroEntrada.close();
    }
    
    ficheroEntrada.open(argv[2], ios::in);
    if (ficheroEntrada.is_open()){
        while (!ficheroEntrada.eof()){
            // cout << "Parrafo tokenizado" << endl;
            tokparag2.push_back(getPhrases(read_paragraph(ficheroEntrada)));
        }
        ficheroEntrada.close();
    }

    // cout << "Tokpa "<< tokparag.at(0) << endl;
    // cout << "Comparacion " << endl;
    cadenas = compareToken(tokparag,tokparag2);
    cout << "Cadena: " << cadenaFinal(cadenas) << endl;
    return 0;
}