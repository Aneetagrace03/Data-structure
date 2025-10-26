#include <stdio.h>
#define max 100

int queue[max];
int front = 0, rear = -1;
int visited[max];


void enqueue(int vertex) {
    rear++;
    queue[rear] = vertex;
}

int dequeue() {
    int vertex = queue[front];
    front++;
    return vertex;
}


int isEmpty() {
    return front > rear;
}


void BFS(int adj[max][max], int n, int start) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;  

    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}
int main(){
    int n,start,adj[max][max];
    printf("enter the number of vertices");
    scanf("%d",&n);
    printf("enter the adjecency matrix");
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&adj[i][j]);
    }
}
printf("enter sarting vertex (0 to %d):",n-1);
    scanf("%d",&start);
for(int i=0;i<n;i++){
visited[i]=0;}

BFS(adj,n,start);
return 0;}