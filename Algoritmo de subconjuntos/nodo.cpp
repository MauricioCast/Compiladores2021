#include <iostream>
#include "nodo.h"

int Nodo::getNum()
{
    return this->num;
}

bool Nodo::getFinal()
{
    return this->final;
}

void Nodo::setNum(int num)
{
    this->num = num;
}

void Nodo::setFinal(bool final)
{
    this->final = final;
}