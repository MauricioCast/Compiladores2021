#ifndef PRIMERO_H
#define PRIMERO_H
#include <bits/stdc++.h>
#include "TablaM.h"
using namespace std;
class Primero
{
private:
    string NT;
    vector<string> primerosT;
public:
    Primero(/* args */);
    ~Primero();
    void generarPrimeros(string, string, vector<string>);
    //getters
    string getNT();
    vector<string> getPrimerosT();
};

Primero::Primero(/* args */)
{
}

Primero::~Primero()
{
}

void Primero::generarPrimeros(string N, string T, vector<string> producciones)
{
    //Todos los simbolos
    string NT = N + T;
    //Primeros Terminales, aqui ya estan terminados
    vector<string> primerosT(NT.size());
    //Primeros No terminales, aun les falta buscar
    vector<vector<pair<int, int>>> primerosN(NT.size());
    //vector para saber si ya se acabo de buscar 0=N0, 1=Si
    vector<int> terminados(NT.size(), 0); //tam, valor inicial
    // primero de simbolos terminales
    for (int i = 0; i < NT.size(); i++)
    {
        if ((NT[i] >= 97 && NT[i] <= 122) | NT[i] == 69) //a-z | E
        {
            primerosT[i].push_back(NT[i]); //agregamos P(T) "a={a}"
            terminados[i] = 1;
        }
    }
    //empezar con Primeros de No terminales
    for (int i = 0; i < NT.size(); i++)
    {
        //No Terminales
        if ((NT[i] >= 65 && NT[i] <= 90) && NT[i] != 69) //A-Z sin E
        {
            for (int j = 0; j < producciones.size(); j++)
            {
                if (NT[i] == producciones[j][0]) //si NT[i]== A, donde A->'alpha'
                {
                    primerosN[i].push_back(make_pair(j, 3)); //(numero de produccion, #posición de primero empezando en 3 por [0]=T [1]=- [2]=>)
                }
            }
        }
    }
    bool salir = false;
    char auxS;
    int auxSPOS;
    int auxE = 0;
    int auxIguales = 0;
    int countSalir = 0;
    while (salir == false)
    {
        for (int i = 0; i < primerosN.size(); i++)
        {
            for (int j = 0; j < primerosN[i].size(); j++)
            {
                //simbolo con el que trabajaremos
                auxS = producciones[primerosN[i][j].first][primerosN[i][j].second];
                //buscar la posición de auxS en el string NT
                for (int k = 0; k < NT.size(); k++)
                {
                    if (auxS == NT[k])
                        auxSPOS = k;
                }
                /*casos que nos podemos encontrar: T, N{termiando}
                N{no terminado, es el mismo} y a otro N{no terminado}*/
                if ((auxS >= 97 && auxS <= 122) | auxS == 69) //simbolo T
                {
                    /* agregar primosT si no estan, sin agregar E*/
                    for (int l = 0; l < primerosT[auxSPOS].size(); l++)
                    {
                        for (int m = 0; m < primerosT[i].size()+1; m++)
                        {
                            if (primerosT[auxSPOS][l] == primerosT[i][m])
                                auxIguales++;
                        }
                        if (auxIguales == 0)
                            primerosT[i].push_back(primerosT[auxSPOS][l]);
                        auxIguales = 0;
                    }
                    /*eliminar pair*/
                    primerosN[i].erase(primerosN[i].begin() + j);
                    j--; /*porque se recorren los pares*/
                }
                else if (auxS >= 65 && auxS <= 90 && auxS != 69 && terminados[auxSPOS] == 1) //simbolo N terminado
                {
                    /*buscar si tiene E*/
                    for (int l = 0; l < primerosT[auxSPOS].size(); l++)
                    {
                        if (primerosT[auxSPOS][l] == 69) //tiene E?
                        {
                            auxE++;
                        }
                    }
                    /* agregar primosT si no estan, sin agregar E*/
                    for (int l = 0; l < primerosT[auxSPOS].size(); l++)
                    {
                        for (int m = 0; m < primerosT[i].size()+1; m++)
                        {
                            if (primerosT[auxSPOS][l] == primerosT[i][m] | primerosT[auxSPOS][l] == 69)
                            {
                                auxIguales++;
                            }
                        }
                        if (auxIguales == 0)
                            primerosT[i].push_back(primerosT[auxSPOS][l]);
                        auxIguales = 0;
                    }
                    /*if por E*/
                    if (auxE != 0) //tiene E
                    {
                        /*avanzar par [][].second++ si aun hay letras en la produccion*/
                        if (primerosN[i][j].second < producciones[primerosN[i][j].first].size() - 1)
                        {
                            primerosN[i][j].second++;
                        }
                        else
                        {
                            /*eliminar par [][]*/
                            primerosN[i].erase(primerosN[i].begin() + j);
                            j--; /*porque se recorren los pares*/
                        }
                    }
                    else if (auxE == 0) //notiene E
                    {
                        /*eliminar par [][]*/
                        primerosN[i].erase(primerosN[i].begin() + j);
                        j--; /*porque se recorren los pares*/
                    }
                    auxE = 0;
                }
                else if (auxS >= 65 && auxS <= 90 && auxS != 69 && terminados[auxSPOS] == 0 && i == auxSPOS) //simbolo N no terminado y es igual A->'alpha' alpha[i] == A
                {
                    /*buscar si tiene E*/
                    for (int l = 0; l < primerosT[auxSPOS].size(); l++)
                    {
                        if (primerosT[auxSPOS][l] == 69) //tiene E?
                            auxE++;
                    }
                    if (auxE != 0)
                    {
                        /*avanzar par [][].second++ si aun hay letras en la produccion*/
                        if (primerosN[i][j].second < producciones[primerosN[i][j].first].size() - 1)
                        {
                            primerosN[i][j].second++;
                        }
                        else
                        {
                            /*eliminar par [][]*/
                            primerosN[i].erase(primerosN[i].begin() + j);
                            j--; /*porque se recorren los pares*/
                        }
                    }
                    else if (auxE == 0)
                    {
                        /*eliminar par [][]*/
                        primerosN[i].erase(primerosN[i].begin() + j);
                        j--; /*porque se recorren los pares*/
                    }
                    auxE = 0;
                }
                else if (auxS >= 65 && auxS <= 90 && auxS != 69 && terminados[auxSPOS] == 0 && i != auxSPOS) //simbolo N no terminado y es difente A->'alpha' alpha[i] != A
                {
                    /*buscar si tiene E*/
                    for (int l = 0; l < primerosT[auxSPOS].size(); l++)
                    {
                        if (primerosT[auxSPOS][l] == 69) //tiene E?
                            auxE++;
                    }
                    /* agregar primosT si no estan, sin agregar E*/
                    for (int l = 0; l < primerosT[auxSPOS].size(); l++)
                    {
                        for (int m = 0; m < primerosT[i].size()+1; m++)
                        {
                            if (primerosT[auxSPOS][l] == primerosT[i][m] | primerosT[auxSPOS][l] == 69)
                                auxIguales++;
                        }
                        if (auxIguales == 0)
                            primerosT[i].push_back(primerosT[auxSPOS][l]);
                        auxIguales = 0;
                    }
                    if (auxE != 0)
                    {
                        /*agregar par [][].second++ si aun hay letras en la produccion*/
                        if (primerosN[i][j].second < producciones[primerosN[i][j].first].size() - 1)
                        {
                            primerosN[i].push_back(make_pair(primerosN[i][j].first, primerosN[i][j].second + 1));
                        }
                    }
                    auxE = 0;
                }
            }
            //probar cuales P(N) ya se encontraron  .size() debe ser igual a 0 pasar terminado[i]=1;
            for (int i = 0; i < primerosN.size(); i++)
            {
                if (primerosN[i].size() == 0)
                    terminados[i] = 1;
            }
        }
        //checar si podemos salir
        for (int i = 0; i < terminados.size(); i++)
        {
            if (terminados[i] == 1)
                countSalir++;
        }
        if (countSalir == terminados.size())
            salir = true;
        countSalir = 0;
    }
    this->NT=NT;
    this->primerosT=primerosT;
}
//getters
string Primero::getNT(){
    return NT;
}
vector<string> Primero::getPrimerosT(){
    return primerosT;
}
#endif
