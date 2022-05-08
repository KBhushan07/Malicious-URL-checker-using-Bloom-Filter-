// For strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 5

char arr1[20][size] = {"http.sddk.com","http.rummy.com","http.op.com","lokj","hheelo"};
int arr2[10];

int hash1(char *x){
    int hash = 7*strlen(x)%10;
    return hash;
}

int hash2(char *x){
    int hash = strlen(x)*strlen(x)%10;
    return hash;
}

int main(){
    
    for(int i=0; i<size; i++){
        int a = hash1(&arr1[i]);
        arr2[a] = 1 ;
        int b = hash2(&arr1[i]);
        arr2[b] = 1 ;
    }
    
    char nam;
    printf("Enter element to be searched : ");
    scanf("%s", &nam);
    int a = hash1(&nam);
    int b = hash2(&nam);
    if(arr2[a]==1 && arr2[b]==1){
        printf("Probaly Present ,let's check for surity");
        
    }
    else{
        printf("Definitely Not Present");
    }
    return 0;
}
