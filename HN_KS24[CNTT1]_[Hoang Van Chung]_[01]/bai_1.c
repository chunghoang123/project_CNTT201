//
// Created by FPT on 7/31/2025.
//
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 1000


typedef struct Operation {
    char action;
    char value;
}Operation;

typedef struct Stack {
    Operation data[MAX];
    int top;
}Stack;

Stack undoStack,redoStack;
char text[MAX];
int length = 0;



void push(Stack *stack, Operation operation) {
    if (stack->top<MAX-1) {
        stack->data[++stack->top] = operation;
    }
}
Operation pop (Stack *stack) {
    if (stack->top>=0) {
        return stack->data[stack->top--];
    }
    Operation nullop = {'N','\0'};
    return nullop;
}


int isEmpty(Stack *stack) {
    return stack->top == -1;
}
void insertChar(char c) {
    text[length++] = c;
    text[length] = '\0';
    Operation operation = {'I',c};
    push(&undoStack,operation);
    redoStack.top = -1;
    printf("Nhap thanh cong\n");
}

void undo() {
    if (!isEmpty(&undoStack)) {
        Operation operation =pop(&undoStack);
       if (operation.action == 'I') {
           length--;
           text[length] = '\0';
           push(&redoStack,operation);
       }
    }
}

void redo() {
    if (!isEmpty(&redoStack)) {
        Operation operation =pop(&redoStack);
        if (operation.action == 'I') {
            text[length++] = operation.value;
            text[length] = '\0';
            push(&undoStack,operation);
        }
    }
}
void display() {
    printf("Current :%s\n",text);

}

int main() {
    undoStack.top = -1;
    redoStack.top = -1;
    int choice;
    char c;
    do {
        printf("___________________MENU_____________________\n");
        printf("1. Insert Char\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Nhap lua chon: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
               printf("nhap ky tu: ");
                getchar();
                scanf("%c",&c);
                insertChar(c);
                break;
            case 2:
                undo();
                break;
            case 3:
                redo();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Ket thuc chuong trinh\n");
                break;
            default:
                printf("Nhap sai moi nhap lai\n ");

        }
    }while(choice!=5);
}















