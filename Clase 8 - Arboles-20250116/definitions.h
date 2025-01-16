typedef struct Node {
    int value;
    struct Node *parent;
    struct Node *child1;
    struct Node *child2;
} Node;

// Crear un nodo
Node *createNode(int newValue);

// Dado un valor, buscar el nodo con ese valor en el arbol e insertar un nodo hijo
void insChild(Node **RootNode, int ParentNodeValue, int newValue);

// Mostar el arbol completo
void showFull(Node *PrimerNode);

// Imprimir una rama en particular
void printBranch(Node *currentNode, int level);

// Encontar un nodo en particular
Node *searchNode(Node *currentNode, int searchedValue);

// Encontar un nodo en particular e imprimir su informacion
void printNodeData(Node *RootNode, int searchedValue);

// Liberar la memoria
void freeTree(Node *PrimerNode);

// Borrar una rama y liberar la memoria de todos sus hijos
void delBranch(Node *PrimerNode, int searchedValue);

// Imprimir todos los nodos que no tienen ningun hijo
void printLeafs(Node *PrimerNode);