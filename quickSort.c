#include<stdio.h>
void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high){
    int pinot=arr[high];
    int i=(low-1);
    for(int  j=low;j<high;j++){
        if(arr[j]<pinot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
swap(&arr[i+1],&arr[high]);
return i+1;
}
void quickSort(int arr[],int low,int high){
    if(low<high){
     int pi = partition(arr, low, high);
quickSort(arr,low,pi-1);
      quickSort(arr,pi+1,high);
    }
}
int main(){
    int arr[100], i,n;
printf("enter the no of elements in the array");
scanf("%d",&n);
printf("enter the elements");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
quickSort(arr,0,n-1);
for(i=0;i<n;i++){
printf("\n%d",arr[i]);
}
return 0;

}