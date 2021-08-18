#include <bits/stdc++.h>
#include "AutomataFinito.h"
#include "AFD.h"
#include "AFN.h"
using namespace std;
int main(int argc, char *argv[])
{
    string auxInput;
    //Recibir producciones por un archivo txt
    string ubicacionEntrada;
    if (argc != 2)
    {
        cout << "Formato: nombreEjecutable nombre.af" << endl;
        exit(0);
    }
    ubicacionEntrada = argv[1];
    AutomataFinito *obj = new AutomataFinito();
    obj->archivo.cargarDesde(ubicacionEntrada);
    //llenado del automata finito
    obj->llenadoDeAutomataFinito();
    AFD *objAFD = new AFD();
    AFN *objAFN = new AFN();
    //menu
    int opc = 0;
    do
    {
        if (obj->AFNoAFD() == true)
        {
            objAFN->setAlfabeto(obj->getAlfabeto());
            objAFN->setTransiciones(obj->getTransiciones());
            objAFN->setEstadoInicial(obj->getEstadoInicial());
            objAFN->setEstadosFinales(obj->getEstadosFinales());
        }
        else
        {
            objAFD->setAlfabeto(obj->getAlfabeto());
            objAFD->setTransiciones(obj->getTransiciones());
            objAFD->setEstadoInicial(obj->getEstadoInicial());
            objAFD->setEstadosFinales(obj->getEstadosFinales());
        }
         system("cls");
        cout << "\tEscoge una opcion" << endl;
        cout << "1.-Agregar Transicion" << endl;
        cout << "2.-Eliminar una Transicion" << endl;
        cout << "3.-Establecer Final" << endl;
        cout << "4.-Establecer Inicial" << endl;
        cout << "5.-Guardar" << endl;
        cout << "6.-Salir" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Transicion a agregar: ";
            cin >> auxInput;
            obj->agregarTransicion(auxInput);
            break;
        case 2:
            cout << "Tansicion a eliminar: ";
            cin >> auxInput;
            obj->eliminarTransicion(auxInput);
            break;
        case 3:
            cout << "Dame un estado final: ";
            cin >> auxInput;
            obj->establecerFinal(auxInput);
            break;
        case 4:
            cout << "Dame un estado inicial: ";
            cin >> auxInput;
            obj->establecerInicial(auxInput);
            break;
        case 5:
            cout << "Guadando..." << endl;
            if (obj->AFNoAFD() == true)
            {
                objAFN->emisor.guardarEn(objAFN->getEstadoInicial(), objAFN->getEstadosFinales(), objAFN->getTransiciones(), "Automata Finito No Determinista");
            }
            else
            {
                objAFD->emisor.guardarEn(objAFD->getEstadoInicial(), objAFD->getEstadosFinales(), objAFD->getTransiciones(), "Automata Finito No Determinista");
            }
        }
    } while (opc != 6);
    return 0;
}
