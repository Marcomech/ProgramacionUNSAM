#define MAX_NODOS 100

typedef struct Nodo
{
    int dato;
    int proxNodo; // Índice del proxNodo nodo en el array
} Nodo;

typedef struct ListaEnlazada
{
    Nodo nodos[MAX_NODOS];
    int primerNodo;
    int tamaño;
} ListaEnlazada;

void initLista(ListaEnlazada *lista);
void insLast(ListaEnlazada *lista, int dato);
void insFirst(ListaEnlazada *lista, int dato);
void delValue(ListaEnlazada *lista, int dato);
void showFull(ListaEnlazada *lista);
void showFirst(ListaEnlazada *lista);
void showLast(ListaEnlazada *lista);
void delFirst(ListaEnlazada *lista);
void delLast(ListaEnlazada *lista);