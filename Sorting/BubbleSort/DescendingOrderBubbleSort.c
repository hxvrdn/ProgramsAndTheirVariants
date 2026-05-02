#include <stdio.h>

/*
Working:
- Same as bubble sort but reverse comparison

Time Complexity: O(n^2)
*/

void bubbleSortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {2, 9, 1, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSortDesc(arr, n);

    printf("Descending order:\n");
    printArray(arr, n);

    return 0;
}