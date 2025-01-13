#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 1000

typedef struct node {
    char* data;
    struct node* next;
} Node;

Node *create(char* data){
    Node *result = (Node*)malloc(sizeof(Node));
    result->data = strdup(data);
    result->next = NULL;
    return result;
}

void printlist(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

int main(){
    char word[MAX_WORD_LENGTH];
    Node *head = NULL;
    while(1){
        scanf("%s", word);
        if(strcmp(word,"END") == 0){
            break;
        }
        Node* newNode = create(word);
        newNode->next = head;
        head = newNode;
    }
    printlist(head);

    Node* current = head;
    while(current != NULL){
        Node* next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    return 0;
}