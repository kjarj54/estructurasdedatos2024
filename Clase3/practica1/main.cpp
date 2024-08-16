#include "list.h"

int main(int argc, char const *argv[])
{
    list *l = new list();
    l->insertar(1);
    l->insertar(2);
    l->insertar(3);
	
	l->verlist();
	
	l->borrar(1);
	
	l->verlist();
	
    return 0;
}
