#include <stdio.h>

struct Result {
    int max;
    int min;
};

struct Result findMaxMin(int arr[], int low, int high) {
    struct Result result, left, right;

    // Only one element
    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }

    // Two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.max = arr[low];
            result.min = arr[high];
        } else {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }

    // Divide
    int mid = (low + high) / 2;

    // Conquer
    left = findMaxMin(arr, low, mid);
    right = findMaxMin(arr, mid + 1, high);

    // Combine
    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;

    return result;
}

int main() {
    int arr[] = {12, 5, 78, 34, 2, 90, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Result result = findMaxMin(arr, 0, n - 1);

    printf("Maximum = %d\n", result.max);
    printf("Minimum = %d\n", result.min);

    return 0;
}