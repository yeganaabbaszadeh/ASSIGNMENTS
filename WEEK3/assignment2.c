#include "stdio.h"

void swapStrings(char **destination, char **source);           

int main(){
	char *str1 = "Programming";	    // define and initialize str1
    char *str2 = "C language";		// define and initialize str2

    printf("Before swap: \n");
	printf("str1: %s, str2: %s\n",str1,str2);
    
	swapStrings(&str1,&str2);
    
	printf("After swap: \n");
	printf("str1: %s, str2: %s\n",str1,str2);

    return 0;
}

void swapStrings(char **destination, char **source){
	
	char *temp = *destination;
	*destination = *source;
	*source = temp;
}

