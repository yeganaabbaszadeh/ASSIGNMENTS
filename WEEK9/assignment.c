#include<stdio.h>

void function(char *source, char *integers, char *nonintegers){

    int i = 0;
    int intI = 0;
    int nonintI = 0;

    for( ; source[i] != '\0'; i++){
        if(source[i] >= 48 && source[i] <= 57){
            integers[intI]=source[i];
            intI++;
        }
        else{
            nonintegers[nonintI]=source[i];
            nonintI++;
        }

        integers[intI] = '\0';
        nonintegers[nonintI] = '\0';
    }   

}


int main(){

    char someString[] = "aBc123DeF456!=";
    char intvalues[256];
    char nonintvalues[256];

    printf("Original string:%s\n", someString);
    function(someString, intvalues, nonintvalues);
    printf("Integers:%s\t Nonintegers:%s\n", intvalues, nonintvalues);

    return 0;
}

