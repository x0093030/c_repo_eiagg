#include <stdio.h>

int gdcd(int a, int b); // Function prototype for GCD calculation
int countWords(const char *str); // Function prototype for counting words
int bubbleSort(int arr[], int size); // Function prototype for bubble sort
int binarySearch(int arr[], int size, int target); // Function prototype for binary search  

int main(void){
    // Test cases for binarySearch
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {10, 20, 30, 40, 50};
    printf("binarySearch test 1: %s\n", (binarySearch(arr1, 5, 3) == 2) ? "Pass" : "Fail");
    printf("binarySearch test 2: %s\n", (binarySearch(arr2, 5, 25) == -1) ? "Pass" : "Fail");

    // Test cases for bubbleSort
    int arr3[] = {5, 3, 1, 4, 2};
    int arr4[] = {9, 7, 5, 3, 1};
    bubbleSort(arr3, 5);
    bubbleSort(arr4, 5);
    printf("bubbleSort test 1: %s\n", (arr3[0]==1 && arr3[1]==2 && arr3[2]==3 && arr3[3]==4 && arr3[4]==5) ? "Pass" : "Fail");
    printf("bubbleSort test 2: %s\n", (arr4[0]==1 && arr4[1]==3 && arr4[2]==5 && arr4[3]==7 && arr4[4]==9) ? "Pass" : "Fail");

    // Test cases for countWords
    printf("countWords test 1: %s\n", (countWords("hello world") == 2) ? "Pass" : "Fail");
    printf("countWords test 2: %s\n", (countWords("one  two   three") == 3) ? "Pass" : "Fail");

    // Test cases for gdcd
    printf("gdcd test 1: %s\n", (gdcd(12, 18) == 6) ? "Pass" : "Fail");
    printf("gdcd test 2: %s\n", (gdcd(17, 13) == 1) ? "Pass" : "Fail");

    return 0;
}

int binarySearch(int arr[], int size, int target) {
    // Performs binary search on a sorted array.
    // arr: the sorted array to search
    // size: number of elements in the array
    // target: the value to search for
    // Returns the index of target if found, otherwise -1.

    int left = 0; // Start index of the search range
    int right = size - 1; // End index of the search range

    // Continue searching while the range is valid
    while (left <= right) {
        // Find the middle index to avoid overflow
        int mid = left + (right - left) / 2;

        // Check if the middle element is the target
        if (arr[mid] == target) {
            return mid; // Element found, return its index
        }
        // If the target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            // If the target is smaller, ignore the right half
            right = mid - 1;
        }
    }
    // Target not found in the array
    return -1;
}

int bubbleSort(int arr[], int size) {
    // Sorts an array using the bubble sort algorithm.
    // arr: the array to sort
    // size: number of elements in the array
    // Returns 0 on success.

    // Outer loop for each pass through the array
    for (int i = 0; i < size - 1; i++) {
        // Inner loop for comparing adjacent elements
        for (int j = 0; j < size - i - 1; j++) {
            // If the current element is greater than the next, swap them
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j]; // Temporary variable for swapping
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        // After each pass, the largest element moves to its correct position
    }
    // Array is sorted in ascending order
    return 0; // Return success
}

int countWords(const char *str) {
    // Counts the number of words in a given string.
    // str: the input string
    // Returns the number of words found.

    int count = 0; // Initialize word count
    int inWord = 0; // Flag to track if currently in a word

    // Iterate through each character in the string
    while (*str) {
        // Check if the current character is a whitespace
        if (*str == ' ' || *str == '\n' || *str == '\t') {
            inWord = 0; // Not in a word
        } else if (inWord == 0) {
            inWord = 1; // Found the start of a new word
            count++; // Increment word count
        }
        str++; // Move to the next character
    }
    return count; // Return the total word count
}

int gdcd(int a, int b) {
    // Computes the greatest common divisor (GCD) of two integers using the Euclidean algorithm.
    // a: first integer
    // b: second integer
    // Returns the GCD of a and b.

    while (b != 0) {
        int temp = b; // Store the value of b
        b = a % b; // Update b to be the remainder of a divided by b
        a = temp; // Update a to be the previous value of b
    }
    return a; // When b is 0, a contains the GCD
}