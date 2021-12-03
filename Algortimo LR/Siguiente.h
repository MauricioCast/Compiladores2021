#ifndef SIGUIENTE_H
#define SIGUIENTE_H
#include <bits/stdc++.h>
#include "TablaM.h"
using namespace std;
class Siguiente
{
private:
    vector<string> siguientesT;
public:
    Siguiente(/* args */);
    ~Siguiente();
    void generarSiguientes(string, string, vector<string>, vector<string>);
    vector<string> getSiguientes();
};

Siguiente::Siguiente(/* args */)
{
}

Siguiente::~Siguiente()
{
}
void Siguiente::generarSiguientes(string N, string NT, vector<string> producciones, vector<string> primerosT)
{
    //Siguientes Terminales, aqui ya estan terminados
    vector<string> siguientesT(N.size());
    //Siguientes no terminados, aun les falta buscar
    vector<vector<pair<int, int>>> siguientesN(N.size());
    //vector para saber si ya se acabo de buscar 0=N0, 1=Si
    vector<int> terminados(N.size(), 0); //tam, valor inicial
    //Siguiente de Siguientes no resueltos
    vector<vector<int>> siguientesSiguiente(N.size());
    //Siguiente de Siguientes auxSig que sirve para modificar sigueinteSiguientes
    vector<vector<int>> auxSigSig(N.size());
    //vector para saber si un S() ya estuvo en otro s()
    vector<vector<int>> almacenSiguientes(N.size(), vector<int>(N.size(), 0));
    //asignar $
    siguientesT[0].push_back('$');
    //empezar con SiguientesN
    for (int i = 0; i < N.size(); i++)
    {
        for (int j = 0; j < producciones.size(); j++)
        {
            for (int k = 0; k < producciones[j].size(); k++)
            {
                if (N[i] == producciones[j][k] && k >= 3)
                {
                    siguientesN[i].push_back(make_pair(j, k));
                }
            }
        }
    }
    //varaibles para los ciclos
    bool salir = false;
    char auxSig, auxP;
    int auxSigPos, auxPPos, auxE = 0;
    int auxIguales = 0, countSalir = 0;
    int auxTam;
    //aignar siguientesT y siguientesSigueinte
    for (int i = 0; i < siguientesN.size(); i++)
    {
        for (int j = 0; j < siguientesN[i].size(); j++)
        {
            //Regla 2: Siguientes(X) = A->'alpha'X => siguiente de (A)
            if (producciones[siguientesN[i][j].first].size() - 1 == siguientesN[i][j].second)
            {
                //cout << "REAGLA 2" << endl;
                //agregar S(A)
                //buscar cual es S(A) y su posición
                auxSig = producciones[siguientesN[i][j].first][0];
                for (int k = 0; k < N.size(); k++)
                {
                    if (N[k] == auxSig)
                        auxSigPos = k;
                }
                //agregar S(A)
                siguientesSiguiente[i].push_back(auxSigPos);
            }
            //Regla 3: Siguientes(X) = A->'alpha'X'beta'
            else
            {
                //cout << "REGLA 3" << endl;
                //buscar cual es P('beta') y su posición
                auxP = producciones[siguientesN[i][j].first][siguientesN[i][j].second + 1];
                for (int k = 0; k < NT.size(); k++)
                {
                    if (NT[k] == auxP)
                        auxPPos = k;
                }
                //primero de 'beta' tiene E?
                /*buscar si tiene E*/
                for (int k = 0; k < primerosT[auxPPos].size(); k++)
                {
                    if (primerosT[auxPPos][k] == 69) //tiene E?
                        auxE++;
                }
                /* agregar primemroT si no estan, sin agregar E*/
                for (int l = 0; l < primerosT[auxPPos].size(); l++)
                {
                    for (int m = 0; m < siguientesT[i].size() + 1; m++)
                    {
                        if (primerosT[auxPPos][l] == siguientesT[i][m] | primerosT[auxPPos][l] == 69)
                        {
                            auxIguales++;
                        }
                    }
                    if (auxIguales == 0)
                        siguientesT[i].push_back(primerosT[auxPPos][l]);
                    auxIguales = 0;
                }
                /*tiene E, agregar P('beta') sin E y S(A)*/
                if (auxE != 0)
                {
                    //agregar S(A)
                    //buscar cual es S(A) y su posición
                    auxSig = producciones[siguientesN[i][j].first][0];
                    for (int k = 0; k < N.size(); k++)
                    {
                        if (N[k] == auxSig)
                            auxSigPos = k;
                    }
                    //agregar S(A)
                    siguientesSiguiente[i].push_back(auxSigPos);
                }
                auxE = 0;
            }
        }
    }
    //ciclo
    while (salir == false)
    {
        //revisar en SiguientesSiguiente S() repetidos o a si mismos
        for (int i = 0; i < siguientesSiguiente.size(); i++)
        {
            for (int j = 0; j < siguientesSiguiente[i].size(); j++)
            {
                if (siguientesSiguiente[i][j] == i)
                {
                    siguientesSiguiente[i].erase(siguientesSiguiente[i].begin() + j);
                    j--;
                }
                else
                {
                    for (int k = 0; k < siguientesSiguiente[i].size(); k++)
                    {
                        if (siguientesSiguiente[i][j] == siguientesSiguiente[i][k] && k != j)
                        {
                            siguientesSiguiente[i].erase(siguientesSiguiente[i].begin() + k);
                            k--;
                        }
                    }
                }
            }
        }
        //almacenar S() en almacenar Siguientes
        for (int i = 0; i < siguientesSiguiente.size(); i++)
        {
            for (int j = 0; j < siguientesSiguiente[i].size(); j++)
            {
                almacenSiguientes[i][siguientesSiguiente[i][j]]++;
            }
        }
        //revisar si alguno ya termino
        for (int i = 0; i < siguientesSiguiente.size(); i++)
        {
            if (siguientesSiguiente[i].size() == 0)
                terminados[i] = 1;
        }
        //meter siguientesT en los siguientes()
        for (int i = 0; i < siguientesSiguiente.size(); i++)
        {
            for (int j = 0; j < siguientesSiguiente[i].size(); j++)
            {
                /* agregar primemroT si no estan, sin agregar E*/
                for (int l = 0; l < siguientesT[siguientesSiguiente[i][j]].size(); l++)
                {
                    for (int m = 0; m < siguientesT[i].size() + 1; m++)
                    {
                        if (siguientesT[siguientesSiguiente[i][j]][l] == siguientesT[i][m])
                        {
                            auxIguales++;
                        }
                    }
                    if (auxIguales == 0)
                        siguientesT[i].push_back(siguientesT[siguientesSiguiente[i][j]][l]);
                    auxIguales = 0;
                }
            }
        }
        //intercambiar
        for (int i = 0; i < siguientesSiguiente.size(); i++)
        {
            for (int j = 0; j < siguientesSiguiente[i].size(); j++)
            {
                for (int k = 0; k < siguientesSiguiente[siguientesSiguiente[i][j]].size(); k++)
                {
                    if (almacenSiguientes[i][siguientesSiguiente[siguientesSiguiente[i][j]][k]] <= N.size())
                        auxSigSig[i].push_back(siguientesSiguiente[siguientesSiguiente[i][j]][k]);
                }
            }
        }
        siguientesSiguiente = auxSigSig;
        //vaciar auxSigSig
        for (int i = 0; i < auxSigSig.size(); i++)
        {
            auxTam = auxSigSig[i].size();
            for (int j = 0; j < auxTam; j++)
            {
                if (auxSigSig[i].size() > 0)
                    auxSigSig[i].pop_back();
            }
        }
        for (int i = 0; i < terminados.size(); i++)
        {
            if (terminados[i] == 1)
            {
                countSalir++;
            }
        }
        if (countSalir == terminados.size())
            salir = true;
        countSalir = 0;
    }
    this->siguientesT=siguientesT;
    //--------------------------------------------------------------------
    /*cout << "siguientes: " << endl;
    for (int i = 0; i < siguientesT.size(); i++)
    {
        cout << N[i] << " " << siguientesT[i] << endl;
    }*/
}
vector<string> Siguiente::getSiguientes(){
    return siguientesT;
}

#endif
