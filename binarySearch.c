#include<stdio.h>
int binarySearch(int arr[],int n,int key){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }

    }
            return -1;
}
int main(){
    int arr[]={20,23,30,33,45,90};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key;
    printf("enter the value to search");
    scanf("%d",&key);
    int result=binarySearch(arr,n,key);
    if(result!=-1){
        printf("elent found at %d",result);
            int space_main=sizeof(key)+sizeof(n)+sizeof(arr);
    int space1=sizeof(int)*3;
    int space2=space_main+space1;
    printf("%d",space2);
   

    }
    else{
        printf("element not found");
       
    
    int space_main=sizeof(key)+sizeof(n)+sizeof(arr);
    int space1=sizeof(int)*3;
    int space2=space_main+space1;
    printf("%d",space2);}
   
}