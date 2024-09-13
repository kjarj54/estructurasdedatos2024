#include <iostream>

using namespace std;

struct NodeTree
{
    int data;
    NodeTree *left;
    NodeTree *right;
};

struct NodeTreeSum{
    int data;
    NodeTreeSum *left;
    NodeTreeSum *right;
    int suma;
};

void insertarArbol(NodeTree *&t, int x)
{
    if (t == NULL)
    {
        t = new NodeTree;
        t->data = x;
        t->left = NULL;
        t->right = NULL;
    }
    else
    {
        NodeTree *aux = t;
        while (true)
        {
            if (x < aux->data)
            {
                if (aux->left == NULL)
                {
                    aux->left = new NodeTree;
                    aux->left->data = x;
                    aux->left->left = NULL;
                    aux->left->right = NULL;
                    break;
                }
                else
                {
                    aux = aux->left;
                }
            }
            else
            {
                if (aux->right == NULL)
                {
                    aux->right = new NodeTree;
                    aux->right->data = x;
                    aux->right->left = NULL;
                    aux->right->right = NULL;
                    break;
                }
                else
                {
                    aux = aux->right;
                }
            }
        }
    }
}

void preOrder(NodeTree *tree){
    if (tree != NULL)
    {
        cout << tree->data << "->";
        preOrder(tree->left);
        preOrder(tree->right);
    } 
}

void eliminarArbol(NodeTree *& tree, int x){
    if (tree == NULL)
    {
        return;
    }else if(x< tree->data){
        eliminarArbol(tree->left, x);        
    }else if(x> tree->data){
        eliminarArbol(tree->right, x);
    }else{
        NodeTree *aux = tree;
        if (tree->left == NULL && tree->right == NULL)
        {
            delete tree;
            tree = NULL;
        }else if(tree->left != NULL){
            tree = tree->left;
            delete aux;
        }else if(tree->right != NULL){
            tree = tree->right;
            delete aux;
        }
        
    }
}

int sumaArbol(NodeTree *tree, int &suma){
    
}

int main(int argc, char const *argv[])
{
    NodeTree *tree = NULL;

    insertarArbol(tree, 10);
    insertarArbol(tree, 5);
    insertarArbol(tree, 15);
    insertarArbol(tree, 3);

    cout << "Preorden: ";

    preOrder(tree);

    eliminarArbol(tree, 5);

    cout << "Preorden: ";

    preOrder(tree);
    return 0;
}