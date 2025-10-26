#include<stdio.h>
void insertionSort(int arr[100],int n){
int i,j,key;
for(i=1;i<n;i++){
    key=arr[i];
    j=i-1;
    while(j>=0&& arr[j]>key){
        arr[j+1]=arr[j];
        j=j-1;
    }
    arr[j+1]=key;
}
}int main(){
    int arr[100], i,n;
printf("enter the no of elements in the array");
scanf("%d",&n);
printf("enter the elements");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
insertionSort(arr,n);
for(i=0;i<n;i++){
printf("\n%d",arr[i]);
}
return 0;

}
