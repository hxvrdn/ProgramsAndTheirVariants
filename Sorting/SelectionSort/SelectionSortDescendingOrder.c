#include <stdio.h>

/*
Working:
- Same as selection sort but selects maximum element

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

void selectionSortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max])
                max = j;
        }
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 5, 8, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSortDesc(arr, n);

    printf("Descending sorted array:\n");
    printArray(arr, n);

    return 0;
}