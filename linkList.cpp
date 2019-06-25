#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int inf;
    struct Node* next;    
} Node;

void append(Node** head, int inf);
void push(Node** head, int inf);
void insertAfter(Node* prev_node, int inf);
void printList(Node* head);
void deleteNodekey(Node** head, int key);
void deleteNodepos(Node** head, int pos);
void dellinkList(Node** head);

//append node
void append(Node** head, int inf){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->inf = inf;
    new_node->next = NULL;
    Node* cur_node = *head;

    if(*head == NULL){
        (*head) = new_node;
        return;
    }
    else
    {
        while(cur_node->next != NULL){
            cur_node = cur_node->next;
        }
        cur_node->next = new_node;
    }
}


void push(Node** head, int inf){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->inf = inf;
    new_node->next = (*head);
    (*head) = new_node;
}

void insertAfter(Node* prev_node, int inf){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->inf = inf;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void printList(Node* head){
    Node* new_node = head;
    printf("\nList here !\n");
    while(new_node != NULL){
        printf("%d \t", new_node->inf);
        new_node = new_node->next;
    }
}

void deleteNodekey(Node** head, int key){
    Node* tmp = *head;
    Node* prev;
    if(tmp != NULL && tmp->inf == key){
        *head = tmp->next;
        free(tmp);
        return;
    }

    while (tmp != NULL && tmp->inf != key)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp == NULL) return;
    prev->next = tmp->next;
    free(tmp);
}


void deleteNodepos(Node** head, int pos){
    Node* tmp = *head, *prev;
    
    if(pos == 1){
        *head = tmp->next;
        free(tmp);
        return;
    }

    int count = 1;
    while(tmp != NULL && count != pos){
        prev = tmp;
        tmp = tmp->next;
        count++;
    }
    if(tmp == NULL) return;

    prev->next = tmp->next;
    free(tmp);
}

void dellinkList(Node** head){
    Node *tmp = *head, *node;
    while(tmp != NULL){
        node = tmp->next;
        free(tmp);
        tmp = node;
    }
    *head = NULL;
}


bool search(Node* head, int key){
    Node* cur_node = head;
    while(cur_node != NULL){
        if(cur_node->inf == key)
            return true;
        cur_node = cur_node->next;
    }
    return false;
}


int main(){
    Node* head = NULL;
    append(&head, 4);

    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);

    insertAfter(head->next, 10);
    printList(head);

    deleteNodekey(&head, 8);
    printList(head);
    
    deleteNodepos(&head, 1);
    printList(head);
    
    // dellinkList(&head);
    // printList(head);
    
    search(head, 5)?printf("\nYes"):printf("\nNO");
    printf("\n");
    return 0;
}