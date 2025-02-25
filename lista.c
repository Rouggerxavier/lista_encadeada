#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} LinkedList;

// 1. Criar lista vazia
LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// 2. Verificar se a lista está vazia
int isEmpty(LinkedList* list) {
    return list->size == 0;
}

// 3. Obter o tamanho da lista
int getSize(LinkedList* list) {
    return list->size;
}

// 4. Obter/modificar o valor de uma posição
int getElement(LinkedList* list, int pos) {
    if (pos < 1 || pos > list->size) {
        printf("Posição inválida!\n");
        return -1;
    }
    Node* temp = list->head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    return temp->data;
}

void setElement(LinkedList* list, int pos, int value) {
    if (pos < 1 || pos > list->size) {
        printf("Posição inválida!\n");
        return;
    }
    Node* temp = list->head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    temp->data = value;
}

// 5. Inserir elemento em uma posição
void insertElement(LinkedList* list, int pos, int value) {
    if (pos < 1 || pos > list->size + 1) {
        printf("Posição inválida!\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (pos == 1) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node* temp = list->head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    list->size++;
}

// 6. Retirar elemento de uma posição
void removeElement(LinkedList* list, int pos) {
    if (pos < 1 || pos > list->size) {
        printf("Posição inválida!\n");
        return;
    }
    Node* temp = list->head;
    if (pos == 1) {
        list->head = temp->next;
        free(temp);
    } else {
        Node* prev = NULL;
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
    list->size--;
}

// 7. Imprimir elementos da lista
void printList(LinkedList* list) {
    if (isEmpty(list)) {
        printf("A lista está vazia.\n");
        return;
    }
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Testes
int main() {
    LinkedList* list = createList();
    
    printList(list);
    
    insertElement(list, 1, 10);
    insertElement(list, 2, 20);
    insertElement(list, 3, 30);
    printList(list);
    
    printf("Elemento na posição 2: %d\n", getElement(list, 2));
    setElement(list, 2, 25);
    printList(list);
    
    removeElement(list, 1);
    printList(list);
    
    printf("Tamanho da lista: %d\n", getSize(list));
    
    return 0;
}
