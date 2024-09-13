//Hacer un funcion recursiva que invierte el arbol
#include <iostream>

using namespace std;

struct NodeTree{
    int data;
    NodeTree *left;
    NodeTree *right;
};

void insert(NodeTree *&tree, int data){
    if(tree == NULL){
        tree = new NodeTree;
        tree->data = data;
        tree->left = NULL;
        tree->right = NULL;
    }else{
        if(data < tree->data){
            insert(tree->left, data);
        }else{
            insert(tree->right, data);
        }
    }
}



int main(int argc, char const *argv[])
{
    
    return 0;
}
