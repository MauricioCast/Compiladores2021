    #ifndef GRAMATICALIBREDECONTEXTO_H
#define GRAMATICALIBREDECONTEXTO_H
#include <bits/stdc++.h>
#include "ReceptorProducciones.h"
using namespace std;
class GramaticaLibreDeContexto
{
private:
    char S;
    string N;
    string T;
    vector<string> producciones;
public:
    ReceptorProducciones archivo;
    GramaticaLibreDeContexto();
    ~GramaticaLibreDeContexto();
    void llenadoDeGLC();
    char getS();
    string getN();
    string getT();
    vector<string> getProducciones();
};
//Constructor
GramaticaLibreDeContexto::GramaticaLibreDeContexto(/* args */)
{

}
//Destructor
GramaticaLibreDeContexto::~GramaticaLibreDeContexto()
{
}
//lenado de Gramatica Libre de Contexto
void GramaticaLibreDeContexto::llenadoDeGLC()
{
    //producciones
    producciones = archivo.getProducciones();
    //Simbolo inicial
    S = producciones[0][0];
    //No terminales y terminales
    bool flag = false;
    for (int i = 0; i < producciones.size(); i++)
    {
        for (int j = 0; j < producciones[i].size(); j++)
        {
            //No terminales
            if (producciones[i][j] >= 65 && producciones[i][j] <= 90 && producciones[i][j] != 69) //A-Z sin E
            {
                for(int k = 0; k < N.size(); k++)
                {
                    if(producciones[i][j]==N[k])
                    {
                        flag=true;
                        break;
                    }
                }
                if (flag == false)
                    N.push_back(producciones[i][j]);
            }
            //Terminales
            else if ((producciones[i][j] >= 97 && producciones[i][j] <= 122) | producciones[i][j] == 69) //a-z con E
            {
                for (int k = 0; k < T.size(); k++)
                {
                    if(producciones[i][j]==T[k])
                    {
                        flag=true;
                        break;
                    }
                }
                if(flag == false)
                    T.push_back(producciones[i][j]);
            }
            flag = false;
        }
    }
}
//gets
char GramaticaLibreDeContexto::getS(){
    return S;
}
string GramaticaLibreDeContexto::getN(){
    return N;
}
string GramaticaLibreDeContexto::getT(){
    return T;
}
vector<string> GramaticaLibreDeContexto::getProducciones(){
    return producciones;
}
#endif