#ifndef TABLAM_H
#define TABLAM_H
#include <bits/stdc++.h>
#include "GramaticaLibreDeContexto.h"
#include "Siguiente.h"
#include "Primero.h"
#include "EmisorDatos.h"
using namespace std;
class TablaM
{
private:
    string T;
    string N;
    vector<vector<string>> tablaM;
public:
    GramaticaLibreDeContexto glc;
    Primero p;
    Siguiente s;
    EmisorDatos emisor;
    TablaM(/* args */);
    ~TablaM();
    void generarTabla(vector<string>, vector<string>, vector<string>, string, string);
    vector<vector<string>> getTablaM();
    string getT();
    string getN();
};

TablaM::TablaM(/* args */)
{
}

TablaM::~TablaM()
{
}
void TablaM::generarTabla(vector<string> producciones, vector<string> primeros, vector<string> siguientes, string N, string T)
{
    //poner $
    for (int i = 0; i < T.size(); i++)
    {
        if (T[i] == 69)
            T[i] = 36;
    }
    string NT = N + T;
    vector<vector<string>> tablaM(N.size(), vector<string>(T.size()));
    char auxSig, auxTSig, auxPrimero, auxT;
    int auxSigPos, auxTSigPos, auxPrimeroPos, auxTPos;
    for (int i = 0; i < producciones.size(); i++)
    {
        if (producciones[i][3] == 69)
        {
            //buscar cual es S(A) en A->E
            auxSig = producciones[i][0];
            //buscar su posicion en N
            for (int j = 0; j < N.size(); j++)
            {
                if (N[j] == auxSig)
                    auxSigPos = j;
            }
            //siguiete
            for (int j = 0; j < siguientes[auxSigPos].size(); j++)
            {
                //buscar cual es el T
                auxT = siguientes[auxSigPos][j];
                //buscar su posicion
                for (int k = 0; k < T.size(); k++)
                {
                    if (auxT == T[k])
                        auxTPos = k;
                }
                tablaM[auxSigPos][auxTPos].push_back(i + 48 + 1 );
            }
        }
        else
        {
            //buscar cual es X en X->'alpha'
            auxSig = producciones[i][0];
            //buscar su posicion en N
            for (int j = 0; j < N.size(); j++)
            {
                if (N[j] == auxSig)
                    auxSigPos = j;
            }
            //buscar cual es primero de la produccion
            auxPrimero = producciones[i][3];
            //buscar posicion en Primeros();
            for (int j = 0; j < NT.size(); j++)
            {
                if (auxPrimero == NT[j])
                    auxPrimeroPos = j;
            }
            //primero
            for (int j = 0; j < primeros[auxPrimeroPos].size(); j++)
            {
                //buscar cual es el T
                auxT = primeros[auxPrimeroPos][j];
                //buscar su posicion
                for (int k = 0; k < T.size(); k++)
                {
                    if (auxT == T[k])
                        auxTPos = k;
                }
                if(auxT!=69)
                    tablaM[auxSigPos][auxTPos].push_back(i + 48 + 1);
            }
        }
    }
    this->T=T;
    this->N=N;
    this->tablaM=tablaM;
}
vector<vector<string>> TablaM::getTablaM(){
    return tablaM;
}
string TablaM::getT(){
    return T;
}
string TablaM::getN(){
    return N;
}
#endif