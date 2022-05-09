//hash 1 = finding length of the string
//hash 2 = finding value of the string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE* ptr;
	char str[50];
	ptr = fopen("file.txt", "a+");
	if (NULL == ptr) {
		printf("file can't be opened \n");
	}
	printf("content of this file are \n");
	while (fgets(str, 50, ptr) != NULL) {
		printf("%s", str);
		int s=0;
		for(int i=0; i<strlen(str); i++){
		    s = s + str[i];
		}
		printf("%d ",s);
		printf("%ld\n",strlen(str));
	}
	fclose(ptr);
	return 0;
}
