#include <stdio.h>

/*
Working:
- Performs one pass, then recursively sorts remaining array

Time Complexity: O(n^2)
Space Complexity: O(n) (recursion stack)
*/

void bubbleSortRecursive(int arr[], int n) {
    if (n == 1)
        return;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    bubbleSortRecursive(arr, n - 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {3, 2, 1, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSortRecursive(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}