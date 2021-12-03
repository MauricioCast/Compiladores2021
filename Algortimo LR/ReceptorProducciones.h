#include<bits/stdc++.h>
using namespace std;
class ReceptorProducciones
{
private:
    vector<string> producciones;
public:
    ReceptorProducciones(/* args */);
    ~ReceptorProducciones();
    void cargarDesde(string);
    vector<string> getProducciones();
};

//constructor
ReceptorProducciones::ReceptorProducciones(/* args */)
{
}
//destructor
ReceptorProducciones::~ReceptorProducciones()
{
}
//abrir archivo y guardar producciones en el atributo producciones
void ReceptorProducciones::cargarDesde(string ubicacionEntrada){
    ifstream archivo;
    string produccion;
    archivo.open(ubicacionEntrada, ios::in); //abrimos en modo lectura
    if(archivo.fail())
    {
        cout<<"Error: Problemas al abrir el archivo"<<endl;
        exit(1);
    }
    while(!archivo.eof()){                            //mientras no sea le final del archivo
        getline(archivo, produccion);                     //getline para guardar produccion por linea
        producciones.push_back(produccion);      
    }
    archivo.close();
}
//regresar las producciones para imprimirlas desde el main
vector<string> ReceptorProducciones::getProducciones(){
    return producciones;
}
