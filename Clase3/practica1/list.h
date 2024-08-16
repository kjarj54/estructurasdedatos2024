#include "nodo.h"

class list
{
private:
    nodo *ini;

public:
    list();
    list(nodo *i);
    void verlist();
    void insertar(int n);
    bool buscar(int n);
    void borrar(int n);
    ~list();
};
