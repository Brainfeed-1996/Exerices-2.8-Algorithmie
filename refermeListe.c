#include <stdio.h>
#include <stdlib.h>

// Définition de la structure du nœud
struct Node {
    int data;
    struct Node* next;
};

// Fonction pour créer un nouveau nœud
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour transformer une liste linéaire en liste circulaire
void makeCircular(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head; // Relier le dernier nœud au premier
}

// Fonction pour afficher la liste (pour vérifier)
void printList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("%d (head)\n", head->data); // Pour montrer que la liste est circulaire
}

int main() {
    // Création d'une liste simplement chaînée linéaire
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Transformation en liste circulaire
    makeCircular(head);

    // Affichage de la liste circulaire
    printList(head);

    return 0;
}
