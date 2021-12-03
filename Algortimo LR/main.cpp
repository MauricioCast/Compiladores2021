#include<bits/stdc++.h>
#include <windows.h>
#include"TablaM.h"
using namespace std;
int main(int argc, char* argv[])
{
    //Recibir producciones por un archivo txt
    char respuesta;
    string ubicacionEntrada;
    if(argc==1)
    {
        cout<<"Formato: nombreEjecutable nombre.txt"<<endl;
        exit(0);
    }
    ubicacionEntrada = argv[1];
    TablaM* obj = new TablaM();
    obj->glc.archivo.cargarDesde(ubicacionEntrada);
    //llenado de la gramatica libre de contexto
    obj->glc.llenadoDeGLC();
    obj->p.generarPrimeros(obj->glc.getN(), obj->glc.getT(), obj->glc.getProducciones());
    obj->s.generarSiguientes(obj->glc.getN(), obj->p.getNT(), obj->glc.getProducciones(), obj->p.getPrimerosT());
    obj->generarTabla(obj->glc.getProducciones(), obj->p.getPrimerosT(), obj->s.getSiguientes(), obj->glc.getN(), obj->glc.getT());
    obj->emisor.guardarEn(obj->glc.getS(), obj->glc.getN(), obj->glc.getT(), obj->glc.getProducciones(), obj->p.getPrimerosT(), obj->s.getSiguientes(), obj->getTablaM());
    return 0;
}
