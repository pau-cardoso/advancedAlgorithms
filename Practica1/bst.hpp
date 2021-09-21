#include <iostream>

using namespace std;

/**
 * @class Node
 * @brief Clase para representar cada nodo dentro del arbol binario
*/
class Node
{
public:
int data;
    Node *left;
    Node *right;
    Node *ancestor;

    //Métodos get
    int getData() { return this->data; }
    Node *getLeft() { return this->left; }
    Node *getRight() { return this->right; }
    Node *getAncestor() { return this->ancestor; }
    //Métodos set
    void setData(int data) { this->data = data; }
    void setLeft(Node *left) { this->left = left; }
    void setRight(Node *right) { this->right = right; }
    void setancestor(Node *ancestor) { this->ancestor = ancestor; }
    //Otros metodos
    static void imprimirInOrder(Node *actual);
    static void imprimirPreOrder(Node *actual);
    static void imprimirPostOrder(Node *actual);
    static Node *dataMenor(Node *actual);
    static Node *dataMayor(Node *actual);

    //Constructor
    Node(Node *ancestor, int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->ancestor = ancestor;
    }

    //Destructor (delete)
    ~Node() {}
};

/**
 * Imprime el arbol a partir de un nodo dado con un recorrido InOrder
 * @note La complejidad es de O(n)
 * @param actual Nodo a partir del cual se quiere imprimir el resto del arbol
*/
void Node :: imprimirInOrder(Node *actual) {
    if (!actual)
        return;
    else {
        imprimirInOrder(actual->left);
        cout << actual->data << " ";
        imprimirInOrder(actual->right);
    }
}

/**
 * Imprime el arbol a partir de un nodo dado con un recorrido PreOrder
 * @note La complejidad es de O(n)
 * @param actual Nodo a partir del cual se quiere imprimir el resto del arbol
*/
void Node :: imprimirPreOrder(Node *actual) {
    if (!actual)
        return;
    else {
        cout << actual->data << " ";
        imprimirPreOrder(actual->left);
        imprimirPreOrder(actual->right);
    }
}

/**
 * Imprime el arbol a partir de un nodo dado con un recorrido PostOrder
 * @note La complejidad es de O(n)
 * @param actual Nodo a partir del cual se quiere imprimir el resto del arbol
*/
void Node :: imprimirPostOrder(Node *actual) {
    if (!actual)
        return;
    else {
        imprimirPostOrder(actual->left);
        imprimirPostOrder(actual->right);
        cout << actual->data << " ";
    }
}


/**
 * @class BST
 * @brief Binary Search Tree, clase para un arbol binario
*/
class BST {

    public:
        Node *root;

        // Métodos get
        Node *getRoot() { return this->root; }
        // Métodos set
        void setRoot(Node *root) { this->root = root; }
        // Otros metodos
        void agregaNodoIterativo(int data);
        Node *buscarNodo(int data);
        void imprimirArbolInOrder();
        void imprimirArbolPreOrder();
        void imprimirArbolPostOrder();
        void eliminarNodo(int data);
        int height();
        int whatLevelAmI(int data);
        Node* antecesor(int data);

        // Método constructor
        BST() {
            this->root = nullptr;
        }
        // Metodo destructor
        ~BST() {}
};

/**
 * Agrega un nuevo nodo al arbol en la posicion segun el data que se desea agregar
 * @param data data que se desea agregar
*/
void BST :: agregaNodoIterativo(int data) {
    Node *actual = this->root;
    Node *ancestor;
    //Arbol vacío
    if (!this->root) {
        this->root = new Node(nullptr, data);
        return;
    }
    if (!this->buscarNodo(data)) {
        //Árbol con dataes
        //Encontrar al nodo ancestor
        while (actual) {
            ancestor = actual;
            if (data < actual->getData()) //Determina la relación de orden
                actual = actual->getLeft();
            else
                actual = actual->getRight();
        }
        if (data < ancestor->getData()) //El elemento es menor que el ancestor
            ancestor->setLeft(new Node(ancestor, data));
        else
            ancestor->setRight(new Node(ancestor, data));
    }
    else
        cout << "data repetido" << endl;
}

/**
 * Busca el data dado como parametro en algun nodo del arbol
 * @param data data a buscar dentro del arbol
 * @return El nodo con el data buscado
*/
Node *BST :: buscarNodo(int data) {
    Node *actual = this->root;
    while (actual) {
        if (actual->getData() == data)
            return actual;
        else
            actual = actual->getData() > data ? actual->getLeft() : actual->getRight();
    }
    return nullptr;
}

/**
 * Regresará un entero que indica el nivel en que se encuentra un dato, 
 * o -1 en caso de que no se encuentre en el BST
 * @note La complejidad es de O(n)
 * @param data Dato a buscar su altura
 * @return Entero indicando el nivel del dato en el BST, o -1 si no se encuentra
*/
int BST :: whatLevelAmI(int data) {
    Node *nodo = buscarNodo(data);
    if (!nodo)
        return -1;
    else {
        int cont = 0;
        while (nodo->getAncestor()) {
            cont++;
            nodo = nodo->getAncestor();
        }
    return cont;
    }
}

/**
 * Imprime el arbol completo de forma InOrder
*/
void BST :: imprimirArbolInOrder() {
    Node::imprimirInOrder(this->root);
    cout << endl;
}

/**
 * Imprime el arbol completo de forma PreOrder
*/
void BST :: imprimirArbolPreOrder() {
    Node::imprimirPreOrder(this->root);
    cout << endl;
}

/**
 * Imprime el arbol completo de forma PostOrder
*/
void BST :: imprimirArbolPostOrder() {
    Node::imprimirPostOrder(this->root);
    cout << endl;
}