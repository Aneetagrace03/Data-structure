#include <stdio.h>
#define SIZE 5

int dequeue[SIZE];
int front = -1;
int rear = -1;

void insertFront(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("dequeue is full");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }
    dequeue[front] = value;
    printf("value inserted at front %d\n", value);
}

void insertRear(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("dequeue is full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    dequeue[rear] = value;
    printf("value inserted at rear %d\n", value);
}

void deleteFront() {
    if (front == -1) {
        printf("dequeue is empty\n");
        return;
    }
    printf("deleted from front: %d\n", dequeue[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("dequeue is empty\n");
        return;
    }
    printf("deleted from rear: %d\n", dequeue[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}


void display() {
    if (front == -1) {
        printf("dequeue is empty\n");
        return;
    }
    printf("dequeue elements ");
    int i = front;
    while (1) {
        printf("%d ", dequeue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {

    insertFront(10);
    insertFront(20);
    insertRear(100);
    insertRear(400);
    display();
    deleteFront();
    display();
    deleteRear();
    display();
    return 0;
}


