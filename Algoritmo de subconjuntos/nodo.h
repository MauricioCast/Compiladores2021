#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;

class Nodo
{
    private:
        int num;
        bool final;

    public:
        void setNum(int);
        void setFinal(bool);
        int getNum();
        bool getFinal();
};

#endif