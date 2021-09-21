#include <iostream>
#include "bst.hpp"

using namespace std;

Node *lca(Node *root, int v1,int v2) {

    Node *padre = nullptr; // Para rastrear al padre del nodo actual
	int menor, mayor; // saber cual es menor y mayor
    int nodeData = root->data; // valor del nodo raiz

    // Se define cual valor es el menor o mayor 
    if (v1 < v2) {
        menor = v1;
        mayor = v2;
    } else {
        menor = v2;
        mayor = v1;
    }
    
    // Recorre el arbol para buscar al LCA
    while (root) {
        cout << "raiz actual: " + to_string(root->getData()) << endl;
        //cout << "padre: " + to_string(padre->getData()) << endl;
        cout << "menor: " + to_string(menor) << endl;
        cout << "mayor: " + to_string(mayor) + "\n" << endl;

        if (menor < nodeData && 
            mayor < nodeData && 
            root->getLeft()->getData() != mayor &&
            root->getLeft()->getData() != menor) {

            padre = root;
            root = root->left;
            nodeData = root->data;
        }
        else if (menor > nodeData && 
                mayor > nodeData &&
                root->getRight()->getData() != menor &&
                root->getRight()->getData() != mayor) {
            padre = root;
            root = root->right;
            nodeData = root->data;
        } 
        else {
            break;
        }
    }
    return root;
}

int main(){
    BST * arbol=new BST(); // Creacion de un nuevo arbol binario
    int opcion, valNodo, predecesor;
    Node * node;
    
    // Se agregan nodos al arbol
    // arbol->agregaNodoIterativo(8);
    // arbol->agregaNodoIterativo(4);
    // arbol->agregaNodoIterativo(2);
    // arbol->agregaNodoIterativo(1);
    // arbol->agregaNodoIterativo(3);
    // arbol->agregaNodoIterativo(6);
    // arbol->agregaNodoIterativo(5);
    // arbol->agregaNodoIterativo(7);
    // arbol->agregaNodoIterativo(10);
    // arbol->agregaNodoIterativo(14);
    // arbol->agregaNodoIterativo(15);
    // arbol->agregaNodoIterativo(9);
    // arbol->agregaNodoIterativo(12);
    // arbol->agregaNodoIterativo(11);
    // arbol->agregaNodoIterativo(13);
    // arbol->imprimirArbolPreOrder();
    
    
    arbol->agregaNodoIterativo(8);
    arbol->agregaNodoIterativo(4);
    arbol->agregaNodoIterativo(9);
    arbol->agregaNodoIterativo(1);
    arbol->agregaNodoIterativo(2);
    arbol->agregaNodoIterativo(3);
    arbol->agregaNodoIterativo(6);
    arbol->agregaNodoIterativo(5);
    arbol->imprimirArbolPreOrder();

    node = lca(arbol->getRoot(), 1, 2);
    cout << "Resultado:  " + to_string(node->getData()) << endl;

    
    cout << endl;
    
    return 0;
}