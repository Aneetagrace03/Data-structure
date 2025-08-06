#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top != SIZE - 1) {
        stack[++top] = value;
    }
}

void pop() {
    if (top != -1) {
        top--;
    }
}

void display() {
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();    // Output: 10 20 30

    pop();
    display();    // Output: 10 20

    return 0;
}

