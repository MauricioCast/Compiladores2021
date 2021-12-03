#ifndef EMISORDATOS_H
#define EMISORDATOS_H
#include <bits/stdc++.h>
#include "TablaM.h"
using namespace std;
class EmisorDatos
{
private:

public:
    EmisorDatos(/* args */);
    ~EmisorDatos();
    void guardarEn(char, string, string, vector<string>, vector<string>, vector<string>, vector<vector<string>>);
};

EmisorDatos::EmisorDatos(/* args */)
{
}

EmisorDatos::~EmisorDatos()
{
}
void EmisorDatos::guardarEn(char S, string N, string T, vector<string> producciones, vector<string> primeros, vector<string> siguientes, vector<vector<string>> tablaM)
{
    ofstream archivo;
    string NT = N + T;
    archivo.open("salida.txt", ios::out);
    if (archivo.fail())
    {
        cout << "El archivo no se pudo crear..." << endl;
        exit(1);
    }
    else
    {
        system("CLS");
        cout << "\n\n\n\n\n\n\n\n\t\t\t-------------------------------------------\n";
        cout << "\t\t\t|Los datos se han guardado en salida.txt :)|\n";
        cout << "\t\t\t-------------------------------------------\n\n\n\n\n\n\n\n";
        archivo << "\n\t\tPractica 6: tablaM" << endl;
        archivo << "\tSimbolo Inicial: " << S << endl;
        archivo << "\tSimbolos No Terminales: " << N << endl;
        archivo << "\tSimbolos Terminales: " << T << endl;
        archivo << "\tProducciones: " << endl;
        for (int i = 0; i < producciones.size(); i++)
        {
            archivo << "\t" << producciones[i] << endl;
        }
        archivo << "\n\n\t\t.:Primeros:." << endl;
        for (int i = 0; i < NT.size(); i++)
        {
            archivo << "\t" << NT[i] << "\t" << primeros[i] << endl;
        }
        archivo << "\n\n\t\t.:Siguientes:." << endl;
        for (int i = 0; i < N.size(); i++)
        {
            archivo << "\t" << N[i] << "\t" << siguientes[i] << endl;
        }
        archivo << "\n\n\t\t.:TablaM de LL(1):." << endl;
        //poner $
        //tiene E?
        int auxE = 0;
        for (int i = 0; i < T.size(); i++)
        {
            if (T[i] == 69)
            {
                T[i] = 36;
                auxE++;
            }
        }
        if (auxE == 0)
            T.push_back('$');
        archivo << "\t";
        for (int i = 0; i < T.size(); i++)
        {
            archivo << "|" << T[i] << "\t";
        }
        archivo << endl;
        for (int i = 0; i < tablaM.size(); i++)
        {
            for (int i = 0; i < T.size(); i++)
            {
                archivo << "_________";
            }
            archivo << endl;
            archivo << N[i] << "\t";
            for (int j = 0; j < tablaM[i].size(); j++)
            {
                archivo << "|";
                for (int k = 0; k < tablaM[i][j].size(); k++)
                {
                    archivo << tablaM[i][j][k] << " ";
                }
                archivo << "\t";
            }
            archivo << endl;
        }
    }
    archivo.close();
}

#endif
