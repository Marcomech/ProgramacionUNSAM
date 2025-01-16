#include <stdio.h>
#include <stdlib.h>

#include "definitions.h"

int main() {
    Node *RootNode = createNode(0);

    insChild(&RootNode, 0, 10);   //           0
    insChild(&RootNode, 0, 20);   //    10           20
    insChild(&RootNode, 10, 40);  // 40   80       30
    insChild(&RootNode, 10, 80);  //        70
    insChild(&RootNode, 20, 30);  //
    insChild(&RootNode, 80, 70);  //

    printf("\n\n======================================\n");

    printf("\nArbol completo: \n");
    showFull(RootNode);

    printf("\n\n======================================\n");

    printf("\n\n");
    return 0;
}

Node *createNode(int newValue) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Error en la creacion del nodo\n");
        exit(1);
    }
    newNode->value = newValue;
    newNode->child1 = NULL;
    newNode->child2 = NULL;
    newNode->parent = NULL;
    return newNode;
}

void insChild(Node **RootNode, int parentNodeValue, int newValue) {
    if (*RootNode == NULL) {
        *RootNode = createNode(newValue);
        return;
    }

    Node *parent = searchNode(*RootNode, parentNodeValue);

    if (parent == NULL) {
        printf("Nodo padre no encontrado\n");
        return;
    }

    Node *newNode = createNode(newValue);
    newNode->parent = parent;

    if (parent->child1 == NULL)
        parent->child1 = newNode;
    else if (parent->child2 == NULL)
        parent->child2 = newNode;
    else {
        printf("El nodo %d ya tiene 2 hijos\n", parentNodeValue);
        free(newNode);
    }
}

void showFull(Node *RootNode) {
    if (RootNode == NULL)
        return;
    printf("  %d", RootNode->value);

    printBranch(RootNode->child1, 1);
    printBranch(RootNode->child2, 1);
}

Node *searchNode(Node *currentNode, int searchedValue) {
    Node *foundNode;

    if (currentNode == NULL)
        return NULL;

    if (currentNode->value == searchedValue)
        return currentNode;

    foundNode = searchNode(currentNode->child1, searchedValue);
    if (foundNode != NULL)
        return foundNode;

    foundNode = searchNode(currentNode->child2, searchedValue);
    if (foundNode != NULL)
        return foundNode;

    return NULL;
}

void printBranch(Node *currentNode, int level) {
    if (currentNode == NULL)
        return;

    printf("\n");

    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("└─%d", currentNode->value);

    printBranch(currentNode->child1, level + 1);
    printBranch(currentNode->child2, level + 1);
}
