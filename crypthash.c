#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypthash.h"

//reallocating the array
int* reAlloc(int *ptr , int size){
    ptr = (int*)realloc( ptr , size*sizeof(int));
    
    if(ptr==NULL){
        return NULL;
    }
    return ptr ;
    
}


//converting string of three characters into octal value of 9 digit
//string -> ascii -> octal
int octal_conv(int x , int i){
    int p = 0 , q = 1;
    while(x != 0){
        p = p + (x % 8) * q;
        x = x / 8;
        q = q * 10;
    }
    
    if(i%3==0){
        return p*1000000;
    }
    else if(i%3==1){
        return p*1000;
    }
    else{
        return p;
    }
}


//left rotation 
int left_rotate(int x , int y){
    x = x >> y ;
    
    if(x<0){
        x = -x;
    }
    
    if(x>100000000){
        x = x % 100000000;
    }
    
    return x;
}


//right rotation
int right_rotate(int x , int y){
    x = x << y ;
    
    if(x<0){
        x = -x;
    }
    
    if(x>100000000){
        x = x % 100000000;
    }
    
    return x;
}


//squaring each number and adding
int squared(int x){
        int s = 0;
        int q , r;
        
        while(x!=0){
            q = x%10;
            r = x/10;
            s = s + q*q;
            x = r;
        }
        
    return s;
}


//getting the final hash value
int get_hash(int x , int prevhash){
    if(prevhash==0){
        prevhash = 927157137;
    }
    
    int m = squared(x);
    int y = x & 1729 ^ m;
    int z = x ^ prevhash;
    x = left_rotate(y , 7) |  right_rotate(z , 11);
    x = ~x ;
    
    if(x<0){
        x = -x;
    }
    
    if(x>100000000){
        x = x % 100000000;
    }
    
    return x;
}


//will break string into block of three characters and will find hash value
int calc_hash(char* ch){
    if(strlen(ch)==1){
        return get_hash(octal_conv(ch[0] , 0) , 0);
    }
    
    else if(strlen(ch)==2){
        return get_hash(octal_conv(ch[0] , 0)+octal_conv(ch[1] , 1) , 0);
    }
    
    else{
        int h = 0;
        for(int i=0; i<strlen(ch); i=i+3){
            int a = octal_conv(ch[i], i);
            int b = octal_conv(ch[i+1], i+1);
            int c = octal_conv(ch[i+2], i+2);
            h = get_hash(a+b+c , h);
        }
        
        if(h<0){
            h = -h ;
        }
        
        if(h<1000000){
            h = 100000000 - h ;
        }
        
        if(h>100000000){
            h = h%100000000;
        }
        
        
    return h ;
    }
    
}

/*void set_array(int*ptr , int x){
    ptr[x] = 1;
    return ;
}*/



/*void cryptographic_func(char*ch , int* arr){

    arr = (int*)reAlloc(arr , 100000000);
    
    FILE* fp = fopen("file.txt","r");
    if(fp == NULL){
        perror("Unable to open");
        exit(1);
    }
    
    printf("hello");
    char lin[300];

    while (fgets(lin, 300 , fp) != NULL) {
    	lin[strcspn(lin, "\n")] = 0;
    	int a = calc_hash(lin);
        arr[a] = 1 ;
    }
    printf("hello");
    int a = calc_hash(ch);
    if(arr[a]==1){
        printf("Site is malicious");
    }
    else{
        printf("Site is safe");
    }
    fclose(fp);
}*/
