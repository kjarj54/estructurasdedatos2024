#include <iostream>
using namespace std;

class nodo
{
private:
    int n;
    nodo *sig; 
    nodo *ant;

public:
    nodo();
    nodo(int n, nodo *sig, nodo *ant);
    void setN(int n);
    int getN();
    void setSig(nodo *sig);
    nodo *getSig();
    void setAnt(nodo *ant);
    nodo *getAnt();
};
