#include <cstdio>

using namespace std;

/*
    Algoritmo: Binary Search Tree

    BST(node n, data)
        node p = n;
        while p != null do
            if(p.data == data) then
                return true
            else if(data <= p.data) then
                p = p.left
            else
                p = p.right
        return false
    end

*/

struct Nodo{
    int dato;
    Nodo *left;
    Nodo *right;
};

Nodo *GetNewNode(int data){
    Nodo *newNodo = new Nodo();
    newNodo->dato = data;
    newNodo->left = newNodo->right = NULL;
    return newNodo;
}

Nodo *Insert(Nodo* root, int dato){
    if(root == NULL)//esta vacio
        root = GetNewNode(dato);
    else if(dato <= root->dato)//se inserta a la izq
        root->left = Insert(root->left,dato);
    else
        root->right = Insert(root->right,dato);
    return root;
}

bool Search(Nodo* root,int dato){
    /*if(root == NULL)
        return false;
    else if(root->dato == dato)
        return true;
    else if(dato <= root->dato)//esta a la izq
        Search(root->left,dato);
    else//esta a a der
        Search(root->right,dato);*/

    while(root != NULL){
        if(root->dato == dato)
            return true;
        else if(dato <= root->dato)//esta a la izq
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

int main()
{
    Nodo *root = NULL;
    bool find;
    int N[6] = {15,10,20,25,8,12};

    for(int i = 0; i < 6; i++)
        root = Insert(root,N[i]);

    find = Search(root,25);

    if(find)
        printf("Encontrado\n");
    else
        printf("No Encontrado\n");

    return 0;
}
