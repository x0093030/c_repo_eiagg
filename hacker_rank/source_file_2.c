#include "header_file_2.h"

#define PI 3.1416
float suma;
int aaa,bbb;

int function2(){
 	int x=10;
 	suma = PI + x;
 	printf("Enter 2 different numbers: \n");
 	scanf("%i  %i",&aaa, &bbb);
 	
 	printf("\nTotal is: %f", suma);
	return 0;
}
