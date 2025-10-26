#include<stdio.h>
#include<stdlib.h>
struct Node{
    char data;
    struct Node *left,*right;
};
struct Node* newNode(char data){
struct Node* node=(struct Node*)malloc(sizeof(struct Node));
node->data=data;
node->left=node->right=NULL;
return node;

}
void preorder(struct Node* root){
    if(root!=NULL){
        printf("%c",root->data);
        preorder(root->left);
        preorder(root->right);

    }
}
void postorder(struct Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
           printf("%c",root->data);
    }
}
int main(){
    struct Node* root=newNode('*');
    root->left = newNode('+');
root->right = newNode('-');

root->left->left = newNode('A');
root->left->right = newNode('B');
root->right->left = newNode('C');
root->right->right = newNode('D');
 printf("Preorder (Prefix): ");
    preorder(root);

    printf("\nPostorder (Postfix): ");
    postorder(root);

    return 0;
}
