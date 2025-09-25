#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 100

typedef struct Node {
    char url[MAX_URL_LEN];
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct Browser {
    Node *current;
} Browser;

Node* createNode(const char *url) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strncpy(newNode->url, url, MAX_URL_LEN);
    newNode->url[MAX_URL_LEN - 1] = '\0';
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void visit(Browser *browser, const char *url) {
    Node *newNode = createNode(url);
   
    if (browser->current != NULL) {
       
        Node *temp = browser->current->next;
        while (temp != NULL) {
            Node *toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        browser->current->next = NULL;
       
        newNode->prev = browser->current;
        browser->current->next = newNode;
    }
   
    browser->current = newNode;
    printf("Visited: %s\n", url);
}

void goBack(Browser *browser) {
    if (browser->current == NULL || browser->current->prev == NULL) {
        printf("Cannot go back\n");
    } else {
        browser->current = browser->current->prev;
        printf("Moved back to: %s\n", browser->current->url);
    }
}

void goForward(Browser *browser) {
    if (browser->current == NULL || browser->current->next == NULL) {
        printf("Cannot go forward\n");
    } else {
        browser->current = browser->current->next;
        printf("Moved forward to: %s\n", browser->current->url);
    }
}

void displayCurrentPage(Browser *browser) {
    if (browser->current == NULL) {
        printf("No page visited yet\n");
    } else {
        printf("Current Page: %s\n", browser->current->url);
    }
}

void freeBrowserHistory(Browser *browser) {
    if (browser->current == NULL) return;
   
 
    while (browser->current->prev != NULL) {
        browser->current = browser->current->prev;
    }
   
    Node *temp = browser->current;
    while (temp != NULL) {
        Node *toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
    browser->current = NULL;
}

int main() {
    Browser browser;
    browser.current = NULL;
   
    int choice;
    char url[MAX_URL_LEN];
   
    while (1) {
        printf("\nBrowser Menu:\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
       
        if (scanf("%d", &choice) != 1) {
         
            while (getchar() != '\n');
            printf("Invalid input, please enter a number between 1 and 5.\n");
            continue;
        }
       
        switch (choice) {
            case 1:
                printf("Enter URL to visit: ");
                scanf("%s", url);
                visit(&browser, url);
                break;
            case 2:
                goBack(&browser);
                break;
            case 3:
                goForward(&browser);
                break;
            case 4:
                displayCurrentPage(&browser);
                break;
            case 5:
                printf("Exiting Browser\n");
                freeBrowserHistory(&browser);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
   
    return 0;
}
