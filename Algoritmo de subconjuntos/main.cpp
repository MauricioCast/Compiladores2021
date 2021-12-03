#include <iostream>
#include <stdlib.h>
#include <regex>
#include "nodo.h"
using namespace std;

string alfabeto, epsilon;
int estados, comas = 0;

int main()
{
    cout << "\nTransformar AFN a AFD por el metodo de subconjuntos" << endl;

    cout << "Ingresa el alfabeto de entrada, separando cada simbolo con una coma (Ej. a,b,c): ";
    cin >> alfabeto;
    epsilon = alfabeto + ",E";
    cin.ignore();

    for(int i=1; i<alfabeto.length(); i+=2)
    {
        if(alfabeto[i] != ',' || alfabeto[alfabeto.length()-1] == ',')
        {
            cout << "La entrada no tiene el formato \"a,b,c\"" << endl;
            cout << "Presiona ENTER para continuar...";
            cin.get();
            exit(0);
        }
        comas++;
    }

    cout << "Cantidad de estados del AFN: ";
    cin >> estados;
    cin.ignore();

    Nodo est[estados];
    string trans[estados][epsilon.length()-comas+1];
    int simb = 0;

    cout << "\nTransiciones" << endl;
    cout << "-En caso de ir a mas de un estado con el mismo simbolo, separar por una coma (Ej. (q1, a): 0,2)" << endl;
    cout << "-En caso de que un estado no tenga una transicion con cierto simbolo, simplemente usar \"-\" (Ej. (q0, c): -)" << endl;

    for(int i=0; i<estados; i++)
    {
        est[i] = Nodo();
        est[i].setNum(i);

        for(int j=0; j<epsilon.length(); j+=2)
        {
            cout << "(q" << est[i].getNum() << ", " << epsilon[j] << "): ";
            cin >> trans[i][simb];
            string aux;

            for(int p=0, q=0; p!=trans[i][simb].npos; p=q)
            {
                aux = trans[i][simb].substr(p+(p!=0), (q=trans[i][simb].find(',', p+1))-p-(p!=0));
                
                if(aux != "-")
                {
                    int num = stoi(aux);
                }
            }
            cin.ignore();
            simb++;
        }

        simb = 0;
    }

    cout << endl << "Tabla de transiciones: " << endl;
    cout << "Estado / ";
    
    for(int i = 0; i < epsilon.length(); i+=2)
    {
        cout << epsilon[i] << " | ";
    }
    cout << endl;

    for(int i = 0; i < estados; i++)
    {
        int simb = 0;
        cout << "q" << est[i].getNum() << " |    ";

        for(int j = 0; j < epsilon.length(); j+=2)
        {
            cout << trans[i][simb] << "    ";
            simb++;
        }
        cout << endl;
    }

    cout << "Presiona ENTER para continuar...";
    cin.get();
    
    return 0;
}