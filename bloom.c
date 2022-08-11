#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include"hash.h"
#include"crypthash.h"

int main(int arc , char* argv[]){
     
    //taking input from user   
    char ch[300];
    printf("Enter site: ");
    fgets(ch, sizeof(ch), stdin);  
    printf("Entered site: ");
    puts(ch);
    
    //calculating hash value for the input
    ch[strcspn(ch, "\n")] = 0;
    int a1 = upTlw(ch);
    int b1 = multsumrev(ch , strlen(ch));
    int c1 = calc_hash3(ch , strlen(ch));
    int d1 = max(ch , strlen(ch));
    int e1 = func5(ch , strlen(ch));  
    //int f1 = m_hash(ch , strlen(ch));
    //int g1 = n_hash(ch , strlen(ch));  
        
    int *arr =(int*) malloc(sizeof(int)*1000000);
    //arr = (int*)reAlloc(arr , 100000000);
    
    char *file=(char*)malloc(sizeof(char)*50);
    strcpy(file,argv[1]);
    
    FILE* fp = fopen(file,"r");
    if(fp == NULL){
        perror("Unable to open");
        exit(1);
    }
    
    //reallocating array for cryptographic hash function
    arr = (int*)reAlloc(arr , 100000000);
    char line[300];
    int p = 0 , q = 0;
    while (fgets(line, 300 , fp) != NULL) {
    
    // reading sites from file and calculating hash values
    
    	line[strcspn(line, "\n")] = 0;
    	int a = upTlw(line);
        int b = multsumrev(line , strlen(line));
        int c = calc_hash3(line , strlen(line));
        int d = max(line , strlen(line));
        int e = func5(line , strlen(line));
       // int f = m_hash(line , strlen(line));
       // int g = n_hash(line , strlen(line));
 
        int cf = calc_hash(line);
        
        
    // setting hash values in array
            arr[a] = 1 ;
	    arr[b] = 1 ;
	    arr[c] = 1 ;
	    arr[d] = 1 ;
	    arr[e] = 1 ;
	 // arr[f] = 1 ;
	 // arr[g] = 1 ;
	    
	    arr[cf] = 1 ;
	    
	    
	// if hash value of input string collides with other site hash values p will increment
	// p will be calculating collision frequency 
	// it will give probability
	    
	    if(a1==a || b1==b || c1==c || e1==e || d1==d ){
	        p++;
	    }
	    
	 // if all hash values are equal to the calculated , we will set q 
	    if(a1==a && b1==b && c1==c && e1==e && d1==d){
	        q=1;
	    }
	   
    }
    
	fclose(fp);
	
	
	if(arr[a1]==1 && arr[b1]==1 && arr[c1]==1 && arr[e1]==1 && arr[d1]==1){
	        printf("probability after 1st level checking is %f\n" , (float)p/150);
	        int f1 = calc_hash(ch);
        
	        if(arr[f1]==1){
	            printf("After rechecking through cryptographic function , Site is found to be malicious. Site -> not secure");
	        }
        
	        else{
	            printf("After rechecking through cryptographic function , Site is found to be safe");
	        }
	    }
    
    	else{
    	    printf("Site is not found -> Safe");
    	}

    return 0;
}

