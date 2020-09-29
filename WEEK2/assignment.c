#include "stdio.h"

int swap(int val1, int val2);
   
int main(){

	int a = 45;
	int b = 55;
 
	swap(a, b);
  
	return 0;
}
  
int swap(int val1, int val2){

	int temp;
  
	printf("Before swap: a:%i, b:%i \n", val1, val2);
  
	temp = val1;
	val1 = val2;
	val2 = temp;
  
	printf("After swap: a:%i, b:%i  \n", val1, val2);
  
	return 999;
} 

