#include<stdio.h>
#include<ctype.h>
char stack[100];
int top=-1;
void push(char x){
    stack[++top]=x;
}
char pop(){
    if(top==-1){
        return 0;
    }
    else{
     return   stack[top--];
    }
}
int precedance(char x){
    if(x=='(')
    return 0;
    if(x =='+'|| x=='-')
    return 1;
    if(x=='*'||x=='/')
    return 2;
    return 0;
}
int main(){
    char exp[100];
    char *e,x;
    printf("enter the expression");
    scanf("%c",&exp);
    printf("\n");
    e=exp;
    while(*e!='\0'){
        if(isalnum(*e))
        printf("%c",*e);
        if(*e=='(')
        push(*e);
        else if(*e==')'){
            while((x== pop()) != '(')
            printf("%s",x);

        }
        while(precedance(stack[top]>=precedance(*e))){
        printf("%c",pop());
        push(*e);
    }
    e++;}   
    while(top!=-1){
        printf("%c",pop());

    }return 0;
}


