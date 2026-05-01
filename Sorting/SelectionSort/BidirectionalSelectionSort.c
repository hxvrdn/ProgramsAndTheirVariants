#include <stdio.h>

/*
Working:
- Find both minimum and maximum in one pass
- Place min at start and max at end

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

void bidirectionalSelectionSort(int arr[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        int min = start, max = start;

        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[min]) min = i;
            if (arr[i] > arr[max]) max = i;
        }

        // Swap min with start
        int temp = arr[start];
        arr[start] = arr[min];
        arr[min] = temp;

        // Adjust max index if it was swapped
        if (max == start) max = min;

        // Swap max with end
        temp = arr[end];
        arr[end] = arr[max];
        arr[max] = temp;

        start++;
        end--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    bidirectionalSelectionSort(arr, n);

    printf("Bidirectional sorted array:\n");
    printArray(arr, n);

    return 0;
}