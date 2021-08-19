#include <iostream>
#include "bst.hpp"

using namespace std;

Node *lca(Node *root, int v1,int v2) {
	int menor, mayor;
    int nodeData = root->getData();
    if (v1 < v2) {
        menor = v1;
        mayor = v2;
    } else {
        menor = v2;
        mayor = v1;
    }
    if (menor < nodeData && mayor < nodeData)
    {
        lca(root->getleft(), v1, v2);
    }
    else if (menor > nodeData && mayor > nodeData)
    {
        lca(root->getDer(), v1, v2);
    } 
    else {
        return root;
    }
}

int main(){
    BST * arbol=new BST(); // Creacion de un nuevo arbol binario
    int opcion, valNodo, predecesor;
    Node * node;
    
    // Se agregan nodos al arbol
    arbol->agregaNodoIterativo(1);
    arbol->agregaNodoIterativo(2);
    arbol->agregaNodoIterativo(3);
    arbol->agregaNodoIterativo(4);
    arbol->agregaNodoIterativo(5);
    arbol->agregaNodoIterativo(6);
    arbol->agregaNodoIterativo(7);
    arbol->imprimirArbolInOrder();

    node = lca(arbol->getRoot(), 4, 6);
    cout << "Resultado: " + node->getData() << endl;

    
    cout << endl;
    
    return 0;
}