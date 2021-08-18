#include<bits/stdc++.h>
using namespace std;
class ReceptorTransiciones
{
private:
    vector<string> Transiciones;
public:
    ReceptorTransiciones(/* args */);
    ~ReceptorTransiciones();
    void cargarDesde(string);
    vector<string> getTransiciones();
};

//constructor
ReceptorTransiciones::ReceptorTransiciones(/* args */)
{
}
//destructor
ReceptorTransiciones::~ReceptorTransiciones()
{
}
//abrir archivo y guardar Transiciones en el atributo Transiciones
void ReceptorTransiciones::cargarDesde(string ubicacionEntrada){
    ifstream archivo;
    string transicion;
    archivo.open(ubicacionEntrada, ios::in); //abrimos en modo lectura
    if(archivo.fail())
    {
        cout<<"Error: Problemas al abrir el archivo"<<endl;
        exit(1);
    }
    while(!archivo.eof()){                            //mientras no sea le final del archivo
        getline(archivo, transicion);                     //getline para guardar transicion por linea
        Transiciones.push_back(transicion);      
    }
    archivo.close();
}
//regresar las Transiciones para imprimirlas desde el main
vector<string> ReceptorTransiciones::getTransiciones(){
    return Transiciones;
}
