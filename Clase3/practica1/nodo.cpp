#include "nodo.h"

nodo::nodo()
{
    n = 0;
    sig = NULL;
    ant = NULL;
}

nodo::nodo(int n, nodo *sig, nodo *ant)
{
    this->n = n;
    this->sig = sig;
    this->ant = ant;
}

void nodo::setN(int n)
{
    this->n = n;
}

int nodo::getN()
{
    return n;
}

void nodo::setSig(nodo *sig)
{
    this->sig = sig;
}

nodo *nodo::getSig()
{
    return sig;
}

void nodo::setAnt(nodo *ant)
{
    this->ant = ant;
}

nodo *nodo::getAnt()
{
    return ant;
}
