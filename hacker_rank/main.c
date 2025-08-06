/*
 ============================================================================
 Name        : C_Language.c
 Author      : Edgar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


 #include "header_file_2.h"


volatile float sum;
volatile int a,b;
#define IS_IT_PRIME_NUMBER 31

void factorial(int x);
int factorial_01(int x); // Recursive factorial function
void psudo_main01(); // Example of a pseudo main function
size_t my_strnlen(const char *s, size_t max); // Custom implementation of strnlen
void *my_memcpy(void *restrict dest, const void *restrict src, size_t count);
void palindrome(char*); // Function prototype for palindrome check)
void swap_numbers(); // Function to swap two numbers
int primo(int num); // Function to check if a number is prime
void fibonacci(int num, int, int, int); //Calculates the Fibonacci number for the parameter 'num'
int function(); //Comes from source_file_2.c
void pointers_size();
void variable_size();
void malloc_calloc();
void struct_union();
int static_variable();
void static_variable2();
void scanf_();

int main(void) {
	//factorial(FACTORIAL_NUMBER); // Example call to factorial function
	//printf("\nFactorial of %d is: %d", FACTORIAL_NUMBER, factorial_01(FACTORIAL_NUMBER)); // Example call to factorial function
	//psudo_main01(); // Example of a pseudo main function
	//palindrome("radar"); // Example call to palindrome function
	//swap_numbers();
	//printf("%s\n", primo(IS_IT_PRIME_NUMBER) ? " is prime" : " is NOT prime");
	//printf("%d %d",0,1);
	//fibonacci(6 -2, 0, 1, 0); // Example call to Fibonacci function
	//function();
	//variable_size();
	//malloc_calloc();
	//struct_union();
	//static_variable2();
	scanf_();
	return 0;
}

void scanf_(){
	char w;
	printf("Write a number:");
	scanf("%c", &w);

	printf("\nNumber entered: %c", w);

	int a=10564;
	printf("\nNumber entered: %d", a/10000);
	a = (a % 10000) ;
	printf("\nNumber entered: %d", a/1000);
	a = (a % 1000) ;
	printf("\nNumber entered: %d", a/100);
	a = (a % 100) ;
	printf("\nNumber entered: %d", a/10);
	a = (a % 10) ;
	printf("\nNumber entered: %d", a);
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

void fibonacci(int num, int first, int second, int third) {
// Calcula el número de Fibonacci para el parámetro 'num'
	if (num > 0){
		third = first + second;
		first = second;
		second = third;
		printf(" %d ", third);		
		fibonacci(num - 1, first, second, third); // Recursive call with updated
	}
}

int primo(int num) {
	// Un número primo es un número natural mayor que 1 que solo tiene dos divisores: él mismo y el 1. 
	// Es decir, no puede dividirse exactamente por ningún otro número distinto de 1 y de sí mismo. 
	// Ejemplos de números primos son: 2, 3, 5, 7, 11, 13, 17, etc.
	// Los números menores o iguales a 1 no son primos
	// retorna 0 si no es primo
	// retorna 1 si es primo
	printf("\nChecking if %d is prime: ", num);
	if (num <= 1) {
		return 0;
	}
	// 2 es el único número par primo
	if (num == 2) {
		return 1;
	}
	// Si el número es par y mayor que 2, no es primo
	if (num % 2 == 0) {
		return 0;
	}
	// Verifica si el número tiene algún divisor entre 3 y la raíz cuadrada de num
	for (int i = 3; i * i <= num; i += 2) {
		// Si encuentra un divisor, no es primo
		if (num % i == 0) {
			return 0;
		}
	}
	// Si no se encontró ningún divisor, es primo
	return 1;
}

void swap_numbers() {
	int a = 10;
	int b = 20;

	printf("Before swapping: a = %d, b = %d\n", a, b);

	a = a + b; // a ahora es 30
	b = a - b; // b ahora es 10 (30 - 20)
	a = a - b; // a ahora es 20 (30 - 10)
	
	printf("After swapping: a = %d, b = %d\n", a, b);
}

void palindrome(char* str) {
	int len = strlen(str);
	int is_palindrome = 1;

	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]) {
			is_palindrome = 0;
			break;
		}
	}

	if (is_palindrome) {
		printf("%s is a palindrome\n", str);
	} else {
		printf("%s is not a palindrome\n", str);
	}
}

void psudo_main01() {
	// Ejemplo de uso de my_memcpy
	char origen[] = "Hola mundo";
	char destino[20];
	my_memcpy(destino, origen, my_strnlen(((origen)), 20)); // Copia la cadena incluyendo el terminador nulo
	printf("Copiado: %s\n", destino);
}

void *my_memcpy(void *restrict dest, const void *restrict src, size_t count)
{
	// Copia byte por byte desde src a dest, hasta count bytes
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;
	for (size_t i = 0; i < count; ++i) {
		d[i] = s[i];
	}
	return dest;
}

size_t my_strnlen(const char *s, size_t max)
{
	size_t len = 0;
	// Recorre la cadena hasta encontrar el terminador nulo o alcanzar 'max'
	while (len < max && s[len] != '\0') {
		len++;
	}
	return len;
}

void factorial(int x) {
	int result = 1;
	for (int i = 1; i <= x; i++) {
		result *= i;
	}
	printf("Factorial of %d is %d\n", x, result);
}

int factorial_01(int x) {
	if (x == 1) {
		return 1;
	} 
	else if (x > 1){
		return x * factorial_01(x - 1);
	} 
	else {
		return 0; // Caso para números negativos
	}
}