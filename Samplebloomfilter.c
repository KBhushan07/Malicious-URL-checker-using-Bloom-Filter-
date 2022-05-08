// For integers
#include <stdio.h>
#include <stdlib.h>
#define size 5

int arr1[size] = {23,14,34,12,29};
int arr2[10];

int hash1(int x){
    int hash = (x*x)%10;
    return hash;
}

int hash2(int x){
    int hash = (x*x*x)%10;
    return hash;
}

int main(){
    
    for(int i=0; i<size; i++){
        int a = hash1(arr1[i]);
        arr2[a] = 1 ;
        int b = hash2(arr1[i]);
        arr2[b] = 1 ;
    }
    
    int num;
    printf("Enter element to be searched : ");
    scanf("%d", &num);
    int a = hash1(num);
    int b = hash2(num);
    if(arr2[a]==1 && arr2[b]==1){
        printf("Probaly Present");
    }
    else{
        printf("Definitely Not Present");
    }
    return 0;
}

