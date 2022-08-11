#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include"hash.h"


//hash 1 

int upTlw(char* str){
    
    int i , m = 1, n = 1 , o = 1;
    
    //Alternate lower to upper from i = 0
    for (i = 0; str[i] != '\0'; i=i+2) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        m = (i+1) * str[i] + m; 
    }
    
    
    //Alternate lower to upper from i = 1
    for (i = 1; str[i] != '\0'; i=i+2) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          str[i] = str[i] - 32;
        }
        n = (i+1) * str[i] + n;
    }
    
    
    //upper to lower and lower to upper
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        
        if (str[i] >='A' && str[i] <= 'Z'){
            str[i] = str[i] + 32 ;
        }
        
        o = (i+1) * str[i] + o; 
    }
    
    
    m = m * o + n * o + o * m * n;
    
    if(m < 0){
        m = -m;
    }
    
    if(m > 1000000){
        m = m % 1000000;
    }
    
    return m;
    
}




//hash 2


//sum of characters present in the string
int sum(char * str , int length){
    int sum = 0;
    for(int i=0; i<length; i++){
        sum = sum + str[i];
        sum = sum ^ i;
    } 
    return sum;
}


//multiplication of string character with its index number
int mult(char* str , int length){
    int s=0;
    for(int i=0; i<length; i++){
        s = s + i*str[i] ;
    }
    return s;
}


//reverse multiplication of string character with its index number
int revmult(char*str , int length){
    int s=0;
    for(int i=0; i<length; i++){
        s = s + i*str[length-i] ;
    }
    return s;
}


//multiplication of above three values
int multsumrev(char *str , int length){
    int a = mult(str , length);
    int b = sum(str , length);
    int c = revmult(str , length);
    a =  a*b*c ;
    
    if(a < 0){
        a = -a;
    }
    
    if(a > 1000000){
        a = a % 1000000;
    }
    
    return a;
    
}




//hash 3



//squaring and adding each character
int square(char*str , int length){
    int s=0;
    for(int i=0; i<length; i++){
        s = s + str[i]*str[i]*i;
    }
    return s;
}


//xoring and multiplying with string character 
int xor_mul(char*str , int length){
    int s=0;
    for(int i=0; i<length; i++){
        s = s + s ^ (i+1)*str[i];
    }
    return s;
}


//shifting the and xoring number by its ascii character  
int shifor(char*str , int length){
    int s=0;
    for(int i=0; i<length; i++){
        s = s*i ^ str[i] + s>>str[i];
    }
    return s;
}


//getting value for hash3 
int calc_hash3(char*str , int length){
    int a = square(str , length);
    int b = xor_mul(str , length);
    int c = shifor(str , length);
    a =  a * b * c ;
    
    a = a + length ;
    
    
    if(a < 0){
        a = -a;
    }
    
    if(a > 1000000){
        a = a % 1000000;
    }
    
    return a;
    
}




//hash 4



//rotating number to left
int rot1(char*str , int length){
    
    int a = 3123 ;
    int b = 0 ;
    
    for(int i = 0 ; i<length ; i++){
        b = a << 11 + str[i] + b;
    }
    
    return b ;
}


//rotating number to right
int rot2(char*str , int length){
    
    int a = 7301 ;
    int b = 0 ;
    
    for(int i = 0 ; i<length ; i++){
        b = a >> 11 + str[i] + b;
    }
    
    return b ;
}


//shifting numbers 
int func4(char*str , int length){
    
    int a = rot1(str , length);
    int b = rot2(str , length);
    int c = 0 ;
    
    while(c!=b){
        a = (a | b) >> b ;
        b = (a | b) << a ;
        c++;
    }
    
    a = a ^ b;
    
    if(a < 0){
        a = -a;
    }
    
    if(a > 1000000){
        a = a % 1000000;
    }
    
    return a;
    
}




//hash 5



//getting sum of prime numbers
int prime_sum(int x){
    
    int i , j , k , s = 0;
    
    for(j = 1; j < x; j++){
        k = 0;
        for(i = 2; i <= j/2 ; i++ ){
            if(j % i == 0){
                k = k + 1;
                break;
            }
        }
        
        if(k == 0 && j!=1){
            s = s + j;
        }
    }
    
    return s;
    
}


//getting hash value 
int func5(char* str , int length){
    
    int a = sum(str , length);
    int b = prime_sum(a);
    
    int c = (INT_MIN + b)%100 ;
    
    
    if(a < 0){
        c = -c;
    }
    
    if(c > 1000000){
        c = c % 1000000;
    }
    
    return ~c;
    
}


//hash 6


//performing various operations such as rotation , arithmetic operations etc to get unique value
int m_hash(char*str, int x){
    
    int s = 1;
    int a = rot1(str , x);
    
    for(int i=0; i<x; i++){
        int a = rot1(str , i);
        s =  ( str[i] - i ) * ( str[i] + i ) ^ a + s;
    }
    
    a = rot2(str , x);
    
    s = s|a;
    
    if(s<0){
        s = -s;
    }
    
    if(s>1000000){
        s = s%1000000 + 1234;
    }
    
    return s;
    
}


//hash 7


int n_hash(char *str , int length){

    int s=1 , c=0;
    
    if(length%2!=0){
        c=1;
    }
    
    for(int t=0; t<length/2; t++){
        s = s + (str[t] * str[length-t])*99;
    }
    
    s = ~s;
    
    if(s<0){
        s = -s;
    }

    if(s>1000000){
        s = s%1000000 + 87;
    }
    
    return s;
    
}


//hash 8


int max(char*str , int x){
    
    int m = sum(str , x);
    int n = mult(str , x);
    int o = revmult(str , x);
    int p = multsumrev(str , x);
    int q = square(str , x);
    int r = xor_mul(str , x);
    
    int a = INT_MAX ;
    
    for(int i=0; i<x; i++){
        a = a & str[i] ^ m + a;
        a = a * n + o | a ;
    }
    
    a = a^p | p^q ;
    a = a + r;
    a = ~a ;
    
    
    if(a<0){
        a = -a;
    }
    
    if(a>1000000){
        a = a%1000000 - 111;
    }
    
    return a;
}



/*void set_array(int *arr , char* ch , int length){
    
    int a = upTlw(ch);
    int b = multsumrev(ch , length);
    int c = calc_hash3(ch , length);
    int d = func4(ch , length);
    int e = func5(ch , length);

    arr[a] = 1;
    arr[b] = 1;
    arr[c] = 1;
    arr[d] = 1;
    arr[e] = 1;
    
}
*/


