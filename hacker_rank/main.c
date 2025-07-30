/*
 ============================================================================
 Name        : C_Language.c
 Author      : Edgar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

// #include <stdio.h>
// #include <stdlib.h>
#include "header_file_2.h"

// #define PI 3.1416
volatile float sum;
volatile int a,b;

int function(); //Comes from source_file_2.c
void pointers_size();
void variable_size();
void malloc_calloc();
void struct_union();
int static_variable();
void static_variable2();
void scanf_();

int main(void) {
	//function();
	//variable_size();
	//malloc_calloc();
	struct_union();
	//static_variable2();
	//scanf_();
	return 0;
}

void scanf_(){
	char w;
	printf("Write a number:");
	scanf("%c", &w);

	printf("\nNumber entered: %c", w);
}


void static_variable2(){
	printf("\n%d ",static_variable());
	printf("\n%d ",static_variable());
	printf("\n%d ",static_variable());
	printf("\n%d ",static_variable());
}

int static_variable(){
	static int count = 0;
	count = count +1;
	return count;
}

void struct_union(){
	struct StructName{
		char a; 	//2b
		int b;		//4b
		float c;	//4b
		double d;	//8b
	};
	struct StructName str;
	str.a='A';
	printf("\nStruct size is: 0x%x bytes", sizeof(str));
	printf("\tElement of array %c", str.a);

		struct StructName2{
		char e; 	//2b
		double f;	//8b
		char g;		//2b -> padding 6b
	};
	struct StructName2 str2;
	printf("\nStruct2 size is: 0x%x bytes", sizeof(str2));

	union UnionName{
		char a;		//2b
		int b;		//4b
		float c;	//4b
		double d;	//8b
	};
	union UnionName uni;
	printf("\nUnion size is: 0x%x bvtes", sizeof(uni));
}

void malloc_calloc(){
	    // Both of these allocate the same number of bytes,
	    // which is the amount of bytes that is required to
	    // store 5 int values.

	    // The memory allocated by calloc will be
	    // zero-initialized, but the memory allocated with
	    // malloc will be uninitialized so reading it would be
	    // undefined behavior.
	    int* allocated_with_malloc = malloc(5 * sizeof(int));
	    int* allocated_with_calloc = calloc(5, sizeof(int));

	    // As you can see, all of the values are initialized to
	    // zero.
	    printf("\nValues of allocated_with_calloc:  (Zero-initialized)");
	    for (size_t i = 0; i < 5; ++i) {
	        printf("\nData %d value: 0x%x", i, allocated_with_calloc[i]);

	    }
	    printf("\n\nValues of allocated_with_malloc: (Not initialized)");
	    for (size_t i = 0; i < 5; ++i) {
	        printf("\nData %d value: 0x%x", i, allocated_with_malloc[i]);
	    }


	    // This malloc requests 1 terabyte of dynamic memory,
	    // which is unavailable in this case, and so the
	    // allocation fails and returns NULL.
	    /*int* failed_malloc = malloc(1000000000000);
	    if (failed_malloc == NULL) {
	        printf("The allocation failed, the value of "
	               "failed_malloc is: %p",
	               (void*)failed_malloc);
	    }
	     */
	    // Remember to always free dynamically allocated memory.
	    free(allocated_with_malloc);
	    free(allocated_with_calloc);
}

void variable_size(){
	char a;
	int b;
	float c;
	double d;
	short int e;
	long int f;
//	short float g;
//	long float h;
	printf("Size of char :\t\t %d Bytes\n", sizeof(a)); 	/*1B*/
	printf("Size of int :\t\t %d Bytes\n", sizeof(b)); 			/*4B*/
	printf("Size of float :\t\t %d Bytes\n", sizeof(c)); 		/*4B*/
	printf("Size of double :\t %d Bytes\n", sizeof(d)); 		/*8B*/
	printf("Size of short int :\t %d Bytes\n", sizeof(e)); 	/*2B*/
	printf("Size of long int :\t %d Bytes\n", sizeof(f)); 	/*4B*/
}

void pointers_size(){
	char* a;
	int* b;
	float* c;
	double* d;
	short int* e;
	long int* f;
	//short float* g;
	//long float* h;
	printf("Size of char pointer: %d Bytes\n", sizeof(a));
	printf("Size of int pointer: %d Bytes\n", sizeof(b));
	printf("Size of float pointer: %d Bytes\n", sizeof(c));
	printf("Size of double pointer: %d Bytes\n", sizeof(d));
	printf("Size of short int pointer: %d Bytes\n", sizeof(e));
	printf("Size of long int pointer: %d Bytes\n", sizeof(f));
}

int function(){
 	extern int x;
 	float sum=3.0;
 	sum = (int)PI + x;
 	printf("Enter 2 different numbers: \n");
 	scanf("%i  %i",&a, &b);

 	printf("\nTotal is: %f", sum);
	return 0;
}
