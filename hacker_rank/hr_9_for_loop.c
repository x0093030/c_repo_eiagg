#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int aux;
int recurse(int n, int a, int b, int c);
void pattern();
int array_sum(int number_of_students, int first_element, int second_element, int third_element, char gender);
int marks_summation(int* marks, int number_of_students, char gender);


int main() 
{
    //pattern();
    printf("%s\n", (recurse(5, 1, 2, 3) == 11) ? "recurse Pass" : "recurse Failed");
    aux = recurse(5, 1, 2, 3);
    //assert(aux == 11);//If expression is false, the program stops.
    printf("%s\n", (array_sum(3, 3, 2, 5, 'b') == 8) ? "array_sum Pass" : "array_sum Failed");
    return 0;

}

void pattern() {
    int n = 5; // Example size of the pattern
    int L = (n * 2) - 1; // Calculate the length of the pattern
    int d_row, d_column, distance;
    for (int row=1; row<=L; row++) {
        for (int column=1; column<=L; column++){
            d_row = abs(row-n);
            d_column = abs(column-n);
            // Calculate the minimum distance to the edge
            //distance = d_row < d_column ? d_row : d_column;
            distance = d_row > d_column ? d_row : d_column;
            printf("%d ", distance + 1); // print columns
            
        }
        printf("\n"); // ptint rows
    }
}

int recurse(int n, int a, int b, int c) {
 if(n==3){
    return c;
  }else{
    return recurse(n-1, b, c, a+b+c);
  }
}

int array_sum(int number_of_students, int first_element, int second_element, int third_element, char gender){
    int sum;

    int *marks = (int *) malloc(number_of_students * sizeof (int));
    marks[0] = first_element;
    marks[1] = second_element;
    marks[2] = third_element;

    sum = marks_summation(marks, number_of_students, gender);
    //printf("%d\n", sum);
    free(marks);
    return sum;
}

int marks_summation(int* marks, int number_of_students, char gender) {
  //Write your code here.
  int aux=0;
  if (gender == 'b'){ //boys will take index 0, 2, 4, etc.
    // If the number of students is even, we start from index 0
    for(int i=0; i<=number_of_students; i= i+2){
        aux = aux + marks[i];
    }
  }else { // 'g' will take index 1, 3, 5, etc.
    // If the number of students is odd, we start from index 1
    for (int i=1; i<=number_of_students; i= i+2){
        aux = aux + marks[i];
    }
  }
  return aux;
}
