//
// Created by FPT on 7/31/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node *insert(Node *root, int value) {
    if (root == NULL) {
        root = createNode(value);
        return root;
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }else if (value > root->data) {
        root->right = insert(root->right, value);
    }else {
        printf("gia tri da ton tai");
        return root;
    }
}
Node *find(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
Node *delete(Node *root, int value) {
    if (root == NULL) {
           return NULL;
    }
    if (value < root->data) {
        root->left = delete(root->left, value);
    }else if (value > root->data) {
        root->right = delete(root->right, value);
    }else {
        if (root->left == NULL&& root->right == NULL) {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else{
            Node* temp = find(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
    }

    }
    return root;
}
void traverse(Node *root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ",root->data);
        traverse(root->right);
    }
}

void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
int main() {
    int choice;
    Node *root = NULL;
    int value;
    do {
        printf("___________________MENU__________________\n");
        printf("1. Them gia tri\n");
        printf("2. Xoa gia tri\n");
        printf("3. Duyet gia tri\n");
        printf("4. Dem la\n");
        printf("5. Chieu cao\n");
        printf("6. Thoat\n");
        printf("nhap lua chon: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d",&value);
                root = insert(root, value);
                break;
            case 2:
                printf("Nhap gia tri can xoa: ");
                scanf("%d",&value);
                root = delete(root, value);
                break;

            case 3:
                printf("Duyet Inorder");
                traverse(root);
                printf("\n");
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("Ket thuc chuong trinh\n");
                freeTree(root);
                break;
            default:
                printf("Nhap sai moi nhap lai\n");


        }



    }while(choice!=6);
}