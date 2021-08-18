#ifndef EMISORDATOS_H
#define EMISORDATOS_H
#include <bits/stdc++.h>
#include "AutomataFinito.h"
using namespace std;
class EmisorDatos
{
private:

public:
    EmisorDatos(/* args */);
    ~EmisorDatos();
    void guardarEn(string estadoInicial, vector<string> estadosFinales, vector<string> transiciones, string af);
};

EmisorDatos::EmisorDatos(/* args */)
{
}

EmisorDatos::~EmisorDatos()
{
}
void EmisorDatos::guardarEn(string estadoInicial, vector<string> estadosFinales, vector<string> transiciones, string af)
{
    ofstream archivo;
    archivo.open("salida.af", ios::out);
    if (archivo.fail())
    {
        cout << "El archivo no se pudo crear..." << endl;
        exit(1);
    }
    else
    {
        system("CLS");
        cout << "\n\n\n\n\n\n\n\n\t\t\t-------------------------------------------\n";
        cout << "\t\t\t|Los datos se han guardado en salida.af :)|\n";
        cout << "\t\t\t-------------------------------------------\n\n\n\n\n\n\n\n";
        archivo << "\n\t\tPractica 1: AFN AFD" << endl;
        archivo << "\n\t\tEs un: "<< af << endl;
        archivo << "inicial: " << estadoInicial <<endl;
        archivo << "finales: ";
        for (int i = 0; i < estadosFinales.size(); i++)
        {
            archivo<< estadosFinales[i]<< " ";
        }
        archivo<< endl;
        for (int i = 0; i < transiciones.size(); i++)
        {
            archivo<<transiciones[i]<<endl;
        } 
    }
    archivo.close();
}

#endif
