#include <stdlib.h>
#include <stdio.h> 

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} Node;
 
Node *create(int data){
    struct node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* node, int data){
    if(node == NULL) return create(data);
    if(data < node->data){
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
 
    return node;
}

int maxDepth(Node* node){
    if(node == NULL){
        return 0;
    } else {
        int leftSide = maxDepth(node->left);
        int rightSide = maxDepth(node->right);
        if(leftSide > rightSide){
            return leftSide+1;
        } else {
            return rightSide+1;
        }
    }
}

int main(){
    Node* root = NULL;
    int num;
    char c;
    while(scanf("%d%c",&num,&c) == 2){
        root = insert(root, num);
        if(c == '\n'){
            break;
        }
    }

    int depth = maxDepth(root);
    printf("Max Depth : %d", depth);
    return 0;
}